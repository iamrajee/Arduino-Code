#ifndef _ROS_ardrone_autonomy_navdata_phys_measures_h
#define _ROS_ardrone_autonomy_navdata_phys_measures_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_phys_measures : public ros::Msg
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
      typedef float _accs_temp_type;
      _accs_temp_type accs_temp;
      typedef uint16_t _gyro_temp_type;
      _gyro_temp_type gyro_temp;
      uint32_t phys_accs_length;
      typedef float _phys_accs_type;
      _phys_accs_type st_phys_accs;
      _phys_accs_type * phys_accs;
      uint32_t phys_gyros_length;
      typedef float _phys_gyros_type;
      _phys_gyros_type st_phys_gyros;
      _phys_gyros_type * phys_gyros;
      typedef uint32_t _alim3V3_type;
      _alim3V3_type alim3V3;
      typedef uint32_t _vrefEpson_type;
      _vrefEpson_type vrefEpson;
      typedef uint32_t _vrefIDG_type;
      _vrefIDG_type vrefIDG;

    navdata_phys_measures():
      header(),
      drone_time(0),
      tag(0),
      size(0),
      accs_temp(0),
      gyro_temp(0),
      phys_accs_length(0), phys_accs(NULL),
      phys_gyros_length(0), phys_gyros(NULL),
      alim3V3(0),
      vrefEpson(0),
      vrefIDG(0)
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
      union {
        float real;
        uint32_t base;
      } u_accs_temp;
      u_accs_temp.real = this->accs_temp;
      *(outbuffer + offset + 0) = (u_accs_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accs_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accs_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accs_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accs_temp);
      *(outbuffer + offset + 0) = (this->gyro_temp >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gyro_temp >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyro_temp);
      *(outbuffer + offset + 0) = (this->phys_accs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->phys_accs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->phys_accs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->phys_accs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phys_accs_length);
      for( uint32_t i = 0; i < phys_accs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_phys_accsi;
      u_phys_accsi.real = this->phys_accs[i];
      *(outbuffer + offset + 0) = (u_phys_accsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_phys_accsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_phys_accsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_phys_accsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phys_accs[i]);
      }
      *(outbuffer + offset + 0) = (this->phys_gyros_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->phys_gyros_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->phys_gyros_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->phys_gyros_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phys_gyros_length);
      for( uint32_t i = 0; i < phys_gyros_length; i++){
      union {
        float real;
        uint32_t base;
      } u_phys_gyrosi;
      u_phys_gyrosi.real = this->phys_gyros[i];
      *(outbuffer + offset + 0) = (u_phys_gyrosi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_phys_gyrosi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_phys_gyrosi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_phys_gyrosi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phys_gyros[i]);
      }
      *(outbuffer + offset + 0) = (this->alim3V3 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->alim3V3 >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->alim3V3 >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->alim3V3 >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alim3V3);
      *(outbuffer + offset + 0) = (this->vrefEpson >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vrefEpson >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vrefEpson >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vrefEpson >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vrefEpson);
      *(outbuffer + offset + 0) = (this->vrefIDG >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vrefIDG >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vrefIDG >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vrefIDG >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vrefIDG);
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
      union {
        float real;
        uint32_t base;
      } u_accs_temp;
      u_accs_temp.base = 0;
      u_accs_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accs_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accs_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accs_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accs_temp = u_accs_temp.real;
      offset += sizeof(this->accs_temp);
      this->gyro_temp =  ((uint16_t) (*(inbuffer + offset)));
      this->gyro_temp |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->gyro_temp);
      uint32_t phys_accs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      phys_accs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      phys_accs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      phys_accs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->phys_accs_length);
      if(phys_accs_lengthT > phys_accs_length)
        this->phys_accs = (float*)realloc(this->phys_accs, phys_accs_lengthT * sizeof(float));
      phys_accs_length = phys_accs_lengthT;
      for( uint32_t i = 0; i < phys_accs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_phys_accs;
      u_st_phys_accs.base = 0;
      u_st_phys_accs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_phys_accs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_phys_accs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_phys_accs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_phys_accs = u_st_phys_accs.real;
      offset += sizeof(this->st_phys_accs);
        memcpy( &(this->phys_accs[i]), &(this->st_phys_accs), sizeof(float));
      }
      uint32_t phys_gyros_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      phys_gyros_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      phys_gyros_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      phys_gyros_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->phys_gyros_length);
      if(phys_gyros_lengthT > phys_gyros_length)
        this->phys_gyros = (float*)realloc(this->phys_gyros, phys_gyros_lengthT * sizeof(float));
      phys_gyros_length = phys_gyros_lengthT;
      for( uint32_t i = 0; i < phys_gyros_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_phys_gyros;
      u_st_phys_gyros.base = 0;
      u_st_phys_gyros.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_phys_gyros.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_phys_gyros.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_phys_gyros.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_phys_gyros = u_st_phys_gyros.real;
      offset += sizeof(this->st_phys_gyros);
        memcpy( &(this->phys_gyros[i]), &(this->st_phys_gyros), sizeof(float));
      }
      this->alim3V3 =  ((uint32_t) (*(inbuffer + offset)));
      this->alim3V3 |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->alim3V3 |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->alim3V3 |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->alim3V3);
      this->vrefEpson =  ((uint32_t) (*(inbuffer + offset)));
      this->vrefEpson |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->vrefEpson |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->vrefEpson |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->vrefEpson);
      this->vrefIDG =  ((uint32_t) (*(inbuffer + offset)));
      this->vrefIDG |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->vrefIDG |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->vrefIDG |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->vrefIDG);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_phys_measures"; };
    const char * getMD5(){ return "649dd469618f5ff313f6bceab2c356b7"; };

  };

}
#endif
