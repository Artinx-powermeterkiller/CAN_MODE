#ifndef CAN_AY2020
#define CAN_AY2020

#include "schedule_table.h"

#define CHANNEL_NUMBER 4

typedef struct
{
	uint8_t enable_state;
	uint8_t freq;
	uint8_t channel;
	uint8_t* id_order_list_ptr;
	uint16_t id;
}CAN_id_t;

typedef struct
{
	uint8_t actived_id[5];
	uint8_t fast_send_order[10];
}fast_channel_t;

typedef struct
{
	uint8_t activied_id[10];
	uint8_t public_channel_occupy_list[13];
	uint8_t read_ahead_buff[10][2];
}slow_channel_t;

void CAN_id_init(CAN_id_t* CAN_id_ptr, uint8_t id,uint8_t freq, uint8_t channel);
void CAN_id_cmd(CAN_id_t* CAN_id, uint8_t state);

void CAN_AY2020_init(void);
void CAN_Channl_init(void);

void add_message_to_channel(int channel_id,int message_id,int freq);
void remove_message_from_channel(int channel_id, int message_id);

#endif
