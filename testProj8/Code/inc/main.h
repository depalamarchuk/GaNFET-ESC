/************************************************ Library ************************************************/

#include "stm32f3xx.h"

#include "sysinit.h"
#include "libUART.h"
#include "libPWM.h"

/************************************************ Functuons ************************************************/
static uint16_t CalculateOCReg(uint8_t throttle);
