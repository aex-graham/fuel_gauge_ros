#ifndef _ROS_depthai_ros_msgs_HandLandmarkArray_h
#define _ROS_depthai_ros_msgs_HandLandmarkArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "depthai_ros_msgs/HandLandmark.h"

namespace depthai_ros_msgs
{

  class HandLandmarkArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t landmarks_length;
      typedef depthai_ros_msgs::HandLandmark _landmarks_type;
      _landmarks_type st_landmarks;
      _landmarks_type * landmarks;

    HandLandmarkArray():
      header(),
      landmarks_length(0), st_landmarks(), landmarks(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->landmarks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->landmarks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->landmarks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->landmarks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->landmarks_length);
      for( uint32_t i = 0; i < landmarks_length; i++){
      offset += this->landmarks[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t landmarks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      landmarks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      landmarks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      landmarks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->landmarks_length);
      if(landmarks_lengthT > landmarks_length)
        this->landmarks = (depthai_ros_msgs::HandLandmark*)realloc(this->landmarks, landmarks_lengthT * sizeof(depthai_ros_msgs::HandLandmark));
      landmarks_length = landmarks_lengthT;
      for( uint32_t i = 0; i < landmarks_length; i++){
      offset += this->st_landmarks.deserialize(inbuffer + offset);
        memcpy( &(this->landmarks[i]), &(this->st_landmarks), sizeof(depthai_ros_msgs::HandLandmark));
      }
     return offset;
    }

    virtual const char * getType() override { return "depthai_ros_msgs/HandLandmarkArray"; };
    virtual const char * getMD5() override { return "9215903cb0dba0f3a32440758d1e30e6"; };

  };

}
#endif
