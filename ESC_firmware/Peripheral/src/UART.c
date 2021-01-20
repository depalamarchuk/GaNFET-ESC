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

void InitDMAusart1 (void)
{
	char init[]			= "DMA1 init";

	RCC					-> AHB1ENR	|= RCC_AHB1ENR_DMA1EN;
	RCC					-> AHB1ENR	|= RCC_AHB1ENR_DMAMUX1EN;

	DMA1_Channel7		-> CCR		&= ~DMA_CCR_EN;

	DMAMUX1_Channel6	-> CCR		&= ~DMAMUX_CxCR_DMAREQ_ID;
	DMAMUX1_Channel6	-> CCR		|= 0x19UL << DMAMUX_CxCR_DMAREQ_ID_Pos; // USART1_TX

	DMA1_Channel7		-> CPAR		= (uint32_t)&USART1->TDR;
	DMA1_Channel7		-> CMAR		= (uint32_t)&init;
	DMA1_Channel7		-> CNDTR	= sizeof(init)-1;						// Size of buffer

	DMA1_Channel7		-> CCR		&= ~DMA_CCR_CIRC;						// Disable cycle mode
	DMA1_Channel7		-> CCR		&= ~DMA_CCR_PINC;						// Disable increment pointer peripheral

	DMA1_Channel7		-> CCR		&= ~DMA_CCR_PSIZE;						// Size of data peripheral = 8 bit
	DMA1_Channel7		-> CCR		&= ~DMA_CCR_MSIZE;						// Size of data memory = 8 bit

	DMA1_Channel7		-> CCR		|= DMA_CCR_DIR;							// Read: memory -> peripheral
	DMA1_Channel7		-> CCR		|= DMA_CCR_MINC;						// Memory increment mode enabled
	DMA1_Channel7		-> CCR		&= ~DMA_CCR_PINC;

	DMA1				-> IFCR		|= DMA_IFCR_CGIF7;
	NVIC_EnableIRQ(DMA1_Channel7_IRQn);
	DMA1_Channel7		-> CCR		|= DMA_CCR_TCIE;						// Transfer complete interrupt enable

	USART1				-> CR3		|= USART_CR3_DMAT;						// Enable DMA for USART1
}

void WriteStrDMAusart1 (char *str)
{
	while(!(USART1->ISR & USART_ISR_TC));

	DMA1_Channel7		-> CCR		&= ~DMA_CCR_EN;

	DMA1_Channel7		-> CMAR		= (uint32_t)str;
	DMA1_Channel7		-> CNDTR	= strlen(str);

	DMA1_Channel7		-> CCR		|= DMA_CCR_EN;

	USART1				-> ISR		&= ~USART_ISR_TC;
}

void WriteDataDMAusart1 (uint8_t *data, uint16_t len)
{
	while(!(USART1->ISR & USART_ISR_TC));

	DMA1_Channel7		-> CCR		&= ~DMA_CCR_EN;

	DMA1_Channel7		-> CMAR		= (uint32_t)data;
	DMA1_Channel7		-> CNDTR	= len;

	DMA1_Channel7		-> CCR		|= DMA_CCR_EN;

	USART1				-> ISR		&= ~USART_ISR_TC;
}

void USART1_IRQHandler (void)
{
	if (USART1->ISR & USART_CR1_RXNEIE)
	{
		USART1	-> ISR &= ~USART_CR1_RXNEIE;
	}
}

void DMA1_CH7_IRQHandler(void)
{
	DMA1				-> IFCR		|= DMA_IFCR_CGIF7;
}
