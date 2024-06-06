#ifndef _ROS_nova_msgs_Status_h
#define _ROS_nova_msgs_Status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace nova_msgs
{

  class Status : public ros::Msg
  {
    public:
      typedef uint8_t _battery_soc_type;
      _battery_soc_type battery_soc;
      typedef float _battery_voltage_type;
      _battery_voltage_type battery_voltage;
      typedef float _battery_current_type;
      _battery_current_type battery_current;
      typedef bool _battery_interlock_switch_type;
      _battery_interlock_switch_type battery_interlock_switch;
      typedef float _deck_height_inches_command_type;
      _deck_height_inches_command_type deck_height_inches_command;
      typedef float _deck_height_inches_type;
      _deck_height_inches_type deck_height_inches;
      typedef bool _light_command_valid_type;
      _light_command_valid_type light_command_valid;
      typedef bool _light_command_on_type;
      _light_command_on_type light_command_on;
      typedef bool _light_status_type;
      _light_status_type light_status;
      typedef bool _light_status_error_type;
      _light_status_error_type light_status_error;
      typedef bool _lap_bar_type;
      _lap_bar_type lap_bar;
      typedef bool _seat_switch_type;
      _seat_switch_type seat_switch;
      typedef bool _correct_passcode_type;
      _correct_passcode_type correct_passcode;
      typedef bool _drive_speed_type;
      _drive_speed_type drive_speed;
      typedef bool _blade_speed_type;
      _blade_speed_type blade_speed;
      typedef bool _pto_status_type;
      _pto_status_type pto_status;

    Status():
      battery_soc(0),
      battery_voltage(0),
      battery_current(0),
      battery_interlock_switch(0),
      deck_height_inches_command(0),
      deck_height_inches(0),
      light_command_valid(0),
      light_command_on(0),
      light_status(0),
      light_status_error(0),
      lap_bar(0),
      seat_switch(0),
      correct_passcode(0),
      drive_speed(0),
      blade_speed(0),
      pto_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->battery_soc >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery_soc);
      union {
        float real;
        uint32_t base;
      } u_battery_voltage;
      u_battery_voltage.real = this->battery_voltage;
      *(outbuffer + offset + 0) = (u_battery_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_battery_current;
      u_battery_current.real = this->battery_current;
      *(outbuffer + offset + 0) = (u_battery_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_current);
      union {
        bool real;
        uint8_t base;
      } u_battery_interlock_switch;
      u_battery_interlock_switch.real = this->battery_interlock_switch;
      *(outbuffer + offset + 0) = (u_battery_interlock_switch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->battery_interlock_switch);
      union {
        float real;
        uint32_t base;
      } u_deck_height_inches_command;
      u_deck_height_inches_command.real = this->deck_height_inches_command;
      *(outbuffer + offset + 0) = (u_deck_height_inches_command.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deck_height_inches_command.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deck_height_inches_command.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deck_height_inches_command.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deck_height_inches_command);
      union {
        float real;
        uint32_t base;
      } u_deck_height_inches;
      u_deck_height_inches.real = this->deck_height_inches;
      *(outbuffer + offset + 0) = (u_deck_height_inches.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_deck_height_inches.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_deck_height_inches.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_deck_height_inches.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->deck_height_inches);
      union {
        bool real;
        uint8_t base;
      } u_light_command_valid;
      u_light_command_valid.real = this->light_command_valid;
      *(outbuffer + offset + 0) = (u_light_command_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->light_command_valid);
      union {
        bool real;
        uint8_t base;
      } u_light_command_on;
      u_light_command_on.real = this->light_command_on;
      *(outbuffer + offset + 0) = (u_light_command_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->light_command_on);
      union {
        bool real;
        uint8_t base;
      } u_light_status;
      u_light_status.real = this->light_status;
      *(outbuffer + offset + 0) = (u_light_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->light_status);
      union {
        bool real;
        uint8_t base;
      } u_light_status_error;
      u_light_status_error.real = this->light_status_error;
      *(outbuffer + offset + 0) = (u_light_status_error.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->light_status_error);
      union {
        bool real;
        uint8_t base;
      } u_lap_bar;
      u_lap_bar.real = this->lap_bar;
      *(outbuffer + offset + 0) = (u_lap_bar.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->lap_bar);
      union {
        bool real;
        uint8_t base;
      } u_seat_switch;
      u_seat_switch.real = this->seat_switch;
      *(outbuffer + offset + 0) = (u_seat_switch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->seat_switch);
      union {
        bool real;
        uint8_t base;
      } u_correct_passcode;
      u_correct_passcode.real = this->correct_passcode;
      *(outbuffer + offset + 0) = (u_correct_passcode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->correct_passcode);
      union {
        bool real;
        uint8_t base;
      } u_drive_speed;
      u_drive_speed.real = this->drive_speed;
      *(outbuffer + offset + 0) = (u_drive_speed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drive_speed);
      union {
        bool real;
        uint8_t base;
      } u_blade_speed;
      u_blade_speed.real = this->blade_speed;
      *(outbuffer + offset + 0) = (u_blade_speed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->blade_speed);
      union {
        bool real;
        uint8_t base;
      } u_pto_status;
      u_pto_status.real = this->pto_status;
      *(outbuffer + offset + 0) = (u_pto_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pto_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->battery_soc =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->battery_soc);
      union {
        float real;
        uint32_t base;
      } u_battery_voltage;
      u_battery_voltage.base = 0;
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_voltage = u_battery_voltage.real;
      offset += sizeof(this->battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_battery_current;
      u_battery_current.base = 0;
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_current = u_battery_current.real;
      offset += sizeof(this->battery_current);
      union {
        bool real;
        uint8_t base;
      } u_battery_interlock_switch;
      u_battery_interlock_switch.base = 0;
      u_battery_interlock_switch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->battery_interlock_switch = u_battery_interlock_switch.real;
      offset += sizeof(this->battery_interlock_switch);
      union {
        float real;
        uint32_t base;
      } u_deck_height_inches_command;
      u_deck_height_inches_command.base = 0;
      u_deck_height_inches_command.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deck_height_inches_command.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deck_height_inches_command.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deck_height_inches_command.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->deck_height_inches_command = u_deck_height_inches_command.real;
      offset += sizeof(this->deck_height_inches_command);
      union {
        float real;
        uint32_t base;
      } u_deck_height_inches;
      u_deck_height_inches.base = 0;
      u_deck_height_inches.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_deck_height_inches.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_deck_height_inches.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_deck_height_inches.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->deck_height_inches = u_deck_height_inches.real;
      offset += sizeof(this->deck_height_inches);
      union {
        bool real;
        uint8_t base;
      } u_light_command_valid;
      u_light_command_valid.base = 0;
      u_light_command_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->light_command_valid = u_light_command_valid.real;
      offset += sizeof(this->light_command_valid);
      union {
        bool real;
        uint8_t base;
      } u_light_command_on;
      u_light_command_on.base = 0;
      u_light_command_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->light_command_on = u_light_command_on.real;
      offset += sizeof(this->light_command_on);
      union {
        bool real;
        uint8_t base;
      } u_light_status;
      u_light_status.base = 0;
      u_light_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->light_status = u_light_status.real;
      offset += sizeof(this->light_status);
      union {
        bool real;
        uint8_t base;
      } u_light_status_error;
      u_light_status_error.base = 0;
      u_light_status_error.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->light_status_error = u_light_status_error.real;
      offset += sizeof(this->light_status_error);
      union {
        bool real;
        uint8_t base;
      } u_lap_bar;
      u_lap_bar.base = 0;
      u_lap_bar.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->lap_bar = u_lap_bar.real;
      offset += sizeof(this->lap_bar);
      union {
        bool real;
        uint8_t base;
      } u_seat_switch;
      u_seat_switch.base = 0;
      u_seat_switch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->seat_switch = u_seat_switch.real;
      offset += sizeof(this->seat_switch);
      union {
        bool real;
        uint8_t base;
      } u_correct_passcode;
      u_correct_passcode.base = 0;
      u_correct_passcode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->correct_passcode = u_correct_passcode.real;
      offset += sizeof(this->correct_passcode);
      union {
        bool real;
        uint8_t base;
      } u_drive_speed;
      u_drive_speed.base = 0;
      u_drive_speed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->drive_speed = u_drive_speed.real;
      offset += sizeof(this->drive_speed);
      union {
        bool real;
        uint8_t base;
      } u_blade_speed;
      u_blade_speed.base = 0;
      u_blade_speed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->blade_speed = u_blade_speed.real;
      offset += sizeof(this->blade_speed);
      union {
        bool real;
        uint8_t base;
      } u_pto_status;
      u_pto_status.base = 0;
      u_pto_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pto_status = u_pto_status.real;
      offset += sizeof(this->pto_status);
     return offset;
    }

    virtual const char * getType() override { return "nova_msgs/Status"; };
    virtual const char * getMD5() override { return "c627f494b6e9676361b1aa144d46a413"; };

  };

}
#endif
