/*
 * File:          my_controller.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/keyboard.h>

#include <stdio.h>
#include <ChassisControl.h>
#include <pid.h>
#include <motor.h>
#include <gyro.h>
#include <remote.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 32



int main(int argc, char **argv) 
{
  /* necessary to initialize webots stuff */
  wb_robot_init();
  motor_init();
  gyro_init();
  remote_init();

  
  while (wb_robot_step(TIME_STEP) != -1) 
  {
    chassis_control();
  };

  
  wb_robot_cleanup();

  return 0;
}
