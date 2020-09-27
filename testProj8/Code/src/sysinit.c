/************************************************ Library ************************************************/

#include "sysinit.h"

/********************************************* Used functions ********************************************/

void InitRCC (void){

	RCC		->CR		|= ((uint32_t)RCC_CR_HSEON); 					// Enable HSE
	while (!(RCC->CR & RCC_CR_HSERDY));									// Ready start HSE

	FLASH	-> ACR		|= FLASH_ACR_PRFTBE;
	FLASH	-> ACR		|= FLASH_ACR_LATENCY_2;							// Clock Flash memory

	RCC		-> CFGR		|= RCC_CFGR_HPRE_DIV1;							// AHB = SYSCLK/1
	RCC		-> CFGR		|= RCC_CFGR_PPRE1_DIV2;							// APB1 = HCLK/2
	RCC		-> CFGR		|= RCC_CFGR_PPRE2_DIV1;							// APB2 = HCLK/1

	RCC		-> CFGR		&= ~RCC_CFGR_PLLMUL;               				// clear PLLMUL bits
	RCC		-> CFGR		&= ~RCC_CFGR_PLLXTPRE;							// clear PLLXTPRE bits
	RCC		-> CFGR		&= ~RCC_CFGR_PLLSRC;							// clear PLLSRC bits

	RCC		-> CFGR		|= RCC_CFGR_PLLSRC_HSE_PREDIV; 					// source HSE
	RCC		-> CFGR		|= RCC_CFGR_PLLXTPRE_HSE_PREDIV_DIV1; 			// source HSE/1 = 8 MHz
	RCC		-> CFGR		|= RCC_CFGR_PLLMUL9; 							// PLL x9: clock = 8 MHz * 9 = 72 MHz

	RCC		-> CR		|= RCC_CR_PLLON;                      			// enable PLL
	while((RCC->CR & RCC_CR_PLLRDY) == 0) {}     						// wait till PLL is ready

	RCC		-> CFGR		|= RCC_CFGR_PPRE2_DIV2;
	RCC		-> CFGR		|= RCC_CFGR_PPRE1_DIV1;
	RCC		-> CFGR		|= RCC_CFGR_HPRE_DIV1;

	RCC		-> CFGR		&= ~RCC_CFGR_SW;                   				// clear SW bits
	RCC		-> CFGR		|= RCC_CFGR_SW_PLL;               				// select source SYSCLK = PLL
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {} 				// wait till PLL is used

}

void GenMCO (void){

	RCC		-> AHBENR	|= RCC_AHBENR_GPIOAEN;                       	// enable clock for port A

	GPIOA	-> MODER	&= ~GPIO_MODER_MODER8;							// setting out alternative push-pull for PA8
	GPIOA	-> MODER	|= GPIO_MODER_MODER8_0;
	GPIOA	-> OSPEEDR	|= ( GPIO_OSPEEDER_OSPEEDR8_0 | GPIO_OSPEEDER_OSPEEDR8_1);		// gpio speed 50 MHz

	RCC		-> CFGR |= RCC_CFGR_MCO_SYSCLK;								// select source clokc SYSCLK

}

void InitGPIO (void){
/*Enable LD2 on pin PB13*/

	RCC		-> AHBENR	|= RCC_AHBENR_GPIOBEN;							// Enable clock port B
	RCC		-> AHBENR	|= RCC_AHBENR_GPIOCEN;							// Enable clock port C

	GPIOB	-> MODER	&= ~GPIO_MODER_MODER13;
	GPIOB	-> MODER	|= GPIO_MODER_MODER13_0;						// Setting GPIO for PP output

	GPIOB	-> MODER	&= ~GPIO_MODER_MODER0;
	GPIOB	-> MODER	|= GPIO_MODER_MODER0_0;							// Setting GPIO for PP output

	GPIOC	-> MODER	&= ~GPIO_MODER_MODER13;							// Setting GPIO for floating input
}
