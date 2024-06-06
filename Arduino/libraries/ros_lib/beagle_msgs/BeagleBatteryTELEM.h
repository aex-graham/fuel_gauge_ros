#ifndef _ROS_beagle_msgs_BeagleBatteryTELEM_h
#define _ROS_beagle_msgs_BeagleBatteryTELEM_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryTELEM : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _run_mode_type;
      _run_mode_type run_mode;
      typedef uint8_t _tfault_type;
      _tfault_type tfault;
      typedef uint16_t _discharge_capacity_type;
      _discharge_capacity_type discharge_capacity;
      typedef float _battery_voltage_type;
      _battery_voltage_type battery_voltage;
      typedef float _battery_current_type;
      _battery_current_type battery_current;

    BeagleBatteryTELEM():
      header(),
      run_mode(0),
      tfault(0),
      discharge_capacity(0),
      battery_voltage(0),
      battery_current(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->run_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->run_mode);
      *(outbuffer + offset + 0) = (this->tfault >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tfault);
      *(outbuffer + offset + 0) = (this->discharge_capacity >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->discharge_capacity >> (8 * 1)) & 0xFF;
      offset += sizeof(this->discharge_capacity);
      union {
        float real;
        uint32_t base;
      } u_battery_voltage;
      u_battery_voltage.real = this->battery_voltage;
      *(outbuffer + offset + 0) = (u_battery_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_battery_current;
      u_battery_current.real = this->battery_current;
      *(outbuffer + offset + 0) = (u_battery_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_current);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->run_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->run_mode);
      this->tfault =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->tfault);
      this->discharge_capacity =  ((uint16_t) (*(inbuffer + offset)));
      this->discharge_capacity |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->discharge_capacity);
      union {
        float real;
        uint32_t base;
      } u_battery_voltage;
      u_battery_voltage.base = 0;
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_voltage = u_battery_voltage.real;
      offset += sizeof(this->battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_battery_current;
      u_battery_current.base = 0;
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_current = u_battery_current.real;
      offset += sizeof(this->battery_current);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryTELEM"; };
    virtual const char * getMD5() override { return "c444e1c0ccae6bc4ff4d514d91b82aeb"; };

  };

}
#endif
