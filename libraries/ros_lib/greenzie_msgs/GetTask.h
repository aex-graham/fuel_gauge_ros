#ifndef _ROS_SERVICE_GetTask_h
#define _ROS_SERVICE_GetTask_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/Task.h"

namespace greenzie_msgs
{

static const char GETTASK[] = "greenzie_msgs/GetTask";

  class GetTaskRequest : public ros::Msg
  {
    public:
      typedef bool _in_earth_frame_type;
      _in_earth_frame_type in_earth_frame;

    GetTaskRequest():
      in_earth_frame(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_in_earth_frame;
      u_in_earth_frame.real = this->in_earth_frame;
      *(outbuffer + offset + 0) = (u_in_earth_frame.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->in_earth_frame);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_in_earth_frame;
      u_in_earth_frame.base = 0;
      u_in_earth_frame.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->in_earth_frame = u_in_earth_frame.real;
      offset += sizeof(this->in_earth_frame);
     return offset;
    }

    virtual const char * getType() override { return GETTASK; };
    virtual const char * getMD5() override { return "ff263711808c94f79ca243ef61a35ca4"; };

  };

  class GetTaskResponse : public ros::Msg
  {
    public:
      typedef greenzie_msgs::Task _task_type;
      _task_type task;
      typedef bool _success_type;
      _success_type success;

    GetTaskResponse():
      task(),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->task.serialize(outbuffer + offset);
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
      offset += this->task.deserialize(inbuffer + offset);
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

    virtual const char * getType() override { return GETTASK; };
    virtual const char * getMD5() override { return "378f39bda3a3bace65d9fe632a9d10e3"; };

  };

  class GetTask {
    public:
    typedef GetTaskRequest Request;
    typedef GetTaskResponse Response;
  };

}
#endif
