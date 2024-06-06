#ifndef _ROS_fixposition_driver_ros1_VRTK_h
#define _ROS_fixposition_driver_ros1_VRTK_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PoseWithCovariance.h"
#include "geometry_msgs/TwistWithCovariance.h"
#include "geometry_msgs/Vector3.h"

namespace fixposition_driver_ros1
{

  class VRTK : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _pose_frame_type;
      _pose_frame_type pose_frame;
      typedef const char* _kin_frame_type;
      _kin_frame_type kin_frame;
      typedef geometry_msgs::PoseWithCovariance _pose_type;
      _pose_type pose;
      typedef geometry_msgs::TwistWithCovariance _velocity_type;
      _velocity_type velocity;
      typedef geometry_msgs::Vector3 _acceleration_type;
      _acceleration_type acceleration;
      typedef int16_t _fusion_status_type;
      _fusion_status_type fusion_status;
      typedef int16_t _imu_bias_status_type;
      _imu_bias_status_type imu_bias_status;
      typedef int16_t _gnss1_status_type;
      _gnss1_status_type gnss1_status;
      typedef int16_t _gnss2_status_type;
      _gnss2_status_type gnss2_status;
      typedef int16_t _wheelspeed_status_type;
      _wheelspeed_status_type wheelspeed_status;
      typedef const char* _version_type;
      _version_type version;

    VRTK():
      header(),
      pose_frame(""),
      kin_frame(""),
      pose(),
      velocity(),
      acceleration(),
      fusion_status(0),
      imu_bias_status(0),
      gnss1_status(0),
      gnss2_status(0),
      wheelspeed_status(0),
      version("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_pose_frame = strlen(this->pose_frame);
      varToArr(outbuffer + offset, length_pose_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->pose_frame, length_pose_frame);
      offset += length_pose_frame;
      uint32_t length_kin_frame = strlen(this->kin_frame);
      varToArr(outbuffer + offset, length_kin_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->kin_frame, length_kin_frame);
      offset += length_kin_frame;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->velocity.serialize(outbuffer + offset);
      offset += this->acceleration.serialize(outbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_fusion_status;
      u_fusion_status.real = this->fusion_status;
      *(outbuffer + offset + 0) = (u_fusion_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fusion_status.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->fusion_status);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_bias_status;
      u_imu_bias_status.real = this->imu_bias_status;
      *(outbuffer + offset + 0) = (u_imu_bias_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_imu_bias_status.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->imu_bias_status);
      union {
        int16_t real;
        uint16_t base;
      } u_gnss1_status;
      u_gnss1_status.real = this->gnss1_status;
      *(outbuffer + offset + 0) = (u_gnss1_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gnss1_status.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gnss1_status);
      union {
        int16_t real;
        uint16_t base;
      } u_gnss2_status;
      u_gnss2_status.real = this->gnss2_status;
      *(outbuffer + offset + 0) = (u_gnss2_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gnss2_status.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gnss2_status);
      union {
        int16_t real;
        uint16_t base;
      } u_wheelspeed_status;
      u_wheelspeed_status.real = this->wheelspeed_status;
      *(outbuffer + offset + 0) = (u_wheelspeed_status.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wheelspeed_status.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->wheelspeed_status);
      uint32_t length_version = strlen(this->version);
      varToArr(outbuffer + offset, length_version);
      offset += 4;
      memcpy(outbuffer + offset, this->version, length_version);
      offset += length_version;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_pose_frame;
      arrToVar(length_pose_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_pose_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_pose_frame-1]=0;
      this->pose_frame = (char *)(inbuffer + offset-1);
      offset += length_pose_frame;
      uint32_t length_kin_frame;
      arrToVar(length_kin_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_kin_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_kin_frame-1]=0;
      this->kin_frame = (char *)(inbuffer + offset-1);
      offset += length_kin_frame;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->velocity.deserialize(inbuffer + offset);
      offset += this->acceleration.deserialize(inbuffer + offset);
      union {
        int16_t real;
        uint16_t base;
      } u_fusion_status;
      u_fusion_status.base = 0;
      u_fusion_status.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fusion_status.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->fusion_status = u_fusion_status.real;
      offset += sizeof(this->fusion_status);
      union {
        int16_t real;
        uint16_t base;
      } u_imu_bias_status;
      u_imu_bias_status.base = 0;
      u_imu_bias_status.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_imu_bias_status.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->imu_bias_status = u_imu_bias_status.real;
      offset += sizeof(this->imu_bias_status);
      union {
        int16_t real;
        uint16_t base;
      } u_gnss1_status;
      u_gnss1_status.base = 0;
      u_gnss1_status.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gnss1_status.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gnss1_status = u_gnss1_status.real;
      offset += sizeof(this->gnss1_status);
      union {
        int16_t real;
        uint16_t base;
      } u_gnss2_status;
      u_gnss2_status.base = 0;
      u_gnss2_status.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gnss2_status.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gnss2_status = u_gnss2_status.real;
      offset += sizeof(this->gnss2_status);
      union {
        int16_t real;
        uint16_t base;
      } u_wheelspeed_status;
      u_wheelspeed_status.base = 0;
      u_wheelspeed_status.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wheelspeed_status.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->wheelspeed_status = u_wheelspeed_status.real;
      offset += sizeof(this->wheelspeed_status);
      uint32_t length_version;
      arrToVar(length_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_version-1]=0;
      this->version = (char *)(inbuffer + offset-1);
      offset += length_version;
     return offset;
    }

    virtual const char * getType() override { return "fixposition_driver_ros1/VRTK"; };
    virtual const char * getMD5() override { return "22d6d51108a2fea4a6df4142dddad933"; };

  };

}
#endif
