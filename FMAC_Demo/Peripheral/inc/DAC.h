/************************************************ Library ************************************************/

#include "stm32g4xx.h"

/************************************************ Used functions ************************************************/

void InitDAC2 (uint32_t mcu_freq);
void WriteDAC2 (int16_t data);
void InitDmaDac2 (void);
void WriteDataDmaDac2 (int16_t *data);
