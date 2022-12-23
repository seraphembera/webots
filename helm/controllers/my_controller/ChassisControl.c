#include <ChassisControl.h>
#include <motor.h>
#include <math.h>
#include <stdio.h>
#include <gyro.h>
#include <remote.h>


void chassis_control(void)
{
  remote_data_update();
  chassis_ground_coordinate_control(get_remote()->x, get_remote()->y, get_remote()->z);
}


void chassis_ground_coordinate_control(float ground_speed_x, float ground_speed_y, float ground_speed_z)
{
  float self_speed_x, self_speed_y;
  float yaw = gyro_yaw_data_update();
  
  self_speed_x = ground_speed_x * cosf(yaw) + ground_speed_y * sinf(yaw);
  self_speed_y = ground_speed_y * cosf(yaw) - ground_speed_x * sinf(yaw);
  
  chassis_self_coordinate_control(self_speed_x, self_speed_y, ground_speed_z);
};


void chassis_self_coordinate_control(float self_speed_x, float self_speed_y, float self_speed_z)
{
  static WheelTypedef wheel;
  
  wheel.left_front = chassis_wheel_calculate(self_speed_x, self_speed_y, self_speed_z, -135.0f);
  wheel.right_front = chassis_wheel_calculate(self_speed_x, self_speed_y, self_speed_z, 135.0f);
  wheel.left_back = chassis_wheel_calculate(self_speed_x, self_speed_y, self_speed_z, -45.0f);
  wheel.right_back = chassis_wheel_calculate(self_speed_x, self_speed_y, self_speed_z, 45.0f);
  
  set_motor_speed(wheel.left_front.speed, wheel.right_front.speed, wheel.left_back.speed, wheel.right_back.speed);
  set_servo_angle(wheel.left_front.angle, wheel.right_front.angle, wheel.left_back.angle, wheel.right_back.angle);
}


SpeedVector chassis_wheel_calculate(float speed_x, float speed_y, float speed_z, float angle)
{
  SpeedVector wheel_speed;
  float velocity_x = 0.0f, velocity_y = 0.0f;
  
  velocity_x = speed_x + speed_z * cosf(ANGLE2RAD(angle));
  velocity_y = speed_y + speed_z * sinf(ANGLE2RAD(angle));
  
  wheel_speed.speed = chassis_judge_speed_direction(velocity_x) * sqrt(velocity_x * velocity_x + velocity_y * velocity_y);
  if((velocity_x != 0) && (velocity_y != 0))
  {
    wheel_speed.angle = RAD2ANGLE(atan(velocity_y/velocity_x));
  }
  
  // printf("angle = %f\n", wheel_speed.angle);
  
  return wheel_speed;
}


float chassis_judge_speed_direction(float x)
{ 
 if(x < 0)
 {
   return -1;
 }  
 else 
 {
   return 1;
 }
}


  
  

