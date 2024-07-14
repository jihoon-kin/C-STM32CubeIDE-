/*
 * led.c
 *
 *  Created on: Jun 17, 2024
 *      Author: user
 */

#include "led.h"


void updateLED(LED_CONTROL *led)
{
	uint32_t currTick = millis(); // HAL_GetTick() == millis()

	if(currTick - led->lastTick >= led->interval)
	{
		// Let's change LED state
		if(led->state == LED_OFF)
		{
			// LED ON
			HAL_GPIO_WritePin(led->GPIOx, led->GPIO_Pin, 1);
			led->state = LED_ON;
			led->lastTick = currTick;
		}
		else
		{
			// LED OFF
			HAL_GPIO_WritePin(led->GPIOx, led->GPIO_Pin, GPIO_PIN_RESET);
			led->state = LED_OFF;
			led->lastTick = currTick;
		}
	}
}
