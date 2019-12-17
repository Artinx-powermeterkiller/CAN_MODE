#include "CAN_AY2020_IMU.h"
#include "CAN_AY2020.h"
#include "BSP_AY2020.h"

static CAN_channel_t CAN_channel[CHANNEL_NUMBER];
static channel_schedule_table_t channel_schedule_table[CHANNEL_NUMBER];
void CAN_AY2020_init(void)
{
	CAN_ID_init();
	CAN_Channl_init();

	BSP_AY2020_timer_init();
	BSP_AY2020_init();

}

void CAN_ID_init(void) 
{

}

void CAN_Channl_init(void)
{
	CAN_channel[0].channel_id = 0;
	CAN_channel[0].least_freq = 500;

	CAN_channel[1].channel_id = 1;
	CAN_channel[1].least_freq = 500;

	CAN_channel[2].channel_id = 2;
	CAN_channel[2].least_freq = 100;

	CAN_channel[3].channel_id = 3;
	CAN_channel[3].least_freq = 0;
}
