#ifndef _ROS_beagle_msgs_BeagleBatterySTATUS_h
#define _ROS_beagle_msgs_BeagleBatterySTATUS_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatterySTATUS : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _run_mode_type;
      _run_mode_type run_mode;
      typedef bool _ready_status_type;
      _ready_status_type ready_status;
      typedef bool _normal_status_type;
      _normal_status_type normal_status;
      typedef bool _finish_status_type;
      _finish_status_type finish_status;
      typedef bool _protect_status_type;
      _protect_status_type protect_status;
      typedef bool _low_voltage_protect_type;
      _low_voltage_protect_type low_voltage_protect;
      typedef bool _temperature_protect_type;
      _temperature_protect_type temperature_protect;
      typedef bool _current_protect_type;
      _current_protect_type current_protect;
      typedef bool _zero_current_protect_type;
      _zero_current_protect_type zero_current_protect;
      typedef bool _over_voltage_protect_type;
      _over_voltage_protect_type over_voltage_protect;
      typedef bool _maintenance_voltage_protect_type;
      _maintenance_voltage_protect_type maintenance_voltage_protect;
      typedef bool _balance_protect_type;
      _balance_protect_type balance_protect;
      typedef bool _charger_not_match_protect_type;
      _charger_not_match_protect_type charger_not_match_protect;
      typedef bool _no_can_msg_enable_type;
      _no_can_msg_enable_type no_can_msg_enable;
      typedef bool _contactor_issue_protect_type;
      _contactor_issue_protect_type contactor_issue_protect;
      typedef bool _estop_protect_type;
      _estop_protect_type estop_protect;
      typedef bool _start_voltage_protect_type;
      _start_voltage_protect_type start_voltage_protect;
      typedef bool _afe_comm_protect_type;
      _afe_comm_protect_type afe_comm_protect;
      typedef bool _bus_voltage_protect_type;
      _bus_voltage_protect_type bus_voltage_protect;
      typedef bool _power_limit_protect_type;
      _power_limit_protect_type power_limit_protect;
      typedef bool _permanent_fault_type;
      _permanent_fault_type permanent_fault;
      typedef bool _low_voltage_alarm_type;
      _low_voltage_alarm_type low_voltage_alarm;
      typedef bool _temperature_alarm_type;
      _temperature_alarm_type temperature_alarm;
      typedef bool _current_alarm_type;
      _current_alarm_type current_alarm;
      typedef bool _zero_current_alarm_type;
      _zero_current_alarm_type zero_current_alarm;
      typedef bool _over_voltage_alarm_type;
      _over_voltage_alarm_type over_voltage_alarm;
      typedef bool _maintenance_voltage_alarm_type;
      _maintenance_voltage_alarm_type maintenance_voltage_alarm;
      typedef bool _balance_alarm_type;
      _balance_alarm_type balance_alarm;
      typedef bool _charger_not_match_alarm_type;
      _charger_not_match_alarm_type charger_not_match_alarm;
      typedef bool _can_msg_alarm_type;
      _can_msg_alarm_type can_msg_alarm;
      typedef bool _contactor_alarm_type;
      _contactor_alarm_type contactor_alarm;
      typedef bool _estop_alarm_type;
      _estop_alarm_type estop_alarm;
      typedef bool _start_voltage_alarm_type;
      _start_voltage_alarm_type start_voltage_alarm;
      typedef bool _afe_comm_alarm_type;
      _afe_comm_alarm_type afe_comm_alarm;
      typedef bool _bus_voltage_match_alarm_type;
      _bus_voltage_match_alarm_type bus_voltage_match_alarm;
      typedef bool _power_limit_alarm_type;
      _power_limit_alarm_type power_limit_alarm;
      typedef uint8_t _bms_multiple_address_type;
      _bms_multiple_address_type bms_multiple_address;
      typedef uint8_t _charger_status_type;
      _charger_status_type charger_status;

    BeagleBatterySTATUS():
      header(),
      run_mode(0),
      ready_status(0),
      normal_status(0),
      finish_status(0),
      protect_status(0),
      low_voltage_protect(0),
      temperature_protect(0),
      current_protect(0),
      zero_current_protect(0),
      over_voltage_protect(0),
      maintenance_voltage_protect(0),
      balance_protect(0),
      charger_not_match_protect(0),
      no_can_msg_enable(0),
      contactor_issue_protect(0),
      estop_protect(0),
      start_voltage_protect(0),
      afe_comm_protect(0),
      bus_voltage_protect(0),
      power_limit_protect(0),
      permanent_fault(0),
      low_voltage_alarm(0),
      temperature_alarm(0),
      current_alarm(0),
      zero_current_alarm(0),
      over_voltage_alarm(0),
      maintenance_voltage_alarm(0),
      balance_alarm(0),
      charger_not_match_alarm(0),
      can_msg_alarm(0),
      contactor_alarm(0),
      estop_alarm(0),
      start_voltage_alarm(0),
      afe_comm_alarm(0),
      bus_voltage_match_alarm(0),
      power_limit_alarm(0),
      bms_multiple_address(0),
      charger_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->run_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->run_mode);
      union {
        bool real;
        uint8_t base;
      } u_ready_status;
      u_ready_status.real = this->ready_status;
      *(outbuffer + offset + 0) = (u_ready_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ready_status);
      union {
        bool real;
        uint8_t base;
      } u_normal_status;
      u_normal_status.real = this->normal_status;
      *(outbuffer + offset + 0) = (u_normal_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->normal_status);
      union {
        bool real;
        uint8_t base;
      } u_finish_status;
      u_finish_status.real = this->finish_status;
      *(outbuffer + offset + 0) = (u_finish_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->finish_status);
      union {
        bool real;
        uint8_t base;
      } u_protect_status;
      u_protect_status.real = this->protect_status;
      *(outbuffer + offset + 0) = (u_protect_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->protect_status);
      union {
        bool real;
        uint8_t base;
      } u_low_voltage_protect;
      u_low_voltage_protect.real = this->low_voltage_protect;
      *(outbuffer + offset + 0) = (u_low_voltage_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->low_voltage_protect);
      union {
        bool real;
        uint8_t base;
      } u_temperature_protect;
      u_temperature_protect.real = this->temperature_protect;
      *(outbuffer + offset + 0) = (u_temperature_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temperature_protect);
      union {
        bool real;
        uint8_t base;
      } u_current_protect;
      u_current_protect.real = this->current_protect;
      *(outbuffer + offset + 0) = (u_current_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_protect);
      union {
        bool real;
        uint8_t base;
      } u_zero_current_protect;
      u_zero_current_protect.real = this->zero_current_protect;
      *(outbuffer + offset + 0) = (u_zero_current_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->zero_current_protect);
      union {
        bool real;
        uint8_t base;
      } u_over_voltage_protect;
      u_over_voltage_protect.real = this->over_voltage_protect;
      *(outbuffer + offset + 0) = (u_over_voltage_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->over_voltage_protect);
      union {
        bool real;
        uint8_t base;
      } u_maintenance_voltage_protect;
      u_maintenance_voltage_protect.real = this->maintenance_voltage_protect;
      *(outbuffer + offset + 0) = (u_maintenance_voltage_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->maintenance_voltage_protect);
      union {
        bool real;
        uint8_t base;
      } u_balance_protect;
      u_balance_protect.real = this->balance_protect;
      *(outbuffer + offset + 0) = (u_balance_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->balance_protect);
      union {
        bool real;
        uint8_t base;
      } u_charger_not_match_protect;
      u_charger_not_match_protect.real = this->charger_not_match_protect;
      *(outbuffer + offset + 0) = (u_charger_not_match_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charger_not_match_protect);
      union {
        bool real;
        uint8_t base;
      } u_no_can_msg_enable;
      u_no_can_msg_enable.real = this->no_can_msg_enable;
      *(outbuffer + offset + 0) = (u_no_can_msg_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->no_can_msg_enable);
      union {
        bool real;
        uint8_t base;
      } u_contactor_issue_protect;
      u_contactor_issue_protect.real = this->contactor_issue_protect;
      *(outbuffer + offset + 0) = (u_contactor_issue_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contactor_issue_protect);
      union {
        bool real;
        uint8_t base;
      } u_estop_protect;
      u_estop_protect.real = this->estop_protect;
      *(outbuffer + offset + 0) = (u_estop_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->estop_protect);
      union {
        bool real;
        uint8_t base;
      } u_start_voltage_protect;
      u_start_voltage_protect.real = this->start_voltage_protect;
      *(outbuffer + offset + 0) = (u_start_voltage_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->start_voltage_protect);
      union {
        bool real;
        uint8_t base;
      } u_afe_comm_protect;
      u_afe_comm_protect.real = this->afe_comm_protect;
      *(outbuffer + offset + 0) = (u_afe_comm_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->afe_comm_protect);
      union {
        bool real;
        uint8_t base;
      } u_bus_voltage_protect;
      u_bus_voltage_protect.real = this->bus_voltage_protect;
      *(outbuffer + offset + 0) = (u_bus_voltage_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bus_voltage_protect);
      union {
        bool real;
        uint8_t base;
      } u_power_limit_protect;
      u_power_limit_protect.real = this->power_limit_protect;
      *(outbuffer + offset + 0) = (u_power_limit_protect.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power_limit_protect);
      union {
        bool real;
        uint8_t base;
      } u_permanent_fault;
      u_permanent_fault.real = this->permanent_fault;
      *(outbuffer + offset + 0) = (u_permanent_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->permanent_fault);
      union {
        bool real;
        uint8_t base;
      } u_low_voltage_alarm;
      u_low_voltage_alarm.real = this->low_voltage_alarm;
      *(outbuffer + offset + 0) = (u_low_voltage_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->low_voltage_alarm);
      union {
        bool real;
        uint8_t base;
      } u_temperature_alarm;
      u_temperature_alarm.real = this->temperature_alarm;
      *(outbuffer + offset + 0) = (u_temperature_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temperature_alarm);
      union {
        bool real;
        uint8_t base;
      } u_current_alarm;
      u_current_alarm.real = this->current_alarm;
      *(outbuffer + offset + 0) = (u_current_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->current_alarm);
      union {
        bool real;
        uint8_t base;
      } u_zero_current_alarm;
      u_zero_current_alarm.real = this->zero_current_alarm;
      *(outbuffer + offset + 0) = (u_zero_current_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->zero_current_alarm);
      union {
        bool real;
        uint8_t base;
      } u_over_voltage_alarm;
      u_over_voltage_alarm.real = this->over_voltage_alarm;
      *(outbuffer + offset + 0) = (u_over_voltage_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->over_voltage_alarm);
      union {
        bool real;
        uint8_t base;
      } u_maintenance_voltage_alarm;
      u_maintenance_voltage_alarm.real = this->maintenance_voltage_alarm;
      *(outbuffer + offset + 0) = (u_maintenance_voltage_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->maintenance_voltage_alarm);
      union {
        bool real;
        uint8_t base;
      } u_balance_alarm;
      u_balance_alarm.real = this->balance_alarm;
      *(outbuffer + offset + 0) = (u_balance_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->balance_alarm);
      union {
        bool real;
        uint8_t base;
      } u_charger_not_match_alarm;
      u_charger_not_match_alarm.real = this->charger_not_match_alarm;
      *(outbuffer + offset + 0) = (u_charger_not_match_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charger_not_match_alarm);
      union {
        bool real;
        uint8_t base;
      } u_can_msg_alarm;
      u_can_msg_alarm.real = this->can_msg_alarm;
      *(outbuffer + offset + 0) = (u_can_msg_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->can_msg_alarm);
      union {
        bool real;
        uint8_t base;
      } u_contactor_alarm;
      u_contactor_alarm.real = this->contactor_alarm;
      *(outbuffer + offset + 0) = (u_contactor_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contactor_alarm);
      union {
        bool real;
        uint8_t base;
      } u_estop_alarm;
      u_estop_alarm.real = this->estop_alarm;
      *(outbuffer + offset + 0) = (u_estop_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->estop_alarm);
      union {
        bool real;
        uint8_t base;
      } u_start_voltage_alarm;
      u_start_voltage_alarm.real = this->start_voltage_alarm;
      *(outbuffer + offset + 0) = (u_start_voltage_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->start_voltage_alarm);
      union {
        bool real;
        uint8_t base;
      } u_afe_comm_alarm;
      u_afe_comm_alarm.real = this->afe_comm_alarm;
      *(outbuffer + offset + 0) = (u_afe_comm_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->afe_comm_alarm);
      union {
        bool real;
        uint8_t base;
      } u_bus_voltage_match_alarm;
      u_bus_voltage_match_alarm.real = this->bus_voltage_match_alarm;
      *(outbuffer + offset + 0) = (u_bus_voltage_match_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bus_voltage_match_alarm);
      union {
        bool real;
        uint8_t base;
      } u_power_limit_alarm;
      u_power_limit_alarm.real = this->power_limit_alarm;
      *(outbuffer + offset + 0) = (u_power_limit_alarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->power_limit_alarm);
      *(outbuffer + offset + 0) = (this->bms_multiple_address >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bms_multiple_address);
      *(outbuffer + offset + 0) = (this->charger_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charger_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->run_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->run_mode);
      union {
        bool real;
        uint8_t base;
      } u_ready_status;
      u_ready_status.base = 0;
      u_ready_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ready_status = u_ready_status.real;
      offset += sizeof(this->ready_status);
      union {
        bool real;
        uint8_t base;
      } u_normal_status;
      u_normal_status.base = 0;
      u_normal_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->normal_status = u_normal_status.real;
      offset += sizeof(this->normal_status);
      union {
        bool real;
        uint8_t base;
      } u_finish_status;
      u_finish_status.base = 0;
      u_finish_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->finish_status = u_finish_status.real;
      offset += sizeof(this->finish_status);
      union {
        bool real;
        uint8_t base;
      } u_protect_status;
      u_protect_status.base = 0;
      u_protect_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->protect_status = u_protect_status.real;
      offset += sizeof(this->protect_status);
      union {
        bool real;
        uint8_t base;
      } u_low_voltage_protect;
      u_low_voltage_protect.base = 0;
      u_low_voltage_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->low_voltage_protect = u_low_voltage_protect.real;
      offset += sizeof(this->low_voltage_protect);
      union {
        bool real;
        uint8_t base;
      } u_temperature_protect;
      u_temperature_protect.base = 0;
      u_temperature_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->temperature_protect = u_temperature_protect.real;
      offset += sizeof(this->temperature_protect);
      union {
        bool real;
        uint8_t base;
      } u_current_protect;
      u_current_protect.base = 0;
      u_current_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->current_protect = u_current_protect.real;
      offset += sizeof(this->current_protect);
      union {
        bool real;
        uint8_t base;
      } u_zero_current_protect;
      u_zero_current_protect.base = 0;
      u_zero_current_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->zero_current_protect = u_zero_current_protect.real;
      offset += sizeof(this->zero_current_protect);
      union {
        bool real;
        uint8_t base;
      } u_over_voltage_protect;
      u_over_voltage_protect.base = 0;
      u_over_voltage_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->over_voltage_protect = u_over_voltage_protect.real;
      offset += sizeof(this->over_voltage_protect);
      union {
        bool real;
        uint8_t base;
      } u_maintenance_voltage_protect;
      u_maintenance_voltage_protect.base = 0;
      u_maintenance_voltage_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->maintenance_voltage_protect = u_maintenance_voltage_protect.real;
      offset += sizeof(this->maintenance_voltage_protect);
      union {
        bool real;
        uint8_t base;
      } u_balance_protect;
      u_balance_protect.base = 0;
      u_balance_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->balance_protect = u_balance_protect.real;
      offset += sizeof(this->balance_protect);
      union {
        bool real;
        uint8_t base;
      } u_charger_not_match_protect;
      u_charger_not_match_protect.base = 0;
      u_charger_not_match_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->charger_not_match_protect = u_charger_not_match_protect.real;
      offset += sizeof(this->charger_not_match_protect);
      union {
        bool real;
        uint8_t base;
      } u_no_can_msg_enable;
      u_no_can_msg_enable.base = 0;
      u_no_can_msg_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->no_can_msg_enable = u_no_can_msg_enable.real;
      offset += sizeof(this->no_can_msg_enable);
      union {
        bool real;
        uint8_t base;
      } u_contactor_issue_protect;
      u_contactor_issue_protect.base = 0;
      u_contactor_issue_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contactor_issue_protect = u_contactor_issue_protect.real;
      offset += sizeof(this->contactor_issue_protect);
      union {
        bool real;
        uint8_t base;
      } u_estop_protect;
      u_estop_protect.base = 0;
      u_estop_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->estop_protect = u_estop_protect.real;
      offset += sizeof(this->estop_protect);
      union {
        bool real;
        uint8_t base;
      } u_start_voltage_protect;
      u_start_voltage_protect.base = 0;
      u_start_voltage_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->start_voltage_protect = u_start_voltage_protect.real;
      offset += sizeof(this->start_voltage_protect);
      union {
        bool real;
        uint8_t base;
      } u_afe_comm_protect;
      u_afe_comm_protect.base = 0;
      u_afe_comm_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->afe_comm_protect = u_afe_comm_protect.real;
      offset += sizeof(this->afe_comm_protect);
      union {
        bool real;
        uint8_t base;
      } u_bus_voltage_protect;
      u_bus_voltage_protect.base = 0;
      u_bus_voltage_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->bus_voltage_protect = u_bus_voltage_protect.real;
      offset += sizeof(this->bus_voltage_protect);
      union {
        bool real;
        uint8_t base;
      } u_power_limit_protect;
      u_power_limit_protect.base = 0;
      u_power_limit_protect.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->power_limit_protect = u_power_limit_protect.real;
      offset += sizeof(this->power_limit_protect);
      union {
        bool real;
        uint8_t base;
      } u_permanent_fault;
      u_permanent_fault.base = 0;
      u_permanent_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->permanent_fault = u_permanent_fault.real;
      offset += sizeof(this->permanent_fault);
      union {
        bool real;
        uint8_t base;
      } u_low_voltage_alarm;
      u_low_voltage_alarm.base = 0;
      u_low_voltage_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->low_voltage_alarm = u_low_voltage_alarm.real;
      offset += sizeof(this->low_voltage_alarm);
      union {
        bool real;
        uint8_t base;
      } u_temperature_alarm;
      u_temperature_alarm.base = 0;
      u_temperature_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->temperature_alarm = u_temperature_alarm.real;
      offset += sizeof(this->temperature_alarm);
      union {
        bool real;
        uint8_t base;
      } u_current_alarm;
      u_current_alarm.base = 0;
      u_current_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->current_alarm = u_current_alarm.real;
      offset += sizeof(this->current_alarm);
      union {
        bool real;
        uint8_t base;
      } u_zero_current_alarm;
      u_zero_current_alarm.base = 0;
      u_zero_current_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->zero_current_alarm = u_zero_current_alarm.real;
      offset += sizeof(this->zero_current_alarm);
      union {
        bool real;
        uint8_t base;
      } u_over_voltage_alarm;
      u_over_voltage_alarm.base = 0;
      u_over_voltage_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->over_voltage_alarm = u_over_voltage_alarm.real;
      offset += sizeof(this->over_voltage_alarm);
      union {
        bool real;
        uint8_t base;
      } u_maintenance_voltage_alarm;
      u_maintenance_voltage_alarm.base = 0;
      u_maintenance_voltage_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->maintenance_voltage_alarm = u_maintenance_voltage_alarm.real;
      offset += sizeof(this->maintenance_voltage_alarm);
      union {
        bool real;
        uint8_t base;
      } u_balance_alarm;
      u_balance_alarm.base = 0;
      u_balance_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->balance_alarm = u_balance_alarm.real;
      offset += sizeof(this->balance_alarm);
      union {
        bool real;
        uint8_t base;
      } u_charger_not_match_alarm;
      u_charger_not_match_alarm.base = 0;
      u_charger_not_match_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->charger_not_match_alarm = u_charger_not_match_alarm.real;
      offset += sizeof(this->charger_not_match_alarm);
      union {
        bool real;
        uint8_t base;
      } u_can_msg_alarm;
      u_can_msg_alarm.base = 0;
      u_can_msg_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->can_msg_alarm = u_can_msg_alarm.real;
      offset += sizeof(this->can_msg_alarm);
      union {
        bool real;
        uint8_t base;
      } u_contactor_alarm;
      u_contactor_alarm.base = 0;
      u_contactor_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contactor_alarm = u_contactor_alarm.real;
      offset += sizeof(this->contactor_alarm);
      union {
        bool real;
        uint8_t base;
      } u_estop_alarm;
      u_estop_alarm.base = 0;
      u_estop_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->estop_alarm = u_estop_alarm.real;
      offset += sizeof(this->estop_alarm);
      union {
        bool real;
        uint8_t base;
      } u_start_voltage_alarm;
      u_start_voltage_alarm.base = 0;
      u_start_voltage_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->start_voltage_alarm = u_start_voltage_alarm.real;
      offset += sizeof(this->start_voltage_alarm);
      union {
        bool real;
        uint8_t base;
      } u_afe_comm_alarm;
      u_afe_comm_alarm.base = 0;
      u_afe_comm_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->afe_comm_alarm = u_afe_comm_alarm.real;
      offset += sizeof(this->afe_comm_alarm);
      union {
        bool real;
        uint8_t base;
      } u_bus_voltage_match_alarm;
      u_bus_voltage_match_alarm.base = 0;
      u_bus_voltage_match_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->bus_voltage_match_alarm = u_bus_voltage_match_alarm.real;
      offset += sizeof(this->bus_voltage_match_alarm);
      union {
        bool real;
        uint8_t base;
      } u_power_limit_alarm;
      u_power_limit_alarm.base = 0;
      u_power_limit_alarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->power_limit_alarm = u_power_limit_alarm.real;
      offset += sizeof(this->power_limit_alarm);
      this->bms_multiple_address =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->bms_multiple_address);
      this->charger_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->charger_status);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatterySTATUS"; };
    virtual const char * getMD5() override { return "806a1ab298c5ae6715187cbaf0aecebe"; };

  };

}
#endif
