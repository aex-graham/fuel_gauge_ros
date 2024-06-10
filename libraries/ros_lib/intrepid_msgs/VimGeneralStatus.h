#ifndef _ROS_intrepid_msgs_VimGeneralStatus_h
#define _ROS_intrepid_msgs_VimGeneralStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace intrepid_msgs
{

  class VimGeneralStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _cal_status_type;
      _cal_status_type cal_status;
      typedef uint8_t _RESERVED_2_type;
      _RESERVED_2_type RESERVED_2;
      typedef uint8_t _state_type;
      _state_type state;
      typedef bool _spare_in_type;
      _spare_in_type spare_in;
      typedef bool _oil_press_in_type;
      _oil_press_in_type oil_press_in;
      typedef bool _brake_in_type;
      _brake_in_type brake_in;
      typedef bool _pto_select_in_type;
      _pto_select_in_type pto_select_in;
      typedef bool _op_press_in_type;
      _op_press_in_type op_press_in;
      typedef bool _start_in_type;
      _start_in_type start_in;
      typedef bool _pto_gate_type;
      _pto_gate_type pto_gate;
      typedef bool _start_gate_type;
      _start_gate_type start_gate;
      typedef uint8_t _latched_fault_locale_type;
      _latched_fault_locale_type latched_fault_locale;
      typedef bool _engine_running_type;
      _engine_running_type engine_running;
      typedef bool _ekill_gate_type;
      _ekill_gate_type ekill_gate;
      typedef bool _hi_lo_in_type;
      _hi_lo_in_type hi_lo_in;
      typedef bool _ptach_in_type;
      _ptach_in_type ptach_in;
      typedef bool _ntach_in_type;
      _ntach_in_type ntach_in;
      typedef bool _ekill_stat_type;
      _ekill_stat_type ekill_stat;
      typedef bool _pto_stat_type;
      _pto_stat_type pto_stat;
      typedef bool _start_stat_type;
      _start_stat_type start_stat;
      typedef bool _calibration_not_allowed_type;
      _calibration_not_allowed_type calibration_not_allowed;
      typedef bool _b_cond_3_type;
      _b_cond_3_type b_cond_3;
      typedef bool _b_cond_2_type;
      _b_cond_2_type b_cond_2;
      typedef bool _b_cond_1_type;
      _b_cond_1_type b_cond_1;
      typedef uint8_t _latched_fault_code_type;
      _latched_fault_code_type latched_fault_code;
      typedef uint8_t _latch_fault_source_addr_type;
      _latch_fault_source_addr_type latch_fault_source_addr;
      typedef uint32_t _tachometer_type;
      _tachometer_type tachometer;
      typedef uint8_t _RESERVED_8_type;
      _RESERVED_8_type RESERVED_8;
      enum { STATE_INIT = 0 };
      enum { STATE_CONTROL_ENABLED = 1 };
      enum { STATE_ENGINE_ENABLED = 2 };
      enum { STATE_ENGINE_RUNNING = 3 };
      enum { STATE_DISABLED = 4 };
      enum { STATE_DEVELOPER_BYPASS = 100     };
      enum { STATE_SYSTEM_CALIBRATION = 101   };

    VimGeneralStatus():
      header(),
      cal_status(0),
      RESERVED_2(0),
      state(0),
      spare_in(0),
      oil_press_in(0),
      brake_in(0),
      pto_select_in(0),
      op_press_in(0),
      start_in(0),
      pto_gate(0),
      start_gate(0),
      latched_fault_locale(0),
      engine_running(0),
      ekill_gate(0),
      hi_lo_in(0),
      ptach_in(0),
      ntach_in(0),
      ekill_stat(0),
      pto_stat(0),
      start_stat(0),
      calibration_not_allowed(0),
      b_cond_3(0),
      b_cond_2(0),
      b_cond_1(0),
      latched_fault_code(0),
      latch_fault_source_addr(0),
      tachometer(0),
      RESERVED_8(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->cal_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cal_status);
      *(outbuffer + offset + 0) = (this->RESERVED_2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->RESERVED_2);
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      union {
        bool real;
        uint8_t base;
      } u_spare_in;
      u_spare_in.real = this->spare_in;
      *(outbuffer + offset + 0) = (u_spare_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->spare_in);
      union {
        bool real;
        uint8_t base;
      } u_oil_press_in;
      u_oil_press_in.real = this->oil_press_in;
      *(outbuffer + offset + 0) = (u_oil_press_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->oil_press_in);
      union {
        bool real;
        uint8_t base;
      } u_brake_in;
      u_brake_in.real = this->brake_in;
      *(outbuffer + offset + 0) = (u_brake_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->brake_in);
      union {
        bool real;
        uint8_t base;
      } u_pto_select_in;
      u_pto_select_in.real = this->pto_select_in;
      *(outbuffer + offset + 0) = (u_pto_select_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pto_select_in);
      union {
        bool real;
        uint8_t base;
      } u_op_press_in;
      u_op_press_in.real = this->op_press_in;
      *(outbuffer + offset + 0) = (u_op_press_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->op_press_in);
      union {
        bool real;
        uint8_t base;
      } u_start_in;
      u_start_in.real = this->start_in;
      *(outbuffer + offset + 0) = (u_start_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->start_in);
      union {
        bool real;
        uint8_t base;
      } u_pto_gate;
      u_pto_gate.real = this->pto_gate;
      *(outbuffer + offset + 0) = (u_pto_gate.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pto_gate);
      union {
        bool real;
        uint8_t base;
      } u_start_gate;
      u_start_gate.real = this->start_gate;
      *(outbuffer + offset + 0) = (u_start_gate.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->start_gate);
      *(outbuffer + offset + 0) = (this->latched_fault_locale >> (8 * 0)) & 0xFF;
      offset += sizeof(this->latched_fault_locale);
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
      } u_ekill_gate;
      u_ekill_gate.real = this->ekill_gate;
      *(outbuffer + offset + 0) = (u_ekill_gate.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ekill_gate);
      union {
        bool real;
        uint8_t base;
      } u_hi_lo_in;
      u_hi_lo_in.real = this->hi_lo_in;
      *(outbuffer + offset + 0) = (u_hi_lo_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hi_lo_in);
      union {
        bool real;
        uint8_t base;
      } u_ptach_in;
      u_ptach_in.real = this->ptach_in;
      *(outbuffer + offset + 0) = (u_ptach_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ptach_in);
      union {
        bool real;
        uint8_t base;
      } u_ntach_in;
      u_ntach_in.real = this->ntach_in;
      *(outbuffer + offset + 0) = (u_ntach_in.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ntach_in);
      union {
        bool real;
        uint8_t base;
      } u_ekill_stat;
      u_ekill_stat.real = this->ekill_stat;
      *(outbuffer + offset + 0) = (u_ekill_stat.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ekill_stat);
      union {
        bool real;
        uint8_t base;
      } u_pto_stat;
      u_pto_stat.real = this->pto_stat;
      *(outbuffer + offset + 0) = (u_pto_stat.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pto_stat);
      union {
        bool real;
        uint8_t base;
      } u_start_stat;
      u_start_stat.real = this->start_stat;
      *(outbuffer + offset + 0) = (u_start_stat.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->start_stat);
      union {
        bool real;
        uint8_t base;
      } u_calibration_not_allowed;
      u_calibration_not_allowed.real = this->calibration_not_allowed;
      *(outbuffer + offset + 0) = (u_calibration_not_allowed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->calibration_not_allowed);
      union {
        bool real;
        uint8_t base;
      } u_b_cond_3;
      u_b_cond_3.real = this->b_cond_3;
      *(outbuffer + offset + 0) = (u_b_cond_3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b_cond_3);
      union {
        bool real;
        uint8_t base;
      } u_b_cond_2;
      u_b_cond_2.real = this->b_cond_2;
      *(outbuffer + offset + 0) = (u_b_cond_2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b_cond_2);
      union {
        bool real;
        uint8_t base;
      } u_b_cond_1;
      u_b_cond_1.real = this->b_cond_1;
      *(outbuffer + offset + 0) = (u_b_cond_1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b_cond_1);
      *(outbuffer + offset + 0) = (this->latched_fault_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->latched_fault_code);
      *(outbuffer + offset + 0) = (this->latch_fault_source_addr >> (8 * 0)) & 0xFF;
      offset += sizeof(this->latch_fault_source_addr);
      *(outbuffer + offset + 0) = (this->tachometer >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tachometer >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tachometer >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tachometer >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tachometer);
      *(outbuffer + offset + 0) = (this->RESERVED_8 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->RESERVED_8);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->cal_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cal_status);
      this->RESERVED_2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->RESERVED_2);
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
      union {
        bool real;
        uint8_t base;
      } u_spare_in;
      u_spare_in.base = 0;
      u_spare_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->spare_in = u_spare_in.real;
      offset += sizeof(this->spare_in);
      union {
        bool real;
        uint8_t base;
      } u_oil_press_in;
      u_oil_press_in.base = 0;
      u_oil_press_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->oil_press_in = u_oil_press_in.real;
      offset += sizeof(this->oil_press_in);
      union {
        bool real;
        uint8_t base;
      } u_brake_in;
      u_brake_in.base = 0;
      u_brake_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->brake_in = u_brake_in.real;
      offset += sizeof(this->brake_in);
      union {
        bool real;
        uint8_t base;
      } u_pto_select_in;
      u_pto_select_in.base = 0;
      u_pto_select_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pto_select_in = u_pto_select_in.real;
      offset += sizeof(this->pto_select_in);
      union {
        bool real;
        uint8_t base;
      } u_op_press_in;
      u_op_press_in.base = 0;
      u_op_press_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->op_press_in = u_op_press_in.real;
      offset += sizeof(this->op_press_in);
      union {
        bool real;
        uint8_t base;
      } u_start_in;
      u_start_in.base = 0;
      u_start_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->start_in = u_start_in.real;
      offset += sizeof(this->start_in);
      union {
        bool real;
        uint8_t base;
      } u_pto_gate;
      u_pto_gate.base = 0;
      u_pto_gate.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pto_gate = u_pto_gate.real;
      offset += sizeof(this->pto_gate);
      union {
        bool real;
        uint8_t base;
      } u_start_gate;
      u_start_gate.base = 0;
      u_start_gate.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->start_gate = u_start_gate.real;
      offset += sizeof(this->start_gate);
      this->latched_fault_locale =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->latched_fault_locale);
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
      } u_ekill_gate;
      u_ekill_gate.base = 0;
      u_ekill_gate.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ekill_gate = u_ekill_gate.real;
      offset += sizeof(this->ekill_gate);
      union {
        bool real;
        uint8_t base;
      } u_hi_lo_in;
      u_hi_lo_in.base = 0;
      u_hi_lo_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hi_lo_in = u_hi_lo_in.real;
      offset += sizeof(this->hi_lo_in);
      union {
        bool real;
        uint8_t base;
      } u_ptach_in;
      u_ptach_in.base = 0;
      u_ptach_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ptach_in = u_ptach_in.real;
      offset += sizeof(this->ptach_in);
      union {
        bool real;
        uint8_t base;
      } u_ntach_in;
      u_ntach_in.base = 0;
      u_ntach_in.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ntach_in = u_ntach_in.real;
      offset += sizeof(this->ntach_in);
      union {
        bool real;
        uint8_t base;
      } u_ekill_stat;
      u_ekill_stat.base = 0;
      u_ekill_stat.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ekill_stat = u_ekill_stat.real;
      offset += sizeof(this->ekill_stat);
      union {
        bool real;
        uint8_t base;
      } u_pto_stat;
      u_pto_stat.base = 0;
      u_pto_stat.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pto_stat = u_pto_stat.real;
      offset += sizeof(this->pto_stat);
      union {
        bool real;
        uint8_t base;
      } u_start_stat;
      u_start_stat.base = 0;
      u_start_stat.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->start_stat = u_start_stat.real;
      offset += sizeof(this->start_stat);
      union {
        bool real;
        uint8_t base;
      } u_calibration_not_allowed;
      u_calibration_not_allowed.base = 0;
      u_calibration_not_allowed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->calibration_not_allowed = u_calibration_not_allowed.real;
      offset += sizeof(this->calibration_not_allowed);
      union {
        bool real;
        uint8_t base;
      } u_b_cond_3;
      u_b_cond_3.base = 0;
      u_b_cond_3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->b_cond_3 = u_b_cond_3.real;
      offset += sizeof(this->b_cond_3);
      union {
        bool real;
        uint8_t base;
      } u_b_cond_2;
      u_b_cond_2.base = 0;
      u_b_cond_2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->b_cond_2 = u_b_cond_2.real;
      offset += sizeof(this->b_cond_2);
      union {
        bool real;
        uint8_t base;
      } u_b_cond_1;
      u_b_cond_1.base = 0;
      u_b_cond_1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->b_cond_1 = u_b_cond_1.real;
      offset += sizeof(this->b_cond_1);
      this->latched_fault_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->latched_fault_code);
      this->latch_fault_source_addr =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->latch_fault_source_addr);
      this->tachometer =  ((uint32_t) (*(inbuffer + offset)));
      this->tachometer |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tachometer |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tachometer |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tachometer);
      this->RESERVED_8 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->RESERVED_8);
     return offset;
    }

    virtual const char * getType() override { return "intrepid_msgs/VimGeneralStatus"; };
    virtual const char * getMD5() override { return "3159b4f074b3cea47ef7da1b577850eb"; };

  };

}
#endif
