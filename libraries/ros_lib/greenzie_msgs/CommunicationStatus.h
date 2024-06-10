#ifndef _ROS_greenzie_msgs_CommunicationStatus_h
#define _ROS_greenzie_msgs_CommunicationStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class CommunicationStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _vpn_connected_type;
      _vpn_connected_type vpn_connected;

    CommunicationStatus():
      header(),
      vpn_connected(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_vpn_connected;
      u_vpn_connected.real = this->vpn_connected;
      *(outbuffer + offset + 0) = (u_vpn_connected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vpn_connected);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_vpn_connected;
      u_vpn_connected.base = 0;
      u_vpn_connected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vpn_connected = u_vpn_connected.real;
      offset += sizeof(this->vpn_connected);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/CommunicationStatus"; };
    virtual const char * getMD5() override { return "5dba3d5d00e3b5674f461047024e6410"; };

  };

}
#endif
