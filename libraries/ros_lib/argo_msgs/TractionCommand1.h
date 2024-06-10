#ifndef _ROS_argo_msgs_TractionCommand1_h
#define _ROS_argo_msgs_TractionCommand1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace argo_msgs
{

  class TractionCommand1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _remote_state_command_type;
      _remote_state_command_type remote_state_command;
      typedef uint8_t _watchdog_counter_type;
      _watchdog_counter_type watchdog_counter;
      typedef float _remote_maximum_motor_current_type;
      _remote_maximum_motor_current_type remote_maximum_motor_current;
      typedef float _remote_maximum_braking_current_type;
      _remote_maximum_braking_current_type remote_maximum_braking_current;
      typedef float _remote_speed_command_type;
      _remote_speed_command_type remote_speed_command;
      enum { REMOTE_STATE_COMMAND_OFF =  0 };
      enum { REMOTE_STATE_COMMAND_IDLE =  1 };
      enum { REMOTE_STATE_COMMAND_ACTIVE =  2 };

    TractionCommand1():
      header(),
      remote_state_command(0),
      watchdog_counter(0),
      remote_maximum_motor_current(0),
      remote_maximum_braking_current(0),
      remote_speed_command(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->remote_state_command >> (8 * 0)) & 0xFF;
      offset += sizeof(this->remote_state_command);
      *(outbuffer + offset + 0) = (this->watchdog_counter >> (8 * 0)) & 0xFF;
      offset += sizeof(this->watchdog_counter);
      union {
        float real;
        uint32_t base;
      } u_remote_maximum_motor_current;
      u_remote_maximum_motor_current.real = this->remote_maximum_motor_current;
      *(outbuffer + offset + 0) = (u_remote_maximum_motor_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_remote_maximum_motor_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_remote_maximum_motor_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_remote_maximum_motor_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remote_maximum_motor_current);
      union {
        float real;
        uint32_t base;
      } u_remote_maximum_braking_current;
      u_remote_maximum_braking_current.real = this->remote_maximum_braking_current;
      *(outbuffer + offset + 0) = (u_remote_maximum_braking_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_remote_maximum_braking_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_remote_maximum_braking_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_remote_maximum_braking_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remote_maximum_braking_current);
      union {
        float real;
        uint32_t base;
      } u_remote_speed_command;
      u_remote_speed_command.real = this->remote_speed_command;
      *(outbuffer + offset + 0) = (u_remote_speed_command.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_remote_speed_command.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_remote_speed_command.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_remote_speed_command.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->remote_speed_command);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->remote_state_command =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->remote_state_command);
      this->watchdog_counter =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->watchdog_counter);
      union {
        float real;
        uint32_t base;
      } u_remote_maximum_motor_current;
      u_remote_maximum_motor_current.base = 0;
      u_remote_maximum_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_remote_maximum_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_remote_maximum_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_remote_maximum_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->remote_maximum_motor_current = u_remote_maximum_motor_current.real;
      offset += sizeof(this->remote_maximum_motor_current);
      union {
        float real;
        uint32_t base;
      } u_remote_maximum_braking_current;
      u_remote_maximum_braking_current.base = 0;
      u_remote_maximum_braking_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_remote_maximum_braking_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_remote_maximum_braking_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_remote_maximum_braking_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->remote_maximum_braking_current = u_remote_maximum_braking_current.real;
      offset += sizeof(this->remote_maximum_braking_current);
      union {
        float real;
        uint32_t base;
      } u_remote_speed_command;
      u_remote_speed_command.base = 0;
      u_remote_speed_command.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_remote_speed_command.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_remote_speed_command.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_remote_speed_command.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->remote_speed_command = u_remote_speed_command.real;
      offset += sizeof(this->remote_speed_command);
     return offset;
    }

    virtual const char * getType() override { return "argo_msgs/TractionCommand1"; };
    virtual const char * getMD5() override { return "2b17310cd07bedddb9152e297407aa94"; };

  };

}
#endif
