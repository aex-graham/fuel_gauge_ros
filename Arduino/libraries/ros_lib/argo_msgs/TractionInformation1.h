#ifndef _ROS_argo_msgs_TractionInformation1_h
#define _ROS_argo_msgs_TractionInformation1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace argo_msgs
{

  class TractionInformation1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _status_type;
      _status_type status;
      typedef float _battery_voltage_type;
      _battery_voltage_type battery_voltage;
      typedef int32_t _motor_rpm_type;
      _motor_rpm_type motor_rpm;
      typedef float _motor_current_type;
      _motor_current_type motor_current;

    TractionInformation1():
      header(),
      status(0),
      battery_voltage(0),
      motor_rpm(0),
      motor_current(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
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
        int32_t real;
        uint32_t base;
      } u_motor_rpm;
      u_motor_rpm.real = this->motor_rpm;
      *(outbuffer + offset + 0) = (u_motor_rpm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_rpm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_rpm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_rpm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_rpm);
      union {
        float real;
        uint32_t base;
      } u_motor_current;
      u_motor_current.real = this->motor_current;
      *(outbuffer + offset + 0) = (u_motor_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_current);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
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
        int32_t real;
        uint32_t base;
      } u_motor_rpm;
      u_motor_rpm.base = 0;
      u_motor_rpm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_rpm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_rpm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_rpm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor_rpm = u_motor_rpm.real;
      offset += sizeof(this->motor_rpm);
      union {
        float real;
        uint32_t base;
      } u_motor_current;
      u_motor_current.base = 0;
      u_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor_current = u_motor_current.real;
      offset += sizeof(this->motor_current);
     return offset;
    }

    virtual const char * getType() override { return "argo_msgs/TractionInformation1"; };
    virtual const char * getMD5() override { return "4e468eba576a98bba1b6a4970569f73d"; };

  };

}
#endif
