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
project(cosmus_gazebo)

find_package(catkin REQUIRED)

catkin_package(
    #  INCLUDE_DIRS include
    #  LIBRARIES mybot_gazebo
    #  CATKIN_DEPENDS other_catkin_pkg
    #  DEPENDS system_lib
)
