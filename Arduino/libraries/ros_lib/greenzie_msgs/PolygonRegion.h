#ifndef _ROS_greenzie_msgs_PolygonRegion_h
#define _ROS_greenzie_msgs_PolygonRegion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Polygon.h"

namespace greenzie_msgs
{

  class PolygonRegion : public ros::Msg
  {
    public:
      typedef geometry_msgs::Polygon _polygon_type;
      _polygon_type polygon;
      typedef int32_t _parent_index_type;
      _parent_index_type parent_index;
      typedef uint8_t _region_type_type;
      _region_type_type region_type;
      enum { UNMOWED =  0 };
      enum { MOWED =  1 };

    PolygonRegion():
      polygon(),
      parent_index(0),
      region_type(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->polygon.serialize(outbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_parent_index;
      u_parent_index.real = this->parent_index;
      *(outbuffer + offset + 0) = (u_parent_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_parent_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_parent_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_parent_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parent_index);
      *(outbuffer + offset + 0) = (this->region_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->region_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->polygon.deserialize(inbuffer + offset);
      union {
        int32_t real;
        uint32_t base;
      } u_parent_index;
      u_parent_index.base = 0;
      u_parent_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_parent_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_parent_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_parent_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->parent_index = u_parent_index.real;
      offset += sizeof(this->parent_index);
      this->region_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->region_type);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/PolygonRegion"; };
    virtual const char * getMD5() override { return "dbd2fe159eabd231bcb0dacff4437543"; };

  };

}
#endif
