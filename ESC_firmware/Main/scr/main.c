#include "main.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

char buffer[] = "Test\r\n";

int main(void)
{
	InitRCC();
	InitLedGPIO();
	InitUSART1();
	InitOpamp1();
	InitOpamp2();
	InitOpamp3();
	InitVrefbuf();
	InitADC12();
	InitDMAusart1();

	xTaskCreate(vTaskLED, "LED", 128, 0 , 1, &TaskConvADCHandle);
	xTaskCreate(vTaskSendUSART, "SendUSART", 128, 0 , 1, &TaskSendUSARTHandle);
	xTaskCreate(vTaskConvADC, "ADC", 128, 0, 2, &TaskConvADCHandle);

	SendDataADC = xQueueCreate(ADCQUEUE, sizeof(uint16_t));

	vTaskStartScheduler();

    while(1)
    {

    }
}

void vTaskLED (void *pvParameters){
	while(1)
	{
		BlinkLED (GREEN, 100);
	}
}

void vTaskSendUSART(void *pvParameters){

	uint16_t adcResult;

	portBASE_TYPE xStatus;
	float adcCoeff = VREF/ADCRES;
	float t0Voltage = 500;
	float TempCoeff = 10;
	float voltage, temperature;
	static char adcResultStr[4],  VoltageStr[4], TemperatureStr[4];

	while(1)
	{

		if (uxQueueMessagesWaiting(SendDataADC) != 0)
		{
			SetLED (RED, OFF);

			xStatus = xQueueReceive(SendDataADC, &adcResult, 0);
			if (xStatus == pdPASS) {
				voltage = adcCoeff*((float)(adcResult));
				temperature = ((voltage - t0Voltage)/TempCoeff);
				ToggleLED(YELLOW);
				SendStringUSART1("Raw data: ");
				SendStringUSART1(UtoaBuiltinDiv(adcResult, adcResultStr));
				SendStringUSART1(" Voltage: ");
				SendStringUSART1(UtoaBuiltinDiv((uint16_t)(voltage), VoltageStr));
				SendStringUSART1(" mV");
				SendStringUSART1(" Temperature: ");
				SendStringUSART1(UtoaBuiltinDiv((uint16_t)(temperature), TemperatureStr));
				SendStringUSART1(" C");
				SendStringUSART1("\r\n");
				ToggleLED(YELLOW);
				vTaskDelay(100);
				WriteDMAuart1();
			}
			else
			{
				SendStringUSART1("Could not receive from the queue.\r\n");
				SetLED (RED, ON);
			}
		}


	}
}

void vTaskConvADC (void *pvParameters){

	uint16_t adcResult;

	static char adcResultStr[5];

	portBASE_TYPE xStatus;

	while(1)
	{
		adcResult = StartConvADC();

		xStatus = xQueueSend(SendDataADC, &adcResult, 0);

		if (xStatus == pdPASS)
		{
			SendStringUSART1("Sent.\r\n");
		}
		else
		{
			SendStringUSART1("Could not send to the queue. ");
			SendStringUSART1(UtoaBuiltinDiv(adcResult, adcResultStr));
			SendStringUSART1("\r\n");
		}

		ToggleLED(WHITE);
		vTaskDelay(200);
	}
}

void InitDMAusart1 (void){
	RCC					-> AHB1ENR	|= RCC_AHB1ENR_DMA1EN;

	DMA1_Channel1		-> CCR		&= ~DMA_CCR_EN;

	DMA1_Channel1		-> CCR		&= ~DMA_CCR_CIRC;						// Disable cycle mode
	DMA1_Channel1		-> CCR		&= ~DMA_CCR_PINC;						// Disable increment pointer peripheral

	DMA1_Channel1		-> CCR		&= ~DMA_CCR_PSIZE;						// Size of data peripheral = 8 bit
	DMA1_Channel1		-> CCR		&= ~DMA_CCR_MSIZE;						// Size of data memory = 8 bit

	DMA1_Channel1		-> CCR		|= DMA_CCR_DIR;							// Read: memory -> peripheral
	DMA1_Channel1		-> CCR		|= DMA_CCR_MINC;						// Disable increment pointer memory (???)
	DMA1_Channel1		-> CCR		&= ~DMA_CCR_PINC;

	DMAMUX1_Channel0	-> CCR		&= ~DMAMUX_CxCR_DMAREQ_ID;
	DMAMUX1_Channel0	-> CCR		|= 0x19UL << DMAMUX_CxCR_DMAREQ_ID_Pos; // USART1_TX

	DMA1_Channel1		-> CPAR		= (uint32_t)&USART1->TDR;
	DMA1_Channel1		-> CMAR		= (uint32_t)&buffer;
	DMA1_Channel1		-> CNDTR	= 32;									// Size of buffer

	USART1				-> CR3		|= USART_CR3_DMAT;						// Enable DMA for USART1

	DMA1_Channel1		-> CCR		|= DMA_CCR_EN;
}

void WriteDMAuart1 (void){
	DMA1_Channel1		-> CCR		&= ~DMA_CCR_EN;
	DMA1_Channel1		-> CNDTR	= (sizeof(buffer)-1);
	DMA1				-> IFCR		|= DMA_IFCR_CGIF1;						// global interrupt flag clear for channel 1
	DMA1_Channel1		-> CCR		|= DMA_CCR_EN;
}

/*
void ADC1_2_IRQHandler(void)
{
	WriteDMAuart1();
}
*/
