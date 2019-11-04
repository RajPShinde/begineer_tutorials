# beginner_tutorials
[![License MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://github.com/RajPShinde/begineer_tutorials/blob/master/LICENSE)
[![Docs Generated](https://img.shields.io/badge/Docs-Generated-brightgreen.svg)](https://github.com/RajPShinde/begineer_tutorials/blob/master/docs)

## Authors

**Raj Prakash Shinde** - [GitHub](https://github.com/RajPShinde)
<br>I am a Masters in Robotics Engineering student at the University of Maryland, College Park. My primary area of interest are Legged Robotics and Automation. 

## Overview
This is beginners tutorial for creating a simple ROS package called begineers_tutorials with a Publisher &amp; Subscriber node. Where a publisher named talker, publishes a message and the subscriber called, listener hears the message. The message type here is a string. A talker node has a service that can be used to change the message content. A launch file can be used to launch both the nodes, which also passes the loop rate as an argument.

## Dependencies
1. Ubuntu 16.04
2. ROS Kinetic

## Build
Steps to build
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
cd src/
git clone https://github.com/RajPShinde/beginner_tutorials
cd ~/catkin_ws/
catkin_make
```

## Run
1. Run roscore
```
cd ~/catkin_ws/
source ./devel/setup.bash
roscore
```

2. Launch both nodes with the launchfile
Open a new Terminal
```
cd ~/catkin_ws/
source ./devel/setup.bash
roslaunch beginner_tutorials nodelauncher.launch rate:=8
```

3. Run service to change string
Open a new Terminal
```
cd ~/catkin_ws/
source ./devel/setup.bash
rosservice call /service_string "Enter new string"
```
4. View Log levels using rqt console and rqt logger level
Open a new Terminal
```
rosrun rqt_console rqt_console
```
Open a new Terminal
```
rosrun rqt_logger_level rqt_logger_level
```

## References
* http://wiki.ros.org/