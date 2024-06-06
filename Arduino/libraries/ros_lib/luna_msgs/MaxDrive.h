#ifndef _ROS_luna_msgs_MaxDrive_h
#define _ROS_luna_msgs_MaxDrive_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace luna_msgs
{

  class MaxDrive : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _max_forward_linear_vel_type;
      _max_forward_linear_vel_type max_forward_linear_vel;
      typedef float _max_reverse_linear_vel_type;
      _max_reverse_linear_vel_type max_reverse_linear_vel;
      typedef float _max_left_angular_rate_type;
      _max_left_angular_rate_type max_left_angular_rate;
      typedef float _max_right_angular_rate_type;
      _max_right_angular_rate_type max_right_angular_rate;

    MaxDrive():
      header(),
      max_forward_linear_vel(0),
      max_reverse_linear_vel(0),
      max_left_angular_rate(0),
      max_right_angular_rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_max_forward_linear_vel;
      u_max_forward_linear_vel.real = this->max_forward_linear_vel;
      *(outbuffer + offset + 0) = (u_max_forward_linear_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_forward_linear_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_forward_linear_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_forward_linear_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_forward_linear_vel);
      union {
        float real;
        uint32_t base;
      } u_max_reverse_linear_vel;
      u_max_reverse_linear_vel.real = this->max_reverse_linear_vel;
      *(outbuffer + offset + 0) = (u_max_reverse_linear_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_reverse_linear_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_reverse_linear_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_reverse_linear_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_reverse_linear_vel);
      union {
        float real;
        uint32_t base;
      } u_max_left_angular_rate;
      u_max_left_angular_rate.real = this->max_left_angular_rate;
      *(outbuffer + offset + 0) = (u_max_left_angular_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_left_angular_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_left_angular_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_left_angular_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_left_angular_rate);
      union {
        float real;
        uint32_t base;
      } u_max_right_angular_rate;
      u_max_right_angular_rate.real = this->max_right_angular_rate;
      *(outbuffer + offset + 0) = (u_max_right_angular_rate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_right_angular_rate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_right_angular_rate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_right_angular_rate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_right_angular_rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_max_forward_linear_vel;
      u_max_forward_linear_vel.base = 0;
      u_max_forward_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_forward_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_forward_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_forward_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_forward_linear_vel = u_max_forward_linear_vel.real;
      offset += sizeof(this->max_forward_linear_vel);
      union {
        float real;
        uint32_t base;
      } u_max_reverse_linear_vel;
      u_max_reverse_linear_vel.base = 0;
      u_max_reverse_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_reverse_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_reverse_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_reverse_linear_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_reverse_linear_vel = u_max_reverse_linear_vel.real;
      offset += sizeof(this->max_reverse_linear_vel);
      union {
        float real;
        uint32_t base;
      } u_max_left_angular_rate;
      u_max_left_angular_rate.base = 0;
      u_max_left_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_left_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_left_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_left_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_left_angular_rate = u_max_left_angular_rate.real;
      offset += sizeof(this->max_left_angular_rate);
      union {
        float real;
        uint32_t base;
      } u_max_right_angular_rate;
      u_max_right_angular_rate.base = 0;
      u_max_right_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_right_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_right_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_right_angular_rate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_right_angular_rate = u_max_right_angular_rate.real;
      offset += sizeof(this->max_right_angular_rate);
     return offset;
    }

    virtual const char * getType() override { return "luna_msgs/MaxDrive"; };
    virtual const char * getMD5() override { return "3b0c416370f6ba3f43dd705133a82459"; };

  };

}
#endif
