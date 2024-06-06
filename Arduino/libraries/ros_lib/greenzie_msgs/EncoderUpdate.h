#ifndef _ROS_greenzie_msgs_EncoderUpdate_h
#define _ROS_greenzie_msgs_EncoderUpdate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class EncoderUpdate : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t encoder_position_length;
      typedef int32_t _encoder_position_type;
      _encoder_position_type st_encoder_position;
      _encoder_position_type * encoder_position;

    EncoderUpdate():
      header(),
      encoder_position_length(0), st_encoder_position(), encoder_position(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->encoder_position_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->encoder_position_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->encoder_position_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->encoder_position_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->encoder_position_length);
      for( uint32_t i = 0; i < encoder_position_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_encoder_positioni;
      u_encoder_positioni.real = this->encoder_position[i];
      *(outbuffer + offset + 0) = (u_encoder_positioni.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_encoder_positioni.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_encoder_positioni.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_encoder_positioni.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->encoder_position[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t encoder_position_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      encoder_position_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      encoder_position_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      encoder_position_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->encoder_position_length);
      if(encoder_position_lengthT > encoder_position_length)
        this->encoder_position = (int32_t*)realloc(this->encoder_position, encoder_position_lengthT * sizeof(int32_t));
      encoder_position_length = encoder_position_lengthT;
      for( uint32_t i = 0; i < encoder_position_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_encoder_position;
      u_st_encoder_position.base = 0;
      u_st_encoder_position.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_encoder_position.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_encoder_position.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_encoder_position.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_encoder_position = u_st_encoder_position.real;
      offset += sizeof(this->st_encoder_position);
        memcpy( &(this->encoder_position[i]), &(this->st_encoder_position), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/EncoderUpdate"; };
    virtual const char * getMD5() override { return "e030e744cb477707cceeba0883d3991c"; };

  };

}
#endif
