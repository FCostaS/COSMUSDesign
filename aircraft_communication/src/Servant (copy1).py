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
dataComm = Communication()

def virtual_leader(data):
    dataComm.id = data.id
    dataComm.longitude = data.latitude
    dataComm.latitude = data.latitude
    dataComm.altitude = data.altitude
    dataComm.acceleration = data.acceleration

def servant():
    ns = rospy.get_namespace()

    # Publisher
    pub = rospy.Publisher('Communication', Communication, queue_size=10)
    rospy.init_node('talker', anonymous = True)
    rate = rospy.Rate(RateNode)

    rospy.loginfo("UAV: " + ns + " on")
    while not rospy.is_shutdown():
        rospy.Subscriber("/Virtual_Leader", Communication, virtual_leader)
        if( ns.find( str( int( dataComm.id) ) ) == -1 ):
            pub.publish(dataComm)
        rate.sleep()

if __name__ == '__main__':
    try:
        servant()
    except rospy.ROSInterruptException:
        pass
