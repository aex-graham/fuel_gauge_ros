#ifndef _ROS_nova_msgs_HardwareInterfaceStatus_h
#define _ROS_nova_msgs_HardwareInterfaceStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "nova_msgs/HardwareInterfacePortInfo.h"

namespace nova_msgs
{

  class HardwareInterfaceStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _mower_battery_voltage_type;
      _mower_battery_voltage_type mower_battery_voltage;
      typedef float _buck_voltage_type;
      _buck_voltage_type buck_voltage;
      typedef float _buck_current_type;
      _buck_current_type buck_current;
      typedef float _buck_power_type;
      _buck_power_type buck_power;
      typedef float _computer_current_type;
      _computer_current_type computer_current;
      typedef float _computer_power_type;
      _computer_power_type computer_power;
      typedef float _led_current_type;
      _led_current_type led_current;
      typedef float _led_power_type;
      _led_power_type led_power;
      typedef float _usb_voltage_type;
      _usb_voltage_type usb_voltage;
      uint32_t aux_ports_length;
      typedef nova_msgs::HardwareInterfacePortInfo _aux_ports_type;
      _aux_ports_type st_aux_ports;
      _aux_ports_type * aux_ports;
      typedef bool _g_estop_status_type;
      _g_estop_status_type g_estop_status;
      typedef bool _g_auto_ready_status_type;
      _g_auto_ready_status_type g_auto_ready_status;
      typedef bool _ignition_status_type;
      _ignition_status_type ignition_status;
      typedef bool _const_12v_input_status_type;
      _const_12v_input_status_type const_12v_input_status;
      typedef bool _const_5v_output_status_type;
      _const_5v_output_status_type const_5v_output_status;
      typedef bool _L1_output_status_type;
      _L1_output_status_type L1_output_status;
      typedef bool _L2_output_status_type;
      _L2_output_status_type L2_output_status;
      typedef bool _L3_output_status_type;
      _L3_output_status_type L3_output_status;
      typedef float _temp_ambient_type;
      _temp_ambient_type temp_ambient;
      typedef float _temp_chip_type;
      _temp_chip_type temp_chip;
      typedef const char* _L1_color_type;
      _L1_color_type L1_color;
      typedef const char* _L2_color_type;
      _L2_color_type L2_color;
      typedef const char* _L3_color_type;
      _L3_color_type L3_color;

