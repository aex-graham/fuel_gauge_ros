#ifndef _ROS_SERVICE_KeyString_h
#define _ROS_SERVICE_KeyString_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hri_safe_remote_control_system
{

static const char KEYSTRING[] = "hri_safe_remote_control_system/KeyString";

  class KeyStringRequest : public ros::Msg
  {
    public:
      typedef uint8_t _Key_type;
      _Key_type Key;
      typedef const char* _Value_type;
      _Value_type Value;

    KeyStringRequest():
      Key(0),
      Value("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->Key >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Key);
      uint32_t length_Value = strlen(this->Value);
      varToArr(outbuffer + offset, length_Value);
      offset += 4;
      memcpy(outbuffer + offset, this->Value, length_Value);
      offset += length_Value;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->Key =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Key);
      uint32_t length_Value;
      arrToVar(length_Value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_Value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_Value-1]=0;
      this->Value = (char *)(inbuffer + offset-1);
      offset += length_Value;
     return offset;
    }

    virtual const char * getType() override { return KEYSTRING; };
    virtual const char * getMD5() override { return "2c2c8bd012794350ddb831c73db5df7b"; };

  };

  class KeyStringResponse : public ros::Msg
  {
    public:

    KeyStringResponse()
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

    virtual const char * getType() override { return KEYSTRING; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class KeyString {
    public:
    typedef KeyStringRequest Request;
    typedef KeyStringResponse Response;
  };

}
#endif
