#ifndef _ROS_hri_safe_remote_control_system_SrcHealth_h
#define _ROS_hri_safe_remote_control_system_SrcHealth_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hri_safe_remote_control_system
{

  class SrcHealth : public ros::Msg
  {
    public:
      typedef uint8_t _src_battery_level_type;
      _src_battery_level_type src_battery_level;
      typedef bool _src_battery_charging_type;
      _src_battery_charging_type src_battery_charging;
      typedef uint8_t _vsc_connection_strength_type;
      _vsc_connection_strength_type vsc_connection_strength;
      typedef uint8_t _src_connection_strength_type;
      _src_connection_strength_type src_connection_strength;
      typedef uint8_t _vsc_rssi_type;
      _vsc_rssi_type vsc_rssi;
      typedef uint8_t _src_rssi_type;
      _src_rssi_type src_rssi;
      typedef uint8_t _vsc_mode_type;
      _vsc_mode_type vsc_mode;

    SrcHealth():
      src_battery_level(0),
      src_battery_charging(0),
      vsc_connection_strength(0),
      src_connection_strength(0),
      vsc_rssi(0),
      src_rssi(0),
      vsc_mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->src_battery_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->src_battery_level);
      union {
        bool real;
        uint8_t base;
      } u_src_battery_charging;
      u_src_battery_charging.real = this->src_battery_charging;
      *(outbuffer + offset + 0) = (u_src_battery_charging.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->src_battery_charging);
      *(outbuffer + offset + 0) = (this->vsc_connection_strength >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vsc_connection_strength);
      *(outbuffer + offset + 0) = (this->src_connection_strength >> (8 * 0)) & 0xFF;
      offset += sizeof(this->src_connection_strength);
      *(outbuffer + offset + 0) = (this->vsc_rssi >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vsc_rssi);
      *(outbuffer + offset + 0) = (this->src_rssi >> (8 * 0)) & 0xFF;
      offset += sizeof(this->src_rssi);
      *(outbuffer + offset + 0) = (this->vsc_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vsc_mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->src_battery_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->src_battery_level);
      union {
        bool real;
        uint8_t base;
      } u_src_battery_charging;
      u_src_battery_charging.base = 0;
      u_src_battery_charging.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->src_battery_charging = u_src_battery_charging.real;
      offset += sizeof(this->src_battery_charging);
      this->vsc_connection_strength =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vsc_connection_strength);
      this->src_connection_strength =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->src_connection_strength);
      this->vsc_rssi =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vsc_rssi);
      this->src_rssi =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->src_rssi);
      this->vsc_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vsc_mode);
     return offset;
    }

    virtual const char * getType() override { return "hri_safe_remote_control_system/SrcHealth"; };
    virtual const char * getMD5() override { return "ec20d0d5846b26039eb04e88e5b8d72e"; };

  };

}
#endif
