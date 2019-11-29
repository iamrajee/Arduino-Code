#ifndef _ROS_ardrone_autonomy_navdata_vision_detect_h
#define _ROS_ardrone_autonomy_navdata_vision_detect_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ardrone_autonomy/matrix33.h"
#include "ardrone_autonomy/vector31.h"

namespace ardrone_autonomy
{

  class navdata_vision_detect : public ros::Msg
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
      typedef uint32_t _nb_detected_type;
      _nb_detected_type nb_detected;
      uint32_t type_length;
      typedef uint32_t _type_type;
      _type_type st_type;
      _type_type * type;
      uint32_t xc_length;
      typedef uint32_t _xc_type;
      _xc_type st_xc;
      _xc_type * xc;
      uint32_t yc_length;
      typedef uint32_t _yc_type;
      _yc_type st_yc;
      _yc_type * yc;
      uint32_t width_length;
      typedef uint32_t _width_type;
      _width_type st_width;
      _width_type * width;
      uint32_t height_length;
      typedef uint32_t _height_type;
      _height_type st_height;
      _height_type * height;
      uint32_t dist_length;
      typedef uint32_t _dist_type;
      _dist_type st_dist;
      _dist_type * dist;
      uint32_t orientation_angle_length;
      typedef float _orientation_angle_type;
      _orientation_angle_type st_orientation_angle;
      _orientation_angle_type * orientation_angle;
      uint32_t rotation_length;
      typedef ardrone_autonomy::matrix33 _rotation_type;
      _rotation_type st_rotation;
      _rotation_type * rotation;
      uint32_t translation_length;
      typedef ardrone_autonomy::vector31 _translation_type;
      _translation_type st_translation;
      _translation_type * translation;
      uint32_t camera_source_length;
      typedef uint32_t _camera_source_type;
      _camera_source_type st_camera_source;
      _camera_source_type * camera_source;

