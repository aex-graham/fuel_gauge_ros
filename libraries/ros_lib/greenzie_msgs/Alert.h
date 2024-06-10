#ifndef _ROS_greenzie_msgs_Alert_h
#define _ROS_greenzie_msgs_Alert_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"

namespace greenzie_msgs
{

  class Alert : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef const char* _source_type;
      _source_type source;
      typedef uint32_t _alert_code_type;
      _alert_code_type alert_code;
      typedef const char* _message_type;
      _message_type message;
      typedef const char* _resolution_type;
      _resolution_type resolution;
      typedef const char* _recovery_action_type;
      _recovery_action_type recovery_action;
      typedef uint8_t _severity_type;
      _severity_type severity;
      typedef bool _is_active_type;
      _is_active_type is_active;
      enum { INFO =  0 };
      enum { WARN =  1     };
      enum { ERROR =  2    };
      enum { FATAL =  3    };

    Alert():
      stamp(),
      source(""),
      alert_code(0),
      message(""),
      resolution(""),
      recovery_action(""),
      severity(0),
      is_active(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      uint32_t length_source = strlen(this->source);
      varToArr(outbuffer + offset, length_source);
      offset += 4;
      memcpy(outbuffer + offset, this->source, length_source);
      offset += length_source;
      *(outbuffer + offset + 0) = (this->alert_code >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->alert_code >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->alert_code >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->alert_code >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alert_code);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      uint32_t length_resolution = strlen(this->resolution);
      varToArr(outbuffer + offset, length_resolution);
      offset += 4;
      memcpy(outbuffer + offset, this->resolution, length_resolution);
      offset += length_resolution;
      uint32_t length_recovery_action = strlen(this->recovery_action);
      varToArr(outbuffer + offset, length_recovery_action);
      offset += 4;
      memcpy(outbuffer + offset, this->recovery_action, length_recovery_action);
      offset += length_recovery_action;
      *(outbuffer + offset + 0) = (this->severity >> (8 * 0)) & 0xFF;
      offset += sizeof(this->severity);
      union {
        bool real;
        uint8_t base;
      } u_is_active;
      u_is_active.real = this->is_active;
      *(outbuffer + offset + 0) = (u_is_active.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_active);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      uint32_t length_source;
      arrToVar(length_source, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_source; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_source-1]=0;
      this->source = (char *)(inbuffer + offset-1);
      offset += length_source;
      this->alert_code =  ((uint32_t) (*(inbuffer + offset)));
      this->alert_code |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->alert_code |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->alert_code |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->alert_code);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      uint32_t length_resolution;
      arrToVar(length_resolution, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_resolution; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_resolution-1]=0;
      this->resolution = (char *)(inbuffer + offset-1);
      offset += length_resolution;
      uint32_t length_recovery_action;
      arrToVar(length_recovery_action, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_recovery_action; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_recovery_action-1]=0;
      this->recovery_action = (char *)(inbuffer + offset-1);
      offset += length_recovery_action;
      this->severity =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->severity);
      union {
        bool real;
        uint8_t base;
      } u_is_active;
      u_is_active.base = 0;
      u_is_active.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_active = u_is_active.real;
      offset += sizeof(this->is_active);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/Alert"; };
    virtual const char * getMD5() override { return "2a657607b5c56853810acbde6442ffdb"; };

  };

}
#endif
