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
 * Auto-generated by genmsg_cpp from file /home/euratlhon/ADIS-16480-Interface/src/adis_16480_driver/srv/doEKFReset.srv
 *
 */


#ifndef ADIS_16480_DRIVER_MESSAGE_DOEKFRESETRESPONSE_H
#define ADIS_16480_DRIVER_MESSAGE_DOEKFRESETRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace adis_16480_driver
{
template <class ContainerAllocator>
struct doEKFResetResponse_
{
  typedef doEKFResetResponse_<ContainerAllocator> Type;

  doEKFResetResponse_()
    : confirm(0)  {
    }
  doEKFResetResponse_(const ContainerAllocator& _alloc)
    : confirm(0)  {
    }



   typedef uint8_t _confirm_type;
  _confirm_type confirm;




  typedef boost::shared_ptr< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct doEKFResetResponse_

typedef ::adis_16480_driver::doEKFResetResponse_<std::allocator<void> > doEKFResetResponse;

typedef boost::shared_ptr< ::adis_16480_driver::doEKFResetResponse > doEKFResetResponsePtr;
typedef boost::shared_ptr< ::adis_16480_driver::doEKFResetResponse const> doEKFResetResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace adis_16480_driver

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'adis_16480_driver': ['/home/euratlhon/ADIS-16480-Interface/src/adis_16480_driver/msg'], 'std_msgs': ['/opt/ros/hydro/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7423cadd06f6bc2a62eec11c489f2e92";
  }

  static const char* value(const ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7423cadd06f6bc2aULL;
  static const uint64_t static_value2 = 0x62eec11c489f2e92ULL;
};

template<class ContainerAllocator>
struct DataType< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "adis_16480_driver/doEKFResetResponse";
  }

  static const char* value(const ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 confirm\n\
";
  }

  static const char* value(const ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.confirm);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct doEKFResetResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::adis_16480_driver::doEKFResetResponse_<ContainerAllocator>& v)
  {
    s << indent << "confirm: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.confirm);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ADIS_16480_DRIVER_MESSAGE_DOEKFRESETRESPONSE_H
