#ifndef _ROS_greenzie_msgs_KeepOutZone_h
#define _ROS_greenzie_msgs_KeepOutZone_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace greenzie_msgs
{

  class KeepOutZone : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef uint8_t _type_type;
      _type_type type;
      typedef float _radius_m_type;
      _radius_m_type radius_m;
      typedef float _buffer_dist_m_type;
      _buffer_dist_m_type buffer_dist_m;
      uint32_t points_length;
      typedef geometry_msgs::Point _points_type;
      _points_type st_points;
      _points_type * points;
      typedef float _error_xy_m_type;
      _error_xy_m_type error_xy_m;
      typedef float _error_z_m_type;
      _error_z_m_type error_z_m;
      typedef uint8_t _behavior_type;
      _behavior_type behavior;
      enum { TYPE_UNKNOWN = 0 };
      enum { TYPE_SINGLE_POINT = 1 };
      enum { TYPE_MULTI_POINT = 2 };
      enum { BEHAVIOR_GO_AROUND = 0 };
      enum { BEHAVIOR_STOP_AND_TURN = 1 };

    KeepOutZone():
      id(""),
      type(0),
      radius_m(0),
      buffer_dist_m(0),
      points_length(0), st_points(), points(nullptr),
      error_xy_m(0),
      error_z_m(0),
      behavior(0)
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
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      union {
        float real;
        uint32_t base;
      } u_radius_m;
      u_radius_m.real = this->radius_m;
      *(outbuffer + offset + 0) = (u_radius_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radius_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_radius_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_radius_m.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->radius_m);
      union {
        float real;
        uint32_t base;
      } u_buffer_dist_m;
      u_buffer_dist_m.real = this->buffer_dist_m;
      *(outbuffer + offset + 0) = (u_buffer_dist_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_buffer_dist_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_buffer_dist_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_buffer_dist_m.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->buffer_dist_m);
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      union {
        float real;
        uint32_t base;
      } u_error_xy_m;
      u_error_xy_m.real = this->error_xy_m;
      *(outbuffer + offset + 0) = (u_error_xy_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_xy_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_xy_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_xy_m.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_xy_m);
      union {
        float real;
        uint32_t base;
      } u_error_z_m;
      u_error_z_m.real = this->error_z_m;
      *(outbuffer + offset + 0) = (u_error_z_m.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_error_z_m.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_error_z_m.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_error_z_m.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->error_z_m);
      *(outbuffer + offset + 0) = (this->behavior >> (8 * 0)) & 0xFF;
      offset += sizeof(this->behavior);
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
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      union {
        float real;
        uint32_t base;
      } u_radius_m;
      u_radius_m.base = 0;
      u_radius_m.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radius_m.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_radius_m.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_radius_m.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->radius_m = u_radius_m.real;
      offset += sizeof(this->radius_m);
      union {
        float real;
        uint32_t base;
      } u_buffer_dist_m;
      u_buffer_dist_m.base = 0;
      u_buffer_dist_m.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_buffer_dist_m.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_buffer_dist_m.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_buffer_dist_m.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->buffer_dist_m = u_buffer_dist_m.real;
      offset += sizeof(this->buffer_dist_m);
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
      union {
        float real;
        uint32_t base;
      } u_error_xy_m;
      u_error_xy_m.base = 0;
      u_error_xy_m.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_xy_m.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_xy_m.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_xy_m.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error_xy_m = u_error_xy_m.real;
      offset += sizeof(this->error_xy_m);
      union {
        float real;
        uint32_t base;
      } u_error_z_m;
      u_error_z_m.base = 0;
      u_error_z_m.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_error_z_m.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_error_z_m.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_error_z_m.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->error_z_m = u_error_z_m.real;
      offset += sizeof(this->error_z_m);
      this->behavior =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->behavior);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/KeepOutZone"; };
    virtual const char * getMD5() override { return "7c16499946be21f8490c5ed6abb72f98"; };

  };

}
#endif
