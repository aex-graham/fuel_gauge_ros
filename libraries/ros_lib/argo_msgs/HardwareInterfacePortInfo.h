#ifndef _ROS_argo_msgs_HardwareInterfacePortInfo_h
#define _ROS_argo_msgs_HardwareInterfacePortInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace argo_msgs
{

  class HardwareInterfacePortInfo : public ros::Msg
  {
    public:
      typedef uint8_t _id_type;
      _id_type id;
      typedef const char* _device_name_type;
      _device_name_type device_name;
      typedef bool _requested_status_type;
      _requested_status_type requested_status;
      typedef bool _output_status_type;
      _output_status_type output_status;
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef float _current_type;
      _current_type current;
      typedef float _power_type;
      _power_type power;

    HardwareInterfacePortInfo():
      id(0),
      device_name(""),
      requested_status(0),
      output_status(0),
      voltage(0),
      current(0),
      power(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      uint32_t length_device_name = strlen(this->device_name);
      varToArr(outbuffer + offset, length_device_name);
      offset += 4;
      memcpy(outbuffer + offset, this->device_name, length_device_name);
      offset += length_device_name;
      union {
        bool real;
        uint8_t base;
      } u_requested_status;
      u_requested_status.real = this->requested_status;
      *(outbuffer + offset + 0) = (u_requested_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->requested_status);
      union {
        bool real;
        uint8_t base;
      } u_output_status;
      u_output_status.real = this->output_status;
      *(outbuffer + offset + 0) = (u_output_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->output_status);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.real = this->current;
      *(outbuffer + offset + 0) = (u_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current);
      union {
        float real;
        uint32_t base;
      } u_power;
      u_power.real = this->power;
      *(outbuffer + offset + 0) = (u_power.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_power.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_power.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_power.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->power);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      uint32_t length_device_name;
      arrToVar(length_device_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_device_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_device_name-1]=0;
      this->device_name = (char *)(inbuffer + offset-1);
      offset += length_device_name;
      union {
        bool real;
        uint8_t base;
      } u_requested_status;
      u_requested_status.base = 0;
      u_requested_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->requested_status = u_requested_status.real;
      offset += sizeof(this->requested_status);
      union {
        bool real;
        uint8_t base;
      } u_output_status;
      u_output_status.base = 0;
      u_output_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->output_status = u_output_status.real;
      offset += sizeof(this->output_status);
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_current;
      u_current.base = 0;
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current = u_current.real;
      offset += sizeof(this->current);
      union {
        float real;
        uint32_t base;
      } u_power;
      u_power.base = 0;
      u_power.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_power.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_power.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_power.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->power = u_power.real;
      offset += sizeof(this->power);
     return offset;
    }

    virtual const char * getType() override { return "argo_msgs/HardwareInterfacePortInfo"; };
    virtual const char * getMD5() override { return "ce9da9bcd8efade1023f6c7a47147ad5"; };

  };

}
#endif
