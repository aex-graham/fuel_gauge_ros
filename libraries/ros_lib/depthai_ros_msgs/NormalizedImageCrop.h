#ifndef _ROS_SERVICE_NormalizedImageCrop_h
#define _ROS_SERVICE_NormalizedImageCrop_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace depthai_ros_msgs
{

static const char NORMALIZEDIMAGECROP[] = "depthai_ros_msgs/NormalizedImageCrop";

  class NormalizedImageCropRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _top_left_type;
      _top_left_type top_left;
      typedef geometry_msgs::Pose2D _bottom_right_type;
      _bottom_right_type bottom_right;

    NormalizedImageCropRequest():
      top_left(),
      bottom_right()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->top_left.serialize(outbuffer + offset);
      offset += this->bottom_right.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->top_left.deserialize(inbuffer + offset);
      offset += this->bottom_right.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return NORMALIZEDIMAGECROP; };
    virtual const char * getMD5() override { return "59bb83618d002416c9960e7cc0740912"; };

  };

  class NormalizedImageCropResponse : public ros::Msg
  {
    public:
      typedef int64_t _status_type;
      _status_type status;

    NormalizedImageCropResponse():
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_status.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_status.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_status.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_status.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_status.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_status.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_status.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_status.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_status.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_status.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_status.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_status.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_status.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_status.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    virtual const char * getType() override { return NORMALIZEDIMAGECROP; };
    virtual const char * getMD5() override { return "4107476a6271fc2684d94be17d33f854"; };

  };

  class NormalizedImageCrop {
    public:
    typedef NormalizedImageCropRequest Request;
    typedef NormalizedImageCropResponse Response;
  };

}
#endif
