#ifndef _ROS_greenzie_msgs_VehicleStatus_h
#define _ROS_greenzie_msgs_VehicleStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class VehicleStatus : public ros::Msg
  {
    public:
      typedef bool _connected_type;
      _connected_type connected;
      typedef bool _engine_running_type;
      _engine_running_type engine_running;
      typedef uint32_t _tachometer_type;
      _tachometer_type tachometer;
      typedef float _battery_voltage_type;
      _battery_voltage_type battery_voltage;
      typedef bool _blades_commanded_type;
      _blades_commanded_type blades_commanded;
      typedef bool _blades_enabled_type;
      _blades_enabled_type blades_enabled;
      typedef bool _control_enabled_type;
      _control_enabled_type control_enabled;
      typedef bool _wheel_control_enabled_type;
      _wheel_control_enabled_type wheel_control_enabled;
      typedef bool _vehicle_estop_triggered_type;
      _vehicle_estop_triggered_type vehicle_estop_triggered;
      typedef bool _remote_estop_triggered_type;
      _remote_estop_triggered_type remote_estop_triggered;
      typedef bool _powerup_enabled_type;
      _powerup_enabled_type powerup_enabled;
      typedef bool _brake_engaged_type;
      _brake_engaged_type brake_engaged;
      typedef bool _operator_present_type;
      _operator_present_type operator_present;
      typedef bool _auto_ready_type;
      _auto_ready_type auto_ready;

    VehicleStatus():
      connected(0),
      engine_running(0),
      tachometer(0),
      battery_voltage(0),
      blades_commanded(0),
      blades_enabled(0),
      control_enabled(0),
      wheel_control_enabled(0),
      vehicle_estop_triggered(0),
      remote_estop_triggered(0),
      powerup_enabled(0),
      brake_engaged(0),
      operator_present(0),
      auto_ready(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_connected;
      u_connected.real = this->connected;
      *(outbuffer + offset + 0) = (u_connected.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->connected);
      union {
        bool real;
        uint8_t base;
      } u_engine_running;
      u_engine_running.real = this->engine_running;
      *(outbuffer + offset + 0) = (u_engine_running.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_running);
      *(outbuffer + offset + 0) = (this->tachometer >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tachometer >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tachometer >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tachometer >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tachometer);
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
        bool real;
        uint8_t base;
      } u_blades_commanded;
      u_blades_commanded.real = this->blades_commanded;
      *(outbuffer + offset + 0) = (u_blades_commanded.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->blades_commanded);
      union {
        bool real;
        uint8_t base;
      } u_blades_enabled;
      u_blades_enabled.real = this->blades_enabled;
      *(outbuffer + offset + 0) = (u_blades_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->blades_enabled);
      union {
        bool real;
        uint8_t base;
      } u_control_enabled;
      u_control_enabled.real = this->control_enabled;
      *(outbuffer + offset + 0) = (u_control_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->control_enabled);
      union {
        bool real;
        uint8_t base;
      } u_wheel_control_enabled;
      u_wheel_control_enabled.real = this->wheel_control_enabled;
      *(outbuffer + offset + 0) = (u_wheel_control_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wheel_control_enabled);
      union {
        bool real;
        uint8_t base;
      } u_vehicle_estop_triggered;
      u_vehicle_estop_triggered.real = this->vehicle_estop_triggered;
      *(outbuffer + offset + 0) = (u_vehicle_estop_triggered.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vehicle_estop_triggered);
      union {
        bool real;
        uint8_t base;
      } u_remote_estop_triggered;
      u_remote_estop_triggered.real = this->remote_estop_triggered;
      *(outbuffer + offset + 0) = (u_remote_estop_triggered.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->remote_estop_triggered);
      union {
        bool real;
        uint8_t base;
      } u_powerup_enabled;
      u_powerup_enabled.real = this->powerup_enabled;
      *(outbuffer + offset + 0) = (u_powerup_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->powerup_enabled);
      union {
        bool real;
        uint8_t base;
      } u_brake_engaged;
      u_brake_engaged.real = this->brake_engaged;
      *(outbuffer + offset + 0) = (u_brake_engaged.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_engaged);
      union {
        bool real;
        uint8_t base;
      } u_operator_present;
      u_operator_present.real = this->operator_present;
      *(outbuffer + offset + 0) = (u_operator_present.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operator_present);
      union {
        bool real;
        uint8_t base;
      } u_auto_ready;
      u_auto_ready.real = this->auto_ready;
      *(outbuffer + offset + 0) = (u_auto_ready.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_ready);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_connected;
      u_connected.base = 0;
      u_connected.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->connected = u_connected.real;
      offset += sizeof(this->connected);
      union {
        bool real;
        uint8_t base;
      } u_engine_running;
      u_engine_running.base = 0;
      u_engine_running.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_running = u_engine_running.real;
      offset += sizeof(this->engine_running);
      this->tachometer =  ((uint32_t) (*(inbuffer + offset)));
      this->tachometer |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tachometer |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tachometer |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tachometer);
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
        bool real;
        uint8_t base;
      } u_blades_commanded;
      u_blades_commanded.base = 0;
      u_blades_commanded.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->blades_commanded = u_blades_commanded.real;
      offset += sizeof(this->blades_commanded);
      union {
        bool real;
        uint8_t base;
      } u_blades_enabled;
      u_blades_enabled.base = 0;
      u_blades_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->blades_enabled = u_blades_enabled.real;
      offset += sizeof(this->blades_enabled);
      union {
        bool real;
        uint8_t base;
      } u_control_enabled;
      u_control_enabled.base = 0;
      u_control_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->control_enabled = u_control_enabled.real;
      offset += sizeof(this->control_enabled);
      union {
        bool real;
        uint8_t base;
      } u_wheel_control_enabled;
      u_wheel_control_enabled.base = 0;
      u_wheel_control_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wheel_control_enabled = u_wheel_control_enabled.real;
      offset += sizeof(this->wheel_control_enabled);
      union {
        bool real;
        uint8_t base;
      } u_vehicle_estop_triggered;
      u_vehicle_estop_triggered.base = 0;
      u_vehicle_estop_triggered.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->vehicle_estop_triggered = u_vehicle_estop_triggered.real;
      offset += sizeof(this->vehicle_estop_triggered);
      union {
        bool real;
        uint8_t base;
      } u_remote_estop_triggered;
      u_remote_estop_triggered.base = 0;
      u_remote_estop_triggered.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->remote_estop_triggered = u_remote_estop_triggered.real;
      offset += sizeof(this->remote_estop_triggered);
      union {
        bool real;
        uint8_t base;
      } u_powerup_enabled;
      u_powerup_enabled.base = 0;
      u_powerup_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->powerup_enabled = u_powerup_enabled.real;
      offset += sizeof(this->powerup_enabled);
      union {
        bool real;
        uint8_t base;
      } u_brake_engaged;
      u_brake_engaged.base = 0;
      u_brake_engaged.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_engaged = u_brake_engaged.real;
      offset += sizeof(this->brake_engaged);
      union {
        bool real;
        uint8_t base;
      } u_operator_present;
      u_operator_present.base = 0;
      u_operator_present.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operator_present = u_operator_present.real;
      offset += sizeof(this->operator_present);
      union {
        bool real;
        uint8_t base;
      } u_auto_ready;
      u_auto_ready.base = 0;
      u_auto_ready.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auto_ready = u_auto_ready.real;
      offset += sizeof(this->auto_ready);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/VehicleStatus"; };
    virtual const char * getMD5() override { return "538bf019fa004ec0f7180857c3ea6280"; };

  };

}
#endif
