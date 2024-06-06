#ifndef _ROS_greenzie_msgs_GpsEstimationData_h
#define _ROS_greenzie_msgs_GpsEstimationData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class GpsEstimationData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _x_interpolated_type;
      _x_interpolated_type x_interpolated;
      typedef float _y_interpolated_type;
      _y_interpolated_type y_interpolated;
      typedef float _speed_type;
      _speed_type speed;
      typedef float _speed_calibrated_type;
      _speed_calibrated_type speed_calibrated;
      typedef float _accel_type;
      _accel_type accel;
      typedef float _accel_calibrated_type;
      _accel_calibrated_type accel_calibrated;
      typedef float _expected_gps_accuracy_type;
      _expected_gps_accuracy_type expected_gps_accuracy;
      typedef float _min_speed_type;
      _min_speed_type min_speed;
      typedef float _local_min_speed_type;
      _local_min_speed_type local_min_speed;
      typedef float _speed_moving_average_type;
      _speed_moving_average_type speed_moving_average;
      typedef float _speed_moving_standard_dev_uncalibrated_type;
      _speed_moving_standard_dev_uncalibrated_type speed_moving_standard_dev_uncalibrated;
      typedef float _speed_moving_standard_dev_calibrated_type;
      _speed_moving_standard_dev_calibrated_type speed_moving_standard_dev_calibrated;
      typedef float _sensitivity_type;
      _sensitivity_type sensitivity;
      typedef float _confidence_interval_type;
      _confidence_interval_type confidence_interval;
      typedef bool _ekf_is_rejecting_data_type;
      _ekf_is_rejecting_data_type ekf_is_rejecting_data;
      typedef uint8_t _marked_state_type;
      _marked_state_type marked_state;
      typedef uint8_t _filter_reason_type;
      _filter_reason_type filter_reason;
      enum { ACCEPTED =  0 };
      enum { FILTERED =  1 };
      enum { INTERPOLATED =  2 };
      enum { NONE =  0 };
      enum { SPEED =  1 };
      enum { ACCELERATION =  2 };

    GpsEstimationData():
      header(),
      x(0),
      y(0),
      x_interpolated(0),
      y_interpolated(0),
      speed(0),
      speed_calibrated(0),
      accel(0),
      accel_calibrated(0),
      expected_gps_accuracy(0),
      min_speed(0),
      local_min_speed(0),
      speed_moving_average(0),
      speed_moving_standard_dev_uncalibrated(0),
      speed_moving_standard_dev_calibrated(0),
      sensitivity(0),
      confidence_interval(0),
      ekf_is_rejecting_data(0),
      marked_state(0),
      filter_reason(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->x_interpolated);
      offset += serializeAvrFloat64(outbuffer + offset, this->y_interpolated);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed_calibrated);
      offset += serializeAvrFloat64(outbuffer + offset, this->accel);
      offset += serializeAvrFloat64(outbuffer + offset, this->accel_calibrated);
      offset += serializeAvrFloat64(outbuffer + offset, this->expected_gps_accuracy);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->local_min_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed_moving_average);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed_moving_standard_dev_uncalibrated);
      offset += serializeAvrFloat64(outbuffer + offset, this->speed_moving_standard_dev_calibrated);
      offset += serializeAvrFloat64(outbuffer + offset, this->sensitivity);
      offset += serializeAvrFloat64(outbuffer + offset, this->confidence_interval);
      union {
        bool real;
        uint8_t base;
      } u_ekf_is_rejecting_data;
      u_ekf_is_rejecting_data.real = this->ekf_is_rejecting_data;
      *(outbuffer + offset + 0) = (u_ekf_is_rejecting_data.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ekf_is_rejecting_data);
      *(outbuffer + offset + 0) = (this->marked_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->marked_state);
      *(outbuffer + offset + 0) = (this->filter_reason >> (8 * 0)) & 0xFF;
      offset += sizeof(this->filter_reason);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x_interpolated));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y_interpolated));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed_calibrated));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accel_calibrated));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->expected_gps_accuracy));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->local_min_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed_moving_average));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed_moving_standard_dev_uncalibrated));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed_moving_standard_dev_calibrated));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->sensitivity));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->confidence_interval));
      union {
        bool real;
        uint8_t base;
      } u_ekf_is_rejecting_data;
      u_ekf_is_rejecting_data.base = 0;
      u_ekf_is_rejecting_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ekf_is_rejecting_data = u_ekf_is_rejecting_data.real;
      offset += sizeof(this->ekf_is_rejecting_data);
      this->marked_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->marked_state);
      this->filter_reason =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->filter_reason);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/GpsEstimationData"; };
    virtual const char * getMD5() override { return "85d20e32ae0570bb101b35367e8200fa"; };

  };

}
#endif
