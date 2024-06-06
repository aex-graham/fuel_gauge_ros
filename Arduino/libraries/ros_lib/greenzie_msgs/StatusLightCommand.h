#ifndef _ROS_greenzie_msgs_StatusLightCommand_h
#define _ROS_greenzie_msgs_StatusLightCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class StatusLightCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _ready_led_type;
      _ready_led_type ready_led;
      typedef uint8_t _map_led_type;
      _map_led_type map_led;
      typedef uint8_t _plan_led_type;
      _plan_led_type plan_led;
      typedef uint8_t _mow_led_type;
      _mow_led_type mow_led;
      typedef uint8_t _L1_lights_type;
      _L1_lights_type L1_lights;
      typedef uint8_t _L2_lights_type;
      _L2_lights_type L2_lights;
      typedef uint8_t _L3_lights_type;
      _L3_lights_type L3_lights;
      enum { OFF =  0 };
      enum { SLOW_BLINK =  1 };
      enum { FAST_BLINK =  2 };
      enum { SOLID =  3 };
      enum { ERROR_BLINK =  4 };

    StatusLightCommand():
      header(),
      ready_led(0),
      map_led(0),
      plan_led(0),
      mow_led(0),
      L1_lights(0),
      L2_lights(0),
      L3_lights(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->ready_led >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ready_led);
      *(outbuffer + offset + 0) = (this->map_led >> (8 * 0)) & 0xFF;
      offset += sizeof(this->map_led);
      *(outbuffer + offset + 0) = (this->plan_led >> (8 * 0)) & 0xFF;
      offset += sizeof(this->plan_led);
      *(outbuffer + offset + 0) = (this->mow_led >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mow_led);
      *(outbuffer + offset + 0) = (this->L1_lights >> (8 * 0)) & 0xFF;
      offset += sizeof(this->L1_lights);
      *(outbuffer + offset + 0) = (this->L2_lights >> (8 * 0)) & 0xFF;
      offset += sizeof(this->L2_lights);
      *(outbuffer + offset + 0) = (this->L3_lights >> (8 * 0)) & 0xFF;
      offset += sizeof(this->L3_lights);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->ready_led =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ready_led);
      this->map_led =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->map_led);
      this->plan_led =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->plan_led);
      this->mow_led =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mow_led);
      this->L1_lights =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->L1_lights);
      this->L2_lights =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->L2_lights);
      this->L3_lights =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->L3_lights);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/StatusLightCommand"; };
    virtual const char * getMD5() override { return "8367fc59f4948352c01c79de5b94f060"; };

  };

}
#endif
