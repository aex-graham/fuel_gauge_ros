#ifndef _ROS_argo_msgs_VCMStatus_h
#define _ROS_argo_msgs_VCMStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace argo_msgs
{

  class VCMStatus : public ros::Msg
  {
    public:
      typedef bool _fault_status_type;
      _fault_status_type fault_status;
      typedef bool _traction_status_type;
      _traction_status_type traction_status;
      typedef uint8_t _deck_status_type;
      _deck_status_type deck_status;
      typedef bool _PTO_switch_status_type;
      _PTO_switch_status_type PTO_switch_status;
      typedef bool _parking_brake_switch_status_type;
      _parking_brake_switch_status_type parking_brake_switch_status;
      typedef bool _seat_switch_status_type;
      _seat_switch_status_type seat_switch_status;
      typedef uint8_t _speed_switch_status_type;
      _speed_switch_status_type speed_switch_status;
      typedef bool _electric_brake_status_type;
      _electric_brake_status_type electric_brake_status;
      typedef bool _deck_stall_left_type;
      _deck_stall_left_type deck_stall_left;
      typedef bool _deck_stall_right_type;
      _deck_stall_right_type deck_stall_right;
      typedef bool _deck_stall_center_type;
      _deck_stall_center_type deck_stall_center;
      typedef bool _ignition_type;
      _ignition_type ignition;
      typedef bool _digital_input_1A_type;
      _digital_input_1A_type digital_input_1A;
      typedef bool _digital_input_2A_type;
      _digital_input_2A_type digital_input_2A;
      typedef bool _digital_input_3A_type;
      _digital_input_3A_type digital_input_3A;
      typedef bool _digital_input_4A_type;
      _digital_input_4A_type digital_input_4A;
      typedef bool _digital_input_5A_type;
      _digital_input_5A_type digital_input_5A;
      typedef bool _digital_input_1B_type;
      _digital_input_1B_type digital_input_1B;
      typedef bool _digital_input_2B_type;
      _digital_input_2B_type digital_input_2B;
      typedef bool _digital_input_3B_type;
      _digital_input_3B_type digital_input_3B;
      typedef bool _digital_input_4B_type;
      _digital_input_4B_type digital_input_4B;
      typedef bool _digital_input_5B_type;
      _digital_input_5B_type digital_input_5B;
      typedef uint16_t _hours_type;
      _hours_type hours;
      typedef bool _seat_LTD_prevent_type;
      _seat_LTD_prevent_type seat_LTD_prevent;
      typedef bool _battery_LTD_prevent_type;
      _battery_LTD_prevent_type battery_LTD_prevent;
      typedef bool _controller_LTD_prevent_type;
      _controller_LTD_prevent_type controller_LTD_prevent;
      typedef bool _steering_LTD_prevent_type;
      _steering_LTD_prevent_type steering_LTD_prevent;
      typedef bool _park_brake_LTD_prevent_type;
      _park_brake_LTD_prevent_type park_brake_LTD_prevent;
      typedef bool _park_brake_release1_type;
      _park_brake_release1_type park_brake_release1;
      typedef bool _seat_exit_LTD_type;
      _seat_exit_LTD_type seat_exit_LTD;
      typedef bool _battery_exit_LTD_type;
      _battery_exit_LTD_type battery_exit_LTD;
      typedef bool _key_exit_LTD_type;
      _key_exit_LTD_type key_exit_LTD;
      typedef bool _controller_exit_LTD_type;
      _controller_exit_LTD_type controller_exit_LTD;
      typedef bool _park_brake_exit_LTD_type;
      _park_brake_exit_LTD_type park_brake_exit_LTD;
      typedef bool _park_brake_release2_type;
      _park_brake_release2_type park_brake_release2;

    VCMStatus():
      fault_status(0),
      traction_status(0),
      deck_status(0),
      PTO_switch_status(0),
      parking_brake_switch_status(0),
      seat_switch_status(0),
      speed_switch_status(0),
      electric_brake_status(0),
      deck_stall_left(0),
      deck_stall_right(0),
      deck_stall_center(0),
      ignition(0),
      digital_input_1A(0),
      digital_input_2A(0),
      digital_input_3A(0),
      digital_input_4A(0),
      digital_input_5A(0),
      digital_input_1B(0),
      digital_input_2B(0),
      digital_input_3B(0),
      digital_input_4B(0),
      digital_input_5B(0),
      hours(0),
      seat_LTD_prevent(0),
      battery_LTD_prevent(0),
      controller_LTD_prevent(0),
      steering_LTD_prevent(0),
      park_brake_LTD_prevent(0),
      park_brake_release1(0),
      seat_exit_LTD(0),
      battery_exit_LTD(0),
      key_exit_LTD(0),
      controller_exit_LTD(0),
      park_brake_exit_LTD(0),
      park_brake_release2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_fault_status;
      u_fault_status.real = this->fault_status;
      *(outbuffer + offset + 0) = (u_fault_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->fault_status);
      union {
        bool real;
        uint8_t base;
      } u_traction_status;
      u_traction_status.real = this->traction_status;
      *(outbuffer + offset + 0) = (u_traction_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->traction_status);
      *(outbuffer + offset + 0) = (this->deck_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->deck_status);
      union {
        bool real;
        uint8_t base;
      } u_PTO_switch_status;
      u_PTO_switch_status.real = this->PTO_switch_status;
      *(outbuffer + offset + 0) = (u_PTO_switch_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->PTO_switch_status);
      union {
        bool real;
        uint8_t base;
      } u_parking_brake_switch_status;
      u_parking_brake_switch_status.real = this->parking_brake_switch_status;
      *(outbuffer + offset + 0) = (u_parking_brake_switch_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->parking_brake_switch_status);
      union {
        bool real;
        uint8_t base;
      } u_seat_switch_status;
      u_seat_switch_status.real = this->seat_switch_status;
      *(outbuffer + offset + 0) = (u_seat_switch_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seat_switch_status);
      *(outbuffer + offset + 0) = (this->speed_switch_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed_switch_status);
      union {
        bool real;
        uint8_t base;
      } u_electric_brake_status;
      u_electric_brake_status.real = this->electric_brake_status;
      *(outbuffer + offset + 0) = (u_electric_brake_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->electric_brake_status);
      union {
        bool real;
        uint8_t base;
      } u_deck_stall_left;
      u_deck_stall_left.real = this->deck_stall_left;
      *(outbuffer + offset + 0) = (u_deck_stall_left.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->deck_stall_left);
      union {
        bool real;
        uint8_t base;
      } u_deck_stall_right;
      u_deck_stall_right.real = this->deck_stall_right;
      *(outbuffer + offset + 0) = (u_deck_stall_right.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->deck_stall_right);
      union {
        bool real;
        uint8_t base;
      } u_deck_stall_center;
      u_deck_stall_center.real = this->deck_stall_center;
      *(outbuffer + offset + 0) = (u_deck_stall_center.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->deck_stall_center);
      union {
        bool real;
        uint8_t base;
      } u_ignition;
      u_ignition.real = this->ignition;
      *(outbuffer + offset + 0) = (u_ignition.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ignition);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_1A;
      u_digital_input_1A.real = this->digital_input_1A;
      *(outbuffer + offset + 0) = (u_digital_input_1A.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_input_1A);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_2A;
      u_digital_input_2A.real = this->digital_input_2A;
      *(outbuffer + offset + 0) = (u_digital_input_2A.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_input_2A);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_3A;
      u_digital_input_3A.real = this->digital_input_3A;
      *(outbuffer + offset + 0) = (u_digital_input_3A.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_input_3A);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_4A;
      u_digital_input_4A.real = this->digital_input_4A;
      *(outbuffer + offset + 0) = (u_digital_input_4A.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_input_4A);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_5A;
      u_digital_input_5A.real = this->digital_input_5A;
      *(outbuffer + offset + 0) = (u_digital_input_5A.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_input_5A);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_1B;
      u_digital_input_1B.real = this->digital_input_1B;
      *(outbuffer + offset + 0) = (u_digital_input_1B.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_input_1B);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_2B;
      u_digital_input_2B.real = this->digital_input_2B;
      *(outbuffer + offset + 0) = (u_digital_input_2B.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_input_2B);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_3B;
      u_digital_input_3B.real = this->digital_input_3B;
      *(outbuffer + offset + 0) = (u_digital_input_3B.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_input_3B);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_4B;
      u_digital_input_4B.real = this->digital_input_4B;
      *(outbuffer + offset + 0) = (u_digital_input_4B.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_input_4B);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_5B;
      u_digital_input_5B.real = this->digital_input_5B;
      *(outbuffer + offset + 0) = (u_digital_input_5B.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_input_5B);
      *(outbuffer + offset + 0) = (this->hours >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hours >> (8 * 1)) & 0xFF;
      offset += sizeof(this->hours);
      union {
        bool real;
        uint8_t base;
      } u_seat_LTD_prevent;
      u_seat_LTD_prevent.real = this->seat_LTD_prevent;
      *(outbuffer + offset + 0) = (u_seat_LTD_prevent.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seat_LTD_prevent);
      union {
        bool real;
        uint8_t base;
      } u_battery_LTD_prevent;
      u_battery_LTD_prevent.real = this->battery_LTD_prevent;
      *(outbuffer + offset + 0) = (u_battery_LTD_prevent.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery_LTD_prevent);
      union {
        bool real;
        uint8_t base;
      } u_controller_LTD_prevent;
      u_controller_LTD_prevent.real = this->controller_LTD_prevent;
      *(outbuffer + offset + 0) = (u_controller_LTD_prevent.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->controller_LTD_prevent);
      union {
        bool real;
        uint8_t base;
      } u_steering_LTD_prevent;
      u_steering_LTD_prevent.real = this->steering_LTD_prevent;
      *(outbuffer + offset + 0) = (u_steering_LTD_prevent.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->steering_LTD_prevent);
      union {
        bool real;
        uint8_t base;
      } u_park_brake_LTD_prevent;
      u_park_brake_LTD_prevent.real = this->park_brake_LTD_prevent;
      *(outbuffer + offset + 0) = (u_park_brake_LTD_prevent.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->park_brake_LTD_prevent);
      union {
        bool real;
        uint8_t base;
      } u_park_brake_release1;
      u_park_brake_release1.real = this->park_brake_release1;
      *(outbuffer + offset + 0) = (u_park_brake_release1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->park_brake_release1);
      union {
        bool real;
        uint8_t base;
      } u_seat_exit_LTD;
      u_seat_exit_LTD.real = this->seat_exit_LTD;
      *(outbuffer + offset + 0) = (u_seat_exit_LTD.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seat_exit_LTD);
      union {
        bool real;
        uint8_t base;
      } u_battery_exit_LTD;
      u_battery_exit_LTD.real = this->battery_exit_LTD;
      *(outbuffer + offset + 0) = (u_battery_exit_LTD.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery_exit_LTD);
      union {
        bool real;
        uint8_t base;
      } u_key_exit_LTD;
      u_key_exit_LTD.real = this->key_exit_LTD;
      *(outbuffer + offset + 0) = (u_key_exit_LTD.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_exit_LTD);
      union {
        bool real;
        uint8_t base;
      } u_controller_exit_LTD;
      u_controller_exit_LTD.real = this->controller_exit_LTD;
      *(outbuffer + offset + 0) = (u_controller_exit_LTD.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->controller_exit_LTD);
      union {
        bool real;
        uint8_t base;
      } u_park_brake_exit_LTD;
      u_park_brake_exit_LTD.real = this->park_brake_exit_LTD;
      *(outbuffer + offset + 0) = (u_park_brake_exit_LTD.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->park_brake_exit_LTD);
      union {
        bool real;
        uint8_t base;
      } u_park_brake_release2;
      u_park_brake_release2.real = this->park_brake_release2;
      *(outbuffer + offset + 0) = (u_park_brake_release2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->park_brake_release2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_fault_status;
      u_fault_status.base = 0;
      u_fault_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->fault_status = u_fault_status.real;
      offset += sizeof(this->fault_status);
      union {
        bool real;
        uint8_t base;
      } u_traction_status;
      u_traction_status.base = 0;
      u_traction_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->traction_status = u_traction_status.real;
      offset += sizeof(this->traction_status);
      this->deck_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->deck_status);
      union {
        bool real;
        uint8_t base;
      } u_PTO_switch_status;
      u_PTO_switch_status.base = 0;
      u_PTO_switch_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->PTO_switch_status = u_PTO_switch_status.real;
      offset += sizeof(this->PTO_switch_status);
      union {
        bool real;
        uint8_t base;
      } u_parking_brake_switch_status;
      u_parking_brake_switch_status.base = 0;
      u_parking_brake_switch_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->parking_brake_switch_status = u_parking_brake_switch_status.real;
      offset += sizeof(this->parking_brake_switch_status);
      union {
        bool real;
        uint8_t base;
      } u_seat_switch_status;
      u_seat_switch_status.base = 0;
      u_seat_switch_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->seat_switch_status = u_seat_switch_status.real;
      offset += sizeof(this->seat_switch_status);
      this->speed_switch_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->speed_switch_status);
      union {
        bool real;
        uint8_t base;
      } u_electric_brake_status;
      u_electric_brake_status.base = 0;
      u_electric_brake_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->electric_brake_status = u_electric_brake_status.real;
      offset += sizeof(this->electric_brake_status);
      union {
        bool real;
        uint8_t base;
      } u_deck_stall_left;
      u_deck_stall_left.base = 0;
      u_deck_stall_left.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->deck_stall_left = u_deck_stall_left.real;
      offset += sizeof(this->deck_stall_left);
      union {
        bool real;
        uint8_t base;
      } u_deck_stall_right;
      u_deck_stall_right.base = 0;
      u_deck_stall_right.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->deck_stall_right = u_deck_stall_right.real;
      offset += sizeof(this->deck_stall_right);
      union {
        bool real;
        uint8_t base;
      } u_deck_stall_center;
      u_deck_stall_center.base = 0;
      u_deck_stall_center.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->deck_stall_center = u_deck_stall_center.real;
      offset += sizeof(this->deck_stall_center);
      union {
        bool real;
        uint8_t base;
      } u_ignition;
      u_ignition.base = 0;
      u_ignition.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ignition = u_ignition.real;
      offset += sizeof(this->ignition);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_1A;
      u_digital_input_1A.base = 0;
      u_digital_input_1A.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_input_1A = u_digital_input_1A.real;
      offset += sizeof(this->digital_input_1A);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_2A;
      u_digital_input_2A.base = 0;
      u_digital_input_2A.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_input_2A = u_digital_input_2A.real;
      offset += sizeof(this->digital_input_2A);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_3A;
      u_digital_input_3A.base = 0;
      u_digital_input_3A.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_input_3A = u_digital_input_3A.real;
      offset += sizeof(this->digital_input_3A);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_4A;
      u_digital_input_4A.base = 0;
      u_digital_input_4A.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_input_4A = u_digital_input_4A.real;
      offset += sizeof(this->digital_input_4A);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_5A;
      u_digital_input_5A.base = 0;
      u_digital_input_5A.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_input_5A = u_digital_input_5A.real;
      offset += sizeof(this->digital_input_5A);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_1B;
      u_digital_input_1B.base = 0;
      u_digital_input_1B.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_input_1B = u_digital_input_1B.real;
      offset += sizeof(this->digital_input_1B);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_2B;
      u_digital_input_2B.base = 0;
      u_digital_input_2B.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_input_2B = u_digital_input_2B.real;
      offset += sizeof(this->digital_input_2B);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_3B;
      u_digital_input_3B.base = 0;
      u_digital_input_3B.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_input_3B = u_digital_input_3B.real;
      offset += sizeof(this->digital_input_3B);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_4B;
      u_digital_input_4B.base = 0;
      u_digital_input_4B.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_input_4B = u_digital_input_4B.real;
      offset += sizeof(this->digital_input_4B);
      union {
        bool real;
        uint8_t base;
      } u_digital_input_5B;
      u_digital_input_5B.base = 0;
      u_digital_input_5B.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->digital_input_5B = u_digital_input_5B.real;
      offset += sizeof(this->digital_input_5B);
      this->hours =  ((uint16_t) (*(inbuffer + offset)));
      this->hours |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->hours);
      union {
        bool real;
        uint8_t base;
      } u_seat_LTD_prevent;
      u_seat_LTD_prevent.base = 0;
      u_seat_LTD_prevent.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->seat_LTD_prevent = u_seat_LTD_prevent.real;
      offset += sizeof(this->seat_LTD_prevent);
      union {
        bool real;
        uint8_t base;
      } u_battery_LTD_prevent;
      u_battery_LTD_prevent.base = 0;
      u_battery_LTD_prevent.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->battery_LTD_prevent = u_battery_LTD_prevent.real;
      offset += sizeof(this->battery_LTD_prevent);
      union {
        bool real;
        uint8_t base;
      } u_controller_LTD_prevent;
      u_controller_LTD_prevent.base = 0;
      u_controller_LTD_prevent.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->controller_LTD_prevent = u_controller_LTD_prevent.real;
      offset += sizeof(this->controller_LTD_prevent);
      union {
        bool real;
        uint8_t base;
      } u_steering_LTD_prevent;
      u_steering_LTD_prevent.base = 0;
      u_steering_LTD_prevent.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->steering_LTD_prevent = u_steering_LTD_prevent.real;
      offset += sizeof(this->steering_LTD_prevent);
      union {
        bool real;
        uint8_t base;
      } u_park_brake_LTD_prevent;
      u_park_brake_LTD_prevent.base = 0;
      u_park_brake_LTD_prevent.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->park_brake_LTD_prevent = u_park_brake_LTD_prevent.real;
      offset += sizeof(this->park_brake_LTD_prevent);
      union {
        bool real;
        uint8_t base;
      } u_park_brake_release1;
      u_park_brake_release1.base = 0;
      u_park_brake_release1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->park_brake_release1 = u_park_brake_release1.real;
      offset += sizeof(this->park_brake_release1);
      union {
        bool real;
        uint8_t base;
      } u_seat_exit_LTD;
      u_seat_exit_LTD.base = 0;
      u_seat_exit_LTD.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->seat_exit_LTD = u_seat_exit_LTD.real;
      offset += sizeof(this->seat_exit_LTD);
      union {
        bool real;
        uint8_t base;
      } u_battery_exit_LTD;
      u_battery_exit_LTD.base = 0;
      u_battery_exit_LTD.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->battery_exit_LTD = u_battery_exit_LTD.real;
      offset += sizeof(this->battery_exit_LTD);
      union {
        bool real;
        uint8_t base;
      } u_key_exit_LTD;
      u_key_exit_LTD.base = 0;
      u_key_exit_LTD.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_exit_LTD = u_key_exit_LTD.real;
      offset += sizeof(this->key_exit_LTD);
      union {
        bool real;
        uint8_t base;
      } u_controller_exit_LTD;
      u_controller_exit_LTD.base = 0;
      u_controller_exit_LTD.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->controller_exit_LTD = u_controller_exit_LTD.real;
      offset += sizeof(this->controller_exit_LTD);
      union {
        bool real;
        uint8_t base;
      } u_park_brake_exit_LTD;
      u_park_brake_exit_LTD.base = 0;
      u_park_brake_exit_LTD.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->park_brake_exit_LTD = u_park_brake_exit_LTD.real;
      offset += sizeof(this->park_brake_exit_LTD);
      union {
        bool real;
        uint8_t base;
      } u_park_brake_release2;
      u_park_brake_release2.base = 0;
      u_park_brake_release2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->park_brake_release2 = u_park_brake_release2.real;
      offset += sizeof(this->park_brake_release2);
     return offset;
    }

    virtual const char * getType() override { return "argo_msgs/VCMStatus"; };
    virtual const char * getMD5() override { return "4c164f33386df6202a6591eb9903aaac"; };

  };

}
#endif
