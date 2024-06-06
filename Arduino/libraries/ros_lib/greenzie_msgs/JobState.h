#ifndef _ROS_greenzie_msgs_JobState_h
#define _ROS_greenzie_msgs_JobState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class JobState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _job_id_type;
      _job_id_type job_id;
      typedef float _job_updated_at_type;
      _job_updated_at_type job_updated_at;
      typedef bool _has_map_type;
      _has_map_type has_map;
      typedef bool _has_stripe_angle_rad_type;
      _has_stripe_angle_rad_type has_stripe_angle_rad;
      typedef bool _has_start_position_type;
      _has_start_position_type has_start_position;
      typedef bool _has_end_position_type;
      _has_end_position_type has_end_position;
      typedef bool _has_mower_deck_width_m_type;
      _has_mower_deck_width_m_type has_mower_deck_width_m;
      typedef bool _has_stripe_overlap_on_each_side_m_type;
      _has_stripe_overlap_on_each_side_m_type has_stripe_overlap_on_each_side_m;

    JobState():
      header(),
      job_id(""),
      job_updated_at(0),
      has_map(0),
      has_stripe_angle_rad(0),
      has_start_position(0),
      has_end_position(0),
      has_mower_deck_width_m(0),
      has_stripe_overlap_on_each_side_m(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_job_id = strlen(this->job_id);
      varToArr(outbuffer + offset, length_job_id);
      offset += 4;
      memcpy(outbuffer + offset, this->job_id, length_job_id);
      offset += length_job_id;
      offset += serializeAvrFloat64(outbuffer + offset, this->job_updated_at);
      union {
        bool real;
        uint8_t base;
      } u_has_map;
      u_has_map.real = this->has_map;
      *(outbuffer + offset + 0) = (u_has_map.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_map);
      union {
        bool real;
        uint8_t base;
      } u_has_stripe_angle_rad;
      u_has_stripe_angle_rad.real = this->has_stripe_angle_rad;
      *(outbuffer + offset + 0) = (u_has_stripe_angle_rad.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_stripe_angle_rad);
      union {
        bool real;
        uint8_t base;
      } u_has_start_position;
      u_has_start_position.real = this->has_start_position;
      *(outbuffer + offset + 0) = (u_has_start_position.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_start_position);
      union {
        bool real;
        uint8_t base;
      } u_has_end_position;
      u_has_end_position.real = this->has_end_position;
      *(outbuffer + offset + 0) = (u_has_end_position.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_end_position);
      union {
        bool real;
        uint8_t base;
      } u_has_mower_deck_width_m;
      u_has_mower_deck_width_m.real = this->has_mower_deck_width_m;
      *(outbuffer + offset + 0) = (u_has_mower_deck_width_m.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_mower_deck_width_m);
      union {
        bool real;
        uint8_t base;
      } u_has_stripe_overlap_on_each_side_m;
      u_has_stripe_overlap_on_each_side_m.real = this->has_stripe_overlap_on_each_side_m;
      *(outbuffer + offset + 0) = (u_has_stripe_overlap_on_each_side_m.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_stripe_overlap_on_each_side_m);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_job_id;
      arrToVar(length_job_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_job_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_job_id-1]=0;
      this->job_id = (char *)(inbuffer + offset-1);
      offset += length_job_id;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->job_updated_at));
      union {
        bool real;
        uint8_t base;
      } u_has_map;
      u_has_map.base = 0;
      u_has_map.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_map = u_has_map.real;
      offset += sizeof(this->has_map);
      union {
        bool real;
        uint8_t base;
      } u_has_stripe_angle_rad;
      u_has_stripe_angle_rad.base = 0;
      u_has_stripe_angle_rad.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_stripe_angle_rad = u_has_stripe_angle_rad.real;
      offset += sizeof(this->has_stripe_angle_rad);
      union {
        bool real;
        uint8_t base;
      } u_has_start_position;
      u_has_start_position.base = 0;
      u_has_start_position.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_start_position = u_has_start_position.real;
      offset += sizeof(this->has_start_position);
      union {
        bool real;
        uint8_t base;
      } u_has_end_position;
      u_has_end_position.base = 0;
      u_has_end_position.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_end_position = u_has_end_position.real;
      offset += sizeof(this->has_end_position);
      union {
        bool real;
        uint8_t base;
      } u_has_mower_deck_width_m;
      u_has_mower_deck_width_m.base = 0;
      u_has_mower_deck_width_m.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_mower_deck_width_m = u_has_mower_deck_width_m.real;
      offset += sizeof(this->has_mower_deck_width_m);
      union {
        bool real;
        uint8_t base;
      } u_has_stripe_overlap_on_each_side_m;
      u_has_stripe_overlap_on_each_side_m.base = 0;
      u_has_stripe_overlap_on_each_side_m.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_stripe_overlap_on_each_side_m = u_has_stripe_overlap_on_each_side_m.real;
      offset += sizeof(this->has_stripe_overlap_on_each_side_m);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/JobState"; };
    virtual const char * getMD5() override { return "d5e8b830b284de4c7e74f37365a90b9f"; };

  };

}
#endif
