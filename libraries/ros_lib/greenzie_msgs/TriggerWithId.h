#ifndef _ROS_SERVICE_TriggerWithId_h
#define _ROS_SERVICE_TriggerWithId_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

static const char TRIGGERWITHID[] = "greenzie_msgs/TriggerWithId";

  class TriggerWithIdRequest : public ros::Msg
  {
    public:
      typedef uint8_t _id_type;
      _id_type id;

    TriggerWithIdRequest():
      id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
     return offset;
    }

    virtual const char * getType() override { return TRIGGERWITHID; };
    virtual const char * getMD5() override { return "541b98e964705918fa8eb206b65347b3"; };

  };

  class TriggerWithIdResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef uint8_t _error_code_type;
      _error_code_type error_code;

    TriggerWithIdResponse():
      success(0),
      error_code(0)
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
      *(outbuffer + offset + 0) = (this->error_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error_code);
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
      this->error_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error_code);
     return offset;
    }

    virtual const char * getType() override { return TRIGGERWITHID; };
    virtual const char * getMD5() override { return "e64e855da06d239f5ca2100b107659ac"; };

  };

  class TriggerWithId {
    public:
    typedef TriggerWithIdRequest Request;
    typedef TriggerWithIdResponse Response;
  };

}
#endif
