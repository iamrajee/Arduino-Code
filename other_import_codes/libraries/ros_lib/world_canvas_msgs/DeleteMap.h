#ifndef _ROS_SERVICE_DeleteMap_h
#define _ROS_SERVICE_DeleteMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace world_canvas_msgs
{

static const char DELETEMAP[] = "world_canvas_msgs/DeleteMap";

  class DeleteMapRequest : public ros::Msg
  {
    public:
      typedef const char* _map_id_type;
      _map_id_type map_id;

    DeleteMapRequest():
      map_id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_map_id = strlen(this->map_id);
      varToArr(outbuffer + offset, length_map_id);
      offset += 4;
      memcpy(outbuffer + offset, this->map_id, length_map_id);
      offset += length_map_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_map_id;
      arrToVar(length_map_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_map_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_map_id-1]=0;
      this->map_id = (char *)(inbuffer + offset-1);
      offset += length_map_id;
     return offset;
    }

    const char * getType(){ return DELETEMAP; };
    const char * getMD5(){ return "d742ddbd5e3e8937162044ae4b300275"; };

  };

  class DeleteMapResponse : public ros::Msg
  {
    public:

    DeleteMapResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return DELETEMAP; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DeleteMap {
    public:
    typedef DeleteMapRequest Request;
    typedef DeleteMapResponse Response;
  };

}
#endif
