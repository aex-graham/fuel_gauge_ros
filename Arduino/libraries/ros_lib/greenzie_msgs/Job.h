#ifndef _ROS_greenzie_msgs_Job_h
#define _ROS_greenzie_msgs_Job_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PolygonStamped.h"
#include "greenzie_msgs/KeepOutZone.h"
#include "geometry_msgs/Point.h"
#include "greenzie_msgs/StripingState.h"

namespace greenzie_msgs
{

  class Job : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef const char* _host_type;
      _host_type host;
      typedef float _created_at_type;
      _created_at_type created_at;
      typedef float _updated_at_type;
      _updated_at_type updated_at;
      typedef bool _has_map_type;
      _has_map_type has_map;
      typedef geometry_msgs::PolygonStamped _map_type;
      _map_type map;
      uint32_t keep_out_zones_length;
      typedef greenzie_msgs::KeepOutZone _keep_out_zones_type;
      _keep_out_zones_type st_keep_out_zones;
      _keep_out_zones_type * keep_out_zones;
      typedef bool _has_start_position_type;
      _has_start_position_type has_start_position;
      typedef geometry_msgs::Point _start_position_type;
      _start_position_type start_position;
      typedef bool _has_end_position_type;
      _has_end_position_type has_end_position;
      typedef geometry_msgs::Point _end_position_type;
      _end_position_type end_position;
      typedef bool _has_stripe_angle_rad_type;
      _has_stripe_angle_rad_type has_stripe_angle_rad;
      typedef float _stripe_angle_rad_type;
      _stripe_angle_rad_type stripe_angle_rad;
      typedef bool _is_earth_valid_type;
      _is_earth_valid_type is_earth_valid;
      typedef uint32_t _num_repeats_type;
      _num_repeats_type num_repeats;
      typedef bool _has_mower_deck_width_m_type;
      _has_mower_deck_width_m_type has_mower_deck_width_m;
      typedef float _mower_deck_width_m_type;
      _mower_deck_width_m_type mower_deck_width_m;
      typedef bool _has_stripe_overlap_on_each_side_m_type;
      _has_stripe_overlap_on_each_side_m_type has_stripe_overlap_on_each_side_m;
      typedef float _stripe_overlap_on_each_side_m_type;
      _stripe_overlap_on_each_side_m_type stripe_overlap_on_each_side_m;
      typedef bool _is_record_and_repeat_type;
      _is_record_and_repeat_type is_record_and_repeat;
      uint32_t recorded_states_length;
      typedef greenzie_msgs::StripingState _recorded_states_type;
      _recorded_states_type st_recorded_states;
      _recorded_states_type * recorded_states;

