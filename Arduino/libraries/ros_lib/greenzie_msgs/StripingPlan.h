#ifndef _ROS_greenzie_msgs_StripingPlan_h
#define _ROS_greenzie_msgs_StripingPlan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseStamped.h"
#include "greenzie_msgs/StripingState.h"
#include "greenzie_msgs/Boundary.h"
#include "geometry_msgs/Polygon.h"
#include "greenzie_msgs/Stripe.h"
#include "greenzie_msgs/Cell.h"
#include "greenzie_msgs/TraversalGraph.h"

namespace greenzie_msgs
{

  class StripingPlan : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::PoseStamped _closest_initial_pose_type;
      _closest_initial_pose_type closest_initial_pose;
      uint32_t states_length;
      typedef greenzie_msgs::StripingState _states_type;
      _states_type st_states;
      _states_type * states;
      typedef bool _status_type;
      _status_type status;
      typedef float _stripe_angle_rad_type;
      _stripe_angle_rad_type stripe_angle_rad;
      uint32_t inner_boundaries_length;
      typedef greenzie_msgs::Boundary _inner_boundaries_type;
      _inner_boundaries_type st_inner_boundaries;
      _inner_boundaries_type * inner_boundaries;
      uint32_t expanded_keep_out_zones_length;
      typedef geometry_msgs::Polygon _expanded_keep_out_zones_type;
      _expanded_keep_out_zones_type st_expanded_keep_out_zones;
      _expanded_keep_out_zones_type * expanded_keep_out_zones;
      typedef greenzie_msgs::Boundary _map_perimeter_type;
      _map_perimeter_type map_perimeter;
      uint32_t boundaries_length;
      typedef greenzie_msgs::Boundary _boundaries_type;
      _boundaries_type st_boundaries;
      _boundaries_type * boundaries;
      uint32_t stripes_length;
      typedef greenzie_msgs::Stripe _stripes_type;
      _stripes_type st_stripes;
      _stripes_type * stripes;
      uint32_t cells_length;
      typedef greenzie_msgs::Cell _cells_type;
      _cells_type st_cells;
      _cells_type * cells;
      uint32_t ordered_stripe_ids_length;
      typedef int64_t _ordered_stripe_ids_type;
      _ordered_stripe_ids_type st_ordered_stripe_ids;
      _ordered_stripe_ids_type * ordered_stripe_ids;
      uint32_t ordered_cell_ids_length;
      typedef int64_t _ordered_cell_ids_type;
      _ordered_cell_ids_type st_ordered_cell_ids;
      _ordered_cell_ids_type * ordered_cell_ids;
      typedef greenzie_msgs::TraversalGraph _traversal_graph_type;
      _traversal_graph_type traversal_graph;
      typedef bool _is_record_and_repeat_type;
      _is_record_and_repeat_type is_record_and_repeat;

