/************************************************ Library ************************************************/

#include "LED.h"

/********************************************* Used functions ********************************************/


void InitLedGPIO (void){

	RCC		-> AHB2ENR	|= RCC_AHB2ENR_GPIOBEN;		// Enable clock port B
	RCC		-> AHB2ENR	|= RCC_AHB2ENR_GPIOCEN;		// Enable clock port C

	//LED1 -- green
	GPIOB	-> MODER	&= ~GPIO_MODER_MODE5;
	GPIOB	-> MODER	|= GPIO_MODER_MODE5_0;		// Setting GPIO for PP output

	//LED2 -- yellow
	GPIOB	-> MODER	&= ~GPIO_MODER_MODE9;
	GPIOB	-> MODER	|= GPIO_MODER_MODE9_0;		// Setting GPIO for PP output

	//LED3 -- white
	GPIOC	-> MODER	&= ~GPIO_MODER_MODE13;
	GPIOC	-> MODER	|= GPIO_MODER_MODE13_0;	// Setting GPIO for PP output

	//LED4 -- blue
	GPIOC	-> MODER	&= ~GPIO_MODER_MODE14;
	GPIOC	-> MODER	|= GPIO_MODER_MODE14_0;	// Setting GPIO for PP output

	//LED2 -- yellow
	GPIOC	-> MODER	&= ~GPIO_MODER_MODE15;
	GPIOC	-> MODER	|= GPIO_MODER_MODE15_0;	// Setting GPIO for PP output
}

//Sets Led state using binary number
void SetLED (LED COLOR, LED STATE)
{
	if ((COLOR == GREEN) && STATE == ON)
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BS5; 		// Enable LED1
	}

	if ((COLOR == GREEN) && STATE == OFF)
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BR5; 		// Disable LED1
	}

	if ((COLOR == YELLOW) && STATE == ON)
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BS9; 		// Enable LED2
	}

	if ((COLOR == YELLOW) && STATE == OFF)
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BR9; 		// Disable LED2
	}

	if ((COLOR == WHITE) && STATE == ON)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BS13; 	// Enable LED3
	}

	if ((COLOR == WHITE) && STATE == OFF)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BR13; 	// Disable LED3
	}

	if ((COLOR == BLUE) && STATE == ON)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BS14; 	// Enable LED4
	}

	if ((COLOR == BLUE) && STATE == OFF)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BR14; 	// Disable LED4
	}

	if ((COLOR == RED) && STATE == ON)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BS15; 	// Enable LED5
	}
	if ((COLOR == RED) && STATE == OFF)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BR15; 	// Disable LED5
	}
}

void ToggleLED (LED COLOR)
{
	if (COLOR == GREEN)
	{
		GPIOB	-> ODR ^= GPIO_ODR_OD5; 					// Toggle LED1
	}
	if (COLOR == YELLOW)
	{
		GPIOB	-> ODR ^= GPIO_ODR_OD9; 					// Toggle LED2
	}
	if (COLOR == WHITE)
	{
		GPIOC	-> ODR ^= GPIO_ODR_OD13; 					// Toggle LED3
	}
	if (COLOR == BLUE)
	{
		GPIOC	-> ODR ^= GPIO_ODR_OD14; 					// Toggle LED4
	}
	if (COLOR == RED)
	{
		GPIOC	-> ODR ^= GPIO_ODR_OD15; 					// Toggle LED5
	}
}

void BlinkLED (LED COLOR, uint16_t period_ms)
{
	ToggleLED(COLOR);
	vTaskDelay(period_ms);
}

