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
1. Launch both nodes Individually
Run roscore (Open a Terminal)
```
cd ~/catkin_ws/
source ./devel/setup.bash
roscore
```
Run talker node (Open a new Terminal)
```
cd ~/catkin_ws/
source ./devel/setup.bash
rosrun beginner_tutorials talker 10
```
Run listener node (Open a new Terminal)
```
cd ~/catkin_ws/
source ./devel/setup.bash
rosrun beginner_tutorials listener
```

2. Launch both nodes with the launchfile
(Open a new Terminal)
```
cd ~/catkin_ws/
source ./devel/setup.bash
roslaunch beginner_tutorials nodelauncher.launch
```
You can change the frequency by passing an argumnet, default is 10 (Open a new Terminal)
```
cd ~/catkin_ws/
source ./devel/setup.bash
roslaunch beginner_tutorials nodelauncher.launch rate:=8
```

3. Run service to change string
launch both nodes and then Open a new Terminal
```
cd ~/catkin_ws/
source ./devel/setup.bash
rosservice call /service_string "Enter new string"
```
4. To view Log levels using rqt console and rqt logger level
Open a new Terminal
```
rosrun rqt_console rqt_console
```
Open a new Terminal
```
rosrun rqt_logger_level rqt_logger_level
```
5. Inspecting TF Frames
After launching both nodes using launch file, we can inspect the TF frames using tf_echo and rqt_tf_tree (Open a new Terminal)

```
rosrun tf tf_echo /world /talk
```
To genereate a pdf of tf frame
```
rosrun tf view_frames
```
Open a new Terminal
```
rosrun rqt_tf_tree rqt_tf_tree
```

6. Run Test
Open a new Terminal
```
cd ~/catkin_ws
source ./devel/setup.bash
catkin_make run_tests_beginner_tutorials
rostest beginner_tutorials testlauncher.launch
```
7. Record in Rosbag
To record in a rosbag, pass a true argument to the launch file(Open a new Terminal)
```
roslaunch beginner_tutorials nodelauncher.launch recordbag:=true
```
To avoid recording, either pass false or don't pass any argument
```
roslaunch beginner_tutorials nodelauncher.launch recordbag:=false
```
OR
```
roslaunch beginner_tutorials nodelauncher.launch
```
8. Use Rosbag
First launch the listener node and then Open a new Terminal and play rosbag
```
cd ~/catkin_ws/src/beginner_tutorials/results
rosbag play recording.bag
```
You can see that the listener node can hear the rosbag data of previously recorded talker node.

## Reference
* http://wiki.ros.org/