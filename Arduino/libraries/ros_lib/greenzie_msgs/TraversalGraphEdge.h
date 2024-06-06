#ifndef _ROS_greenzie_msgs_TraversalGraphEdge_h
#define _ROS_greenzie_msgs_TraversalGraphEdge_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class TraversalGraphEdge : public ros::Msg
  {
    public:
      typedef int64_t _node_id_0_type;
      _node_id_0_type node_id_0;
      typedef int64_t _node_id_1_type;
      _node_id_1_type node_id_1;
      typedef float _weight_type;
      _weight_type weight;

    TraversalGraphEdge():
      node_id_0(0),
      node_id_1(0),
      weight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_node_id_0;
      u_node_id_0.real = this->node_id_0;
      *(outbuffer + offset + 0) = (u_node_id_0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_node_id_0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_node_id_0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_node_id_0.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_node_id_0.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_node_id_0.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_node_id_0.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_node_id_0.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->node_id_0);
      union {
        int64_t real;
        uint64_t base;
      } u_node_id_1;
      u_node_id_1.real = this->node_id_1;
      *(outbuffer + offset + 0) = (u_node_id_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_node_id_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_node_id_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_node_id_1.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_node_id_1.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_node_id_1.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_node_id_1.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_node_id_1.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->node_id_1);
      offset += serializeAvrFloat64(outbuffer + offset, this->weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_node_id_0;
      u_node_id_0.base = 0;
      u_node_id_0.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_node_id_0.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_node_id_0.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_node_id_0.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_node_id_0.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_node_id_0.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_node_id_0.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_node_id_0.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->node_id_0 = u_node_id_0.real;
      offset += sizeof(this->node_id_0);
      union {
        int64_t real;
        uint64_t base;
      } u_node_id_1;
      u_node_id_1.base = 0;
      u_node_id_1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_node_id_1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_node_id_1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_node_id_1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_node_id_1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_node_id_1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_node_id_1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_node_id_1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->node_id_1 = u_node_id_1.real;
      offset += sizeof(this->node_id_1);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->weight));
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/TraversalGraphEdge"; };
    virtual const char * getMD5() override { return "cc902b868baf1c0e980c979ee2205c82"; };

  };

}
#endif
