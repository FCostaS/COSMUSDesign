# All rights reserved.
#
# The COSMUS Design (Co-Simulation Multi-UAV for Systems Design) is licensed under the Apache License, Version 2.0
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
