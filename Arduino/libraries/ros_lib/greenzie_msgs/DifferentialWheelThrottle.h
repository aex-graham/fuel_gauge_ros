#ifndef _ROS_greenzie_msgs_DifferentialWheelThrottle_h
#define _ROS_greenzie_msgs_DifferentialWheelThrottle_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class DifferentialWheelThrottle : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t setpoints_length;
      typedef float _setpoints_type;
      _setpoints_type st_setpoints;
      _setpoints_type * setpoints;

    DifferentialWheelThrottle():
      header(),
      setpoints_length(0), st_setpoints(), setpoints(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->setpoints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->setpoints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->setpoints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->setpoints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->setpoints_length);
      for( uint32_t i = 0; i < setpoints_length; i++){
      union {
        float real;
        uint32_t base;
      } u_setpointsi;
      u_setpointsi.real = this->setpoints[i];
      *(outbuffer + offset + 0) = (u_setpointsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_setpointsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_setpointsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_setpointsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->setpoints[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t setpoints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      setpoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      setpoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      setpoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->setpoints_length);
      if(setpoints_lengthT > setpoints_length)
        this->setpoints = (float*)realloc(this->setpoints, setpoints_lengthT * sizeof(float));
      setpoints_length = setpoints_lengthT;
      for( uint32_t i = 0; i < setpoints_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_setpoints;
      u_st_setpoints.base = 0;
      u_st_setpoints.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_setpoints.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_setpoints.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_setpoints.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_setpoints = u_st_setpoints.real;
      offset += sizeof(this->st_setpoints);
        memcpy( &(this->setpoints[i]), &(this->st_setpoints), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/DifferentialWheelThrottle"; };
    virtual const char * getMD5() override { return "fbc18b026f8844e3631f1f32fa685df5"; };

  };

}
#endif
