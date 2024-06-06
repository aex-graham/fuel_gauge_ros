#ifndef _ROS_greenzie_msgs_ImageWithDetections_h
#define _ROS_greenzie_msgs_ImageWithDetections_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "depthai_ros_msgs/SpatialDetectionArray.h"

namespace greenzie_msgs
{

  class ImageWithDetections : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      typedef depthai_ros_msgs::SpatialDetectionArray _detections_type;
      _detections_type detections;

    ImageWithDetections():
      image(),
      detections()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->image.serialize(outbuffer + offset);
      offset += this->detections.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->detections.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/ImageWithDetections"; };
    virtual const char * getMD5() override { return "4c79974f94b6385a79bd869ec52be1ef"; };

  };

}
#endif
