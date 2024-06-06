#ifndef _ROS_beagle_msgs_BeagleBatteryHVESSS1_h
#define _ROS_beagle_msgs_BeagleBatteryHVESSS1_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryHVESSS1 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _pos_contactor_state_type;
      _pos_contactor_state_type pos_contactor_state;
      typedef uint8_t _neg_contactor_state_type;
      _neg_contactor_state_type neg_contactor_state;
      typedef uint8_t _bus_disconnect_warning_type;
      _bus_disconnect_warning_type bus_disconnect_warning;
      typedef uint8_t _precharge_relay_state_type;
      _precharge_relay_state_type precharge_relay_state;
      typedef uint8_t _center_contactor_state_type;
      _center_contactor_state_type center_contactor_state;
      typedef uint8_t _active_isolation_test_type;
      _active_isolation_test_type active_isolation_test;
      typedef uint8_t _passive_isolation_test_type;
      _passive_isolation_test_type passive_isolation_test;
      typedef uint8_t _hvil_status_type;
      _hvil_status_type hvil_status;
      typedef uint8_t _state_of_charge_status_type;
      _state_of_charge_status_type state_of_charge_status;
      typedef uint8_t _cell_balance_status_type;
      _cell_balance_status_type cell_balance_status;
      typedef uint8_t _cell_balancing_active_type;
      _cell_balancing_active_type cell_balancing_active;
      typedef uint8_t _bus_connection_status_type;
      _bus_connection_status_type bus_connection_status;
      typedef uint8_t _operational_status_type;
      _operational_status_type operational_status;
      typedef uint8_t _no_of_hvesps_type;
      _no_of_hvesps_type no_of_hvesps;

    BeagleBatteryHVESSS1():
      header(),
      pos_contactor_state(0),
      neg_contactor_state(0),
      bus_disconnect_warning(0),
      precharge_relay_state(0),
      center_contactor_state(0),
      active_isolation_test(0),
      passive_isolation_test(0),
      hvil_status(0),
      state_of_charge_status(0),
      cell_balance_status(0),
      cell_balancing_active(0),
      bus_connection_status(0),
      operational_status(0),
      no_of_hvesps(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->pos_contactor_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pos_contactor_state);
      *(outbuffer + offset + 0) = (this->neg_contactor_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->neg_contactor_state);
      *(outbuffer + offset + 0) = (this->bus_disconnect_warning >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bus_disconnect_warning);
      *(outbuffer + offset + 0) = (this->precharge_relay_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->precharge_relay_state);
      *(outbuffer + offset + 0) = (this->center_contactor_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->center_contactor_state);
      *(outbuffer + offset + 0) = (this->active_isolation_test >> (8 * 0)) & 0xFF;
      offset += sizeof(this->active_isolation_test);
      *(outbuffer + offset + 0) = (this->passive_isolation_test >> (8 * 0)) & 0xFF;
      offset += sizeof(this->passive_isolation_test);
      *(outbuffer + offset + 0) = (this->hvil_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hvil_status);
      *(outbuffer + offset + 0) = (this->state_of_charge_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state_of_charge_status);
      *(outbuffer + offset + 0) = (this->cell_balance_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cell_balance_status);
      *(outbuffer + offset + 0) = (this->cell_balancing_active >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cell_balancing_active);
      *(outbuffer + offset + 0) = (this->bus_connection_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->bus_connection_status);
      *(outbuffer + offset + 0) = (this->operational_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operational_status);
      *(outbuffer + offset + 0) = (this->no_of_hvesps >> (8 * 0)) & 0xFF;
      offset += sizeof(this->no_of_hvesps);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->pos_contactor_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pos_contactor_state);
      this->neg_contactor_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->neg_contactor_state);
      this->bus_disconnect_warning =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->bus_disconnect_warning);
      this->precharge_relay_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->precharge_relay_state);
      this->center_contactor_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->center_contactor_state);
      this->active_isolation_test =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->active_isolation_test);
      this->passive_isolation_test =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->passive_isolation_test);
      this->hvil_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->hvil_status);
      this->state_of_charge_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state_of_charge_status);
      this->cell_balance_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cell_balance_status);
      this->cell_balancing_active =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cell_balancing_active);
      this->bus_connection_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->bus_connection_status);
      this->operational_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->operational_status);
      this->no_of_hvesps =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->no_of_hvesps);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryHVESSS1"; };
    virtual const char * getMD5() override { return "b03c36717acb795a22aecba2ee4ddc82"; };

  };

}
#endif
