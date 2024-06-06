#ifndef _ROS_greenzie_msgs_CoordinateSystemUpdate_h
#define _ROS_greenzie_msgs_CoordinateSystemUpdate_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace greenzie_msgs
{

  class CoordinateSystemUpdate : public ros::Msg
  {
    public:
      typedef uint8_t _category_type;
      _category_type category;
      typedef const char* _frame_id_type;
      _frame_id_type frame_id;
      typedef uint8_t _sequence_id_type;
      _sequence_id_type sequence_id;
      typedef geometry_msgs::Point _offset_type;
      _offset_type offset;
      typedef bool _is_valid_type;
      _is_valid_type is_valid;
      typedef bool _is_in_type;
      _is_in_type is_in;

    CoordinateSystemUpdate():
      category(0),
      frame_id(""),
      sequence_id(0),
      offset(),
      is_valid(0),
      is_in(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->category >> (8 * 0)) & 0xFF;
      offset += sizeof(this->category);
      uint32_t length_frame_id = strlen(this->frame_id);
      varToArr(outbuffer + offset, length_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      *(outbuffer + offset + 0) = (this->sequence_id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sequence_id);
      offset += this->offset.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_valid;
      u_is_valid.real = this->is_valid;
      *(outbuffer + offset + 0) = (u_is_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_valid);
      union {
        bool real;
        uint8_t base;
      } u_is_in;
      u_is_in.real = this->is_in;
      *(outbuffer + offset + 0) = (u_is_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_in);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->category =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->category);
      uint32_t length_frame_id;
      arrToVar(length_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      this->sequence_id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sequence_id);
      offset += this->offset.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_valid;
      u_is_valid.base = 0;
      u_is_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_valid = u_is_valid.real;
      offset += sizeof(this->is_valid);
      union {
        bool real;
        uint8_t base;
      } u_is_in;
      u_is_in.base = 0;
      u_is_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_in = u_is_in.real;
      offset += sizeof(this->is_in);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/CoordinateSystemUpdate"; };
    virtual const char * getMD5() override { return "5ae8f29adc537976783aabf520570790"; };

  };

}
#endif
