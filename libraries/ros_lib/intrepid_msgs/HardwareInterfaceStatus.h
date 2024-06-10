#ifndef _ROS_intrepid_msgs_HardwareInterfaceStatus_h
#define _ROS_intrepid_msgs_HardwareInterfaceStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace intrepid_msgs
{

  class HardwareInterfaceStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _pcie_voltage_type;
      _pcie_voltage_type pcie_voltage;
      typedef float _harness_battery_voltage_type;
      _harness_battery_voltage_type harness_battery_voltage;
      typedef float _src_charger_voltage_type;
      _src_charger_voltage_type src_charger_voltage;

    HardwareInterfaceStatus():
      header(),
      pcie_voltage(0),
      harness_battery_voltage(0),
      src_charger_voltage(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_pcie_voltage;
      u_pcie_voltage.real = this->pcie_voltage;
      *(outbuffer + offset + 0) = (u_pcie_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pcie_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pcie_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pcie_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pcie_voltage);
      union {
        float real;
        uint32_t base;
      } u_harness_battery_voltage;
      u_harness_battery_voltage.real = this->harness_battery_voltage;
      *(outbuffer + offset + 0) = (u_harness_battery_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_harness_battery_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_harness_battery_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_harness_battery_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->harness_battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_src_charger_voltage;
      u_src_charger_voltage.real = this->src_charger_voltage;
      *(outbuffer + offset + 0) = (u_src_charger_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_src_charger_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_src_charger_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_src_charger_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->src_charger_voltage);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_pcie_voltage;
      u_pcie_voltage.base = 0;
      u_pcie_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pcie_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pcie_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pcie_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pcie_voltage = u_pcie_voltage.real;
      offset += sizeof(this->pcie_voltage);
      union {
        float real;
        uint32_t base;
      } u_harness_battery_voltage;
      u_harness_battery_voltage.base = 0;
      u_harness_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_harness_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_harness_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_harness_battery_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->harness_battery_voltage = u_harness_battery_voltage.real;
      offset += sizeof(this->harness_battery_voltage);
      union {
        float real;
        uint32_t base;
      } u_src_charger_voltage;
      u_src_charger_voltage.base = 0;
      u_src_charger_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_src_charger_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_src_charger_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_src_charger_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->src_charger_voltage = u_src_charger_voltage.real;
      offset += sizeof(this->src_charger_voltage);
     return offset;
    }

    virtual const char * getType() override { return "intrepid_msgs/HardwareInterfaceStatus"; };
    virtual const char * getMD5() override { return "4b7acde7e672b94fcd8a8a2ab4fb2606"; };

  };

}
#endif
