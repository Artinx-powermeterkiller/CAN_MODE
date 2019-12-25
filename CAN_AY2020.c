#include "CAN_AY2020_IMU.h"
#include "CAN_AY2020.h"
#include <stdlib.h>

static uint8_t* public_channel_occupy_list[2];

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
	if (channel != 0 && channel != 1)
	{
		CAN_id_ptr->id_order_list_ptr = calloc(freq + 1, sizeof(uint16_t));
	}
	else
	{

	}
}