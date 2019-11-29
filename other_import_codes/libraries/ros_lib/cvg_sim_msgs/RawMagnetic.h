#ifndef _ROS_cvg_sim_msgs_RawMagnetic_h
#define _ROS_cvg_sim_msgs_RawMagnetic_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cvg_sim_msgs
{

  class RawMagnetic : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      float channel[3];

    RawMagnetic():
      header(),
      channel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->channel[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->channel[i]));
      }
     return offset;
    }

    const char * getType(){ return "cvg_sim_msgs/RawMagnetic"; };
    const char * getMD5(){ return "babd510868ac7b486e2097c79e1384c9"; };

  };

}
#endif