    Job():
      id(""),
      host(""),
      created_at(0),
      updated_at(0),
      has_map(0),
      map(),
      keep_out_zones_length(0), st_keep_out_zones(), keep_out_zones(nullptr),
      has_start_position(0),
      start_position(),
      has_end_position(0),
      end_position(),
      has_stripe_angle_rad(0),
      stripe_angle_rad(0),
      is_earth_valid(0),
      num_repeats(0),
      has_mower_deck_width_m(0),
      mower_deck_width_m(0),
      has_stripe_overlap_on_each_side_m(0),
      stripe_overlap_on_each_side_m(0),
      is_record_and_repeat(0),
      recorded_states_length(0), st_recorded_states(), recorded_states(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      uint32_t length_host = strlen(this->host);
      varToArr(outbuffer + offset, length_host);
      offset += 4;
      memcpy(outbuffer + offset, this->host, length_host);
      offset += length_host;
      offset += serializeAvrFloat64(outbuffer + offset, this->created_at);
      offset += serializeAvrFloat64(outbuffer + offset, this->updated_at);
      union {
        bool real;
        uint8_t base;
      } u_has_map;
      u_has_map.real = this->has_map;
      *(outbuffer + offset + 0) = (u_has_map.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_map);
      offset += this->map.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->keep_out_zones_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->keep_out_zones_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->keep_out_zones_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->keep_out_zones_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->keep_out_zones_length);
      for( uint32_t i = 0; i < keep_out_zones_length; i++){
      offset += this->keep_out_zones[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_has_start_position;
      u_has_start_position.real = this->has_start_position;
      *(outbuffer + offset + 0) = (u_has_start_position.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_start_position);
      offset += this->start_position.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_has_end_position;
      u_has_end_position.real = this->has_end_position;
      *(outbuffer + offset + 0) = (u_has_end_position.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_end_position);
      offset += this->end_position.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_has_stripe_angle_rad;
      u_has_stripe_angle_rad.real = this->has_stripe_angle_rad;
      *(outbuffer + offset + 0) = (u_has_stripe_angle_rad.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_stripe_angle_rad);
      union {
        float real;
        uint32_t base;
      } u_stripe_angle_rad;
      u_stripe_angle_rad.real = this->stripe_angle_rad;
      *(outbuffer + offset + 0) = (u_stripe_angle_rad.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stripe_angle_rad.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stripe_angle_rad.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stripe_angle_rad.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stripe_angle_rad);
      union {
        bool real;
        uint8_t base;
      } u_is_earth_valid;
      u_is_earth_valid.real = this->is_earth_valid;
      *(outbuffer + offset + 0) = (u_is_earth_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_earth_valid);
      *(outbuffer + offset + 0) = (this->num_repeats >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_repeats >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_repeats >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_repeats >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_repeats);
      union {
        bool real;
        uint8_t base;
      } u_has_mower_deck_width_m;
      u_has_mower_deck_width_m.real = this->has_mower_deck_width_m;
      *(outbuffer + offset + 0) = (u_has_mower_deck_width_m.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_mower_deck_width_m);
      union {
        float real;
        uint32_t base;
      } u_mower_deck_width_m;
      u_mower_deck_width_m.real = this->mower_deck_width_m;
      *(outbuffer + offset + 0) = (u_mower_deck_width_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mower_deck_width_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mower_deck_width_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mower_deck_width_m.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mower_deck_width_m);
      union {
        bool real;
        uint8_t base;
      } u_has_stripe_overlap_on_each_side_m;
      u_has_stripe_overlap_on_each_side_m.real = this->has_stripe_overlap_on_each_side_m;
      *(outbuffer + offset + 0) = (u_has_stripe_overlap_on_each_side_m.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_stripe_overlap_on_each_side_m);
      union {
        float real;
        uint32_t base;
      } u_stripe_overlap_on_each_side_m;
      u_stripe_overlap_on_each_side_m.real = this->stripe_overlap_on_each_side_m;
      *(outbuffer + offset + 0) = (u_stripe_overlap_on_each_side_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stripe_overlap_on_each_side_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stripe_overlap_on_each_side_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stripe_overlap_on_each_side_m.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stripe_overlap_on_each_side_m);
      union {
        bool real;
        uint8_t base;
      } u_is_record_and_repeat;
      u_is_record_and_repeat.real = this->is_record_and_repeat;
      *(outbuffer + offset + 0) = (u_is_record_and_repeat.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_record_and_repeat);
      *(outbuffer + offset + 0) = (this->recorded_states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->recorded_states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->recorded_states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->recorded_states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->recorded_states_length);
      for( uint32_t i = 0; i < recorded_states_length; i++){
      offset += this->recorded_states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      uint32_t length_host;
      arrToVar(length_host, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_host; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_host-1]=0;
      this->host = (char *)(inbuffer + offset-1);
      offset += length_host;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->created_at));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->updated_at));
      union {
        bool real;
        uint8_t base;
      } u_has_map;
      u_has_map.base = 0;
      u_has_map.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_map = u_has_map.real;
      offset += sizeof(this->has_map);
      offset += this->map.deserialize(inbuffer + offset);
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
      union {
        bool real;
        uint8_t base;
      } u_has_start_position;
      u_has_start_position.base = 0;
      u_has_start_position.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_start_position = u_has_start_position.real;
      offset += sizeof(this->has_start_position);
      offset += this->start_position.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_has_end_position;
      u_has_end_position.base = 0;
      u_has_end_position.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_end_position = u_has_end_position.real;
      offset += sizeof(this->has_end_position);
      offset += this->end_position.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_has_stripe_angle_rad;
      u_has_stripe_angle_rad.base = 0;
      u_has_stripe_angle_rad.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_stripe_angle_rad = u_has_stripe_angle_rad.real;
      offset += sizeof(this->has_stripe_angle_rad);
      union {
        float real;
        uint32_t base;
      } u_stripe_angle_rad;
      u_stripe_angle_rad.base = 0;
      u_stripe_angle_rad.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stripe_angle_rad.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stripe_angle_rad.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stripe_angle_rad.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stripe_angle_rad = u_stripe_angle_rad.real;
      offset += sizeof(this->stripe_angle_rad);
      union {
        bool real;
        uint8_t base;
      } u_is_earth_valid;
      u_is_earth_valid.base = 0;
      u_is_earth_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_earth_valid = u_is_earth_valid.real;
      offset += sizeof(this->is_earth_valid);
      this->num_repeats =  ((uint32_t) (*(inbuffer + offset)));
      this->num_repeats |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_repeats |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_repeats |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_repeats);
      union {
        bool real;
        uint8_t base;
      } u_has_mower_deck_width_m;
      u_has_mower_deck_width_m.base = 0;
      u_has_mower_deck_width_m.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_mower_deck_width_m = u_has_mower_deck_width_m.real;
      offset += sizeof(this->has_mower_deck_width_m);
      union {
        float real;
        uint32_t base;
      } u_mower_deck_width_m;
      u_mower_deck_width_m.base = 0;
      u_mower_deck_width_m.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mower_deck_width_m.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mower_deck_width_m.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mower_deck_width_m.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mower_deck_width_m = u_mower_deck_width_m.real;
      offset += sizeof(this->mower_deck_width_m);
      union {
        bool real;
        uint8_t base;
      } u_has_stripe_overlap_on_each_side_m;
      u_has_stripe_overlap_on_each_side_m.base = 0;
      u_has_stripe_overlap_on_each_side_m.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_stripe_overlap_on_each_side_m = u_has_stripe_overlap_on_each_side_m.real;
      offset += sizeof(this->has_stripe_overlap_on_each_side_m);
      union {
        float real;
        uint32_t base;
      } u_stripe_overlap_on_each_side_m;
      u_stripe_overlap_on_each_side_m.base = 0;
      u_stripe_overlap_on_each_side_m.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_stripe_overlap_on_each_side_m.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_stripe_overlap_on_each_side_m.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_stripe_overlap_on_each_side_m.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->stripe_overlap_on_each_side_m = u_stripe_overlap_on_each_side_m.real;
      offset += sizeof(this->stripe_overlap_on_each_side_m);
      union {
        bool real;
        uint8_t base;
      } u_is_record_and_repeat;
      u_is_record_and_repeat.base = 0;
      u_is_record_and_repeat.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_record_and_repeat = u_is_record_and_repeat.real;
      offset += sizeof(this->is_record_and_repeat);
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
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/Job"; };
    virtual const char * getMD5() override { return "8b25344305052c4e342d46b5c704e462"; };

  };

}
#endif
