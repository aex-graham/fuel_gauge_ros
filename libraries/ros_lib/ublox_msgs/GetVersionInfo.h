#ifndef _ROS_SERVICE_GetVersionInfo_h
#define _ROS_SERVICE_GetVersionInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ublox_msgs
{

static const char GETVERSIONINFO[] = "ublox_msgs/GetVersionInfo";

  class GetVersionInfoRequest : public ros::Msg
  {
    public:

    GetVersionInfoRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETVERSIONINFO; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetVersionInfoResponse : public ros::Msg
  {
    public:
      typedef const char* _hardware_type;
      _hardware_type hardware;
      typedef const char* _software_type;
      _software_type software;
      typedef const char* _firmware_type;
      _firmware_type firmware;
      typedef const char* _protocol_type;
      _protocol_type protocol;
      typedef const char* _device_model_type;
      _device_model_type device_model;

    GetVersionInfoResponse():
      hardware(""),
      software(""),
      firmware(""),
      protocol(""),
      device_model("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_hardware = strlen(this->hardware);
      varToArr(outbuffer + offset, length_hardware);
      offset += 4;
      memcpy(outbuffer + offset, this->hardware, length_hardware);
      offset += length_hardware;
      uint32_t length_software = strlen(this->software);
      varToArr(outbuffer + offset, length_software);
      offset += 4;
      memcpy(outbuffer + offset, this->software, length_software);
      offset += length_software;
      uint32_t length_firmware = strlen(this->firmware);
      varToArr(outbuffer + offset, length_firmware);
      offset += 4;
      memcpy(outbuffer + offset, this->firmware, length_firmware);
      offset += length_firmware;
      uint32_t length_protocol = strlen(this->protocol);
      varToArr(outbuffer + offset, length_protocol);
      offset += 4;
      memcpy(outbuffer + offset, this->protocol, length_protocol);
      offset += length_protocol;
      uint32_t length_device_model = strlen(this->device_model);
      varToArr(outbuffer + offset, length_device_model);
      offset += 4;
      memcpy(outbuffer + offset, this->device_model, length_device_model);
      offset += length_device_model;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_hardware;
      arrToVar(length_hardware, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hardware; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hardware-1]=0;
      this->hardware = (char *)(inbuffer + offset-1);
      offset += length_hardware;
      uint32_t length_software;
      arrToVar(length_software, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_software; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_software-1]=0;
      this->software = (char *)(inbuffer + offset-1);
      offset += length_software;
      uint32_t length_firmware;
      arrToVar(length_firmware, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_firmware; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_firmware-1]=0;
      this->firmware = (char *)(inbuffer + offset-1);
      offset += length_firmware;
      uint32_t length_protocol;
      arrToVar(length_protocol, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_protocol; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_protocol-1]=0;
      this->protocol = (char *)(inbuffer + offset-1);
      offset += length_protocol;
      uint32_t length_device_model;
      arrToVar(length_device_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_device_model; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_device_model-1]=0;
      this->device_model = (char *)(inbuffer + offset-1);
      offset += length_device_model;
     return offset;
    }

    virtual const char * getType() override { return GETVERSIONINFO; };
    virtual const char * getMD5() override { return "eb2abbadc882d0f577325496fc555e98"; };

  };

  class GetVersionInfo {
    public:
    typedef GetVersionInfoRequest Request;
    typedef GetVersionInfoResponse Response;
  };

}
#endif
