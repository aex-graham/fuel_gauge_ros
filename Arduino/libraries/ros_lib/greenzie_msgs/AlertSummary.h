#ifndef _ROS_greenzie_msgs_AlertSummary_h
#define _ROS_greenzie_msgs_AlertSummary_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/Alert.h"

namespace greenzie_msgs
{

  class AlertSummary : public ros::Msg
  {
    public:
      uint32_t alerts_length;
      typedef greenzie_msgs::Alert _alerts_type;
      _alerts_type st_alerts;
      _alerts_type * alerts;
      uint32_t ignore_sources_length;
      typedef char* _ignore_sources_type;
      _ignore_sources_type st_ignore_sources;
      _ignore_sources_type * ignore_sources;

    AlertSummary():
      alerts_length(0), st_alerts(), alerts(nullptr),
      ignore_sources_length(0), st_ignore_sources(), ignore_sources(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->alerts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->alerts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->alerts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->alerts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alerts_length);
      for( uint32_t i = 0; i < alerts_length; i++){
      offset += this->alerts[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->ignore_sources_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ignore_sources_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ignore_sources_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ignore_sources_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ignore_sources_length);
      for( uint32_t i = 0; i < ignore_sources_length; i++){
      uint32_t length_ignore_sourcesi = strlen(this->ignore_sources[i]);
      varToArr(outbuffer + offset, length_ignore_sourcesi);
      offset += 4;
      memcpy(outbuffer + offset, this->ignore_sources[i], length_ignore_sourcesi);
      offset += length_ignore_sourcesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t alerts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      alerts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      alerts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      alerts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->alerts_length);
      if(alerts_lengthT > alerts_length)
        this->alerts = (greenzie_msgs::Alert*)realloc(this->alerts, alerts_lengthT * sizeof(greenzie_msgs::Alert));
      alerts_length = alerts_lengthT;
      for( uint32_t i = 0; i < alerts_length; i++){
      offset += this->st_alerts.deserialize(inbuffer + offset);
        memcpy( &(this->alerts[i]), &(this->st_alerts), sizeof(greenzie_msgs::Alert));
      }
      uint32_t ignore_sources_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ignore_sources_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ignore_sources_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ignore_sources_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ignore_sources_length);
      if(ignore_sources_lengthT > ignore_sources_length)
        this->ignore_sources = (char**)realloc(this->ignore_sources, ignore_sources_lengthT * sizeof(char*));
      ignore_sources_length = ignore_sources_lengthT;
      for( uint32_t i = 0; i < ignore_sources_length; i++){
      uint32_t length_st_ignore_sources;
      arrToVar(length_st_ignore_sources, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_ignore_sources; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_ignore_sources-1]=0;
      this->st_ignore_sources = (char *)(inbuffer + offset-1);
      offset += length_st_ignore_sources;
        memcpy( &(this->ignore_sources[i]), &(this->st_ignore_sources), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/AlertSummary"; };
    virtual const char * getMD5() override { return "6355a5ded85cd94cb73e9d1e888d82eb"; };

  };

}
#endif
