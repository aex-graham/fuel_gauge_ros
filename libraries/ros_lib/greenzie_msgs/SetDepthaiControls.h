#ifndef _ROS_SERVICE_SetDepthaiControls_h
#define _ROS_SERVICE_SetDepthaiControls_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

static const char SETDEPTHAICONTROLS[] = "greenzie_msgs/SetDepthaiControls";

  class SetDepthaiControlsRequest : public ros::Msg
  {
    public:
      typedef uint8_t _autofocus_mode_type;
      _autofocus_mode_type autofocus_mode;
      typedef uint8_t _manual_focus_position_type;
      _manual_focus_position_type manual_focus_position;
      typedef bool _auto_exposure_enable_type;
      _auto_exposure_enable_type auto_exposure_enable;
      typedef uint32_t _manual_exposure_time_us_type;
      _manual_exposure_time_us_type manual_exposure_time_us;
      typedef uint32_t _manual_exposure_iso_type;
      _manual_exposure_iso_type manual_exposure_iso;
      typedef uint8_t _auto_white_balance_mode_type;
      _auto_white_balance_mode_type auto_white_balance_mode;
      typedef uint16_t _manual_white_balance_type;
      _manual_white_balance_type manual_white_balance;
      enum { AUTO_FOCUS_MODE_OFF =  0 };
      enum { AUTO_FOCUS_MODE_AUTO =  1 };
      enum { AUTO_FOCUS_MODE_MACRO =  2 };
      enum { AUTO_FOCUS_MODE_CONTINUOUS_VIDEO =  3 };
      enum { AUTO_FOCUS_MODE_CONTINUOUS_PICTURE =  4 };
      enum { AUTO_FOCUS_MODE_EDOF =  5 };
      enum { AUTO_WHITE_BALANCE_MODE_OFF =  0 };
      enum { AUTO_WHITE_BALANCE_MODE_AUTO =  1 };
      enum { AUTO_WHITE_BALANCE_MODE_INCANDESCENT =  2 };
      enum { AUTO_WHITE_BALANCE_MODE_FLOURESCENT =  3 };
      enum { AUTO_WHITE_BALANCE_MODE_WARM_FLOURESCENT =  4 };
      enum { AUTO_WHITE_BALANCE_MODE_DAYLIGHT =  5 };
      enum { AUTO_WHITE_BALANCE_MODE_CLOUDY_DAYLIGHT =  6 };
      enum { AUTO_WHITE_BALANCE_MODE_TWILIGHT =  7 };
      enum { AUTO_WHITE_BALANCE_MODE_SHADE =  8 };

    SetDepthaiControlsRequest():
      autofocus_mode(0),
      manual_focus_position(0),
      auto_exposure_enable(0),
      manual_exposure_time_us(0),
      manual_exposure_iso(0),
      auto_white_balance_mode(0),
      manual_white_balance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->autofocus_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autofocus_mode);
      *(outbuffer + offset + 0) = (this->manual_focus_position >> (8 * 0)) & 0xFF;
      offset += sizeof(this->manual_focus_position);
      union {
        bool real;
        uint8_t base;
      } u_auto_exposure_enable;
      u_auto_exposure_enable.real = this->auto_exposure_enable;
      *(outbuffer + offset + 0) = (u_auto_exposure_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_exposure_enable);
      *(outbuffer + offset + 0) = (this->manual_exposure_time_us >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->manual_exposure_time_us >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->manual_exposure_time_us >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->manual_exposure_time_us >> (8 * 3)) & 0xFF;
      offset += sizeof(this->manual_exposure_time_us);
      *(outbuffer + offset + 0) = (this->manual_exposure_iso >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->manual_exposure_iso >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->manual_exposure_iso >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->manual_exposure_iso >> (8 * 3)) & 0xFF;
      offset += sizeof(this->manual_exposure_iso);
      *(outbuffer + offset + 0) = (this->auto_white_balance_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_white_balance_mode);
      *(outbuffer + offset + 0) = (this->manual_white_balance >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->manual_white_balance >> (8 * 1)) & 0xFF;
      offset += sizeof(this->manual_white_balance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->autofocus_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->autofocus_mode);
      this->manual_focus_position =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->manual_focus_position);
      union {
        bool real;
        uint8_t base;
      } u_auto_exposure_enable;
      u_auto_exposure_enable.base = 0;
      u_auto_exposure_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auto_exposure_enable = u_auto_exposure_enable.real;
      offset += sizeof(this->auto_exposure_enable);
      this->manual_exposure_time_us =  ((uint32_t) (*(inbuffer + offset)));
      this->manual_exposure_time_us |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->manual_exposure_time_us |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->manual_exposure_time_us |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->manual_exposure_time_us);
      this->manual_exposure_iso =  ((uint32_t) (*(inbuffer + offset)));
      this->manual_exposure_iso |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->manual_exposure_iso |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->manual_exposure_iso |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->manual_exposure_iso);
      this->auto_white_balance_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->auto_white_balance_mode);
      this->manual_white_balance =  ((uint16_t) (*(inbuffer + offset)));
      this->manual_white_balance |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->manual_white_balance);
     return offset;
    }

    virtual const char * getType() override { return SETDEPTHAICONTROLS; };
    virtual const char * getMD5() override { return "ee8142070993e84fa97fb7fda234d8c7"; };

  };

  class SetDepthaiControlsResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetDepthaiControlsResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return SETDEPTHAICONTROLS; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetDepthaiControls {
    public:
    typedef SetDepthaiControlsRequest Request;
    typedef SetDepthaiControlsResponse Response;
  };

}
#endif
