#ifndef _ROS_greenzie_msgs_EngineControl_h
#define _ROS_greenzie_msgs_EngineControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class EngineControl : public ros::Msg
  {
    public:
      typedef int8_t _engine_status_type;
      _engine_status_type engine_status;
      enum { ENGINE_OFF =  0 };
      enum { ENGINE_ON =  1 };
      enum { ENGINE_START =  2 };

    EngineControl():
      engine_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_engine_status;
      u_engine_status.real = this->engine_status;
      *(outbuffer + offset + 0) = (u_engine_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_engine_status;
      u_engine_status.base = 0;
      u_engine_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_status = u_engine_status.real;
      offset += sizeof(this->engine_status);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/EngineControl"; };
    virtual const char * getMD5() override { return "91c380cb6190e0c963e99ac060e51c5b"; };

  };

}
#endif
