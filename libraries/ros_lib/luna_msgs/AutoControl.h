#ifndef _ROS_luna_msgs_AutoControl_h
#define _ROS_luna_msgs_AutoControl_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace luna_msgs
{

  class AutoControl : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _key_enable_type;
      _key_enable_type key_enable;
      typedef bool _crank_enable_type;
      _crank_enable_type crank_enable;
      typedef bool _engine_enable_type;
      _engine_enable_type engine_enable;
      typedef bool _estop_enable_type;
      _estop_enable_type estop_enable;
      typedef bool _drive_enable_type;
      _drive_enable_type drive_enable;
      typedef bool _PTO_enable_type;
      _PTO_enable_type PTO_enable;
      typedef float _HOC_inches_type;
      _HOC_inches_type HOC_inches;
      typedef uint16_t _left_command_type;
      _left_command_type left_command;
      typedef uint16_t _right_command_type;
      _right_command_type right_command;
      typedef uint8_t _throttle_type;
      _throttle_type throttle;

    AutoControl():
      header(),
      key_enable(0),
      crank_enable(0),
      engine_enable(0),
      estop_enable(0),
      drive_enable(0),
      PTO_enable(0),
      HOC_inches(0),
      left_command(0),
      right_command(0),
      throttle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_key_enable;
      u_key_enable.real = this->key_enable;
      *(outbuffer + offset + 0) = (u_key_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_enable);
      union {
        bool real;
        uint8_t base;
      } u_crank_enable;
      u_crank_enable.real = this->crank_enable;
      *(outbuffer + offset + 0) = (u_crank_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->crank_enable);
      union {
        bool real;
        uint8_t base;
      } u_engine_enable;
      u_engine_enable.real = this->engine_enable;
      *(outbuffer + offset + 0) = (u_engine_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_enable);
      union {
        bool real;
        uint8_t base;
      } u_estop_enable;
      u_estop_enable.real = this->estop_enable;
      *(outbuffer + offset + 0) = (u_estop_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->estop_enable);
      union {
        bool real;
        uint8_t base;
      } u_drive_enable;
      u_drive_enable.real = this->drive_enable;
      *(outbuffer + offset + 0) = (u_drive_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drive_enable);
      union {
        bool real;
        uint8_t base;
      } u_PTO_enable;
      u_PTO_enable.real = this->PTO_enable;
      *(outbuffer + offset + 0) = (u_PTO_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->PTO_enable);
      union {
        float real;
        uint32_t base;
      } u_HOC_inches;
      u_HOC_inches.real = this->HOC_inches;
      *(outbuffer + offset + 0) = (u_HOC_inches.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_HOC_inches.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_HOC_inches.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_HOC_inches.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->HOC_inches);
      *(outbuffer + offset + 0) = (this->left_command >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->left_command >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_command);
      *(outbuffer + offset + 0) = (this->right_command >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->right_command >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_command);
      *(outbuffer + offset + 0) = (this->throttle >> (8 * 0)) & 0xFF;
      offset += sizeof(this->throttle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_key_enable;
      u_key_enable.base = 0;
      u_key_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_enable = u_key_enable.real;
      offset += sizeof(this->key_enable);
      union {
        bool real;
        uint8_t base;
      } u_crank_enable;
      u_crank_enable.base = 0;
      u_crank_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->crank_enable = u_crank_enable.real;
      offset += sizeof(this->crank_enable);
      union {
        bool real;
        uint8_t base;
      } u_engine_enable;
      u_engine_enable.base = 0;
      u_engine_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_enable = u_engine_enable.real;
      offset += sizeof(this->engine_enable);
      union {
        bool real;
        uint8_t base;
      } u_estop_enable;
      u_estop_enable.base = 0;
      u_estop_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->estop_enable = u_estop_enable.real;
      offset += sizeof(this->estop_enable);
      union {
        bool real;
        uint8_t base;
      } u_drive_enable;
      u_drive_enable.base = 0;
      u_drive_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->drive_enable = u_drive_enable.real;
      offset += sizeof(this->drive_enable);
      union {
        bool real;
        uint8_t base;
      } u_PTO_enable;
      u_PTO_enable.base = 0;
      u_PTO_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->PTO_enable = u_PTO_enable.real;
      offset += sizeof(this->PTO_enable);
      union {
        float real;
        uint32_t base;
      } u_HOC_inches;
      u_HOC_inches.base = 0;
      u_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->HOC_inches = u_HOC_inches.real;
      offset += sizeof(this->HOC_inches);
      this->left_command =  ((uint16_t) (*(inbuffer + offset)));
      this->left_command |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->left_command);
      this->right_command =  ((uint16_t) (*(inbuffer + offset)));
      this->right_command |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->right_command);
      this->throttle =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->throttle);
     return offset;
    }

    virtual const char * getType() override { return "luna_msgs/AutoControl"; };
    virtual const char * getMD5() override { return "0569a523913169e6282e7c7eb230be08"; };

  };

}
#endif
