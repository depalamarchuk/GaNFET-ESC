/************************************************ Library ************************************************/

#include "ADC.h"

/********************************************* Used functions ********************************************/

void InitADC (void){
	uint16_t ticks = 0;									//(1us = 168 ticks @ 168MHz)

	// Internal voltage reference
	RCC				-> APB2ENR	|= RCC_APB2ENR_SYSCFGEN;

	VREFBUF			-> CSR		|= VREFBUF_CSR_VRS_0;	//VREFBUF = 2.5V
	while (VREFBUF->CSR & VREFBUF_CSR_VRR);
	VREFBUF			-> CSR		|= VREFBUF_CSR_ENVR;
	VREFBUF			-> CSR		&= ~VREFBUF_CSR_HIZ;

	//Pin init

	RCC				-> AHB2ENR 	|= RCC_AHB2ENR_ADC12EN;
	RCC				-> AHB2ENR	|= RCC_AHB2ENR_GPIOAEN;
	RCC				-> AHB2ENR	|= RCC_AHB2ENR_GPIOBEN;

	//GPIOA			-> MODER	|= GPIO_MODER_MODE0;
	GPIOB			-> MODER	|= GPIO_MODER_MODE11;

	RCC				-> CCIPR	|= RCC_CCIPR_ADC12SEL_0; 				//adc_ker_ck is PLLP
	ADC12_COMMON	-> CCR		&= ~ADC_CCR_CKMODE;						//input ADC clock = adc_ker_ck
	ADC12_COMMON	-> CCR		&= ~ADC_CCR_PRESC;						//input ADC clock not divided

	//ADC12_COMMON	-> CCR		|= ADC_CCR_VREFEN;

	//Calibration

	ADC1			->	CR		&= ~ADC_CR_DEEPPWD;						// Deep power down is turned on
	ADC1			->	CR		|= ADC_CR_ADVREGEN;						// ADC1 voltage regulator enable

	while (!(ticks = 1680))
		{
			ticks++;
		}

	ADC1			->	CR		&= ~ADC_CR_ADCALDIF;

	ADC1			->	CR		|= ADC_CR_ADCAL;						//start calibration
	while (ADC1->CR & ADC_CR_ADCAL);									//wait for calibration to be completed

	//Trigger

	ADC1			->	CFGR	&= ~ADC_CFGR_EXTEN;
	ADC1			->	CFGR	&= ~ADC_CFGR_CONT;						//0 -- single conversion, 1 -- continuous conversion
	ADC1			->	SMPR2	|= 0x7UL << ADC_SMPR2_SMP14_Pos;		//601.5 ADC clock cycles
	ADC1			->	SQR1	&= ~ADC_SQR1_SQ1;
	ADC1			->	SQR1	|= 0xEUL << ADC_SQR1_SQ1_Pos;			//ADC1_IN14 channel select
	ADC1			->	SQR1	&= ~ADC_SQR1_L;							//Length of regular ADC channel = 1

	//enable

	ADC1			->	CR		|= ADC_CR_ADEN;

	while (!(ADC1->ISR & ADC_ISR_ADRDY));
}

uint16_t StartConvADC(void)
{
	ADC1			-> CR		|= ADC_CR_ADSTART;

	while (!(ADC1 -> ISR & ADC_ISR_EOC));

	return (ADC1 -> DR);
}
