#ifndef _ROS_cvg_sim_msgs_RC_h
#define _ROS_cvg_sim_msgs_RC_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cvg_sim_msgs
{

  class RC : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _status_type;
      _status_type status;
      typedef bool _valid_type;
      _valid_type valid;
      uint32_t axis_length;
      typedef float _axis_type;
      _axis_type st_axis;
      _axis_type * axis;
      uint32_t axis_function_length;
      typedef uint8_t _axis_function_type;
      _axis_function_type st_axis_function;
      _axis_function_type * axis_function;
      uint32_t swit_length;
      typedef int8_t _swit_type;
      _swit_type st_swit;
      _swit_type * swit;
      uint32_t swit_function_length;
      typedef uint8_t _swit_function_type;
      _swit_function_type st_swit_function;
      _swit_function_type * swit_function;
      enum { ROLL =  1 };
      enum { PITCH =  2 };
      enum { YAW =  3 };
      enum { STEER =  4 };
      enum { HEIGHT =  5 };
      enum { THRUST =  6 };
      enum { BRAKE =  7 };

    RC():
      header(),
      status(0),
      valid(0),
      axis_length(0), axis(NULL),
      axis_function_length(0), axis_function(NULL),
      swit_length(0), swit(NULL),
      swit_function_length(0), swit_function(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->status >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      union {
        bool real;
        uint8_t base;
      } u_valid;
      u_valid.real = this->valid;
      *(outbuffer + offset + 0) = (u_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->valid);
      *(outbuffer + offset + 0) = (this->axis_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->axis_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->axis_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->axis_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->axis_length);
      for( uint32_t i = 0; i < axis_length; i++){
      union {
        float real;
        uint32_t base;
      } u_axisi;
      u_axisi.real = this->axis[i];
      *(outbuffer + offset + 0) = (u_axisi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_axisi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_axisi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_axisi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->axis[i]);
      }
      *(outbuffer + offset + 0) = (this->axis_function_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->axis_function_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->axis_function_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->axis_function_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->axis_function_length);
      for( uint32_t i = 0; i < axis_function_length; i++){
      *(outbuffer + offset + 0) = (this->axis_function[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->axis_function[i]);
      }
      *(outbuffer + offset + 0) = (this->swit_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->swit_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->swit_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->swit_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->swit_length);
      for( uint32_t i = 0; i < swit_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_switi;
      u_switi.real = this->swit[i];
      *(outbuffer + offset + 0) = (u_switi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->swit[i]);
      }
      *(outbuffer + offset + 0) = (this->swit_function_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->swit_function_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->swit_function_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->swit_function_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->swit_function_length);
      for( uint32_t i = 0; i < swit_function_length; i++){
      *(outbuffer + offset + 0) = (this->swit_function[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->swit_function[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->status =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->status);
      union {
        bool real;
        uint8_t base;
      } u_valid;
      u_valid.base = 0;
      u_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->valid = u_valid.real;
      offset += sizeof(this->valid);
      uint32_t axis_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      axis_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      axis_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      axis_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->axis_length);
      if(axis_lengthT > axis_length)
        this->axis = (float*)realloc(this->axis, axis_lengthT * sizeof(float));
      axis_length = axis_lengthT;
      for( uint32_t i = 0; i < axis_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_axis;
      u_st_axis.base = 0;
      u_st_axis.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_axis.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_axis.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_axis.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_axis = u_st_axis.real;
      offset += sizeof(this->st_axis);
        memcpy( &(this->axis[i]), &(this->st_axis), sizeof(float));
      }
      uint32_t axis_function_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      axis_function_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      axis_function_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      axis_function_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->axis_function_length);
      if(axis_function_lengthT > axis_function_length)
        this->axis_function = (uint8_t*)realloc(this->axis_function, axis_function_lengthT * sizeof(uint8_t));
      axis_function_length = axis_function_lengthT;
      for( uint32_t i = 0; i < axis_function_length; i++){
      this->st_axis_function =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_axis_function);
        memcpy( &(this->axis_function[i]), &(this->st_axis_function), sizeof(uint8_t));
      }
      uint32_t swit_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      swit_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      swit_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      swit_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->swit_length);
      if(swit_lengthT > swit_length)
        this->swit = (int8_t*)realloc(this->swit, swit_lengthT * sizeof(int8_t));
      swit_length = swit_lengthT;
      for( uint32_t i = 0; i < swit_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_st_swit;
      u_st_swit.base = 0;
      u_st_swit.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_swit = u_st_swit.real;
      offset += sizeof(this->st_swit);
        memcpy( &(this->swit[i]), &(this->st_swit), sizeof(int8_t));
      }
      uint32_t swit_function_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      swit_function_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      swit_function_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      swit_function_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->swit_function_length);
      if(swit_function_lengthT > swit_function_length)
        this->swit_function = (uint8_t*)realloc(this->swit_function, swit_function_lengthT * sizeof(uint8_t));
      swit_function_length = swit_function_lengthT;
      for( uint32_t i = 0; i < swit_function_length; i++){
      this->st_swit_function =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_swit_function);
        memcpy( &(this->swit_function[i]), &(this->st_swit_function), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return "cvg_sim_msgs/RC"; };
    const char * getMD5(){ return "2691c2fe8c5ab2323146bdd8dd2e449e"; };

  };

}
#endif
