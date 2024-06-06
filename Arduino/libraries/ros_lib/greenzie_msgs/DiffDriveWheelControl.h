#ifndef _ROS_greenzie_msgs_DiffDriveWheelControl_h
#define _ROS_greenzie_msgs_DiffDriveWheelControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class DiffDriveWheelControl : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _setpoint_left_type;
      _setpoint_left_type setpoint_left;
      typedef float _setpoint_right_type;
      _setpoint_right_type setpoint_right;

    DiffDriveWheelControl():
      header(),
      setpoint_left(0),
      setpoint_right(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint_left);
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint_right);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint_left));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint_right));
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/DiffDriveWheelControl"; };
    virtual const char * getMD5() override { return "87188bdd716025d73ef59aff1575bc49"; };

  };

}
#endif
