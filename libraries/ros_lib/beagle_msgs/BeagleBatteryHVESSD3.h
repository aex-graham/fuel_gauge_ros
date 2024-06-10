#ifndef _ROS_beagle_msgs_BeagleBatteryHVESSD3_h
#define _ROS_beagle_msgs_BeagleBatteryHVESSD3_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace beagle_msgs
{

  class BeagleBatteryHVESSD3 : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _highest_cell_temp_type;
      _highest_cell_temp_type highest_cell_temp;
      typedef float _lowest_cell_temp_type;
      _lowest_cell_temp_type lowest_cell_temp;
      typedef float _average_cell_temp_type;
      _average_cell_temp_type average_cell_temp;
      typedef uint16_t _cell_temp_diff_status_type;
      _cell_temp_diff_status_type cell_temp_diff_status;

    BeagleBatteryHVESSD3():
      header(),
      highest_cell_temp(0),
      lowest_cell_temp(0),
      average_cell_temp(0),
      cell_temp_diff_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_highest_cell_temp;
      u_highest_cell_temp.real = this->highest_cell_temp;
      *(outbuffer + offset + 0) = (u_highest_cell_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_highest_cell_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_highest_cell_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_highest_cell_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->highest_cell_temp);
      union {
        float real;
        uint32_t base;
      } u_lowest_cell_temp;
      u_lowest_cell_temp.real = this->lowest_cell_temp;
      *(outbuffer + offset + 0) = (u_lowest_cell_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lowest_cell_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lowest_cell_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lowest_cell_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lowest_cell_temp);
      union {
        float real;
        uint32_t base;
      } u_average_cell_temp;
      u_average_cell_temp.real = this->average_cell_temp;
      *(outbuffer + offset + 0) = (u_average_cell_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_average_cell_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_average_cell_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_average_cell_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->average_cell_temp);
      *(outbuffer + offset + 0) = (this->cell_temp_diff_status >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cell_temp_diff_status >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cell_temp_diff_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_highest_cell_temp;
      u_highest_cell_temp.base = 0;
      u_highest_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_highest_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_highest_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_highest_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->highest_cell_temp = u_highest_cell_temp.real;
      offset += sizeof(this->highest_cell_temp);
      union {
        float real;
        uint32_t base;
      } u_lowest_cell_temp;
      u_lowest_cell_temp.base = 0;
      u_lowest_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lowest_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lowest_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lowest_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lowest_cell_temp = u_lowest_cell_temp.real;
      offset += sizeof(this->lowest_cell_temp);
      union {
        float real;
        uint32_t base;
      } u_average_cell_temp;
      u_average_cell_temp.base = 0;
      u_average_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_average_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_average_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_average_cell_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->average_cell_temp = u_average_cell_temp.real;
      offset += sizeof(this->average_cell_temp);
      this->cell_temp_diff_status =  ((uint16_t) (*(inbuffer + offset)));
      this->cell_temp_diff_status |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->cell_temp_diff_status);
     return offset;
    }

    virtual const char * getType() override { return "beagle_msgs/BeagleBatteryHVESSD3"; };
    virtual const char * getMD5() override { return "f920de826d91bb2fba32ffefcef4c806"; };

  };

}
#endif
