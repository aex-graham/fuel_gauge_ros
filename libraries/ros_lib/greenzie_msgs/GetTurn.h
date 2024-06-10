#ifndef _ROS_SERVICE_GetTurn_h
#define _ROS_SERVICE_GetTurn_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "greenzie_msgs/StripingState.h"
#include "greenzie_msgs/KeepOutZone.h"

namespace greenzie_msgs
{

static const char GETTURN[] = "greenzie_msgs/GetTurn";

  class GetTurnRequest : public ros::Msg
  {
    public:
      typedef const char* _frame_id_type;
      _frame_id_type frame_id;
      typedef geometry_msgs::Point _first_stripe_start_type;
      _first_stripe_start_type first_stripe_start;
      typedef geometry_msgs::Point _first_stripe_end_type;
      _first_stripe_end_type first_stripe_end;
      typedef geometry_msgs::Point _second_stripe_start_type;
      _second_stripe_start_type second_stripe_start;
      typedef geometry_msgs::Point _second_stripe_end_type;
      _second_stripe_end_type second_stripe_end;
      typedef const char* _turn_type_name_type;
      _turn_type_name_type turn_type_name;
      typedef float _mower_deck_width_m_type;
      _mower_deck_width_m_type mower_deck_width_m;
      typedef float _stripe_overlap_on_each_side_m_type;
      _stripe_overlap_on_each_side_m_type stripe_overlap_on_each_side_m;
      uint32_t keep_out_zones_length;
      typedef greenzie_msgs::KeepOutZone _keep_out_zones_type;
      _keep_out_zones_type st_keep_out_zones;
      _keep_out_zones_type * keep_out_zones;

    GetTurnRequest():
      frame_id(""),
      first_stripe_start(),
      first_stripe_end(),
      second_stripe_start(),
      second_stripe_end(),
      turn_type_name(""),
      mower_deck_width_m(0),
      stripe_overlap_on_each_side_m(0),
      keep_out_zones_length(0), st_keep_out_zones(), keep_out_zones(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_frame_id = strlen(this->frame_id);
      varToArr(outbuffer + offset, length_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      offset += this->first_stripe_start.serialize(outbuffer + offset);
      offset += this->first_stripe_end.serialize(outbuffer + offset);
      offset += this->second_stripe_start.serialize(outbuffer + offset);
      offset += this->second_stripe_end.serialize(outbuffer + offset);
      uint32_t length_turn_type_name = strlen(this->turn_type_name);
      varToArr(outbuffer + offset, length_turn_type_name);
      offset += 4;
      memcpy(outbuffer + offset, this->turn_type_name, length_turn_type_name);
      offset += length_turn_type_name;
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
        float real;
        uint32_t base;
      } u_stripe_overlap_on_each_side_m;
      u_stripe_overlap_on_each_side_m.real = this->stripe_overlap_on_each_side_m;
      *(outbuffer + offset + 0) = (u_stripe_overlap_on_each_side_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stripe_overlap_on_each_side_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stripe_overlap_on_each_side_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stripe_overlap_on_each_side_m.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stripe_overlap_on_each_side_m);
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
      uint32_t length_frame_id;
      arrToVar(length_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      offset += this->first_stripe_start.deserialize(inbuffer + offset);
      offset += this->first_stripe_end.deserialize(inbuffer + offset);
      offset += this->second_stripe_start.deserialize(inbuffer + offset);
      offset += this->second_stripe_end.deserialize(inbuffer + offset);
      uint32_t length_turn_type_name;
      arrToVar(length_turn_type_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_turn_type_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_turn_type_name-1]=0;
      this->turn_type_name = (char *)(inbuffer + offset-1);
      offset += length_turn_type_name;
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

    virtual const char * getType() override { return GETTURN; };
    virtual const char * getMD5() override { return "86bebc90fa2236095cac11263347166b"; };

  };

  class GetTurnResponse : public ros::Msg
  {
    public:
      typedef bool _valid_plan_type;
      _valid_plan_type valid_plan;
      uint32_t states_length;
      typedef greenzie_msgs::StripingState _states_type;
      _states_type st_states;
      _states_type * states;
      uint32_t extrema_states_length;
      typedef greenzie_msgs::StripingState _extrema_states_type;
      _extrema_states_type st_extrema_states;
      _extrema_states_type * extrema_states;
      typedef float _expected_shift_type;
      _expected_shift_type expected_shift;

    GetTurnResponse():
      valid_plan(0),
      states_length(0), st_states(), states(nullptr),
      extrema_states_length(0), st_extrema_states(), extrema_states(nullptr),
      expected_shift(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_valid_plan;
      u_valid_plan.real = this->valid_plan;
      *(outbuffer + offset + 0) = (u_valid_plan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valid_plan);
      *(outbuffer + offset + 0) = (this->states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->extrema_states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->extrema_states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->extrema_states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->extrema_states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->extrema_states_length);
      for( uint32_t i = 0; i < extrema_states_length; i++){
      offset += this->extrema_states[i].serialize(outbuffer + offset);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->expected_shift);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_valid_plan;
      u_valid_plan.base = 0;
      u_valid_plan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->valid_plan = u_valid_plan.real;
      offset += sizeof(this->valid_plan);
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->states_length);
      if(states_lengthT > states_length)
        this->states = (greenzie_msgs::StripingState*)realloc(this->states, states_lengthT * sizeof(greenzie_msgs::StripingState));
      states_length = states_lengthT;
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->st_states.deserialize(inbuffer + offset);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(greenzie_msgs::StripingState));
      }
      uint32_t extrema_states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      extrema_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      extrema_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      extrema_states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->extrema_states_length);
      if(extrema_states_lengthT > extrema_states_length)
        this->extrema_states = (greenzie_msgs::StripingState*)realloc(this->extrema_states, extrema_states_lengthT * sizeof(greenzie_msgs::StripingState));
      extrema_states_length = extrema_states_lengthT;
      for( uint32_t i = 0; i < extrema_states_length; i++){
      offset += this->st_extrema_states.deserialize(inbuffer + offset);
        memcpy( &(this->extrema_states[i]), &(this->st_extrema_states), sizeof(greenzie_msgs::StripingState));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->expected_shift));
     return offset;
    }

    virtual const char * getType() override { return GETTURN; };
    virtual const char * getMD5() override { return "9b30b85f4a8765d474b4cbc9b0d34f96"; };

  };

  class GetTurn {
    public:
    typedef GetTurnRequest Request;
    typedef GetTurnResponse Response;
  };

}
#endif
