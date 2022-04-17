#ifndef _VELODYNE_PLUGIN_HH_
#define _VELODYNE_PLUGIN_HH_

//  Gazebo api
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>

// ROS
#include <thread>
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "std_msgs/Float32.h"
#include <cosmus_messages/Control_Surfaces.h>

namespace gazebo {

  /// \brief A plugin to control a Velodyne sensor.
  class ControlPlugin : public ModelPlugin {

    /// \brief Constructor
    public:
      ControlPlugin() {}
      ~ControlPlugin()  {
            rosNode->shutdown();
            delete rosNode;
       }

      virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);
      void OnRosMsg(const cosmus_messages::Control_SurfacesConstPtr &_msg);

    private:
      sdf::ElementPtr sdf;  // SDF for this plugin.
      physics::ModelPtr model; // Pointer to the model.
      transport::NodePtr gzNode; // A node used for transport
      transport::SubscriberPtr controlSub; // A subscriber to a named topic.
      transport::PublisherPtr controlPub; // Control publisher.
      std::mutex mutex; // Protection.

      /* Variáveis ROS */
      ros::NodeHandle *rosNode; /// A node use for ROS transport
      ros::Subscriber rosSub; /// A ROS subscriber
      ros::Publisher rosPub;
      ros::CallbackQueue rosQueue; /// A ROS callbackqueue that helps process messages
      std::string namespace_;

};

void ControlPlugin::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf) {

     std::cerr << "\nThe plugin is attach to model[" << _model->GetName() << "]\n";
     this->model = _model; // Store the model pointer for convenience.

     /******************************************* For Gazebo node *******************************************/
     this->gzNode = transport::NodePtr(new transport::Node()); // Initialize transport

     #if GAZEBO_MAJOR_VERSION < 8
        this->gzNode->Init(this->model->GetWorld()->GetName());
     #else
        this->gzNode->Init(this->model->GetWorld()->Name());
     #endif

     // Publish
     this->controlPub = this->gzNode->Advertise<msgs::Cessna>("~/" + _model->GetName() + "/control", 1000);

     /******************************************* For ROS Node *******************************************/
    // Initialize ros, if it has not already bee initialized.
    if (!ros::isInitialized()) {
            int argc    = 0;
            char** argv = NULL;
            ros::init(argc, argv, _model->GetName(), ros::init_options::NoSigintHandler);
    }

    // Create our ROS node. This acts in a similar manner to the Gazebo node
    this->rosNode = new ros::NodeHandle( _model->GetName() );

    // Create a named topic, and subscribe to it.
     this->rosSub = this->rosNode->subscribe("command", 1000,
				             &ControlPlugin::OnRosMsg, this);
}

void ControlPlugin::OnRosMsg(const cosmus_messages::Control_SurfacesConstPtr &_msg) {
    msgs::Cessna msg;
    msg.set_cmd_propeller_speed(_msg->propeller);
    msg.set_cmd_right_flap(_msg->right_flap);
    msg.set_cmd_left_flap(-_msg->right_flap);
    msg.set_cmd_right_aileron(_msg->right_aileron);
    msg.set_cmd_left_aileron(-_msg->right_aileron);
    msg.set_cmd_elevators(_msg->elevators);
    msg.set_cmd_rudder(_msg->rudder);
    this->controlPub->Publish(msg);
}

  // Tell Gazebo about this plugin, so that Gazebo can call Load on this plugin.
  GZ_REGISTER_MODEL_PLUGIN(ControlPlugin)

} // end gazebo namespace
#endif
