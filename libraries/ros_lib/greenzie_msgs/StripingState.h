#ifndef _ROS_greenzie_msgs_StripingState_h
#define _ROS_greenzie_msgs_StripingState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseStamped.h"
#include "geometry_msgs/TwistStamped.h"

namespace greenzie_msgs
{

  class StripingState : public ros::Msg
  {
    public:
      typedef geometry_msgs::PoseStamped _pose_type;
      _pose_type pose;
      typedef geometry_msgs::TwistStamped _twist_type;
      _twist_type twist;
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint8_t _direction_type;
      _direction_type direction;
      typedef bool _in_global_plan_type;
      _in_global_plan_type in_global_plan;
      enum { OUTLINE =  0 };
      enum { STRIPE_START =  1 };
      enum { STRIPE_END =  2 };
      enum { STRIPE_INTERMEDIATE =  3 };
      enum { STOP =  4 };
      enum { STOP_REVERSE =  5 };
      enum { AVOIDANCE =  6 };
      enum { DIRECTION_FORWARD =  0 };
      enum { DIRECTION_REVERSE =  1 };

    StripingState():
      pose(),
      twist(),
      type(0),
      direction(0),
      in_global_plan(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->direction >> (8 * 0)) & 0xFF;
      offset += sizeof(this->direction);
      union {
        bool real;
        uint8_t base;
      } u_in_global_plan;
      u_in_global_plan.real = this->in_global_plan;
      *(outbuffer + offset + 0) = (u_in_global_plan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_global_plan);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->direction =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->direction);
      union {
        bool real;
        uint8_t base;
      } u_in_global_plan;
      u_in_global_plan.base = 0;
      u_in_global_plan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_global_plan = u_in_global_plan.real;
      offset += sizeof(this->in_global_plan);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/StripingState"; };
    virtual const char * getMD5() override { return "d4e3fcdcb580bfadbbb28a6198e3b725"; };

  };

}
#endif
