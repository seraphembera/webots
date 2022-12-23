#ifndef __CHASSISCONTROL_H
#define __CHASSISCONTROL_H


typedef struct
{
  float speed;
  float angle;
}SpeedVector;


typedef struct
{
  SpeedVector left_front;
  SpeedVector right_front;
  SpeedVector left_back;
  SpeedVector right_back;
}WheelTypedef;


void chassis_control(void);
void chassis_ground_coordinate_control(float ground_speed_x, float ground_speed_y, float ground_speed_z);
void chassis_self_coordinate_control(float self_speed_x, float self_speed_y, float self_speed_z);
SpeedVector chassis_wheel_calculate(float speed_x, float speed_y, float speed_z, float angle);
float chassis_judge_speed_direction(float x);


#endif