    HardwareInterfaceStatus():
      header(),
      mower_battery_voltage(0),
      buck_voltage(0),
      buck_current(0),
      buck_power(0),
      computer_current(0),
      computer_power(0),
      led_current(0),
      led_power(0),
      usb_voltage(0),
      aux_ports_length(0), st_aux_ports(), aux_ports(nullptr),
      g_estop_status(0),
      g_auto_ready_status(0),
      ignition_status(0),
      const_12v_input_status(0),
      const_5v_output_status(0),
      L1_output_status(0),
      L2_output_status(0),
      L3_output_status(0),
      temp_ambient(0),
      temp_chip(0),
      L1_color(""),
      L2_color(""),
      L3_color("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_mower_battery_voltage;
      u_mower_battery_voltage.real = this->mower_battery_voltage;
      *(outbuffer + offset + 0) = (u_mower_battery_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mower_battery_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mower_battery_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mower_battery_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mower_battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_buck_voltage;
      u_buck_voltage.real = this->buck_voltage;
      *(outbuffer + offset + 0) = (u_buck_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_buck_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_buck_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_buck_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->buck_voltage);
      union {
        float real;
        uint32_t base;
      } u_buck_current;
      u_buck_current.real = this->buck_current;
      *(outbuffer + offset + 0) = (u_buck_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_buck_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_buck_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_buck_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->buck_current);
      union {
        float real;
        uint32_t base;
      } u_buck_power;
      u_buck_power.real = this->buck_power;
      *(outbuffer + offset + 0) = (u_buck_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_buck_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_buck_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_buck_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->buck_power);
      union {
        float real;
        uint32_t base;
      } u_computer_current;
      u_computer_current.real = this->computer_current;
      *(outbuffer + offset + 0) = (u_computer_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_computer_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_computer_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_computer_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->computer_current);
      union {
        float real;
        uint32_t base;
      } u_computer_power;
      u_computer_power.real = this->computer_power;
      *(outbuffer + offset + 0) = (u_computer_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_computer_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_computer_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_computer_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->computer_power);
      union {
        float real;
        uint32_t base;
      } u_led_current;
      u_led_current.real = this->led_current;
      *(outbuffer + offset + 0) = (u_led_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_led_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_led_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_led_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->led_current);
      union {
        float real;
        uint32_t base;
      } u_led_power;
      u_led_power.real = this->led_power;
      *(outbuffer + offset + 0) = (u_led_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_led_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_led_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_led_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->led_power);
      union {
        float real;
        uint32_t base;
      } u_usb_voltage;
      u_usb_voltage.real = this->usb_voltage;
      *(outbuffer + offset + 0) = (u_usb_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_usb_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_usb_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_usb_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->usb_voltage);
      *(outbuffer + offset + 0) = (this->aux_ports_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->aux_ports_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->aux_ports_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->aux_ports_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->aux_ports_length);
      for( uint32_t i = 0; i < aux_ports_length; i++){
      offset += this->aux_ports[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_g_estop_status;
      u_g_estop_status.real = this->g_estop_status;
      *(outbuffer + offset + 0) = (u_g_estop_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->g_estop_status);
      union {
        bool real;
        uint8_t base;
      } u_g_auto_ready_status;
      u_g_auto_ready_status.real = this->g_auto_ready_status;
      *(outbuffer + offset + 0) = (u_g_auto_ready_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->g_auto_ready_status);
      union {
        bool real;
        uint8_t base;
      } u_ignition_status;
      u_ignition_status.real = this->ignition_status;
      *(outbuffer + offset + 0) = (u_ignition_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ignition_status);
      union {
        bool real;
        uint8_t base;
      } u_const_12v_input_status;
      u_const_12v_input_status.real = this->const_12v_input_status;
      *(outbuffer + offset + 0) = (u_const_12v_input_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->const_12v_input_status);
      union {
        bool real;
        uint8_t base;
      } u_const_5v_output_status;
      u_const_5v_output_status.real = this->const_5v_output_status;
      *(outbuffer + offset + 0) = (u_const_5v_output_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->const_5v_output_status);
      union {
        bool real;
        uint8_t base;
      } u_L1_output_status;
      u_L1_output_status.real = this->L1_output_status;
      *(outbuffer + offset + 0) = (u_L1_output_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->L1_output_status);
      union {
        bool real;
        uint8_t base;
      } u_L2_output_status;
      u_L2_output_status.real = this->L2_output_status;
      *(outbuffer + offset + 0) = (u_L2_output_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->L2_output_status);
      union {
        bool real;
        uint8_t base;
      } u_L3_output_status;
      u_L3_output_status.real = this->L3_output_status;
      *(outbuffer + offset + 0) = (u_L3_output_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->L3_output_status);
      union {
        float real;
        uint32_t base;
      } u_temp_ambient;
      u_temp_ambient.real = this->temp_ambient;
      *(outbuffer + offset + 0) = (u_temp_ambient.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp_ambient.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temp_ambient.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temp_ambient.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temp_ambient);
      union {
        float real;
        uint32_t base;
      } u_temp_chip;
      u_temp_chip.real = this->temp_chip;
      *(outbuffer + offset + 0) = (u_temp_chip.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp_chip.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temp_chip.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temp_chip.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temp_chip);
      uint32_t length_L1_color = strlen(this->L1_color);
      varToArr(outbuffer + offset, length_L1_color);
      offset += 4;
      memcpy(outbuffer + offset, this->L1_color, length_L1_color);
      offset += length_L1_color;
      uint32_t length_L2_color = strlen(this->L2_color);
      varToArr(outbuffer + offset, length_L2_color);
      offset += 4;
      memcpy(outbuffer + offset, this->L2_color, length_L2_color);
      offset += length_L2_color;
      uint32_t length_L3_color = strlen(this->L3_color);
      varToArr(outbuffer + offset, length_L3_color);
      offset += 4;
      memcpy(outbuffer + offset, this->L3_color, length_L3_color);
      offset += length_L3_color;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_mower_battery_voltage;
      u_mower_battery_voltage.base = 0;
      u_mower_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mower_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mower_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mower_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->mower_battery_voltage = u_mower_battery_voltage.real;
      offset += sizeof(this->mower_battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_buck_voltage;
      u_buck_voltage.base = 0;
      u_buck_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_buck_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_buck_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_buck_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->buck_voltage = u_buck_voltage.real;
      offset += sizeof(this->buck_voltage);
      union {
        float real;
        uint32_t base;
      } u_buck_current;
      u_buck_current.base = 0;
      u_buck_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_buck_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_buck_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_buck_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->buck_current = u_buck_current.real;
      offset += sizeof(this->buck_current);
      union {
        float real;
        uint32_t base;
      } u_buck_power;
      u_buck_power.base = 0;
      u_buck_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_buck_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_buck_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_buck_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->buck_power = u_buck_power.real;
      offset += sizeof(this->buck_power);
      union {
        float real;
        uint32_t base;
      } u_computer_current;
      u_computer_current.base = 0;
      u_computer_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_computer_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_computer_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_computer_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->computer_current = u_computer_current.real;
      offset += sizeof(this->computer_current);
      union {
        float real;
        uint32_t base;
      } u_computer_power;
      u_computer_power.base = 0;
      u_computer_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_computer_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_computer_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_computer_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->computer_power = u_computer_power.real;
      offset += sizeof(this->computer_power);
      union {
        float real;
        uint32_t base;
      } u_led_current;
      u_led_current.base = 0;
      u_led_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_led_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_led_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_led_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->led_current = u_led_current.real;
      offset += sizeof(this->led_current);
      union {
        float real;
        uint32_t base;
      } u_led_power;
      u_led_power.base = 0;
      u_led_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_led_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_led_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_led_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->led_power = u_led_power.real;
      offset += sizeof(this->led_power);
      union {
        float real;
        uint32_t base;
      } u_usb_voltage;
      u_usb_voltage.base = 0;
      u_usb_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_usb_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_usb_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_usb_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->usb_voltage = u_usb_voltage.real;
      offset += sizeof(this->usb_voltage);
      uint32_t aux_ports_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      aux_ports_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      aux_ports_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      aux_ports_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->aux_ports_length);
      if(aux_ports_lengthT > aux_ports_length)
        this->aux_ports = (nova_msgs::HardwareInterfacePortInfo*)realloc(this->aux_ports, aux_ports_lengthT * sizeof(nova_msgs::HardwareInterfacePortInfo));
      aux_ports_length = aux_ports_lengthT;
      for( uint32_t i = 0; i < aux_ports_length; i++){
      offset += this->st_aux_ports.deserialize(inbuffer + offset);
        memcpy( &(this->aux_ports[i]), &(this->st_aux_ports), sizeof(nova_msgs::HardwareInterfacePortInfo));
      }
      union {
        bool real;
        uint8_t base;
      } u_g_estop_status;
      u_g_estop_status.base = 0;
      u_g_estop_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->g_estop_status = u_g_estop_status.real;
      offset += sizeof(this->g_estop_status);
      union {
        bool real;
        uint8_t base;
      } u_g_auto_ready_status;
      u_g_auto_ready_status.base = 0;
      u_g_auto_ready_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->g_auto_ready_status = u_g_auto_ready_status.real;
      offset += sizeof(this->g_auto_ready_status);
      union {
        bool real;
        uint8_t base;
      } u_ignition_status;
      u_ignition_status.base = 0;
      u_ignition_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ignition_status = u_ignition_status.real;
      offset += sizeof(this->ignition_status);
      union {
        bool real;
        uint8_t base;
      } u_const_12v_input_status;
      u_const_12v_input_status.base = 0;
      u_const_12v_input_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->const_12v_input_status = u_const_12v_input_status.real;
      offset += sizeof(this->const_12v_input_status);
      union {
        bool real;
        uint8_t base;
      } u_const_5v_output_status;
      u_const_5v_output_status.base = 0;
      u_const_5v_output_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->const_5v_output_status = u_const_5v_output_status.real;
      offset += sizeof(this->const_5v_output_status);
      union {
        bool real;
        uint8_t base;
      } u_L1_output_status;
      u_L1_output_status.base = 0;
      u_L1_output_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->L1_output_status = u_L1_output_status.real;
      offset += sizeof(this->L1_output_status);
      union {
        bool real;
        uint8_t base;
      } u_L2_output_status;
      u_L2_output_status.base = 0;
      u_L2_output_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->L2_output_status = u_L2_output_status.real;
      offset += sizeof(this->L2_output_status);
      union {
        bool real;
        uint8_t base;
      } u_L3_output_status;
      u_L3_output_status.base = 0;
      u_L3_output_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->L3_output_status = u_L3_output_status.real;
      offset += sizeof(this->L3_output_status);
      union {
        float real;
        uint32_t base;
      } u_temp_ambient;
      u_temp_ambient.base = 0;
      u_temp_ambient.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp_ambient.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temp_ambient.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temp_ambient.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temp_ambient = u_temp_ambient.real;
      offset += sizeof(this->temp_ambient);
      union {
        float real;
        uint32_t base;
      } u_temp_chip;
      u_temp_chip.base = 0;
      u_temp_chip.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp_chip.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temp_chip.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temp_chip.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temp_chip = u_temp_chip.real;
      offset += sizeof(this->temp_chip);
      uint32_t length_L1_color;
      arrToVar(length_L1_color, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_L1_color; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_L1_color-1]=0;
      this->L1_color = (char *)(inbuffer + offset-1);
      offset += length_L1_color;
      uint32_t length_L2_color;
      arrToVar(length_L2_color, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_L2_color; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_L2_color-1]=0;
      this->L2_color = (char *)(inbuffer + offset-1);
      offset += length_L2_color;
      uint32_t length_L3_color;
      arrToVar(length_L3_color, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_L3_color; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_L3_color-1]=0;
      this->L3_color = (char *)(inbuffer + offset-1);
      offset += length_L3_color;
     return offset;
    }

    virtual const char * getType() override { return "nova_msgs/HardwareInterfaceStatus"; };
    virtual const char * getMD5() override { return "ab7490945f2c8f99cede6200f2a02637"; };

  };

}
#endif
