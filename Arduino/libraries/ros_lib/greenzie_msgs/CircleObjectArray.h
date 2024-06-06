#ifndef _ROS_greenzie_msgs_CircleObjectArray_h
#define _ROS_greenzie_msgs_CircleObjectArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/CircleObject.h"

namespace greenzie_msgs
{

  class CircleObjectArray : public ros::Msg
  {
    public:
      uint32_t circles_length;
      typedef greenzie_msgs::CircleObject _circles_type;
      _circles_type st_circles;
      _circles_type * circles;

    CircleObjectArray():
      circles_length(0), st_circles(), circles(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->circles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->circles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->circles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->circles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->circles_length);
      for( uint32_t i = 0; i < circles_length; i++){
      offset += this->circles[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t circles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      circles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      circles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      circles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->circles_length);
      if(circles_lengthT > circles_length)
        this->circles = (greenzie_msgs::CircleObject*)realloc(this->circles, circles_lengthT * sizeof(greenzie_msgs::CircleObject));
      circles_length = circles_lengthT;
      for( uint32_t i = 0; i < circles_length; i++){
      offset += this->st_circles.deserialize(inbuffer + offset);
        memcpy( &(this->circles[i]), &(this->st_circles), sizeof(greenzie_msgs::CircleObject));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/CircleObjectArray"; };
    virtual const char * getMD5() override { return "41b74ca494d3de74a4139ca7da0d7ab2"; };

  };

}
#endif
