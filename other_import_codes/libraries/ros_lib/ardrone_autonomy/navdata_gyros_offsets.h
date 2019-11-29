#ifndef _ROS_ardrone_autonomy_navdata_gyros_offsets_h
#define _ROS_ardrone_autonomy_navdata_gyros_offsets_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_gyros_offsets : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _drone_time_type;
      _drone_time_type drone_time;
      typedef uint16_t _tag_type;
      _tag_type tag;
      typedef uint16_t _size_type;
      _size_type size;
      uint32_t offset_g_length;
      typedef float _offset_g_type;
      _offset_g_type st_offset_g;
      _offset_g_type * offset_g;

    navdata_gyros_offsets():
      header(),
      drone_time(0),
      tag(0),
      size(0),
      offset_g_length(0), offset_g(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->drone_time);
      *(outbuffer + offset + 0) = (this->tag >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tag >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tag);
      *(outbuffer + offset + 0) = (this->size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size >> (8 * 1)) & 0xFF;
      offset += sizeof(this->size);
      *(outbuffer + offset + 0) = (this->offset_g_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->offset_g_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->offset_g_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->offset_g_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset_g_length);
      for( uint32_t i = 0; i < offset_g_length; i++){
      union {
        float real;
        uint32_t base;
      } u_offset_gi;
      u_offset_gi.real = this->offset_g[i];
      *(outbuffer + offset + 0) = (u_offset_gi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_offset_gi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_offset_gi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_offset_gi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset_g[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->drone_time));
      this->tag =  ((uint16_t) (*(inbuffer + offset)));
      this->tag |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->tag);
      this->size =  ((uint16_t) (*(inbuffer + offset)));
      this->size |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->size);
      uint32_t offset_g_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      offset_g_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      offset_g_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      offset_g_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->offset_g_length);
      if(offset_g_lengthT > offset_g_length)
        this->offset_g = (float*)realloc(this->offset_g, offset_g_lengthT * sizeof(float));
      offset_g_length = offset_g_lengthT;
      for( uint32_t i = 0; i < offset_g_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_offset_g;
      u_st_offset_g.base = 0;
      u_st_offset_g.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_offset_g.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_offset_g.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_offset_g.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_offset_g = u_st_offset_g.real;
      offset += sizeof(this->st_offset_g);
        memcpy( &(this->offset_g[i]), &(this->st_offset_g), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_gyros_offsets"; };
    const char * getMD5(){ return "c1f7c76e172c058c98de03cda79060d4"; };

  };

}
#endif
