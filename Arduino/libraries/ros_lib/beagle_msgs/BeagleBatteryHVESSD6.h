#ifndef _ROS_beagle_msgs_BeagleBatteryHVESSD6_h
#define _ROS_beagle_msgs_BeagleBatteryHVESSD6_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryHVESSD6 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _bus_voltage_type;
      _bus_voltage_type bus_voltage;
      typedef float _ignition_voltage_type;
      _ignition_voltage_type ignition_voltage;
      typedef int16_t _electronics_temp_type;
      _electronics_temp_type electronics_temp;

    BeagleBatteryHVESSD6():
      header(),
      bus_voltage(0),
      ignition_voltage(0),
      electronics_temp(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_bus_voltage;
      u_bus_voltage.real = this->bus_voltage;
      *(outbuffer + offset + 0) = (u_bus_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bus_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bus_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bus_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bus_voltage);
      union {
        float real;
        uint32_t base;
      } u_ignition_voltage;
      u_ignition_voltage.real = this->ignition_voltage;
      *(outbuffer + offset + 0) = (u_ignition_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ignition_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ignition_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ignition_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ignition_voltage);
      union {
        int16_t real;
        uint16_t base;
      } u_electronics_temp;
      u_electronics_temp.real = this->electronics_temp;
      *(outbuffer + offset + 0) = (u_electronics_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_electronics_temp.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->electronics_temp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_bus_voltage;
      u_bus_voltage.base = 0;
      u_bus_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bus_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bus_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bus_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bus_voltage = u_bus_voltage.real;
      offset += sizeof(this->bus_voltage);
      union {
        float real;
        uint32_t base;
      } u_ignition_voltage;
      u_ignition_voltage.base = 0;
      u_ignition_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ignition_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ignition_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ignition_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ignition_voltage = u_ignition_voltage.real;
      offset += sizeof(this->ignition_voltage);
      union {
        int16_t real;
        uint16_t base;
      } u_electronics_temp;
      u_electronics_temp.base = 0;
      u_electronics_temp.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_electronics_temp.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->electronics_temp = u_electronics_temp.real;
      offset += sizeof(this->electronics_temp);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryHVESSD6"; };
    virtual const char * getMD5() override { return "7efb3f5a6682ddfcccfd0dccd9b0d4c1"; };

  };

}
#endif
