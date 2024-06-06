#ifndef _ROS_SERVICE_SetBlades_h
#define _ROS_SERVICE_SetBlades_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

static const char SETBLADES[] = "greenzie_msgs/SetBlades";

  class SetBladesRequest : public ros::Msg
  {
    public:
      typedef bool _enable_blades_type;
      _enable_blades_type enable_blades;

    SetBladesRequest():
      enable_blades(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable_blades;
      u_enable_blades.real = this->enable_blades;
      *(outbuffer + offset + 0) = (u_enable_blades.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_blades);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable_blades;
      u_enable_blades.base = 0;
      u_enable_blades.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_blades = u_enable_blades.real;
      offset += sizeof(this->enable_blades);
     return offset;
    }

    virtual const char * getType() override { return SETBLADES; };
    virtual const char * getMD5() override { return "b2a1e344aeb20d2649ee33c31afca3cb"; };

  };

  class SetBladesResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetBladesResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return SETBLADES; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetBlades {
    public:
    typedef SetBladesRequest Request;
    typedef SetBladesResponse Response;
  };

}
#endif
