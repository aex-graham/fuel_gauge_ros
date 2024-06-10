#ifndef _ROS_SERVICE_EmergencyStop_h
#define _ROS_SERVICE_EmergencyStop_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hri_safe_remote_control_system
{

static const char EMERGENCYSTOP[] = "hri_safe_remote_control_system/EmergencyStop";

  class EmergencyStopRequest : public ros::Msg
  {
    public:
      typedef uint8_t _EmergencyStop_type;
      _EmergencyStop_type EmergencyStop;
      enum { ESTOP_REASON_CLEAR = 0 };
      enum { ESTOP_REASON_SET = 1 };

    EmergencyStopRequest():
      EmergencyStop(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->EmergencyStop >> (8 * 0)) & 0xFF;
      offset += sizeof(this->EmergencyStop);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->EmergencyStop =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->EmergencyStop);
     return offset;
    }

    virtual const char * getType() override { return EMERGENCYSTOP; };
    virtual const char * getMD5() override { return "3262d025043b891a90d437526c73f6e1"; };

  };

  class EmergencyStopResponse : public ros::Msg
  {
    public:

    EmergencyStopResponse()
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

    virtual const char * getType() override { return EMERGENCYSTOP; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class EmergencyStop {
    public:
    typedef EmergencyStopRequest Request;
    typedef EmergencyStopResponse Response;
  };

}
#endif
