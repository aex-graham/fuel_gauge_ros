#ifndef _ROS_greenzie_msgs_ClusterInfo_h
#define _ROS_greenzie_msgs_ClusterInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class ClusterInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t point_counts_length;
      typedef int32_t _point_counts_type;
      _point_counts_type st_point_counts;
      _point_counts_type * point_counts;
      uint32_t closest_point_distances_length;
      typedef float _closest_point_distances_type;
      _closest_point_distances_type st_closest_point_distances;
      _closest_point_distances_type * closest_point_distances;

    ClusterInfo():
      header(),
      point_counts_length(0), st_point_counts(), point_counts(nullptr),
      closest_point_distances_length(0), st_closest_point_distances(), closest_point_distances(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->point_counts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_counts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_counts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_counts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_counts_length);
      for( uint32_t i = 0; i < point_counts_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_point_countsi;
      u_point_countsi.real = this->point_counts[i];
      *(outbuffer + offset + 0) = (u_point_countsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_point_countsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_point_countsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_point_countsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_counts[i]);
      }
      *(outbuffer + offset + 0) = (this->closest_point_distances_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->closest_point_distances_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->closest_point_distances_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->closest_point_distances_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->closest_point_distances_length);
      for( uint32_t i = 0; i < closest_point_distances_length; i++){
      union {
        float real;
        uint32_t base;
      } u_closest_point_distancesi;
      u_closest_point_distancesi.real = this->closest_point_distances[i];
      *(outbuffer + offset + 0) = (u_closest_point_distancesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_closest_point_distancesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_closest_point_distancesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_closest_point_distancesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->closest_point_distances[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t point_counts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_counts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_counts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_counts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_counts_length);
      if(point_counts_lengthT > point_counts_length)
        this->point_counts = (int32_t*)realloc(this->point_counts, point_counts_lengthT * sizeof(int32_t));
      point_counts_length = point_counts_lengthT;
      for( uint32_t i = 0; i < point_counts_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_point_counts;
      u_st_point_counts.base = 0;
      u_st_point_counts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_point_counts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_point_counts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_point_counts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_point_counts = u_st_point_counts.real;
      offset += sizeof(this->st_point_counts);
        memcpy( &(this->point_counts[i]), &(this->st_point_counts), sizeof(int32_t));
      }
      uint32_t closest_point_distances_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      closest_point_distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      closest_point_distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      closest_point_distances_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->closest_point_distances_length);
      if(closest_point_distances_lengthT > closest_point_distances_length)
        this->closest_point_distances = (float*)realloc(this->closest_point_distances, closest_point_distances_lengthT * sizeof(float));
      closest_point_distances_length = closest_point_distances_lengthT;
      for( uint32_t i = 0; i < closest_point_distances_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_closest_point_distances;
      u_st_closest_point_distances.base = 0;
      u_st_closest_point_distances.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_closest_point_distances.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_closest_point_distances.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_closest_point_distances.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_closest_point_distances = u_st_closest_point_distances.real;
      offset += sizeof(this->st_closest_point_distances);
        memcpy( &(this->closest_point_distances[i]), &(this->st_closest_point_distances), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/ClusterInfo"; };
    virtual const char * getMD5() override { return "d329c29bccfb0358ae3bc26b3c7f8caa"; };

  };

}
#endif
