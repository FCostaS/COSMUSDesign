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
#include <aircraft_control/control_surfaces.h>

namespace gazebo
{
  /// \brief A plugin to control a Velodyne sensor.
  class VelodynePlugin : public ModelPlugin
  {
    /// \brief Constructor
    public: VelodynePlugin() {}

    /// \brief The load function is called by Gazebo when the plugin is
    /// inserted into simulation
    /// \param[in] _model A pointer to the model that this plugin is
    /// attached to.
    /// \param[in] _sdf A pointer to the plugin's SDF element.
    public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
    {
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
     this->controlPub = this->gzNode->Advertise<msgs::Cessna>("~/" + _model->GetName() + "/control");

     // Subscribe
     /* this->controlSub = this->gzNode->Subscribe("~/" + _model->GetName() + "/state", &VelodynePlugin::OnControl, this); */
     
     /******************************************* For ROS Node *******************************************/
     if (_sdf->HasElement("robotNamespace")){
    	namespace_ = _sdf->GetElement("robotNamespace")->Get<std::string>();
    } else {
    	gzerr << "[gazebo_wind_plugin] Please specify a robotNamespace.\n";
    }

    if (_sdf->HasElement("robotNamespace")) {
    	this->namespace_ = _sdf->GetElement("robotNamespace")->Get<std::string>();
    } else {
    	gzerr << "Please specify a robotNamespace.\n";
    }

    if (!ros::isInitialized()) { // Initialize ros, if it has not already bee initialized.
            int argc    = 0;
            char** argv = NULL;
            ros::init(argc, argv, this->namespace_, ros::init_options::NoSigintHandler);
    }
    ROS_INFO("Hello World! I'm ROS =D");

    // Create our ROS node. This acts in a similar manner to the Gazebo node
    this->rosNode.reset(new ros::NodeHandle(this->namespace_));

    // Create a named topic, and subscribe to it.
    ros::SubscribeOptions so = ros::SubscribeOptions::create<aircraft_control::control_surfaces>(
            this->namespace_ + "/cmd_control_surfaces", 1,
            boost::bind(&VelodynePlugin::OnRosMsg, this, _1),
            ros::VoidPtr(), &this->rosQueue);
     this->rosSub = this->rosNode->subscribe(so);

     // Create node for publish
     /* this->rosPub = this->rosNode->advertise<cessna_control::control_surfaces>(this->namespace_ + "/state", 1); */

     // Spin up the queue helper thread.
     this->rosQueueThread = std::thread(std::bind(&VelodynePlugin::QueueThread, this));

    }

    // Load
    void OnRosMsg(const aircraft_control::control_surfacesConstPtr &_msg) {
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

    /*void OnControl(ConstCessnaPtr &_msg) {
	cessna_control::control_surfaces msgROS;
	msgROS.propeller = _msg->propeller_speed();
	msgROS.left_aileron = _msg->left_aileron();
	msgROS.left_flap = _msg->left_flap();
	msgROS.right_aileron = _msg->right_aileron();
	msgROS.right_flap = _msg->right_flap();
	msgROS.elevators = _msg->elevators();
        msgROS.rudder = _msg->rudder();
        this->rosPub.publish(msgROS);
    }*/

    private: void QueueThread() { // ROS helper function that processes messages
   
        static const double timeout = 0.001;

        while (this->rosNode->ok()) {
            this->rosQueue.callAvailable(ros::WallDuration(timeout));
        }
    }

    private:
    sdf::ElementPtr sdf;  // SDF for this plugin.
    physics::ModelPtr model; // Pointer to the model.
    transport::NodePtr gzNode; // A node used for transport
    transport::SubscriberPtr controlSub; // A subscriber to a named topic.
    transport::PublisherPtr controlPub; // Control publisher.
    std::mutex mutex; // Protection.

    /* Variáveis ROS */
    std::unique_ptr<ros::NodeHandle> rosNode; /// A node use for ROS transport
    ros::Subscriber rosSub; /// A ROS subscriber
    ros::Publisher rosPub;
    ros::CallbackQueue rosQueue; /// A ROS callbackqueue that helps process messages
    std::thread rosQueueThread; /// A thread the keeps running the rosQueue
    std::string namespace_;
  };

  // Tell Gazebo about this plugin, so that Gazebo can call Load on this plugin.
  GZ_REGISTER_MODEL_PLUGIN(VelodynePlugin)
}
#endif
