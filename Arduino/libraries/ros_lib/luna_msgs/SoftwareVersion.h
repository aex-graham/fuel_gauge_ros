#ifndef _ROS_luna_msgs_SoftwareVersion_h
#define _ROS_luna_msgs_SoftwareVersion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace luna_msgs
{

  class SoftwareVersion : public ros::Msg
  {
    public:
      typedef const char* _m4_version_type;
      _m4_version_type m4_version;
      typedef const char* _maxcontrol_version_type;
      _maxcontrol_version_type maxcontrol_version;
      typedef const char* _perception_kit_version_type;
      _perception_kit_version_type perception_kit_version;

    SoftwareVersion():
      m4_version(""),
      maxcontrol_version(""),
      perception_kit_version("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_m4_version = strlen(this->m4_version);
      varToArr(outbuffer + offset, length_m4_version);
      offset += 4;
      memcpy(outbuffer + offset, this->m4_version, length_m4_version);
      offset += length_m4_version;
      uint32_t length_maxcontrol_version = strlen(this->maxcontrol_version);
      varToArr(outbuffer + offset, length_maxcontrol_version);
      offset += 4;
      memcpy(outbuffer + offset, this->maxcontrol_version, length_maxcontrol_version);
      offset += length_maxcontrol_version;
      uint32_t length_perception_kit_version = strlen(this->perception_kit_version);
      varToArr(outbuffer + offset, length_perception_kit_version);
      offset += 4;
      memcpy(outbuffer + offset, this->perception_kit_version, length_perception_kit_version);
      offset += length_perception_kit_version;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_m4_version;
      arrToVar(length_m4_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_m4_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_m4_version-1]=0;
      this->m4_version = (char *)(inbuffer + offset-1);
      offset += length_m4_version;
      uint32_t length_maxcontrol_version;
      arrToVar(length_maxcontrol_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_maxcontrol_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_maxcontrol_version-1]=0;
      this->maxcontrol_version = (char *)(inbuffer + offset-1);
      offset += length_maxcontrol_version;
      uint32_t length_perception_kit_version;
      arrToVar(length_perception_kit_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_perception_kit_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_perception_kit_version-1]=0;
      this->perception_kit_version = (char *)(inbuffer + offset-1);
      offset += length_perception_kit_version;
     return offset;
    }

    virtual const char * getType() override { return "luna_msgs/SoftwareVersion"; };
    virtual const char * getMD5() override { return "0e644c86efa9b857f7a10770411d40cf"; };

  };

}
#endif
