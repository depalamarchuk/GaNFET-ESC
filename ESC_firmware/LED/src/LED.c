/************************************************ Library ************************************************/

#include "LED.h"

/********************************************* Used functions ********************************************/


void InitLedGPIO (void){

	RCC		-> AHB2ENR	|= RCC_AHB2ENR_GPIOBEN;		// Enable clock port B
	RCC		-> AHB2ENR	|= RCC_AHB2ENR_GPIOCEN;		// Enable clock port C

	//LED1 -- green
	GPIOB	-> MODER	&= ~GPIO_MODER_MODER5;
	GPIOB	-> MODER	|= GPIO_MODER_MODER5_0;		// Setting GPIO for PP output

	//LED2 -- yellow
	GPIOB	-> MODER	&= ~GPIO_MODER_MODER9;
	GPIOB	-> MODER	|= GPIO_MODER_MODER9_0;		// Setting GPIO for PP output

	//LED3 -- white
	GPIOC	-> MODER	&= ~GPIO_MODER_MODER13;
	GPIOC	-> MODER	|= GPIO_MODER_MODER13_0;	// Setting GPIO for PP output

	//LED4 -- blue
	GPIOC	-> MODER	&= ~GPIO_MODER_MODER14;
	GPIOC	-> MODER	|= GPIO_MODER_MODER14_0;	// Setting GPIO for PP output

	//LED2 -- yellow
	GPIOC	-> MODER	&= ~GPIO_MODER_MODER15;
	GPIOC	-> MODER	|= GPIO_MODER_MODER15_0;	// Setting GPIO for PP output
}

//Sets Led state using binary number
void SetLED (uint8_t COLOR)
{
	if (COLOR & LED_GREEN)
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BS_5; 		// Enable LED1
	}
	else
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BR_5; 		// Disable LED1
	}

	if (COLOR & LED_YELLOW)
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BS_9; 		// Enable LED2
	}
	else
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BR_9; 		// Disable LED2
	}

	if (COLOR & LED_WHITE)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BS_13; 	// Enable LED3
	}
	else
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BR_13; 	// Disable LED3
	}

	if (COLOR & LED_BLUE)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BS_14; 	// Enable LED4
	}
	else
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BR_14; 	// Disable LED4
	}

	if (COLOR & LED_RED)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BS_15; 	// Enable LED5
	}
	else
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BR_15; 	// Disable LED5
	}

	if (COLOR & LED_UNDEF1 & LED_UNDEF2 & LED_UNDEF3)
	{
		//Do workaround later, presumably it will be UART warning
	}
}

void TurnOnLED (uint8_t COLOR)
{
	if (COLOR & LED_GREEN)
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BS_5; 		// Enable LED1
	}

	if (COLOR & LED_YELLOW)
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BS_9; 		// Enable LED2
	}

	if (COLOR & LED_WHITE)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BS_13; 	// Enable LED3
	}

	if (COLOR & LED_BLUE)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BS_14; 	// Enable LED4
	}

	if (COLOR & LED_RED)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BS_15; 	// Enable LED5
	}

	if (COLOR & LED_UNDEF1 & LED_UNDEF2 & LED_UNDEF3)
	{
		//Do workaround later, presumably it will be UART warning
	}
}

void TurnOffLED (uint8_t COLOR)
{
	if (COLOR & LED_GREEN)
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BR_5; 		// Disable LED1
	}

	if (COLOR & LED_YELLOW)
	{
		GPIOB	-> BSRR		|= GPIO_BSRR_BR_9; 		// Disable LED2
	}

	if (COLOR & LED_WHITE)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BR_13; 	// Disable LED3
	}

	if (COLOR & LED_BLUE)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BR_14; 	// Disable LED4
	}

	if (COLOR & LED_RED)
	{
		GPIOC	-> BSRR		|= GPIO_BSRR_BR_15; 	// Disable LED5
	}

	if (COLOR & LED_UNDEF1 & LED_UNDEF2 & LED_UNDEF3)
	{
		//Do workaround later, presumably it will be UART warning
	}
}

void BlinkLED (uint8_t COLOR, uint8_t period)
{
//implement delay normally later
	SetLED(COLOR);
	delay(period/2);
	SetLED(0);
	delay(period/2);
}

void ToggleLED ()
{
	GPIOB	-> ODR ^= GPIO_ODR_OD5; 					// Toggle LED1
	GPIOB	-> ODR ^= GPIO_ODR_OD9; 					// Toggle LED2
	GPIOC	-> ODR ^= GPIO_ODR_OD13; 					// Toggle LED3
	GPIOC	-> ODR ^= GPIO_ODR_OD14; 					// Toggle LED4
	GPIOC	-> ODR ^= GPIO_ODR_OD15; 					// Toggle LED5
}


//In this function we assume that 8-bit value is actually 5-bit value
//since 3 least significant bits are not defined as LEDS
void ShiftLEDLeft (uint8_t *COLOR)
{
	uint8_t TEMP_COLOR = *COLOR;
	uint8_t fifth_led_mask = 0b00100000;
	uint8_t fifth_led_masked;

	TEMP_COLOR << 1;

	fifth_led_masked = TEMP_COLOR & fifth_led_mask;
	TEMP_COLOR = TEMP_COLOR | (fifth_led_masked >> 6);

	COLOR = &TEMP_COLOR;
}
