#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("change", 1000);

  // make the period of delay time 2 sec
  ros::Rate loop_rate(0.5);

  int count = 0, state = 0;
  while (ros::ok())
  {
    ++count;
    
    std_msgs::String msg;

    std::stringstream talker_msg, listener_msg;
    talker_msg << "I'm now in count " << count;

    ROS_INFO("%s", talker_msg.str().c_str());
    
    ros::spinOnce();
    
    if(count == 5)
    {
      ++state;
      listener_msg << "I'm now in state " << state;
      msg.data = listener_msg.str();
      chatter_pub.publish(msg);
      count = 0;
    }

    loop_rate.sleep();
  }

  return 0;
}

