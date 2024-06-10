#ifndef _ROS_fixposition_driver_ros1_WheelSensor_h
#define _ROS_fixposition_driver_ros1_WheelSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace fixposition_driver_ros1
{

  class WheelSensor : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _location_type;
      _location_type location;
      typedef int32_t _vx_type;
      _vx_type vx;
      typedef int32_t _vy_type;
      _vy_type vy;
      typedef int32_t _vz_type;
      _vz_type vz;
      typedef bool _vx_valid_type;
      _vx_valid_type vx_valid;
      typedef bool _vy_valid_type;
      _vy_valid_type vy_valid;
      typedef bool _vz_valid_type;
      _vz_valid_type vz_valid;

    WheelSensor():
      header(),
      location(""),
      vx(0),
      vy(0),
      vz(0),
      vx_valid(0),
      vy_valid(0),
      vz_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_location = strlen(this->location);
      varToArr(outbuffer + offset, length_location);
      offset += 4;
      memcpy(outbuffer + offset, this->location, length_location);
      offset += length_location;
      union {
        int32_t real;
        uint32_t base;
      } u_vx;
      u_vx.real = this->vx;
      *(outbuffer + offset + 0) = (u_vx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vx);
      union {
        int32_t real;
        uint32_t base;
      } u_vy;
      u_vy.real = this->vy;
      *(outbuffer + offset + 0) = (u_vy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vy);
      union {
        int32_t real;
        uint32_t base;
      } u_vz;
      u_vz.real = this->vz;
      *(outbuffer + offset + 0) = (u_vz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vz);
      union {
        bool real;
        uint8_t base;
      } u_vx_valid;
      u_vx_valid.real = this->vx_valid;
      *(outbuffer + offset + 0) = (u_vx_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vx_valid);
      union {
        bool real;
        uint8_t base;
      } u_vy_valid;
      u_vy_valid.real = this->vy_valid;
      *(outbuffer + offset + 0) = (u_vy_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vy_valid);
      union {
        bool real;
        uint8_t base;
      } u_vz_valid;
      u_vz_valid.real = this->vz_valid;
      *(outbuffer + offset + 0) = (u_vz_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vz_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_location;
      arrToVar(length_location, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_location; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_location-1]=0;
      this->location = (char *)(inbuffer + offset-1);
      offset += length_location;
      union {
        int32_t real;
        uint32_t base;
      } u_vx;
      u_vx.base = 0;
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vx = u_vx.real;
      offset += sizeof(this->vx);
      union {
        int32_t real;
        uint32_t base;
      } u_vy;
      u_vy.base = 0;
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vy = u_vy.real;
      offset += sizeof(this->vy);
      union {
        int32_t real;
        uint32_t base;
      } u_vz;
      u_vz.base = 0;
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vz = u_vz.real;
      offset += sizeof(this->vz);
      union {
        bool real;
        uint8_t base;
      } u_vx_valid;
      u_vx_valid.base = 0;
      u_vx_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vx_valid = u_vx_valid.real;
      offset += sizeof(this->vx_valid);
      union {
        bool real;
        uint8_t base;
      } u_vy_valid;
      u_vy_valid.base = 0;
      u_vy_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vy_valid = u_vy_valid.real;
      offset += sizeof(this->vy_valid);
      union {
        bool real;
        uint8_t base;
      } u_vz_valid;
      u_vz_valid.base = 0;
      u_vz_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vz_valid = u_vz_valid.real;
      offset += sizeof(this->vz_valid);
     return offset;
    }

    virtual const char * getType() override { return "fixposition_driver_ros1/WheelSensor"; };
    virtual const char * getMD5() override { return "80080356d0f1e51e2dbb0fca7fd5dc02"; };

  };

}
#endif
