#ifndef _ROS_intrepid_msgs_EdmGeneralStatus_h
#define _ROS_intrepid_msgs_EdmGeneralStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace intrepid_msgs
{

  class EdmGeneralStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _swash_pos_type;
      _swash_pos_type swash_pos;
      typedef float _swash_vel_type;
      _swash_vel_type swash_vel;
      typedef float _current_type;
      _current_type current;
      typedef bool _is_locked_type;
      _is_locked_type is_locked;
      typedef uint8_t _cal_status_type;
      _cal_status_type cal_status;
      typedef uint8_t _control_mode_select_type;
      _control_mode_select_type control_mode_select;
      typedef bool _pos_is_valid_type;
      _pos_is_valid_type pos_is_valid;
      typedef uint8_t _RESERVED_6_type;
      _RESERVED_6_type RESERVED_6;
      typedef uint8_t _locale_type;
      _locale_type locale;
      typedef uint8_t _latched_fault_code_type;
      _latched_fault_code_type latched_fault_code;
      typedef uint8_t _state_type;
      _state_type state;
      enum { STATE_INIT = 0 };
      enum { STATE_NEUTRAL_SERVO = 1 };
      enum { STATE_ENABLED = 2 };
      enum { STATE_LOW_POWER_MODE = 3 };
      enum { STATE_FAIL_REDUCED_FUNCTION = 4 };
      enum { STATE_FAIL_DISABLED_NEUTRAL = 5 };
      enum { STATE_FAIL_DISABLED_NO_DRIVE = 6 };
      enum { STATE_CALIBRATING = 7 };
      enum { STATE_DUTY_CYCLE_OVERRIDE = 8 };

    EdmGeneralStatus():
      header(),
      swash_pos(0),
      swash_vel(0),
      current(0),
      is_locked(0),
      cal_status(0),
      control_mode_select(0),
      pos_is_valid(0),
      RESERVED_6(0),
      locale(0),
      latched_fault_code(0),
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_swash_pos;
      u_swash_pos.real = this->swash_pos;
      *(outbuffer + offset + 0) = (u_swash_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_swash_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_swash_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_swash_pos.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->swash_pos);
      union {
        float real;
        uint32_t base;
      } u_swash_vel;
      u_swash_vel.real = this->swash_vel;
      *(outbuffer + offset + 0) = (u_swash_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_swash_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_swash_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_swash_vel.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->swash_vel);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current);
      union {
        bool real;
        uint8_t base;
      } u_is_locked;
      u_is_locked.real = this->is_locked;
      *(outbuffer + offset + 0) = (u_is_locked.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_locked);
      *(outbuffer + offset + 0) = (this->cal_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cal_status);
      *(outbuffer + offset + 0) = (this->control_mode_select >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_mode_select);
      union {
        bool real;
        uint8_t base;
      } u_pos_is_valid;
      u_pos_is_valid.real = this->pos_is_valid;
      *(outbuffer + offset + 0) = (u_pos_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pos_is_valid);
      *(outbuffer + offset + 0) = (this->RESERVED_6 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->RESERVED_6);
      *(outbuffer + offset + 0) = (this->locale >> (8 * 0)) & 0xFF;
      offset += sizeof(this->locale);
      *(outbuffer + offset + 0) = (this->latched_fault_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->latched_fault_code);
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_swash_pos;
      u_swash_pos.base = 0;
      u_swash_pos.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_swash_pos.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_swash_pos.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_swash_pos.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->swash_pos = u_swash_pos.real;
      offset += sizeof(this->swash_pos);
      union {
        float real;
        uint32_t base;
      } u_swash_vel;
      u_swash_vel.base = 0;
      u_swash_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_swash_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_swash_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_swash_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->swash_vel = u_swash_vel.real;
      offset += sizeof(this->swash_vel);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        bool real;
        uint8_t base;
      } u_is_locked;
      u_is_locked.base = 0;
      u_is_locked.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_locked = u_is_locked.real;
      offset += sizeof(this->is_locked);
      this->cal_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cal_status);
      this->control_mode_select =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->control_mode_select);
      union {
        bool real;
        uint8_t base;
      } u_pos_is_valid;
      u_pos_is_valid.base = 0;
      u_pos_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pos_is_valid = u_pos_is_valid.real;
      offset += sizeof(this->pos_is_valid);
      this->RESERVED_6 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->RESERVED_6);
      this->locale =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->locale);
      this->latched_fault_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->latched_fault_code);
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
     return offset;
    }

    virtual const char * getType() override { return "intrepid_msgs/EdmGeneralStatus"; };
    virtual const char * getMD5() override { return "be3a0a0053b85f64de60697e7c3c2b48"; };

  };

}
#endif
