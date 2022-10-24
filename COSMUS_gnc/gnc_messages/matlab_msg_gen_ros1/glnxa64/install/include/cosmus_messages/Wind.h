// Generated by gencpp from file cosmus_messages/Wind.msg
// DO NOT EDIT!


#ifndef COSMUS_MESSAGES_MESSAGE_WIND_H
#define COSMUS_MESSAGES_MESSAGE_WIND_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <cosmus_messages/Vector3D.h>

namespace cosmus_messages
{
template <class ContainerAllocator>
struct Wind_
{
  typedef Wind_<ContainerAllocator> Type;

  Wind_()
    : frame_id()
    , time_usec(0)
    , velocity()  {
    }
  Wind_(const ContainerAllocator& _alloc)
    : frame_id(_alloc)
    , time_usec(0)
    , velocity(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _frame_id_type;
  _frame_id_type frame_id;

   typedef int64_t _time_usec_type;
  _time_usec_type time_usec;

   typedef  ::cosmus_messages::Vector3D_<ContainerAllocator>  _velocity_type;
  _velocity_type velocity;





  typedef boost::shared_ptr< ::cosmus_messages::Wind_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cosmus_messages::Wind_<ContainerAllocator> const> ConstPtr;

}; // struct Wind_

typedef ::cosmus_messages::Wind_<std::allocator<void> > Wind;

typedef boost::shared_ptr< ::cosmus_messages::Wind > WindPtr;
typedef boost::shared_ptr< ::cosmus_messages::Wind const> WindConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cosmus_messages::Wind_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cosmus_messages::Wind_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::cosmus_messages::Wind_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cosmus_messages::Wind_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cosmus_messages::Wind_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cosmus_messages::Wind_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cosmus_messages::Wind_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cosmus_messages::Wind_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cosmus_messages::Wind_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5c75feb886f80a82c19f1632ee37220a";
  }

  static const char* value(const ::cosmus_messages::Wind_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5c75feb886f80a82ULL;
  static const uint64_t static_value2 = 0xc19f1632ee37220aULL;
};

template<class ContainerAllocator>
struct DataType< ::cosmus_messages::Wind_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cosmus_messages/Wind";
  }

  static const char* value(const ::cosmus_messages::Wind_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cosmus_messages::Wind_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string frame_id\n"
"int64 time_usec\n"
"cosmus_messages/Vector3D velocity\n"
"\n"
"================================================================================\n"
"MSG: cosmus_messages/Vector3D\n"
"# ingroup subt_msgs\n"
"# interface Datagram\n"
"# A message containing some payload to communicate among one or\n"
"# multiple teammates.\n"
"\n"
"float32 x\n"
"float32 y\n"
"float32 z\n"
;
  }

  static const char* value(const ::cosmus_messages::Wind_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cosmus_messages::Wind_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.frame_id);
      stream.next(m.time_usec);
      stream.next(m.velocity);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Wind_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cosmus_messages::Wind_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cosmus_messages::Wind_<ContainerAllocator>& v)
  {
    s << indent << "frame_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.frame_id);
    s << indent << "time_usec: ";
    Printer<int64_t>::stream(s, indent + "  ", v.time_usec);
    s << indent << "velocity: ";
    s << std::endl;
    Printer< ::cosmus_messages::Vector3D_<ContainerAllocator> >::stream(s, indent + "  ", v.velocity);
  }
};

} // namespace message_operations
} // namespace ros

#endif // COSMUS_MESSAGES_MESSAGE_WIND_H