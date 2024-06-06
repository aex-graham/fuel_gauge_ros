#ifndef _ROS_SERVICE_SetPlan_h
#define _ROS_SERVICE_SetPlan_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/StripingPlan.h"
#include "greenzie_msgs/Job.h"

namespace greenzie_msgs
{

static const char SETPLAN[] = "greenzie_msgs/SetPlan";

  class SetPlanRequest : public ros::Msg
  {
    public:
      typedef greenzie_msgs::StripingPlan _plan_type;
      _plan_type plan;
      typedef greenzie_msgs::Job _job_type;
      _job_type job;

    SetPlanRequest():
      plan(),
      job()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->plan.serialize(outbuffer + offset);
      offset += this->job.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->plan.deserialize(inbuffer + offset);
      offset += this->job.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return SETPLAN; };
    virtual const char * getMD5() override { return "e210cb09a56c6b1fd4a1e24209a13f9d"; };

  };

  class SetPlanResponse : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;

    SetPlanResponse():
      message("")
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
     return offset;
    }

    virtual const char * getType() override { return SETPLAN; };
    virtual const char * getMD5() override { return "5f003d6bcc824cbd51361d66d8e4f76c"; };

  };

  class SetPlan {
    public:
    typedef SetPlanRequest Request;
    typedef SetPlanResponse Response;
  };

}
#endif
