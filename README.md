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
$ sudo apt install python3-rosdep python3-rosinstall python3-rosinstall-generator python3-wstool build-essential python3-catkin-tools
$ sudo rosdep init
$ rosdep update
```

2. If you don't have ROS workspace yet you can do so by
```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ sudo apt-get install 
$ catkin_init_workspace
$ cd ~/catkin_ws/
$ catkin init
```

3. Add sourcing to your .bashrc file
```
$ git clone -b main https://github.com/FCostaS/Swarm-Fixed-Wing.git
$ catkin build
$ echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
$ echo "export GAZEBO_MODEL_PATH=~/.gazebo/models" >>  ~/.bashrc
$ source ~/.bashrc
```

# Basic Usage
Launching the simulation is quite simple: it is enough to run in a terminal the command
```
$ roslaunch aircraft_gazebo cessna_spawn.launch
```
> Note: The first run of gazebo might take considerably long, as it will download some models from an online database. To avoid any problems when starting the simulation for the first time, you may run the gazebo command in the terminal line.

# Developer Usage

See [Fixed-Wing UAV Simulator wiki](https://github.com/FCostaS/Swarm-Fixed-Wing/wiki) for more instructions and examples.
