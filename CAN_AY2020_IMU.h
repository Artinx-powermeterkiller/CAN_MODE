#ifndef CAN_AY2020_IMU_H
#define CAN_AY2020_IMU_H

#include "CAN_AY2020.h"

#define MY_BASE_ID IMU_1_ID

typedef struct
{
	int attitude_angle_id;
	int angular_velocity_id ;
	int accelerated_speed_id ;
}CAN_ID_t;


#endif 
