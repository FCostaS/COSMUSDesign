#!/usr/bin/env python
# license removed for brevity
import rospy
import rosnode
import math
from std_msgs.msg import String
from sensor_msgs.msg import NavSatFix
from sensor_msgs.msg import Imu
from cosmus_communication.msg import Communication, NetworkComm

def virtual_leader(data):
    dataComm2 = []

    for uav in data.comms:
        if( ns.find( str( uav.id ) ) == -1 ):
            dataComm2.append(uav)

    pub.publish(dataComm2)
    #rate.sleep()

def client():
    global pub
    global rate
    global ns
    #RateNode = 100 # 100hz
    Queue_Size = 20

    rospy.init_node('listener', anonymous = True)
    pub = rospy.Publisher('Communication', NetworkComm, queue_size=Queue_Size)
    ns = rospy.get_namespace()
    #rate = rospy.Rate(RateNode)

    rospy.loginfo("UAV: " + ns + " on")
    rospy.Subscriber("/UAVs_Info", NetworkComm, virtual_leader)
    rospy.spin()

if __name__ == '__main__':
    try:
        client()
    except rospy.ROSInterruptException:
        pass
