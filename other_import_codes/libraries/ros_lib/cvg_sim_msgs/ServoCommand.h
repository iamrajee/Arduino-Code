#ifndef _ROS_cvg_sim_msgs_ServoCommand_h
#define _ROS_cvg_sim_msgs_ServoCommand_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cvg_sim_msgs
{

  class ServoCommand : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t value_length;
      typedef uint16_t _value_type;
      _value_type st_value;
      _value_type * value;

    ServoCommand():
      header(),
      value_length(0), value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->value_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_length);
      for( uint32_t i = 0; i < value_length; i++){
      *(outbuffer + offset + 0) = (this->value[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value[i] >> (8 * 1)) & 0xFF;
      offset += sizeof(this->value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t value_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->value_length);
      if(value_lengthT > value_length)
        this->value = (uint16_t*)realloc(this->value, value_lengthT * sizeof(uint16_t));
      value_length = value_lengthT;
      for( uint32_t i = 0; i < value_length; i++){
      this->st_value =  ((uint16_t) (*(inbuffer + offset)));
      this->st_value |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->st_value);
        memcpy( &(this->value[i]), &(this->st_value), sizeof(uint16_t));
      }
     return offset;
    }

    const char * getType(){ return "cvg_sim_msgs/ServoCommand"; };
    const char * getMD5(){ return "d60ef35d4e3412dc6686b189be2523d0"; };

  };

}
#endif
