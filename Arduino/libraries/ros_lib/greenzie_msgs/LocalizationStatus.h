#ifndef _ROS_greenzie_msgs_LocalizationStatus_h
#define _ROS_greenzie_msgs_LocalizationStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class LocalizationStatus : public ros::Msg
  {
    public:
      typedef uint8_t _status_type;
      _status_type status;
      typedef const char* _status_str_type;
      _status_str_type status_str;
      typedef bool _known_location_type;
      _known_location_type known_location;
      typedef bool _known_orientation_type;
      _known_orientation_type known_orientation;
      enum { UNINITIALIZED =  0 };
      enum { INITIALIZING =  1 };
      enum { READY =  2   };
      enum { RECOVERY =  3 };

    LocalizationStatus():
      status(0),
      status_str(""),
      known_location(0),
      known_orientation(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      uint32_t length_status_str = strlen(this->status_str);
      varToArr(outbuffer + offset, length_status_str);
      offset += 4;
      memcpy(outbuffer + offset, this->status_str, length_status_str);
      offset += length_status_str;
      union {
        bool real;
        uint8_t base;
      } u_known_location;
      u_known_location.real = this->known_location;
      *(outbuffer + offset + 0) = (u_known_location.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->known_location);
      union {
        bool real;
        uint8_t base;
      } u_known_orientation;
      u_known_orientation.real = this->known_orientation;
      *(outbuffer + offset + 0) = (u_known_orientation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->known_orientation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      uint32_t length_status_str;
      arrToVar(length_status_str, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status_str; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status_str-1]=0;
      this->status_str = (char *)(inbuffer + offset-1);
      offset += length_status_str;
      union {
        bool real;
        uint8_t base;
      } u_known_location;
      u_known_location.base = 0;
      u_known_location.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->known_location = u_known_location.real;
      offset += sizeof(this->known_location);
      union {
        bool real;
        uint8_t base;
      } u_known_orientation;
      u_known_orientation.base = 0;
      u_known_orientation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->known_orientation = u_known_orientation.real;
      offset += sizeof(this->known_orientation);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/LocalizationStatus"; };
    virtual const char * getMD5() override { return "9a784699a91e4f4e95baa2dd9d8e80a4"; };

  };

}
#endif
