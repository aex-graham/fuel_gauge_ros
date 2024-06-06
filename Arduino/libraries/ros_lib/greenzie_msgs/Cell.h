#ifndef _ROS_greenzie_msgs_Cell_h
#define _ROS_greenzie_msgs_Cell_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace greenzie_msgs
{

  class Cell : public ros::Msg
  {
    public:
      typedef int64_t _id_type;
      _id_type id;
      uint32_t points_length;
      typedef geometry_msgs::Point _points_type;
      _points_type st_points;
      _points_type * points;
      uint32_t neighbor_cell_ids_length;
      typedef int64_t _neighbor_cell_ids_type;
      _neighbor_cell_ids_type st_neighbor_cell_ids;
      _neighbor_cell_ids_type * neighbor_cell_ids;
      uint32_t stripe_ids_length;
      typedef int64_t _stripe_ids_type;
      _stripe_ids_type st_stripe_ids;
      _stripe_ids_type * stripe_ids;

    Cell():
      id(0),
      points_length(0), st_points(), points(nullptr),
      neighbor_cell_ids_length(0), st_neighbor_cell_ids(), neighbor_cell_ids(nullptr),
      stripe_ids_length(0), st_stripe_ids(), stripe_ids(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->neighbor_cell_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->neighbor_cell_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->neighbor_cell_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->neighbor_cell_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->neighbor_cell_ids_length);
      for( uint32_t i = 0; i < neighbor_cell_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_neighbor_cell_idsi;
      u_neighbor_cell_idsi.real = this->neighbor_cell_ids[i];
      *(outbuffer + offset + 0) = (u_neighbor_cell_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_neighbor_cell_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_neighbor_cell_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_neighbor_cell_idsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_neighbor_cell_idsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_neighbor_cell_idsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_neighbor_cell_idsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_neighbor_cell_idsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->neighbor_cell_ids[i]);
      }
      *(outbuffer + offset + 0) = (this->stripe_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stripe_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stripe_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stripe_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stripe_ids_length);
      for( uint32_t i = 0; i < stripe_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_stripe_idsi;
      u_stripe_idsi.real = this->stripe_ids[i];
      *(outbuffer + offset + 0) = (u_stripe_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_stripe_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_stripe_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_stripe_idsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_stripe_idsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_stripe_idsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_stripe_idsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_stripe_idsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->stripe_ids[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->id = u_id.real;
      offset += sizeof(this->id);
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (geometry_msgs::Point*)realloc(this->points, points_lengthT * sizeof(geometry_msgs::Point));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(geometry_msgs::Point));
      }
      uint32_t neighbor_cell_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      neighbor_cell_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      neighbor_cell_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      neighbor_cell_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->neighbor_cell_ids_length);
      if(neighbor_cell_ids_lengthT > neighbor_cell_ids_length)
        this->neighbor_cell_ids = (int64_t*)realloc(this->neighbor_cell_ids, neighbor_cell_ids_lengthT * sizeof(int64_t));
      neighbor_cell_ids_length = neighbor_cell_ids_lengthT;
      for( uint32_t i = 0; i < neighbor_cell_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_neighbor_cell_ids;
      u_st_neighbor_cell_ids.base = 0;
      u_st_neighbor_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_neighbor_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_neighbor_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_neighbor_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_neighbor_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_neighbor_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_neighbor_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_neighbor_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_neighbor_cell_ids = u_st_neighbor_cell_ids.real;
      offset += sizeof(this->st_neighbor_cell_ids);
        memcpy( &(this->neighbor_cell_ids[i]), &(this->st_neighbor_cell_ids), sizeof(int64_t));
      }
      uint32_t stripe_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stripe_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stripe_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stripe_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stripe_ids_length);
      if(stripe_ids_lengthT > stripe_ids_length)
        this->stripe_ids = (int64_t*)realloc(this->stripe_ids, stripe_ids_lengthT * sizeof(int64_t));
      stripe_ids_length = stripe_ids_lengthT;
      for( uint32_t i = 0; i < stripe_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_stripe_ids;
      u_st_stripe_ids.base = 0;
      u_st_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_stripe_ids.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_stripe_ids = u_st_stripe_ids.real;
      offset += sizeof(this->st_stripe_ids);
        memcpy( &(this->stripe_ids[i]), &(this->st_stripe_ids), sizeof(int64_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/Cell"; };
    virtual const char * getMD5() override { return "e11c488bcdcd467f1f522a815a064427"; };

  };

}
#endif
