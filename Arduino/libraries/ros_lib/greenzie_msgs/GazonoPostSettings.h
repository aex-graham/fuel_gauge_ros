#ifndef _ROS_greenzie_msgs_GazonoPostSettings_h
#define _ROS_greenzie_msgs_GazonoPostSettings_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class GazonoPostSettings : public ros::Msg
  {
    public:
      typedef float _update_period_s_type;
      _update_period_s_type update_period_s;
      typedef float _override_duration_s_type;
      _override_duration_s_type override_duration_s;

    GazonoPostSettings():
      update_period_s(0),
      override_duration_s(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_update_period_s;
      u_update_period_s.real = this->update_period_s;
      *(outbuffer + offset + 0) = (u_update_period_s.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_update_period_s.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_update_period_s.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_update_period_s.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->update_period_s);
      union {
        float real;
        uint32_t base;
      } u_override_duration_s;
      u_override_duration_s.real = this->override_duration_s;
      *(outbuffer + offset + 0) = (u_override_duration_s.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_override_duration_s.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_override_duration_s.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_override_duration_s.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->override_duration_s);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_update_period_s;
      u_update_period_s.base = 0;
      u_update_period_s.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_update_period_s.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_update_period_s.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_update_period_s.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->update_period_s = u_update_period_s.real;
      offset += sizeof(this->update_period_s);
      union {
        float real;
        uint32_t base;
      } u_override_duration_s;
      u_override_duration_s.base = 0;
      u_override_duration_s.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_override_duration_s.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_override_duration_s.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_override_duration_s.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->override_duration_s = u_override_duration_s.real;
      offset += sizeof(this->override_duration_s);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/GazonoPostSettings"; };
    virtual const char * getMD5() override { return "ed2cfe9b7b11fbf7cb00643206417f2d"; };

  };

}
#endif
