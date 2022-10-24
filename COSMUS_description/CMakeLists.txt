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
project(cosmus_description)

find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  roscpp
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES gazebo_models
#  CATKIN_DEPENDS gazebo_ros roscpp
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
#   src/${PROJECT_NAME}/gazebo_models.cpp
# )
