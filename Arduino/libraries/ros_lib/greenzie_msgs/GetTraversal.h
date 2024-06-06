#ifndef _ROS_SERVICE_GetTraversal_h
#define _ROS_SERVICE_GetTraversal_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/StripingState.h"
#include "geometry_msgs/Point.h"

namespace greenzie_msgs
{

static const char GETTRAVERSAL[] = "greenzie_msgs/GetTraversal";

  class GetTraversalRequest : public ros::Msg
  {
    public:
      typedef const char* _frame_id_type;
      _frame_id_type frame_id;
      typedef const char* _job_id_type;
      _job_id_type job_id;
      typedef geometry_msgs::Point _start_point_type;
      _start_point_type start_point;
      typedef geometry_msgs::Point _goal_point_type;
      _goal_point_type goal_point;

    GetTraversalRequest():
      frame_id(""),
      job_id(""),
      start_point(),
      goal_point()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_frame_id = strlen(this->frame_id);
      varToArr(outbuffer + offset, length_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      uint32_t length_job_id = strlen(this->job_id);
      varToArr(outbuffer + offset, length_job_id);
      offset += 4;
      memcpy(outbuffer + offset, this->job_id, length_job_id);
      offset += length_job_id;
      offset += this->start_point.serialize(outbuffer + offset);
      offset += this->goal_point.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_frame_id;
      arrToVar(length_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      uint32_t length_job_id;
      arrToVar(length_job_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_job_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_job_id-1]=0;
      this->job_id = (char *)(inbuffer + offset-1);
      offset += length_job_id;
      offset += this->start_point.deserialize(inbuffer + offset);
      offset += this->goal_point.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GETTRAVERSAL; };
    virtual const char * getMD5() override { return "730d979da1f9dba252463c592eab91a0"; };

  };

  class GetTraversalResponse : public ros::Msg
  {
    public:
      typedef bool _valid_plan_type;
      _valid_plan_type valid_plan;
      uint32_t states_length;
      typedef greenzie_msgs::StripingState _states_type;
      _states_type st_states;
      _states_type * states;

    GetTraversalResponse():
      valid_plan(0),
      states_length(0), st_states(), states(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_valid_plan;
      u_valid_plan.real = this->valid_plan;
      *(outbuffer + offset + 0) = (u_valid_plan.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valid_plan);
      *(outbuffer + offset + 0) = (this->states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_valid_plan;
      u_valid_plan.base = 0;
      u_valid_plan.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->valid_plan = u_valid_plan.real;
      offset += sizeof(this->valid_plan);
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->states_length);
      if(states_lengthT > states_length)
        this->states = (greenzie_msgs::StripingState*)realloc(this->states, states_lengthT * sizeof(greenzie_msgs::StripingState));
      states_length = states_lengthT;
      for( uint32_t i = 0; i < states_length; i++){
      offset += this->st_states.deserialize(inbuffer + offset);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(greenzie_msgs::StripingState));
      }
     return offset;
    }

    virtual const char * getType() override { return GETTRAVERSAL; };
    virtual const char * getMD5() override { return "eebeb4ef63fff5337559aa1908753fcf"; };

  };

  class GetTraversal {
    public:
    typedef GetTraversalRequest Request;
    typedef GetTraversalResponse Response;
  };

}
#endif
