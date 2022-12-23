/***************(C) COPYRIGHT SWUST_ROBOCON *************BEGIN OF FILE***************/   
/**
  ******************************************************************************
  * @file      pid.h
  * @author    SWUST_ROBOCON
  * @version   V1.0.0
  * @date      2022-10-25
  * @brief     
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 SWUST_ROBOCON.
  * All rights reserved.</center></h2>
  * 
  ******************************************************************************
  */

#ifndef __PID_H
#define __PID_H

#ifdef __cplusplus
 extern "C" {       
#endif

#define LimitMax(input, max)   \
    {                          \
        if (input > max)       \
        {                      \
            input = max;       \
        }                      \
        else if (input < -max) \
        {                      \
            input = -max;      \
        }                      \
    }

typedef enum
{
  POSITION_MODE = 0,
  INCREMENT_MODE =1,
}PID_MODE;

typedef struct
{
	PID_MODE mode;
	
	float Kp;
	float Ki;
	float Kd;

	float max_out;  //������
	float max_iout; //���������

	float measure;
	float target;

	float Pout;
	float Iout;
	float Dout;
	float PID_out;
	
	float Dbuf[3];  //΢���� 0���� 1��һ�� 2���ϴ�
	float error[3]; //����� 0���� 1��һ�� 2���ϴ�
} PidTypeDef;


void pid_init(PidTypeDef *pid, PID_MODE mode, const float Kp, const float Ki, const float Kd, const float max_iout, const float max_out);
float pid_control(PidTypeDef * pid, float target, float measure);
float pid_cascade_control(PidTypeDef  * pid_outer, PidTypeDef * pid_inside, float pid_outer_target, float pid_outer_mersure, float pid_inside_mersure);
void pid_clear(PidTypeDef *pid);

#ifdef __cplusplus
}
#endif

#endif /* __PID_H */

/**
  * @}
  */

/***************(C) COPYRIGHT SWUST_ROBOCON *************END OF FILE********************/
