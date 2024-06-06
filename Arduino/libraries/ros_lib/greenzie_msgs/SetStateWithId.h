#ifndef _ROS_SERVICE_SetStateWithId_h
#define _ROS_SERVICE_SetStateWithId_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace greenzie_msgs
{

static const char SETSTATEWITHID[] = "greenzie_msgs/SetStateWithId";

  class SetStateWithIdRequest : public ros::Msg
  {
    public:
      typedef uint8_t _id_type;
      _id_type id;
      typedef uint8_t _state_type;
      _state_type state;
      enum { RUGGED_SCIENCE_POE_STATE_DISABLED =  0   };
      enum { RUGGED_SCIENCE_POE_STATE_ENABLED =  1   };
      enum { RUGGED_SCIENCE_POE_STATE_AUTO =  2   };
      enum { RUGGED_SCIENCE_POE_STATE_ERROR =  3 };

    SetStateWithIdRequest():
      id(0),
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
     return offset;
    }

    virtual const char * getType() override { return SETSTATEWITHID; };
    virtual const char * getMD5() override { return "4c01355b94888da239a24407899a3614"; };

  };

  class SetStateWithIdResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef uint8_t _error_code_type;
      _error_code_type error_code;
      enum { POE_ERROR_CODE_NO_ERROR =  0   };
      enum { POE_ERROR_CODE_UNMONITORED =  1   };
      enum { POE_ERROR_CODE_FAILED =  2   };

    SetStateWithIdResponse():
      success(0),
      error_code(0)
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
      *(outbuffer + offset + 0) = (this->error_code >> (8 * 0)) & 0xFF;
      offset += sizeof(this->error_code);
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
      this->error_code =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->error_code);
     return offset;
    }

    virtual const char * getType() override { return SETSTATEWITHID; };
    virtual const char * getMD5() override { return "9baddea9e77d65a9cfc766f4cde89559"; };

  };

  class SetStateWithId {
    public:
    typedef SetStateWithIdRequest Request;
    typedef SetStateWithIdResponse Response;
  };

}
#endif
