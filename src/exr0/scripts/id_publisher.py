#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32

def publish_id_digits():
    rospy.init_node('id_publisher', anonymous=True)
    publisher = rospy.Publisher('Bazylkhanov', Int32, queue_size=10)
    id_digits = [2,0,1,8,4,1,0,5,0]

    #rate1 = rospy.Rate(1)   # 1 Hz
    rate50 = rospy.Rate(50) # 50 Hz

    while not rospy.is_shutdown():
        for digit in id_digits:
            publisher.publish(digit)
            #rate1.sleep()
            rate50.sleep()

if __name__ == '__main__':
    try:
        publish_id_digits()
    except rospy.ROSInterruptException:
        pass

