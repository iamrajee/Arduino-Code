#ifndef _ROS_ardrone_autonomy_navdata_games_h
#define _ROS_ardrone_autonomy_navdata_games_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_games : public ros::Msg
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
      typedef uint32_t _double_tap_counter_type;
      _double_tap_counter_type double_tap_counter;
      typedef uint32_t _finish_line_counter_type;
      _finish_line_counter_type finish_line_counter;

    navdata_games():
      header(),
      drone_time(0),
      tag(0),
      size(0),
      double_tap_counter(0),
      finish_line_counter(0)
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
      *(outbuffer + offset + 0) = (this->double_tap_counter >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->double_tap_counter >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->double_tap_counter >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->double_tap_counter >> (8 * 3)) & 0xFF;
      offset += sizeof(this->double_tap_counter);
      *(outbuffer + offset + 0) = (this->finish_line_counter >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->finish_line_counter >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->finish_line_counter >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->finish_line_counter >> (8 * 3)) & 0xFF;
      offset += sizeof(this->finish_line_counter);
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
      this->double_tap_counter =  ((uint32_t) (*(inbuffer + offset)));
      this->double_tap_counter |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->double_tap_counter |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->double_tap_counter |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->double_tap_counter);
      this->finish_line_counter =  ((uint32_t) (*(inbuffer + offset)));
      this->finish_line_counter |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->finish_line_counter |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->finish_line_counter |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->finish_line_counter);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_games"; };
    const char * getMD5(){ return "3b3ea3628a5ac44a2ed78d3ac0c1cf49"; };

  };

}
#endif
