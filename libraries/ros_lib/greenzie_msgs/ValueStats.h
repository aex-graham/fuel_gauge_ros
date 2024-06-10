#ifndef _ROS_greenzie_msgs_ValueStats_h
#define _ROS_greenzie_msgs_ValueStats_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class ValueStats : public ros::Msg
  {
    public:
      typedef float _mean_type;
      _mean_type mean;
      typedef float _stddev_type;
      _stddev_type stddev;
      typedef float _size_type;
      _size_type size;

    ValueStats():
      mean(0),
      stddev(0),
      size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->mean);
      offset += serializeAvrFloat64(outbuffer + offset, this->stddev);
      offset += serializeAvrFloat64(outbuffer + offset, this->size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->mean));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->stddev));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->size));
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/ValueStats"; };
    virtual const char * getMD5() override { return "34fa784f80645bd1ebeebc90da02db78"; };

  };

}
#endif
