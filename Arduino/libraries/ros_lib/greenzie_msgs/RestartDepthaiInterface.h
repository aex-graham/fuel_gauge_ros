#ifndef _ROS_SERVICE_RestartDepthaiInterface_h
#define _ROS_SERVICE_RestartDepthaiInterface_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

static const char RESTARTDEPTHAIINTERFACE[] = "greenzie_msgs/RestartDepthaiInterface";

  class RestartDepthaiInterfaceRequest : public ros::Msg
  {
    public:

    RestartDepthaiInterfaceRequest()
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

    virtual const char * getType() override { return RESTARTDEPTHAIINTERFACE; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class RestartDepthaiInterfaceResponse : public ros::Msg
  {
    public:
      typedef uint8_t _result_type;
      _result_type result;
      enum { COMMAND_REJECTED =  0 };
      enum { COMMAND_ACCEPTED =  1 };
      enum { COMMAND_ALREADY_IN_PROGRESS =  2 };

    RestartDepthaiInterfaceResponse():
      result(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->result >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->result =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->result);
     return offset;
    }

    virtual const char * getType() override { return RESTARTDEPTHAIINTERFACE; };
    virtual const char * getMD5() override { return "30a0c2f05f5a1ac5ff1c9a814a1bb064"; };

  };

  class RestartDepthaiInterface {
    public:
    typedef RestartDepthaiInterfaceRequest Request;
    typedef RestartDepthaiInterfaceResponse Response;
  };

}
#endif
