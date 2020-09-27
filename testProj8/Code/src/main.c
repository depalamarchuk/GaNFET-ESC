/************************************************ Library ************************************************/

#include "main.h"

/************************************************** Main *************************************************/

int main(void)
{

	InitRCC();
	InitGPIO();
	InitUSART();
	InitPWM();

	xTaskCreate(vTaskButtonUser, "Button", 32, 0, 1, 0);
	xTaskCreate(vTaskPWMGen, "PWM", 32, 0, 1, 0);

	vTaskStartScheduler();

	while(1)
	{

	}

}

/************************************************ Used FreeRTOS tasks ************************************************/

void vTaskPWMGen (void *argument){
	static uint16_t i;

	uint8_t sw = 0;

	while (1)
	{
		TIM2	-> CCR2		= i;

		if (sw == 0){
			i++;
		}
		else
		{
			i--;
		}

		if (i == 1000){
			sw = 1;
		}
		else if (i == 0 || i > 1000)
		{
			i = 0;
			sw = 0;
		}

		vTaskDelay(5);
	}
}

void vTaskButtonUser (void *argument){

	while (1)
	{
		if ((GPIOC -> IDR & GPIO_IDR_13) == 0){
			vTaskDelay(100);
			GPIOB	-> ODR ^= GPIO_ODR_0;
			SendStringUSART2 ("Button\r\n");
		}

		vTaskDelay(200);
	}
}

/***************************************************** Interrupt *****************************************************/

void USART2_IRQHandler (void){
	if (USART2->ISR & USART_CR1_RXNEIE){

		USART2	-> ISR &= ~USART_CR1_RXNEIE;

		if (USART2 -> RDR == '0'){
			SendStringUSART2 ("OFF\r\n");
			GPIOB	-> BSRR |= GPIO_BSRR_BR_13;
		}

		if (USART2 -> RDR == '1'){
			SendStringUSART2 ("ON\r\n");
			GPIOB	-> BSRR |= GPIO_BSRR_BS_13;
		}

	}

}
