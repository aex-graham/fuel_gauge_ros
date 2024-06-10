#ifndef _ROS_beagle_msgs_BeagleBatteryHVESSD8_h
#define _ROS_beagle_msgs_BeagleBatteryHVESSD8_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryHVESSD8 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _high_cell_volt_mod_type;
      _high_cell_volt_mod_type high_cell_volt_mod;
      typedef uint8_t _high_cell_volt_cell_type;
      _high_cell_volt_cell_type high_cell_volt_cell;
      typedef uint8_t _low_cell_volt_mod_type;
      _low_cell_volt_mod_type low_cell_volt_mod;
      typedef uint8_t _low_cell_volt_cell_type;
      _low_cell_volt_cell_type low_cell_volt_cell;
      typedef float _average_cell_voltage_type;
      _average_cell_voltage_type average_cell_voltage;

    BeagleBatteryHVESSD8():
      header(),
      high_cell_volt_mod(0),
      high_cell_volt_cell(0),
      low_cell_volt_mod(0),
      low_cell_volt_cell(0),
      average_cell_voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->high_cell_volt_mod >> (8 * 0)) & 0xFF;
      offset += sizeof(this->high_cell_volt_mod);
      *(outbuffer + offset + 0) = (this->high_cell_volt_cell >> (8 * 0)) & 0xFF;
      offset += sizeof(this->high_cell_volt_cell);
      *(outbuffer + offset + 0) = (this->low_cell_volt_mod >> (8 * 0)) & 0xFF;
      offset += sizeof(this->low_cell_volt_mod);
      *(outbuffer + offset + 0) = (this->low_cell_volt_cell >> (8 * 0)) & 0xFF;
      offset += sizeof(this->low_cell_volt_cell);
      union {
        float real;
        uint32_t base;
      } u_average_cell_voltage;
      u_average_cell_voltage.real = this->average_cell_voltage;
      *(outbuffer + offset + 0) = (u_average_cell_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_average_cell_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_average_cell_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_average_cell_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->average_cell_voltage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->high_cell_volt_mod =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->high_cell_volt_mod);
      this->high_cell_volt_cell =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->high_cell_volt_cell);
      this->low_cell_volt_mod =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->low_cell_volt_mod);
      this->low_cell_volt_cell =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->low_cell_volt_cell);
      union {
        float real;
        uint32_t base;
      } u_average_cell_voltage;
      u_average_cell_voltage.base = 0;
      u_average_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_average_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_average_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_average_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->average_cell_voltage = u_average_cell_voltage.real;
      offset += sizeof(this->average_cell_voltage);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryHVESSD8"; };
    virtual const char * getMD5() override { return "589224687cb52e2220e4a5da1a37198f"; };

  };

}
#endif
