#ifndef _ROS_beagle_msgs_BeagleBatteryHVESSD7_h
#define _ROS_beagle_msgs_BeagleBatteryHVESSD7_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryHVESSD7 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _discharge_energy_type;
      _discharge_energy_type discharge_energy;
      typedef float _charge_energy_type;
      _charge_energy_type charge_energy;
      typedef float _max_charge_voltage_limit_type;
      _max_charge_voltage_limit_type max_charge_voltage_limit;

    BeagleBatteryHVESSD7():
      header(),
      discharge_energy(0),
      charge_energy(0),
      max_charge_voltage_limit(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_discharge_energy;
      u_discharge_energy.real = this->discharge_energy;
      *(outbuffer + offset + 0) = (u_discharge_energy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_discharge_energy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_discharge_energy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_discharge_energy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->discharge_energy);
      union {
        float real;
        uint32_t base;
      } u_charge_energy;
      u_charge_energy.real = this->charge_energy;
      *(outbuffer + offset + 0) = (u_charge_energy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charge_energy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charge_energy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charge_energy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charge_energy);
      union {
        float real;
        uint32_t base;
      } u_max_charge_voltage_limit;
      u_max_charge_voltage_limit.real = this->max_charge_voltage_limit;
      *(outbuffer + offset + 0) = (u_max_charge_voltage_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_charge_voltage_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_charge_voltage_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_charge_voltage_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_charge_voltage_limit);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_discharge_energy;
      u_discharge_energy.base = 0;
      u_discharge_energy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_discharge_energy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_discharge_energy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_discharge_energy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->discharge_energy = u_discharge_energy.real;
      offset += sizeof(this->discharge_energy);
      union {
        float real;
        uint32_t base;
      } u_charge_energy;
      u_charge_energy.base = 0;
      u_charge_energy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charge_energy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charge_energy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charge_energy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->charge_energy = u_charge_energy.real;
      offset += sizeof(this->charge_energy);
      union {
        float real;
        uint32_t base;
      } u_max_charge_voltage_limit;
      u_max_charge_voltage_limit.base = 0;
      u_max_charge_voltage_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_charge_voltage_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_charge_voltage_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_charge_voltage_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_charge_voltage_limit = u_max_charge_voltage_limit.real;
      offset += sizeof(this->max_charge_voltage_limit);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryHVESSD7"; };
    virtual const char * getMD5() override { return "b11242ace0ed6c82b41d2dedec489826"; };

  };

}
#endif
