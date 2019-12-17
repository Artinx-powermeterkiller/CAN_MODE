#ifndef CAN_AY2020
#define CAN_AY2020

#include "schedule_table.h"

typedef struct
{
	int channel_id;
	int least_freq;
	channl_schedule_table_t* schedule_table_ptr;
}CAN_channel_t;
N_MODE

void CAN_AY2020_init(void);
void CAN_Channl_init(void);

void add_message_to_channel(int channel_id,int message_id,int freq);
void remove_message_from_channel(int channel_id, int message_id);

#endif
