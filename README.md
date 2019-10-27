# beginner_tutorials
[![License MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://github.com/RajPShinde/begineer_tutorials/blob/master/LICENSE)

## Authors

**Raj Prakash Shinde** - [GitHub](https://github.com/RajPShinde)
<br>I am a Masters in Robotics Engineering student at the University of Maryland, College Park. My primary area of interest are Legged Robotics and Automation. 

## Overview
This is beginners tutorial for creating a simple ROS package called begineers_tutorials with a Publisher &amp; Subscriber node. Where a publisher named talker, publishes a message "Hello, I'm Raj" and the subscriber called, listener hears the message. The message type here is a string.

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

2. Run ROS node talker- Publisher from package begineer_tutorials
* Open a new Terminal Shift+ctrl+T
```
cd ~/catkin_ws/
source ./devel/setup.bash
rosrun beginner_tutorials talker
```

3. Run ROS node listener- Subscriber from package begineer_tutorials
* Open a new Terminal Shift+ctrl+T
```
cd ~/catkin_ws/
source ./devel/setup.bash
rosrun beginner_tutorials listener
```
## References
* http://wiki.ros.org/