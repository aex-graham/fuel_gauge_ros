#ifndef _ROS_greenzie_msgs_MeasurementSourceStatus_h
#define _ROS_greenzie_msgs_MeasurementSourceStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class MeasurementSourceStatus : public ros::Msg
  {
    public:
      typedef const char* _source_odometry_alias_type;
      _source_odometry_alias_type source_odometry_alias;
      typedef uint8_t _status_type;
      _status_type status;
      typedef bool _is_stable_type;
      _is_stable_type is_stable;
      enum { NONE =  0      };
      enum { VALID =  1     };
      enum { RECOVERY =  2  };
      enum { LOST =  3      };

    MeasurementSourceStatus():
      source_odometry_alias(""),
      status(0),
      is_stable(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_source_odometry_alias = strlen(this->source_odometry_alias);
      varToArr(outbuffer + offset, length_source_odometry_alias);
      offset += 4;
      memcpy(outbuffer + offset, this->source_odometry_alias, length_source_odometry_alias);
      offset += length_source_odometry_alias;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      union {
        bool real;
        uint8_t base;
      } u_is_stable;
      u_is_stable.real = this->is_stable;
      *(outbuffer + offset + 0) = (u_is_stable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_stable);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_source_odometry_alias;
      arrToVar(length_source_odometry_alias, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source_odometry_alias; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source_odometry_alias-1]=0;
      this->source_odometry_alias = (char *)(inbuffer + offset-1);
      offset += length_source_odometry_alias;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      union {
        bool real;
        uint8_t base;
      } u_is_stable;
      u_is_stable.base = 0;
      u_is_stable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_stable = u_is_stable.real;
      offset += sizeof(this->is_stable);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/MeasurementSourceStatus"; };
    virtual const char * getMD5() override { return "06252a901fa2cd7fd32719e3b697e3e4"; };

  };

}
#endif
