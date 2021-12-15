#ifndef CESSNA_CONTROL_H
#define CESSNA_CONTROL_H

//  Gazebo api
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/common/Plugin.hh>

// ROS
#include <thread>
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "std_msgs/Float32.h"

#include <algorithm>

namespace gazebo {

   class CessnaControlPlugin : public ModelPlugin {

      // Constructor
      public: 
         CessnaControlPlugin();
         virtual ~CessnaControlPlugin();

      protected:
  
   };
}
#endif
