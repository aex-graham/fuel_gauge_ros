#ifndef _ROS_greenzie_msgs_StateMachineState_h
#define _ROS_greenzie_msgs_StateMachineState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class StateMachineState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _state_type;
      _state_type state;
      typedef float _start_time_type;
      _start_time_type start_time;
      enum { UNDEFINED =  -1 };
      enum { READY =  0 };
      enum { MAP =  1 };
      enum { INIT =  2 };
      enum { MOW =  3 };
      enum { ERROR =  4 };
      enum { VALIDATION =  5 };
      enum { GOTO =  6 };

    StateMachineState():
      header(),
      state(0),
      start_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      offset += serializeAvrFloat64(outbuffer + offset, this->start_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->state = u_state.real;
      offset += sizeof(this->state);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->start_time));
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/StateMachineState"; };
    virtual const char * getMD5() override { return "1660baf0311c400d26622653de527a7c"; };

  };

}
#endif
