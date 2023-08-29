#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

def id_callback(data):
    rospy.loginfo("Received digit: %d", data.data)

def id_subscriber():
    rospy.init_node('id_subscriber', anonymous=True)
    rospy.Subscriber('Bazylkhanov', Int32, id_callback)
    rospy.spin()

if __name__ == '__main__':
    id_subscriber()

