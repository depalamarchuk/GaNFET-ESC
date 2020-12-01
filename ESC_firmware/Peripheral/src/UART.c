/************************************************ Library ************************************************/

#include "UART.h"

/********************************************* Used functions ********************************************/

void InitUSART1 (void){

	RCC		-> APB2ENR	|= RCC_APB2ENR_USART1EN;

	RCC		-> AHB2ENR	|= RCC_AHB2ENR_GPIOBEN;

	//TX
	GPIOB	-> MODER	&= ~GPIO_MODER_MODE6;
	GPIOB	-> MODER	|= GPIO_MODER_MODE6_1;

	GPIOB	-> OTYPER	&= ~GPIO_OTYPER_OT_6;

	GPIOB	-> PUPDR	&= ~GPIO_PUPDR_PUPD6;
	GPIOB	-> PUPDR	|= GPIO_PUPDR_PUPD9_0;

	GPIOB	-> OSPEEDR	|= GPIO_OSPEEDR_OSPEED8;

	GPIOB	-> AFR[0]	|= 0x07 << (4*6);

	//RX
	GPIOB	-> MODER	&= ~GPIO_MODER_MODE7;
	GPIOB	-> MODER	|= GPIO_MODER_MODE7_1;

	GPIOB	-> PUPDR	&= ~GPIO_PUPDR_PUPD7;

	GPIOB	-> AFR[0]	|= 0x07 << (4*7);

	//baudrate = 9600
	USART1	-> BRR		= 0x445C; //BRR = (fck + baudrate /2 ) / baudrate

	USART1	-> CR1		|= USART_CR1_TE;
	USART1	-> CR1		|= USART_CR1_RE;
	USART1	-> CR1 		|= USART_CR1_UE;

	USART1	-> CR1		|= USART_CR1_RXNEIE;
	NVIC_EnableIRQ(USART1_IRQn);
}


void SendUSART1 (char chr){
	while(!(USART1->ISR & USART_ISR_TC));
	USART1	->ISR		&= ~USART_ISR_TC;

	USART1	->TDR 		= chr;
}

void SendStringUSART1 (char* str){
	uint8_t i = 0;

	while(str[i])
	{
		SendUSART1 (str[i++]);
	}
}

void SendDataUSART1 (uint8_t data){
	while(!(USART1->ISR & USART_ISR_TC));
	USART1	->ISR		&= ~USART_ISR_TC;

	USART1	->TDR 		= data;
}

void USART1_IRQHandler (void){
	if (USART1->ISR & USART_CR1_RXNEIE)
	{
		USART1	-> ISR &= ~USART_CR1_RXNEIE;
	}
}

