/************************************************ Include ************************************************/

#include "stm32g4xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "LED.h"
#include "UART.h"
#include "fmac.h"
#include "sysinit.h"
#include "DAC.h"
#include "CORDIC.h"
#include "vrefbuf.h"
#include "conversions.h"

/************************************************ Defines ************************************************/

TaskHandle_t TaskLEDHandle;
TaskHandle_t TaskSendUSARTHandle;

/*********************************************** Functions ***********************************************/

void InitTIM6(void);
void vTaskLED (void *pvParameters);
void vTaskSendUSART(void *pvParameters);