    StripingPlan():
      header(),
      closest_initial_pose(),
      states_length(0), st_states(), states(nullptr),
      status(0),
      stripe_angle_rad(0),
      inner_boundaries_length(0), st_inner_boundaries(), inner_boundaries(nullptr),
      expanded_keep_out_zones_length(0), st_expanded_keep_out_zones(), expanded_keep_out_zones(nullptr),
      map_perimeter(),
      boundaries_length(0), st_boundaries(), boundaries(nullptr),
      stripes_length(0), st_stripes(), stripes(nullptr),
      cells_length(0), st_cells(), cells(nullptr),
      ordered_stripe_ids_length(0), st_ordered_stripe_ids(), ordered_stripe_ids(nullptr),
      ordered_cell_ids_length(0), st_ordered_cell_ids(), ordered_cell_ids(nullptr),
      traversal_graph(),
      is_record_and_repeat(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->closest_initial_pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      offset += serializeAvrFloat64(outbuffer + offset, this->stripe_angle_rad);
      *(outbuffer + offset + 0) = (this->inner_boundaries_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->inner_boundaries_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->inner_boundaries_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->inner_boundaries_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->inner_boundaries_length);
      for( uint32_t i = 0; i < inner_boundaries_length; i++){
      offset += this->inner_boundaries[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->expanded_keep_out_zones_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->expanded_keep_out_zones_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->expanded_keep_out_zones_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->expanded_keep_out_zones_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->expanded_keep_out_zones_length);
      for( uint32_t i = 0; i < expanded_keep_out_zones_length; i++){
      offset += this->expanded_keep_out_zones[i].serialize(outbuffer + offset);
      }
      offset += this->map_perimeter.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->boundaries_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->boundaries_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->boundaries_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->boundaries_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->boundaries_length);
      for( uint32_t i = 0; i < boundaries_length; i++){
      offset += this->boundaries[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->stripes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stripes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stripes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stripes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stripes_length);
      for( uint32_t i = 0; i < stripes_length; i++){
      offset += this->stripes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cells_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cells_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cells_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cells_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cells_length);
      for( uint32_t i = 0; i < cells_length; i++){
      offset += this->cells[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->ordered_stripe_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ordered_stripe_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ordered_stripe_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ordered_stripe_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ordered_stripe_ids_length);
      for( uint32_t i = 0; i < ordered_stripe_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_ordered_stripe_idsi;
      u_ordered_stripe_idsi.real = this->ordered_stripe_ids[i];
      *(outbuffer + offset + 0) = (u_ordered_stripe_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ordered_stripe_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ordered_stripe_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ordered_stripe_idsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ordered_stripe_idsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ordered_stripe_idsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ordered_stripe_idsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ordered_stripe_idsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ordered_stripe_ids[i]);
      }
      *(outbuffer + offset + 0) = (this->ordered_cell_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ordered_cell_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ordered_cell_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ordered_cell_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ordered_cell_ids_length);
      for( uint32_t i = 0; i < ordered_cell_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_ordered_cell_idsi;
      u_ordered_cell_idsi.real = this->ordered_cell_ids[i];
      *(outbuffer + offset + 0) = (u_ordered_cell_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ordered_cell_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ordered_cell_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ordered_cell_idsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_ordered_cell_idsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_ordered_cell_idsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_ordered_cell_idsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_ordered_cell_idsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->ordered_cell_ids[i]);
      }
      offset += this->traversal_graph.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_record_and_repeat;
      u_is_record_and_repeat.real = this->is_record_and_repeat;
      *(outbuffer + offset + 0) = (u_is_record_and_repeat.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_record_and_repeat);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->closest_initial_pose.deserialize(inbuffer + offset);
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
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->stripe_angle_rad));
      uint32_t inner_boundaries_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      inner_boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      inner_boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      inner_boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->inner_boundaries_length);
      if(inner_boundaries_lengthT > inner_boundaries_length)
        this->inner_boundaries = (greenzie_msgs::Boundary*)realloc(this->inner_boundaries, inner_boundaries_lengthT * sizeof(greenzie_msgs::Boundary));
      inner_boundaries_length = inner_boundaries_lengthT;
      for( uint32_t i = 0; i < inner_boundaries_length; i++){
      offset += this->st_inner_boundaries.deserialize(inbuffer + offset);
        memcpy( &(this->inner_boundaries[i]), &(this->st_inner_boundaries), sizeof(greenzie_msgs::Boundary));
      }
      uint32_t expanded_keep_out_zones_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      expanded_keep_out_zones_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      expanded_keep_out_zones_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      expanded_keep_out_zones_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->expanded_keep_out_zones_length);
      if(expanded_keep_out_zones_lengthT > expanded_keep_out_zones_length)
        this->expanded_keep_out_zones = (geometry_msgs::Polygon*)realloc(this->expanded_keep_out_zones, expanded_keep_out_zones_lengthT * sizeof(geometry_msgs::Polygon));
      expanded_keep_out_zones_length = expanded_keep_out_zones_lengthT;
      for( uint32_t i = 0; i < expanded_keep_out_zones_length; i++){
      offset += this->st_expanded_keep_out_zones.deserialize(inbuffer + offset);
        memcpy( &(this->expanded_keep_out_zones[i]), &(this->st_expanded_keep_out_zones), sizeof(geometry_msgs::Polygon));
      }
      offset += this->map_perimeter.deserialize(inbuffer + offset);
      uint32_t boundaries_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      boundaries_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->boundaries_length);
      if(boundaries_lengthT > boundaries_length)
        this->boundaries = (greenzie_msgs::Boundary*)realloc(this->boundaries, boundaries_lengthT * sizeof(greenzie_msgs::Boundary));
      boundaries_length = boundaries_lengthT;
      for( uint32_t i = 0; i < boundaries_length; i++){
      offset += this->st_boundaries.deserialize(inbuffer + offset);
        memcpy( &(this->boundaries[i]), &(this->st_boundaries), sizeof(greenzie_msgs::Boundary));
      }
      uint32_t stripes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stripes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stripes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stripes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stripes_length);
      if(stripes_lengthT > stripes_length)
        this->stripes = (greenzie_msgs::Stripe*)realloc(this->stripes, stripes_lengthT * sizeof(greenzie_msgs::Stripe));
      stripes_length = stripes_lengthT;
      for( uint32_t i = 0; i < stripes_length; i++){
      offset += this->st_stripes.deserialize(inbuffer + offset);
        memcpy( &(this->stripes[i]), &(this->st_stripes), sizeof(greenzie_msgs::Stripe));
      }
      uint32_t cells_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cells_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cells_length);
      if(cells_lengthT > cells_length)
        this->cells = (greenzie_msgs::Cell*)realloc(this->cells, cells_lengthT * sizeof(greenzie_msgs::Cell));
      cells_length = cells_lengthT;
      for( uint32_t i = 0; i < cells_length; i++){
      offset += this->st_cells.deserialize(inbuffer + offset);
        memcpy( &(this->cells[i]), &(this->st_cells), sizeof(greenzie_msgs::Cell));
      }
      uint32_t ordered_stripe_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ordered_stripe_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ordered_stripe_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ordered_stripe_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ordered_stripe_ids_length);
      if(ordered_stripe_ids_lengthT > ordered_stripe_ids_length)
        this->ordered_stripe_ids = (int64_t*)realloc(this->ordered_stripe_ids, ordered_stripe_ids_lengthT * sizeof(int64_t));
      ordered_stripe_ids_length = ordered_stripe_ids_lengthT;
      for( uint32_t i = 0; i < ordered_stripe_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_ordered_stripe_ids;
      u_st_ordered_stripe_ids.base = 0;
      u_st_ordered_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ordered_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ordered_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ordered_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_ordered_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_ordered_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_ordered_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_ordered_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_ordered_stripe_ids = u_st_ordered_stripe_ids.real;
      offset += sizeof(this->st_ordered_stripe_ids);
        memcpy( &(this->ordered_stripe_ids[i]), &(this->st_ordered_stripe_ids), sizeof(int64_t));
      }
      uint32_t ordered_cell_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ordered_cell_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ordered_cell_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ordered_cell_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ordered_cell_ids_length);
      if(ordered_cell_ids_lengthT > ordered_cell_ids_length)
        this->ordered_cell_ids = (int64_t*)realloc(this->ordered_cell_ids, ordered_cell_ids_lengthT * sizeof(int64_t));
      ordered_cell_ids_length = ordered_cell_ids_lengthT;
      for( uint32_t i = 0; i < ordered_cell_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_ordered_cell_ids;
      u_st_ordered_cell_ids.base = 0;
      u_st_ordered_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_ordered_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_ordered_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_ordered_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_ordered_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_ordered_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_ordered_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_ordered_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_ordered_cell_ids = u_st_ordered_cell_ids.real;
      offset += sizeof(this->st_ordered_cell_ids);
        memcpy( &(this->ordered_cell_ids[i]), &(this->st_ordered_cell_ids), sizeof(int64_t));
      }
      offset += this->traversal_graph.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_record_and_repeat;
      u_is_record_and_repeat.base = 0;
      u_is_record_and_repeat.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_record_and_repeat = u_is_record_and_repeat.real;
      offset += sizeof(this->is_record_and_repeat);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/StripingPlan"; };
    virtual const char * getMD5() override { return "5a7c161b0b5e6dc6323e7f8351e1d4d8"; };

  };

}
#endif
