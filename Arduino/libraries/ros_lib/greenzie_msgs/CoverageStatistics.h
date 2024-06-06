#ifndef _ROS_greenzie_msgs_CoverageStatistics_h
#define _ROS_greenzie_msgs_CoverageStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

  class CoverageStatistics : public ros::Msg
  {
    public:
      typedef float _percentage_completed_type;
      _percentage_completed_type percentage_completed;
      typedef float _percentage_missed_type;
      _percentage_missed_type percentage_missed;
      typedef float _percentage_overshot_type;
      _percentage_overshot_type percentage_overshot;
      typedef float _area_completed_type;
      _area_completed_type area_completed;
      typedef float _area_missed_type;
      _area_missed_type area_missed;
      typedef float _area_overshot_type;
      _area_overshot_type area_overshot;

    CoverageStatistics():
      percentage_completed(0),
      percentage_missed(0),
      percentage_overshot(0),
      area_completed(0),
      area_missed(0),
      area_overshot(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_percentage_completed;
      u_percentage_completed.real = this->percentage_completed;
      *(outbuffer + offset + 0) = (u_percentage_completed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_percentage_completed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_percentage_completed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_percentage_completed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->percentage_completed);
      union {
        float real;
        uint32_t base;
      } u_percentage_missed;
      u_percentage_missed.real = this->percentage_missed;
      *(outbuffer + offset + 0) = (u_percentage_missed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_percentage_missed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_percentage_missed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_percentage_missed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->percentage_missed);
      union {
        float real;
        uint32_t base;
      } u_percentage_overshot;
      u_percentage_overshot.real = this->percentage_overshot;
      *(outbuffer + offset + 0) = (u_percentage_overshot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_percentage_overshot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_percentage_overshot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_percentage_overshot.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->percentage_overshot);
      union {
        float real;
        uint32_t base;
      } u_area_completed;
      u_area_completed.real = this->area_completed;
      *(outbuffer + offset + 0) = (u_area_completed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_area_completed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_area_completed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_area_completed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->area_completed);
      union {
        float real;
        uint32_t base;
      } u_area_missed;
      u_area_missed.real = this->area_missed;
      *(outbuffer + offset + 0) = (u_area_missed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_area_missed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_area_missed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_area_missed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->area_missed);
      union {
        float real;
        uint32_t base;
      } u_area_overshot;
      u_area_overshot.real = this->area_overshot;
      *(outbuffer + offset + 0) = (u_area_overshot.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_area_overshot.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_area_overshot.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_area_overshot.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->area_overshot);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_percentage_completed;
      u_percentage_completed.base = 0;
      u_percentage_completed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_percentage_completed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_percentage_completed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_percentage_completed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->percentage_completed = u_percentage_completed.real;
      offset += sizeof(this->percentage_completed);
      union {
        float real;
        uint32_t base;
      } u_percentage_missed;
      u_percentage_missed.base = 0;
      u_percentage_missed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_percentage_missed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_percentage_missed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_percentage_missed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->percentage_missed = u_percentage_missed.real;
      offset += sizeof(this->percentage_missed);
      union {
        float real;
        uint32_t base;
      } u_percentage_overshot;
      u_percentage_overshot.base = 0;
      u_percentage_overshot.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_percentage_overshot.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_percentage_overshot.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_percentage_overshot.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->percentage_overshot = u_percentage_overshot.real;
      offset += sizeof(this->percentage_overshot);
      union {
        float real;
        uint32_t base;
      } u_area_completed;
      u_area_completed.base = 0;
      u_area_completed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_area_completed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_area_completed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_area_completed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->area_completed = u_area_completed.real;
      offset += sizeof(this->area_completed);
      union {
        float real;
        uint32_t base;
      } u_area_missed;
      u_area_missed.base = 0;
      u_area_missed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_area_missed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_area_missed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_area_missed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->area_missed = u_area_missed.real;
      offset += sizeof(this->area_missed);
      union {
        float real;
        uint32_t base;
      } u_area_overshot;
      u_area_overshot.base = 0;
      u_area_overshot.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_area_overshot.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_area_overshot.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_area_overshot.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->area_overshot = u_area_overshot.real;
      offset += sizeof(this->area_overshot);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/CoverageStatistics"; };
    virtual const char * getMD5() override { return "df0f8b5e286675a990aed86727fb4616"; };

  };

}
#endif
