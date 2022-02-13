/************************************************ Library ************************************************/

#include "stm32g4xx.h"

void InitUSART1 (void);
void SendUSART1 (char scr);
void SendStringUSART1 (char* str);
void SendDataUSART1 (uint8_t data);
void InitDMAusart1 (void);
void WriteStrDMAusart1 (char *data);
void WriteDataDMAusart1 (uint8_t *data, uint16_t len);
