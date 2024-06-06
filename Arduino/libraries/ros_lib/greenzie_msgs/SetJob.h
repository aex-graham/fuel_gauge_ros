#ifndef _ROS_SERVICE_SetJob_h
#define _ROS_SERVICE_SetJob_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/Job.h"

namespace greenzie_msgs
{

static const char SETJOB[] = "greenzie_msgs/SetJob";

  class SetJobRequest : public ros::Msg
  {
    public:
      typedef greenzie_msgs::Job _job_type;
      _job_type job;
      typedef const char* _job_lla_json_type;
      _job_lla_json_type job_lla_json;

    SetJobRequest():
      job(),
      job_lla_json("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->job.serialize(outbuffer + offset);
      uint32_t length_job_lla_json = strlen(this->job_lla_json);
      varToArr(outbuffer + offset, length_job_lla_json);
      offset += 4;
      memcpy(outbuffer + offset, this->job_lla_json, length_job_lla_json);
      offset += length_job_lla_json;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->job.deserialize(inbuffer + offset);
      uint32_t length_job_lla_json;
      arrToVar(length_job_lla_json, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_job_lla_json; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_job_lla_json-1]=0;
      this->job_lla_json = (char *)(inbuffer + offset-1);
      offset += length_job_lla_json;
     return offset;
    }

    virtual const char * getType() override { return SETJOB; };
    virtual const char * getMD5() override { return "d1fdbc20917a22518da0dfad5ba574d6"; };

  };

  class SetJobResponse : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;
      typedef bool _success_type;
      _success_type success;

    SetJobResponse():
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

    virtual const char * getType() override { return SETJOB; };
    virtual const char * getMD5() override { return "9bf829f07d795d3f9e541a07897da2c4"; };

  };

  class SetJob {
    public:
    typedef SetJobRequest Request;
    typedef SetJobResponse Response;
  };

}
#endif
