#ifndef _ROS_SERVICE_SetEncoderPrediction_h
#define _ROS_SERVICE_SetEncoderPrediction_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

static const char SETENCODERPREDICTION[] = "greenzie_msgs/SetEncoderPrediction";

  class SetEncoderPredictionRequest : public ros::Msg
  {
    public:
      typedef bool _enable_encoder_prediction_type;
      _enable_encoder_prediction_type enable_encoder_prediction;

    SetEncoderPredictionRequest():
      enable_encoder_prediction(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable_encoder_prediction;
      u_enable_encoder_prediction.real = this->enable_encoder_prediction;
      *(outbuffer + offset + 0) = (u_enable_encoder_prediction.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->enable_encoder_prediction);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_enable_encoder_prediction;
      u_enable_encoder_prediction.base = 0;
      u_enable_encoder_prediction.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->enable_encoder_prediction = u_enable_encoder_prediction.real;
      offset += sizeof(this->enable_encoder_prediction);
     return offset;
    }

    virtual const char * getType() override { return SETENCODERPREDICTION; };
    virtual const char * getMD5() override { return "0427b6c188afe1636c17867065c85ba5"; };

  };

  class SetEncoderPredictionResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    SetEncoderPredictionResponse():
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

    virtual const char * getType() override { return SETENCODERPREDICTION; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class SetEncoderPrediction {
    public:
    typedef SetEncoderPredictionRequest Request;
    typedef SetEncoderPredictionResponse Response;
  };

}
#endif
