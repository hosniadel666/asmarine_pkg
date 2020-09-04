#include "ros/ros.h"
#include "std_msgs/String.h"

// ROS will call the listenerCallback() function whenever a new message arrives
void listenerCallback(const std_msgs::String::ConstPtr& msg);

int main(int argc, char **argv)
{
  // Initialize ROS node with unique name in a system
  ros::init(argc, argv, "listener");

  // Create a handle to this node process 
  ros::NodeHandle n;

  // Subscribe to the change_s topic with the master
  ros::Subscriber sub = n.subscribe("change_s", 1000, listenerCallback);

  ros::spin();

  return 0;
}

void listenerCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard : %s", msg->data.c_str());
}