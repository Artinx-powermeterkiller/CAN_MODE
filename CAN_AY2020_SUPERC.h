#ifndef CAN_AY2020_SUPERC_H
#define CAN_AY2020_SUPERC_H

#include "CAN_AY2020.h"

#define MY_BASE_ID 0x120

typedef struct
{
	int on_time_power_id = MY_BASE_ID + 1;
	int capacitance_state_id = MY_BASE_ID + 2;
}CAN_ID_T;


#endif 
