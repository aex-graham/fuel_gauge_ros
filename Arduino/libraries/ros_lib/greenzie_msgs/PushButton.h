#ifndef _ROS_greenzie_msgs_PushButton_h
#define _ROS_greenzie_msgs_PushButton_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class PushButton : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _map_button_type;
      _map_button_type map_button;
      typedef uint8_t _cancel_button_type;
      _cancel_button_type cancel_button;

    PushButton():
      header(),
      map_button(0),
      cancel_button(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->map_button >> (8 * 0)) & 0xFF;
      offset += sizeof(this->map_button);
      *(outbuffer + offset + 0) = (this->cancel_button >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cancel_button);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->map_button =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->map_button);
      this->cancel_button =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cancel_button);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/PushButton"; };
    virtual const char * getMD5() override { return "0c8aa92dcfe7e5afe22fc16b3f0333ea"; };

  };

}
#endif
