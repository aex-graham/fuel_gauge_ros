#ifndef _ROS_argo_msgs_InventusBatteryStatus_h
#define _ROS_argo_msgs_InventusBatteryStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace argo_msgs
{

  class InventusBatteryStatus : public ros::Msg
  {
    public:
      typedef uint8_t _SOC_type;
      _SOC_type SOC;
      typedef uint8_t _SOH_type;
      _SOH_type SOH;
      typedef float _SystemDischargeCurrentLimit_type;
      _SystemDischargeCurrentLimit_type SystemDischargeCurrentLimit;
      typedef float _SystemChargeCurrentLimit_type;
      _SystemChargeCurrentLimit_type SystemChargeCurrentLimit;

    InventusBatteryStatus():
      SOC(0),
      SOH(0),
      SystemDischargeCurrentLimit(0),
      SystemChargeCurrentLimit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->SOC >> (8 * 0)) & 0xFF;
      offset += sizeof(this->SOC);
      *(outbuffer + offset + 0) = (this->SOH >> (8 * 0)) & 0xFF;
      offset += sizeof(this->SOH);
      union {
        float real;
        uint32_t base;
      } u_SystemDischargeCurrentLimit;
      u_SystemDischargeCurrentLimit.real = this->SystemDischargeCurrentLimit;
      *(outbuffer + offset + 0) = (u_SystemDischargeCurrentLimit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_SystemDischargeCurrentLimit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_SystemDischargeCurrentLimit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_SystemDischargeCurrentLimit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->SystemDischargeCurrentLimit);
      union {
        float real;
        uint32_t base;
      } u_SystemChargeCurrentLimit;
      u_SystemChargeCurrentLimit.real = this->SystemChargeCurrentLimit;
      *(outbuffer + offset + 0) = (u_SystemChargeCurrentLimit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_SystemChargeCurrentLimit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_SystemChargeCurrentLimit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_SystemChargeCurrentLimit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->SystemChargeCurrentLimit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->SOC =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->SOC);
      this->SOH =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->SOH);
      union {
        float real;
        uint32_t base;
      } u_SystemDischargeCurrentLimit;
      u_SystemDischargeCurrentLimit.base = 0;
      u_SystemDischargeCurrentLimit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_SystemDischargeCurrentLimit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_SystemDischargeCurrentLimit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_SystemDischargeCurrentLimit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->SystemDischargeCurrentLimit = u_SystemDischargeCurrentLimit.real;
      offset += sizeof(this->SystemDischargeCurrentLimit);
      union {
        float real;
        uint32_t base;
      } u_SystemChargeCurrentLimit;
      u_SystemChargeCurrentLimit.base = 0;
      u_SystemChargeCurrentLimit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_SystemChargeCurrentLimit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_SystemChargeCurrentLimit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_SystemChargeCurrentLimit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->SystemChargeCurrentLimit = u_SystemChargeCurrentLimit.real;
      offset += sizeof(this->SystemChargeCurrentLimit);
     return offset;
    }

    virtual const char * getType() override { return "argo_msgs/InventusBatteryStatus"; };
    virtual const char * getMD5() override { return "37a1f0a4d606d67c67963e48c2bb4258"; };

  };

}
#endif
