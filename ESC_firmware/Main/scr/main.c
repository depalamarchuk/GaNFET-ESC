#include "main.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	InitRCC();
	InitLedGPIO();
	InitUSART1();
	InitADC();

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
	static float adcCoeff = VREF/ADCRES;
	float t0Voltage = 500;
	float TempCoeff = 10;
	static float voltage, temperature;
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
