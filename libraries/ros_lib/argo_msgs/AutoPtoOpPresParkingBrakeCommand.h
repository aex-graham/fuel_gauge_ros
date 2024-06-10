#ifndef _ROS_argo_msgs_AutoPtoOpPresParkingBrakeCommand_h
#define _ROS_argo_msgs_AutoPtoOpPresParkingBrakeCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace argo_msgs
{

  class AutoPtoOpPresParkingBrakeCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _pto_commanded_on_type;
      _pto_commanded_on_type pto_commanded_on;
      typedef bool _operator_presence_commanded_on_type;
      _operator_presence_commanded_on_type operator_presence_commanded_on;
      typedef bool _parking_brake_disengage_type;
      _parking_brake_disengage_type parking_brake_disengage;

    AutoPtoOpPresParkingBrakeCommand():
      header(),
      pto_commanded_on(0),
      operator_presence_commanded_on(0),
      parking_brake_disengage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_pto_commanded_on;
      u_pto_commanded_on.real = this->pto_commanded_on;
      *(outbuffer + offset + 0) = (u_pto_commanded_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pto_commanded_on);
      union {
        bool real;
        uint8_t base;
      } u_operator_presence_commanded_on;
      u_operator_presence_commanded_on.real = this->operator_presence_commanded_on;
      *(outbuffer + offset + 0) = (u_operator_presence_commanded_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operator_presence_commanded_on);
      union {
        bool real;
        uint8_t base;
      } u_parking_brake_disengage;
      u_parking_brake_disengage.real = this->parking_brake_disengage;
      *(outbuffer + offset + 0) = (u_parking_brake_disengage.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->parking_brake_disengage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_pto_commanded_on;
      u_pto_commanded_on.base = 0;
      u_pto_commanded_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pto_commanded_on = u_pto_commanded_on.real;
      offset += sizeof(this->pto_commanded_on);
      union {
        bool real;
        uint8_t base;
      } u_operator_presence_commanded_on;
      u_operator_presence_commanded_on.base = 0;
      u_operator_presence_commanded_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operator_presence_commanded_on = u_operator_presence_commanded_on.real;
      offset += sizeof(this->operator_presence_commanded_on);
      union {
        bool real;
        uint8_t base;
      } u_parking_brake_disengage;
      u_parking_brake_disengage.base = 0;
      u_parking_brake_disengage.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->parking_brake_disengage = u_parking_brake_disengage.real;
      offset += sizeof(this->parking_brake_disengage);
     return offset;
    }

    virtual const char * getType() override { return "argo_msgs/AutoPtoOpPresParkingBrakeCommand"; };
    virtual const char * getMD5() override { return "d9b5eb677de3169eaf3718c117102c93"; };

  };

}
#endif
