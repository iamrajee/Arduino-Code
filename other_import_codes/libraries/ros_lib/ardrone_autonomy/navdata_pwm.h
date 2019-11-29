#ifndef _ROS_ardrone_autonomy_navdata_pwm_h
#define _ROS_ardrone_autonomy_navdata_pwm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_pwm : public ros::Msg
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
      typedef uint8_t _motor1_type;
      _motor1_type motor1;
      typedef uint8_t _motor2_type;
      _motor2_type motor2;
      typedef uint8_t _motor3_type;
      _motor3_type motor3;
      typedef uint8_t _motor4_type;
      _motor4_type motor4;
      typedef uint8_t _sat_motor1_type;
      _sat_motor1_type sat_motor1;
      typedef uint8_t _sat_motor2_type;
      _sat_motor2_type sat_motor2;
      typedef uint8_t _sat_motor3_type;
      _sat_motor3_type sat_motor3;
      typedef uint8_t _sat_motor4_type;
      _sat_motor4_type sat_motor4;
      typedef float _gaz_feed_forward_type;
      _gaz_feed_forward_type gaz_feed_forward;
      typedef float _gaz_altitude_type;
      _gaz_altitude_type gaz_altitude;
      typedef float _altitude_integral_type;
      _altitude_integral_type altitude_integral;
      typedef float _vz_ref_type;
      _vz_ref_type vz_ref;
      typedef int32_t _u_pitch_type;
      _u_pitch_type u_pitch;
      typedef int32_t _u_roll_type;
      _u_roll_type u_roll;
      typedef int32_t _u_yaw_type;
      _u_yaw_type u_yaw;
      typedef float _yaw_u_I_type;
      _yaw_u_I_type yaw_u_I;
      typedef int32_t _u_pitch_planif_type;
      _u_pitch_planif_type u_pitch_planif;
      typedef int32_t _u_roll_planif_type;
      _u_roll_planif_type u_roll_planif;
      typedef int32_t _u_yaw_planif_type;
      _u_yaw_planif_type u_yaw_planif;
      typedef float _u_gaz_planif_type;
      _u_gaz_planif_type u_gaz_planif;
      typedef uint16_t _current_motor1_type;
      _current_motor1_type current_motor1;
      typedef uint16_t _current_motor2_type;
      _current_motor2_type current_motor2;
      typedef uint16_t _current_motor3_type;
      _current_motor3_type current_motor3;
      typedef uint16_t _current_motor4_type;
      _current_motor4_type current_motor4;
      typedef float _altitude_der_type;
      _altitude_der_type altitude_der;

    navdata_pwm():
      header(),
      drone_time(0),
      tag(0),
      size(0),
      motor1(0),
      motor2(0),
      motor3(0),
      motor4(0),
      sat_motor1(0),
      sat_motor2(0),
      sat_motor3(0),
      sat_motor4(0),
      gaz_feed_forward(0),
      gaz_altitude(0),
      altitude_integral(0),
      vz_ref(0),
      u_pitch(0),
      u_roll(0),
      u_yaw(0),
      yaw_u_I(0),
      u_pitch_planif(0),
      u_roll_planif(0),
      u_yaw_planif(0),
      u_gaz_planif(0),
      current_motor1(0),
      current_motor2(0),
      current_motor3(0),
      current_motor4(0),
      altitude_der(0)
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
      *(outbuffer + offset + 0) = (this->motor1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor1);
      *(outbuffer + offset + 0) = (this->motor2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor2);
      *(outbuffer + offset + 0) = (this->motor3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor3);
      *(outbuffer + offset + 0) = (this->motor4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor4);
      *(outbuffer + offset + 0) = (this->sat_motor1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sat_motor1);
      *(outbuffer + offset + 0) = (this->sat_motor2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sat_motor2);
      *(outbuffer + offset + 0) = (this->sat_motor3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sat_motor3);
      *(outbuffer + offset + 0) = (this->sat_motor4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sat_motor4);
      union {
        float real;
        uint32_t base;
      } u_gaz_feed_forward;
      u_gaz_feed_forward.real = this->gaz_feed_forward;
      *(outbuffer + offset + 0) = (u_gaz_feed_forward.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gaz_feed_forward.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gaz_feed_forward.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gaz_feed_forward.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gaz_feed_forward);
      union {
        float real;
        uint32_t base;
      } u_gaz_altitude;
      u_gaz_altitude.real = this->gaz_altitude;
      *(outbuffer + offset + 0) = (u_gaz_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gaz_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gaz_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gaz_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gaz_altitude);
      union {
        float real;
        uint32_t base;
      } u_altitude_integral;
      u_altitude_integral.real = this->altitude_integral;
      *(outbuffer + offset + 0) = (u_altitude_integral.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude_integral.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude_integral.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude_integral.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude_integral);
      union {
        float real;
        uint32_t base;
      } u_vz_ref;
      u_vz_ref.real = this->vz_ref;
      *(outbuffer + offset + 0) = (u_vz_ref.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vz_ref.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vz_ref.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vz_ref.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vz_ref);
      union {
        int32_t real;
        uint32_t base;
      } u_u_pitch;
      u_u_pitch.real = this->u_pitch;
      *(outbuffer + offset + 0) = (u_u_pitch.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u_pitch.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u_pitch.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u_pitch.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u_pitch);
      union {
        int32_t real;
        uint32_t base;
      } u_u_roll;
      u_u_roll.real = this->u_roll;
      *(outbuffer + offset + 0) = (u_u_roll.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u_roll.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u_roll.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u_roll.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u_roll);
      union {
        int32_t real;
        uint32_t base;
      } u_u_yaw;
      u_u_yaw.real = this->u_yaw;
      *(outbuffer + offset + 0) = (u_u_yaw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u_yaw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u_yaw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u_yaw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u_yaw);
      union {
        float real;
        uint32_t base;
      } u_yaw_u_I;
      u_yaw_u_I.real = this->yaw_u_I;
      *(outbuffer + offset + 0) = (u_yaw_u_I.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_yaw_u_I.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_yaw_u_I.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_yaw_u_I.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yaw_u_I);
      union {
        int32_t real;
        uint32_t base;
      } u_u_pitch_planif;
      u_u_pitch_planif.real = this->u_pitch_planif;
      *(outbuffer + offset + 0) = (u_u_pitch_planif.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u_pitch_planif.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u_pitch_planif.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u_pitch_planif.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u_pitch_planif);
      union {
        int32_t real;
        uint32_t base;
      } u_u_roll_planif;
      u_u_roll_planif.real = this->u_roll_planif;
      *(outbuffer + offset + 0) = (u_u_roll_planif.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u_roll_planif.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u_roll_planif.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u_roll_planif.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u_roll_planif);
      union {
        int32_t real;
        uint32_t base;
      } u_u_yaw_planif;
      u_u_yaw_planif.real = this->u_yaw_planif;
      *(outbuffer + offset + 0) = (u_u_yaw_planif.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u_yaw_planif.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u_yaw_planif.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u_yaw_planif.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u_yaw_planif);
      union {
        float real;
        uint32_t base;
      } u_u_gaz_planif;
      u_u_gaz_planif.real = this->u_gaz_planif;
      *(outbuffer + offset + 0) = (u_u_gaz_planif.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_u_gaz_planif.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_u_gaz_planif.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_u_gaz_planif.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->u_gaz_planif);
      *(outbuffer + offset + 0) = (this->current_motor1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_motor1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current_motor1);
      *(outbuffer + offset + 0) = (this->current_motor2 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_motor2 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current_motor2);
      *(outbuffer + offset + 0) = (this->current_motor3 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_motor3 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current_motor3);
      *(outbuffer + offset + 0) = (this->current_motor4 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_motor4 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->current_motor4);
      union {
        float real;
        uint32_t base;
      } u_altitude_der;
      u_altitude_der.real = this->altitude_der;
      *(outbuffer + offset + 0) = (u_altitude_der.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude_der.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude_der.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude_der.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude_der);
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
      this->motor1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor1);
      this->motor2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor2);
      this->motor3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor3);
      this->motor4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor4);
      this->sat_motor1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sat_motor1);
      this->sat_motor2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sat_motor2);
      this->sat_motor3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sat_motor3);
      this->sat_motor4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->sat_motor4);
      union {
        float real;
        uint32_t base;
      } u_gaz_feed_forward;
      u_gaz_feed_forward.base = 0;
      u_gaz_feed_forward.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gaz_feed_forward.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gaz_feed_forward.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gaz_feed_forward.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gaz_feed_forward = u_gaz_feed_forward.real;
      offset += sizeof(this->gaz_feed_forward);
      union {
        float real;
        uint32_t base;
      } u_gaz_altitude;
      u_gaz_altitude.base = 0;
      u_gaz_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gaz_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gaz_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gaz_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gaz_altitude = u_gaz_altitude.real;
      offset += sizeof(this->gaz_altitude);
      union {
        float real;
        uint32_t base;
      } u_altitude_integral;
      u_altitude_integral.base = 0;
      u_altitude_integral.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude_integral.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude_integral.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude_integral.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude_integral = u_altitude_integral.real;
      offset += sizeof(this->altitude_integral);
      union {
        float real;
        uint32_t base;
      } u_vz_ref;
      u_vz_ref.base = 0;
      u_vz_ref.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vz_ref.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vz_ref.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vz_ref.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vz_ref = u_vz_ref.real;
      offset += sizeof(this->vz_ref);
      union {
        int32_t real;
        uint32_t base;
      } u_u_pitch;
      u_u_pitch.base = 0;
      u_u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u_pitch.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u_pitch = u_u_pitch.real;
      offset += sizeof(this->u_pitch);
      union {
        int32_t real;
        uint32_t base;
      } u_u_roll;
      u_u_roll.base = 0;
      u_u_roll.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u_roll.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u_roll.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u_roll.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u_roll = u_u_roll.real;
      offset += sizeof(this->u_roll);
      union {
        int32_t real;
        uint32_t base;
      } u_u_yaw;
      u_u_yaw.base = 0;
      u_u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u_yaw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u_yaw = u_u_yaw.real;
      offset += sizeof(this->u_yaw);
      union {
        float real;
        uint32_t base;
      } u_yaw_u_I;
      u_yaw_u_I.base = 0;
      u_yaw_u_I.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_yaw_u_I.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_yaw_u_I.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_yaw_u_I.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->yaw_u_I = u_yaw_u_I.real;
      offset += sizeof(this->yaw_u_I);
      union {
        int32_t real;
        uint32_t base;
      } u_u_pitch_planif;
      u_u_pitch_planif.base = 0;
      u_u_pitch_planif.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u_pitch_planif.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u_pitch_planif.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u_pitch_planif.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u_pitch_planif = u_u_pitch_planif.real;
      offset += sizeof(this->u_pitch_planif);
      union {
        int32_t real;
        uint32_t base;
      } u_u_roll_planif;
      u_u_roll_planif.base = 0;
      u_u_roll_planif.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u_roll_planif.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u_roll_planif.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u_roll_planif.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u_roll_planif = u_u_roll_planif.real;
      offset += sizeof(this->u_roll_planif);
      union {
        int32_t real;
        uint32_t base;
      } u_u_yaw_planif;
      u_u_yaw_planif.base = 0;
      u_u_yaw_planif.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u_yaw_planif.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u_yaw_planif.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u_yaw_planif.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u_yaw_planif = u_u_yaw_planif.real;
      offset += sizeof(this->u_yaw_planif);
      union {
        float real;
        uint32_t base;
      } u_u_gaz_planif;
      u_u_gaz_planif.base = 0;
      u_u_gaz_planif.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_u_gaz_planif.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_u_gaz_planif.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_u_gaz_planif.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->u_gaz_planif = u_u_gaz_planif.real;
      offset += sizeof(this->u_gaz_planif);
      this->current_motor1 =  ((uint16_t) (*(inbuffer + offset)));
      this->current_motor1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current_motor1);
      this->current_motor2 =  ((uint16_t) (*(inbuffer + offset)));
      this->current_motor2 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current_motor2);
      this->current_motor3 =  ((uint16_t) (*(inbuffer + offset)));
      this->current_motor3 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current_motor3);
      this->current_motor4 =  ((uint16_t) (*(inbuffer + offset)));
      this->current_motor4 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->current_motor4);
      union {
        float real;
        uint32_t base;
      } u_altitude_der;
      u_altitude_der.base = 0;
      u_altitude_der.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude_der.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude_der.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude_der.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude_der = u_altitude_der.real;
      offset += sizeof(this->altitude_der);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_pwm"; };
    const char * getMD5(){ return "6369e637a869960c68d7de5c2e10d6b1"; };

  };

}
#endif
