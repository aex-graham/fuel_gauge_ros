#ifndef _ROS_beagle_msgs_BeagleBatteryHYBRID_h
#define _ROS_beagle_msgs_BeagleBatteryHYBRID_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryHYBRID : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _hybrid_enable_type;
      _hybrid_enable_type hybrid_enable;
      typedef uint8_t _charge_mode_type;
      _charge_mode_type charge_mode;
      typedef uint16_t _charge_current_limit_type;
      _charge_current_limit_type charge_current_limit;
      typedef float _charge_voltage_limit_type;
      _charge_voltage_limit_type charge_voltage_limit;
      typedef float _current_delta_type;
      _current_delta_type current_delta;
      typedef bool _master_loss_type;
      _master_loss_type master_loss;
      typedef uint8_t _charge_rev_type;
      _charge_rev_type charge_rev;

    BeagleBatteryHYBRID():
      header(),
      hybrid_enable(0),
      charge_mode(0),
      charge_current_limit(0),
      charge_voltage_limit(0),
      current_delta(0),
      master_loss(0),
      charge_rev(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_hybrid_enable;
      u_hybrid_enable.real = this->hybrid_enable;
      *(outbuffer + offset + 0) = (u_hybrid_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hybrid_enable);
      *(outbuffer + offset + 0) = (this->charge_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charge_mode);
      *(outbuffer + offset + 0) = (this->charge_current_limit >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->charge_current_limit >> (8 * 1)) & 0xFF;
      offset += sizeof(this->charge_current_limit);
      union {
        float real;
        uint32_t base;
      } u_charge_voltage_limit;
      u_charge_voltage_limit.real = this->charge_voltage_limit;
      *(outbuffer + offset + 0) = (u_charge_voltage_limit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_charge_voltage_limit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_charge_voltage_limit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_charge_voltage_limit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->charge_voltage_limit);
      union {
        float real;
        uint32_t base;
      } u_current_delta;
      u_current_delta.real = this->current_delta;
      *(outbuffer + offset + 0) = (u_current_delta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_delta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_delta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_delta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_delta);
      union {
        bool real;
        uint8_t base;
      } u_master_loss;
      u_master_loss.real = this->master_loss;
      *(outbuffer + offset + 0) = (u_master_loss.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->master_loss);
      *(outbuffer + offset + 0) = (this->charge_rev >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charge_rev);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_hybrid_enable;
      u_hybrid_enable.base = 0;
      u_hybrid_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hybrid_enable = u_hybrid_enable.real;
      offset += sizeof(this->hybrid_enable);
      this->charge_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->charge_mode);
      this->charge_current_limit =  ((uint16_t) (*(inbuffer + offset)));
      this->charge_current_limit |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->charge_current_limit);
      union {
        float real;
        uint32_t base;
      } u_charge_voltage_limit;
      u_charge_voltage_limit.base = 0;
      u_charge_voltage_limit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_charge_voltage_limit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_charge_voltage_limit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_charge_voltage_limit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->charge_voltage_limit = u_charge_voltage_limit.real;
      offset += sizeof(this->charge_voltage_limit);
      union {
        float real;
        uint32_t base;
      } u_current_delta;
      u_current_delta.base = 0;
      u_current_delta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_delta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_delta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_delta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_delta = u_current_delta.real;
      offset += sizeof(this->current_delta);
      union {
        bool real;
        uint8_t base;
      } u_master_loss;
      u_master_loss.base = 0;
      u_master_loss.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->master_loss = u_master_loss.real;
      offset += sizeof(this->master_loss);
      this->charge_rev =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->charge_rev);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryHYBRID"; };
    virtual const char * getMD5() override { return "c7e4124f0a19047c548295a688475373"; };

  };

}
#endif
