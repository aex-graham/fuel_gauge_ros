#ifndef _ROS_greenzie_msgs_DepthaiDeviceInfo_h
#define _ROS_greenzie_msgs_DepthaiDeviceInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "greenzie_msgs/DepthaiSensorInfo.h"

namespace greenzie_msgs
{

  class DepthaiDeviceInfo : public ros::Msg
  {
    public:
      typedef uint8_t _interface_state_type;
      _interface_state_type interface_state;
      typedef bool _is_pipeline_running_type;
      _is_pipeline_running_type is_pipeline_running;
      typedef const char* _device_state_type;
      _device_state_type device_state;
      typedef const char* _device_status_type;
      _device_status_type device_status;
      typedef const char* _mx_id_type;
      _mx_id_type mx_id;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _ip_type;
      _ip_type ip;
      typedef const char* _protocol_type;
      _protocol_type protocol;
      typedef const char* _platform_type;
      _platform_type platform;
      typedef const char* _bootloader_version_type;
      _bootloader_version_type bootloader_version;
      typedef bool _found_unavailable_device_type;
      _found_unavailable_device_type found_unavailable_device;
      typedef bool _found_other_mx_id_type;
      _found_other_mx_id_type found_other_mx_id;
      typedef bool _is_wide_angle_type;
      _is_wide_angle_type is_wide_angle;
      typedef float _camera_hfov_type;
      _camera_hfov_type camera_hfov;
      uint32_t sensor_info_length;
      typedef greenzie_msgs::DepthaiSensorInfo _sensor_info_type;
      _sensor_info_type st_sensor_info;
      _sensor_info_type * sensor_info;
      enum { STATE_SEARCHING =  0 };
      enum { STATE_PIPELINE_SETUP =  1 };
      enum { STATE_EXECUTING =  2 };

