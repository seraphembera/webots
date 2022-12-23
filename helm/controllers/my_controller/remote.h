#ifndef __REMOTE_H
#define __REMOTE_H

typedef struct
{
  float x;
  float y;
  float z;
}RemoteTypedef;


void remote_init(void);
void remote_data_update(void);
RemoteTypedef * get_remote(void);

#endif
