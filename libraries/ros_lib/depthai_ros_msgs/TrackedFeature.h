#ifndef _ROS_depthai_ros_msgs_TrackedFeature_h
#define _ROS_depthai_ros_msgs_TrackedFeature_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"

namespace depthai_ros_msgs
{

  class TrackedFeature : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef uint32_t _id_type;
      _id_type id;
      typedef uint32_t _age_type;
      _age_type age;
      typedef float _harris_score_type;
      _harris_score_type harris_score;
      typedef float _tracking_error_type;
      _tracking_error_type tracking_error;

    TrackedFeature():
      header(),
      position(),
      id(0),
      age(0),
      harris_score(0),
      tracking_error(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->age >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->age >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->age >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->age >> (8 * 3)) & 0xFF;
      offset += sizeof(this->age);
      union {
        float real;
        uint32_t base;
      } u_harris_score;
      u_harris_score.real = this->harris_score;
      *(outbuffer + offset + 0) = (u_harris_score.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_harris_score.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_harris_score.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_harris_score.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->harris_score);
      union {
        float real;
        uint32_t base;
      } u_tracking_error;
      u_tracking_error.real = this->tracking_error;
      *(outbuffer + offset + 0) = (u_tracking_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tracking_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tracking_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tracking_error.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tracking_error);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      this->age =  ((uint32_t) (*(inbuffer + offset)));
      this->age |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->age |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->age |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->age);
      union {
        float real;
        uint32_t base;
      } u_harris_score;
      u_harris_score.base = 0;
      u_harris_score.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_harris_score.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_harris_score.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_harris_score.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->harris_score = u_harris_score.real;
      offset += sizeof(this->harris_score);
      union {
        float real;
        uint32_t base;
      } u_tracking_error;
      u_tracking_error.base = 0;
      u_tracking_error.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tracking_error.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tracking_error.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tracking_error.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tracking_error = u_tracking_error.real;
      offset += sizeof(this->tracking_error);
     return offset;
    }

    virtual const char * getType() override { return "depthai_ros_msgs/TrackedFeature"; };
    virtual const char * getMD5() override { return "7b24a14f9b5d900250ec5c3f7bf1ec5e"; };

  };

}
#endif
