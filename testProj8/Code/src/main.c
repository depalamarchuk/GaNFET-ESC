/************************************************ Library ************************************************/

#include "main.h"

/************************************************** Main *************************************************/

int main(void)
{

	InitRCC();
	InitGPIO();
	InitUSART();
	InitPWM();

	while(1)
	{

	}

}


static uint16_t CalculateOCReg(uint8_t throttle)
{
	uint16_t OCReg;

	OCReg = throttle*10 + 1000;

	return OCReg;
}

/***************************************************** Interrupt *****************************************************/

void USART2_IRQHandler (void){
	static uint16_t DutyCycle;

	if (USART2->ISR & USART_CR1_RXNEIE){

		USART2	-> ISR &= ~USART_CR1_RXNEIE;

		if (((USART2 -> RDR) >= 0) && ((USART2 -> RDR) <= 100))
		{
			DutyCycle = CalculateOCReg(USART2 -> RDR);
			TIM2	-> CCR2		= DutyCycle;
			SendStringUSART2("OK.\r\n");
		}
		else
		{
			SendStringUSART2("Incorrect duty cycle.\r\n");
		}
	}

}
