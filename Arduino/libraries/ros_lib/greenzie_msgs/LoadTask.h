#ifndef _ROS_SERVICE_LoadTask_h
#define _ROS_SERVICE_LoadTask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

static const char LOADTASK[] = "greenzie_msgs/LoadTask";

  class LoadTaskRequest : public ros::Msg
  {
    public:
      typedef const char* _task_name_type;
      _task_name_type task_name;

    LoadTaskRequest():
      task_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_task_name = strlen(this->task_name);
      varToArr(outbuffer + offset, length_task_name);
      offset += 4;
      memcpy(outbuffer + offset, this->task_name, length_task_name);
      offset += length_task_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_task_name;
      arrToVar(length_task_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_task_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_task_name-1]=0;
      this->task_name = (char *)(inbuffer + offset-1);
      offset += length_task_name;
     return offset;
    }

    virtual const char * getType() override { return LOADTASK; };
    virtual const char * getMD5() override { return "cfe37cdddcaaf5bd95f630c73751773b"; };

  };

  class LoadTaskResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _msg_type;
      _msg_type msg;

    LoadTaskResponse():
      success(0),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    virtual const char * getType() override { return LOADTASK; };
    virtual const char * getMD5() override { return "e835b04f93d0b30fd8cb71e0967a16db"; };

  };

  class LoadTask {
    public:
    typedef LoadTaskRequest Request;
    typedef LoadTaskResponse Response;
  };

}
#endif
