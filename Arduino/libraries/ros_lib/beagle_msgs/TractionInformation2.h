#ifndef _ROS_beagle_msgs_TractionInformation2_h
#define _ROS_beagle_msgs_TractionInformation2_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class TractionInformation2 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int16_t _controller_temperature_type;
      _controller_temperature_type controller_temperature;
      typedef int16_t _motor_temperature_type;
      _motor_temperature_type motor_temperature;
      typedef float _battery_current_type;
      _battery_current_type battery_current;
      typedef float _motor_input_power_type;
      _motor_input_power_type motor_input_power;

    TractionInformation2():
      header(),
      controller_temperature(0),
      motor_temperature(0),
      battery_current(0),
      motor_input_power(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_controller_temperature;
      u_controller_temperature.real = this->controller_temperature;
      *(outbuffer + offset + 0) = (u_controller_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_controller_temperature.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->controller_temperature);
      union {
        int16_t real;
        uint16_t base;
      } u_motor_temperature;
      u_motor_temperature.real = this->motor_temperature;
      *(outbuffer + offset + 0) = (u_motor_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_temperature.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->motor_temperature);
      union {
        float real;
        uint32_t base;
      } u_battery_current;
      u_battery_current.real = this->battery_current;
      *(outbuffer + offset + 0) = (u_battery_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_current);
      union {
        float real;
        uint32_t base;
      } u_motor_input_power;
      u_motor_input_power.real = this->motor_input_power;
      *(outbuffer + offset + 0) = (u_motor_input_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_motor_input_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_motor_input_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_motor_input_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_input_power);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_controller_temperature;
      u_controller_temperature.base = 0;
      u_controller_temperature.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_controller_temperature.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->controller_temperature = u_controller_temperature.real;
      offset += sizeof(this->controller_temperature);
      union {
        int16_t real;
        uint16_t base;
      } u_motor_temperature;
      u_motor_temperature.base = 0;
      u_motor_temperature.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_temperature.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->motor_temperature = u_motor_temperature.real;
      offset += sizeof(this->motor_temperature);
      union {
        float real;
        uint32_t base;
      } u_battery_current;
      u_battery_current.base = 0;
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_current = u_battery_current.real;
      offset += sizeof(this->battery_current);
      union {
        float real;
        uint32_t base;
      } u_motor_input_power;
      u_motor_input_power.base = 0;
      u_motor_input_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_motor_input_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_motor_input_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_motor_input_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->motor_input_power = u_motor_input_power.real;
      offset += sizeof(this->motor_input_power);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/TractionInformation2"; };
    virtual const char * getMD5() override { return "e2662d5cde18fd29d1f62fd1278835ed"; };

  };

}
#endif
