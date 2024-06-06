#ifndef _ROS_beagle_msgs_BeagleBatteryHVESSD4_h
#define _ROS_beagle_msgs_BeagleBatteryHVESSD4_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryHVESSD4 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _discharge_capacity_type;
      _discharge_capacity_type discharge_capacity;
      typedef float _charge_capacity_type;
      _charge_capacity_type charge_capacity;
      typedef uint16_t _cell_balancing_count_type;
      _cell_balancing_count_type cell_balancing_count;

    BeagleBatteryHVESSD4():
      header(),
      discharge_capacity(0),
      charge_capacity(0),
      cell_balancing_count(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      } u_charge_capacity;
      u_charge_capacity.real = this->charge_capacity;
      *(outbuffer + offset + 0) = (u_charge_capacity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charge_capacity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charge_capacity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charge_capacity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charge_capacity);
      *(outbuffer + offset + 0) = (this->cell_balancing_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cell_balancing_count >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cell_balancing_count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
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
      } u_charge_capacity;
      u_charge_capacity.base = 0;
      u_charge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charge_capacity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->charge_capacity = u_charge_capacity.real;
      offset += sizeof(this->charge_capacity);
      this->cell_balancing_count =  ((uint16_t) (*(inbuffer + offset)));
      this->cell_balancing_count |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->cell_balancing_count);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryHVESSD4"; };
    virtual const char * getMD5() override { return "b3d21393b59c485185075befee740499"; };

  };

}
#endif
