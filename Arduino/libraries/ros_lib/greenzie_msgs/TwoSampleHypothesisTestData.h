#ifndef _ROS_greenzie_msgs_TwoSampleHypothesisTestData_h
#define _ROS_greenzie_msgs_TwoSampleHypothesisTestData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/HypothesisTestData.h"
#include "greenzie_msgs/ValueStats.h"

namespace greenzie_msgs
{

  class TwoSampleHypothesisTestData : public ros::Msg
  {
    public:
      typedef greenzie_msgs::HypothesisTestData _results_type;
      _results_type results;
      typedef greenzie_msgs::ValueStats _a_type;
      _a_type a;
      typedef greenzie_msgs::ValueStats _b_type;
      _b_type b;
      uint32_t usd_length;
      typedef float _usd_type;
      _usd_type st_usd;
      _usd_type * usd;

    TwoSampleHypothesisTestData():
      results(),
      a(),
      b(),
      usd_length(0), st_usd(), usd(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->results.serialize(outbuffer + offset);
      offset += this->a.serialize(outbuffer + offset);
      offset += this->b.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->usd_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->usd_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->usd_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->usd_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->usd_length);
      for( uint32_t i = 0; i < usd_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->usd[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->results.deserialize(inbuffer + offset);
      offset += this->a.deserialize(inbuffer + offset);
      offset += this->b.deserialize(inbuffer + offset);
      uint32_t usd_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      usd_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      usd_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      usd_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->usd_length);
      if(usd_lengthT > usd_length)
        this->usd = (float*)realloc(this->usd, usd_lengthT * sizeof(float));
      usd_length = usd_lengthT;
      for( uint32_t i = 0; i < usd_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_usd));
        memcpy( &(this->usd[i]), &(this->st_usd), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/TwoSampleHypothesisTestData"; };
    virtual const char * getMD5() override { return "9272d9631865b826c3eb6f6baff34d71"; };

  };

}
#endif
