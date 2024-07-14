/*
 * led.h
 *
 *  Created on: Jun 17, 2024
 *      Author: user
 */

#ifndef HW_LED_H_
#define HW_LED_H_

#include "hw.h"

// LED state define dufrjgud
typedef enum{
	LED_OFF, // 0
	LED_ON   // 1
}LED_STATE;

// struct for LED control
typedef struct{
	GPIO_TypeDef *GPIOx; // LED connect GPIO port
	uint16_t 	 GPIO_Pin; // LED connect PIN number
	uint32_t	 interval; // LED toggle time(delay function is 32 bit)
	LED_STATE	 state; // LED's current state
	uint32_t	 lastTick; // Let's save last changed time on LED
}LED_CONTROL;

// save LED state
void updateLED(LED_CONTROL *led);

#endif /* HW_LED_H_ */
