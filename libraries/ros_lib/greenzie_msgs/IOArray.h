#ifndef _ROS_greenzie_msgs_IOArray_h
#define _ROS_greenzie_msgs_IOArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class IOArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t digital_data_length;
      typedef bool _digital_data_type;
      _digital_data_type st_digital_data;
      _digital_data_type * digital_data;
      uint32_t analog_data_length;
      typedef int32_t _analog_data_type;
      _analog_data_type st_analog_data;
      _analog_data_type * analog_data;

    IOArray():
      header(),
      digital_data_length(0), st_digital_data(), digital_data(nullptr),
      analog_data_length(0), st_analog_data(), analog_data(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->digital_data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->digital_data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->digital_data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->digital_data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->digital_data_length);
      for( uint32_t i = 0; i < digital_data_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_digital_datai;
      u_digital_datai.real = this->digital_data[i];
      *(outbuffer + offset + 0) = (u_digital_datai.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_data[i]);
      }
      *(outbuffer + offset + 0) = (this->analog_data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->analog_data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->analog_data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->analog_data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->analog_data_length);
      for( uint32_t i = 0; i < analog_data_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_analog_datai;
      u_analog_datai.real = this->analog_data[i];
      *(outbuffer + offset + 0) = (u_analog_datai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_analog_datai.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_analog_datai.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_analog_datai.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->analog_data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t digital_data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      digital_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      digital_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      digital_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->digital_data_length);
      if(digital_data_lengthT > digital_data_length)
        this->digital_data = (bool*)realloc(this->digital_data, digital_data_lengthT * sizeof(bool));
      digital_data_length = digital_data_lengthT;
      for( uint32_t i = 0; i < digital_data_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_digital_data;
      u_st_digital_data.base = 0;
      u_st_digital_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_digital_data = u_st_digital_data.real;
      offset += sizeof(this->st_digital_data);
        memcpy( &(this->digital_data[i]), &(this->st_digital_data), sizeof(bool));
      }
      uint32_t analog_data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      analog_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      analog_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      analog_data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->analog_data_length);
      if(analog_data_lengthT > analog_data_length)
        this->analog_data = (int32_t*)realloc(this->analog_data, analog_data_lengthT * sizeof(int32_t));
      analog_data_length = analog_data_lengthT;
      for( uint32_t i = 0; i < analog_data_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_analog_data;
      u_st_analog_data.base = 0;
      u_st_analog_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_analog_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_analog_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_analog_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_analog_data = u_st_analog_data.real;
      offset += sizeof(this->st_analog_data);
        memcpy( &(this->analog_data[i]), &(this->st_analog_data), sizeof(int32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/IOArray"; };
    virtual const char * getMD5() override { return "540592dec05294c6ee3d513e8a65a59b"; };

  };

}
#endif
