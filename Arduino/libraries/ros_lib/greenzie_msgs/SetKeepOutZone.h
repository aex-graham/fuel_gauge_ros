#ifndef _ROS_SERVICE_SetKeepOutZone_h
#define _ROS_SERVICE_SetKeepOutZone_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/KeepOutZone.h"

namespace greenzie_msgs
{

static const char SETKEEPOUTZONE[] = "greenzie_msgs/SetKeepOutZone";

  class SetKeepOutZoneRequest : public ros::Msg
  {
    public:
      typedef greenzie_msgs::KeepOutZone _keep_out_zone_type;
      _keep_out_zone_type keep_out_zone;

    SetKeepOutZoneRequest():
      keep_out_zone()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->keep_out_zone.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->keep_out_zone.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETKEEPOUTZONE; };
    virtual const char * getMD5() override { return "690ba0c0a40a6b97b3babd49729a5358"; };

  };

  class SetKeepOutZoneResponse : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;
      typedef bool _success_type;
      _success_type success;

    SetKeepOutZoneResponse():
      message(""),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
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
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
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

    virtual const char * getType() override { return SETKEEPOUTZONE; };
    virtual const char * getMD5() override { return "9bf829f07d795d3f9e541a07897da2c4"; };

  };

  class SetKeepOutZone {
    public:
    typedef SetKeepOutZoneRequest Request;
    typedef SetKeepOutZoneResponse Response;
  };

}
#endif
