#ifndef _ROS_beagle_msgs_BeagleBatterySOC_h
#define _ROS_beagle_msgs_BeagleBatterySOC_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatterySOC : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint16_t _soc_type;
      _soc_type soc;

    BeagleBatterySOC():
      header(),
      soc(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->soc >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->soc >> (8 * 1)) & 0xFF;
      offset += sizeof(this->soc);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->soc =  ((uint16_t) (*(inbuffer + offset)));
      this->soc |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->soc);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatterySOC"; };
    virtual const char * getMD5() override { return "4cae96aae56075815bef6b3463823c40"; };

  };

}
#endif
