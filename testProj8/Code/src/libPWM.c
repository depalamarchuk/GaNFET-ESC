/************************************************ Library ************************************************/

#include "libPWM.h"

/********************************************* Used functions ********************************************/

void InitPWM (void){
	RCC		-> APB1ENR	|= RCC_APB1ENR_TIM2EN;

	RCC		-> AHBENR	|= RCC_AHBENR_GPIOAEN;

	GPIOA	-> MODER	&= ~GPIO_MODER_MODER1;
	GPIOA	-> MODER	|= GPIO_MODER_MODER1_1;

	GPIOA	-> OTYPER	&= ~GPIO_OTYPER_OT_1;

	GPIOA	-> PUPDR	&= ~GPIO_PUPDR_PUPDR1;

	GPIOA	-> OSPEEDR	&= ~GPIO_OSPEEDER_OSPEEDR1;

	GPIOA	-> AFR[0]	|= (0x01 << (4*1));

	TIM2	-> PSC		= 720-1;
	TIM2	-> ARR		= 100000;
	TIM2	-> CCR2		= 0;

	TIM2	-> CCMR1	&= ~TIM_CCMR1_OC2M;
	TIM2	-> CCMR1	|= (TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2);

	TIM2	-> CCER		|= TIM_CCER_CC2E;
	TIM2	-> CCER		&= ~TIM_CCER_CC2P;

	TIM2	-> CR1		&= ~TIM_CR1_DIR;
	TIM2	-> CR1		|= TIM_CR1_CEN;
}
