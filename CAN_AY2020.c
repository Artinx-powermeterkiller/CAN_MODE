#include "CAN_AY2020_IMU.h"
#include "CAN_AY2020.h"
#include <stdlib.h>

static fast_channel_t fast_channel[2];

void CAN_AY2020_init(void)
{
	CAN_Channl_init();
	
	BSP_AY2020_timer_init();
	BSP_AY2020_init();

}

void CAN_id_init(CAN_id_t* CAN_id_ptr, uint8_t id, uint8_t freq, uint8_t channel)
{
	CAN_id_ptr->id = id;
	CAN_id_ptr->freq = freq;
	CAN_id_ptr->channel = channel;
	if (channel > 1)
	{
		CAN_id_ptr->slow_channel_id_order_list_ptr = calloc(freq + 1, sizeof(uint16_t));
	}
	else
	{
		CAN_fast_channel_id_order_list_build(&fast_channel[channel],CAN_id_ptr);
	}
}

void CAN_fast_channel_id_order_list_build(fast_channel_t* fast_channel, CAN_id_t* CAN_id_ptr)
{
	uint16_t id = CAN_id_ptr->id, freq = CAN_id_ptr->freq;

	if (id>= ID_LIMITED || freq%100!=0||fast_channel->number_of_id>=5)
	{
		return 0;
	}

	for (uint8_t i = 0; i < fast_channel->number_of_id; i++)
	{
		if (fast_channel->actived_id[i] == id)
		{
			return 0;
		}
	}

	fast_channel->actived_id[fast_channel->number_of_id] = id;
	fast_channel->number_of_id++;

	uint8_t repetition_num = freq % 100;

	for (uint8_t i = 0; i < repetition_num; i++)
	{
		if (fast_channel->fast_send_order[i] == 0)
		{
			fast_channel->fast_send_order[i] = id;
		}
	}

}

uint8_t* CAN_slow_channel_id_order_list_build(slow_channel_t* slow_channel,  CAN_id_t* CAN_id_ptr)
{
	uint16_t id = CAN_id_ptr->id, freq = CAN_id_ptr->freq;
	if (id >= ID_LIMITED || freq>= 100 || fast_channel->number_of_id >= 10)
	{
		return 0;
	}

	slow_channel->actived_id[slow_channel->number_of_id] = id;
	slow_channel->number_of_id++;

}