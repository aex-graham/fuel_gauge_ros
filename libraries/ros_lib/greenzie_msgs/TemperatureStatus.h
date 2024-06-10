#ifndef _ROS_greenzie_msgs_TemperatureStatus_h
#define _ROS_greenzie_msgs_TemperatureStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class TemperatureStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _fahrenheit_type;
      _fahrenheit_type fahrenheit;
      typedef float _celsius_type;
      _celsius_type celsius;

    TemperatureStatus():
      header(),
      fahrenheit(0),
      celsius(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_fahrenheit;
      u_fahrenheit.real = this->fahrenheit;
      *(outbuffer + offset + 0) = (u_fahrenheit.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fahrenheit.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fahrenheit.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fahrenheit.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fahrenheit);
      union {
        float real;
        uint32_t base;
      } u_celsius;
      u_celsius.real = this->celsius;
      *(outbuffer + offset + 0) = (u_celsius.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_celsius.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_celsius.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_celsius.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->celsius);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_fahrenheit;
      u_fahrenheit.base = 0;
      u_fahrenheit.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fahrenheit.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fahrenheit.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fahrenheit.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fahrenheit = u_fahrenheit.real;
      offset += sizeof(this->fahrenheit);
      union {
        float real;
        uint32_t base;
      } u_celsius;
      u_celsius.base = 0;
      u_celsius.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_celsius.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_celsius.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_celsius.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->celsius = u_celsius.real;
      offset += sizeof(this->celsius);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/TemperatureStatus"; };
    virtual const char * getMD5() override { return "4ded3b8f7ca70ac5d8679547948e7a3b"; };

  };

}
#endif
