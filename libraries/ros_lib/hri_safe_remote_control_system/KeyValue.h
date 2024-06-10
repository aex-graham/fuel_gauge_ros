#ifndef _ROS_SERVICE_KeyValue_h
#define _ROS_SERVICE_KeyValue_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hri_safe_remote_control_system
{

static const char KEYVALUE[] = "hri_safe_remote_control_system/KeyValue";

  class KeyValueRequest : public ros::Msg
  {
    public:
      typedef uint8_t _Key_type;
      _Key_type Key;
      typedef int32_t _Value_type;
      _Value_type Value;

    KeyValueRequest():
      Key(0),
      Value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->Key >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Key);
      union {
        int32_t real;
        uint32_t base;
      } u_Value;
      u_Value.real = this->Value;
      *(outbuffer + offset + 0) = (u_Value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->Key =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Key);
      union {
        int32_t real;
        uint32_t base;
      } u_Value;
      u_Value.base = 0;
      u_Value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Value = u_Value.real;
      offset += sizeof(this->Value);
     return offset;
    }

    virtual const char * getType() override { return KEYVALUE; };
    virtual const char * getMD5() override { return "dac0607fb8d0b4f981ba2f919fc0bf58"; };

  };

  class KeyValueResponse : public ros::Msg
  {
    public:

    KeyValueResponse()
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

    virtual const char * getType() override { return KEYVALUE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class KeyValue {
    public:
    typedef KeyValueRequest Request;
    typedef KeyValueResponse Response;
  };

}
#endif
