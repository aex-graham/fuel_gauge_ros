#ifndef _ROS_depthai_ros_msgs_TrackedFeatures_h
#define _ROS_depthai_ros_msgs_TrackedFeatures_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "depthai_ros_msgs/TrackedFeature.h"

namespace depthai_ros_msgs
{

  class TrackedFeatures : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t features_length;
      typedef depthai_ros_msgs::TrackedFeature _features_type;
      _features_type st_features;
      _features_type * features;

    TrackedFeatures():
      header(),
      features_length(0), st_features(), features(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->features_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->features_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->features_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->features_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->features_length);
      for( uint32_t i = 0; i < features_length; i++){
      offset += this->features[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t features_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      features_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      features_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      features_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->features_length);
      if(features_lengthT > features_length)
        this->features = (depthai_ros_msgs::TrackedFeature*)realloc(this->features, features_lengthT * sizeof(depthai_ros_msgs::TrackedFeature));
      features_length = features_lengthT;
      for( uint32_t i = 0; i < features_length; i++){
      offset += this->st_features.deserialize(inbuffer + offset);
        memcpy( &(this->features[i]), &(this->st_features), sizeof(depthai_ros_msgs::TrackedFeature));
      }
     return offset;
    }

    virtual const char * getType() override { return "depthai_ros_msgs/TrackedFeatures"; };
    virtual const char * getMD5() override { return "b205be15f3779117f010ff7ec03c8749"; };

  };

}
#endif
