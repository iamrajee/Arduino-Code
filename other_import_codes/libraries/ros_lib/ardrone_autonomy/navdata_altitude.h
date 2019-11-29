#ifndef _ROS_ardrone_autonomy_navdata_altitude_h
#define _ROS_ardrone_autonomy_navdata_altitude_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ardrone_autonomy/vector31.h"
#include "ardrone_autonomy/vector21.h"

namespace ardrone_autonomy
{

  class navdata_altitude : public ros::Msg
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
      typedef int32_t _altitude_vision_type;
      _altitude_vision_type altitude_vision;
      typedef float _altitude_vz_type;
      _altitude_vz_type altitude_vz;
      typedef int32_t _altitude_ref_type;
      _altitude_ref_type altitude_ref;
      typedef int32_t _altitude_raw_type;
      _altitude_raw_type altitude_raw;
      typedef float _obs_accZ_type;
      _obs_accZ_type obs_accZ;
      typedef float _obs_alt_type;
      _obs_alt_type obs_alt;
      typedef ardrone_autonomy::vector31 _obs_x_type;
      _obs_x_type obs_x;
      typedef uint32_t _obs_state_type;
      _obs_state_type obs_state;
      typedef ardrone_autonomy::vector21 _est_vb_type;
      _est_vb_type est_vb;
      typedef uint32_t _est_state_type;
      _est_state_type est_state;

    navdata_altitude():
      header(),
      drone_time(0),
      tag(0),
      size(0),
      altitude_vision(0),
      altitude_vz(0),
      altitude_ref(0),
      altitude_raw(0),
      obs_accZ(0),
      obs_alt(0),
      obs_x(),
      obs_state(0),
      est_vb(),
      est_state(0)
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
        int32_t real;
        uint32_t base;
      } u_altitude_vision;
      u_altitude_vision.real = this->altitude_vision;
      *(outbuffer + offset + 0) = (u_altitude_vision.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude_vision.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude_vision.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude_vision.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude_vision);
      union {
        float real;
        uint32_t base;
      } u_altitude_vz;
      u_altitude_vz.real = this->altitude_vz;
      *(outbuffer + offset + 0) = (u_altitude_vz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude_vz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude_vz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude_vz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude_vz);
      union {
        int32_t real;
        uint32_t base;
      } u_altitude_ref;
      u_altitude_ref.real = this->altitude_ref;
      *(outbuffer + offset + 0) = (u_altitude_ref.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude_ref.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude_ref.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude_ref.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude_ref);
      union {
        int32_t real;
        uint32_t base;
      } u_altitude_raw;
      u_altitude_raw.real = this->altitude_raw;
      *(outbuffer + offset + 0) = (u_altitude_raw.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude_raw.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude_raw.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude_raw.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude_raw);
      union {
        float real;
        uint32_t base;
      } u_obs_accZ;
      u_obs_accZ.real = this->obs_accZ;
      *(outbuffer + offset + 0) = (u_obs_accZ.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_accZ.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_accZ.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_accZ.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_accZ);
      union {
        float real;
        uint32_t base;
      } u_obs_alt;
      u_obs_alt.real = this->obs_alt;
      *(outbuffer + offset + 0) = (u_obs_alt.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_obs_alt.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_obs_alt.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_obs_alt.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_alt);
      offset += this->obs_x.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->obs_state >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->obs_state >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->obs_state >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->obs_state >> (8 * 3)) & 0xFF;
      offset += sizeof(this->obs_state);
      offset += this->est_vb.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->est_state >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->est_state >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->est_state >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->est_state >> (8 * 3)) & 0xFF;
      offset += sizeof(this->est_state);
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
        int32_t real;
        uint32_t base;
      } u_altitude_vision;
      u_altitude_vision.base = 0;
      u_altitude_vision.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude_vision.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude_vision.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude_vision.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude_vision = u_altitude_vision.real;
      offset += sizeof(this->altitude_vision);
      union {
        float real;
        uint32_t base;
      } u_altitude_vz;
      u_altitude_vz.base = 0;
      u_altitude_vz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude_vz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude_vz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude_vz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude_vz = u_altitude_vz.real;
      offset += sizeof(this->altitude_vz);
      union {
        int32_t real;
        uint32_t base;
      } u_altitude_ref;
      u_altitude_ref.base = 0;
      u_altitude_ref.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude_ref.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude_ref.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude_ref.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude_ref = u_altitude_ref.real;
      offset += sizeof(this->altitude_ref);
      union {
        int32_t real;
        uint32_t base;
      } u_altitude_raw;
      u_altitude_raw.base = 0;
      u_altitude_raw.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude_raw.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude_raw.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude_raw.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude_raw = u_altitude_raw.real;
      offset += sizeof(this->altitude_raw);
      union {
        float real;
        uint32_t base;
      } u_obs_accZ;
      u_obs_accZ.base = 0;
      u_obs_accZ.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs_accZ.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs_accZ.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs_accZ.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs_accZ = u_obs_accZ.real;
      offset += sizeof(this->obs_accZ);
      union {
        float real;
        uint32_t base;
      } u_obs_alt;
      u_obs_alt.base = 0;
      u_obs_alt.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_obs_alt.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_obs_alt.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_obs_alt.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->obs_alt = u_obs_alt.real;
      offset += sizeof(this->obs_alt);
      offset += this->obs_x.deserialize(inbuffer + offset);
      this->obs_state =  ((uint32_t) (*(inbuffer + offset)));
      this->obs_state |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->obs_state |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->obs_state |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->obs_state);
      offset += this->est_vb.deserialize(inbuffer + offset);
      this->est_state =  ((uint32_t) (*(inbuffer + offset)));
      this->est_state |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->est_state |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->est_state |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->est_state);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_altitude"; };
    const char * getMD5(){ return "f0fd1fd20697e6083c6bc3a308a260dc"; };

  };

}
#endif
