#ifndef _ROS_SERVICE_HWIntBuildInfo_h
#define _ROS_SERVICE_HWIntBuildInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

static const char HWINTBUILDINFO[] = "greenzie_msgs/HWIntBuildInfo";

  class HWIntBuildInfoRequest : public ros::Msg
  {
    public:

    HWIntBuildInfoRequest()
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

    virtual const char * getType() override { return HWINTBUILDINFO; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class HWIntBuildInfoResponse : public ros::Msg
  {
    public:
      typedef const char* _pio_environment_type;
      _pio_environment_type pio_environment;
      typedef const char* _firmware_version_type;
      _firmware_version_type firmware_version;
      typedef const char* _compilation_time_type;
      _compilation_time_type compilation_time;
      typedef const char* _user_email_type;
      _user_email_type user_email;
      typedef const char* _git_branch_type;
      _git_branch_type git_branch;
      typedef const char* _latest_git_hash_type;
      _latest_git_hash_type latest_git_hash;

    HWIntBuildInfoResponse():
      pio_environment(""),
      firmware_version(""),
      compilation_time(""),
      user_email(""),
      git_branch(""),
      latest_git_hash("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_pio_environment = strlen(this->pio_environment);
      varToArr(outbuffer + offset, length_pio_environment);
      offset += 4;
      memcpy(outbuffer + offset, this->pio_environment, length_pio_environment);
      offset += length_pio_environment;
      uint32_t length_firmware_version = strlen(this->firmware_version);
      varToArr(outbuffer + offset, length_firmware_version);
      offset += 4;
      memcpy(outbuffer + offset, this->firmware_version, length_firmware_version);
      offset += length_firmware_version;
      uint32_t length_compilation_time = strlen(this->compilation_time);
      varToArr(outbuffer + offset, length_compilation_time);
      offset += 4;
      memcpy(outbuffer + offset, this->compilation_time, length_compilation_time);
      offset += length_compilation_time;
      uint32_t length_user_email = strlen(this->user_email);
      varToArr(outbuffer + offset, length_user_email);
      offset += 4;
      memcpy(outbuffer + offset, this->user_email, length_user_email);
      offset += length_user_email;
      uint32_t length_git_branch = strlen(this->git_branch);
      varToArr(outbuffer + offset, length_git_branch);
      offset += 4;
      memcpy(outbuffer + offset, this->git_branch, length_git_branch);
      offset += length_git_branch;
      uint32_t length_latest_git_hash = strlen(this->latest_git_hash);
      varToArr(outbuffer + offset, length_latest_git_hash);
      offset += 4;
      memcpy(outbuffer + offset, this->latest_git_hash, length_latest_git_hash);
      offset += length_latest_git_hash;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_pio_environment;
      arrToVar(length_pio_environment, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_pio_environment; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_pio_environment-1]=0;
      this->pio_environment = (char *)(inbuffer + offset-1);
      offset += length_pio_environment;
      uint32_t length_firmware_version;
      arrToVar(length_firmware_version, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_firmware_version; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_firmware_version-1]=0;
      this->firmware_version = (char *)(inbuffer + offset-1);
      offset += length_firmware_version;
      uint32_t length_compilation_time;
      arrToVar(length_compilation_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_compilation_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_compilation_time-1]=0;
      this->compilation_time = (char *)(inbuffer + offset-1);
      offset += length_compilation_time;
      uint32_t length_user_email;
      arrToVar(length_user_email, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_user_email; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_user_email-1]=0;
      this->user_email = (char *)(inbuffer + offset-1);
      offset += length_user_email;
      uint32_t length_git_branch;
      arrToVar(length_git_branch, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_git_branch; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_git_branch-1]=0;
      this->git_branch = (char *)(inbuffer + offset-1);
      offset += length_git_branch;
      uint32_t length_latest_git_hash;
      arrToVar(length_latest_git_hash, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_latest_git_hash; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_latest_git_hash-1]=0;
      this->latest_git_hash = (char *)(inbuffer + offset-1);
      offset += length_latest_git_hash;
     return offset;
    }

    virtual const char * getType() override { return HWINTBUILDINFO; };
    virtual const char * getMD5() override { return "29b2e86d8a3387151fcabb3606f01d28"; };

  };

  class HWIntBuildInfo {
    public:
    typedef HWIntBuildInfoRequest Request;
    typedef HWIntBuildInfoResponse Response;
  };

}
#endif
