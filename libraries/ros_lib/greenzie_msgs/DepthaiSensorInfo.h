#ifndef _ROS_greenzie_msgs_DepthaiSensorInfo_h
#define _ROS_greenzie_msgs_DepthaiSensorInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class DepthaiSensorInfo : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef bool _has_autofocus_type;
      _has_autofocus_type has_autofocus;
      typedef int32_t _height_type;
      _height_type height;
      typedef int32_t _width_type;
      _width_type width;
      typedef const char* _socket_type;
      _socket_type socket;
      typedef uint8_t _lens_position_type;
      _lens_position_type lens_position;

    DepthaiSensorInfo():
      name(""),
      has_autofocus(0),
      height(0),
      width(0),
      socket(""),
      lens_position(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_has_autofocus;
      u_has_autofocus.real = this->has_autofocus;
      *(outbuffer + offset + 0) = (u_has_autofocus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_autofocus);
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.real = this->width;
      *(outbuffer + offset + 0) = (u_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      uint32_t length_socket = strlen(this->socket);
      varToArr(outbuffer + offset, length_socket);
      offset += 4;
      memcpy(outbuffer + offset, this->socket, length_socket);
      offset += length_socket;
      *(outbuffer + offset + 0) = (this->lens_position >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lens_position);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_has_autofocus;
      u_has_autofocus.base = 0;
      u_has_autofocus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_autofocus = u_has_autofocus.real;
      offset += sizeof(this->has_autofocus);
      union {
        int32_t real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
      union {
        int32_t real;
        uint32_t base;
      } u_width;
      u_width.base = 0;
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->width = u_width.real;
      offset += sizeof(this->width);
      uint32_t length_socket;
      arrToVar(length_socket, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_socket; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_socket-1]=0;
      this->socket = (char *)(inbuffer + offset-1);
      offset += length_socket;
      this->lens_position =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->lens_position);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/DepthaiSensorInfo"; };
    virtual const char * getMD5() override { return "5fefbe22637a6e6f358f6603c0331dcb"; };

  };

}
#endif
