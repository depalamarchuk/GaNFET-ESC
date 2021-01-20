#include "main.h"

//#if !defined(__SOFT_FP__) && defined(__ARM_FP)
//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
//#endif
;

uint16_t coeff_a[] = {0x8d83,0x2959,0xff57};
uint16_t coeff_b[] = {0x06c2,0x0d83,0x06c2};
uint8_t coeff_gain = 2;

int main(void)
{
	InitRCC();
	InitLedGPIO();
	InitUSART1();
	InitDMAusart1();
	InitFmac();
	WriteFmacIirCoefficients(coeff_a, coeff_b, 0x00, sizeof(coeff_a), sizeof(coeff_b));
	SelectFmacIir(0x00, 0x08, 0x00, 0x00, sizeof(coeff_a), sizeof(coeff_b), 0x00, 0x04, 0x00, coeff_gain);
	InitOpamp1();
	InitOpamp2();
	InitOpamp3();
	InitVrefbuf();
	InitADC12();

	xTaskCreate(vTaskLED, "LED", 128, 0 , 1, &TaskLEDHandle);
	xTaskCreate(vTaskSendUSART, "SendUSART", 2048, 0 , 1, &TaskSendUSARTHandle);

	SendDataADC = xQueueCreate(512, sizeof(uint16_t));
	SendDataFMAC = xQueueCreate(512, sizeof(uint16_t));

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

	uint16_t adcResult, fmacResult;

	portBASE_TYPE xAdcStatus, xFmacStatus;
	/*float adcCoeff = VREF/ADCRES;
	float t0Voltage = 500;
	float TempCoeff = 10;
	float voltage, temperature; */
	static char adcResultStr[4],  fmacResultStr[4];
	//static char VoltageStr[4], TemperatureStr[4];

	while(1)
	{

		if (uxQueueMessagesWaiting(SendDataADC) != 0)
		{
			SetLED (RED, OFF);

			xAdcStatus = xQueueReceiveFromISR(SendDataADC, &adcResult, 0);
			if (xAdcStatus == pdPASS) {
				//voltage = adcCoeff*((float)(adcResult));
				//temperature = ((voltage - t0Voltage)/TempCoeff);
				ToggleLED(YELLOW);
				WriteStrDMAusart1("Unfiltered: ");
				WriteStrDMAusart1(UtoaBuiltinDiv(adcResult, adcResultStr));
				/* WriteStrDMAusart1(" Voltage: ");
				WriteStrDMAusart1(UtoaBuiltinDiv((uint16_t)(voltage), VoltageStr));
				WriteStrDMAusart1(" mV");
				WriteStrDMAusart1(" Temperature: ");
				WriteStrDMAusart1(UtoaBuiltinDiv((uint16_t)(temperature), TemperatureStr));
				WriteStrDMAusart1(" C");
				WriteStrDMAusart1("\r\n"); */
				ToggleLED(YELLOW);
				vTaskDelay(100);

			}
			else
			{
				WriteStrDMAusart1("Could not receive from the ADC queue.\r\n");
				SetLED (RED, ON);
			}

			xFmacStatus = xQueueReceiveFromISR(SendDataFMAC, &fmacResult, 0);
			if (xFmacStatus == pdPASS) {
				ToggleLED(YELLOW);
				WriteStrDMAusart1("Filtered: ");
				WriteStrDMAusart1(UtoaBuiltinDiv(fmacResult, fmacResultStr));
				ToggleLED(YELLOW);
				vTaskDelay(100);
			}
			else
			{
				WriteStrDMAusart1("Could not receive from the FMAC queue.\r\n");
				SetLED (RED, ON);
			}
		}
	}
}

void ADC1_2_IRQHandler(void)
{
	uint16_t temp;

	if (ADC1->ISR & ADC_ISR_JEOS)
	{
		ADC1->ISR |= ADC_ISR_JEOS;
		temp = (ADC1 -> JDR1);
		xQueueSendToBackFromISR(SendDataADC, &temp, 0);
		WriteFmacData(temp);
		ToggleLED(WHITE);
	}
}

void FMAC_IRQHandler(void)
{
	static uint16_t temp;

	if (FMAC -> SR & FMAC_SR_YEMPTY)
	{
		FMAC -> SR &= ~FMAC_SR_YEMPTY;
		temp = (FMAC -> RDATA);
		xQueueSendToBackFromISR(SendDataFMAC, &temp, 0);
		ToggleLED(BLUE);
	}
}
