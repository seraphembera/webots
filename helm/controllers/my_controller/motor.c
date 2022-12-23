#include <motor.h>
#include <webots/motor.h>
#include <math.h>

static MotorTag motor_tag;

void motor_init(void)
{
  motor_tag.wheel1_motor = wb_robot_get_device("wheel1_motor");
  motor_tag.wheel2_motor = wb_robot_get_device("wheel2_motor");
  motor_tag.wheel3_motor = wb_robot_get_device("wheel3_motor");
  motor_tag.wheel4_motor = wb_robot_get_device("wheel4_motor");
  motor_tag.wheel1_servo = wb_robot_get_device("wheel1_servo");
  motor_tag.wheel2_servo = wb_robot_get_device("wheel2_servo");
  motor_tag.wheel3_servo = wb_robot_get_device("wheel3_servo");
  motor_tag.wheel4_servo = wb_robot_get_device("wheel4_servo");
  
  wb_motor_set_position(motor_tag.wheel1_motor, INFINITY);
  wb_motor_set_position(motor_tag.wheel2_motor, INFINITY);
  wb_motor_set_position(motor_tag.wheel3_motor, INFINITY);
  wb_motor_set_position(motor_tag.wheel4_motor, INFINITY);
  wb_motor_set_position(motor_tag.wheel1_servo, 0);
  wb_motor_set_position(motor_tag.wheel2_servo, 0);
  wb_motor_set_position(motor_tag.wheel3_servo, 0);
  wb_motor_set_position(motor_tag.wheel4_servo, 0);
  
  wb_motor_set_velocity(motor_tag.wheel1_motor, 0);
  wb_motor_set_velocity(motor_tag.wheel2_motor, 0);
  wb_motor_set_velocity(motor_tag.wheel3_motor, 0);
  wb_motor_set_velocity(motor_tag.wheel4_motor, 0);
}

void set_motor_speed(float motor1_speed, float motor2_speed, float motor3_speed, float motor4_speed)
{
  wb_motor_set_velocity(motor_tag.wheel1_motor, motor1_speed);
  wb_motor_set_velocity(motor_tag.wheel2_motor, motor2_speed);
  wb_motor_set_velocity(motor_tag.wheel3_motor, motor3_speed);
  wb_motor_set_velocity(motor_tag.wheel4_motor, motor4_speed);
}

void set_servo_angle(float servo1_angle, float servo2_angle, float servo3_angle, float servo4_angle)
{
  wb_motor_set_position(motor_tag.wheel1_servo, ANGLE2RAD(servo1_angle));
  wb_motor_set_position(motor_tag.wheel2_servo, ANGLE2RAD(servo2_angle));
  wb_motor_set_position(motor_tag.wheel3_servo, ANGLE2RAD(servo3_angle));
  wb_motor_set_position(motor_tag.wheel4_servo, ANGLE2RAD(servo4_angle));
}

MotorTag* get_motor_tag(void)
{
  return &motor_tag;
}

