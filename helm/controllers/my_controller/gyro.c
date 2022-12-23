#include <gyro.h>
#include <webots/robot.h>
#include <webots/inertial_unit.h>

static WbDeviceTag gyro;

void gyro_init(void)
{
    gyro = wb_robot_get_device("inertial_unit");
    wb_inertial_unit_enable(gyro, 32);
}

double gyro_yaw_data_update(void)
{
  const double * data = wb_inertial_unit_get_roll_pitch_yaw(gyro);
  
  return data[2];
}


