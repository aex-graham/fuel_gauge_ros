#ifndef _ROS_SERVICE_SetJobRecording_h
#define _ROS_SERVICE_SetJobRecording_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PolygonStamped.h"
#include "greenzie_msgs/KeepOutZone.h"
#include "greenzie_msgs/StripingState.h"

namespace greenzie_msgs
{

static const char SETJOBRECORDING[] = "greenzie_msgs/SetJobRecording";

  class SetJobRecordingRequest : public ros::Msg
  {
    public:
      typedef geometry_msgs::PolygonStamped _perimeter_type;
      _perimeter_type perimeter;
      uint32_t recorded_states_length;
      typedef greenzie_msgs::StripingState _recorded_states_type;
      _recorded_states_type st_recorded_states;
      _recorded_states_type * recorded_states;
      uint32_t keep_out_zones_length;
      typedef greenzie_msgs::KeepOutZone _keep_out_zones_type;
      _keep_out_zones_type st_keep_out_zones;
      _keep_out_zones_type * keep_out_zones;
      uint32_t recorded_states_simplified_length;
      typedef greenzie_msgs::StripingState _recorded_states_simplified_type;
      _recorded_states_simplified_type st_recorded_states_simplified;
      _recorded_states_simplified_type * recorded_states_simplified;

    SetJobRecordingRequest():
      perimeter(),
      recorded_states_length(0), st_recorded_states(), recorded_states(nullptr),
      keep_out_zones_length(0), st_keep_out_zones(), keep_out_zones(nullptr),
      recorded_states_simplified_length(0), st_recorded_states_simplified(), recorded_states_simplified(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->perimeter.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->recorded_states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->recorded_states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->recorded_states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->recorded_states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recorded_states_length);
      for( uint32_t i = 0; i < recorded_states_length; i++){
      offset += this->recorded_states[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->keep_out_zones_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->keep_out_zones_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->keep_out_zones_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->keep_out_zones_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->keep_out_zones_length);
      for( uint32_t i = 0; i < keep_out_zones_length; i++){
      offset += this->keep_out_zones[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->recorded_states_simplified_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->recorded_states_simplified_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->recorded_states_simplified_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->recorded_states_simplified_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recorded_states_simplified_length);
      for( uint32_t i = 0; i < recorded_states_simplified_length; i++){
      offset += this->recorded_states_simplified[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->perimeter.deserialize(inbuffer + offset);
      uint32_t recorded_states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      recorded_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      recorded_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      recorded_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->recorded_states_length);
      if(recorded_states_lengthT > recorded_states_length)
        this->recorded_states = (greenzie_msgs::StripingState*)realloc(this->recorded_states, recorded_states_lengthT * sizeof(greenzie_msgs::StripingState));
      recorded_states_length = recorded_states_lengthT;
      for( uint32_t i = 0; i < recorded_states_length; i++){
      offset += this->st_recorded_states.deserialize(inbuffer + offset);
        memcpy( &(this->recorded_states[i]), &(this->st_recorded_states), sizeof(greenzie_msgs::StripingState));
      }
      uint32_t keep_out_zones_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      keep_out_zones_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      keep_out_zones_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      keep_out_zones_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->keep_out_zones_length);
      if(keep_out_zones_lengthT > keep_out_zones_length)
        this->keep_out_zones = (greenzie_msgs::KeepOutZone*)realloc(this->keep_out_zones, keep_out_zones_lengthT * sizeof(greenzie_msgs::KeepOutZone));
      keep_out_zones_length = keep_out_zones_lengthT;
      for( uint32_t i = 0; i < keep_out_zones_length; i++){
      offset += this->st_keep_out_zones.deserialize(inbuffer + offset);
        memcpy( &(this->keep_out_zones[i]), &(this->st_keep_out_zones), sizeof(greenzie_msgs::KeepOutZone));
      }
      uint32_t recorded_states_simplified_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      recorded_states_simplified_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      recorded_states_simplified_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      recorded_states_simplified_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->recorded_states_simplified_length);
      if(recorded_states_simplified_lengthT > recorded_states_simplified_length)
        this->recorded_states_simplified = (greenzie_msgs::StripingState*)realloc(this->recorded_states_simplified, recorded_states_simplified_lengthT * sizeof(greenzie_msgs::StripingState));
      recorded_states_simplified_length = recorded_states_simplified_lengthT;
      for( uint32_t i = 0; i < recorded_states_simplified_length; i++){
      offset += this->st_recorded_states_simplified.deserialize(inbuffer + offset);
        memcpy( &(this->recorded_states_simplified[i]), &(this->st_recorded_states_simplified), sizeof(greenzie_msgs::StripingState));
      }
     return offset;
    }

    virtual const char * getType() override { return SETJOBRECORDING; };
    virtual const char * getMD5() override { return "ecbee512a9b21ec6bdc20c1f9afefeec"; };

  };

  class SetJobRecordingResponse : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;
      typedef bool _success_type;
      _success_type success;

    SetJobRecordingResponse():
      message(""),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return SETJOBRECORDING; };
    virtual const char * getMD5() override { return "9bf829f07d795d3f9e541a07897da2c4"; };

  };

  class SetJobRecording {
    public:
    typedef SetJobRecordingRequest Request;
    typedef SetJobRecordingResponse Response;
  };

}
#endif
