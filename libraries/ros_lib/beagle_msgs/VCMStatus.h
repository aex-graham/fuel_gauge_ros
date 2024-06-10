#ifndef _ROS_beagle_msgs_VCMStatus_h
#define _ROS_beagle_msgs_VCMStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace beagle_msgs
{

  class VCMStatus : public ros::Msg
  {
    public:
      typedef bool _system_brake_on_type;
      _system_brake_on_type system_brake_on;
      typedef bool _foot_brake_on_type;
      _foot_brake_on_type foot_brake_on;
      typedef bool _left_brake_on_type;
      _left_brake_on_type left_brake_on;
      typedef bool _right_brake_on_type;
      _right_brake_on_type right_brake_on;
      typedef uint8_t _traction_profile_type;
      _traction_profile_type traction_profile;
      typedef uint8_t _deck_profile_type;
      _deck_profile_type deck_profile;
      typedef bool _charger_door_type;
      _charger_door_type charger_door;
      typedef bool _charger_loopback_on_type;
      _charger_loopback_on_type charger_loopback_on;
      typedef bool _seat_switch_on_type;
      _seat_switch_on_type seat_switch_on;
      typedef bool _pto_switch_on_type;
      _pto_switch_on_type pto_switch_on;
      typedef bool _chute_switch_on_type;
      _chute_switch_on_type chute_switch_on;
      typedef bool _boost_switch_on_type;
      _boost_switch_on_type boost_switch_on;
      typedef bool _creep_switch_on_type;
      _creep_switch_on_type creep_switch_on;
      typedef bool _parking_brake_release_on_type;
      _parking_brake_release_on_type parking_brake_release_on;
      typedef bool _user_peripheral_1_type;
      _user_peripheral_1_type user_peripheral_1;
      typedef bool _user_peripheral_2_type;
      _user_peripheral_2_type user_peripheral_2;
      typedef bool _autonomous_mode_enable_type;
      _autonomous_mode_enable_type autonomous_mode_enable;
      typedef uint8_t _autonomous_mode_type;
      _autonomous_mode_type autonomous_mode;
      typedef bool _key_switch_on_type;
      _key_switch_on_type key_switch_on;
      typedef uint8_t _system_state_type;
      _system_state_type system_state;
      typedef uint8_t _battery_state_type;
      _battery_state_type battery_state;
      typedef uint8_t _vehicle_state_type;
      _vehicle_state_type vehicle_state;
      typedef uint8_t _traction_state_type;
      _traction_state_type traction_state;
      typedef uint8_t _deck_state_type;
      _deck_state_type deck_state;
      typedef uint32_t _deck_running_time_min_type;
      _deck_running_time_min_type deck_running_time_min;
      enum { AUTO_MODE_MANUAL =  0 };
      enum { AUTO_MODE_SELF_DRIVING =  1 };
      enum { AUTO_MODE_ERROR =  2 };
      enum { SYSTEM_OFF =  0 };
      enum { SYSTEM_ON =  1 };
      enum { SYSTEM_ERROR =  2 };
      enum { BATTERY_OFF =  0 };
      enum { BATTERY_PRECHARGING =  1 };
      enum { BATTERY_CHARGING =  2 };
      enum { BATTERY_DISCHARGING =  3 };
      enum { BATTERY_ERROR =  4 };
      enum { VEHICLE_OFF =  0 };
      enum { VEHICLE_STARTUP =  1 };
      enum { VEHICLE_CALIBRATION =  2 };
      enum { VEHICLE_CHARGING =  3 };
      enum { VEHICLE_STANDBY =  4 };
      enum { VEHICLE_RUNNING =  5 };
      enum { VEHICLE_LIMPING =  6 };
      enum { VEHICLE_SECONDARY_STANDBY =  7 };
      enum { VEHICLE_SECONDARY_STANDBY_LIMPING =  8 };
      enum { VEHICLE_ERROR =  9 };
      enum { TRACTION_OFF =  0 };
      enum { TRACTION_HOLD =  1 };
      enum { TRACTION_RUNNING =  2 };
      enum { TRACTION_RAMP_DOWN =  3 };
      enum { TRACTION_ERROR =  4 };
      enum { DECK_OFF =  0 };
      enum { DECK_OFF_STALL =  1 };
      enum { DECK_OFF_LOW_BATTERY_WARNING =  2 };
      enum { DECK_WINDING_DOWN =  3 };
      enum { DECK_WINDING_DOWN_STALL =  4 };
      enum { DECK_WINDING_DOWN_LOW_BATTERY_WARNING =  5 };
      enum { DECK_RUNNING =  6 };
      enum { DECK_ERROR =  7 };

    VCMStatus():
      system_brake_on(0),
      foot_brake_on(0),
      left_brake_on(0),
      right_brake_on(0),
      traction_profile(0),
      deck_profile(0),
      charger_door(0),
      charger_loopback_on(0),
      seat_switch_on(0),
      pto_switch_on(0),
      chute_switch_on(0),
      boost_switch_on(0),
      creep_switch_on(0),
      parking_brake_release_on(0),
      user_peripheral_1(0),
      user_peripheral_2(0),
      autonomous_mode_enable(0),
      autonomous_mode(0),
      key_switch_on(0),
      system_state(0),
      battery_state(0),
      vehicle_state(0),
      traction_state(0),
      deck_state(0),
      deck_running_time_min(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_system_brake_on;
      u_system_brake_on.real = this->system_brake_on;
      *(outbuffer + offset + 0) = (u_system_brake_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->system_brake_on);
      union {
        bool real;
        uint8_t base;
      } u_foot_brake_on;
      u_foot_brake_on.real = this->foot_brake_on;
      *(outbuffer + offset + 0) = (u_foot_brake_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->foot_brake_on);
      union {
        bool real;
        uint8_t base;
      } u_left_brake_on;
      u_left_brake_on.real = this->left_brake_on;
      *(outbuffer + offset + 0) = (u_left_brake_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_brake_on);
      union {
        bool real;
        uint8_t base;
      } u_right_brake_on;
      u_right_brake_on.real = this->right_brake_on;
      *(outbuffer + offset + 0) = (u_right_brake_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_brake_on);
      *(outbuffer + offset + 0) = (this->traction_profile >> (8 * 0)) & 0xFF;
      offset += sizeof(this->traction_profile);
      *(outbuffer + offset + 0) = (this->deck_profile >> (8 * 0)) & 0xFF;
      offset += sizeof(this->deck_profile);
      union {
        bool real;
        uint8_t base;
      } u_charger_door;
      u_charger_door.real = this->charger_door;
      *(outbuffer + offset + 0) = (u_charger_door.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charger_door);
      union {
        bool real;
        uint8_t base;
      } u_charger_loopback_on;
      u_charger_loopback_on.real = this->charger_loopback_on;
      *(outbuffer + offset + 0) = (u_charger_loopback_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charger_loopback_on);
      union {
        bool real;
        uint8_t base;
      } u_seat_switch_on;
      u_seat_switch_on.real = this->seat_switch_on;
      *(outbuffer + offset + 0) = (u_seat_switch_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seat_switch_on);
      union {
        bool real;
        uint8_t base;
      } u_pto_switch_on;
      u_pto_switch_on.real = this->pto_switch_on;
      *(outbuffer + offset + 0) = (u_pto_switch_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pto_switch_on);
      union {
        bool real;
        uint8_t base;
      } u_chute_switch_on;
      u_chute_switch_on.real = this->chute_switch_on;
      *(outbuffer + offset + 0) = (u_chute_switch_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->chute_switch_on);
      union {
        bool real;
        uint8_t base;
      } u_boost_switch_on;
      u_boost_switch_on.real = this->boost_switch_on;
      *(outbuffer + offset + 0) = (u_boost_switch_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->boost_switch_on);
      union {
        bool real;
        uint8_t base;
      } u_creep_switch_on;
      u_creep_switch_on.real = this->creep_switch_on;
      *(outbuffer + offset + 0) = (u_creep_switch_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->creep_switch_on);
      union {
        bool real;
        uint8_t base;
      } u_parking_brake_release_on;
      u_parking_brake_release_on.real = this->parking_brake_release_on;
      *(outbuffer + offset + 0) = (u_parking_brake_release_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->parking_brake_release_on);
      union {
        bool real;
        uint8_t base;
      } u_user_peripheral_1;
      u_user_peripheral_1.real = this->user_peripheral_1;
      *(outbuffer + offset + 0) = (u_user_peripheral_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_peripheral_1);
      union {
        bool real;
        uint8_t base;
      } u_user_peripheral_2;
      u_user_peripheral_2.real = this->user_peripheral_2;
      *(outbuffer + offset + 0) = (u_user_peripheral_2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->user_peripheral_2);
      union {
        bool real;
        uint8_t base;
      } u_autonomous_mode_enable;
      u_autonomous_mode_enable.real = this->autonomous_mode_enable;
      *(outbuffer + offset + 0) = (u_autonomous_mode_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autonomous_mode_enable);
      *(outbuffer + offset + 0) = (this->autonomous_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autonomous_mode);
      union {
        bool real;
        uint8_t base;
      } u_key_switch_on;
      u_key_switch_on.real = this->key_switch_on;
      *(outbuffer + offset + 0) = (u_key_switch_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->key_switch_on);
      *(outbuffer + offset + 0) = (this->system_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->system_state);
      *(outbuffer + offset + 0) = (this->battery_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery_state);
      *(outbuffer + offset + 0) = (this->vehicle_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vehicle_state);
      *(outbuffer + offset + 0) = (this->traction_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->traction_state);
      *(outbuffer + offset + 0) = (this->deck_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->deck_state);
      *(outbuffer + offset + 0) = (this->deck_running_time_min >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->deck_running_time_min >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->deck_running_time_min >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->deck_running_time_min >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deck_running_time_min);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_system_brake_on;
      u_system_brake_on.base = 0;
      u_system_brake_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->system_brake_on = u_system_brake_on.real;
      offset += sizeof(this->system_brake_on);
      union {
        bool real;
        uint8_t base;
      } u_foot_brake_on;
      u_foot_brake_on.base = 0;
      u_foot_brake_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->foot_brake_on = u_foot_brake_on.real;
      offset += sizeof(this->foot_brake_on);
      union {
        bool real;
        uint8_t base;
      } u_left_brake_on;
      u_left_brake_on.base = 0;
      u_left_brake_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_brake_on = u_left_brake_on.real;
      offset += sizeof(this->left_brake_on);
      union {
        bool real;
        uint8_t base;
      } u_right_brake_on;
      u_right_brake_on.base = 0;
      u_right_brake_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_brake_on = u_right_brake_on.real;
      offset += sizeof(this->right_brake_on);
      this->traction_profile =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->traction_profile);
      this->deck_profile =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->deck_profile);
      union {
        bool real;
        uint8_t base;
      } u_charger_door;
      u_charger_door.base = 0;
      u_charger_door.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->charger_door = u_charger_door.real;
      offset += sizeof(this->charger_door);
      union {
        bool real;
        uint8_t base;
      } u_charger_loopback_on;
      u_charger_loopback_on.base = 0;
      u_charger_loopback_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->charger_loopback_on = u_charger_loopback_on.real;
      offset += sizeof(this->charger_loopback_on);
      union {
        bool real;
        uint8_t base;
      } u_seat_switch_on;
      u_seat_switch_on.base = 0;
      u_seat_switch_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->seat_switch_on = u_seat_switch_on.real;
      offset += sizeof(this->seat_switch_on);
      union {
        bool real;
        uint8_t base;
      } u_pto_switch_on;
      u_pto_switch_on.base = 0;
      u_pto_switch_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pto_switch_on = u_pto_switch_on.real;
      offset += sizeof(this->pto_switch_on);
      union {
        bool real;
        uint8_t base;
      } u_chute_switch_on;
      u_chute_switch_on.base = 0;
      u_chute_switch_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->chute_switch_on = u_chute_switch_on.real;
      offset += sizeof(this->chute_switch_on);
      union {
        bool real;
        uint8_t base;
      } u_boost_switch_on;
      u_boost_switch_on.base = 0;
      u_boost_switch_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->boost_switch_on = u_boost_switch_on.real;
      offset += sizeof(this->boost_switch_on);
      union {
        bool real;
        uint8_t base;
      } u_creep_switch_on;
      u_creep_switch_on.base = 0;
      u_creep_switch_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->creep_switch_on = u_creep_switch_on.real;
      offset += sizeof(this->creep_switch_on);
      union {
        bool real;
        uint8_t base;
      } u_parking_brake_release_on;
      u_parking_brake_release_on.base = 0;
      u_parking_brake_release_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->parking_brake_release_on = u_parking_brake_release_on.real;
      offset += sizeof(this->parking_brake_release_on);
      union {
        bool real;
        uint8_t base;
      } u_user_peripheral_1;
      u_user_peripheral_1.base = 0;
      u_user_peripheral_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->user_peripheral_1 = u_user_peripheral_1.real;
      offset += sizeof(this->user_peripheral_1);
      union {
        bool real;
        uint8_t base;
      } u_user_peripheral_2;
      u_user_peripheral_2.base = 0;
      u_user_peripheral_2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->user_peripheral_2 = u_user_peripheral_2.real;
      offset += sizeof(this->user_peripheral_2);
      union {
        bool real;
        uint8_t base;
      } u_autonomous_mode_enable;
      u_autonomous_mode_enable.base = 0;
      u_autonomous_mode_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->autonomous_mode_enable = u_autonomous_mode_enable.real;
      offset += sizeof(this->autonomous_mode_enable);
      this->autonomous_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->autonomous_mode);
      union {
        bool real;
        uint8_t base;
      } u_key_switch_on;
      u_key_switch_on.base = 0;
      u_key_switch_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->key_switch_on = u_key_switch_on.real;
      offset += sizeof(this->key_switch_on);
      this->system_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->system_state);
      this->battery_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->battery_state);
      this->vehicle_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vehicle_state);
      this->traction_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->traction_state);
      this->deck_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->deck_state);
      this->deck_running_time_min =  ((uint32_t) (*(inbuffer + offset)));
      this->deck_running_time_min |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->deck_running_time_min |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->deck_running_time_min |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->deck_running_time_min);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/VCMStatus"; };
    virtual const char * getMD5() override { return "fefb3f1b6b355817e4957fc9ad95cc3a"; };

  };

}
#endif
