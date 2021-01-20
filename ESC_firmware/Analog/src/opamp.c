/************************************************ Library ************************************************/

#include "opamp.h"

/********************************************* Used functions ********************************************/

void InitOpamp1 (void){

	uint32_t ticks = 0;													//(1us = 168 ticks @ 168MHz)
	uint8_t trim = 0;

	RCC				-> APB2ENR	|= RCC_APB2ENR_SYSCFGEN;

	RCC				-> AHB2ENR	|= RCC_AHB2ENR_GPIOAEN;
	RCC				-> AHB2ENR	|= RCC_AHB2ENR_GPIOBEN;

/************************************************* Opamp 1 ************************************************/

	GPIOA			-> MODER	|= GPIO_MODER_MODE1;
	GPIOA			-> MODER	|= GPIO_MODER_MODE2;
	GPIOA			-> MODER	|= GPIO_MODER_MODE3;

	OPAMP1			-> CSR		&= ~OPAMP_CSR_VPSEL;					//PA1 = OPAMP1_VINP0
	OPAMP1			-> CSR		|= OPAMP_CSR_VMSEL_1;					//Feedback resistor is connected to OPAMP VINM input (PGA mode)
	OPAMP1			-> CSR		&= ~OPAMP_CSR_OPAMPINTEN;				//PA2 = OPAMP1_VOUT = ADC1_IN3

	OPAMP1			-> CSR		|= OPAMP_CSR_CALON;

	OPAMP1			-> CSR		|= OPAMP_CSR_OPAMPxEN;
	OPAMP1			-> CSR		|= OPAMP_CSR_USERTRIM;

	OPAMP1			-> CSR		&= ~OPAMP_CSR_HIGHSPEEDEN;				//Normal operating mode
	OPAMP1			-> CSR		|= 0x3UL << OPAMP_CSR_CALSEL_Pos;		//0.9*VDDA applied on OPAMP inputs (for NMOS calibration)

	do
	{
		OPAMP1		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETN_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP1 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP1			-> CSR		&= ~OPAMP_CSR_HIGHSPEEDEN;				//Normal operating mode
	OPAMP1			-> CSR		|= 0x1UL << OPAMP_CSR_CALSEL_Pos;		//0.1*VDDA applied on OPAMP inputs (for PMOS calibration)

	do
	{
		OPAMP1		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETP_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP1 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP1			-> CSR		|= OPAMP_CSR_HIGHSPEEDEN;				//Operational amplifier in high-speed mode
	OPAMP1			-> CSR		|= 0x3UL << OPAMP_CSR_CALSEL_Pos;		//0.9*VDDA applied on OPAMP inputs (for NMOS calibration)

	do
	{
		OPAMP1		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETN_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP1 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP1			-> CSR		|= OPAMP_CSR_HIGHSPEEDEN;				//Operational amplifier in high-speed mode
	OPAMP1			-> CSR		|= 0x1UL << OPAMP_CSR_CALSEL_Pos;		//0.1*VDDA applied on OPAMP inputs (for PMOS calibration)

	do
	{
		OPAMP1		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETP_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP1 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP1			-> CSR		&= ~OPAMP_CSR_CALON;

	OPAMP1			-> CSR		|= OPAMP_CSR_HIGHSPEEDEN;
	OPAMP1			-> CSR		&= ~OPAMP_CSR_PGGAIN;
	OPAMP1			-> CSR		|= 0b00010UL << OPAMP_CSR_PGGAIN_Pos;	//Non inverting internal gain =8
}

void InitOpamp2 (void){

	uint32_t ticks = 0;													//(1us = 168 ticks @ 168MHz)
	uint8_t trim = 0;

	RCC				-> APB2ENR	|= RCC_APB2ENR_SYSCFGEN;

	RCC				-> AHB2ENR	|= RCC_AHB2ENR_GPIOAEN;
	RCC				-> AHB2ENR	|= RCC_AHB2ENR_GPIOBEN;

/************************************************* Opamp 1 ************************************************/

	GPIOA			-> MODER	|= GPIO_MODER_MODE5;
	GPIOA			-> MODER	|= GPIO_MODER_MODE6;
	GPIOA			-> MODER	|= GPIO_MODER_MODE7;

	OPAMP2			-> CSR		&= ~OPAMP_CSR_VPSEL;					//PA5 = OPAMP2_VINP0
	OPAMP2			-> CSR		|= OPAMP_CSR_VMSEL_1;					//Feedback resistor is connected to OPAMP VINM input (PGA mode)
	OPAMP2			-> CSR		&= ~OPAMP_CSR_OPAMPINTEN;				//PA6 = OPAMP2_VOUT = ADC2_IN3

	OPAMP2			-> CSR		|= OPAMP_CSR_CALON;

	OPAMP2			-> CSR		|= OPAMP_CSR_OPAMPxEN;
	OPAMP2			-> CSR		|= OPAMP_CSR_USERTRIM;

	OPAMP2			-> CSR		&= ~OPAMP_CSR_HIGHSPEEDEN;				//Normal operating mode
	OPAMP2			-> CSR		|= 0x3UL << OPAMP_CSR_CALSEL_Pos;		//0.9*VDDA applied on OPAMP inputs (for NMOS calibration)


	do
	{
		OPAMP2		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETN_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP2 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP2			-> CSR		&= ~OPAMP_CSR_HIGHSPEEDEN;				//Normal operating mode
	OPAMP2			-> CSR		|= 0x1UL << OPAMP_CSR_CALSEL_Pos;		//0.1*VDDA applied on OPAMP inputs (for PMOS calibration)

	do
	{
		OPAMP2		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETP_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP2 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP2			-> CSR		|= OPAMP_CSR_HIGHSPEEDEN;				//Operational amplifier in high-speed mode
	OPAMP2			-> CSR		|= 0x3UL << OPAMP_CSR_CALSEL_Pos;		//0.9*VDDA applied on OPAMP inputs (for NMOS calibration)

	do
	{
		OPAMP2		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETN_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP2 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP2			-> CSR		|= OPAMP_CSR_HIGHSPEEDEN;				//Operational amplifier in high-speed mode
	OPAMP2			-> CSR		|= 0x1UL << OPAMP_CSR_CALSEL_Pos;		//0.1*VDDA applied on OPAMP inputs (for PMOS calibration)

	do
	{
		OPAMP2		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETP_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP2 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP2			-> CSR		&= ~OPAMP_CSR_CALON;

	OPAMP2			-> CSR		|= OPAMP_CSR_HIGHSPEEDEN;
	OPAMP2			-> CSR		&= ~OPAMP_CSR_PGGAIN;
	OPAMP2			-> CSR		|= 0b00010UL << OPAMP_CSR_PGGAIN_Pos;	//Non inverting internal gain =8
}

void InitOpamp3 (void){

	uint32_t ticks = 0;													//(1us = 168 ticks @ 168MHz)
	uint8_t trim = 0;

	RCC				-> APB2ENR	|= RCC_APB2ENR_SYSCFGEN;

	RCC				-> AHB2ENR	|= RCC_AHB2ENR_GPIOAEN;
	RCC				-> AHB2ENR	|= RCC_AHB2ENR_GPIOBEN;

	GPIOB			-> MODER	|= GPIO_MODER_MODE0;
	GPIOB			-> MODER	|= GPIO_MODER_MODE1;
	GPIOB			-> MODER	|= GPIO_MODER_MODE2;

	OPAMP3			-> CSR		&= ~OPAMP_CSR_VPSEL;					//PB0 = OPAMP3_VINP0
	OPAMP3			-> CSR		|= OPAMP_CSR_VMSEL_1;					//Feedback resistor is connected to OPAMP VINM input (PGA mode)
	OPAMP3			-> CSR		&= ~OPAMP_CSR_OPAMPINTEN;				//PB1 = OPAMP3_VOUT = ADC1_IN12

	OPAMP3			-> CSR		|= OPAMP_CSR_CALON;

	OPAMP3			-> CSR		|= OPAMP_CSR_OPAMPxEN;
	OPAMP3			-> CSR		|= OPAMP_CSR_USERTRIM;

	OPAMP3			-> CSR		&= ~OPAMP_CSR_HIGHSPEEDEN;				//Normal operating mode
	OPAMP3			-> CSR		|= 0x3UL << OPAMP_CSR_CALSEL_Pos;		//0.9*VDDA applied on OPAMP inputs (for NMOS calibration)

	do
	{
		OPAMP3		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETN_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP3 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP3			-> CSR		&= ~OPAMP_CSR_HIGHSPEEDEN;				//Normal operating mode
	OPAMP3			-> CSR		|= 0x1UL << OPAMP_CSR_CALSEL_Pos;		//0.1*VDDA applied on OPAMP inputs (for PMOS calibration)

	do
	{
		OPAMP3		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETP_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP3 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP3			-> CSR		|= OPAMP_CSR_HIGHSPEEDEN;				//Operational amplifier in high-speed mode
	OPAMP3			-> CSR		|= 0x3UL << OPAMP_CSR_CALSEL_Pos;		//0.9*VDDA applied on OPAMP inputs (for NMOS calibration)

	do
	{
		OPAMP3		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETN_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP3 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP3			-> CSR		|= OPAMP_CSR_HIGHSPEEDEN;				//Operational amplifier in high-speed mode
	OPAMP3			-> CSR		|= 0x1UL << OPAMP_CSR_CALSEL_Pos;		//0.1*VDDA applied on OPAMP inputs (for PMOS calibration)

	do
	{
		OPAMP3		-> CSR		|= (trim << OPAMP_CSR_TRIMOFFSETP_Pos);

		while (!(ticks == 168000))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while((OPAMP3 -> CSR & OPAMP_CSR_OUTCAL)!=0);

	ticks = 0;
	trim = 0;

	OPAMP3			-> CSR		&= ~OPAMP_CSR_CALON;

	OPAMP3			-> CSR		|= OPAMP_CSR_HIGHSPEEDEN;
	OPAMP3			-> CSR		&= ~OPAMP_CSR_PGGAIN;
	OPAMP3			-> CSR		|= 0b00010UL << OPAMP_CSR_PGGAIN_Pos;	//Non inverting internal gain =8
}
