#ifndef _ROS_greenzie_msgs_UltrasonicArray_h
#define _ROS_greenzie_msgs_UltrasonicArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace greenzie_msgs
{

  class UltrasonicArray : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t data_length;
      typedef int32_t _data_type;
      _data_type st_data;
      _data_type * data;
      uint32_t time_sec_length;
      typedef uint32_t _time_sec_type;
      _time_sec_type st_time_sec;
      _time_sec_type * time_sec;
      uint32_t time_nsec_length;
      typedef uint32_t _time_nsec_type;
      _time_nsec_type st_time_nsec;
      _time_nsec_type * time_nsec;

    UltrasonicArray():
      header(),
      data_length(0), st_data(), data(nullptr),
      time_sec_length(0), st_time_sec(), time_sec(nullptr),
      time_nsec_length(0), st_time_nsec(), time_nsec(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_datai;
      u_datai.real = this->data[i];
      *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_datai.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_datai.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_datai.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      *(outbuffer + offset + 0) = (this->time_sec_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_sec_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_sec_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_sec_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_sec_length);
      for( uint32_t i = 0; i < time_sec_length; i++){
      *(outbuffer + offset + 0) = (this->time_sec[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_sec[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_sec[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_sec[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_sec[i]);
      }
      *(outbuffer + offset + 0) = (this->time_nsec_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_nsec_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_nsec_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_nsec_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_nsec_length);
      for( uint32_t i = 0; i < time_nsec_length; i++){
      *(outbuffer + offset + 0) = (this->time_nsec[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_nsec[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_nsec[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_nsec[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_nsec[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (int32_t*)realloc(this->data, data_lengthT * sizeof(int32_t));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_data;
      u_st_data.base = 0;
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_data = u_st_data.real;
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(int32_t));
      }
      uint32_t time_sec_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      time_sec_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      time_sec_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      time_sec_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->time_sec_length);
      if(time_sec_lengthT > time_sec_length)
        this->time_sec = (uint32_t*)realloc(this->time_sec, time_sec_lengthT * sizeof(uint32_t));
      time_sec_length = time_sec_lengthT;
      for( uint32_t i = 0; i < time_sec_length; i++){
      this->st_time_sec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_time_sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_time_sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_time_sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_time_sec);
        memcpy( &(this->time_sec[i]), &(this->st_time_sec), sizeof(uint32_t));
      }
      uint32_t time_nsec_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      time_nsec_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      time_nsec_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      time_nsec_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->time_nsec_length);
      if(time_nsec_lengthT > time_nsec_length)
        this->time_nsec = (uint32_t*)realloc(this->time_nsec, time_nsec_lengthT * sizeof(uint32_t));
      time_nsec_length = time_nsec_lengthT;
      for( uint32_t i = 0; i < time_nsec_length; i++){
      this->st_time_nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->st_time_nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_time_nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_time_nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_time_nsec);
        memcpy( &(this->time_nsec[i]), &(this->st_time_nsec), sizeof(uint32_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/UltrasonicArray"; };
    virtual const char * getMD5() override { return "62386e373311fb086db4f020b2b79bba"; };

  };

}
#endif
