#ifndef _ROS_SERVICE_GetSmartStripeAngle_h
#define _ROS_SERVICE_GetSmartStripeAngle_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PolygonStamped.h"

namespace greenzie_msgs
{

static const char GETSMARTSTRIPEANGLE[] = "greenzie_msgs/GetSmartStripeAngle";

  class GetSmartStripeAngleRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PolygonStamped _polygon_type;
      _polygon_type polygon;

    GetSmartStripeAngleRequest():
      polygon()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->polygon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->polygon.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETSMARTSTRIPEANGLE; };
    virtual const char * getMD5() override { return "e257093c51f646bb3fd81ee37f162324"; };

  };

  class GetSmartStripeAngleResponse : public ros::Msg
  {
    public:
      typedef float _stripe_angle_rad_type;
      _stripe_angle_rad_type stripe_angle_rad;
      typedef bool _success_type;
      _success_type success;

    GetSmartStripeAngleResponse():
      stripe_angle_rad(0),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_stripe_angle_rad;
      u_stripe_angle_rad.real = this->stripe_angle_rad;
      *(outbuffer + offset + 0) = (u_stripe_angle_rad.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stripe_angle_rad.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stripe_angle_rad.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stripe_angle_rad.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stripe_angle_rad);
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
        float real;
        uint32_t base;
      } u_stripe_angle_rad;
      u_stripe_angle_rad.base = 0;
      u_stripe_angle_rad.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stripe_angle_rad.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stripe_angle_rad.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stripe_angle_rad.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stripe_angle_rad = u_stripe_angle_rad.real;
      offset += sizeof(this->stripe_angle_rad);
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

    virtual const char * getType() override { return GETSMARTSTRIPEANGLE; };
    virtual const char * getMD5() override { return "8e3179569534e69594cf1bfcb1265e99"; };

  };

  class GetSmartStripeAngle {
    public:
    typedef GetSmartStripeAngleRequest Request;
    typedef GetSmartStripeAngleResponse Response;
  };

}
#endif
