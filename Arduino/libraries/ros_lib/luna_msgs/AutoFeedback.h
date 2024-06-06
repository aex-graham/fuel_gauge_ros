#ifndef _ROS_luna_msgs_AutoFeedback_h
#define _ROS_luna_msgs_AutoFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace luna_msgs
{

  class AutoFeedback : public ros::Msg
  {
    public:
      typedef uint8_t _state_type;
      _state_type state;
      typedef uint8_t _cell_status_type;
      _cell_status_type cell_status;
      typedef bool _has_map_type;
      _has_map_type has_map;
      typedef bool _done_mowing_type;
      _done_mowing_type done_mowing;
      typedef uint8_t _vrtk_gnss1_status_type;
      _vrtk_gnss1_status_type vrtk_gnss1_status;
      typedef uint8_t _vrtk_gnss2_status_type;
      _vrtk_gnss2_status_type vrtk_gnss2_status;
      typedef uint8_t _vrtk_fusion_status_type;
      _vrtk_fusion_status_type vrtk_fusion_status;
      typedef uint8_t _vrtk_imu_bias_status_type;
      _vrtk_imu_bias_status_type vrtk_imu_bias_status;
      typedef uint8_t _vrtk_wheelspeed_status_type;
      _vrtk_wheelspeed_status_type vrtk_wheelspeed_status;
      typedef uint16_t _striping_angle_deg_type;
      _striping_angle_deg_type striping_angle_deg;
      typedef uint16_t _yaw_deg_type;
      _yaw_deg_type yaw_deg;
      enum { READY =  0 };
      enum { MAP =  1 };
      enum { INIT =  2 };
      enum { MOW =  3 };
      enum { VALIDATION =  4 };
      enum { UPDATING =  5 };
      enum { ERROR =  6 };

    AutoFeedback():
      state(0),
      cell_status(0),
      has_map(0),
      done_mowing(0),
      vrtk_gnss1_status(0),
      vrtk_gnss2_status(0),
      vrtk_fusion_status(0),
      vrtk_imu_bias_status(0),
      vrtk_wheelspeed_status(0),
      striping_angle_deg(0),
      yaw_deg(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      *(outbuffer + offset + 0) = (this->cell_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->cell_status);
      union {
        bool real;
        uint8_t base;
      } u_has_map;
      u_has_map.real = this->has_map;
      *(outbuffer + offset + 0) = (u_has_map.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->has_map);
      union {
        bool real;
        uint8_t base;
      } u_done_mowing;
      u_done_mowing.real = this->done_mowing;
      *(outbuffer + offset + 0) = (u_done_mowing.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->done_mowing);
      *(outbuffer + offset + 0) = (this->vrtk_gnss1_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vrtk_gnss1_status);
      *(outbuffer + offset + 0) = (this->vrtk_gnss2_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vrtk_gnss2_status);
      *(outbuffer + offset + 0) = (this->vrtk_fusion_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vrtk_fusion_status);
      *(outbuffer + offset + 0) = (this->vrtk_imu_bias_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vrtk_imu_bias_status);
      *(outbuffer + offset + 0) = (this->vrtk_wheelspeed_status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->vrtk_wheelspeed_status);
      *(outbuffer + offset + 0) = (this->striping_angle_deg >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->striping_angle_deg >> (8 * 1)) & 0xFF;
      offset += sizeof(this->striping_angle_deg);
      *(outbuffer + offset + 0) = (this->yaw_deg >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->yaw_deg >> (8 * 1)) & 0xFF;
      offset += sizeof(this->yaw_deg);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
      this->cell_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->cell_status);
      union {
        bool real;
        uint8_t base;
      } u_has_map;
      u_has_map.base = 0;
      u_has_map.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->has_map = u_has_map.real;
      offset += sizeof(this->has_map);
      union {
        bool real;
        uint8_t base;
      } u_done_mowing;
      u_done_mowing.base = 0;
      u_done_mowing.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->done_mowing = u_done_mowing.real;
      offset += sizeof(this->done_mowing);
      this->vrtk_gnss1_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vrtk_gnss1_status);
      this->vrtk_gnss2_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vrtk_gnss2_status);
      this->vrtk_fusion_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vrtk_fusion_status);
      this->vrtk_imu_bias_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vrtk_imu_bias_status);
      this->vrtk_wheelspeed_status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->vrtk_wheelspeed_status);
      this->striping_angle_deg =  ((uint16_t) (*(inbuffer + offset)));
      this->striping_angle_deg |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->striping_angle_deg);
      this->yaw_deg =  ((uint16_t) (*(inbuffer + offset)));
      this->yaw_deg |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->yaw_deg);
     return offset;
    }

    virtual const char * getType() override { return "luna_msgs/AutoFeedback"; };
    virtual const char * getMD5() override { return "fa8ad50adf7e7cc0241d123c6f87b8ed"; };

  };

}
#endif