    DepthaiDeviceInfo():
      interface_state(0),
      is_pipeline_running(0),
      device_state(""),
      device_status(""),
      mx_id(""),
      name(""),
      ip(""),
      protocol(""),
      platform(""),
      bootloader_version(""),
      found_unavailable_device(0),
      found_other_mx_id(0),
      is_wide_angle(0),
      camera_hfov(0),
      sensor_info_length(0), st_sensor_info(), sensor_info(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->interface_state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->interface_state);
      union {
        bool real;
        uint8_t base;
      } u_is_pipeline_running;
      u_is_pipeline_running.real = this->is_pipeline_running;
      *(outbuffer + offset + 0) = (u_is_pipeline_running.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_pipeline_running);
      uint32_t length_device_state = strlen(this->device_state);
      varToArr(outbuffer + offset, length_device_state);
      offset += 4;
      memcpy(outbuffer + offset, this->device_state, length_device_state);
      offset += length_device_state;
      uint32_t length_device_status = strlen(this->device_status);
      varToArr(outbuffer + offset, length_device_status);
      offset += 4;
      memcpy(outbuffer + offset, this->device_status, length_device_status);
      offset += length_device_status;
      uint32_t length_mx_id = strlen(this->mx_id);
      varToArr(outbuffer + offset, length_mx_id);
      offset += 4;
      memcpy(outbuffer + offset, this->mx_id, length_mx_id);
      offset += length_mx_id;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_ip = strlen(this->ip);
      varToArr(outbuffer + offset, length_ip);
      offset += 4;
      memcpy(outbuffer + offset, this->ip, length_ip);
      offset += length_ip;
      uint32_t length_protocol = strlen(this->protocol);
      varToArr(outbuffer + offset, length_protocol);
      offset += 4;
      memcpy(outbuffer + offset, this->protocol, length_protocol);
      offset += length_protocol;
      uint32_t length_platform = strlen(this->platform);
      varToArr(outbuffer + offset, length_platform);
      offset += 4;
      memcpy(outbuffer + offset, this->platform, length_platform);
      offset += length_platform;
      uint32_t length_bootloader_version = strlen(this->bootloader_version);
      varToArr(outbuffer + offset, length_bootloader_version);
      offset += 4;
      memcpy(outbuffer + offset, this->bootloader_version, length_bootloader_version);
      offset += length_bootloader_version;
      union {
        bool real;
        uint8_t base;
      } u_found_unavailable_device;
      u_found_unavailable_device.real = this->found_unavailable_device;
      *(outbuffer + offset + 0) = (u_found_unavailable_device.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->found_unavailable_device);
      union {
        bool real;
        uint8_t base;
      } u_found_other_mx_id;
      u_found_other_mx_id.real = this->found_other_mx_id;
      *(outbuffer + offset + 0) = (u_found_other_mx_id.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->found_other_mx_id);
      union {
        bool real;
        uint8_t base;
      } u_is_wide_angle;
      u_is_wide_angle.real = this->is_wide_angle;
      *(outbuffer + offset + 0) = (u_is_wide_angle.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_wide_angle);
      union {
        float real;
        uint32_t base;
      } u_camera_hfov;
      u_camera_hfov.real = this->camera_hfov;
      *(outbuffer + offset + 0) = (u_camera_hfov.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_camera_hfov.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_camera_hfov.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_camera_hfov.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->camera_hfov);
      *(outbuffer + offset + 0) = (this->sensor_info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sensor_info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sensor_info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sensor_info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sensor_info_length);
      for( uint32_t i = 0; i < sensor_info_length; i++){
      offset += this->sensor_info[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->interface_state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->interface_state);
      union {
        bool real;
        uint8_t base;
      } u_is_pipeline_running;
      u_is_pipeline_running.base = 0;
      u_is_pipeline_running.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_pipeline_running = u_is_pipeline_running.real;
      offset += sizeof(this->is_pipeline_running);
      uint32_t length_device_state;
      arrToVar(length_device_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_device_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_device_state-1]=0;
      this->device_state = (char *)(inbuffer + offset-1);
      offset += length_device_state;
      uint32_t length_device_status;
      arrToVar(length_device_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_device_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_device_status-1]=0;
      this->device_status = (char *)(inbuffer + offset-1);
      offset += length_device_status;
      uint32_t length_mx_id;
      arrToVar(length_mx_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mx_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mx_id-1]=0;
      this->mx_id = (char *)(inbuffer + offset-1);
      offset += length_mx_id;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_ip;
      arrToVar(length_ip, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ip; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ip-1]=0;
      this->ip = (char *)(inbuffer + offset-1);
      offset += length_ip;
      uint32_t length_protocol;
      arrToVar(length_protocol, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_protocol; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_protocol-1]=0;
      this->protocol = (char *)(inbuffer + offset-1);
      offset += length_protocol;
      uint32_t length_platform;
      arrToVar(length_platform, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_platform; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_platform-1]=0;
      this->platform = (char *)(inbuffer + offset-1);
      offset += length_platform;
      uint32_t length_bootloader_version;
      arrToVar(length_bootloader_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_bootloader_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_bootloader_version-1]=0;
      this->bootloader_version = (char *)(inbuffer + offset-1);
      offset += length_bootloader_version;
      union {
        bool real;
        uint8_t base;
      } u_found_unavailable_device;
      u_found_unavailable_device.base = 0;
      u_found_unavailable_device.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->found_unavailable_device = u_found_unavailable_device.real;
      offset += sizeof(this->found_unavailable_device);
      union {
        bool real;
        uint8_t base;
      } u_found_other_mx_id;
      u_found_other_mx_id.base = 0;
      u_found_other_mx_id.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->found_other_mx_id = u_found_other_mx_id.real;
      offset += sizeof(this->found_other_mx_id);
      union {
        bool real;
        uint8_t base;
      } u_is_wide_angle;
      u_is_wide_angle.base = 0;
      u_is_wide_angle.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_wide_angle = u_is_wide_angle.real;
      offset += sizeof(this->is_wide_angle);
      union {
        float real;
        uint32_t base;
      } u_camera_hfov;
      u_camera_hfov.base = 0;
      u_camera_hfov.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_camera_hfov.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_camera_hfov.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_camera_hfov.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->camera_hfov = u_camera_hfov.real;
      offset += sizeof(this->camera_hfov);
      uint32_t sensor_info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sensor_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sensor_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sensor_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sensor_info_length);
      if(sensor_info_lengthT > sensor_info_length)
        this->sensor_info = (greenzie_msgs::DepthaiSensorInfo*)realloc(this->sensor_info, sensor_info_lengthT * sizeof(greenzie_msgs::DepthaiSensorInfo));
      sensor_info_length = sensor_info_lengthT;
      for( uint32_t i = 0; i < sensor_info_length; i++){
      offset += this->st_sensor_info.deserialize(inbuffer + offset);
        memcpy( &(this->sensor_info[i]), &(this->st_sensor_info), sizeof(greenzie_msgs::DepthaiSensorInfo));
      }
     return offset;
    }

    virtual const char * getType() override { return "greenzie_msgs/DepthaiDeviceInfo"; };
    virtual const char * getMD5() override { return "682c8798838194d5e1cc07837a4539bf"; };

  };

}
#endif
