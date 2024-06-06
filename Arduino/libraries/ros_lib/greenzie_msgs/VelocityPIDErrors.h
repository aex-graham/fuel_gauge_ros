#ifndef _ROS_greenzie_msgs_VelocityPIDErrors_h
#define _ROS_greenzie_msgs_VelocityPIDErrors_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class VelocityPIDErrors : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _left_setpoint_type;
      _left_setpoint_type left_setpoint;
      typedef float _left_pid_target_type;
      _left_pid_target_type left_pid_target;
      typedef float _left_actual_type;
      _left_actual_type left_actual;
      typedef float _left_feedforward_type;
      _left_feedforward_type left_feedforward;
      typedef float _left_proportional_type;
      _left_proportional_type left_proportional;
      typedef float _left_integral_type;
      _left_integral_type left_integral;
      typedef float _left_derivative_type;
      _left_derivative_type left_derivative;
      typedef float _left_output_type;
      _left_output_type left_output;
      typedef float _left_total_type;
      _left_total_type left_total;
      typedef float _left_filtered_type;
      _left_filtered_type left_filtered;
      typedef float _left_scaled_type;
      _left_scaled_type left_scaled;
      typedef float _right_setpoint_type;
      _right_setpoint_type right_setpoint;
      typedef float _right_pid_target_type;
      _right_pid_target_type right_pid_target;
      typedef float _right_actual_type;
      _right_actual_type right_actual;
      typedef float _right_feedforward_type;
      _right_feedforward_type right_feedforward;
      typedef float _right_proportional_type;
      _right_proportional_type right_proportional;
      typedef float _right_integral_type;
      _right_integral_type right_integral;
      typedef float _right_derivative_type;
      _right_derivative_type right_derivative;
      typedef float _right_output_type;
      _right_output_type right_output;
      typedef float _right_total_type;
      _right_total_type right_total;
      typedef float _right_filtered_type;
      _right_filtered_type right_filtered;
      typedef float _right_scaled_type;
      _right_scaled_type right_scaled;

    VelocityPIDErrors():
      header(),
      left_setpoint(0),
      left_pid_target(0),
      left_actual(0),
      left_feedforward(0),
      left_proportional(0),
      left_integral(0),
      left_derivative(0),
      left_output(0),
      left_total(0),
      left_filtered(0),
      left_scaled(0),
      right_setpoint(0),
      right_pid_target(0),
      right_actual(0),
      right_feedforward(0),
      right_proportional(0),
      right_integral(0),
      right_derivative(0),
      right_output(0),
      right_total(0),
      right_filtered(0),
      right_scaled(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_setpoint);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_pid_target);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_actual);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_feedforward);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_proportional);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_integral);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_derivative);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_output);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_total);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_filtered);
      offset += serializeAvrFloat64(outbuffer + offset, this->left_scaled);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_setpoint);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_pid_target);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_actual);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_feedforward);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_proportional);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_integral);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_derivative);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_output);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_total);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_filtered);
      offset += serializeAvrFloat64(outbuffer + offset, this->right_scaled);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_setpoint));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_pid_target));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_actual));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_feedforward));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_proportional));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_integral));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_derivative));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_output));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_total));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_filtered));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->left_scaled));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_setpoint));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_pid_target));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_actual));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_feedforward));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_proportional));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_integral));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_derivative));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_output));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_total));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_filtered));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->right_scaled));
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/VelocityPIDErrors"; };
    virtual const char * getMD5() override { return "41d4036047735ccae39713f05f94e8b6"; };

  };

}
#endif