    navdata_vision_detect():
      header(),
      drone_time(0),
      tag(0),
      size(0),
      nb_detected(0),
      type_length(0), type(NULL),
      xc_length(0), xc(NULL),
      yc_length(0), yc(NULL),
      width_length(0), width(NULL),
      height_length(0), height(NULL),
      dist_length(0), dist(NULL),
      orientation_angle_length(0), orientation_angle(NULL),
      rotation_length(0), rotation(NULL),
      translation_length(0), translation(NULL),
      camera_source_length(0), camera_source(NULL)
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
      *(outbuffer + offset + 0) = (this->nb_detected >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nb_detected >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nb_detected >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nb_detected >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nb_detected);
      *(outbuffer + offset + 0) = (this->type_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type_length);
      for( uint32_t i = 0; i < type_length; i++){
      *(outbuffer + offset + 0) = (this->type[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type[i]);
      }
      *(outbuffer + offset + 0) = (this->xc_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->xc_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->xc_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->xc_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xc_length);
      for( uint32_t i = 0; i < xc_length; i++){
      *(outbuffer + offset + 0) = (this->xc[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->xc[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->xc[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->xc[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->xc[i]);
      }
      *(outbuffer + offset + 0) = (this->yc_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->yc_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->yc_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->yc_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yc_length);
      for( uint32_t i = 0; i < yc_length; i++){
      *(outbuffer + offset + 0) = (this->yc[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->yc[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->yc[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->yc[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->yc[i]);
      }
      *(outbuffer + offset + 0) = (this->width_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width_length);
      for( uint32_t i = 0; i < width_length; i++){
      *(outbuffer + offset + 0) = (this->width[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width[i]);
      }
      *(outbuffer + offset + 0) = (this->height_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height_length);
      for( uint32_t i = 0; i < height_length; i++){
      *(outbuffer + offset + 0) = (this->height[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height[i]);
      }
      *(outbuffer + offset + 0) = (this->dist_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dist_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dist_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dist_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dist_length);
      for( uint32_t i = 0; i < dist_length; i++){
      *(outbuffer + offset + 0) = (this->dist[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dist[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dist[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dist[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dist[i]);
      }
      *(outbuffer + offset + 0) = (this->orientation_angle_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->orientation_angle_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->orientation_angle_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->orientation_angle_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientation_angle_length);
      for( uint32_t i = 0; i < orientation_angle_length; i++){
      union {
        float real;
        uint32_t base;
      } u_orientation_anglei;
      u_orientation_anglei.real = this->orientation_angle[i];
      *(outbuffer + offset + 0) = (u_orientation_anglei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_orientation_anglei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_orientation_anglei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_orientation_anglei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->orientation_angle[i]);
      }
      *(outbuffer + offset + 0) = (this->rotation_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->rotation_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->rotation_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->rotation_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->rotation_length);
      for( uint32_t i = 0; i < rotation_length; i++){
      offset += this->rotation[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->translation_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->translation_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->translation_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->translation_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->translation_length);
      for( uint32_t i = 0; i < translation_length; i++){
      offset += this->translation[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->camera_source_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->camera_source_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->camera_source_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->camera_source_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->camera_source_length);
      for( uint32_t i = 0; i < camera_source_length; i++){
      *(outbuffer + offset + 0) = (this->camera_source[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->camera_source[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->camera_source[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->camera_source[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->camera_source[i]);
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
      this->nb_detected =  ((uint32_t) (*(inbuffer + offset)));
      this->nb_detected |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->nb_detected |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->nb_detected |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->nb_detected);
      uint32_t type_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->type_length);
      if(type_lengthT > type_length)
        this->type = (uint32_t*)realloc(this->type, type_lengthT * sizeof(uint32_t));
      type_length = type_lengthT;
      for( uint32_t i = 0; i < type_length; i++){
      this->st_type =  ((uint32_t) (*(inbuffer + offset)));
      this->st_type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_type);
        memcpy( &(this->type[i]), &(this->st_type), sizeof(uint32_t));
      }
      uint32_t xc_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      xc_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      xc_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      xc_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->xc_length);
      if(xc_lengthT > xc_length)
        this->xc = (uint32_t*)realloc(this->xc, xc_lengthT * sizeof(uint32_t));
      xc_length = xc_lengthT;
      for( uint32_t i = 0; i < xc_length; i++){
      this->st_xc =  ((uint32_t) (*(inbuffer + offset)));
      this->st_xc |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_xc |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_xc |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_xc);
        memcpy( &(this->xc[i]), &(this->st_xc), sizeof(uint32_t));
      }
      uint32_t yc_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      yc_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      yc_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      yc_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->yc_length);
      if(yc_lengthT > yc_length)
        this->yc = (uint32_t*)realloc(this->yc, yc_lengthT * sizeof(uint32_t));
      yc_length = yc_lengthT;
      for( uint32_t i = 0; i < yc_length; i++){
      this->st_yc =  ((uint32_t) (*(inbuffer + offset)));
      this->st_yc |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_yc |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_yc |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_yc);
        memcpy( &(this->yc[i]), &(this->st_yc), sizeof(uint32_t));
      }
      uint32_t width_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      width_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      width_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      width_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->width_length);
      if(width_lengthT > width_length)
        this->width = (uint32_t*)realloc(this->width, width_lengthT * sizeof(uint32_t));
      width_length = width_lengthT;
      for( uint32_t i = 0; i < width_length; i++){
      this->st_width =  ((uint32_t) (*(inbuffer + offset)));
      this->st_width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_width);
        memcpy( &(this->width[i]), &(this->st_width), sizeof(uint32_t));
      }
      uint32_t height_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      height_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      height_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      height_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->height_length);
      if(height_lengthT > height_length)
        this->height = (uint32_t*)realloc(this->height, height_lengthT * sizeof(uint32_t));
      height_length = height_lengthT;
      for( uint32_t i = 0; i < height_length; i++){
      this->st_height =  ((uint32_t) (*(inbuffer + offset)));
      this->st_height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_height);
        memcpy( &(this->height[i]), &(this->st_height), sizeof(uint32_t));
      }
      uint32_t dist_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dist_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dist_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dist_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dist_length);
      if(dist_lengthT > dist_length)
        this->dist = (uint32_t*)realloc(this->dist, dist_lengthT * sizeof(uint32_t));
      dist_length = dist_lengthT;
      for( uint32_t i = 0; i < dist_length; i++){
      this->st_dist =  ((uint32_t) (*(inbuffer + offset)));
      this->st_dist |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_dist |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_dist |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_dist);
        memcpy( &(this->dist[i]), &(this->st_dist), sizeof(uint32_t));
      }
      uint32_t orientation_angle_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      orientation_angle_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      orientation_angle_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      orientation_angle_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->orientation_angle_length);
      if(orientation_angle_lengthT > orientation_angle_length)
        this->orientation_angle = (float*)realloc(this->orientation_angle, orientation_angle_lengthT * sizeof(float));
      orientation_angle_length = orientation_angle_lengthT;
      for( uint32_t i = 0; i < orientation_angle_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_orientation_angle;
      u_st_orientation_angle.base = 0;
      u_st_orientation_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_orientation_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_orientation_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_orientation_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_orientation_angle = u_st_orientation_angle.real;
      offset += sizeof(this->st_orientation_angle);
        memcpy( &(this->orientation_angle[i]), &(this->st_orientation_angle), sizeof(float));
      }
      uint32_t rotation_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      rotation_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rotation_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rotation_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->rotation_length);
      if(rotation_lengthT > rotation_length)
        this->rotation = (ardrone_autonomy::matrix33*)realloc(this->rotation, rotation_lengthT * sizeof(ardrone_autonomy::matrix33));
      rotation_length = rotation_lengthT;
      for( uint32_t i = 0; i < rotation_length; i++){
      offset += this->st_rotation.deserialize(inbuffer + offset);
        memcpy( &(this->rotation[i]), &(this->st_rotation), sizeof(ardrone_autonomy::matrix33));
      }
      uint32_t translation_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      translation_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      translation_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      translation_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->translation_length);
      if(translation_lengthT > translation_length)
        this->translation = (ardrone_autonomy::vector31*)realloc(this->translation, translation_lengthT * sizeof(ardrone_autonomy::vector31));
      translation_length = translation_lengthT;
      for( uint32_t i = 0; i < translation_length; i++){
      offset += this->st_translation.deserialize(inbuffer + offset);
        memcpy( &(this->translation[i]), &(this->st_translation), sizeof(ardrone_autonomy::vector31));
      }
      uint32_t camera_source_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      camera_source_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      camera_source_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      camera_source_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->camera_source_length);
      if(camera_source_lengthT > camera_source_length)
        this->camera_source = (uint32_t*)realloc(this->camera_source, camera_source_lengthT * sizeof(uint32_t));
      camera_source_length = camera_source_lengthT;
      for( uint32_t i = 0; i < camera_source_length; i++){
      this->st_camera_source =  ((uint32_t) (*(inbuffer + offset)));
      this->st_camera_source |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_camera_source |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_camera_source |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_camera_source);
        memcpy( &(this->camera_source[i]), &(this->st_camera_source), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_vision_detect"; };
    const char * getMD5(){ return "ab5f6b8c66aead58358d45a7c2dce7f6"; };

  };

}
#endif
