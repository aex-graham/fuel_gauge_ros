#ifndef _ROS_intrepid_msgs_LbsmGeneralStatus_h
#define _ROS_intrepid_msgs_LbsmGeneralStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace intrepid_msgs
{

  class LbsmGeneralStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _pos_type;
      _pos_type pos;
      typedef bool _is_neutral_type;
      _is_neutral_type is_neutral;
      typedef uint8_t _locale_type;
      _locale_type locale;
      typedef uint8_t _latched_fault_code_type;
      _latched_fault_code_type latched_fault_code;

    LbsmGeneralStatus():
      header(),
      pos(0),
      is_neutral(0),
      locale(0),
      latched_fault_code(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_pos;
      u_pos.real = this->pos;
      *(outbuffer + offset + 0) = (u_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pos.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pos.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pos);
      union {
        bool real;
        uint8_t base;
      } u_is_neutral;
      u_is_neutral.real = this->is_neutral;
      *(outbuffer + offset + 0) = (u_is_neutral.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_neutral);
      *(outbuffer + offset + 0) = (this->locale >> (8 * 0)) & 0xFF;
      offset += sizeof(this->locale);
      *(outbuffer + offset + 0) = (this->latched_fault_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->latched_fault_code);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_pos;
      u_pos.base = 0;
      u_pos.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pos.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pos.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pos = u_pos.real;
      offset += sizeof(this->pos);
      union {
        bool real;
        uint8_t base;
      } u_is_neutral;
      u_is_neutral.base = 0;
      u_is_neutral.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_neutral = u_is_neutral.real;
      offset += sizeof(this->is_neutral);
      this->locale =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->locale);
      this->latched_fault_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->latched_fault_code);
     return offset;
    }

    virtual const char * getType() override { return "intrepid_msgs/LbsmGeneralStatus"; };
    virtual const char * getMD5() override { return "6428a93ef3b90b2fa816db3f6b3a7b53"; };

  };

}
#endif
