#ifndef _ROS_greenzie_msgs_CoordinateSystemJump_h
#define _ROS_greenzie_msgs_CoordinateSystemJump_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "std_msgs/Bool.h"

namespace greenzie_msgs
{

  class CoordinateSystemJump : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _jump_type;
      _jump_type jump;
      typedef std_msgs::Bool _end_is_earth_type;
      _end_is_earth_type end_is_earth;

    CoordinateSystemJump():
      header(),
      jump(),
      end_is_earth()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->jump.serialize(outbuffer + offset);
      offset += this->end_is_earth.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->jump.deserialize(inbuffer + offset);
      offset += this->end_is_earth.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/CoordinateSystemJump"; };
    virtual const char * getMD5() override { return "16311c4ca86e82e65804703699363a96"; };

  };

}
#endif
