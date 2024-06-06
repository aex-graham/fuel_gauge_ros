#ifndef _ROS_greenzie_msgs_PolygonArray_h
#define _ROS_greenzie_msgs_PolygonArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PolygonStamped.h"

namespace greenzie_msgs
{

  class PolygonArray : public ros::Msg
  {
    public:
      uint32_t polygons_length;
      typedef geometry_msgs::PolygonStamped _polygons_type;
      _polygons_type st_polygons;
      _polygons_type * polygons;

    PolygonArray():
      polygons_length(0), st_polygons(), polygons(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->polygons_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->polygons_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->polygons_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->polygons_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->polygons_length);
      for( uint32_t i = 0; i < polygons_length; i++){
      offset += this->polygons[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t polygons_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->polygons_length);
      if(polygons_lengthT > polygons_length)
        this->polygons = (geometry_msgs::PolygonStamped*)realloc(this->polygons, polygons_lengthT * sizeof(geometry_msgs::PolygonStamped));
      polygons_length = polygons_lengthT;
      for( uint32_t i = 0; i < polygons_length; i++){
      offset += this->st_polygons.deserialize(inbuffer + offset);
        memcpy( &(this->polygons[i]), &(this->st_polygons), sizeof(geometry_msgs::PolygonStamped));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/PolygonArray"; };
    virtual const char * getMD5() override { return "83ec1a63af0e0dd439e477cb9e510976"; };

  };

}
#endif
