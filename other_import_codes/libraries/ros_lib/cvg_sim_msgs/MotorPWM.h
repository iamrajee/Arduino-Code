#ifndef _ROS_cvg_sim_msgs_MotorPWM_h
#define _ROS_cvg_sim_msgs_MotorPWM_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cvg_sim_msgs
{

  class MotorPWM : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t pwm_length;
      typedef uint8_t _pwm_type;
      _pwm_type st_pwm;
      _pwm_type * pwm;

    MotorPWM():
      header(),
      pwm_length(0), pwm(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->pwm_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pwm_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pwm_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pwm_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pwm_length);
      for( uint32_t i = 0; i < pwm_length; i++){
      *(outbuffer + offset + 0) = (this->pwm[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pwm[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t pwm_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pwm_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pwm_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pwm_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pwm_length);
      if(pwm_lengthT > pwm_length)
        this->pwm = (uint8_t*)realloc(this->pwm, pwm_lengthT * sizeof(uint8_t));
      pwm_length = pwm_lengthT;
      for( uint32_t i = 0; i < pwm_length; i++){
      this->st_pwm =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_pwm);
        memcpy( &(this->pwm[i]), &(this->st_pwm), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "cvg_sim_msgs/MotorPWM"; };
    const char * getMD5(){ return "42f78dd80f99e0208248b8a257b8a645"; };

  };

}
#endif
