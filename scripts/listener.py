#!/usr/bin/env python

import rospy
from std_msgs.msg import String

# ROS will call the listenerCallback() function whenever a new message arrives
def listenerCallback(data):
    rospy.loginfo(rospy.get_caller_id() + 'I heard : %s', data.data)

def listener():

    # Initialize ROS node with unique name in a system
    rospy.init_node('listener', anonymous = True)
    
    # Subscribe to the change_s topic with the master
    rospy.Subscriber('change_s', String, listenerCallback)
    
    #  Calling message listenerCallbacks as fast as possible
    rospy.spin()

if __name__ == '__main__':
    listener()
