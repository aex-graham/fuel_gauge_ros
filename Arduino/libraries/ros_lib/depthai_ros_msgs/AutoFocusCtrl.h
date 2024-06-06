#ifndef _ROS_depthai_ros_msgs_AutoFocusCtrl_h
#define _ROS_depthai_ros_msgs_AutoFocusCtrl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace depthai_ros_msgs
{

  class AutoFocusCtrl : public ros::Msg
  {
    public:
      typedef uint8_t _auto_focus_mode_type;
      _auto_focus_mode_type auto_focus_mode;
      typedef bool _trigger_auto_focus_type;
      _trigger_auto_focus_type trigger_auto_focus;
      enum { AF_MODE_AUTO =  0 };
      enum { AF_MODE_MACRO =  1 };
      enum { AF_MODE_CONTINUOUS_VIDEO =  2 };
      enum { AF_MODE_CONTINUOUS_PICTURE =  3 };
      enum { AF_MODE_EDOF =  4 };

    AutoFocusCtrl():
      auto_focus_mode(0),
      trigger_auto_focus(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->auto_focus_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_focus_mode);
      union {
        bool real;
        uint8_t base;
      } u_trigger_auto_focus;
      u_trigger_auto_focus.real = this->trigger_auto_focus;
      *(outbuffer + offset + 0) = (u_trigger_auto_focus.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->trigger_auto_focus);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->auto_focus_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->auto_focus_mode);
      union {
        bool real;
        uint8_t base;
      } u_trigger_auto_focus;
      u_trigger_auto_focus.base = 0;
      u_trigger_auto_focus.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->trigger_auto_focus = u_trigger_auto_focus.real;
      offset += sizeof(this->trigger_auto_focus);
     return offset;
    }

    virtual const char * getType() override { return "depthai_ros_msgs/AutoFocusCtrl"; };
    virtual const char * getMD5() override { return "57bd33867f64daa701fce3a114856f8f"; };

  };

}
#endif
