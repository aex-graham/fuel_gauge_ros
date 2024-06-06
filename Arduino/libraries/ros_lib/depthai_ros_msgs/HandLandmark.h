#ifndef _ROS_depthai_ros_msgs_HandLandmark_h
#define _ROS_depthai_ros_msgs_HandLandmark_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Point.h"

namespace depthai_ros_msgs
{

  class HandLandmark : public ros::Msg
  {
    public:
      typedef const char* _label_type;
      _label_type label;
      typedef float _lm_score_type;
      _lm_score_type lm_score;
      uint32_t landmark_length;
      typedef geometry_msgs::Pose2D _landmark_type;
      _landmark_type st_landmark;
      _landmark_type * landmark;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef bool _is_spatial_type;
      _is_spatial_type is_spatial;

    HandLandmark():
      label(""),
      lm_score(0),
      landmark_length(0), st_landmark(), landmark(nullptr),
      position(),
      is_spatial(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_label = strlen(this->label);
      varToArr(outbuffer + offset, length_label);
      offset += 4;
      memcpy(outbuffer + offset, this->label, length_label);
      offset += length_label;
      union {
        float real;
        uint32_t base;
      } u_lm_score;
      u_lm_score.real = this->lm_score;
      *(outbuffer + offset + 0) = (u_lm_score.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lm_score.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lm_score.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lm_score.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lm_score);
      *(outbuffer + offset + 0) = (this->landmark_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->landmark_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->landmark_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->landmark_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->landmark_length);
      for( uint32_t i = 0; i < landmark_length; i++){
      offset += this->landmark[i].serialize(outbuffer + offset);
      }
      offset += this->position.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_spatial;
      u_is_spatial.real = this->is_spatial;
      *(outbuffer + offset + 0) = (u_is_spatial.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_spatial);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_label;
      arrToVar(length_label, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_label; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_label-1]=0;
      this->label = (char *)(inbuffer + offset-1);
      offset += length_label;
      union {
        float real;
        uint32_t base;
      } u_lm_score;
      u_lm_score.base = 0;
      u_lm_score.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lm_score.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lm_score.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lm_score.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lm_score = u_lm_score.real;
      offset += sizeof(this->lm_score);
      uint32_t landmark_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      landmark_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      landmark_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      landmark_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->landmark_length);
      if(landmark_lengthT > landmark_length)
        this->landmark = (geometry_msgs::Pose2D*)realloc(this->landmark, landmark_lengthT * sizeof(geometry_msgs::Pose2D));
      landmark_length = landmark_lengthT;
      for( uint32_t i = 0; i < landmark_length; i++){
      offset += this->st_landmark.deserialize(inbuffer + offset);
        memcpy( &(this->landmark[i]), &(this->st_landmark), sizeof(geometry_msgs::Pose2D));
      }
      offset += this->position.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_is_spatial;
      u_is_spatial.base = 0;
      u_is_spatial.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_spatial = u_is_spatial.real;
      offset += sizeof(this->is_spatial);
     return offset;
    }

    virtual const char * getType() override { return "depthai_ros_msgs/HandLandmark"; };
    virtual const char * getMD5() override { return "e126f09ad65617304665e31f1a5736de"; };

  };

}
#endif
