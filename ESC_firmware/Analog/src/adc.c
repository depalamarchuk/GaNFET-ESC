/************************************************ Library ************************************************/

#include "ADC.h"

/********************************************* Used functions ********************************************/

void InitADC12 (void){
	uint16_t ticks = 0;														//(1us = 168 ticks @ 168MHz)

	//Pin init

	RCC				-> AHB2ENR 		|= RCC_AHB2ENR_ADC12EN;
	//RCC				-> AHB2ENR		|= RCC_AHB2ENR_GPIOAEN;
	RCC				-> AHB2ENR		|= RCC_AHB2ENR_GPIOBEN;

	//GPIOA			-> MODER		|= GPIO_MODER_MODE0;
	//GPIOA			-> MODER		|= GPIO_MODER_MODE2;
	//GPIOA			-> MODER		|= GPIO_MODER_MODE4;
	//GPIOA			-> MODER		|= GPIO_MODER_MODE6;
	//GPIOB			-> MODER		|= GPIO_MODER_MODE1;
	GPIOB			-> MODER		|= GPIO_MODER_MODE11;
	//GPIOB			-> MODER		|= GPIO_MODER_MODE12;

	//Clock
	RCC				-> CCIPR		|= RCC_CCIPR_ADC12SEL_0; 				//adc_ker_ck is PLLP
	ADC12_COMMON	-> CCR			&= ~ADC_CCR_CKMODE;						//input ADC clock = adc_ker_ck
	ADC12_COMMON	-> CCR			&= ~ADC_CCR_PRESC;						//input ADC clock not divided

	//Calibration
	ADC1			->	CR			&= ~ADC_CR_DEEPPWD;						// Deep power down is enabled on reset
	ADC1			->	CR			|= ADC_CR_ADVREGEN;					// ADC1 voltage regulator enable

	//ADC2			->	CR			&= ~ADC_CR_DEEPPWD;
	//ADC2			->	CR			|= ADC_CR_ADVREGEN;

	while (!(ticks == 1680))
		{
			ticks++;
		}

	ADC1			->	CR			&= ~ADC_CR_ADCALDIF;

	ADC1			->	CR			|= ADC_CR_ADCAL;						//start calibration
	while (ADC1->CR & ADC_CR_ADCAL);										//wait for calibration to be completed

	//ADC2			->	CR			&= ~ADC_CR_ADCALDIF;

	//ADC2			->	CR			|= ADC_CR_ADCAL;						//start calibration
	//while (ADC2->CR & ADC_CR_ADCAL);										//wait for calibration to be completed

	//TIM_CLK/((PSC + 1)*(ARR + 1)
	RCC				->	APB1ENR1	|= RCC_APB1ENR1_TIM6EN;
	TIM6			->	PSC			= 200-1;
	TIM6			->	ARR			= 84;									//Recalculate 1MS per second
	TIM6			->	CR2			|= TIM_CR2_MMS_1;						//Enable generation TRGO for ADC
	TIM6			->	CR1			|= TIM_CR1_CEN;

	ADC1			->	SMPR2		|= 0x7UL << ADC_SMPR2_SMP14_Pos;		//601.5 ADC clock cycles

	//ADC1			->	CFGR		|= ADC_CFGR_DMAEN;
	//ADC1			->	CFGR		&= ~ADC_CFGR_DMACFG;					//0: DMA One Shot mode selected
	//ADC1			->	CFGR		|= ADC_CFGR_JQDIS;						//Injected Queue disabled

	ADC1			->	JSQR		|= 0xEUL << ADC_JSQR_JEXTSEL_Pos;		//adc_jext_trg14
	ADC1			->	JSQR		|= ADC_JSQR_JEXTEN_0;					//01: Hardware trigger detection on the rising edge
	ADC1			->	JSQR		|= 0xEUL << ADC_JSQR_JSQ1_Pos;			//JSQ1 = ADC1_IN14 channel
	ADC1			->	JSQR		&= ~ADC_JSQR_JL;						//1 conversion

	//Interrupt
	//ADC2			->	IER			|= ADC_IER_JEOSIE;
	ADC1			->	IER			|= ADC_IER_JEOSIE;
	NVIC_EnableIRQ(ADC1_2_IRQn);
	NVIC_SetPriority(ADC1_2_IRQn, 5);

	//Enable
	ADC1			->	CR			|= ADC_CR_ADEN;
	while (!(ADC1->ISR & ADC_ISR_ADRDY));

	ADC1			->	CR			|= ADC_CR_JADSTART;
	//ADC2			->	CR			|= ADC_CR_ADEN;
	//while (!(ADC2->ISR & ADC_ISR_ADRDY));
}

/*
uint16_t StartConvADC(void)
{
	ADC1			-> CR			|= ADC_CR_JADSTART;

	while (!(ADC1 -> ISR & ADC_ISR_JEOC));

	return (ADC1 -> JDR1);
}
*/
