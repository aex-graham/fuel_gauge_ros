#ifndef _ROS_greenzie_msgs_TraversalGraph_h
#define _ROS_greenzie_msgs_TraversalGraph_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/TraversalGraphEdge.h"
#include "greenzie_msgs/TraversalGraphNode.h"

namespace greenzie_msgs
{

  class TraversalGraph : public ros::Msg
  {
    public:
      uint32_t edges_length;
      typedef greenzie_msgs::TraversalGraphEdge _edges_type;
      _edges_type st_edges;
      _edges_type * edges;
      uint32_t nodes_length;
      typedef greenzie_msgs::TraversalGraphNode _nodes_type;
      _nodes_type st_nodes;
      _nodes_type * nodes;

    TraversalGraph():
      edges_length(0), st_edges(), edges(nullptr),
      nodes_length(0), st_nodes(), nodes(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->edges_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->edges_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->edges_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->edges_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->edges_length);
      for( uint32_t i = 0; i < edges_length; i++){
      offset += this->edges[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->nodes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nodes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nodes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nodes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodes_length);
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->nodes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t edges_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      edges_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->edges_length);
      if(edges_lengthT > edges_length)
        this->edges = (greenzie_msgs::TraversalGraphEdge*)realloc(this->edges, edges_lengthT * sizeof(greenzie_msgs::TraversalGraphEdge));
      edges_length = edges_lengthT;
      for( uint32_t i = 0; i < edges_length; i++){
      offset += this->st_edges.deserialize(inbuffer + offset);
        memcpy( &(this->edges[i]), &(this->st_edges), sizeof(greenzie_msgs::TraversalGraphEdge));
      }
      uint32_t nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->nodes_length);
      if(nodes_lengthT > nodes_length)
        this->nodes = (greenzie_msgs::TraversalGraphNode*)realloc(this->nodes, nodes_lengthT * sizeof(greenzie_msgs::TraversalGraphNode));
      nodes_length = nodes_lengthT;
      for( uint32_t i = 0; i < nodes_length; i++){
      offset += this->st_nodes.deserialize(inbuffer + offset);
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(greenzie_msgs::TraversalGraphNode));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/TraversalGraph"; };
    virtual const char * getMD5() override { return "c29f64f34dd693e032791b9a8e592e09"; };

  };

}
#endif
