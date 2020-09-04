#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def talker():

    count = 0
    state = 0

    pub = rospy.Publisher('change_s', String, queue_size = 10)
    rospy.init_node('talker', anonymous = True)
    rate = rospy.Rate(0.5) 
    while not rospy.is_shutdown():
        count += 1
        talker_str = "I'm now in count %s" % str(count)
        rospy.loginfo(talker_str)
        if count == 5:
            state += 1
            listener_str = "I'm now in state %s" % str(state)
            pub.publish(listener_str)
            count = 0
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
