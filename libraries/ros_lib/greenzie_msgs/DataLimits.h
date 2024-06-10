#ifndef _ROS_greenzie_msgs_DataLimits_h
#define _ROS_greenzie_msgs_DataLimits_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class DataLimits : public ros::Msg
  {
    public:
      typedef bool _engage_limits_type;
      _engage_limits_type engage_limits;
      typedef float _min_type;
      _min_type min;
      typedef float _max_type;
      _max_type max;

    DataLimits():
      engage_limits(0),
      min(0),
      max(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_engage_limits;
      u_engage_limits.real = this->engage_limits;
      *(outbuffer + offset + 0) = (u_engage_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engage_limits);
      offset += serializeAvrFloat64(outbuffer + offset, this->min);
      offset += serializeAvrFloat64(outbuffer + offset, this->max);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_engage_limits;
      u_engage_limits.base = 0;
      u_engage_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engage_limits = u_engage_limits.real;
      offset += sizeof(this->engage_limits);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max));
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/DataLimits"; };
    virtual const char * getMD5() override { return "3ddde13f2c3faf79ccb197ae288ec81f"; };

  };

}
#endif
