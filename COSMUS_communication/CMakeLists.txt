# Copyright (c) 2022, São Paulo-Brazil, Ontário-Canadá,
# represented by UNIFESP - Universidade Federal de São Paulo
# and CAPES - Coordenação de Aperfeiçoamento de Pessoal de Nível Superior
#
# All rights reserved.
#
# The COSMUS Design platform is licensed under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with the
# License.

cmake_minimum_required(VERSION 3.0.2)
project(cosmus_communication)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   Communication.msg
   NetworkComm.msg
   Odom.msg
)

generate_messages()

###################################
## catkin specific configuration ##
###################################

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES aircraft_communication
  CATKIN_DEPENDS message_runtime
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/aircraft_communication.cpp
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
catkin_install_python(PROGRAMS src/Client.py src/Network.py src/Odometry.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
