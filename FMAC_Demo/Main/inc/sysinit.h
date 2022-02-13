/************************************************ Library ************************************************/

#include "stm32g4xx.h"

/********************************************* Defines ********************************************/

#define INT_FLASH_KEY1		((uint32_t)0x45670123)
#define INT_FLASH_KEY2		((uint32_t)0xCDEF89AB)

/********************************************* Used functions ********************************************/

void InitRCC (void);

void flashUnlock (void);
void flashLock (void);
void flashAllErase (void);
uint32_t flashReadData (uint32_t address);
void flashWriteData (uint32_t address, uint32_t data);
