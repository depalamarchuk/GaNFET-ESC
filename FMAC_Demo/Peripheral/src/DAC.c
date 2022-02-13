/************************************************ Library ************************************************/

#include "DAC.h"

/************************************************ Used functions ************************************************/

void InitDAC2 (uint32_t mcu_freq)
{
	float cal_delay = 50E-5/(1/((float)mcu_freq));
	uint32_t ticks = 0;
	uint16_t trim = 0;

	RCC 	-> AHB2ENR	|= RCC_AHB2ENR_DAC2EN;
	RCC		-> AHB2ENR	|= RCC_AHB2ENR_GPIOAEN;

	DAC2	-> MCR		&= ~DAC_CR_HFSEL;
	DAC2	-> MCR		|= (0x3UL << DAC_CR_HFSEL_Pos); //High frequency interface mode compatible to AHB>160 MHz enabled

	//normally pin setting is not required
	GPIOA	-> MODER	&= ~GPIO_MODER_MODE6;
	GPIOA	-> MODER	|= (0x3UL << GPIO_MODER_MODE6_Pos);

	DAC2	-> MCR		|= 	DAC_MCR_SINFORMAT1;

	DAC2	-> CR		|= DAC_CR_CEN1;

	do
	{
		DAC2		-> CCR		&= ~DAC_CCR_OTRIM1;
		DAC2		-> CCR		|= (trim << DAC_CCR_OTRIM1_Pos);

		while (ticks < ((uint32_t)cal_delay))
		{
			ticks++;
		}

		ticks = 0;
		trim++;
	} while(!(DAC2->SR & DAC_SR_CAL_FLAG1));

	DAC2	-> CR		&= ~DAC_CR_CEN1;

	DAC2	-> CR		|= DAC_CR_EN1;

	while (!(DAC2->SR & DAC_SR_DAC1RDY));

}

void WriteDAC2 (int16_t data)
{
	if (data < 4096)
	{
		DAC2 -> DHR12R1 = data;
	}
}

void InitDmaDac2 (void)
{
	uint32_t init		= 2048;

	RCC					-> AHB1ENR	|= RCC_AHB1ENR_DMA1EN;
	RCC					-> AHB1ENR	|= RCC_AHB1ENR_DMAMUX1EN;

	DMA1_Channel2		-> CCR		&= ~DMA_CCR_EN;

	DMAMUX1_Channel1	-> CCR		&= ~DMAMUX_CxCR_DMAREQ_ID;
	DMAMUX1_Channel1	-> CCR		|= 41 << DMAMUX_CxCR_DMAREQ_ID_Pos;		// DAC2_CH1

	DMA1_Channel2		-> CPAR		= (uint32_t)&(DAC2 -> DHR12R1);
	DMA1_Channel2		-> CMAR		= (uint32_t)&init;
	DMA1_Channel2		-> CNDTR	= 1;									// Size of buffer

	DMA1_Channel2		-> CCR		&= ~DMA_CCR_CIRC;						// Disable cycle mode
	DMA1_Channel2		-> CCR		&= ~DMA_CCR_PINC;						// Disable increment pointer peripheral

	DMA1_Channel2		-> CCR		|= (0x1UL << DMA_CCR_PSIZE_Pos);		// Size of data peripheral = 16 bit
	DMA1_Channel2		-> CCR		|= (0x2UL << DMA_CCR_MSIZE_Pos);		// Size of data memory = 16 bit

	DMA1_Channel2		-> CCR		|= DMA_CCR_DIR;							// Read: memory -> peripheral
	DMA1_Channel2		-> CCR		|= DMA_CCR_MINC;						// Memory increment mode enabled
	DMA1_Channel2		-> CCR		&= ~DMA_CCR_PINC;

	DMA1				-> IFCR		|= DMA_IFCR_CGIF2;
	NVIC_EnableIRQ(DMA1_Channel2_IRQn);
	DMA1_Channel2		-> CCR		|= DMA_CCR_TCIE;						// Transfer complete interrupt enable

	DAC2				-> CR		|= DAC_CR_DMAEN1;						// Enable DMA for DAC2
}

void WriteDataDmaDac2 (int16_t *data)
{
	DMA1_Channel2		-> CCR		&= ~DMA_CCR_EN;

	DMA1_Channel2		-> CMAR		= (uint32_t)data;
	DMA1_Channel2		-> CNDTR	= 1;

	DMA1_Channel2		-> CCR		|= DMA_CCR_EN;
}

