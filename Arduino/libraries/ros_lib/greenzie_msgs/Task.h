#ifndef _ROS_greenzie_msgs_Task_h
#define _ROS_greenzie_msgs_Task_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/Job.h"
#include "greenzie_msgs/PolygonRegionArray.h"
#include "greenzie_msgs/StripingPlan.h"
#include "greenzie_msgs/ExecutePathActionFeedback.h"

namespace greenzie_msgs
{

  class Task : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef greenzie_msgs::Job _job_type;
      _job_type job;
      typedef const char* _job_lla_json_type;
      _job_lla_json_type job_lla_json;
      typedef greenzie_msgs::Job _planner_job_type;
      _planner_job_type planner_job;
      typedef greenzie_msgs::PolygonRegionArray _mowed_areas_type;
      _mowed_areas_type mowed_areas;
      typedef bool _has_plan_type;
      _has_plan_type has_plan;
      typedef greenzie_msgs::StripingPlan _plan_type;
      _plan_type plan;
      typedef bool _done_mowing_type;
      _done_mowing_type done_mowing;
      typedef greenzie_msgs::ExecutePathActionFeedback _feedback_type;
      _feedback_type feedback;

    Task():
      id(""),
      job(),
      job_lla_json(""),
      planner_job(),
      mowed_areas(),
      has_plan(0),
      plan(),
      done_mowing(0),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      offset += this->job.serialize(outbuffer + offset);
      uint32_t length_job_lla_json = strlen(this->job_lla_json);
      varToArr(outbuffer + offset, length_job_lla_json);
      offset += 4;
      memcpy(outbuffer + offset, this->job_lla_json, length_job_lla_json);
      offset += length_job_lla_json;
      offset += this->planner_job.serialize(outbuffer + offset);
      offset += this->mowed_areas.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_has_plan;
      u_has_plan.real = this->has_plan;
      *(outbuffer + offset + 0) = (u_has_plan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_plan);
      offset += this->plan.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_done_mowing;
      u_done_mowing.real = this->done_mowing;
      *(outbuffer + offset + 0) = (u_done_mowing.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->done_mowing);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
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
      offset += this->planner_job.deserialize(inbuffer + offset);
      offset += this->mowed_areas.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_has_plan;
      u_has_plan.base = 0;
      u_has_plan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_plan = u_has_plan.real;
      offset += sizeof(this->has_plan);
      offset += this->plan.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_done_mowing;
      u_done_mowing.base = 0;
      u_done_mowing.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->done_mowing = u_done_mowing.real;
      offset += sizeof(this->done_mowing);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/Task"; };
    virtual const char * getMD5() override { return "2e82836eb87d86c449c94e14b0ef736c"; };

  };

}
#endif
