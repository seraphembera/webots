#include <remote.h>
#include <webots/keyboard.h>
#include <stdio.h>

static RemoteTypedef remote;

void remote_init(void)
{
  wb_keyboard_enable(32);
}

void remote_data_update(void)
{
  int key = wb_keyboard_get_key();
  if(key == WB_KEYBOARD_UP)
  {
    remote.x = 0;
    remote.y = 20;
    remote.z = 0;
  }
  else if(key == WB_KEYBOARD_DOWN)
  {
    remote.x = 0;
    remote.y = -20;
    remote.z = 0;
  }
  else if(key == WB_KEYBOARD_LEFT)
  {
    remote.x = -20;
    remote.y = 0;
    remote.z = 0;
  }
  else if(key == WB_KEYBOARD_RIGHT)
  {
    remote.x = 20;
    remote.y = 0;
    remote.z = 0;
  }
  else if(key == (WB_KEYBOARD_LEFT + WB_KEYBOARD_UP))
  {
    remote.x = -20;
    remote.y = 20;
    remote.z = 0;
  }
  else if(key == (WB_KEYBOARD_RIGHT + WB_KEYBOARD_UP))
  {
    remote.x = 20;
    remote.y = 20;
    remote.z = 0;
  }
  else if(key == (WB_KEYBOARD_LEFT + WB_KEYBOARD_DOWN))
  {
    remote.x = -20;
    remote.y = -20;
    remote.z = 0;
  }
  else if(key == (WB_KEYBOARD_RIGHT + WB_KEYBOARD_DOWN))
  {
    remote.x = 20;
    remote.y = -20;
    remote.z = 0;
  }
  else
  {
    remote.x = 0;
    remote.y = 0;
    remote.z = 0;
  }
  // printf("x = %f\n", remote.x);
  // printf("y = %f\n", remote.y);
  // printf("z = %f\n", remote.z);
  printf("key = %d\n", key);
}

RemoteTypedef * get_remote(void)
{
  return &remote;
}
