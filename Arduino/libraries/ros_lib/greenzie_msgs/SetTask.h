#ifndef _ROS_SERVICE_SetTask_h
#define _ROS_SERVICE_SetTask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/Task.h"

namespace greenzie_msgs
{

static const char SETTASK[] = "greenzie_msgs/SetTask";

  class SetTaskRequest : public ros::Msg
  {
    public:
      typedef greenzie_msgs::Task _task_type;
      _task_type task;

    SetTaskRequest():
      task()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->task.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->task.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETTASK; };
    virtual const char * getMD5() override { return "f82ba5648f7ff9690ccfcd998f666da2"; };

  };

  class SetTaskResponse : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;
      typedef bool _success_type;
      _success_type success;

    SetTaskResponse():
      message(""),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return SETTASK; };
    virtual const char * getMD5() override { return "9bf829f07d795d3f9e541a07897da2c4"; };

  };

  class SetTask {
    public:
    typedef SetTaskRequest Request;
    typedef SetTaskResponse Response;
  };

}
#endif
