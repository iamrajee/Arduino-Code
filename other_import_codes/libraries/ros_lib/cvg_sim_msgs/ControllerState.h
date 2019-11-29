#ifndef _ROS_cvg_sim_msgs_ControllerState_h
#define _ROS_cvg_sim_msgs_ControllerState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cvg_sim_msgs
{

  class ControllerState : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _source_type;
      _source_type source;
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef uint8_t _state_type;
      _state_type state;
      enum { MOTORS =  1 };
      enum { ATTITUDE =  2 };
      enum { VELOCITY =  4 };
      enum { POSITION =  8 };
      enum { HEADING =  16 };
      enum { HEIGHT =  32 };
      enum { MOTORS_RUNNING =  1 };
      enum { AIRBORNE =  2 };

    ControllerState():
      header(),
      source(0),
      mode(0),
      state(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->source >> (8 * 0)) & 0xFF;
      offset += sizeof(this->source);
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->source =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->source);
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      this->state =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->state);
     return offset;
    }

    const char * getType(){ return "cvg_sim_msgs/ControllerState"; };
    const char * getMD5(){ return "a0f668496c9bbf505c01f59674f2a0c2"; };

  };

}
#endif
