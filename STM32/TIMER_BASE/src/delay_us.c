/*
 * delay_us.c
 *
 *  Created on: Jun 14, 2024
 *      Author: user
 */

#include "delay_us.h"

void delay_us(uint32_t us)
{
	__HAL_TIM_SET_COUNTER(&htim2, 0);
	while((__HAL_TIM_GET_COUNTER(&htim2)) < us);
}
