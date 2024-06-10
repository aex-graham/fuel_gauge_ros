#ifndef _ROS_SERVICE_ConvertPlanToPath_h
#define _ROS_SERVICE_ConvertPlanToPath_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_msgs/Path.h"
#include "greenzie_msgs/StripingPlan.h"

namespace greenzie_msgs
{

static const char CONVERTPLANTOPATH[] = "greenzie_msgs/ConvertPlanToPath";

  class ConvertPlanToPathRequest : public ros::Msg
  {
    public:
      typedef greenzie_msgs::StripingPlan _plan_type;
      _plan_type plan;

    ConvertPlanToPathRequest():
      plan()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->plan.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->plan.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return CONVERTPLANTOPATH; };
    virtual const char * getMD5() override { return "08e0ec97d24c805472414d2b907c45be"; };

  };

  class ConvertPlanToPathResponse : public ros::Msg
  {
    public:
      typedef nav_msgs::Path _path_type;
      _path_type path;

    ConvertPlanToPathResponse():
      path()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->path.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->path.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return CONVERTPLANTOPATH; };
    virtual const char * getMD5() override { return "58d6f138c7de7ef47c75d4b7e5df5472"; };

  };

  class ConvertPlanToPath {
    public:
    typedef ConvertPlanToPathRequest Request;
    typedef ConvertPlanToPathResponse Response;
  };

}
#endif
