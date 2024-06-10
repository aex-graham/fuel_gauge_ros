#ifndef _ROS_SERVICE_IgnitionTimerSettings_h
#define _ROS_SERVICE_IgnitionTimerSettings_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

static const char IGNITIONTIMERSETTINGS[] = "greenzie_msgs/IgnitionTimerSettings";

  class IgnitionTimerSettingsRequest : public ros::Msg
  {
    public:

    IgnitionTimerSettingsRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return IGNITIONTIMERSETTINGS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class IgnitionTimerSettingsResponse : public ros::Msg
  {
    public:
      typedef uint16_t _greenzie_shutdown_timeout_type;
      _greenzie_shutdown_timeout_type greenzie_shutdown_timeout;
      typedef uint16_t _ignition_timeout_type;
      _ignition_timeout_type ignition_timeout;
      typedef float _low_battery_threshold_type;
      _low_battery_threshold_type low_battery_threshold;
      typedef bool _is_valid_type;
      _is_valid_type is_valid;
      typedef const char* _message_type;
      _message_type message;

    IgnitionTimerSettingsResponse():
      greenzie_shutdown_timeout(0),
      ignition_timeout(0),
      low_battery_threshold(0),
      is_valid(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->greenzie_shutdown_timeout >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->greenzie_shutdown_timeout >> (8 * 1)) & 0xFF;
      offset += sizeof(this->greenzie_shutdown_timeout);
      *(outbuffer + offset + 0) = (this->ignition_timeout >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ignition_timeout >> (8 * 1)) & 0xFF;
      offset += sizeof(this->ignition_timeout);
      union {
        float real;
        uint32_t base;
      } u_low_battery_threshold;
      u_low_battery_threshold.real = this->low_battery_threshold;
      *(outbuffer + offset + 0) = (u_low_battery_threshold.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_low_battery_threshold.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_low_battery_threshold.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_low_battery_threshold.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->low_battery_threshold);
      union {
        bool real;
        uint8_t base;
      } u_is_valid;
      u_is_valid.real = this->is_valid;
      *(outbuffer + offset + 0) = (u_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_valid);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->greenzie_shutdown_timeout =  ((uint16_t) (*(inbuffer + offset)));
      this->greenzie_shutdown_timeout |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->greenzie_shutdown_timeout);
      this->ignition_timeout =  ((uint16_t) (*(inbuffer + offset)));
      this->ignition_timeout |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->ignition_timeout);
      union {
        float real;
        uint32_t base;
      } u_low_battery_threshold;
      u_low_battery_threshold.base = 0;
      u_low_battery_threshold.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_low_battery_threshold.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_low_battery_threshold.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_low_battery_threshold.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->low_battery_threshold = u_low_battery_threshold.real;
      offset += sizeof(this->low_battery_threshold);
      union {
        bool real;
        uint8_t base;
      } u_is_valid;
      u_is_valid.base = 0;
      u_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_valid = u_is_valid.real;
      offset += sizeof(this->is_valid);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return IGNITIONTIMERSETTINGS; };
    virtual const char * getMD5() override { return "82610c9ea959910f1abe943075f5b002"; };

  };

  class IgnitionTimerSettings {
    public:
    typedef IgnitionTimerSettingsRequest Request;
    typedef IgnitionTimerSettingsResponse Response;
  };

}
#endif
