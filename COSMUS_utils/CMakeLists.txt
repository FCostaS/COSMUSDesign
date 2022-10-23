# Copyright (c) 2021, United States Government, as represented by the
# Administrator of the National Aeronautics and Space Administration.
#
# All rights reserved.
#
# The "ISAAC - Integrated System for Autonomous and Adaptive Caretaking
# platform" software is licensed under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with the
# License. You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations
# under the License.

cmake_minimum_required(VERSION 2.8.3)
project(cosmus_utils)

# Specify C++14 standard
add_definitions(-std=c++14)

# Find packages
find_package(catkin REQUIRED COMPONENTS
    visualization_msgs
    tf2
    tf2_ros
    tf2_eigen
    tf2_msgs
    tf2_geometry_msgs
    cosmus_messages
    geometry_msgs
    gazebo_ros
    sensor_msgs
)

find_package(gazebo REQUIRED)

# Call catkin
catkin_package(
  INCLUDE_DIRS
  LIBRARIES
  CATKIN_DEPENDS
    visualization_msgs
    tf2
    tf2_ros
    tf2_eigen
    tf2_msgs
    tf2_geometry_msgs
    cosmus_messages
    geometry_msgs
    gazebo_plugins
    gazebo_ros
    roscpp
    sensor_msgs
    DEPENDS GAZEBO
)

###########
## Build ##
###########

# Specify additional locations of header files
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
)

# Add gazebo to the link directorries
link_directories(${GAZEBO_LIBRARY_DIRS})
list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

# Initialise a list which will keep track of all targets
# that need to be installed.
set(targets_to_install "")

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(sdf_parser src/sdf_parser.cc)
target_link_libraries(sdf_parser ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
add_dependencies(sdf_parser ${catkin_EXPORTED_TARGETS})

add_executable(odometry src/odometry.cc)
target_link_libraries(odometry ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
add_dependencies(odometry ${catkin_EXPORTED_TARGETS})

#############
## Install ##
#############

# Install all targets that were defined above (some conditionally) and added to the
# variable targets_to_install
install(
  TARGETS
    ${targets_to_install}
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
  LIBRARY DESTINATION ${LIB_DESTINATION}
)
