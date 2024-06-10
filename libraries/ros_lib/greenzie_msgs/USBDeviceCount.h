#ifndef _ROS_greenzie_msgs_USBDeviceCount_h
#define _ROS_greenzie_msgs_USBDeviceCount_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class USBDeviceCount : public ros::Msg
  {
    public:
      typedef const char* _device_name_type;
      _device_name_type device_name;
      typedef bool _device_connected_type;
      _device_connected_type device_connected;
      typedef uint32_t _count_found_type;
      _count_found_type count_found;
      typedef uint32_t _count_expected_type;
      _count_expected_type count_expected;

    USBDeviceCount():
      device_name(""),
      device_connected(0),
      count_found(0),
      count_expected(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_device_name = strlen(this->device_name);
      varToArr(outbuffer + offset, length_device_name);
      offset += 4;
      memcpy(outbuffer + offset, this->device_name, length_device_name);
      offset += length_device_name;
      union {
        bool real;
        uint8_t base;
      } u_device_connected;
      u_device_connected.real = this->device_connected;
      *(outbuffer + offset + 0) = (u_device_connected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->device_connected);
      *(outbuffer + offset + 0) = (this->count_found >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->count_found >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->count_found >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->count_found >> (8 * 3)) & 0xFF;
      offset += sizeof(this->count_found);
      *(outbuffer + offset + 0) = (this->count_expected >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->count_expected >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->count_expected >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->count_expected >> (8 * 3)) & 0xFF;
      offset += sizeof(this->count_expected);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_device_name;
      arrToVar(length_device_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_device_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_device_name-1]=0;
      this->device_name = (char *)(inbuffer + offset-1);
      offset += length_device_name;
      union {
        bool real;
        uint8_t base;
      } u_device_connected;
      u_device_connected.base = 0;
      u_device_connected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->device_connected = u_device_connected.real;
      offset += sizeof(this->device_connected);
      this->count_found =  ((uint32_t) (*(inbuffer + offset)));
      this->count_found |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->count_found |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->count_found |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->count_found);
      this->count_expected =  ((uint32_t) (*(inbuffer + offset)));
      this->count_expected |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->count_expected |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->count_expected |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->count_expected);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/USBDeviceCount"; };
    virtual const char * getMD5() override { return "f8e73eaab2aadafbf65f71492aa2fcb4"; };

  };

}
#endif
