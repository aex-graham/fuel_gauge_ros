#ifndef _ROS_beagle_msgs_BeagleBatteryHVESSD5_h
#define _ROS_beagle_msgs_BeagleBatteryHVESSD5_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryHVESSD5 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _discharge_current_limit_type;
      _discharge_current_limit_type discharge_current_limit;
      typedef float _regen_current_limit_type;
      _regen_current_limit_type regen_current_limit;
      typedef float _min_cell_state_of_charge_type;
      _min_cell_state_of_charge_type min_cell_state_of_charge;
      typedef float _max_cell_state_of_charge_type;
      _max_cell_state_of_charge_type max_cell_state_of_charge;

    BeagleBatteryHVESSD5():
      header(),
      discharge_current_limit(0),
      regen_current_limit(0),
      min_cell_state_of_charge(0),
      max_cell_state_of_charge(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_discharge_current_limit;
      u_discharge_current_limit.real = this->discharge_current_limit;
      *(outbuffer + offset + 0) = (u_discharge_current_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_discharge_current_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_discharge_current_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_discharge_current_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->discharge_current_limit);
      union {
        float real;
        uint32_t base;
      } u_regen_current_limit;
      u_regen_current_limit.real = this->regen_current_limit;
      *(outbuffer + offset + 0) = (u_regen_current_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_regen_current_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_regen_current_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_regen_current_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->regen_current_limit);
      union {
        float real;
        uint32_t base;
      } u_min_cell_state_of_charge;
      u_min_cell_state_of_charge.real = this->min_cell_state_of_charge;
      *(outbuffer + offset + 0) = (u_min_cell_state_of_charge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_cell_state_of_charge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_cell_state_of_charge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_cell_state_of_charge.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_cell_state_of_charge);
      union {
        float real;
        uint32_t base;
      } u_max_cell_state_of_charge;
      u_max_cell_state_of_charge.real = this->max_cell_state_of_charge;
      *(outbuffer + offset + 0) = (u_max_cell_state_of_charge.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_cell_state_of_charge.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_cell_state_of_charge.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_cell_state_of_charge.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_cell_state_of_charge);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_discharge_current_limit;
      u_discharge_current_limit.base = 0;
      u_discharge_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_discharge_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_discharge_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_discharge_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->discharge_current_limit = u_discharge_current_limit.real;
      offset += sizeof(this->discharge_current_limit);
      union {
        float real;
        uint32_t base;
      } u_regen_current_limit;
      u_regen_current_limit.base = 0;
      u_regen_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_regen_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_regen_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_regen_current_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->regen_current_limit = u_regen_current_limit.real;
      offset += sizeof(this->regen_current_limit);
      union {
        float real;
        uint32_t base;
      } u_min_cell_state_of_charge;
      u_min_cell_state_of_charge.base = 0;
      u_min_cell_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_cell_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_cell_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_cell_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_cell_state_of_charge = u_min_cell_state_of_charge.real;
      offset += sizeof(this->min_cell_state_of_charge);
      union {
        float real;
        uint32_t base;
      } u_max_cell_state_of_charge;
      u_max_cell_state_of_charge.base = 0;
      u_max_cell_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_cell_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_cell_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_cell_state_of_charge.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_cell_state_of_charge = u_max_cell_state_of_charge.real;
      offset += sizeof(this->max_cell_state_of_charge);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryHVESSD5"; };
    virtual const char * getMD5() override { return "fa3d375998b63c97e2dcdf8f8c701f64"; };

  };

}
#endif
