#ifndef _ROS_greenzie_msgs_USBDeviceArray_h
#define _ROS_greenzie_msgs_USBDeviceArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/USBDeviceCount.h"

namespace greenzie_msgs
{

  class USBDeviceArray : public ros::Msg
  {
    public:
      uint32_t devices_length;
      typedef greenzie_msgs::USBDeviceCount _devices_type;
      _devices_type st_devices;
      _devices_type * devices;
      typedef bool _all_devices_present_type;
      _all_devices_present_type all_devices_present;

    USBDeviceArray():
      devices_length(0), st_devices(), devices(nullptr),
      all_devices_present(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->devices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->devices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->devices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->devices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->devices_length);
      for( uint32_t i = 0; i < devices_length; i++){
      offset += this->devices[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_all_devices_present;
      u_all_devices_present.real = this->all_devices_present;
      *(outbuffer + offset + 0) = (u_all_devices_present.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->all_devices_present);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t devices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      devices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      devices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      devices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->devices_length);
      if(devices_lengthT > devices_length)
        this->devices = (greenzie_msgs::USBDeviceCount*)realloc(this->devices, devices_lengthT * sizeof(greenzie_msgs::USBDeviceCount));
      devices_length = devices_lengthT;
      for( uint32_t i = 0; i < devices_length; i++){
      offset += this->st_devices.deserialize(inbuffer + offset);
        memcpy( &(this->devices[i]), &(this->st_devices), sizeof(greenzie_msgs::USBDeviceCount));
      }
      union {
        bool real;
        uint8_t base;
      } u_all_devices_present;
      u_all_devices_present.base = 0;
      u_all_devices_present.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->all_devices_present = u_all_devices_present.real;
      offset += sizeof(this->all_devices_present);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/USBDeviceArray"; };
    virtual const char * getMD5() override { return "861347d388a5cf156900c0170cee86ca"; };

  };

}
#endif
