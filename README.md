# Fixed-Wing UAV Simulator

The Fixed-Wing UAV Simulator is a ROS package, aimed to modeling, developing and testbed algorithms of navigation for Unmanned Aerial Vehicles (UAVs) with fixed-wing. The plataform has support for swarming applications and integration with MATLAB/Simulink.

This simulation platform allows to understand the behavior of the flight control system by comparing and evaluating different indoor and outdoor scenarios, with a details level quite close to reality.

# Installation Instructions
## Ubuntu 20.04 with ROS Noetic and Gazebo 11

To use the code developed and stored in this repository some preliminary actions are needed. They are listed below. The ROS Noetic is a version of ROS for Ubuntu Focal Fossa.

1. Install and initialize ROS Noetic desktop full
```
$ sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
$ sudo apt install curl # if you haven't already installed curl
$ curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
$ sudo apt-get update
$ sudo apt install ros-noetic-desktop-full
$ echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
$ source ~/.bashrc
$ sudo apt install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential
$ sudo apt install python3-rosdep
$ sudo rosdep init
$ rosdep update
```

2. If you don't have ROS workspace yet you can do so by
