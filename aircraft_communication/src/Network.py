#!/usr/bin/env python
# license removed for brevity
import rospy
import rosnode
import math
import message_filters
from copy import deepcopy
from std_msgs.msg import String
from sensor_msgs.msg import NavSatFix
from sensor_msgs.msg import Imu
from nav_msgs.msg import Odometry
from aircraft_communication.msg import Communication, NetworkComm

def callback_gps(sub1, sub2, sub3, sub4, sub5):
    dataComms = []
    uavs = [sub1, sub2, sub3, sub4, sub5]
    uav_id = 1

    for uav in uavs:
        dataComm = Communication()
        dataComm.id = uav_id
        dataComm.x = uav.pose.pose.position.x
        dataComm.y = uav.pose.pose.position.y
        dataComm.z = uav.pose.pose.position.z
        #dataComm.velocity_x = uav.twist.twist.linear.x
        #dataComm.velocity_y = uav.twist.twist.linear.y
        #dataComm.velocity_z = uav.twist.twist.linear.z
        dataComms.append(dataComm)
        uav_id = uav_id + 1

    pub.publish(dataComms)
    #rate.sleep()

def virtual_leader():
    global pub
    global rate
    #RateNode = 1000 # Hz
    Queue_Size = 50

    rospy.init_node('listener', anonymous = True)
    pub = rospy.Publisher('UAVs_Info', NetworkComm, queue_size=Queue_Size)
    #rate = rospy.Rate(RateNode)

    # UAV's topics
    sub1 = message_filters.Subscriber("/uav1" + "/position", Odometry)
    sub2 = message_filters.Subscriber("/uav2" + "/position", Odometry)
    sub3 = message_filters.Subscriber("/uav3" + "/position", Odometry)
    sub4 = message_filters.Subscriber("/uav4" + "/position", Odometry)
    sub5 = message_filters.Subscriber("/uav5" + "/position", Odometry)

    # Time Synchronizer
    ts = message_filters.TimeSynchronizer([sub1, sub2, sub3, sub4, sub5], Queue_Size)
    ts.registerCallback(callback_gps)
    rospy.spin()

if __name__ == '__main__':
    try:
        virtual_leader()
    except rospy.ROSInterruptException:
        pass
