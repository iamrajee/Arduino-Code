#ifndef _ROS_cvg_sim_msgs_RawImu_h
#define _ROS_cvg_sim_msgs_RawImu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cvg_sim_msgs
{

  class RawImu : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint16_t angular_velocity[3];
      uint16_t linear_acceleration[3];

    RawImu():
      header(),
      angular_velocity(),
      linear_acceleration()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      *(outbuffer + offset + 0) = (this->angular_velocity[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->angular_velocity[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->angular_velocity[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      *(outbuffer + offset + 0) = (this->linear_acceleration[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->linear_acceleration[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->linear_acceleration[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      this->angular_velocity[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->angular_velocity[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->angular_velocity[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      this->linear_acceleration[i] =  ((uint16_t) (*(inbuffer + offset)));
      this->linear_acceleration[i] |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->linear_acceleration[i]);
      }
     return offset;
    }

    const char * getType(){ return "cvg_sim_msgs/RawImu"; };
    const char * getMD5(){ return "0879a838e899792bcf72ccfe7b5595ef"; };

  };

}
#endif
