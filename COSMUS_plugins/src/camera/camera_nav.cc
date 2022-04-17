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
#include "gazebo/sensors/CameraSensor.hh"

// Tf2 includes
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/static_transform_broadcaster.h>

// Aircraft includes
#include <cosmus_plugins/camera_nav.h>

// Wifi Sensor message
#include <geometry_msgs/PoseStamped.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>

// STL includes
#include <string>

#define TOPIC_NAME_CAMERA "fisheye"

namespace gazebo {

  NavCameraPlugin::NavCameraPlugin() { }
  NavCameraPlugin::~NavCameraPlugin() {
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
  void NavCameraPlugin::Load(sensors::SensorPtr sensor, sdf::ElementPtr sdf) {
    sensor_ = std::dynamic_pointer_cast<sensors::WideAngleCameraSensor>(sensor);
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

    if(sdf->HasElement("update_rate")) {
        sensor_->SetUpdateRate(sdf_->Get<double> ("update_rate"));
    }

    std::string robot_name = model_->GetName();
    Node_hz = new ros::NodeHandle(robot_name);
    image_pub = Node_hz->advertise<sensor_msgs::Image>(TOPIC_NAME_CAMERA, 1);

    // Check that we have a mono camera
    if (sensor_->Camera()->ImageFormat() != "L8") {
        ROS_FATAL_STREAM("Camera format must be L8");
    }

    // Set image constants
    image_msg_.is_bigendian = false;
    image_msg_.header.frame_id = model_->GetName();
    image_msg_.encoding = sensor_msgs::image_encodings::MONO8;

    updateConnection = sensor_->ConnectUpdated (
        std::bind(&NavCameraPlugin::Callback, this)
    );
  }

  void NavCameraPlugin::Callback() {
    // Quickly record the current time and current pose before doing other computations
    ros::Time curr_time = ros::Time::now();

    // Publish the nav cam image
    image_msg_.header.stamp.sec  = sensor_->LastMeasurementTime().sec;
    image_msg_.header.stamp.nsec = sensor_->LastMeasurementTime().nsec;
    image_msg_.height            = sensor_->ImageHeight();
    image_msg_.width             = sensor_->ImageWidth();
    image_msg_.step              = image_msg_.width;
    image_msg_.data.resize(image_msg_.step * image_msg_.height);

    const uint8_t* data_start = reinterpret_cast<const uint8_t*>(sensor_->ImageData());

    std::copy(data_start,
              data_start + image_msg_.step * image_msg_.height,
              image_msg_.data.begin()
    );

    image_pub.publish(image_msg_);
  }

  GZ_REGISTER_SENSOR_PLUGIN(NavCameraPlugin)
} // namespace gazebo
