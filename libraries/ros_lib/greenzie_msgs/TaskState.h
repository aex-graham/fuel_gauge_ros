#ifndef _ROS_greenzie_msgs_TaskState_h
#define _ROS_greenzie_msgs_TaskState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "greenzie_msgs/ExecutePathActionFeedback.h"
#include "greenzie_msgs/JobState.h"
#include "greenzie_msgs/PolygonRegionArray.h"

namespace greenzie_msgs
{

  class TaskState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _task_id_type;
      _task_id_type task_id;
      typedef bool _has_plan_type;
      _has_plan_type has_plan;
      typedef bool _done_mowing_type;
      _done_mowing_type done_mowing;
      typedef greenzie_msgs::ExecutePathActionFeedback _feedback_type;
      _feedback_type feedback;
      typedef greenzie_msgs::JobState _job_state_type;
      _job_state_type job_state;
      typedef greenzie_msgs::PolygonRegionArray _mowed_areas_type;
      _mowed_areas_type mowed_areas;

    TaskState():
      header(),
      task_id(""),
      has_plan(0),
      done_mowing(0),
      feedback(),
      job_state(),
      mowed_areas()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_task_id = strlen(this->task_id);
      varToArr(outbuffer + offset, length_task_id);
      offset += 4;
      memcpy(outbuffer + offset, this->task_id, length_task_id);
      offset += length_task_id;
      union {
        bool real;
        uint8_t base;
      } u_has_plan;
      u_has_plan.real = this->has_plan;
      *(outbuffer + offset + 0) = (u_has_plan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_plan);
      union {
        bool real;
        uint8_t base;
      } u_done_mowing;
      u_done_mowing.real = this->done_mowing;
      *(outbuffer + offset + 0) = (u_done_mowing.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->done_mowing);
      offset += this->feedback.serialize(outbuffer + offset);
      offset += this->job_state.serialize(outbuffer + offset);
      offset += this->mowed_areas.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_task_id;
      arrToVar(length_task_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_task_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_task_id-1]=0;
      this->task_id = (char *)(inbuffer + offset-1);
      offset += length_task_id;
      union {
        bool real;
        uint8_t base;
      } u_has_plan;
      u_has_plan.base = 0;
      u_has_plan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_plan = u_has_plan.real;
      offset += sizeof(this->has_plan);
      union {
        bool real;
        uint8_t base;
      } u_done_mowing;
      u_done_mowing.base = 0;
      u_done_mowing.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->done_mowing = u_done_mowing.real;
      offset += sizeof(this->done_mowing);
      offset += this->feedback.deserialize(inbuffer + offset);
      offset += this->job_state.deserialize(inbuffer + offset);
      offset += this->mowed_areas.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/TaskState"; };
    virtual const char * getMD5() override { return "46b6887c6de1576ab64b5b3af3731f77"; };

  };

}
#endif
