/************************************************ Library ************************************************/

#include "libUART.h"

/********************************************* Used functions ********************************************/

void InitUSART (void){

	RCC		-> APB1ENR	|= RCC_APB1ENR_USART2EN;

	RCC		-> AHBENR	|= RCC_AHBENR_GPIOAEN;

	GPIOA	-> MODER	&= ~GPIO_MODER_MODER2;
	GPIOA	-> MODER	|= GPIO_MODER_MODER2_1;

	GPIOA	-> OTYPER	&= ~GPIO_OTYPER_OT_2;

	GPIOA	-> PUPDR	&= ~GPIO_PUPDR_PUPDR2;
	GPIOA	-> PUPDR	|= GPIO_PUPDR_PUPDR2_0;

	GPIOA	-> OSPEEDR	|= GPIO_OSPEEDER_OSPEEDR2;

	GPIOA	-> AFR[0]	|= (0x07 << (4*2));

	GPIOA	-> MODER	&= ~GPIO_MODER_MODER3;
	GPIOA	-> MODER	|= GPIO_MODER_MODER3_1;

	GPIOA	-> PUPDR	&= ~GPIO_PUPDR_PUPDR3;

	GPIOA	-> AFR[0]	|= (0x07 << (4*3));

	USART2	-> BRR		= 0xEA6;

	USART2	-> CR1		|= USART_CR1_TE;
	USART2	-> CR1		|= USART_CR1_RE;
	USART2	-> CR1 		|= USART_CR1_UE;

	USART2	-> CR1		|= USART_CR1_RXNEIE;
	NVIC_EnableIRQ(USART2_IRQn);
}


void SendUSART2 (char chr){
	while(!(USART2->ISR & USART_ISR_TC));
	USART2	->ISR		&= ~USART_ISR_TC;

	USART2	->TDR 		= chr;
}

void SendStringUSART2 (char* str){
	uint8_t i = 0;

	while(str[i])
	SendUSART2 (str[i++]);
}

void SendDataUSART2 (uint8_t data){
	while(!(USART2->ISR & USART_ISR_TC));
	USART2	->ISR		&= ~USART_ISR_TC;

	USART2	->TDR 		= data;
}
