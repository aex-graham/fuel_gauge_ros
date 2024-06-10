#ifndef _ROS_intrepid_msgs_EdmWheelCommand_h
#define _ROS_intrepid_msgs_EdmWheelCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace intrepid_msgs
{

  class EdmWheelCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _left_control_mode_type;
      _left_control_mode_type left_control_mode;
      typedef uint8_t _right_control_mode_type;
      _right_control_mode_type right_control_mode;
      typedef float _left_demand_angle_deg_type;
      _left_demand_angle_deg_type left_demand_angle_deg;
      typedef float _right_demand_angle_deg_type;
      _right_demand_angle_deg_type right_demand_angle_deg;
      enum { STATE_NO_DRIVE = 0 };
      enum { STATE_POSITION_CONTROL = 2 };
      enum { STATE_MOTION_PROFILED = 3 };
      enum { STATE_SYSTEM_CALIBRATION = 4 };
      enum { STATE_FAIL_REDUCED_FUNCTION = 5 };
      enum { STATE_FAIL_DISABLED_NEUTRAL = 6 };

    EdmWheelCommand():
      header(),
      left_control_mode(0),
      right_control_mode(0),
      left_demand_angle_deg(0),
      right_demand_angle_deg(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->left_control_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_control_mode);
      *(outbuffer + offset + 0) = (this->right_control_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_control_mode);
      union {
        float real;
        uint32_t base;
      } u_left_demand_angle_deg;
      u_left_demand_angle_deg.real = this->left_demand_angle_deg;
      *(outbuffer + offset + 0) = (u_left_demand_angle_deg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_demand_angle_deg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_left_demand_angle_deg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_left_demand_angle_deg.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->left_demand_angle_deg);
      union {
        float real;
        uint32_t base;
      } u_right_demand_angle_deg;
      u_right_demand_angle_deg.real = this->right_demand_angle_deg;
      *(outbuffer + offset + 0) = (u_right_demand_angle_deg.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_demand_angle_deg.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_right_demand_angle_deg.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_right_demand_angle_deg.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->right_demand_angle_deg);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->left_control_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->left_control_mode);
      this->right_control_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->right_control_mode);
      union {
        float real;
        uint32_t base;
      } u_left_demand_angle_deg;
      u_left_demand_angle_deg.base = 0;
      u_left_demand_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_demand_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_left_demand_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_left_demand_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->left_demand_angle_deg = u_left_demand_angle_deg.real;
      offset += sizeof(this->left_demand_angle_deg);
      union {
        float real;
        uint32_t base;
      } u_right_demand_angle_deg;
      u_right_demand_angle_deg.base = 0;
      u_right_demand_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_demand_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_right_demand_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_right_demand_angle_deg.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->right_demand_angle_deg = u_right_demand_angle_deg.real;
      offset += sizeof(this->right_demand_angle_deg);
     return offset;
    }

    virtual const char * getType() override { return "intrepid_msgs/EdmWheelCommand"; };
    virtual const char * getMD5() override { return "7126c5fe9840f709ee31440aa7220da1"; };

  };

}
#endif
