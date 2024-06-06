#ifndef _ROS_fixposition_driver_ros1_Speed_h
#define _ROS_fixposition_driver_ros1_Speed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "fixposition_driver_ros1/WheelSensor.h"

namespace fixposition_driver_ros1
{

  class Speed : public ros::Msg
  {
    public:
      uint32_t sensors_length;
      typedef fixposition_driver_ros1::WheelSensor _sensors_type;
      _sensors_type st_sensors;
      _sensors_type * sensors;

    Speed():
      sensors_length(0), st_sensors(), sensors(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->sensors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sensors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sensors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensors_length);
      for( uint32_t i = 0; i < sensors_length; i++){
      offset += this->sensors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t sensors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sensors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sensors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sensors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sensors_length);
      if(sensors_lengthT > sensors_length)
        this->sensors = (fixposition_driver_ros1::WheelSensor*)realloc(this->sensors, sensors_lengthT * sizeof(fixposition_driver_ros1::WheelSensor));
      sensors_length = sensors_lengthT;
      for( uint32_t i = 0; i < sensors_length; i++){
      offset += this->st_sensors.deserialize(inbuffer + offset);
        memcpy( &(this->sensors[i]), &(this->st_sensors), sizeof(fixposition_driver_ros1::WheelSensor));
      }
     return offset;
    }

    virtual const char * getType() override { return "fixposition_driver_ros1/Speed"; };
    virtual const char * getMD5() override { return "c35c230ca1b330732decce9c593d3ae9"; };

  };

}
#endif
