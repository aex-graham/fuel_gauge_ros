#ifndef _ROS_argo_msgs_AutoThrottleCommand_h
#define _ROS_argo_msgs_AutoThrottleCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace argo_msgs
{

  class AutoThrottleCommand : public ros::Msg
  {
    public:
      typedef int16_t _left_throttle_type;
      _left_throttle_type left_throttle;
      typedef int16_t _right_throttle_type;
      _right_throttle_type right_throttle;

    AutoThrottleCommand():
      left_throttle(0),
      right_throttle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_throttle;
      u_left_throttle.real = this->left_throttle;
      *(outbuffer + offset + 0) = (u_left_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_throttle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_throttle);
      union {
        int16_t real;
        uint16_t base;
      } u_right_throttle;
      u_right_throttle.real = this->right_throttle;
      *(outbuffer + offset + 0) = (u_right_throttle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_throttle.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_throttle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_throttle;
      u_left_throttle.base = 0;
      u_left_throttle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_throttle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left_throttle = u_left_throttle.real;
      offset += sizeof(this->left_throttle);
      union {
        int16_t real;
        uint16_t base;
      } u_right_throttle;
      u_right_throttle.base = 0;
      u_right_throttle.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_throttle.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right_throttle = u_right_throttle.real;
      offset += sizeof(this->right_throttle);
     return offset;
    }

    virtual const char * getType() override { return "argo_msgs/AutoThrottleCommand"; };
    virtual const char * getMD5() override { return "bb66df620d87cac1468359f612dfb4d7"; };

  };

}
#endif
