#ifndef _ROS_ardrone_autonomy_Navdata_h
#define _ROS_ardrone_autonomy_Navdata_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class Navdata : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _batteryPercent_type;
      _batteryPercent_type batteryPercent;
      typedef uint32_t _state_type;
      _state_type state;
      typedef int32_t _magX_type;
      _magX_type magX;
      typedef int32_t _magY_type;
      _magY_type magY;
      typedef int32_t _magZ_type;
      _magZ_type magZ;
      typedef int32_t _pressure_type;
      _pressure_type pressure;
      typedef int32_t _temp_type;
      _temp_type temp;
      typedef float _wind_speed_type;
      _wind_speed_type wind_speed;
      typedef float _wind_angle_type;
      _wind_angle_type wind_angle;
      typedef float _wind_comp_angle_type;
      _wind_comp_angle_type wind_comp_angle;
      typedef float _rotX_type;
      _rotX_type rotX;
      typedef float _rotY_type;
      _rotY_type rotY;
      typedef float _rotZ_type;
      _rotZ_type rotZ;
      typedef int32_t _altd_type;
      _altd_type altd;
      typedef float _vx_type;
      _vx_type vx;
      typedef float _vy_type;
      _vy_type vy;
      typedef float _vz_type;
      _vz_type vz;
      typedef float _ax_type;
      _ax_type ax;
      typedef float _ay_type;
      _ay_type ay;
      typedef float _az_type;
      _az_type az;
      typedef uint8_t _motor1_type;
      _motor1_type motor1;
      typedef uint8_t _motor2_type;
      _motor2_type motor2;
      typedef uint8_t _motor3_type;
      _motor3_type motor3;
      typedef uint8_t _motor4_type;
      _motor4_type motor4;
      typedef uint32_t _tags_count_type;
      _tags_count_type tags_count;
      uint32_t tags_type_length;
      typedef uint32_t _tags_type_type;
      _tags_type_type st_tags_type;
      _tags_type_type * tags_type;
      uint32_t tags_xc_length;
      typedef uint32_t _tags_xc_type;
      _tags_xc_type st_tags_xc;
      _tags_xc_type * tags_xc;
      uint32_t tags_yc_length;
      typedef uint32_t _tags_yc_type;
      _tags_yc_type st_tags_yc;
      _tags_yc_type * tags_yc;
      uint32_t tags_width_length;
      typedef uint32_t _tags_width_type;
      _tags_width_type st_tags_width;
      _tags_width_type * tags_width;
      uint32_t tags_height_length;
      typedef uint32_t _tags_height_type;
      _tags_height_type st_tags_height;
      _tags_height_type * tags_height;
      uint32_t tags_orientation_length;
      typedef float _tags_orientation_type;
      _tags_orientation_type st_tags_orientation;
      _tags_orientation_type * tags_orientation;
      uint32_t tags_distance_length;
      typedef float _tags_distance_type;
      _tags_distance_type st_tags_distance;
      _tags_distance_type * tags_distance;
      typedef float _tm_type;
      _tm_type tm;

    Navdata():
      header(),
      batteryPercent(0),
      state(0),
      magX(0),
      magY(0),
      magZ(0),
      pressure(0),
      temp(0),
      wind_speed(0),
      wind_angle(0),
      wind_comp_angle(0),
      rotX(0),
      rotY(0),
      rotZ(0),
      altd(0),
      vx(0),
      vy(0),
      vz(0),
      ax(0),
      ay(0),
      az(0),
      motor1(0),
      motor2(0),
      motor3(0),
      motor4(0),
      tags_count(0),
      tags_type_length(0), tags_type(NULL),
      tags_xc_length(0), tags_xc(NULL),
      tags_yc_length(0), tags_yc(NULL),
      tags_width_length(0), tags_width(NULL),
      tags_height_length(0), tags_height(NULL),
      tags_orientation_length(0), tags_orientation(NULL),
      tags_distance_length(0), tags_distance(NULL),
      tm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_batteryPercent;
      u_batteryPercent.real = this->batteryPercent;
      *(outbuffer + offset + 0) = (u_batteryPercent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_batteryPercent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_batteryPercent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_batteryPercent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->batteryPercent);
      *(outbuffer + offset + 0) = (this->state >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->state >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->state >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->state >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state);
      union {
        int32_t real;
        uint32_t base;
      } u_magX;
      u_magX.real = this->magX;
      *(outbuffer + offset + 0) = (u_magX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->magX);
      union {
        int32_t real;
        uint32_t base;
      } u_magY;
      u_magY.real = this->magY;
      *(outbuffer + offset + 0) = (u_magY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->magY);
      union {
        int32_t real;
        uint32_t base;
      } u_magZ;
      u_magZ.real = this->magZ;
      *(outbuffer + offset + 0) = (u_magZ.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magZ.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magZ.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magZ.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->magZ);
      union {
        int32_t real;
        uint32_t base;
      } u_pressure;
      u_pressure.real = this->pressure;
      *(outbuffer + offset + 0) = (u_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pressure.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pressure);
      union {
        int32_t real;
        uint32_t base;
      } u_temp;
      u_temp.real = this->temp;
      *(outbuffer + offset + 0) = (u_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temp);
      union {
        float real;
        uint32_t base;
      } u_wind_speed;
      u_wind_speed.real = this->wind_speed;
      *(outbuffer + offset + 0) = (u_wind_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wind_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wind_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wind_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wind_speed);
      union {
        float real;
        uint32_t base;
      } u_wind_angle;
      u_wind_angle.real = this->wind_angle;
      *(outbuffer + offset + 0) = (u_wind_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wind_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wind_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wind_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wind_angle);
      union {
        float real;
        uint32_t base;
      } u_wind_comp_angle;
      u_wind_comp_angle.real = this->wind_comp_angle;
      *(outbuffer + offset + 0) = (u_wind_comp_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wind_comp_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wind_comp_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wind_comp_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wind_comp_angle);
      union {
        float real;
        uint32_t base;
      } u_rotX;
      u_rotX.real = this->rotX;
      *(outbuffer + offset + 0) = (u_rotX.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rotX.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rotX.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rotX.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rotX);
      union {
        float real;
        uint32_t base;
      } u_rotY;
      u_rotY.real = this->rotY;
      *(outbuffer + offset + 0) = (u_rotY.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rotY.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rotY.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rotY.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rotY);
      union {
        float real;
        uint32_t base;
      } u_rotZ;
      u_rotZ.real = this->rotZ;
      *(outbuffer + offset + 0) = (u_rotZ.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rotZ.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rotZ.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rotZ.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rotZ);
      union {
        int32_t real;
        uint32_t base;
      } u_altd;
      u_altd.real = this->altd;
      *(outbuffer + offset + 0) = (u_altd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altd.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altd.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altd.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altd);
      union {
        float real;
        uint32_t base;
      } u_vx;
      u_vx.real = this->vx;
      *(outbuffer + offset + 0) = (u_vx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vx);
      union {
        float real;
        uint32_t base;
      } u_vy;
      u_vy.real = this->vy;
      *(outbuffer + offset + 0) = (u_vy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vy);
      union {
        float real;
        uint32_t base;
      } u_vz;
      u_vz.real = this->vz;
      *(outbuffer + offset + 0) = (u_vz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vz);
      union {
        float real;
        uint32_t base;
      } u_ax;
      u_ax.real = this->ax;
      *(outbuffer + offset + 0) = (u_ax.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ax.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ax.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ax.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ax);
      union {
        float real;
        uint32_t base;
      } u_ay;
      u_ay.real = this->ay;
      *(outbuffer + offset + 0) = (u_ay.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ay.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ay.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ay.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ay);
      union {
        float real;
        uint32_t base;
      } u_az;
      u_az.real = this->az;
      *(outbuffer + offset + 0) = (u_az.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_az.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_az.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_az.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->az);
      *(outbuffer + offset + 0) = (this->motor1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor1);
      *(outbuffer + offset + 0) = (this->motor2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor2);
      *(outbuffer + offset + 0) = (this->motor3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor3);
      *(outbuffer + offset + 0) = (this->motor4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor4);
      *(outbuffer + offset + 0) = (this->tags_count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_count >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_count >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_count >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_count);
      *(outbuffer + offset + 0) = (this->tags_type_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_type_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_type_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_type_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_type_length);
      for( uint32_t i = 0; i < tags_type_length; i++){
      *(outbuffer + offset + 0) = (this->tags_type[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_type[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_type[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_type[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_type[i]);
      }
      *(outbuffer + offset + 0) = (this->tags_xc_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_xc_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_xc_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_xc_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_xc_length);
      for( uint32_t i = 0; i < tags_xc_length; i++){
      *(outbuffer + offset + 0) = (this->tags_xc[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_xc[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_xc[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_xc[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_xc[i]);
      }
      *(outbuffer + offset + 0) = (this->tags_yc_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_yc_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_yc_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_yc_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_yc_length);
      for( uint32_t i = 0; i < tags_yc_length; i++){
      *(outbuffer + offset + 0) = (this->tags_yc[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_yc[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_yc[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_yc[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_yc[i]);
      }
      *(outbuffer + offset + 0) = (this->tags_width_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_width_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_width_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_width_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_width_length);
      for( uint32_t i = 0; i < tags_width_length; i++){
      *(outbuffer + offset + 0) = (this->tags_width[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_width[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_width[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_width[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_width[i]);
      }
      *(outbuffer + offset + 0) = (this->tags_height_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_height_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_height_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_height_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_height_length);
      for( uint32_t i = 0; i < tags_height_length; i++){
      *(outbuffer + offset + 0) = (this->tags_height[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_height[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_height[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_height[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_height[i]);
      }
      *(outbuffer + offset + 0) = (this->tags_orientation_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_orientation_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_orientation_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_orientation_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_orientation_length);
      for( uint32_t i = 0; i < tags_orientation_length; i++){
      union {
        float real;
        uint32_t base;
      } u_tags_orientationi;
      u_tags_orientationi.real = this->tags_orientation[i];
      *(outbuffer + offset + 0) = (u_tags_orientationi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tags_orientationi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tags_orientationi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tags_orientationi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_orientation[i]);
      }
      *(outbuffer + offset + 0) = (this->tags_distance_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tags_distance_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tags_distance_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tags_distance_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_distance_length);
      for( uint32_t i = 0; i < tags_distance_length; i++){
      union {
        float real;
        uint32_t base;
      } u_tags_distancei;
      u_tags_distancei.real = this->tags_distance[i];
      *(outbuffer + offset + 0) = (u_tags_distancei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tags_distancei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tags_distancei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tags_distancei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tags_distance[i]);
      }
      union {
        float real;
        uint32_t base;
      } u_tm;
      u_tm.real = this->tm;
      *(outbuffer + offset + 0) = (u_tm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tm.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_batteryPercent;
      u_batteryPercent.base = 0;
      u_batteryPercent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_batteryPercent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_batteryPercent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_batteryPercent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->batteryPercent = u_batteryPercent.real;
      offset += sizeof(this->batteryPercent);
      this->state =  ((uint32_t) (*(inbuffer + offset)));
      this->state |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->state |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->state |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->state);
      union {
        int32_t real;
        uint32_t base;
      } u_magX;
      u_magX.base = 0;
      u_magX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->magX = u_magX.real;
      offset += sizeof(this->magX);
      union {
        int32_t real;
        uint32_t base;
      } u_magY;
      u_magY.base = 0;
      u_magY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->magY = u_magY.real;
      offset += sizeof(this->magY);
      union {
        int32_t real;
        uint32_t base;
      } u_magZ;
      u_magZ.base = 0;
      u_magZ.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magZ.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magZ.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magZ.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->magZ = u_magZ.real;
      offset += sizeof(this->magZ);
      union {
        int32_t real;
        uint32_t base;
      } u_pressure;
      u_pressure.base = 0;
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pressure.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pressure = u_pressure.real;
      offset += sizeof(this->pressure);
      union {
        int32_t real;
        uint32_t base;
      } u_temp;
      u_temp.base = 0;
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temp = u_temp.real;
      offset += sizeof(this->temp);
      union {
        float real;
        uint32_t base;
      } u_wind_speed;
      u_wind_speed.base = 0;
      u_wind_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wind_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wind_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wind_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wind_speed = u_wind_speed.real;
      offset += sizeof(this->wind_speed);
      union {
        float real;
        uint32_t base;
      } u_wind_angle;
      u_wind_angle.base = 0;
      u_wind_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wind_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wind_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wind_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wind_angle = u_wind_angle.real;
      offset += sizeof(this->wind_angle);
      union {
        float real;
        uint32_t base;
      } u_wind_comp_angle;
      u_wind_comp_angle.base = 0;
      u_wind_comp_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wind_comp_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wind_comp_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wind_comp_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wind_comp_angle = u_wind_comp_angle.real;
      offset += sizeof(this->wind_comp_angle);
      union {
        float real;
        uint32_t base;
      } u_rotX;
      u_rotX.base = 0;
      u_rotX.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rotX.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rotX.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rotX.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rotX = u_rotX.real;
      offset += sizeof(this->rotX);
      union {
        float real;
        uint32_t base;
      } u_rotY;
      u_rotY.base = 0;
      u_rotY.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rotY.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rotY.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rotY.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rotY = u_rotY.real;
      offset += sizeof(this->rotY);
      union {
        float real;
        uint32_t base;
      } u_rotZ;
      u_rotZ.base = 0;
      u_rotZ.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rotZ.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rotZ.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rotZ.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->rotZ = u_rotZ.real;
      offset += sizeof(this->rotZ);
      union {
        int32_t real;
        uint32_t base;
      } u_altd;
      u_altd.base = 0;
      u_altd.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altd.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altd.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altd.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altd = u_altd.real;
      offset += sizeof(this->altd);
      union {
        float real;
        uint32_t base;
      } u_vx;
      u_vx.base = 0;
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vx = u_vx.real;
      offset += sizeof(this->vx);
      union {
        float real;
        uint32_t base;
      } u_vy;
      u_vy.base = 0;
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vy = u_vy.real;
      offset += sizeof(this->vy);
      union {
        float real;
        uint32_t base;
      } u_vz;
      u_vz.base = 0;
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vz = u_vz.real;
      offset += sizeof(this->vz);
      union {
        float real;
        uint32_t base;
      } u_ax;
      u_ax.base = 0;
      u_ax.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ax.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ax.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ax.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ax = u_ax.real;
      offset += sizeof(this->ax);
      union {
        float real;
        uint32_t base;
      } u_ay;
      u_ay.base = 0;
      u_ay.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ay.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ay.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ay.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ay = u_ay.real;
      offset += sizeof(this->ay);
      union {
        float real;
        uint32_t base;
      } u_az;
      u_az.base = 0;
      u_az.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_az.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_az.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_az.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->az = u_az.real;
      offset += sizeof(this->az);
      this->motor1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor1);
      this->motor2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor2);
      this->motor3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor3);
      this->motor4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor4);
      this->tags_count =  ((uint32_t) (*(inbuffer + offset)));
      this->tags_count |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->tags_count |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->tags_count |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->tags_count);
      uint32_t tags_type_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_type_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_type_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_type_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_type_length);
      if(tags_type_lengthT > tags_type_length)
        this->tags_type = (uint32_t*)realloc(this->tags_type, tags_type_lengthT * sizeof(uint32_t));
      tags_type_length = tags_type_lengthT;
      for( uint32_t i = 0; i < tags_type_length; i++){
      this->st_tags_type =  ((uint32_t) (*(inbuffer + offset)));
      this->st_tags_type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_tags_type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_tags_type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_tags_type);
        memcpy( &(this->tags_type[i]), &(this->st_tags_type), sizeof(uint32_t));
      }
      uint32_t tags_xc_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_xc_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_xc_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_xc_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_xc_length);
      if(tags_xc_lengthT > tags_xc_length)
        this->tags_xc = (uint32_t*)realloc(this->tags_xc, tags_xc_lengthT * sizeof(uint32_t));
      tags_xc_length = tags_xc_lengthT;
      for( uint32_t i = 0; i < tags_xc_length; i++){
      this->st_tags_xc =  ((uint32_t) (*(inbuffer + offset)));
      this->st_tags_xc |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_tags_xc |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_tags_xc |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_tags_xc);
        memcpy( &(this->tags_xc[i]), &(this->st_tags_xc), sizeof(uint32_t));
      }
      uint32_t tags_yc_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_yc_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_yc_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_yc_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_yc_length);
      if(tags_yc_lengthT > tags_yc_length)
        this->tags_yc = (uint32_t*)realloc(this->tags_yc, tags_yc_lengthT * sizeof(uint32_t));
      tags_yc_length = tags_yc_lengthT;
      for( uint32_t i = 0; i < tags_yc_length; i++){
      this->st_tags_yc =  ((uint32_t) (*(inbuffer + offset)));
      this->st_tags_yc |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_tags_yc |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_tags_yc |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_tags_yc);
        memcpy( &(this->tags_yc[i]), &(this->st_tags_yc), sizeof(uint32_t));
      }
      uint32_t tags_width_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_width_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_width_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_width_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_width_length);
      if(tags_width_lengthT > tags_width_length)
        this->tags_width = (uint32_t*)realloc(this->tags_width, tags_width_lengthT * sizeof(uint32_t));
      tags_width_length = tags_width_lengthT;
      for( uint32_t i = 0; i < tags_width_length; i++){
      this->st_tags_width =  ((uint32_t) (*(inbuffer + offset)));
      this->st_tags_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_tags_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_tags_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_tags_width);
        memcpy( &(this->tags_width[i]), &(this->st_tags_width), sizeof(uint32_t));
      }
      uint32_t tags_height_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_height_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_height_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_height_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_height_length);
      if(tags_height_lengthT > tags_height_length)
        this->tags_height = (uint32_t*)realloc(this->tags_height, tags_height_lengthT * sizeof(uint32_t));
      tags_height_length = tags_height_lengthT;
      for( uint32_t i = 0; i < tags_height_length; i++){
      this->st_tags_height =  ((uint32_t) (*(inbuffer + offset)));
      this->st_tags_height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_tags_height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_tags_height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_tags_height);
        memcpy( &(this->tags_height[i]), &(this->st_tags_height), sizeof(uint32_t));
      }
      uint32_t tags_orientation_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_orientation_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_orientation_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_orientation_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_orientation_length);
      if(tags_orientation_lengthT > tags_orientation_length)
        this->tags_orientation = (float*)realloc(this->tags_orientation, tags_orientation_lengthT * sizeof(float));
      tags_orientation_length = tags_orientation_lengthT;
      for( uint32_t i = 0; i < tags_orientation_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_tags_orientation;
      u_st_tags_orientation.base = 0;
      u_st_tags_orientation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_tags_orientation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_tags_orientation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_tags_orientation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_tags_orientation = u_st_tags_orientation.real;
      offset += sizeof(this->st_tags_orientation);
        memcpy( &(this->tags_orientation[i]), &(this->st_tags_orientation), sizeof(float));
      }
      uint32_t tags_distance_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tags_distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tags_distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tags_distance_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tags_distance_length);
      if(tags_distance_lengthT > tags_distance_length)
        this->tags_distance = (float*)realloc(this->tags_distance, tags_distance_lengthT * sizeof(float));
      tags_distance_length = tags_distance_lengthT;
      for( uint32_t i = 0; i < tags_distance_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_tags_distance;
      u_st_tags_distance.base = 0;
      u_st_tags_distance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_tags_distance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_tags_distance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_tags_distance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_tags_distance = u_st_tags_distance.real;
      offset += sizeof(this->st_tags_distance);
        memcpy( &(this->tags_distance[i]), &(this->st_tags_distance), sizeof(float));
      }
      union {
        float real;
        uint32_t base;
      } u_tm;
      u_tm.base = 0;
      u_tm.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tm.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tm.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tm.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tm = u_tm.real;
      offset += sizeof(this->tm);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/Navdata"; };
    const char * getMD5(){ return "e1169f766234363125ac62c9a3f87eeb"; };

  };

}
#endif
