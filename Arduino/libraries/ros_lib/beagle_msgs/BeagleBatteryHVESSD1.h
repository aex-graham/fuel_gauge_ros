#ifndef _ROS_beagle_msgs_BeagleBatteryHVESSD1_h
#define _ROS_beagle_msgs_BeagleBatteryHVESSD1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryHVESSD1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _discharge_power_limit_type;
      _discharge_power_limit_type discharge_power_limit;
      typedef float _charge_power_limit_type;
      _charge_power_limit_type charge_power_limit;
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef float _current_type;
      _current_type current;

    BeagleBatteryHVESSD1():
      header(),
      discharge_power_limit(0),
      charge_power_limit(0),
      voltage(0),
      current(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_discharge_power_limit;
      u_discharge_power_limit.real = this->discharge_power_limit;
      *(outbuffer + offset + 0) = (u_discharge_power_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_discharge_power_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_discharge_power_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_discharge_power_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->discharge_power_limit);
      union {
        float real;
        uint32_t base;
      } u_charge_power_limit;
      u_charge_power_limit.real = this->charge_power_limit;
      *(outbuffer + offset + 0) = (u_charge_power_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charge_power_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charge_power_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charge_power_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charge_power_limit);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_discharge_power_limit;
      u_discharge_power_limit.base = 0;
      u_discharge_power_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_discharge_power_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_discharge_power_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_discharge_power_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->discharge_power_limit = u_discharge_power_limit.real;
      offset += sizeof(this->discharge_power_limit);
      union {
        float real;
        uint32_t base;
      } u_charge_power_limit;
      u_charge_power_limit.base = 0;
      u_charge_power_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charge_power_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charge_power_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charge_power_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->charge_power_limit = u_charge_power_limit.real;
      offset += sizeof(this->charge_power_limit);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
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
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryHVESSD1"; };
    virtual const char * getMD5() override { return "c996e2b32d323c26d628d4506ef66ec3"; };

  };

}
#endif
