#ifndef _ROS_ardrone_autonomy_navdata_raw_measures_h
#define _ROS_ardrone_autonomy_navdata_raw_measures_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_raw_measures : public ros::Msg
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
      uint32_t raw_gyros_length;
      typedef int16_t _raw_gyros_type;
      _raw_gyros_type st_raw_gyros;
      _raw_gyros_type * raw_gyros;
      uint32_t raw_gyros_110_length;
      typedef int16_t _raw_gyros_110_type;
      _raw_gyros_110_type st_raw_gyros_110;
      _raw_gyros_110_type * raw_gyros_110;
      typedef uint32_t _vbat_raw_type;
      _vbat_raw_type vbat_raw;
      typedef uint16_t _us_debut_echo_type;
      _us_debut_echo_type us_debut_echo;
      typedef uint16_t _us_fin_echo_type;
      _us_fin_echo_type us_fin_echo;
      typedef uint16_t _us_association_echo_type;
      _us_association_echo_type us_association_echo;
      typedef uint16_t _us_distance_echo_type;
      _us_distance_echo_type us_distance_echo;
      typedef uint16_t _us_courbe_temps_type;
      _us_courbe_temps_type us_courbe_temps;
      typedef uint16_t _us_courbe_valeur_type;
      _us_courbe_valeur_type us_courbe_valeur;
      typedef uint16_t _us_courbe_ref_type;
      _us_courbe_ref_type us_courbe_ref;
      typedef uint16_t _flag_echo_ini_type;
      _flag_echo_ini_type flag_echo_ini;
      typedef uint16_t _nb_echo_type;
      _nb_echo_type nb_echo;
      typedef uint32_t _sum_echo_type;
      _sum_echo_type sum_echo;
      typedef int32_t _alt_temp_raw_type;
      _alt_temp_raw_type alt_temp_raw;
      typedef int16_t _gradient_type;
      _gradient_type gradient;

    navdata_raw_measures():
      header(),
      drone_time(0),
      tag(0),
      size(0),
      raw_gyros_length(0), raw_gyros(NULL),
      raw_gyros_110_length(0), raw_gyros_110(NULL),
      vbat_raw(0),
      us_debut_echo(0),
      us_fin_echo(0),
      us_association_echo(0),
      us_distance_echo(0),
      us_courbe_temps(0),
      us_courbe_valeur(0),
      us_courbe_ref(0),
      flag_echo_ini(0),
      nb_echo(0),
      sum_echo(0),
      alt_temp_raw(0),
      gradient(0)
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
      *(outbuffer + offset + 0) = (this->raw_gyros_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->raw_gyros_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->raw_gyros_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->raw_gyros_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->raw_gyros_length);
      for( uint32_t i = 0; i < raw_gyros_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_raw_gyrosi;
      u_raw_gyrosi.real = this->raw_gyros[i];
      *(outbuffer + offset + 0) = (u_raw_gyrosi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_gyrosi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->raw_gyros[i]);
      }
      *(outbuffer + offset + 0) = (this->raw_gyros_110_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->raw_gyros_110_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->raw_gyros_110_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->raw_gyros_110_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->raw_gyros_110_length);
      for( uint32_t i = 0; i < raw_gyros_110_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_raw_gyros_110i;
      u_raw_gyros_110i.real = this->raw_gyros_110[i];
      *(outbuffer + offset + 0) = (u_raw_gyros_110i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_raw_gyros_110i.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->raw_gyros_110[i]);
      }
      *(outbuffer + offset + 0) = (this->vbat_raw >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vbat_raw >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vbat_raw >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vbat_raw >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vbat_raw);
      *(outbuffer + offset + 0) = (this->us_debut_echo >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->us_debut_echo >> (8 * 1)) & 0xFF;
      offset += sizeof(this->us_debut_echo);
      *(outbuffer + offset + 0) = (this->us_fin_echo >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->us_fin_echo >> (8 * 1)) & 0xFF;
      offset += sizeof(this->us_fin_echo);
      *(outbuffer + offset + 0) = (this->us_association_echo >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->us_association_echo >> (8 * 1)) & 0xFF;
      offset += sizeof(this->us_association_echo);
      *(outbuffer + offset + 0) = (this->us_distance_echo >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->us_distance_echo >> (8 * 1)) & 0xFF;
      offset += sizeof(this->us_distance_echo);
      *(outbuffer + offset + 0) = (this->us_courbe_temps >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->us_courbe_temps >> (8 * 1)) & 0xFF;
      offset += sizeof(this->us_courbe_temps);
      *(outbuffer + offset + 0) = (this->us_courbe_valeur >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->us_courbe_valeur >> (8 * 1)) & 0xFF;
      offset += sizeof(this->us_courbe_valeur);
      *(outbuffer + offset + 0) = (this->us_courbe_ref >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->us_courbe_ref >> (8 * 1)) & 0xFF;
      offset += sizeof(this->us_courbe_ref);
      *(outbuffer + offset + 0) = (this->flag_echo_ini >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->flag_echo_ini >> (8 * 1)) & 0xFF;
      offset += sizeof(this->flag_echo_ini);
      *(outbuffer + offset + 0) = (this->nb_echo >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nb_echo >> (8 * 1)) & 0xFF;
      offset += sizeof(this->nb_echo);
      *(outbuffer + offset + 0) = (this->sum_echo >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sum_echo >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sum_echo >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sum_echo >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sum_echo);
      union {
        int32_t real;
        uint32_t base;
      } u_alt_temp_raw;
      u_alt_temp_raw.real = this->alt_temp_raw;
      *(outbuffer + offset + 0) = (u_alt_temp_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alt_temp_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alt_temp_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alt_temp_raw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alt_temp_raw);
      union {
        int16_t real;
        uint16_t base;
      } u_gradient;
      u_gradient.real = this->gradient;
      *(outbuffer + offset + 0) = (u_gradient.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gradient.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gradient);
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
      uint32_t raw_gyros_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      raw_gyros_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      raw_gyros_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      raw_gyros_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->raw_gyros_length);
      if(raw_gyros_lengthT > raw_gyros_length)
        this->raw_gyros = (int16_t*)realloc(this->raw_gyros, raw_gyros_lengthT * sizeof(int16_t));
      raw_gyros_length = raw_gyros_lengthT;
      for( uint32_t i = 0; i < raw_gyros_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_raw_gyros;
      u_st_raw_gyros.base = 0;
      u_st_raw_gyros.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_raw_gyros.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_raw_gyros = u_st_raw_gyros.real;
      offset += sizeof(this->st_raw_gyros);
        memcpy( &(this->raw_gyros[i]), &(this->st_raw_gyros), sizeof(int16_t));
      }
      uint32_t raw_gyros_110_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      raw_gyros_110_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      raw_gyros_110_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      raw_gyros_110_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->raw_gyros_110_length);
      if(raw_gyros_110_lengthT > raw_gyros_110_length)
        this->raw_gyros_110 = (int16_t*)realloc(this->raw_gyros_110, raw_gyros_110_lengthT * sizeof(int16_t));
      raw_gyros_110_length = raw_gyros_110_lengthT;
      for( uint32_t i = 0; i < raw_gyros_110_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_raw_gyros_110;
      u_st_raw_gyros_110.base = 0;
      u_st_raw_gyros_110.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_raw_gyros_110.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_raw_gyros_110 = u_st_raw_gyros_110.real;
      offset += sizeof(this->st_raw_gyros_110);
        memcpy( &(this->raw_gyros_110[i]), &(this->st_raw_gyros_110), sizeof(int16_t));
      }
      this->vbat_raw =  ((uint32_t) (*(inbuffer + offset)));
      this->vbat_raw |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->vbat_raw |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->vbat_raw |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->vbat_raw);
      this->us_debut_echo =  ((uint16_t) (*(inbuffer + offset)));
      this->us_debut_echo |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->us_debut_echo);
      this->us_fin_echo =  ((uint16_t) (*(inbuffer + offset)));
      this->us_fin_echo |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->us_fin_echo);
      this->us_association_echo =  ((uint16_t) (*(inbuffer + offset)));
      this->us_association_echo |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->us_association_echo);
      this->us_distance_echo =  ((uint16_t) (*(inbuffer + offset)));
      this->us_distance_echo |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->us_distance_echo);
      this->us_courbe_temps =  ((uint16_t) (*(inbuffer + offset)));
      this->us_courbe_temps |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->us_courbe_temps);
      this->us_courbe_valeur =  ((uint16_t) (*(inbuffer + offset)));
      this->us_courbe_valeur |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->us_courbe_valeur);
      this->us_courbe_ref =  ((uint16_t) (*(inbuffer + offset)));
      this->us_courbe_ref |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->us_courbe_ref);
      this->flag_echo_ini =  ((uint16_t) (*(inbuffer + offset)));
      this->flag_echo_ini |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->flag_echo_ini);
      this->nb_echo =  ((uint16_t) (*(inbuffer + offset)));
      this->nb_echo |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->nb_echo);
      this->sum_echo =  ((uint32_t) (*(inbuffer + offset)));
      this->sum_echo |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sum_echo |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sum_echo |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sum_echo);
      union {
        int32_t real;
        uint32_t base;
      } u_alt_temp_raw;
      u_alt_temp_raw.base = 0;
      u_alt_temp_raw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alt_temp_raw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alt_temp_raw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alt_temp_raw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alt_temp_raw = u_alt_temp_raw.real;
      offset += sizeof(this->alt_temp_raw);
      union {
        int16_t real;
        uint16_t base;
      } u_gradient;
      u_gradient.base = 0;
      u_gradient.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gradient.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gradient = u_gradient.real;
      offset += sizeof(this->gradient);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_raw_measures"; };
    const char * getMD5(){ return "4da7145c7478d1eb84be4d5fa4acd9ca"; };

  };

}
#endif
