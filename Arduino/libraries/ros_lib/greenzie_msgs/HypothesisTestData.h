#ifndef _ROS_greenzie_msgs_HypothesisTestData_h
#define _ROS_greenzie_msgs_HypothesisTestData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class HypothesisTestData : public ros::Msg
  {
    public:
      typedef float _score_type;
      _score_type score;
      typedef float _p_val_type;
      _p_val_type p_val;
      typedef float _degrees_of_freedom_type;
      _degrees_of_freedom_type degrees_of_freedom;
      typedef bool _is_significant_type;
      _is_significant_type is_significant;
      uint32_t usd_length;
      typedef float _usd_type;
      _usd_type st_usd;
      _usd_type * usd;

    HypothesisTestData():
      score(0),
      p_val(0),
      degrees_of_freedom(0),
      is_significant(0),
      usd_length(0), st_usd(), usd(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->score);
      offset += serializeAvrFloat64(outbuffer + offset, this->p_val);
      offset += serializeAvrFloat64(outbuffer + offset, this->degrees_of_freedom);
      union {
        bool real;
        uint8_t base;
      } u_is_significant;
      u_is_significant.real = this->is_significant;
      *(outbuffer + offset + 0) = (u_is_significant.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_significant);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->score));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->p_val));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->degrees_of_freedom));
      union {
        bool real;
        uint8_t base;
      } u_is_significant;
      u_is_significant.base = 0;
      u_is_significant.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_significant = u_is_significant.real;
      offset += sizeof(this->is_significant);
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

    virtual const char * getType() override { return "greenzie_msgs/HypothesisTestData"; };
    virtual const char * getMD5() override { return "cfc6fae0d8ddf8fd36e0c04526a33f99"; };

  };

}
#endif
