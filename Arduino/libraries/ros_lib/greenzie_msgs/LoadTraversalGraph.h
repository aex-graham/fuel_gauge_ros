#ifndef _ROS_SERVICE_LoadTraversalGraph_h
#define _ROS_SERVICE_LoadTraversalGraph_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/TraversalGraph.h"

namespace greenzie_msgs
{

static const char LOADTRAVERSALGRAPH[] = "greenzie_msgs/LoadTraversalGraph";

  class LoadTraversalGraphRequest : public ros::Msg
  {
    public:
      typedef greenzie_msgs::TraversalGraph _traversal_graph_type;
      _traversal_graph_type traversal_graph;

    LoadTraversalGraphRequest():
      traversal_graph()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->traversal_graph.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->traversal_graph.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return LOADTRAVERSALGRAPH; };
    virtual const char * getMD5() override { return "ca5a8b9fcc873fad1506b38fa4b4217f"; };

  };

  class LoadTraversalGraphResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    LoadTraversalGraphResponse():
      success(0)
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
     return offset;
    }

    virtual const char * getType() override { return LOADTRAVERSALGRAPH; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class LoadTraversalGraph {
    public:
    typedef LoadTraversalGraphRequest Request;
    typedef LoadTraversalGraphResponse Response;
  };

}
#endif
