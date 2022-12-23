#ifndef __MOTOR_H
#define __MOTOR_H

#include <webots/robot.h>

#define PI 3.1415926f

#define RAD2ANGLE(x) ((x)/PI*180.0f)
#define ANGLE2RAD(x) ((x)*PI/180.0f)



typedef struct
{
  WbDeviceTag wheel1_motor;
  WbDeviceTag wheel2_motor;
  WbDeviceTag wheel3_motor;
  WbDeviceTag wheel4_motor;
  WbDeviceTag wheel1_servo;
  WbDeviceTag wheel2_servo;
  WbDeviceTag wheel3_servo;
  WbDeviceTag wheel4_servo;
}MotorTag;


void motor_init(void);
void set_motor_speed(float motor1_speed, float motor2_speed, float motor3_speed, float motor4_speed);
void set_servo_angle(float servo1_angle, float servo2_angle, float servo3_angle, float servo4_angle);
MotorTag* get_motor_tag(void);

#endif
