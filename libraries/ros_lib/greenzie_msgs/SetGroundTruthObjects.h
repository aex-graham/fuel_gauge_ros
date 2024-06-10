#ifndef _ROS_SERVICE_SetGroundTruthObjects_h
#define _ROS_SERVICE_SetGroundTruthObjects_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Polygon.h"
#include "greenzie_msgs/CircleObject.h"

namespace greenzie_msgs
{

static const char SETGROUNDTRUTHOBJECTS[] = "greenzie_msgs/SetGroundTruthObjects";

  class SetGroundTruthObjectsRequest : public ros::Msg
  {
    public:
      typedef greenzie_msgs::CircleObject _circle_object_type;
      _circle_object_type circle_object;
      typedef geometry_msgs::Polygon _polygon_object_type;
      _polygon_object_type polygon_object;
      typedef bool _clear_previous_objects_type;
      _clear_previous_objects_type clear_previous_objects;

    SetGroundTruthObjectsRequest():
      circle_object(),
      polygon_object(),
      clear_previous_objects(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->circle_object.serialize(outbuffer + offset);
      offset += this->polygon_object.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_clear_previous_objects;
      u_clear_previous_objects.real = this->clear_previous_objects;
      *(outbuffer + offset + 0) = (u_clear_previous_objects.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->clear_previous_objects);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->circle_object.deserialize(inbuffer + offset);
      offset += this->polygon_object.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_clear_previous_objects;
      u_clear_previous_objects.base = 0;
      u_clear_previous_objects.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->clear_previous_objects = u_clear_previous_objects.real;
      offset += sizeof(this->clear_previous_objects);
     return offset;
    }

    virtual const char * getType() override { return SETGROUNDTRUTHOBJECTS; };
    virtual const char * getMD5() override { return "d19dc23381bc55e6512a512499a49eb2"; };

  };

  class SetGroundTruthObjectsResponse : public ros::Msg
  {
    public:

    SetGroundTruthObjectsResponse()
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

    virtual const char * getType() override { return SETGROUNDTRUTHOBJECTS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetGroundTruthObjects {
    public:
    typedef SetGroundTruthObjectsRequest Request;
    typedef SetGroundTruthObjectsResponse Response;
  };

}
#endif
