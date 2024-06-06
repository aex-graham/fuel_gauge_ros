#ifndef _ROS_beagle_msgs_AsiThrottleStatus_h
#define _ROS_beagle_msgs_AsiThrottleStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "beagle_msgs/AsiStatusCode.h"

namespace beagle_msgs
{

  class AsiThrottleStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _throttle_percentage_type;
      _throttle_percentage_type throttle_percentage;
      typedef float _throttle_angle_rel_type;
      _throttle_angle_rel_type throttle_angle_rel;
      typedef float _throttle_angle_abs_type;
      _throttle_angle_abs_type throttle_angle_abs;
      typedef uint8_t _heartbeat_counter_type;
      _heartbeat_counter_type heartbeat_counter;
      typedef beagle_msgs::AsiStatusCode _asi_status_code_type;
      _asi_status_code_type asi_status_code;

    AsiThrottleStatus():
      header(),
      throttle_percentage(0),
      throttle_angle_rel(0),
      throttle_angle_abs(0),
      heartbeat_counter(0),
      asi_status_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_throttle_percentage;
      u_throttle_percentage.real = this->throttle_percentage;
      *(outbuffer + offset + 0) = (u_throttle_percentage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle_percentage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle_percentage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle_percentage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->throttle_percentage);
      union {
        float real;
        uint32_t base;
      } u_throttle_angle_rel;
      u_throttle_angle_rel.real = this->throttle_angle_rel;
      *(outbuffer + offset + 0) = (u_throttle_angle_rel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle_angle_rel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle_angle_rel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle_angle_rel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->throttle_angle_rel);
      union {
        float real;
        uint32_t base;
      } u_throttle_angle_abs;
      u_throttle_angle_abs.real = this->throttle_angle_abs;
      *(outbuffer + offset + 0) = (u_throttle_angle_abs.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_throttle_angle_abs.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_throttle_angle_abs.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_throttle_angle_abs.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->throttle_angle_abs);
      *(outbuffer + offset + 0) = (this->heartbeat_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->heartbeat_counter);
      offset += this->asi_status_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_throttle_percentage;
      u_throttle_percentage.base = 0;
      u_throttle_percentage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle_percentage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle_percentage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle_percentage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->throttle_percentage = u_throttle_percentage.real;
      offset += sizeof(this->throttle_percentage);
      union {
        float real;
        uint32_t base;
      } u_throttle_angle_rel;
      u_throttle_angle_rel.base = 0;
      u_throttle_angle_rel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle_angle_rel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle_angle_rel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle_angle_rel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->throttle_angle_rel = u_throttle_angle_rel.real;
      offset += sizeof(this->throttle_angle_rel);
      union {
        float real;
        uint32_t base;
      } u_throttle_angle_abs;
      u_throttle_angle_abs.base = 0;
      u_throttle_angle_abs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_throttle_angle_abs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_throttle_angle_abs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_throttle_angle_abs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->throttle_angle_abs = u_throttle_angle_abs.real;
      offset += sizeof(this->throttle_angle_abs);
      this->heartbeat_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->heartbeat_counter);
      offset += this->asi_status_code.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/AsiThrottleStatus"; };
    virtual const char * getMD5() override { return "a7d402b97b24a2d6a87340548000db82"; };

  };

}
#endif
