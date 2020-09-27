/************************************************ Library ************************************************/

#include "stm32f3xx.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "sysinit.h"
#include "libUART.h"
#include "libPWM.h"

/************************************************ Defines ************************************************/

#define OSC_FREQ	72000000
#define PWM_FREQ	50
#define PWM_RES		OSC_FREQ/PWM_FREQ

/************************************************ Used FreeRTOS tasks ************************************************/

void vTaskButtonUser (void *argument);
void vTaskPWMGen (void *argument);
