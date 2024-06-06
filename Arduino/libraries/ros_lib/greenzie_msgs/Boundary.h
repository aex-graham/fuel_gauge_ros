#ifndef _ROS_greenzie_msgs_Boundary_h
#define _ROS_greenzie_msgs_Boundary_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "greenzie_msgs/PointList.h"

namespace greenzie_msgs
{

  class Boundary : public ros::Msg
  {
    public:
      typedef int64_t _id_type;
      _id_type id;
      uint32_t exterior_points_length;
      typedef geometry_msgs::Point _exterior_points_type;
      _exterior_points_type st_exterior_points;
      _exterior_points_type * exterior_points;
      uint32_t interior_polygons_length;
      typedef greenzie_msgs::PointList _interior_polygons_type;
      _interior_polygons_type st_interior_polygons;
      _interior_polygons_type * interior_polygons;
      uint32_t cell_ids_length;
      typedef int64_t _cell_ids_type;
      _cell_ids_type st_cell_ids;
      _cell_ids_type * cell_ids;

    Boundary():
      id(0),
      exterior_points_length(0), st_exterior_points(), exterior_points(nullptr),
      interior_polygons_length(0), st_interior_polygons(), interior_polygons(nullptr),
      cell_ids_length(0), st_cell_ids(), cell_ids(nullptr)
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
      *(outbuffer + offset + 0) = (this->exterior_points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->exterior_points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->exterior_points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->exterior_points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->exterior_points_length);
      for( uint32_t i = 0; i < exterior_points_length; i++){
      offset += this->exterior_points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->interior_polygons_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->interior_polygons_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->interior_polygons_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->interior_polygons_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->interior_polygons_length);
      for( uint32_t i = 0; i < interior_polygons_length; i++){
      offset += this->interior_polygons[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->cell_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cell_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cell_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cell_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cell_ids_length);
      for( uint32_t i = 0; i < cell_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_cell_idsi;
      u_cell_idsi.real = this->cell_ids[i];
      *(outbuffer + offset + 0) = (u_cell_idsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cell_idsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cell_idsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cell_idsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_cell_idsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_cell_idsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_cell_idsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_cell_idsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->cell_ids[i]);
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
      uint32_t exterior_points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      exterior_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      exterior_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      exterior_points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->exterior_points_length);
      if(exterior_points_lengthT > exterior_points_length)
        this->exterior_points = (geometry_msgs::Point*)realloc(this->exterior_points, exterior_points_lengthT * sizeof(geometry_msgs::Point));
      exterior_points_length = exterior_points_lengthT;
      for( uint32_t i = 0; i < exterior_points_length; i++){
      offset += this->st_exterior_points.deserialize(inbuffer + offset);
        memcpy( &(this->exterior_points[i]), &(this->st_exterior_points), sizeof(geometry_msgs::Point));
      }
      uint32_t interior_polygons_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      interior_polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      interior_polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      interior_polygons_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->interior_polygons_length);
      if(interior_polygons_lengthT > interior_polygons_length)
        this->interior_polygons = (greenzie_msgs::PointList*)realloc(this->interior_polygons, interior_polygons_lengthT * sizeof(greenzie_msgs::PointList));
      interior_polygons_length = interior_polygons_lengthT;
      for( uint32_t i = 0; i < interior_polygons_length; i++){
      offset += this->st_interior_polygons.deserialize(inbuffer + offset);
        memcpy( &(this->interior_polygons[i]), &(this->st_interior_polygons), sizeof(greenzie_msgs::PointList));
      }
      uint32_t cell_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cell_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cell_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cell_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cell_ids_length);
      if(cell_ids_lengthT > cell_ids_length)
        this->cell_ids = (int64_t*)realloc(this->cell_ids, cell_ids_lengthT * sizeof(int64_t));
      cell_ids_length = cell_ids_lengthT;
      for( uint32_t i = 0; i < cell_ids_length; i++){
      union {
        int64_t real;
        uint64_t base;
      } u_st_cell_ids;
      u_st_cell_ids.base = 0;
      u_st_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_cell_ids.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_cell_ids = u_st_cell_ids.real;
      offset += sizeof(this->st_cell_ids);
        memcpy( &(this->cell_ids[i]), &(this->st_cell_ids), sizeof(int64_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/Boundary"; };
    virtual const char * getMD5() override { return "226a8fb1547ca92a153613c8126e05de"; };

  };

}
#endif
