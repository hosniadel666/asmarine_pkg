#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv)
{
  // Initialize ROS node with unique name in a system
  ros::init(argc, argv, "talker");

  // Create a handle to this node process 
  ros::NodeHandle n;

  // Tell the master that will be publishing a message of type std_msgs/String on the topic change_s
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("change_s", 1000);

  // Specify the loop frequency
  ros::Rate loop_rate(0.5);

  int count = 0, state = 0;

  // Loop untill exeption handling
  while (ros::ok())
  {
    ++count;
    
    std_msgs::String msg;

    std::stringstream talker_msg, listener_msg;
    talker_msg << "I'm now in count " << count;
    
    // Print on ROS console 
    ROS_INFO("%s", talker_msg.str().c_str());
    
    ros::spinOnce();
    
    // After 10 sec publish a message and change the state
    if(count == 5)
    {
      ++state;
      listener_msg << "I'm now in state " << state;
      msg.data = listener_msg.str();
      chatter_pub.publish(msg);
      count = 0;
    }

    // Sleep time depends on loop frequency
    loop_rate.sleep();
  }

  return 0;
}

