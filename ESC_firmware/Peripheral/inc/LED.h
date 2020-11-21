/************************************************ Library ************************************************/

#include "stm32g4xx.h"

//colors indicate port numbers
typedef enum SettingsLED{
	GREEN		= 5,
	YELLOW		= 9,
	WHITE		= 13,
	BLUE		= 14,
	RED			= 15,
	ON			= 1,
	OFF			= 0
} LED;

/********************************************* Used functions ********************************************/
void InitLedGPIO (void);
void SetLED (LED COLOR, LED STATE);
void BlinkLED (LED COLOR, uint16_t period_ms);
void ToggleLED (LED COLOR);
