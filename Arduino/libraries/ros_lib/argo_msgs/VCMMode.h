#ifndef _ROS_argo_msgs_VCMMode_h
#define _ROS_argo_msgs_VCMMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace argo_msgs
{

  class VCMMode : public ros::Msg
  {
    public:
      typedef uint8_t _mode_type;
      _mode_type mode;
      enum { MANUAL_MODE =  0 };
      enum { AUTO_MODE =  2 };

    VCMMode():
      mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
     return offset;
    }

    virtual const char * getType() override { return "argo_msgs/VCMMode"; };
    virtual const char * getMD5() override { return "393adaa85e54a721c1ad8e6b4fc260df"; };

  };

}
#endif
