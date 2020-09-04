# asmarine_ros_pkg
This repository contains code necessary to make a topic message communication between two nodes (publisher and subscriber node) using c++ and python, For every 5 counts every 10 sec in the publisher node, It should publish a message to the subscriber node and change its state.



Prerequisites:
-----------------

To run the program, you need to have the following installed :

- Ubuntu 16
- ROS Kinetic http://wiki.ros.org/kinetic/Installation

Getting Started
------------------

> add the package in your catkin_ws
```
$ cd ~/catkin_ws/src

$ git clone https://github.com/hosniadel666/asmarine_ros_pkg.git

```
### Now to run the programme using c++

> first build the package source files and run roscore

```
$ cd asmarine/build

$ cmake ..

$ make

$ roscore
```

> second we run the two nodes
```
$ cd ~/catkin_ws/src/asmarine

$ ./build/talker
```
and in another terminal run
```
$ ./build/listener
```
### Now to run the programme using python


```
$ roscore

$ rosrun asmarine talker.py
```
and in another terminal run
```
$ rosrun asmarine listener.py
```
Result 
------------------
+ the execution of the program should be like that :
<p align="center">
<img src="https://github.com/hosniadel666/asmarine_ros_pkg/blob/master/images/ezgif.com-crop.gif" hspace="0"/>
</p>

+ You can visualize the relation between nodes By using the rqt_graph ROS plugin to visualize the ROS computation graph
```
$ rosrun rqt_graph rqt_graph
```

<p align="center">
<img src="https://github.com/hosniadel666/asmarine_ros_pkg/blob/master/images/rqt_graph%205.PNG" hspace="0"/>
</p>