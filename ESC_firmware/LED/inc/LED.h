/************************************************ Library ************************************************/

#include "stm32g4xx.h"

#define LED_GREEN		0b00000001
#define LED_YELLOW		0b00000010
#define LED_WHITE		0b00000100
#define LED_BLUE		0b00001000
#define LED_RED			0b00010000
#define LED_UNDEF1		0b00100000
#define LED_UNDEF2		0b01000000
#define LED_UNDEF3		0b10000000

/********************************************* Used functions ********************************************/
void InitLedGPIO (void);
void SetLED (uint8_t COLOR);
void TurnOnLED (uint8_t COLOR);
void TurnOffLED (uint8_t COLOR);
void BlinkLED (uint8_t COLOR, uint8_t period);
void ToggleLED ();
void ShiftLEDLeft (uint8_t *COLOR);
