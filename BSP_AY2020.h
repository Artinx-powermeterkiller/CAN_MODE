#ifndef BSP_AY2020_H
#define BSP_AY2020_H

#include "CAN_AY2020.h"

static int Tim_Channel_lag[CHANNEL_NUMBER];

void	BSP_AY2020_timer_init();
void BSP_AY2020_CAN_init();

#endif