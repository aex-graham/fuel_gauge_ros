#ifndef _ROS_SERVICE_GetDepthaiStatus_h
#define _ROS_SERVICE_GetDepthaiStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/DepthaiDeviceInfo.h"

namespace greenzie_msgs
{

static const char GETDEPTHAISTATUS[] = "greenzie_msgs/GetDepthaiStatus";

  class GetDepthaiStatusRequest : public ros::Msg
  {
    public:

    GetDepthaiStatusRequest()
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

    virtual const char * getType() override { return GETDEPTHAISTATUS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetDepthaiStatusResponse : public ros::Msg
  {
    public:
      uint32_t device_status_length;
      typedef greenzie_msgs::DepthaiDeviceInfo _device_status_type;
      _device_status_type st_device_status;
      _device_status_type * device_status;

    GetDepthaiStatusResponse():
      device_status_length(0), st_device_status(), device_status(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->device_status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->device_status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->device_status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->device_status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->device_status_length);
      for( uint32_t i = 0; i < device_status_length; i++){
      offset += this->device_status[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t device_status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      device_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      device_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      device_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->device_status_length);
      if(device_status_lengthT > device_status_length)
        this->device_status = (greenzie_msgs::DepthaiDeviceInfo*)realloc(this->device_status, device_status_lengthT * sizeof(greenzie_msgs::DepthaiDeviceInfo));
      device_status_length = device_status_lengthT;
      for( uint32_t i = 0; i < device_status_length; i++){
      offset += this->st_device_status.deserialize(inbuffer + offset);
        memcpy( &(this->device_status[i]), &(this->st_device_status), sizeof(greenzie_msgs::DepthaiDeviceInfo));
      }
     return offset;
    }

    virtual const char * getType() override { return GETDEPTHAISTATUS; };
    virtual const char * getMD5() override { return "e0d3166e1461f4b6a695ee810ae7619e"; };

  };

  class GetDepthaiStatus {
    public:
    typedef GetDepthaiStatusRequest Request;
    typedef GetDepthaiStatusResponse Response;
  };

}
#endif
