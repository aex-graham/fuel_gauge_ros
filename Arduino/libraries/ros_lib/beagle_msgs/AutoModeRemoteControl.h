#ifndef _ROS_beagle_msgs_AutoModeRemoteControl_h
#define _ROS_beagle_msgs_AutoModeRemoteControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace beagle_msgs
{

  class AutoModeRemoteControl : public ros::Msg
  {
    public:
      typedef int16_t _left_throttle_type;
      _left_throttle_type left_throttle;
      typedef int16_t _right_throttle_type;
      _right_throttle_type right_throttle;
      typedef bool _pto_switch_type;
      _pto_switch_type pto_switch;
      typedef bool _brake_disengage_type;
      _brake_disengage_type brake_disengage;
      typedef uint8_t _watchdog_counter_type;
      _watchdog_counter_type watchdog_counter;

    AutoModeRemoteControl():
      left_throttle(0),
      right_throttle(0),
      pto_switch(0),
      brake_disengage(0),
      watchdog_counter(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_throttle;
      u_left_throttle.real = this->left_throttle;
      *(outbuffer + offset + 0) = (u_left_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_throttle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_throttle);
      union {
        int16_t real;
        uint16_t base;
      } u_right_throttle;
      u_right_throttle.real = this->right_throttle;
      *(outbuffer + offset + 0) = (u_right_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_throttle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_throttle);
      union {
        bool real;
        uint8_t base;
      } u_pto_switch;
      u_pto_switch.real = this->pto_switch;
      *(outbuffer + offset + 0) = (u_pto_switch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pto_switch);
      union {
        bool real;
        uint8_t base;
      } u_brake_disengage;
      u_brake_disengage.real = this->brake_disengage;
      *(outbuffer + offset + 0) = (u_brake_disengage.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_disengage);
      *(outbuffer + offset + 0) = (this->watchdog_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->watchdog_counter);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_throttle;
      u_left_throttle.base = 0;
      u_left_throttle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_throttle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left_throttle = u_left_throttle.real;
      offset += sizeof(this->left_throttle);
      union {
        int16_t real;
        uint16_t base;
      } u_right_throttle;
      u_right_throttle.base = 0;
      u_right_throttle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_throttle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right_throttle = u_right_throttle.real;
      offset += sizeof(this->right_throttle);
      union {
        bool real;
        uint8_t base;
      } u_pto_switch;
      u_pto_switch.base = 0;
      u_pto_switch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pto_switch = u_pto_switch.real;
      offset += sizeof(this->pto_switch);
      union {
        bool real;
        uint8_t base;
      } u_brake_disengage;
      u_brake_disengage.base = 0;
      u_brake_disengage.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_disengage = u_brake_disengage.real;
      offset += sizeof(this->brake_disengage);
      this->watchdog_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->watchdog_counter);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/AutoModeRemoteControl"; };
    virtual const char * getMD5() override { return "754f2f65a41a9d257885c2ca1293c76e"; };

  };

}
#endif
