#ifndef _ROS_greenzie_msgs_IgnitionTimerStatus_h
#define _ROS_greenzie_msgs_IgnitionTimerStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class IgnitionTimerStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _average_battery_level_type;
      _average_battery_level_type average_battery_level;
      typedef bool _ignition_status_type;
      _ignition_status_type ignition_status;
      typedef uint8_t _state_type;
      _state_type state;

    IgnitionTimerStatus():
      header(),
      average_battery_level(0),
      ignition_status(0),
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_average_battery_level;
      u_average_battery_level.real = this->average_battery_level;
      *(outbuffer + offset + 0) = (u_average_battery_level.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_average_battery_level.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_average_battery_level.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_average_battery_level.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->average_battery_level);
      union {
        bool real;
        uint8_t base;
      } u_ignition_status;
      u_ignition_status.real = this->ignition_status;
      *(outbuffer + offset + 0) = (u_ignition_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ignition_status);
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_average_battery_level;
      u_average_battery_level.base = 0;
      u_average_battery_level.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_average_battery_level.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_average_battery_level.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_average_battery_level.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->average_battery_level = u_average_battery_level.real;
      offset += sizeof(this->average_battery_level);
      union {
        bool real;
        uint8_t base;
      } u_ignition_status;
      u_ignition_status.base = 0;
      u_ignition_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ignition_status = u_ignition_status.real;
      offset += sizeof(this->ignition_status);
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/IgnitionTimerStatus"; };
    virtual const char * getMD5() override { return "7f5c283469ab1523b44302ee7e8770bc"; };

  };

}
#endif
