#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def talker():

    count = 0
    state = 0

    # Tell the master that will be publishing a message of type String on the topic change_s
    pub = rospy.Publisher('change_s', String, queue_size = 10)

    # Initialize ROS node with unique name in a system
    rospy.init_node('talker', anonymous = True)

    # specify the loop frequency
    rate = rospy.Rate(0.5) 

    # Loop untill exeption handling
    while not rospy.is_shutdown():
        count += 1
        talker_str = "I'm now in count %s" % str(count)
        
        # Print on ROS console 
        rospy.loginfo(talker_str)

        # After 10 sec publish a message and change the state
        if count == 5:
            state += 1
            listener_str = "I'm now in state %s" % str(state)
            pub.publish(listener_str)
            count = 0

        # Sleep time depends on loop frequency
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
