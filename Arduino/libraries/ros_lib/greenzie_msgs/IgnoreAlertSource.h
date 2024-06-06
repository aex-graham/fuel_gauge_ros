#ifndef _ROS_SERVICE_IgnoreAlertSource_h
#define _ROS_SERVICE_IgnoreAlertSource_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

static const char IGNOREALERTSOURCE[] = "greenzie_msgs/IgnoreAlertSource";

  class IgnoreAlertSourceRequest : public ros::Msg
  {
    public:
      typedef const char* _source_type;
      _source_type source;
      typedef bool _add_type;
      _add_type add;

    IgnoreAlertSourceRequest():
      source(""),
      add(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_source = strlen(this->source);
      varToArr(outbuffer + offset, length_source);
      offset += 4;
      memcpy(outbuffer + offset, this->source, length_source);
      offset += length_source;
      union {
        bool real;
        uint8_t base;
      } u_add;
      u_add.real = this->add;
      *(outbuffer + offset + 0) = (u_add.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->add);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_source;
      arrToVar(length_source, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source-1]=0;
      this->source = (char *)(inbuffer + offset-1);
      offset += length_source;
      union {
        bool real;
        uint8_t base;
      } u_add;
      u_add.base = 0;
      u_add.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->add = u_add.real;
      offset += sizeof(this->add);
     return offset;
    }

    virtual const char * getType() override { return IGNOREALERTSOURCE; };
    virtual const char * getMD5() override { return "b0b308d0fa0f03d1447630077fe06c9e"; };

  };

  class IgnoreAlertSourceResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    IgnoreAlertSourceResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return IGNOREALERTSOURCE; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class IgnoreAlertSource {
    public:
    typedef IgnoreAlertSourceRequest Request;
    typedef IgnoreAlertSourceResponse Response;
  };

}
#endif
