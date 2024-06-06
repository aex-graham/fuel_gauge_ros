#ifndef _ROS_luna_msgs_PerceptionStatus_h
#define _ROS_luna_msgs_PerceptionStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace luna_msgs
{

  class PerceptionStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _perception_system_status_type;
      _perception_system_status_type perception_system_status;
      typedef bool _front_left_radar_status_rx_type;
      _front_left_radar_status_rx_type front_left_radar_status_rx;
      typedef bool _front_center_radar_status_rx_type;
      _front_center_radar_status_rx_type front_center_radar_status_rx;
      typedef bool _front_right_radar_status_rx_type;
      _front_right_radar_status_rx_type front_right_radar_status_rx;
      typedef bool _rear_right_radar_status_rx_type;
      _rear_right_radar_status_rx_type rear_right_radar_status_rx;
      typedef bool _rear_left_radar_status_rx_type;
      _rear_left_radar_status_rx_type rear_left_radar_status_rx;
      typedef bool _front_left_radar_points_rx_type;
      _front_left_radar_points_rx_type front_left_radar_points_rx;
      typedef bool _front_center_radar_points_rx_type;
      _front_center_radar_points_rx_type front_center_radar_points_rx;
      typedef bool _front_right_radar_points_rx_type;
      _front_right_radar_points_rx_type front_right_radar_points_rx;
      typedef bool _rear_right_radar_points_rx_type;
      _rear_right_radar_points_rx_type rear_right_radar_points_rx;
      typedef bool _rear_left_radar_points_rx_type;
      _rear_left_radar_points_rx_type rear_left_radar_points_rx;
      enum { PERCEPTION_STATUS_OK = 1 };

    PerceptionStatus():
      header(),
      perception_system_status(0),
      front_left_radar_status_rx(0),
      front_center_radar_status_rx(0),
      front_right_radar_status_rx(0),
      rear_right_radar_status_rx(0),
      rear_left_radar_status_rx(0),
      front_left_radar_points_rx(0),
      front_center_radar_points_rx(0),
      front_right_radar_points_rx(0),
      rear_right_radar_points_rx(0),
      rear_left_radar_points_rx(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->perception_system_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->perception_system_status);
      union {
        bool real;
        uint8_t base;
      } u_front_left_radar_status_rx;
      u_front_left_radar_status_rx.real = this->front_left_radar_status_rx;
      *(outbuffer + offset + 0) = (u_front_left_radar_status_rx.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_left_radar_status_rx);
      union {
        bool real;
        uint8_t base;
      } u_front_center_radar_status_rx;
      u_front_center_radar_status_rx.real = this->front_center_radar_status_rx;
      *(outbuffer + offset + 0) = (u_front_center_radar_status_rx.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_center_radar_status_rx);
      union {
        bool real;
        uint8_t base;
      } u_front_right_radar_status_rx;
      u_front_right_radar_status_rx.real = this->front_right_radar_status_rx;
      *(outbuffer + offset + 0) = (u_front_right_radar_status_rx.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_right_radar_status_rx);
      union {
        bool real;
        uint8_t base;
      } u_rear_right_radar_status_rx;
      u_rear_right_radar_status_rx.real = this->rear_right_radar_status_rx;
      *(outbuffer + offset + 0) = (u_rear_right_radar_status_rx.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_right_radar_status_rx);
      union {
        bool real;
        uint8_t base;
      } u_rear_left_radar_status_rx;
      u_rear_left_radar_status_rx.real = this->rear_left_radar_status_rx;
      *(outbuffer + offset + 0) = (u_rear_left_radar_status_rx.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_left_radar_status_rx);
      union {
        bool real;
        uint8_t base;
      } u_front_left_radar_points_rx;
      u_front_left_radar_points_rx.real = this->front_left_radar_points_rx;
      *(outbuffer + offset + 0) = (u_front_left_radar_points_rx.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_left_radar_points_rx);
      union {
        bool real;
        uint8_t base;
      } u_front_center_radar_points_rx;
      u_front_center_radar_points_rx.real = this->front_center_radar_points_rx;
      *(outbuffer + offset + 0) = (u_front_center_radar_points_rx.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_center_radar_points_rx);
      union {
        bool real;
        uint8_t base;
      } u_front_right_radar_points_rx;
      u_front_right_radar_points_rx.real = this->front_right_radar_points_rx;
      *(outbuffer + offset + 0) = (u_front_right_radar_points_rx.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->front_right_radar_points_rx);
      union {
        bool real;
        uint8_t base;
      } u_rear_right_radar_points_rx;
      u_rear_right_radar_points_rx.real = this->rear_right_radar_points_rx;
      *(outbuffer + offset + 0) = (u_rear_right_radar_points_rx.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_right_radar_points_rx);
      union {
        bool real;
        uint8_t base;
      } u_rear_left_radar_points_rx;
      u_rear_left_radar_points_rx.real = this->rear_left_radar_points_rx;
      *(outbuffer + offset + 0) = (u_rear_left_radar_points_rx.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rear_left_radar_points_rx);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->perception_system_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->perception_system_status);
      union {
        bool real;
        uint8_t base;
      } u_front_left_radar_status_rx;
      u_front_left_radar_status_rx.base = 0;
      u_front_left_radar_status_rx.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_left_radar_status_rx = u_front_left_radar_status_rx.real;
      offset += sizeof(this->front_left_radar_status_rx);
      union {
        bool real;
        uint8_t base;
      } u_front_center_radar_status_rx;
      u_front_center_radar_status_rx.base = 0;
      u_front_center_radar_status_rx.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_center_radar_status_rx = u_front_center_radar_status_rx.real;
      offset += sizeof(this->front_center_radar_status_rx);
      union {
        bool real;
        uint8_t base;
      } u_front_right_radar_status_rx;
      u_front_right_radar_status_rx.base = 0;
      u_front_right_radar_status_rx.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_right_radar_status_rx = u_front_right_radar_status_rx.real;
      offset += sizeof(this->front_right_radar_status_rx);
      union {
        bool real;
        uint8_t base;
      } u_rear_right_radar_status_rx;
      u_rear_right_radar_status_rx.base = 0;
      u_rear_right_radar_status_rx.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_right_radar_status_rx = u_rear_right_radar_status_rx.real;
      offset += sizeof(this->rear_right_radar_status_rx);
      union {
        bool real;
        uint8_t base;
      } u_rear_left_radar_status_rx;
      u_rear_left_radar_status_rx.base = 0;
      u_rear_left_radar_status_rx.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_left_radar_status_rx = u_rear_left_radar_status_rx.real;
      offset += sizeof(this->rear_left_radar_status_rx);
      union {
        bool real;
        uint8_t base;
      } u_front_left_radar_points_rx;
      u_front_left_radar_points_rx.base = 0;
      u_front_left_radar_points_rx.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_left_radar_points_rx = u_front_left_radar_points_rx.real;
      offset += sizeof(this->front_left_radar_points_rx);
      union {
        bool real;
        uint8_t base;
      } u_front_center_radar_points_rx;
      u_front_center_radar_points_rx.base = 0;
      u_front_center_radar_points_rx.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_center_radar_points_rx = u_front_center_radar_points_rx.real;
      offset += sizeof(this->front_center_radar_points_rx);
      union {
        bool real;
        uint8_t base;
      } u_front_right_radar_points_rx;
      u_front_right_radar_points_rx.base = 0;
      u_front_right_radar_points_rx.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->front_right_radar_points_rx = u_front_right_radar_points_rx.real;
      offset += sizeof(this->front_right_radar_points_rx);
      union {
        bool real;
        uint8_t base;
      } u_rear_right_radar_points_rx;
      u_rear_right_radar_points_rx.base = 0;
      u_rear_right_radar_points_rx.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_right_radar_points_rx = u_rear_right_radar_points_rx.real;
      offset += sizeof(this->rear_right_radar_points_rx);
      union {
        bool real;
        uint8_t base;
      } u_rear_left_radar_points_rx;
      u_rear_left_radar_points_rx.base = 0;
      u_rear_left_radar_points_rx.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rear_left_radar_points_rx = u_rear_left_radar_points_rx.real;
      offset += sizeof(this->rear_left_radar_points_rx);
     return offset;
    }

    virtual const char * getType() override { return "luna_msgs/PerceptionStatus"; };
    virtual const char * getMD5() override { return "3b2e8f5de1ce48e6581c582949319df2"; };

  };

}
#endif
