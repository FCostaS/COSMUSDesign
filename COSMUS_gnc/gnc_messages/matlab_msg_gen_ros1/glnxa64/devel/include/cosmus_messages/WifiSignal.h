// Generated by gencpp from file cosmus_messages/WifiSignal.msg
// DO NOT EDIT!


#ifndef COSMUS_MESSAGES_MESSAGE_WIFISIGNAL_H
#define COSMUS_MESSAGES_MESSAGE_WIFISIGNAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cosmus_messages
{
template <class ContainerAllocator>
struct WifiSignal_
{
  typedef WifiSignal_<ContainerAllocator> Type;

  WifiSignal_()
    : ssid()
    , signal_dbm(0.0)
    , frequency(0.0)  {
    }
  WifiSignal_(const ContainerAllocator& _alloc)
    : ssid(_alloc)
    , signal_dbm(0.0)
    , frequency(0.0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _ssid_type;
  _ssid_type ssid;

   typedef float _signal_dbm_type;
  _signal_dbm_type signal_dbm;

   typedef float _frequency_type;
  _frequency_type frequency;





  typedef boost::shared_ptr< ::cosmus_messages::WifiSignal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cosmus_messages::WifiSignal_<ContainerAllocator> const> ConstPtr;

}; // struct WifiSignal_

typedef ::cosmus_messages::WifiSignal_<std::allocator<void> > WifiSignal;

typedef boost::shared_ptr< ::cosmus_messages::WifiSignal > WifiSignalPtr;
typedef boost::shared_ptr< ::cosmus_messages::WifiSignal const> WifiSignalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cosmus_messages::WifiSignal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cosmus_messages::WifiSignal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cosmus_messages

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'cosmus_messages': ['/home/fabricio/catkin_ws/src/COSMUS_gnc/gnc_messages/matlab_msg_gen_ros1/glnxa64/src/cosmus_messages/msg'], 'std_msgs': ['/home/fabricio/MATLAB/R2021b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg', '/home/fabricio/MATLAB/R2021b/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cosmus_messages::WifiSignal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cosmus_messages::WifiSignal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cosmus_messages::WifiSignal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cosmus_messages::WifiSignal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cosmus_messages::WifiSignal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cosmus_messages::WifiSignal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cosmus_messages::WifiSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "78a42198664f79cded956369f4e3d801";
  }

  static const char* value(const ::cosmus_messages::WifiSignal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x78a42198664f79cdULL;
  static const uint64_t static_value2 = 0xed956369f4e3d801ULL;
};

template<class ContainerAllocator>
struct DataType< ::cosmus_messages::WifiSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cosmus_messages/WifiSignal";
  }

  static const char* value(const ::cosmus_messages::WifiSignal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cosmus_messages::WifiSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Copyright (c) 2017, United States Government, as represented by the\n"
"# Administrator of the National Aeronautics and Space Administration.\n"
"#\n"
"# All rights reserved.\n"
"#\n"
"# The Astrobee platform is licensed under the Apache License, Version 2.0\n"
"# (the \"License\"); you may not use this file except in compliance with the\n"
"# License. You may obtain a copy of the License at\n"
"#\n"
"#     http://www.apache.org/licenses/LICENSE-2.0\n"
"#\n"
"# Unless required by applicable law or agreed to in writing, software\n"
"# distributed under the License is distributed on an \"AS IS\" BASIS, WITHOUT\n"
"# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the\n"
"# License for the specific language governing permissions and limitations\n"
"# under the License.\n"
"#\n"
"# A Wifi signal characteristics\n"
"\n"
"string ssid            # name of AP\n"
"float32   signal_dbm      # dBm\n"
"float32  frequency        # Hz\n"
;
  }

  static const char* value(const ::cosmus_messages::WifiSignal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cosmus_messages::WifiSignal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.ssid);
      stream.next(m.signal_dbm);
      stream.next(m.frequency);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WifiSignal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cosmus_messages::WifiSignal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cosmus_messages::WifiSignal_<ContainerAllocator>& v)
  {
    s << indent << "ssid: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.ssid);
    s << indent << "signal_dbm: ";
    Printer<float>::stream(s, indent + "  ", v.signal_dbm);
    s << indent << "frequency: ";
    Printer<float>::stream(s, indent + "  ", v.frequency);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COSMUS_MESSAGES_MESSAGE_WIFISIGNAL_H