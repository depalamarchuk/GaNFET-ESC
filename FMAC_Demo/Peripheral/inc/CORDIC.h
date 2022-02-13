/************************************************ Library ************************************************/

#include "stm32g4xx.h"

/************************************************ Defines ************************************************/

typedef enum CordicFunctions{
	COSINE						= 0,
	SINE						= 1,
	PHASE						= 2,
	MODULUS						= 3,
	ARCTANGENT					= 4,
	COSH						= 5,
	SINH						= 6,
	ARCTANH						= 7,
	LN  						= 8,
	SQRT						= 9
} func_t;

/************************************************ Used functions ************************************************/

void InitCORDIC(void);
void WriteCORDIC(int32_t data);
int32_t ReadCORDIC(void);
void QuickFunctionQ15inQ15out(	int16_t *arg1, int16_t *arg2, int16_t *res1, int16_t *res2, uint16_t size,
									uint8_t scale, func_t function, uint8_t precision);
void QuickFunctionQ31inQ31out(	int32_t *arg1, int32_t *arg2, int32_t *res1, int32_t *res2, uint16_t size,
									uint8_t scale, func_t function, uint8_t precision);
