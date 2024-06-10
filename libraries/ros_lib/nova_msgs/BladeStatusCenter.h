#ifndef _ROS_nova_msgs_BladeStatusCenter_h
#define _ROS_nova_msgs_BladeStatusCenter_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nova_msgs
{

  class BladeStatusCenter : public ros::Msg
  {
    public:
      typedef int16_t _current_type;
      _current_type current;
      typedef int32_t _velocity_actual_type;
      _velocity_actual_type velocity_actual;
      typedef float _torque_actual_type;
      _torque_actual_type torque_actual;

    BladeStatusCenter():
      current(0),
      velocity_actual(0),
      torque_actual(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current);
      union {
        int32_t real;
        uint32_t base;
      } u_velocity_actual;
      u_velocity_actual.real = this->velocity_actual;
      *(outbuffer + offset + 0) = (u_velocity_actual.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_velocity_actual.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_velocity_actual.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_velocity_actual.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_actual);
      offset += serializeAvrFloat64(outbuffer + offset, this->torque_actual);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        int32_t real;
        uint32_t base;
      } u_velocity_actual;
      u_velocity_actual.base = 0;
      u_velocity_actual.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_velocity_actual.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_velocity_actual.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_velocity_actual.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->velocity_actual = u_velocity_actual.real;
      offset += sizeof(this->velocity_actual);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->torque_actual));
     return offset;
    }

    virtual const char * getType() override { return "nova_msgs/BladeStatusCenter"; };
    virtual const char * getMD5() override { return "4a1d59a4378c028c257b29b402bc9b74"; };

  };

}
#endif
