# Copyright (c) 2022, São Paulo-Brazil, Ontário-Canadá,
# represented by UNIFESP - Universidade Federal de São Paulo
# and CAPES - Coordenação de Aperfeiçoamento de Pessoal de Nível Superior
#
# All rights reserved.
#
# The COSMUS Design platform is licensed under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with the
# License.

cmake_minimum_required(VERSION 2.8.3)
project(cosmus_plugins)

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
    wifi_receiver
    camera_nav
    airspeed_plugin
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

# Create a sensor plugin for the wifi receiver
add_library(
    wifi_receiver
    SHARED src/wifi_receiver/wifi_receiver.cc)
target_link_libraries(
    wifi_receiver
    ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
add_dependencies(
    wifi_receiver
    ${catkin_EXPORTED_TARGETS})
list(APPEND targets_to_install wifi_receiver)

# Create a sensor plugin for the Camera navigation
add_library(
    camera_nav
    SHARED src/camera/camera_nav.cc)
target_link_libraries(
    camera_nav
    ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
add_dependencies(
    camera_nav
    ${catkin_EXPORTED_TARGETS})
list(APPEND targets_to_install camera_nav)

# Create a sensor plugin for airspeed
add_library(
    airspeed_plugin
    SHARED src/airspeed/airspeed_plugin.cc)
target_link_libraries(
    airspeed_plugin
    ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
add_dependencies(
    airspeed_plugin
    ${catkin_EXPORTED_TARGETS})
list(APPEND targets_to_install airspeed_plugin)

# Create a sensor plugin for airspeed
add_library(
    aircraft_control
    SHARED src/command/aircraft_control.cc)
target_link_libraries(
    aircraft_control
    ${catkin_LIBRARIES} ${GAZEBO_LIBRARIES})
add_dependencies(
    aircraft_control
    ${catkin_EXPORTED_TARGETS})
list(APPEND targets_to_install aircraft_control)

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
