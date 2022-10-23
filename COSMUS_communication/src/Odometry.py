#!/usr/bin/env python
# license removed for brevity
import rospy
import rosnode
import math
from nav_msgs.msg import Odometry
from cosmus_communication.msg import Odom
from tf.transformations import euler_from_quaternion, quaternion_from_euler

def get_rotation(x,y,z,w):

    (roll, pitch, yaw) = euler_from_quaternion ([x, y, z, w])
    pitch = -pitch;
    return (roll, pitch, yaw)

def callback(msg):
    data = Odom()

    data.position_x = msg.pose.pose.position.x
    data.position_y = msg.pose.pose.position.y
    data.position_z = msg.pose.pose.position.z

    x_vel = msg.twist.twist.linear.x * msg.twist.twist.linear.x
    y_vel = msg.twist.twist.linear.y * msg.twist.twist.linear.y
    z_vel = msg.twist.twist.linear.z * msg.twist.twist.linear.z
    data.velocity = math.sqrt(x_vel + y_vel + z_vel)

    (data.roll, data.pitch, data.yaw) = get_rotation(msg.pose.pose.orientation.x, msg.pose.pose.orientation.y, msg.pose.pose.orientation.z, msg.pose.pose.orientation.w)

    pub.publish(data)

def client():
    global pub
    global rate
    global ns
    #RateNode = 100 # 100hz
    Queue_Size = 50

    rospy.init_node('odom', anonymous = True)
    pub = rospy.Publisher('ground_truth/Odometry', Odom, queue_size=Queue_Size)
    ns = rospy.get_namespace()
    #rate = rospy.Rate(RateNode)

    #rospy.loginfo("UAV: " + ns + " on")
    rospy.Subscriber(ns + "position", Odometry, callback)
    rospy.spin()

if __name__ == '__main__':
    try:
        client()
    except rospy.ROSInterruptException:
        pass
