#ifndef _ROS_nova_msgs_BladeStatus_h
#define _ROS_nova_msgs_BladeStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nova_msgs
{

  class BladeStatus : public ros::Msg
  {
    public:
      typedef int16_t _status_word_type;
      _status_word_type status_word;
      typedef int32_t _velocity_actual_type;
      _velocity_actual_type velocity_actual;
      typedef float _torque_actual_type;
      _torque_actual_type torque_actual;

    BladeStatus():
      status_word(0),
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
      } u_status_word;
      u_status_word.real = this->status_word;
      *(outbuffer + offset + 0) = (u_status_word.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_status_word.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->status_word);
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
      } u_status_word;
      u_status_word.base = 0;
      u_status_word.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_status_word.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->status_word = u_status_word.real;
      offset += sizeof(this->status_word);
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

    virtual const char * getType() override { return "nova_msgs/BladeStatus"; };
    virtual const char * getMD5() override { return "a02aa7e6cff4b650c49f36a7b0cd22c3"; };

  };

}
#endif
