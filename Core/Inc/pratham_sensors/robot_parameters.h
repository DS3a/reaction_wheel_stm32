#ifndef _ROS_pratham_sensors_robot_parameters_h
#define _ROS_pratham_sensors_robot_parameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float32.h"

namespace pratham_sensors
{

  class robot_parameters : public ros::Msg
  {
    public:
      typedef std_msgs::Float32 _wheel_diameter_type;
      _wheel_diameter_type wheel_diameter;
      typedef std_msgs::Float32 _wheel_distance_type;
      _wheel_distance_type wheel_distance;

    robot_parameters():
      wheel_diameter(),
      wheel_distance()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->wheel_diameter.serialize(outbuffer + offset);
      offset += this->wheel_distance.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->wheel_diameter.deserialize(inbuffer + offset);
      offset += this->wheel_distance.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "pratham_sensors/robot_parameters"; };
    virtual const char * getMD5() override { return "1938a8a6ca2d9c68bc0cc66b04bffd62"; };

  };

}
#endif
