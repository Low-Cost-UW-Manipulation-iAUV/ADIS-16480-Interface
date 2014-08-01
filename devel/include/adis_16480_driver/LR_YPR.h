/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/euratlhon/ADIS-16480-Interface/src/adis_16480_driver/msg/LR_YPR.msg
 *
 */


#ifndef ADIS_16480_DRIVER_MESSAGE_LR_YPR_H
#define ADIS_16480_DRIVER_MESSAGE_LR_YPR_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <adis_16480_driver/YPR.h>

namespace adis_16480_driver
{
template <class ContainerAllocator>
struct LR_YPR_
{
  typedef LR_YPR_<ContainerAllocator> Type;

  LR_YPR_()
    : header()
    , ypr()  {
    }
  LR_YPR_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , ypr(_alloc)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::adis_16480_driver::YPR_<ContainerAllocator>  _ypr_type;
  _ypr_type ypr;




  typedef boost::shared_ptr< ::adis_16480_driver::LR_YPR_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::adis_16480_driver::LR_YPR_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct LR_YPR_

typedef ::adis_16480_driver::LR_YPR_<std::allocator<void> > LR_YPR;

typedef boost::shared_ptr< ::adis_16480_driver::LR_YPR > LR_YPRPtr;
typedef boost::shared_ptr< ::adis_16480_driver::LR_YPR const> LR_YPRConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::adis_16480_driver::LR_YPR_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::adis_16480_driver::LR_YPR_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace adis_16480_driver

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'adis_16480_driver': ['/home/euratlhon/ADIS-16480-Interface/src/adis_16480_driver/msg'], 'std_msgs': ['/opt/ros/hydro/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::adis_16480_driver::LR_YPR_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::adis_16480_driver::LR_YPR_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::adis_16480_driver::LR_YPR_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::adis_16480_driver::LR_YPR_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::adis_16480_driver::LR_YPR_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::adis_16480_driver::LR_YPR_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::adis_16480_driver::LR_YPR_<ContainerAllocator> >
{
  static const char* value()
  {
    return "02eb98049cf72c79887f313f959e9efe";
  }

  static const char* value(const ::adis_16480_driver::LR_YPR_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x02eb98049cf72c79ULL;
  static const uint64_t static_value2 = 0x887f313f959e9efeULL;
};

template<class ContainerAllocator>
struct DataType< ::adis_16480_driver::LR_YPR_<ContainerAllocator> >
{
  static const char* value()
  {
    return "adis_16480_driver/LR_YPR";
  }

  static const char* value(const ::adis_16480_driver::LR_YPR_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::adis_16480_driver::LR_YPR_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
YPR ypr\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: adis_16480_driver/YPR\n\
float64 yaw\n\
float64 pitch\n\
float64 roll\n\
";
  }

  static const char* value(const ::adis_16480_driver::LR_YPR_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::adis_16480_driver::LR_YPR_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.ypr);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct LR_YPR_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::adis_16480_driver::LR_YPR_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::adis_16480_driver::LR_YPR_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "ypr: ";
    s << std::endl;
    Printer< ::adis_16480_driver::YPR_<ContainerAllocator> >::stream(s, indent + "  ", v.ypr);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ADIS_16480_DRIVER_MESSAGE_LR_YPR_H
