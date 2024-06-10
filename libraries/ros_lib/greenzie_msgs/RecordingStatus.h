#ifndef _ROS_greenzie_msgs_RecordingStatus_h
#define _ROS_greenzie_msgs_RecordingStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace greenzie_msgs
{

  class RecordingStatus : public ros::Msg
  {
    public:
      typedef bool _is_recording_type;
      _is_recording_type is_recording;
      uint32_t recorded_path_length;
      typedef geometry_msgs::Point _recorded_path_type;
      _recorded_path_type st_recorded_path;
      _recorded_path_type * recorded_path;

    RecordingStatus():
      is_recording(0),
      recorded_path_length(0), st_recorded_path(), recorded_path(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_recording;
      u_is_recording.real = this->is_recording;
      *(outbuffer + offset + 0) = (u_is_recording.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_recording);
      *(outbuffer + offset + 0) = (this->recorded_path_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->recorded_path_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->recorded_path_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->recorded_path_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recorded_path_length);
      for( uint32_t i = 0; i < recorded_path_length; i++){
      offset += this->recorded_path[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_is_recording;
      u_is_recording.base = 0;
      u_is_recording.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_recording = u_is_recording.real;
      offset += sizeof(this->is_recording);
      uint32_t recorded_path_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      recorded_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      recorded_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      recorded_path_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->recorded_path_length);
      if(recorded_path_lengthT > recorded_path_length)
        this->recorded_path = (geometry_msgs::Point*)realloc(this->recorded_path, recorded_path_lengthT * sizeof(geometry_msgs::Point));
      recorded_path_length = recorded_path_lengthT;
      for( uint32_t i = 0; i < recorded_path_length; i++){
      offset += this->st_recorded_path.deserialize(inbuffer + offset);
        memcpy( &(this->recorded_path[i]), &(this->st_recorded_path), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/RecordingStatus"; };
    virtual const char * getMD5() override { return "13b2b18a31f8932d90e13980bd8a0244"; };

  };

}
#endif
