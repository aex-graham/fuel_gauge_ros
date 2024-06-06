#ifndef _ROS_beagle_msgs_AsiStatusCode_h
#define _ROS_beagle_msgs_AsiStatusCode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace beagle_msgs
{

  class AsiStatusCode : public ros::Msg
  {
    public:
      typedef bool _low_magnetic_field_error_type;
      _low_magnetic_field_error_type low_magnetic_field_error;
      typedef bool _travel_bounds_fault_type;
      _travel_bounds_fault_type travel_bounds_fault;
      typedef bool _redundant_sensor_mismatch_type;
      _redundant_sensor_mismatch_type redundant_sensor_mismatch;
      typedef bool _A1335_error_sensor1_type;
      _A1335_error_sensor1_type A1335_error_sensor1;
      typedef bool _A1335_error_sensor2_type;
      _A1335_error_sensor2_type A1335_error_sensor2;
      typedef bool _SPI_comm_error_sensor1_type;
      _SPI_comm_error_sensor1_type SPI_comm_error_sensor1;
      typedef bool _SPI_comm_error_sensor2_type;
      _SPI_comm_error_sensor2_type SPI_comm_error_sensor2;
      typedef bool _non_operational_type;
      _non_operational_type non_operational;

    AsiStatusCode():
      low_magnetic_field_error(0),
      travel_bounds_fault(0),
      redundant_sensor_mismatch(0),
      A1335_error_sensor1(0),
      A1335_error_sensor2(0),
      SPI_comm_error_sensor1(0),
      SPI_comm_error_sensor2(0),
      non_operational(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_low_magnetic_field_error;
      u_low_magnetic_field_error.real = this->low_magnetic_field_error;
      *(outbuffer + offset + 0) = (u_low_magnetic_field_error.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->low_magnetic_field_error);
      union {
        bool real;
        uint8_t base;
      } u_travel_bounds_fault;
      u_travel_bounds_fault.real = this->travel_bounds_fault;
      *(outbuffer + offset + 0) = (u_travel_bounds_fault.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->travel_bounds_fault);
      union {
        bool real;
        uint8_t base;
      } u_redundant_sensor_mismatch;
      u_redundant_sensor_mismatch.real = this->redundant_sensor_mismatch;
      *(outbuffer + offset + 0) = (u_redundant_sensor_mismatch.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->redundant_sensor_mismatch);
      union {
        bool real;
        uint8_t base;
      } u_A1335_error_sensor1;
      u_A1335_error_sensor1.real = this->A1335_error_sensor1;
      *(outbuffer + offset + 0) = (u_A1335_error_sensor1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->A1335_error_sensor1);
      union {
        bool real;
        uint8_t base;
      } u_A1335_error_sensor2;
      u_A1335_error_sensor2.real = this->A1335_error_sensor2;
      *(outbuffer + offset + 0) = (u_A1335_error_sensor2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->A1335_error_sensor2);
      union {
        bool real;
        uint8_t base;
      } u_SPI_comm_error_sensor1;
      u_SPI_comm_error_sensor1.real = this->SPI_comm_error_sensor1;
      *(outbuffer + offset + 0) = (u_SPI_comm_error_sensor1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->SPI_comm_error_sensor1);
      union {
        bool real;
        uint8_t base;
      } u_SPI_comm_error_sensor2;
      u_SPI_comm_error_sensor2.real = this->SPI_comm_error_sensor2;
      *(outbuffer + offset + 0) = (u_SPI_comm_error_sensor2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->SPI_comm_error_sensor2);
      union {
        bool real;
        uint8_t base;
      } u_non_operational;
      u_non_operational.real = this->non_operational;
      *(outbuffer + offset + 0) = (u_non_operational.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->non_operational);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_low_magnetic_field_error;
      u_low_magnetic_field_error.base = 0;
      u_low_magnetic_field_error.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->low_magnetic_field_error = u_low_magnetic_field_error.real;
      offset += sizeof(this->low_magnetic_field_error);
      union {
        bool real;
        uint8_t base;
      } u_travel_bounds_fault;
      u_travel_bounds_fault.base = 0;
      u_travel_bounds_fault.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->travel_bounds_fault = u_travel_bounds_fault.real;
      offset += sizeof(this->travel_bounds_fault);
      union {
        bool real;
        uint8_t base;
      } u_redundant_sensor_mismatch;
      u_redundant_sensor_mismatch.base = 0;
      u_redundant_sensor_mismatch.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->redundant_sensor_mismatch = u_redundant_sensor_mismatch.real;
      offset += sizeof(this->redundant_sensor_mismatch);
      union {
        bool real;
        uint8_t base;
      } u_A1335_error_sensor1;
      u_A1335_error_sensor1.base = 0;
      u_A1335_error_sensor1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->A1335_error_sensor1 = u_A1335_error_sensor1.real;
      offset += sizeof(this->A1335_error_sensor1);
      union {
        bool real;
        uint8_t base;
      } u_A1335_error_sensor2;
      u_A1335_error_sensor2.base = 0;
      u_A1335_error_sensor2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->A1335_error_sensor2 = u_A1335_error_sensor2.real;
      offset += sizeof(this->A1335_error_sensor2);
      union {
        bool real;
        uint8_t base;
      } u_SPI_comm_error_sensor1;
      u_SPI_comm_error_sensor1.base = 0;
      u_SPI_comm_error_sensor1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->SPI_comm_error_sensor1 = u_SPI_comm_error_sensor1.real;
      offset += sizeof(this->SPI_comm_error_sensor1);
      union {
        bool real;
        uint8_t base;
      } u_SPI_comm_error_sensor2;
      u_SPI_comm_error_sensor2.base = 0;
      u_SPI_comm_error_sensor2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->SPI_comm_error_sensor2 = u_SPI_comm_error_sensor2.real;
      offset += sizeof(this->SPI_comm_error_sensor2);
      union {
        bool real;
        uint8_t base;
      } u_non_operational;
      u_non_operational.base = 0;
      u_non_operational.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->non_operational = u_non_operational.real;
      offset += sizeof(this->non_operational);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/AsiStatusCode"; };
    virtual const char * getMD5() override { return "05f4a96d107f056591d5e7ad090d5b25"; };

  };

}
#endif
