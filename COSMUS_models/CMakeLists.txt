cmake_minimum_required(VERSION 3.0.2)
project(cosmus_models)

find_package(catkin REQUIRED COMPONENTS
  gazebo_ros
  roscpp
)

###################################
## catkin specific configuration ##
###################################

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
