#ifndef _ROS_beagle_msgs_BeagleBatteryInfo_h
#define _ROS_beagle_msgs_BeagleBatteryInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef float _current_type;
      _current_type current;
      typedef float _state_of_charge_type;
      _state_of_charge_type state_of_charge;
      typedef float _discharge_capacity_type;
      _discharge_capacity_type discharge_capacity;
      typedef float _average_cell_temp_type;
      _average_cell_temp_type average_cell_temp;

    BeagleBatteryInfo():
      header(),
      voltage(0),
      current(0),
      state_of_charge(0),
      discharge_capacity(0),
      average_cell_temp(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      } u_discharge_capacity;
      u_discharge_capacity.real = this->discharge_capacity;
      *(outbuffer + offset + 0) = (u_discharge_capacity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_discharge_capacity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_discharge_capacity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_discharge_capacity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->discharge_capacity);
      union {
        float real;
        uint32_t base;
      } u_average_cell_temp;
      u_average_cell_temp.real = this->average_cell_temp;
      *(outbuffer + offset + 0) = (u_average_cell_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_average_cell_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_average_cell_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_average_cell_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->average_cell_temp);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      } u_discharge_capacity;
      u_discharge_capacity.base = 0;
      u_discharge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_discharge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_discharge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_discharge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->discharge_capacity = u_discharge_capacity.real;
      offset += sizeof(this->discharge_capacity);
      union {
        float real;
        uint32_t base;
      } u_average_cell_temp;
      u_average_cell_temp.base = 0;
      u_average_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_average_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_average_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_average_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->average_cell_temp = u_average_cell_temp.real;
      offset += sizeof(this->average_cell_temp);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryInfo"; };
    virtual const char * getMD5() override { return "f22f1cb1ceb0363d34cb89821e6f29c8"; };

  };

}
#endif
