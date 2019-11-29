#ifndef _ROS_cvg_sim_msgs_Altitude_h
#define _ROS_cvg_sim_msgs_Altitude_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cvg_sim_msgs
{

  class Altitude : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _height_type;
      _height_type height;
      typedef float _altitude_type;
      _altitude_type altitude;
      typedef float _elevation_type;
      _elevation_type elevation;
      typedef float _qnh_type;
      _qnh_type qnh;

    Altitude():
      header(),
      height(0),
      altitude(0),
      elevation(0),
      qnh(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_height;
      u_height.real = this->height;
      *(outbuffer + offset + 0) = (u_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_elevation;
      u_elevation.real = this->elevation;
      *(outbuffer + offset + 0) = (u_elevation.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_elevation.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_elevation.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_elevation.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->elevation);
      union {
        float real;
        uint32_t base;
      } u_qnh;
      u_qnh.real = this->qnh;
      *(outbuffer + offset + 0) = (u_qnh.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_qnh.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_qnh.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_qnh.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->qnh);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_height;
      u_height.base = 0;
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->height = u_height.real;
      offset += sizeof(this->height);
      union {
        float real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_elevation;
      u_elevation.base = 0;
      u_elevation.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_elevation.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_elevation.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_elevation.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->elevation = u_elevation.real;
      offset += sizeof(this->elevation);
      union {
        float real;
        uint32_t base;
      } u_qnh;
      u_qnh.base = 0;
      u_qnh.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_qnh.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_qnh.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_qnh.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->qnh = u_qnh.real;
      offset += sizeof(this->qnh);
     return offset;
    }

    const char * getType(){ return "cvg_sim_msgs/Altitude"; };
    const char * getMD5(){ return "b9fb5f353226e94d84dfd4ef8a74c81d"; };

  };

}
#endif
