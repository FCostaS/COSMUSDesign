/* Copyright (c) 2017, United States Government, as represented by the
 * Administrator of the National Aeronautics and Space Administration.
 *
 * All rights reserved.
 *
 * The Astrobee platform is licensed under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with the
 * License. You may obtain a copy of the License at
 *
 *     https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#ifndef RF_MODEL_H_
#define RF_MODEL_H_

// ROS includes
#include <ros/ros.h>
#include <ros/callback_queue.h>

// General messages
#include <geometry_msgs/TransformStamped.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud2_iterator.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/CameraInfo.h>
#include <visualization_msgs/MarkerArray.h> // Wifi Sensor message

// Transformation helper code
#include <tf2_ros/transform_listener.h>

// Gazebo includes
#include <gazebo/common/common.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/sensors/sensors.hh>
#include <gazebo/common/Plugin.hh>
#include <gazebo/sensors/SensorFactory.hh>
#include <gazebo/sensors/SensorManager.hh>
#include <gazebo/physics/Link.hh>
#include <gazebo/util/system.hh>

#if GAZEBO_MAJOR_VERSION <= 7
#include <gazebo/math/gzmath.hh>
#endif
#include <gazebo/rendering/rendering.hh>

// Eigen includes
#include <Eigen/Geometry>

// STL includes
#include <string>
#include <thread>
#include <memory>

namespace gazebo {

  // Convenience wrapper around a sensor plugin
  class RFModel {
   public:
    RFModel(); // Constructor
    virtual ~RFModel(); // Destructor

    double ModelPropagationn();

   private:

  };

  double RFModel::ModelPropagationn() {
    return 1.0;
  }

} // namespace gazebo


#endif
