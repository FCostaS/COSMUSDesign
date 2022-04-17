/* Copyright (c) 2021, United States Government, as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 *
 * All rights reserved.
 *
 * The "ISAAC - Integrated System for Autonomous and Adaptive Caretaking
 * platform" software is licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with the
 * License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

// ROS includes
#include <ros/ros.h>

// Wifi Sensor library
#include <gazebo/sensors/WirelessReceiver.hh>
#include <gazebo/sensors/WirelessTransmitter.hh>

// Tf2 includes
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/static_transform_broadcaster.h>

// Aircraft includes
#include <cosmus_plugins/wifi_receiver.h>

// Wifi Sensor message
#include <cosmus_messages/WifiSignal.h>
#include <cosmus_messages/WifiSignals.h>
#include <cosmus_messages/Communication.h>
#include <cosmus_messages/NetworkComm.h>

// STL includes
#include <string>

#define ModelStdDev 6.0

namespace gazebo {

WifiReceiverPlugin::WifiReceiverPlugin() { }

WifiReceiverPlugin::~WifiReceiverPlugin() {
  Node_hz->shutdown();
  delete Node_hz;
  if (updateConnection) {
      #if GAZEBO_MAJOR_VERSION > 7
      updateConnection.reset();
      #else
      sensor_->DisconnectUpdated(updateConnection);
      #endif
  }
}

// Sensor plugin load callback
void WifiReceiverPlugin::Load(sensors::SensorPtr sensor, sdf::ElementPtr sdf) {
  sensor_ = std::dynamic_pointer_cast<sensors::WirelessTransmitter>(sensor);
  parentEntity = boost::dynamic_pointer_cast<physics::Link>(physics::get_world ()->EntityByName(sensor_->ParentName()));

  sdf_ = sdf;
  world_ = gazebo::physics::get_world(sensor->WorldName());
  #if GAZEBO_MAJOR_VERSION > 7
  model_ = boost::static_pointer_cast < physics::Link >(
    world_->EntityByName(sensor->ParentName()))->GetModel();
  #else
  model_ = boost::static_pointer_cast<physics::Link>(
    world_->GetEntity(sensor->ParentName()))->GetModel();
  #endif

  /* IR Model */
  if(sdf->HasElement("NoiseFloor")) {
      NoiseFloor = sdf_->Get<double> ( "NoiseFloor" );
  } else {
    NoiseFloor = DEFAULT_NOISE_FLOOR;
  }

  if(sdf->HasElement("ByteNum")) {
      ByteNum = sdf_->Get<double> ( "ByteNum" );
  } else {
      ByteNum = DEFAULT_BYTE_NUM;
  }

  if(sdf->HasElement("FreqComm")) {
      FreqComm = sdf_->Get<double> ( "FreqComm" );
  } else {
      FreqComm = DEFAULT_FREQ_COMM;
  }

  /* Receiver Data */
  if(sdf->HasElement("min_frequency")) {
      this->MinFreq = sdf_->Get<double> ( "min_frequency" );
  }

  if(sdf->HasElement("max_frequency")) {
      this->MaxFreq = sdf_->Get<double> ( "max_frequency" );
  }

  if(sdf->HasElement("power")) {
      this->Power = sdf_->Get<double> ( "power" );
  }

  if(sdf->HasElement("gain")) {
      this->Gain = sdf_->Get<double> ( "gain" );
  }

  if(sdf->HasElement("sensitivity")) {
      this->Sensitivity = sdf_->Get<double> ( "sensitivity" );
  }

  if(sdf->HasElement("update_rate")) {
      sensor_->SetUpdateRate(sdf_->Get<double> ("update_rate"));
  }

  std::string robot_name = model_->GetName();
  Node_hz = new ros::NodeHandle(robot_name);
  RSSI = Node_hz->advertise<cosmus_messages::WifiSignals>(TOPIC_NAME_RSSI, 1);
  Datagram = Node_hz->advertise<cosmus_messages::NetworkComm>(TOPIC_NAME_DATA_RECEIVER, 1);

  updateConnection = sensor_->ConnectUpdated (
      std::bind(&WifiReceiverPlugin::Callback, this)
  );

}

