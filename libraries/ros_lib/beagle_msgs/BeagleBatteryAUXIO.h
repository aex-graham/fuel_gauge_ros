#ifndef _ROS_beagle_msgs_BeagleBatteryAUXIO_h
#define _ROS_beagle_msgs_BeagleBatteryAUXIO_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryAUXIO : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _auxio_1_type;
      _auxio_1_type auxio_1;
      typedef bool _auxio_2_type;
      _auxio_2_type auxio_2;
      typedef bool _auxio_3_type;
      _auxio_3_type auxio_3;
      typedef bool _auxio_4_type;
      _auxio_4_type auxio_4;
      typedef bool _auxio_5_type;
      _auxio_5_type auxio_5;
      typedef bool _auxio_6_type;
      _auxio_6_type auxio_6;
      typedef bool _auxio_7_type;
      _auxio_7_type auxio_7;
      typedef bool _auxio_8_type;
      _auxio_8_type auxio_8;

    BeagleBatteryAUXIO():
      header(),
      auxio_1(0),
      auxio_2(0),
      auxio_3(0),
      auxio_4(0),
      auxio_5(0),
      auxio_6(0),
      auxio_7(0),
      auxio_8(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_auxio_1;
      u_auxio_1.real = this->auxio_1;
      *(outbuffer + offset + 0) = (u_auxio_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auxio_1);
      union {
        bool real;
        uint8_t base;
      } u_auxio_2;
      u_auxio_2.real = this->auxio_2;
      *(outbuffer + offset + 0) = (u_auxio_2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auxio_2);
      union {
        bool real;
        uint8_t base;
      } u_auxio_3;
      u_auxio_3.real = this->auxio_3;
      *(outbuffer + offset + 0) = (u_auxio_3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auxio_3);
      union {
        bool real;
        uint8_t base;
      } u_auxio_4;
      u_auxio_4.real = this->auxio_4;
      *(outbuffer + offset + 0) = (u_auxio_4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auxio_4);
      union {
        bool real;
        uint8_t base;
      } u_auxio_5;
      u_auxio_5.real = this->auxio_5;
      *(outbuffer + offset + 0) = (u_auxio_5.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auxio_5);
      union {
        bool real;
        uint8_t base;
      } u_auxio_6;
      u_auxio_6.real = this->auxio_6;
      *(outbuffer + offset + 0) = (u_auxio_6.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auxio_6);
      union {
        bool real;
        uint8_t base;
      } u_auxio_7;
      u_auxio_7.real = this->auxio_7;
      *(outbuffer + offset + 0) = (u_auxio_7.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auxio_7);
      union {
        bool real;
        uint8_t base;
      } u_auxio_8;
      u_auxio_8.real = this->auxio_8;
      *(outbuffer + offset + 0) = (u_auxio_8.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auxio_8);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_auxio_1;
      u_auxio_1.base = 0;
      u_auxio_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auxio_1 = u_auxio_1.real;
      offset += sizeof(this->auxio_1);
      union {
        bool real;
        uint8_t base;
      } u_auxio_2;
      u_auxio_2.base = 0;
      u_auxio_2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auxio_2 = u_auxio_2.real;
      offset += sizeof(this->auxio_2);
      union {
        bool real;
        uint8_t base;
      } u_auxio_3;
      u_auxio_3.base = 0;
      u_auxio_3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auxio_3 = u_auxio_3.real;
      offset += sizeof(this->auxio_3);
      union {
        bool real;
        uint8_t base;
      } u_auxio_4;
      u_auxio_4.base = 0;
      u_auxio_4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auxio_4 = u_auxio_4.real;
      offset += sizeof(this->auxio_4);
      union {
        bool real;
        uint8_t base;
      } u_auxio_5;
      u_auxio_5.base = 0;
      u_auxio_5.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auxio_5 = u_auxio_5.real;
      offset += sizeof(this->auxio_5);
      union {
        bool real;
        uint8_t base;
      } u_auxio_6;
      u_auxio_6.base = 0;
      u_auxio_6.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auxio_6 = u_auxio_6.real;
      offset += sizeof(this->auxio_6);
      union {
        bool real;
        uint8_t base;
      } u_auxio_7;
      u_auxio_7.base = 0;
      u_auxio_7.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auxio_7 = u_auxio_7.real;
      offset += sizeof(this->auxio_7);
      union {
        bool real;
        uint8_t base;
      } u_auxio_8;
      u_auxio_8.base = 0;
      u_auxio_8.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auxio_8 = u_auxio_8.real;
      offset += sizeof(this->auxio_8);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryAUXIO"; };
    virtual const char * getMD5() override { return "777af9efb55ce5e2dc6f08be07d429aa"; };

  };

}
#endif
