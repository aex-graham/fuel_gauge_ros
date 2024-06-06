#ifndef _ROS_SERVICE_HardwareInterfacePowerControl_h
#define _ROS_SERVICE_HardwareInterfacePowerControl_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace argo_msgs
{

static const char HARDWAREINTERFACEPOWERCONTROL[] = "argo_msgs/HardwareInterfacePowerControl";

  class HardwareInterfacePowerControlRequest : public ros::Msg
  {
    public:
      typedef bool _enable_aux_pwr_0_type;
      _enable_aux_pwr_0_type enable_aux_pwr_0;
      typedef bool _enable_aux_pwr_1_type;
      _enable_aux_pwr_1_type enable_aux_pwr_1;

    HardwareInterfacePowerControlRequest():
      enable_aux_pwr_0(0),
      enable_aux_pwr_1(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable_aux_pwr_0;
      u_enable_aux_pwr_0.real = this->enable_aux_pwr_0;
      *(outbuffer + offset + 0) = (u_enable_aux_pwr_0.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_aux_pwr_0);
      union {
        bool real;
        uint8_t base;
      } u_enable_aux_pwr_1;
      u_enable_aux_pwr_1.real = this->enable_aux_pwr_1;
      *(outbuffer + offset + 0) = (u_enable_aux_pwr_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_aux_pwr_1);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable_aux_pwr_0;
      u_enable_aux_pwr_0.base = 0;
      u_enable_aux_pwr_0.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_aux_pwr_0 = u_enable_aux_pwr_0.real;
      offset += sizeof(this->enable_aux_pwr_0);
      union {
        bool real;
        uint8_t base;
      } u_enable_aux_pwr_1;
      u_enable_aux_pwr_1.base = 0;
      u_enable_aux_pwr_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_aux_pwr_1 = u_enable_aux_pwr_1.real;
      offset += sizeof(this->enable_aux_pwr_1);
     return offset;
    }

    virtual const char * getType() override { return HARDWAREINTERFACEPOWERCONTROL; };
    virtual const char * getMD5() override { return "021a1076798d7496b570a80a329fc94c"; };

  };

  class HardwareInterfacePowerControlResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    HardwareInterfacePowerControlResponse():
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

    virtual const char * getType() override { return HARDWAREINTERFACEPOWERCONTROL; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class HardwareInterfacePowerControl {
    public:
    typedef HardwareInterfacePowerControlRequest Request;
    typedef HardwareInterfacePowerControlResponse Response;
  };

}
#endif
