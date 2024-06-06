#ifndef _ROS_greenzie_msgs_PoEInfo_h
#define _ROS_greenzie_msgs_PoEInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/PoEPortInfo.h"

namespace greenzie_msgs
{

  class PoEInfo : public ros::Msg
  {
    public:
      typedef const char* _version_type;
      _version_type version;
      uint32_t ports_length;
      typedef greenzie_msgs::PoEPortInfo _ports_type;
      _ports_type st_ports;
      _ports_type * ports;

    PoEInfo():
      version(""),
      ports_length(0), st_ports(), ports(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_version = strlen(this->version);
      varToArr(outbuffer + offset, length_version);
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_version);
      offset += length_version;
      *(outbuffer + offset + 0) = (this->ports_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ports_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ports_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ports_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ports_length);
      for( uint32_t i = 0; i < ports_length; i++){
      offset += this->ports[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_version;
      arrToVar(length_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_version-1]=0;
      this->version = (char *)(inbuffer + offset-1);
      offset += length_version;
      uint32_t ports_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ports_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ports_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ports_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ports_length);
      if(ports_lengthT > ports_length)
        this->ports = (greenzie_msgs::PoEPortInfo*)realloc(this->ports, ports_lengthT * sizeof(greenzie_msgs::PoEPortInfo));
      ports_length = ports_lengthT;
      for( uint32_t i = 0; i < ports_length; i++){
      offset += this->st_ports.deserialize(inbuffer + offset);
        memcpy( &(this->ports[i]), &(this->st_ports), sizeof(greenzie_msgs::PoEPortInfo));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/PoEInfo"; };
    virtual const char * getMD5() override { return "64a537b20d876e3d7056f2b1ba3b3a27"; };

  };

}
#endif
