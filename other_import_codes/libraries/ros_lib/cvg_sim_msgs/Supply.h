#ifndef _ROS_cvg_sim_msgs_Supply_h
#define _ROS_cvg_sim_msgs_Supply_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cvg_sim_msgs
{

  class Supply : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t voltage_length;
      typedef float _voltage_type;
      _voltage_type st_voltage;
      _voltage_type * voltage;
      uint32_t current_length;
      typedef float _current_type;
      _current_type st_current;
      _current_type * current;

    Supply():
      header(),
      voltage_length(0), voltage(NULL),
      current_length(0), current(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->voltage_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->voltage_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->voltage_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->voltage_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage_length);
      for( uint32_t i = 0; i < voltage_length; i++){
      union {
        float real;
        uint32_t base;
      } u_voltagei;
      u_voltagei.real = this->voltage[i];
      *(outbuffer + offset + 0) = (u_voltagei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltagei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltagei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltagei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage[i]);
      }
      *(outbuffer + offset + 0) = (this->current_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_length);
      for( uint32_t i = 0; i < current_length; i++){
      union {
        float real;
        uint32_t base;
      } u_currenti;
      u_currenti.real = this->current[i];
      *(outbuffer + offset + 0) = (u_currenti.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_currenti.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_currenti.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_currenti.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t voltage_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      voltage_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->voltage_length);
      if(voltage_lengthT > voltage_length)
        this->voltage = (float*)realloc(this->voltage, voltage_lengthT * sizeof(float));
      voltage_length = voltage_lengthT;
      for( uint32_t i = 0; i < voltage_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_voltage;
      u_st_voltage.base = 0;
      u_st_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_voltage = u_st_voltage.real;
      offset += sizeof(this->st_voltage);
        memcpy( &(this->voltage[i]), &(this->st_voltage), sizeof(float));
      }
      uint32_t current_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      current_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      current_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      current_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->current_length);
      if(current_lengthT > current_length)
        this->current = (float*)realloc(this->current, current_lengthT * sizeof(float));
      current_length = current_lengthT;
      for( uint32_t i = 0; i < current_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_current;
      u_st_current.base = 0;
      u_st_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_current = u_st_current.real;
      offset += sizeof(this->st_current);
        memcpy( &(this->current[i]), &(this->st_current), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "cvg_sim_msgs/Supply"; };
    const char * getMD5(){ return "26f5225a2b836fba706a87e45759fdfc"; };

  };

}
#endif
