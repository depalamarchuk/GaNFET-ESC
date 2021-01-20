/************************************************ Include ************************************************/

#include "stm32g4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "LED.h"
#include "UART.h"
#include "vrefbuf.h"
#include "adc.h"
#include "opamp.h"
#include "fmac.h"
#include "sysinit.h"

/************************************************ Defines ************************************************/

//#define __SOFT_FP__		0
//#define __ARM_FP		1

xQueueHandle SendDataADC;
xQueueHandle SendDataFMAC;

TaskHandle_t TaskLEDHandle;
TaskHandle_t TaskSendUSARTHandle;
TaskHandle_t TaskConvADCHandle;

#define ADCQUEUE	32
#define VREF		2500.f
#define ADCRES		4096.f

/*********************************************** Functions ***********************************************/

void vTaskLED (void *pvParameters);
void vTaskSendUSART(void *pvParameters);
