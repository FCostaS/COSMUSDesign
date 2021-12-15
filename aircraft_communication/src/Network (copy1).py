#!/usr/bin/env python
# license removed for brevity
import rospy
import rosnode
import math
from std_msgs.msg import String
from sensor_msgs.msg import NavSatFix
from sensor_msgs.msg import Imu
from aircraft_communication.msg import Communication, NetworkComm

RateNode = 100 # 10hz
N_UAVs = 3
dataComm = Communication()
dataComm2 = []

def gps_callback(data):
    # rospy.get_caller_id() = /talker_28365_1617946265425
    dataComm.longitude = data.latitude
    dataComm.latitude = data.latitude
    dataComm.altitude = data.altitude

def imu_callback(data):
    X = data.linear_acceleration.x
    Y = data.linear_acceleration.y
    Z = data.linear_acceleration.z
    dataComm.acceleration = math.sqrt(X*X + Y*Y + Z*Z)

def virtual_leader():
    # Publisher
    pub = rospy.Publisher('Virtual_Leader', Communication, queue_size=10)
    pub2 = rospy.Publisher('Virtual_Leader2', NetworkComm, queue_size=10)

    rospy.init_node('talker', anonymous = True)
    rate = rospy.Rate(RateNode)

    rospy.loginfo("Virtual Leader on")
    while not rospy.is_shutdown():
        dataComm2 = []
        for x in range(1, N_UAVs + 1):
            rospy.Subscriber("/Cessna" + str(x) + "/Cessna" + str(x) + "/fix", NavSatFix, gps_callback)
            rospy.Subscriber("/Cessna" + str(x) + "/imu", Imu, imu_callback)
            dataComm.id = x
            dataComm2.append(dataComm)
            pub.publish(dataComm)
            rate.sleep()

        pub2.publish(dataComm2)
        rate.sleep()

if __name__ == '__main__':
    try:
        virtual_leader()
    except rospy.ROSInterruptException:
        pass
