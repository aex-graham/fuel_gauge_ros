#ifndef _ROS_beagle_msgs_BeagleBatteryHVESSD2_h
#define _ROS_beagle_msgs_BeagleBatteryHVESSD2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryHVESSD2 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _state_of_charge_type;
      _state_of_charge_type state_of_charge;
      typedef float _highest_cell_voltage_type;
      _highest_cell_voltage_type highest_cell_voltage;
      typedef float _lowest_cell_voltage_type;
      _lowest_cell_voltage_type lowest_cell_voltage;

    BeagleBatteryHVESSD2():
      header(),
      state_of_charge(0),
      highest_cell_voltage(0),
      lowest_cell_voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_state_of_charge;
      u_state_of_charge.real = this->state_of_charge;
      *(outbuffer + offset + 0) = (u_state_of_charge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state_of_charge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state_of_charge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state_of_charge.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_of_charge);
      union {
        float real;
        uint32_t base;
      } u_highest_cell_voltage;
      u_highest_cell_voltage.real = this->highest_cell_voltage;
      *(outbuffer + offset + 0) = (u_highest_cell_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_highest_cell_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_highest_cell_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_highest_cell_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->highest_cell_voltage);
      union {
        float real;
        uint32_t base;
      } u_lowest_cell_voltage;
      u_lowest_cell_voltage.real = this->lowest_cell_voltage;
      *(outbuffer + offset + 0) = (u_lowest_cell_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lowest_cell_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lowest_cell_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lowest_cell_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lowest_cell_voltage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_state_of_charge;
      u_state_of_charge.base = 0;
      u_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state_of_charge = u_state_of_charge.real;
      offset += sizeof(this->state_of_charge);
      union {
        float real;
        uint32_t base;
      } u_highest_cell_voltage;
      u_highest_cell_voltage.base = 0;
      u_highest_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_highest_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_highest_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_highest_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->highest_cell_voltage = u_highest_cell_voltage.real;
      offset += sizeof(this->highest_cell_voltage);
      union {
        float real;
        uint32_t base;
      } u_lowest_cell_voltage;
      u_lowest_cell_voltage.base = 0;
      u_lowest_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lowest_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lowest_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lowest_cell_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lowest_cell_voltage = u_lowest_cell_voltage.real;
      offset += sizeof(this->lowest_cell_voltage);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryHVESSD2"; };
    virtual const char * getMD5() override { return "cf6d0bcb726c65a0ada2170343072aae"; };

  };

}
#endif
