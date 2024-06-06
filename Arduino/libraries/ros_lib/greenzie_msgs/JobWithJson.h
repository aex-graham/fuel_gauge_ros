#ifndef _ROS_greenzie_msgs_JobWithJson_h
#define _ROS_greenzie_msgs_JobWithJson_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/Job.h"

namespace greenzie_msgs
{

  class JobWithJson : public ros::Msg
  {
    public:
      typedef greenzie_msgs::Job _job_type;
      _job_type job;
      typedef const char* _job_lla_json_type;
      _job_lla_json_type job_lla_json;

    JobWithJson():
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

    virtual const char * getType() override { return "greenzie_msgs/JobWithJson"; };
    virtual const char * getMD5() override { return "d1fdbc20917a22518da0dfad5ba574d6"; };

  };

}
#endif
