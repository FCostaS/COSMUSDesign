/*
 * Copyright 2015 James Jackson MAGICC Lab, BYU, Provo, UT
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * The airspeed aircraft plugin is adapted from package https://github.com/byu-magicc/rosflight_plugins.git
 * with all credits attributed to the developer.
 */

#ifndef SDF_NODE_H
#define SDF_NODE_H

#include <random>
#include <chrono>
#include <cmath>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>
#include <tf/tf.h>
#include <sensor_msgs/Imu.h>
#include <cosmus_messages/Odom.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <nav_msgs/Odometry.h>

#define Rate_pub 1000

using namespace std;

ros::Publisher pub_pose;

void Callback(const nav_msgs::Odometry::ConstPtr& msg, ros::Publisher *pub_pose) {
    cosmus_messages::Odom pub_msg;
    double roll, pitch, yaw;

    tf::Quaternion q(
        msg->pose.pose.orientation.x,
        msg->pose.pose.orientation.y,
        msg->pose.pose.orientation.z,
        msg->pose.pose.orientation.w);

    tf::Matrix3x3 m(q);
    m.getRPY(roll, pitch, yaw);

    pub_msg.pitch = pitch;
    pub_msg.roll = roll;
    pub_msg.yaw = yaw;
    pub_msg.accel_x = msg->pose.pose.position.x;
    pub_msg.accel_y = msg->pose.pose.position.y;
    pub_msg.accel_z = msg->pose.pose.position.z;

    pub_pose->publish(pub_msg);
}


int main(int argc, char **argv) {

    ros::init(argc, argv, "conversion_node");

    ros::NodeHandle nh_;

    pub_pose = nh_.advertise<cosmus_messages::Odom>("odometry", 0);
    ros::Subscriber sub_odom_ = nh_.subscribe<nav_msgs::Odometry>(ros::this_node::getNamespace() + "/imu", 0, boost::bind(&Callback, _1, &pub_pose));

    ros::spin();

    return 0;
}

#endif
