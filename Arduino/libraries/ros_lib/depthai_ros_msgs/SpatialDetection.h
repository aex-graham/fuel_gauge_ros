#ifndef _ROS_depthai_ros_msgs_SpatialDetection_h
#define _ROS_depthai_ros_msgs_SpatialDetection_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "vision_msgs/ObjectHypothesis.h"
#include "vision_msgs/BoundingBox2D.h"
#include "geometry_msgs/Point.h"

namespace depthai_ros_msgs
{

  class SpatialDetection : public ros::Msg
  {
    public:
      uint32_t results_length;
      typedef vision_msgs::ObjectHypothesis _results_type;
      _results_type st_results;
      _results_type * results;
      typedef vision_msgs::BoundingBox2D _bbox_type;
      _bbox_type bbox;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef bool _is_tracking_type;
      _is_tracking_type is_tracking;
      typedef const char* _tracking_id_type;
      _tracking_id_type tracking_id;

    SpatialDetection():
      results_length(0), st_results(), results(nullptr),
      bbox(),
      position(),
      is_tracking(0),
      tracking_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->results_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->results_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->results_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->results_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->results_length);
      for( uint32_t i = 0; i < results_length; i++){
      offset += this->results[i].serialize(outbuffer + offset);
      }
      offset += this->bbox.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_tracking;
      u_is_tracking.real = this->is_tracking;
      *(outbuffer + offset + 0) = (u_is_tracking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_tracking);
      uint32_t length_tracking_id = strlen(this->tracking_id);
      varToArr(outbuffer + offset, length_tracking_id);
      offset += 4;
      memcpy(outbuffer + offset, this->tracking_id, length_tracking_id);
      offset += length_tracking_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t results_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      results_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      results_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      results_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->results_length);
      if(results_lengthT > results_length)
        this->results = (vision_msgs::ObjectHypothesis*)realloc(this->results, results_lengthT * sizeof(vision_msgs::ObjectHypothesis));
      results_length = results_lengthT;
      for( uint32_t i = 0; i < results_length; i++){
      offset += this->st_results.deserialize(inbuffer + offset);
        memcpy( &(this->results[i]), &(this->st_results), sizeof(vision_msgs::ObjectHypothesis));
      }
      offset += this->bbox.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_tracking;
      u_is_tracking.base = 0;
      u_is_tracking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_tracking = u_is_tracking.real;
      offset += sizeof(this->is_tracking);
      uint32_t length_tracking_id;
      arrToVar(length_tracking_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tracking_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tracking_id-1]=0;
      this->tracking_id = (char *)(inbuffer + offset-1);
      offset += length_tracking_id;
     return offset;
    }

    virtual const char * getType() override { return "depthai_ros_msgs/SpatialDetection"; };
    virtual const char * getMD5() override { return "503c7980b555f0fd79e92d14cb9ac446"; };

  };

}
#endif
