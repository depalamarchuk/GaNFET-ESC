/************************************************ Library ************************************************/

#include "sysinit.h"

/********************************************* Used functions ********************************************/

void InitRCC (void){

	RCC		->CR			|= ((uint32_t)RCC_CR_HSEON); 					// Enable HSE
	while (!(RCC->CR & RCC_CR_HSERDY));									// Ready start HSE

	FLASH	-> ACR			|= FLASH_ACR_PRFTEN;
	FLASH	-> ACR			|= FLASH_ACR_LATENCY_4WS;						// Clock Flash memory

	RCC		-> CFGR			|= RCC_CFGR_HPRE_DIV1;							// AHB = SYSCLK/1
	RCC		-> CFGR			|= RCC_CFGR_PPRE1_DIV1;							// APB1 = HCLK/2
	RCC		-> CFGR			|= RCC_CFGR_PPRE2_DIV1;							// APB2 = HCLK/1

	RCC		-> PLLCFGR		&= ~RCC_PLLCFGR_PLLQEN;							// clear PLLQEN bits
	RCC		-> PLLCFGR		&= ~RCC_PLLCFGR_PLLQ;								// clear PLLQ bits
	RCC		-> PLLCFGR		&= ~RCC_PLLCFGR_PLLREN;							// clear PLLREN bits
	RCC		-> PLLCFGR		&= ~RCC_PLLCFGR_PLLR;								// clear PLLR bits
	RCC		-> PLLCFGR		&= ~RCC_PLLCFGR_PLLN;								// clear PLLN bits
	RCC		-> PLLCFGR		&= ~RCC_PLLCFGR_PLLM_0;							// clear PLLM bits
	RCC		-> PLLCFGR		&= ~RCC_PLLCFGR_PLLSRC;               				// clear PLLSRC bits

	/*
	 * Reliable clock algorithm will be implemented later
	RCC		-> CR			|= RCC_CR_CSSON;
	RCC		-> CR			|= RCC_CR_HSEBYP;
	RCC		-> CR			|= RCC_CR_HSEON;
	while((RCC->CR & RCC_CR_HSERDY) == 0) {}
	*/

	RCC		-> PLLCFGR		|= RCC_PLLCFGR_PLLSRC_HSE; 					// source HSE = 8MHz
	RCC		-> PLLCFGR		&= ~RCC_PLLCFGR_PLLM_0; 					// PLLM = HSE/1 = 8 MHz
	RCC		-> PLLCFGR		|= 0x29UL << RCC_PLLCFGR_PLLN_Pos; 			// PLLN = PLLM*42 = 336 MHz
	RCC		-> PLLCFGR		&= RCC_PLLCFGR_PLLR; 						// PLLR = PLLN/2 = 168 MHz
	RCC		-> PLLCFGR		&= RCC_PLLCFGR_PLLREN;
	RCC		-> PLLCFGR		&= RCC_PLLCFGR_PLLQ; 						// PLLQ = PLLN/2 = 168 MHz (can be used for FD CAN)
	RCC		-> PLLCFGR		&= RCC_PLLCFGR_PLLQEN;
	//PLLP is not used.

	RCC		-> CR			|= RCC_CR_PLLON;                      		// enable PLL
	while((RCC->CR & RCC_CR_PLLRDY) == 0) {}     						// wait till PLL is ready

	RCC		-> CFGR			&= ~RCC_CFGR_SW;                   			// clear SW bits
	RCC		-> CFGR			|= RCC_CFGR_SW_PLL;               			// select source SYSCLK = PLL
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {} 				// wait till PLL is used

}
