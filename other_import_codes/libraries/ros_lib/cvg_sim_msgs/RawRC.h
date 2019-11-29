#ifndef _ROS_cvg_sim_msgs_RawRC_h
#define _ROS_cvg_sim_msgs_RawRC_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cvg_sim_msgs
{

  class RawRC : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _status_type;
      _status_type status;
      uint32_t channel_length;
      typedef uint16_t _channel_type;
      _channel_type st_channel;
      _channel_type * channel;

    RawRC():
      header(),
      status(0),
      channel_length(0), channel(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      *(outbuffer + offset + 0) = (this->channel_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channel_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->channel_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->channel_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->channel_length);
      for( uint32_t i = 0; i < channel_length; i++){
      *(outbuffer + offset + 0) = (this->channel[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->channel[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->channel[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      uint32_t channel_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      channel_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      channel_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      channel_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->channel_length);
      if(channel_lengthT > channel_length)
        this->channel = (uint16_t*)realloc(this->channel, channel_lengthT * sizeof(uint16_t));
      channel_length = channel_lengthT;
      for( uint32_t i = 0; i < channel_length; i++){
      this->st_channel =  ((uint16_t) (*(inbuffer + offset)));
      this->st_channel |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_channel);
        memcpy( &(this->channel[i]), &(this->st_channel), sizeof(uint16_t));
      }
     return offset;
    }

    const char * getType(){ return "cvg_sim_msgs/RawRC"; };
    const char * getMD5(){ return "f1584488325f747abea0b77036f70e2c"; };

  };

}
#endif
