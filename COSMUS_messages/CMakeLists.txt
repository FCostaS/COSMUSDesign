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
project(cosmus_messages)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
  geometry_msgs
  actionlib_msgs
  trajectory_msgs
  sensor_msgs
)

# Generate messages in the 'msg' folder
file(GLOB MSG_FILES msg/*.msg)
foreach(SRC ${MSG_FILES})
  get_filename_component(NAME ${SRC} NAME)
  list(APPEND MSG_FILE_NAMES ${NAME})
endforeach()
add_message_files(FILES ${MSG_FILE_NAMES})

generate_messages(
  DEPENDENCIES std_msgs geometry_msgs actionlib_msgs trajectory_msgs sensor_msgs std_msgs
)

catkin_package(
 # INCLUDE_DIRS include
  LIBRARIES
  CATKIN_DEPENDS geometry_msgs actionlib_msgs trajectory_msgs sensor_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
