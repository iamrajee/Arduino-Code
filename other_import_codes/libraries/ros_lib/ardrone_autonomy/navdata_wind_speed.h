#ifndef _ROS_ardrone_autonomy_navdata_wind_speed_h
#define _ROS_ardrone_autonomy_navdata_wind_speed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_wind_speed : public ros::Msg
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
      typedef float _wind_speed_type;
      _wind_speed_type wind_speed;
      typedef float _wind_angle_type;
      _wind_angle_type wind_angle;
      typedef float _wind_compensation_theta_type;
      _wind_compensation_theta_type wind_compensation_theta;
      typedef float _wind_compensation_phi_type;
      _wind_compensation_phi_type wind_compensation_phi;
      typedef float _state_x1_type;
      _state_x1_type state_x1;
      typedef float _state_x2_type;
      _state_x2_type state_x2;
      typedef float _state_x3_type;
      _state_x3_type state_x3;
      typedef float _state_x4_type;
      _state_x4_type state_x4;
      typedef float _state_x5_type;
      _state_x5_type state_x5;
      typedef float _state_x6_type;
      _state_x6_type state_x6;
      typedef float _magneto_debug1_type;
      _magneto_debug1_type magneto_debug1;
      typedef float _magneto_debug2_type;
      _magneto_debug2_type magneto_debug2;
      typedef float _magneto_debug3_type;
      _magneto_debug3_type magneto_debug3;

    navdata_wind_speed():
      header(),
      drone_time(0),
      tag(0),
      size(0),
      wind_speed(0),
      wind_angle(0),
      wind_compensation_theta(0),
      wind_compensation_phi(0),
      state_x1(0),
      state_x2(0),
      state_x3(0),
      state_x4(0),
      state_x5(0),
      state_x6(0),
      magneto_debug1(0),
      magneto_debug2(0),
      magneto_debug3(0)
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
      } u_wind_compensation_theta;
      u_wind_compensation_theta.real = this->wind_compensation_theta;
      *(outbuffer + offset + 0) = (u_wind_compensation_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wind_compensation_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wind_compensation_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wind_compensation_theta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wind_compensation_theta);
      union {
        float real;
        uint32_t base;
      } u_wind_compensation_phi;
      u_wind_compensation_phi.real = this->wind_compensation_phi;
      *(outbuffer + offset + 0) = (u_wind_compensation_phi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_wind_compensation_phi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_wind_compensation_phi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_wind_compensation_phi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wind_compensation_phi);
      union {
        float real;
        uint32_t base;
      } u_state_x1;
      u_state_x1.real = this->state_x1;
      *(outbuffer + offset + 0) = (u_state_x1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state_x1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state_x1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state_x1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_x1);
      union {
        float real;
        uint32_t base;
      } u_state_x2;
      u_state_x2.real = this->state_x2;
      *(outbuffer + offset + 0) = (u_state_x2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state_x2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state_x2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state_x2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_x2);
      union {
        float real;
        uint32_t base;
      } u_state_x3;
      u_state_x3.real = this->state_x3;
      *(outbuffer + offset + 0) = (u_state_x3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state_x3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state_x3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state_x3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_x3);
      union {
        float real;
        uint32_t base;
      } u_state_x4;
      u_state_x4.real = this->state_x4;
      *(outbuffer + offset + 0) = (u_state_x4.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state_x4.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state_x4.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state_x4.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_x4);
      union {
        float real;
        uint32_t base;
      } u_state_x5;
      u_state_x5.real = this->state_x5;
      *(outbuffer + offset + 0) = (u_state_x5.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state_x5.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state_x5.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state_x5.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_x5);
      union {
        float real;
        uint32_t base;
      } u_state_x6;
      u_state_x6.real = this->state_x6;
      *(outbuffer + offset + 0) = (u_state_x6.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state_x6.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state_x6.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state_x6.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_x6);
      union {
        float real;
        uint32_t base;
      } u_magneto_debug1;
      u_magneto_debug1.real = this->magneto_debug1;
      *(outbuffer + offset + 0) = (u_magneto_debug1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magneto_debug1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magneto_debug1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magneto_debug1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->magneto_debug1);
      union {
        float real;
        uint32_t base;
      } u_magneto_debug2;
      u_magneto_debug2.real = this->magneto_debug2;
      *(outbuffer + offset + 0) = (u_magneto_debug2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magneto_debug2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magneto_debug2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magneto_debug2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->magneto_debug2);
      union {
        float real;
        uint32_t base;
      } u_magneto_debug3;
      u_magneto_debug3.real = this->magneto_debug3;
      *(outbuffer + offset + 0) = (u_magneto_debug3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_magneto_debug3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_magneto_debug3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_magneto_debug3.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->magneto_debug3);
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
      } u_wind_compensation_theta;
      u_wind_compensation_theta.base = 0;
      u_wind_compensation_theta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wind_compensation_theta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wind_compensation_theta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wind_compensation_theta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wind_compensation_theta = u_wind_compensation_theta.real;
      offset += sizeof(this->wind_compensation_theta);
      union {
        float real;
        uint32_t base;
      } u_wind_compensation_phi;
      u_wind_compensation_phi.base = 0;
      u_wind_compensation_phi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_wind_compensation_phi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_wind_compensation_phi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_wind_compensation_phi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->wind_compensation_phi = u_wind_compensation_phi.real;
      offset += sizeof(this->wind_compensation_phi);
      union {
        float real;
        uint32_t base;
      } u_state_x1;
      u_state_x1.base = 0;
      u_state_x1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state_x1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state_x1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state_x1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state_x1 = u_state_x1.real;
      offset += sizeof(this->state_x1);
      union {
        float real;
        uint32_t base;
      } u_state_x2;
      u_state_x2.base = 0;
      u_state_x2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state_x2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state_x2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state_x2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state_x2 = u_state_x2.real;
      offset += sizeof(this->state_x2);
      union {
        float real;
        uint32_t base;
      } u_state_x3;
      u_state_x3.base = 0;
      u_state_x3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state_x3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state_x3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state_x3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state_x3 = u_state_x3.real;
      offset += sizeof(this->state_x3);
      union {
        float real;
        uint32_t base;
      } u_state_x4;
      u_state_x4.base = 0;
      u_state_x4.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state_x4.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state_x4.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state_x4.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state_x4 = u_state_x4.real;
      offset += sizeof(this->state_x4);
      union {
        float real;
        uint32_t base;
      } u_state_x5;
      u_state_x5.base = 0;
      u_state_x5.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state_x5.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state_x5.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state_x5.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state_x5 = u_state_x5.real;
      offset += sizeof(this->state_x5);
      union {
        float real;
        uint32_t base;
      } u_state_x6;
      u_state_x6.base = 0;
      u_state_x6.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state_x6.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state_x6.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state_x6.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state_x6 = u_state_x6.real;
      offset += sizeof(this->state_x6);
      union {
        float real;
        uint32_t base;
      } u_magneto_debug1;
      u_magneto_debug1.base = 0;
      u_magneto_debug1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magneto_debug1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magneto_debug1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magneto_debug1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->magneto_debug1 = u_magneto_debug1.real;
      offset += sizeof(this->magneto_debug1);
      union {
        float real;
        uint32_t base;
      } u_magneto_debug2;
      u_magneto_debug2.base = 0;
      u_magneto_debug2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magneto_debug2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magneto_debug2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magneto_debug2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->magneto_debug2 = u_magneto_debug2.real;
      offset += sizeof(this->magneto_debug2);
      union {
        float real;
        uint32_t base;
      } u_magneto_debug3;
      u_magneto_debug3.base = 0;
      u_magneto_debug3.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_magneto_debug3.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_magneto_debug3.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_magneto_debug3.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->magneto_debug3 = u_magneto_debug3.real;
      offset += sizeof(this->magneto_debug3);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_wind_speed"; };
    const char * getMD5(){ return "2cc5c1e9675c330dd38261e958a136d3"; };

  };

}
#endif