double WifiReceiverPlugin::ModelPropagation(
      const ignition::math::Pose3d &_receiver,
      const double _rxGain,
      const sensors::WirelessTransmitterPtr transmitter,
      const ignition::math::Pose3d &txPose) {

      std::string entityName;
      double dist;
      ignition::math::Vector3d end = _receiver.Pos();
      ignition::math::Vector3d start = txPose.Pos();
      physics::WorldPtr world_ = gazebo::physics::get_world(transmitter->WorldName());

      // Avoid computing the intersection of coincident points
      // This prevents an assertion in bullet (issue #849)
      if (start == end) {
        end.Z() += 0.00001;
      }

      // Acquire the mutex for avoiding race condition with the physics engine
      //boost::recursive_mutex::scoped_lock lock(*(
      //    world_->Physics()->GetPhysicsUpdateMutex()));

      // Looking for obstacles between start and end points
      int n = 2;

      //physics::RayShapePtr testRay = boost::dynamic_pointer_cast<gazebo::physics::RayShape>(
      //        world_->Physics()->CreateShape("ray", gazebo::physics::CollisionPtr()));

      //testRay->SetPoints(start, end);
      //testRay->GetIntersection(dist, entityName);

      // ToDo: The ray intersects with my own collision model. Fix it.
      //if (!entityName.empty()) {
      //  n = 2;
      //}

      double distance = std::max(1.0, txPose.Pos().Distance(_receiver.Pos()));
      double x = std::abs(ignition::math::Rand::DblNormal(0.0, ModelStdDev));
      double wavelength = common::SpeedOfLight / (transmitter->Freq() * 1000000);

      // Hata-Okumara propagation model
      double rxPower = transmitter->Power() + transmitter->Gain() + _rxGain - x +
          20 * log10(wavelength) - 20 * log10(4 * M_PI) - 10 * n * log10(distance);

      /*std::cout << "txPower = " << transmitter->Power()
                << " txGain = " << transmitter->Gain()
                << " rxGain = " << _rxGain
                << " wavelength = " << wavelength
                << " n = " << n
                << " distance = " << distance << "\n";*/

      return rxPower;
}

void WifiReceiverPlugin::Callback() {
      int countPck = 0;
      std::string txEssid;
      double rxPower;
      double txFreq;
      float packetDropProb, randDraw;
      float ber; //ber: Bit Error Rate
      bool bPacketReceived;

      ignition::math::Pose3d myPos = parentEntity.lock()->WorldPose();
      std::vector<sensors::SensorPtr> Sensors = sensors::SensorManager::Instance()->GetSensors();
      cosmus_messages::WifiSignals msg_all;
      cosmus_messages::WifiSignal rx_msg;
      cosmus_messages::NetworkComm wifi_scan;
      cosmus_messages::Communication data;

      for (int i = 0 ; i < Sensors.size () ; i++) {

        if ( Sensors[i]->Type() == "wireless_transmitter") {
          sensors::WirelessTransmitterPtr transmitter = std::dynamic_pointer_cast<sensors::WirelessTransmitter> (Sensors[i]);

          if(transmitter->ESSID() != sensor_->ESSID()) {
            txEntity = boost::dynamic_pointer_cast<physics::Link>(physics::get_world()->EntityByName(transmitter->ParentName()));
            txPose = txEntity.lock()->WorldPose();
            txFreq = transmitter->Freq();
            
            //rxPower = transmitter->SignalStrength(myPos, sensor_->Gain());
            rxPower = ModelPropagation(myPos, sensor_->Gain(), transmitter, txPose);

            // Discard if the frequency received is out of our frequency range,
            // or if the received signal strengh is lower than the sensivity
            if ((txFreq < this->MinFreq) ||
                (txFreq > this->MaxFreq) ||
                (rxPower < this->Sensitivity)) {
              continue;
            }

            /* if(transmitter->Freq() == FreqComm ) {
                ber = 0;
                packetDropProb = 0;
                bPacketReceived = true;
            } else {
                ber = QPSKPowerToBER( dbmToPow (rxPower), dbmToPow (NoiseFloor) );
                packetDropProb = 1.0 - exp( ByteNum*log(1-ber) );
                randDraw = ( rand () % 1000 ) / 1000.0;
                bPacketReceived = randDraw > packetDropProb;
            } */

            bPacketReceived = true;
            if(bPacketReceived) {
                // RSSI
                rx_msg.frequency = transmitter->Freq();
                rx_msg.ssid = transmitter->ESSID();
                rx_msg.signal_dbm = rxPower;
                msg_all.signals.push_back(rx_msg);

                // Data
                data.x = txPose.Pos().X();
                data.y = txPose.Pos().Y();
                data.z = txPose.Pos().Z();
                data.ssid = transmitter->ESSID();
                wifi_scan.comms.push_back(data);

                countPck++;
            }

          }
        }
     }

     // publish information
     if(countPck) {
       RSSI.publish(msg_all);
       Datagram.publish(wifi_scan);
     }
}

  GZ_REGISTER_SENSOR_PLUGIN(WifiReceiverPlugin)
} // namespace gazebo
