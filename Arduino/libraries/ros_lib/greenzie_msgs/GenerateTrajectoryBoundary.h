#ifndef _ROS_SERVICE_GenerateTrajectoryBoundary_h
#define _ROS_SERVICE_GenerateTrajectoryBoundary_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PolygonStamped.h"
#include "greenzie_msgs/KeepOutZone.h"
#include "greenzie_msgs/StripingTrajectory.h"

namespace greenzie_msgs
{

static const char GENERATETRAJECTORYBOUNDARY[] = "greenzie_msgs/GenerateTrajectoryBoundary";

  class GenerateTrajectoryBoundaryRequest : public ros::Msg
  {
    public:
      typedef greenzie_msgs::StripingTrajectory _trajectory_type;
      _trajectory_type trajectory;

    GenerateTrajectoryBoundaryRequest():
      trajectory()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GENERATETRAJECTORYBOUNDARY; };
    virtual const char * getMD5() override { return "2d21c117bf8b397cd2c7626241c688f9"; };

  };

  class GenerateTrajectoryBoundaryResponse : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;
      typedef bool _success_type;
      _success_type success;
      typedef geometry_msgs::PolygonStamped _boundary_type;
      _boundary_type boundary;
      uint32_t keep_out_zones_length;
      typedef greenzie_msgs::KeepOutZone _keep_out_zones_type;
      _keep_out_zones_type st_keep_out_zones;
      _keep_out_zones_type * keep_out_zones;

    GenerateTrajectoryBoundaryResponse():
      message(""),
      success(0),
      boundary(),
      keep_out_zones_length(0), st_keep_out_zones(), keep_out_zones(nullptr)
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
      offset += this->boundary.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->keep_out_zones_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->keep_out_zones_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->keep_out_zones_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->keep_out_zones_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->keep_out_zones_length);
      for( uint32_t i = 0; i < keep_out_zones_length; i++){
      offset += this->keep_out_zones[i].serialize(outbuffer + offset);
      }
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
      offset += this->boundary.deserialize(inbuffer + offset);
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
     return offset;
    }

    virtual const char * getType() override { return GENERATETRAJECTORYBOUNDARY; };
    virtual const char * getMD5() override { return "345668c7f6bbae1b1de67852abe773d9"; };

  };

  class GenerateTrajectoryBoundary {
    public:
    typedef GenerateTrajectoryBoundaryRequest Request;
    typedef GenerateTrajectoryBoundaryResponse Response;
  };

}
#endif
