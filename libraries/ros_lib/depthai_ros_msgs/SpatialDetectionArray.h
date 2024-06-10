#ifndef _ROS_depthai_ros_msgs_SpatialDetectionArray_h
#define _ROS_depthai_ros_msgs_SpatialDetectionArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "depthai_ros_msgs/SpatialDetection.h"

namespace depthai_ros_msgs
{

  class SpatialDetectionArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t detections_length;
      typedef depthai_ros_msgs::SpatialDetection _detections_type;
      _detections_type st_detections;
      _detections_type * detections;

    SpatialDetectionArray():
      header(),
      detections_length(0), st_detections(), detections(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->detections_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->detections_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->detections_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->detections_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detections_length);
      for( uint32_t i = 0; i < detections_length; i++){
      offset += this->detections[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t detections_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      detections_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->detections_length);
      if(detections_lengthT > detections_length)
        this->detections = (depthai_ros_msgs::SpatialDetection*)realloc(this->detections, detections_lengthT * sizeof(depthai_ros_msgs::SpatialDetection));
      detections_length = detections_lengthT;
      for( uint32_t i = 0; i < detections_length; i++){
      offset += this->st_detections.deserialize(inbuffer + offset);
        memcpy( &(this->detections[i]), &(this->st_detections), sizeof(depthai_ros_msgs::SpatialDetection));
      }
     return offset;
    }

    virtual const char * getType() override { return "depthai_ros_msgs/SpatialDetectionArray"; };
    virtual const char * getMD5() override { return "f3caf8c6374b91f3a4b93f9610044116"; };

  };

}
#endif
