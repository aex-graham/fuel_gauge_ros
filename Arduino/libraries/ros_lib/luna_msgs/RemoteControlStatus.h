#ifndef _ROS_luna_msgs_RemoteControlStatus_h
#define _ROS_luna_msgs_RemoteControlStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace luna_msgs
{

  class RemoteControlStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _local_key_state_type;
      _local_key_state_type local_key_state;
      typedef bool _remote_key_state_type;
      _remote_key_state_type remote_key_state;
      typedef bool _engine_cranking_type;
      _engine_cranking_type engine_cranking;
      typedef bool _engine_running_type;
      _engine_running_type engine_running;
      typedef bool _estop_state_type;
      _estop_state_type estop_state;
      typedef bool _drive_enable_type;
      _drive_enable_type drive_enable;
      typedef bool _PTO_enable_type;
      _PTO_enable_type PTO_enable;
      typedef float _HOC_inches_type;
      _HOC_inches_type HOC_inches;
      typedef bool _high_range_enable_type;
      _high_range_enable_type high_range_enable;
      typedef bool _operator_presence_type;
      _operator_presence_type operator_presence;
      typedef bool _mapping_enable_type;
      _mapping_enable_type mapping_enable;
      typedef uint8_t _drive_response_type;
      _drive_response_type drive_response;
      typedef bool _autonomous_prepare_type;
      _autonomous_prepare_type autonomous_prepare;
      typedef bool _autonomous_enable_type;
      _autonomous_enable_type autonomous_enable;
      typedef uint8_t _drive_level_type;
      _drive_level_type drive_level;

    RemoteControlStatus():
      header(),
      local_key_state(0),
      remote_key_state(0),
      engine_cranking(0),
      engine_running(0),
      estop_state(0),
      drive_enable(0),
      PTO_enable(0),
      HOC_inches(0),
      high_range_enable(0),
      operator_presence(0),
      mapping_enable(0),
      drive_response(0),
      autonomous_prepare(0),
      autonomous_enable(0),
      drive_level(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_local_key_state;
      u_local_key_state.real = this->local_key_state;
      *(outbuffer + offset + 0) = (u_local_key_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->local_key_state);
      union {
        bool real;
        uint8_t base;
      } u_remote_key_state;
      u_remote_key_state.real = this->remote_key_state;
      *(outbuffer + offset + 0) = (u_remote_key_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->remote_key_state);
      union {
        bool real;
        uint8_t base;
      } u_engine_cranking;
      u_engine_cranking.real = this->engine_cranking;
      *(outbuffer + offset + 0) = (u_engine_cranking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_cranking);
      union {
        bool real;
        uint8_t base;
      } u_engine_running;
      u_engine_running.real = this->engine_running;
      *(outbuffer + offset + 0) = (u_engine_running.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->engine_running);
      union {
        bool real;
        uint8_t base;
      } u_estop_state;
      u_estop_state.real = this->estop_state;
      *(outbuffer + offset + 0) = (u_estop_state.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->estop_state);
      union {
        bool real;
        uint8_t base;
      } u_drive_enable;
      u_drive_enable.real = this->drive_enable;
      *(outbuffer + offset + 0) = (u_drive_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drive_enable);
      union {
        bool real;
        uint8_t base;
      } u_PTO_enable;
      u_PTO_enable.real = this->PTO_enable;
      *(outbuffer + offset + 0) = (u_PTO_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->PTO_enable);
      union {
        float real;
        uint32_t base;
      } u_HOC_inches;
      u_HOC_inches.real = this->HOC_inches;
      *(outbuffer + offset + 0) = (u_HOC_inches.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_HOC_inches.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_HOC_inches.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_HOC_inches.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->HOC_inches);
      union {
        bool real;
        uint8_t base;
      } u_high_range_enable;
      u_high_range_enable.real = this->high_range_enable;
      *(outbuffer + offset + 0) = (u_high_range_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->high_range_enable);
      union {
        bool real;
        uint8_t base;
      } u_operator_presence;
      u_operator_presence.real = this->operator_presence;
      *(outbuffer + offset + 0) = (u_operator_presence.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operator_presence);
      union {
        bool real;
        uint8_t base;
      } u_mapping_enable;
      u_mapping_enable.real = this->mapping_enable;
      *(outbuffer + offset + 0) = (u_mapping_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mapping_enable);
      *(outbuffer + offset + 0) = (this->drive_response >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drive_response);
      union {
        bool real;
        uint8_t base;
      } u_autonomous_prepare;
      u_autonomous_prepare.real = this->autonomous_prepare;
      *(outbuffer + offset + 0) = (u_autonomous_prepare.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autonomous_prepare);
      union {
        bool real;
        uint8_t base;
      } u_autonomous_enable;
      u_autonomous_enable.real = this->autonomous_enable;
      *(outbuffer + offset + 0) = (u_autonomous_enable.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->autonomous_enable);
      *(outbuffer + offset + 0) = (this->drive_level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->drive_level);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_local_key_state;
      u_local_key_state.base = 0;
      u_local_key_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->local_key_state = u_local_key_state.real;
      offset += sizeof(this->local_key_state);
      union {
        bool real;
        uint8_t base;
      } u_remote_key_state;
      u_remote_key_state.base = 0;
      u_remote_key_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->remote_key_state = u_remote_key_state.real;
      offset += sizeof(this->remote_key_state);
      union {
        bool real;
        uint8_t base;
      } u_engine_cranking;
      u_engine_cranking.base = 0;
      u_engine_cranking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_cranking = u_engine_cranking.real;
      offset += sizeof(this->engine_cranking);
      union {
        bool real;
        uint8_t base;
      } u_engine_running;
      u_engine_running.base = 0;
      u_engine_running.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->engine_running = u_engine_running.real;
      offset += sizeof(this->engine_running);
      union {
        bool real;
        uint8_t base;
      } u_estop_state;
      u_estop_state.base = 0;
      u_estop_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->estop_state = u_estop_state.real;
      offset += sizeof(this->estop_state);
      union {
        bool real;
        uint8_t base;
      } u_drive_enable;
      u_drive_enable.base = 0;
      u_drive_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->drive_enable = u_drive_enable.real;
      offset += sizeof(this->drive_enable);
      union {
        bool real;
        uint8_t base;
      } u_PTO_enable;
      u_PTO_enable.base = 0;
      u_PTO_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->PTO_enable = u_PTO_enable.real;
      offset += sizeof(this->PTO_enable);
      union {
        float real;
        uint32_t base;
      } u_HOC_inches;
      u_HOC_inches.base = 0;
      u_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_HOC_inches.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->HOC_inches = u_HOC_inches.real;
      offset += sizeof(this->HOC_inches);
      union {
        bool real;
        uint8_t base;
      } u_high_range_enable;
      u_high_range_enable.base = 0;
      u_high_range_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->high_range_enable = u_high_range_enable.real;
      offset += sizeof(this->high_range_enable);
      union {
        bool real;
        uint8_t base;
      } u_operator_presence;
      u_operator_presence.base = 0;
      u_operator_presence.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operator_presence = u_operator_presence.real;
      offset += sizeof(this->operator_presence);
      union {
        bool real;
        uint8_t base;
      } u_mapping_enable;
      u_mapping_enable.base = 0;
      u_mapping_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mapping_enable = u_mapping_enable.real;
      offset += sizeof(this->mapping_enable);
      this->drive_response =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->drive_response);
      union {
        bool real;
        uint8_t base;
      } u_autonomous_prepare;
      u_autonomous_prepare.base = 0;
      u_autonomous_prepare.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->autonomous_prepare = u_autonomous_prepare.real;
      offset += sizeof(this->autonomous_prepare);
      union {
        bool real;
        uint8_t base;
      } u_autonomous_enable;
      u_autonomous_enable.base = 0;
      u_autonomous_enable.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->autonomous_enable = u_autonomous_enable.real;
      offset += sizeof(this->autonomous_enable);
      this->drive_level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->drive_level);
     return offset;
    }

    virtual const char * getType() override { return "luna_msgs/RemoteControlStatus"; };
    virtual const char * getMD5() override { return "2b30a9df0ec0ee0f7f6f8dec6b9ebbf5"; };

  };

}
#endif
