#ifndef _ROS_SERVICE_GetVscSettings_h
#define _ROS_SERVICE_GetVscSettings_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hri_safe_remote_control_system
{

static const char GETVSCSETTINGS[] = "hri_safe_remote_control_system/GetVscSettings";

  class GetVscSettingsRequest : public ros::Msg
  {
    public:

    GetVscSettingsRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETVSCSETTINGS; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetVscSettingsResponse : public ros::Msg
  {
    public:
      typedef bool _srv_ready_type;
      _srv_ready_type srv_ready;
      typedef const char* _serial_number_type;
      _serial_number_type serial_number;
      typedef const char* _firmware_version_type;
      _firmware_version_type firmware_version;
      typedef int16_t _radio_power_db_type;
      _radio_power_db_type radio_power_db;

    GetVscSettingsResponse():
      srv_ready(0),
      serial_number(""),
      firmware_version(""),
      radio_power_db(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_srv_ready;
      u_srv_ready.real = this->srv_ready;
      *(outbuffer + offset + 0) = (u_srv_ready.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->srv_ready);
      uint32_t length_serial_number = strlen(this->serial_number);
      varToArr(outbuffer + offset, length_serial_number);
      offset += 4;
      memcpy(outbuffer + offset, this->serial_number, length_serial_number);
      offset += length_serial_number;
      uint32_t length_firmware_version = strlen(this->firmware_version);
      varToArr(outbuffer + offset, length_firmware_version);
      offset += 4;
      memcpy(outbuffer + offset, this->firmware_version, length_firmware_version);
      offset += length_firmware_version;
      union {
        int16_t real;
        uint16_t base;
      } u_radio_power_db;
      u_radio_power_db.real = this->radio_power_db;
      *(outbuffer + offset + 0) = (u_radio_power_db.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_radio_power_db.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->radio_power_db);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_srv_ready;
      u_srv_ready.base = 0;
      u_srv_ready.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->srv_ready = u_srv_ready.real;
      offset += sizeof(this->srv_ready);
      uint32_t length_serial_number;
      arrToVar(length_serial_number, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_serial_number; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_serial_number-1]=0;
      this->serial_number = (char *)(inbuffer + offset-1);
      offset += length_serial_number;
      uint32_t length_firmware_version;
      arrToVar(length_firmware_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_firmware_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_firmware_version-1]=0;
      this->firmware_version = (char *)(inbuffer + offset-1);
      offset += length_firmware_version;
      union {
        int16_t real;
        uint16_t base;
      } u_radio_power_db;
      u_radio_power_db.base = 0;
      u_radio_power_db.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_radio_power_db.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->radio_power_db = u_radio_power_db.real;
      offset += sizeof(this->radio_power_db);
     return offset;
    }

    virtual const char * getType() override { return GETVSCSETTINGS; };
    virtual const char * getMD5() override { return "0311af2244cb422ed7ab1f33423ae67a"; };

  };

  class GetVscSettings {
    public:
    typedef GetVscSettingsRequest Request;
    typedef GetVscSettingsResponse Response;
  };

}
#endif
