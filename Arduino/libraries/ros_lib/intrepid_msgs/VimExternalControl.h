#ifndef _ROS_intrepid_msgs_VimExternalControl_h
#define _ROS_intrepid_msgs_VimExternalControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace intrepid_msgs
{

  class VimExternalControl : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _override_left_lapbar_type;
      _override_left_lapbar_type override_left_lapbar;
      typedef int16_t _override_right_lapbar_type;
      _override_right_lapbar_type override_right_lapbar;
      typedef uint16_t _override_token_response_type;
      _override_token_response_type override_token_response;
      typedef uint8_t _override_latched_fault_type;
      _override_latched_fault_type override_latched_fault;
      typedef bool _override_in_spare_type;
      _override_in_spare_type override_in_spare;
      typedef bool _in_spare_enable_type;
      _in_spare_enable_type in_spare_enable;
      typedef bool _override_in_start_type;
      _override_in_start_type override_in_start;
      typedef bool _in_start_enable_type;
      _in_start_enable_type in_start_enable;
      typedef bool _override_in_operator_presence_type;
      _override_in_operator_presence_type override_in_operator_presence;
      typedef bool _in_operator_presence_enable_type;
      _in_operator_presence_enable_type in_operator_presence_enable;
      typedef bool _override_in_pto_select_type;
      _override_in_pto_select_type override_in_pto_select;
      typedef bool _in_pto_select_enable_type;
      _in_pto_select_enable_type in_pto_select_enable;
      typedef bool _override_in_virtual_type;
      _override_in_virtual_type override_in_virtual;
      typedef bool _in_virtual_enable_type;
      _in_virtual_enable_type in_virtual_enable;
      typedef bool _override_in_hi_lo_type;
      _override_in_hi_lo_type override_in_hi_lo;
      typedef bool _in_hi_lo_enable_type;
      _in_hi_lo_enable_type in_hi_lo_enable;
      typedef bool _override_in_brake_engage_type;
      _override_in_brake_engage_type override_in_brake_engage;
      typedef bool _in_brake_engage_enable_type;
      _in_brake_engage_enable_type in_brake_engage_enable;
      typedef bool _override_in_oil_pressure_type;
      _override_in_oil_pressure_type override_in_oil_pressure;
      typedef bool _in_oil_pressure_enable_type;
      _in_oil_pressure_enable_type in_oil_pressure_enable;

    VimExternalControl():
      header(),
      override_left_lapbar(0),
      override_right_lapbar(0),
      override_token_response(0),
      override_latched_fault(0),
      override_in_spare(0),
      in_spare_enable(0),
      override_in_start(0),
      in_start_enable(0),
      override_in_operator_presence(0),
      in_operator_presence_enable(0),
      override_in_pto_select(0),
      in_pto_select_enable(0),
      override_in_virtual(0),
      in_virtual_enable(0),
      override_in_hi_lo(0),
      in_hi_lo_enable(0),
      override_in_brake_engage(0),
      in_brake_engage_enable(0),
      override_in_oil_pressure(0),
      in_oil_pressure_enable(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_override_left_lapbar;
      u_override_left_lapbar.real = this->override_left_lapbar;
      *(outbuffer + offset + 0) = (u_override_left_lapbar.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_override_left_lapbar.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->override_left_lapbar);
      union {
        int16_t real;
        uint16_t base;
      } u_override_right_lapbar;
      u_override_right_lapbar.real = this->override_right_lapbar;
      *(outbuffer + offset + 0) = (u_override_right_lapbar.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_override_right_lapbar.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->override_right_lapbar);
      *(outbuffer + offset + 0) = (this->override_token_response >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->override_token_response >> (8 * 1)) & 0xFF;
      offset += sizeof(this->override_token_response);
      *(outbuffer + offset + 0) = (this->override_latched_fault >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_latched_fault);
      union {
        bool real;
        uint8_t base;
      } u_override_in_spare;
      u_override_in_spare.real = this->override_in_spare;
      *(outbuffer + offset + 0) = (u_override_in_spare.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_in_spare);
      union {
        bool real;
        uint8_t base;
      } u_in_spare_enable;
      u_in_spare_enable.real = this->in_spare_enable;
      *(outbuffer + offset + 0) = (u_in_spare_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_spare_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_start;
      u_override_in_start.real = this->override_in_start;
      *(outbuffer + offset + 0) = (u_override_in_start.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_in_start);
      union {
        bool real;
        uint8_t base;
      } u_in_start_enable;
      u_in_start_enable.real = this->in_start_enable;
      *(outbuffer + offset + 0) = (u_in_start_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_start_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_operator_presence;
      u_override_in_operator_presence.real = this->override_in_operator_presence;
      *(outbuffer + offset + 0) = (u_override_in_operator_presence.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_in_operator_presence);
      union {
        bool real;
        uint8_t base;
      } u_in_operator_presence_enable;
      u_in_operator_presence_enable.real = this->in_operator_presence_enable;
      *(outbuffer + offset + 0) = (u_in_operator_presence_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_operator_presence_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_pto_select;
      u_override_in_pto_select.real = this->override_in_pto_select;
      *(outbuffer + offset + 0) = (u_override_in_pto_select.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_in_pto_select);
      union {
        bool real;
        uint8_t base;
      } u_in_pto_select_enable;
      u_in_pto_select_enable.real = this->in_pto_select_enable;
      *(outbuffer + offset + 0) = (u_in_pto_select_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_pto_select_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_virtual;
      u_override_in_virtual.real = this->override_in_virtual;
      *(outbuffer + offset + 0) = (u_override_in_virtual.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_in_virtual);
      union {
        bool real;
        uint8_t base;
      } u_in_virtual_enable;
      u_in_virtual_enable.real = this->in_virtual_enable;
      *(outbuffer + offset + 0) = (u_in_virtual_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_virtual_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_hi_lo;
      u_override_in_hi_lo.real = this->override_in_hi_lo;
      *(outbuffer + offset + 0) = (u_override_in_hi_lo.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_in_hi_lo);
      union {
        bool real;
        uint8_t base;
      } u_in_hi_lo_enable;
      u_in_hi_lo_enable.real = this->in_hi_lo_enable;
      *(outbuffer + offset + 0) = (u_in_hi_lo_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_hi_lo_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_brake_engage;
      u_override_in_brake_engage.real = this->override_in_brake_engage;
      *(outbuffer + offset + 0) = (u_override_in_brake_engage.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_in_brake_engage);
      union {
        bool real;
        uint8_t base;
      } u_in_brake_engage_enable;
      u_in_brake_engage_enable.real = this->in_brake_engage_enable;
      *(outbuffer + offset + 0) = (u_in_brake_engage_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_brake_engage_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_oil_pressure;
      u_override_in_oil_pressure.real = this->override_in_oil_pressure;
      *(outbuffer + offset + 0) = (u_override_in_oil_pressure.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->override_in_oil_pressure);
      union {
        bool real;
        uint8_t base;
      } u_in_oil_pressure_enable;
      u_in_oil_pressure_enable.real = this->in_oil_pressure_enable;
      *(outbuffer + offset + 0) = (u_in_oil_pressure_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_oil_pressure_enable);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_override_left_lapbar;
      u_override_left_lapbar.base = 0;
      u_override_left_lapbar.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_override_left_lapbar.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->override_left_lapbar = u_override_left_lapbar.real;
      offset += sizeof(this->override_left_lapbar);
      union {
        int16_t real;
        uint16_t base;
      } u_override_right_lapbar;
      u_override_right_lapbar.base = 0;
      u_override_right_lapbar.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_override_right_lapbar.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->override_right_lapbar = u_override_right_lapbar.real;
      offset += sizeof(this->override_right_lapbar);
      this->override_token_response =  ((uint16_t) (*(inbuffer + offset)));
      this->override_token_response |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->override_token_response);
      this->override_latched_fault =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->override_latched_fault);
      union {
        bool real;
        uint8_t base;
      } u_override_in_spare;
      u_override_in_spare.base = 0;
      u_override_in_spare.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override_in_spare = u_override_in_spare.real;
      offset += sizeof(this->override_in_spare);
      union {
        bool real;
        uint8_t base;
      } u_in_spare_enable;
      u_in_spare_enable.base = 0;
      u_in_spare_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_spare_enable = u_in_spare_enable.real;
      offset += sizeof(this->in_spare_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_start;
      u_override_in_start.base = 0;
      u_override_in_start.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override_in_start = u_override_in_start.real;
      offset += sizeof(this->override_in_start);
      union {
        bool real;
        uint8_t base;
      } u_in_start_enable;
      u_in_start_enable.base = 0;
      u_in_start_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_start_enable = u_in_start_enable.real;
      offset += sizeof(this->in_start_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_operator_presence;
      u_override_in_operator_presence.base = 0;
      u_override_in_operator_presence.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override_in_operator_presence = u_override_in_operator_presence.real;
      offset += sizeof(this->override_in_operator_presence);
      union {
        bool real;
        uint8_t base;
      } u_in_operator_presence_enable;
      u_in_operator_presence_enable.base = 0;
      u_in_operator_presence_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_operator_presence_enable = u_in_operator_presence_enable.real;
      offset += sizeof(this->in_operator_presence_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_pto_select;
      u_override_in_pto_select.base = 0;
      u_override_in_pto_select.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override_in_pto_select = u_override_in_pto_select.real;
      offset += sizeof(this->override_in_pto_select);
      union {
        bool real;
        uint8_t base;
      } u_in_pto_select_enable;
      u_in_pto_select_enable.base = 0;
      u_in_pto_select_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_pto_select_enable = u_in_pto_select_enable.real;
      offset += sizeof(this->in_pto_select_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_virtual;
      u_override_in_virtual.base = 0;
      u_override_in_virtual.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override_in_virtual = u_override_in_virtual.real;
      offset += sizeof(this->override_in_virtual);
      union {
        bool real;
        uint8_t base;
      } u_in_virtual_enable;
      u_in_virtual_enable.base = 0;
      u_in_virtual_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_virtual_enable = u_in_virtual_enable.real;
      offset += sizeof(this->in_virtual_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_hi_lo;
      u_override_in_hi_lo.base = 0;
      u_override_in_hi_lo.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override_in_hi_lo = u_override_in_hi_lo.real;
      offset += sizeof(this->override_in_hi_lo);
      union {
        bool real;
        uint8_t base;
      } u_in_hi_lo_enable;
      u_in_hi_lo_enable.base = 0;
      u_in_hi_lo_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_hi_lo_enable = u_in_hi_lo_enable.real;
      offset += sizeof(this->in_hi_lo_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_brake_engage;
      u_override_in_brake_engage.base = 0;
      u_override_in_brake_engage.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override_in_brake_engage = u_override_in_brake_engage.real;
      offset += sizeof(this->override_in_brake_engage);
      union {
        bool real;
        uint8_t base;
      } u_in_brake_engage_enable;
      u_in_brake_engage_enable.base = 0;
      u_in_brake_engage_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_brake_engage_enable = u_in_brake_engage_enable.real;
      offset += sizeof(this->in_brake_engage_enable);
      union {
        bool real;
        uint8_t base;
      } u_override_in_oil_pressure;
      u_override_in_oil_pressure.base = 0;
      u_override_in_oil_pressure.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->override_in_oil_pressure = u_override_in_oil_pressure.real;
      offset += sizeof(this->override_in_oil_pressure);
      union {
        bool real;
        uint8_t base;
      } u_in_oil_pressure_enable;
      u_in_oil_pressure_enable.base = 0;
      u_in_oil_pressure_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_oil_pressure_enable = u_in_oil_pressure_enable.real;
      offset += sizeof(this->in_oil_pressure_enable);
     return offset;
    }

    virtual const char * getType() override { return "intrepid_msgs/VimExternalControl"; };
    virtual const char * getMD5() override { return "a53ba43c5eef97bdd757a6d2e2895fc9"; };

  };

}
#endif
