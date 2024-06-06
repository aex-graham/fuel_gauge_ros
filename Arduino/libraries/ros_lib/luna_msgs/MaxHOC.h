#ifndef _ROS_luna_msgs_MaxHOC_h
#define _ROS_luna_msgs_MaxHOC_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace luna_msgs
{

  class MaxHOC : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _max_HOC_inches_type;
      _max_HOC_inches_type max_HOC_inches;
      typedef float _min_HOC_inches_type;
      _min_HOC_inches_type min_HOC_inches;

    MaxHOC():
      header(),
      max_HOC_inches(0),
      min_HOC_inches(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_max_HOC_inches;
      u_max_HOC_inches.real = this->max_HOC_inches;
      *(outbuffer + offset + 0) = (u_max_HOC_inches.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_HOC_inches.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_HOC_inches.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_HOC_inches.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_HOC_inches);
      union {
        float real;
        uint32_t base;
      } u_min_HOC_inches;
      u_min_HOC_inches.real = this->min_HOC_inches;
      *(outbuffer + offset + 0) = (u_min_HOC_inches.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_HOC_inches.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_HOC_inches.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_HOC_inches.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_HOC_inches);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_max_HOC_inches;
      u_max_HOC_inches.base = 0;
      u_max_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_HOC_inches = u_max_HOC_inches.real;
      offset += sizeof(this->max_HOC_inches);
      union {
        float real;
        uint32_t base;
      } u_min_HOC_inches;
      u_min_HOC_inches.base = 0;
      u_min_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_HOC_inches = u_min_HOC_inches.real;
      offset += sizeof(this->min_HOC_inches);
     return offset;
    }

    virtual const char * getType() override { return "luna_msgs/MaxHOC"; };
    virtual const char * getMD5() override { return "848196b23b1a56d20c733db16fd1f576"; };

  };

}
#endif
