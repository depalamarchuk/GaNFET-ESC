/************************************************ Library ************************************************/

#include "stm32f3xx.h"

/********************************************* Used functions ********************************************/

void InitUSART (void);
void SendUSART2 (char scr);
void SendStringUSART2 (char* str);
void SendDataUSART2 (uint8_t data);
