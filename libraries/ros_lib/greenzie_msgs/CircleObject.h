#ifndef _ROS_greenzie_msgs_CircleObject_h
#define _ROS_greenzie_msgs_CircleObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class CircleObject : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _radius_m_type;
      _radius_m_type radius_m;

    CircleObject():
      x(0),
      y(0),
      radius_m(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->radius_m);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->radius_m));
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/CircleObject"; };
    virtual const char * getMD5() override { return "3252cea998ae961df0f79941470dc84e"; };

  };

}
#endif
