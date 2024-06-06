#ifndef _ROS_depthai_ros_msgs_ImuWithMagneticField_h
#define _ROS_depthai_ros_msgs_ImuWithMagneticField_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/MagneticField.h"

namespace depthai_ros_msgs
{

  class ImuWithMagneticField : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef sensor_msgs::Imu _imu_type;
      _imu_type imu;
      typedef sensor_msgs::MagneticField _field_type;
      _field_type field;

    ImuWithMagneticField():
      header(),
      imu(),
      field()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->imu.serialize(outbuffer + offset);
      offset += this->field.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->imu.deserialize(inbuffer + offset);
      offset += this->field.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "depthai_ros_msgs/ImuWithMagneticField"; };
    virtual const char * getMD5() override { return "7542bff2bd62a394f0408d003d2b52df"; };

  };

}
#endif
