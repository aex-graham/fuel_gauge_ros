#ifndef _ROS_greenzie_msgs_BoundaryPoints_h
#define _ROS_greenzie_msgs_BoundaryPoints_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/PointList.h"

namespace greenzie_msgs
{

  class BoundaryPoints : public ros::Msg
  {
    public:
      uint32_t bounds_length;
      typedef greenzie_msgs::PointList _bounds_type;
      _bounds_type st_bounds;
      _bounds_type * bounds;

    BoundaryPoints():
      bounds_length(0), st_bounds(), bounds(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->bounds_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->bounds_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->bounds_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->bounds_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bounds_length);
      for( uint32_t i = 0; i < bounds_length; i++){
      offset += this->bounds[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t bounds_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      bounds_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      bounds_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      bounds_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->bounds_length);
      if(bounds_lengthT > bounds_length)
        this->bounds = (greenzie_msgs::PointList*)realloc(this->bounds, bounds_lengthT * sizeof(greenzie_msgs::PointList));
      bounds_length = bounds_lengthT;
      for( uint32_t i = 0; i < bounds_length; i++){
      offset += this->st_bounds.deserialize(inbuffer + offset);
        memcpy( &(this->bounds[i]), &(this->st_bounds), sizeof(greenzie_msgs::PointList));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/BoundaryPoints"; };
    virtual const char * getMD5() override { return "30f282fe27d00dbcc9843b541f006d11"; };

  };

}
#endif
