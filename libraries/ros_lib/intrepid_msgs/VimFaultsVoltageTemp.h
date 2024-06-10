#ifndef _ROS_intrepid_msgs_VimFaultsVoltageTemp_h
#define _ROS_intrepid_msgs_VimFaultsVoltageTemp_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace intrepid_msgs
{

  class VimFaultsVoltageTemp : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _current_fault_code_type;
      _current_fault_code_type current_fault_code;
      typedef uint8_t _current_fault_locale_type;
      _current_fault_locale_type current_fault_locale;
      typedef float _operation_time_sec_type;
      _operation_time_sec_type operation_time_sec;
      typedef float _temp_deg_c_type;
      _temp_deg_c_type temp_deg_c;
      typedef uint8_t _latched_fault_code_type;
      _latched_fault_code_type latched_fault_code;
      typedef uint8_t _latched_fault_locale_type;
      _latched_fault_locale_type latched_fault_locale;
      typedef float _battery_voltage_type;
      _battery_voltage_type battery_voltage;

    VimFaultsVoltageTemp():
      header(),
      current_fault_code(0),
      current_fault_locale(0),
      operation_time_sec(0),
      temp_deg_c(0),
      latched_fault_code(0),
      latched_fault_locale(0),
      battery_voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->current_fault_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_fault_code);
      *(outbuffer + offset + 0) = (this->current_fault_locale >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_fault_locale);
      offset += serializeAvrFloat64(outbuffer + offset, this->operation_time_sec);
      union {
        float real;
        uint32_t base;
      } u_temp_deg_c;
      u_temp_deg_c.real = this->temp_deg_c;
      *(outbuffer + offset + 0) = (u_temp_deg_c.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp_deg_c.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temp_deg_c.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temp_deg_c.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temp_deg_c);
      *(outbuffer + offset + 0) = (this->latched_fault_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->latched_fault_code);
      *(outbuffer + offset + 0) = (this->latched_fault_locale >> (8 * 0)) & 0xFF;
      offset += sizeof(this->latched_fault_locale);
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
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->current_fault_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->current_fault_code);
      this->current_fault_locale =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->current_fault_locale);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->operation_time_sec));
      union {
        float real;
        uint32_t base;
      } u_temp_deg_c;
      u_temp_deg_c.base = 0;
      u_temp_deg_c.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp_deg_c.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temp_deg_c.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temp_deg_c.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temp_deg_c = u_temp_deg_c.real;
      offset += sizeof(this->temp_deg_c);
      this->latched_fault_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->latched_fault_code);
      this->latched_fault_locale =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->latched_fault_locale);
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
     return offset;
    }

    virtual const char * getType() override { return "intrepid_msgs/VimFaultsVoltageTemp"; };
    virtual const char * getMD5() override { return "2f997b2e2df25905447fe21832e8ad11"; };

  };

}
#endif
