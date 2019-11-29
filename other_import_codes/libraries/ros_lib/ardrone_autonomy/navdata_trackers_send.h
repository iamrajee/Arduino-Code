#ifndef _ROS_ardrone_autonomy_navdata_trackers_send_h
#define _ROS_ardrone_autonomy_navdata_trackers_send_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ardrone_autonomy/vector21.h"

namespace ardrone_autonomy
{

  class navdata_trackers_send : public ros::Msg
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
      uint32_t locked_length;
      typedef int32_t _locked_type;
      _locked_type st_locked;
      _locked_type * locked;
      uint32_t point_length;
      typedef ardrone_autonomy::vector21 _point_type;
      _point_type st_point;
      _point_type * point;

    navdata_trackers_send():
      header(),
      drone_time(0),
      tag(0),
      size(0),
      locked_length(0), locked(NULL),
      point_length(0), point(NULL)
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
      *(outbuffer + offset + 0) = (this->locked_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->locked_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->locked_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->locked_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->locked_length);
      for( uint32_t i = 0; i < locked_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_lockedi;
      u_lockedi.real = this->locked[i];
      *(outbuffer + offset + 0) = (u_lockedi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lockedi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lockedi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lockedi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->locked[i]);
      }
      *(outbuffer + offset + 0) = (this->point_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->point_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->point_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->point_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->point_length);
      for( uint32_t i = 0; i < point_length; i++){
      offset += this->point[i].serialize(outbuffer + offset);
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
      uint32_t locked_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      locked_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      locked_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      locked_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->locked_length);
      if(locked_lengthT > locked_length)
        this->locked = (int32_t*)realloc(this->locked, locked_lengthT * sizeof(int32_t));
      locked_length = locked_lengthT;
      for( uint32_t i = 0; i < locked_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_locked;
      u_st_locked.base = 0;
      u_st_locked.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_locked.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_locked.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_locked.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_locked = u_st_locked.real;
      offset += sizeof(this->st_locked);
        memcpy( &(this->locked[i]), &(this->st_locked), sizeof(int32_t));
      }
      uint32_t point_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      point_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->point_length);
      if(point_lengthT > point_length)
        this->point = (ardrone_autonomy::vector21*)realloc(this->point, point_lengthT * sizeof(ardrone_autonomy::vector21));
      point_length = point_lengthT;
      for( uint32_t i = 0; i < point_length; i++){
      offset += this->st_point.deserialize(inbuffer + offset);
        memcpy( &(this->point[i]), &(this->st_point), sizeof(ardrone_autonomy::vector21));
      }
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_trackers_send"; };
    const char * getMD5(){ return "77326ae58ca7691bcd2f23425242a70e"; };

  };

}
#endif
