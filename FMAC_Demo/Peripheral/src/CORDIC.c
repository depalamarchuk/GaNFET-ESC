/************************************************ Library ************************************************/

#include "CORDIC.h"

/********************************************* Used functions ********************************************/

void InitCORDIC(void)
{
	RCC 	-> AHB1ENR	|= RCC_AHB1ENR_CORDICEN;
}

void WriteCORDIC(int32_t data)
{
	CORDIC	-> WDATA	= data;
}

int32_t ReadCORDIC(void)
{
	return (CORDIC -> RDATA);
}

//A quick function is designed to return a value without an interrupt, however the mcu halts until the calculation is finished
void QuickFunctionQ15inQ15out(	int16_t *arg1, int16_t *arg2, int16_t *res1, int16_t *res2, uint16_t size,
									uint8_t scale, func_t function, uint8_t precision)
{
	uint16_t i = 0;
	static int32_t data;
	static uint32_t data1, data2;
	static int32_t result, result1, result2;

	//is this the same?
	CORDIC		-> CSR 		&= (~CORDIC_CSR_FUNC & ~CORDIC_CSR_PRECISION & ~CORDIC_CSR_SCALE);

	CORDIC		-> CSR 		&= ~CORDIC_CSR_FUNC;
	CORDIC		-> CSR 		&= ~CORDIC_CSR_PRECISION;
	CORDIC		-> CSR 		&= ~CORDIC_CSR_SCALE;

	CORDIC		-> CSR 		|= (function << CORDIC_CSR_FUNC_Pos);
	if (precision < 16)
	{
		CORDIC	-> CSR 		|= (precision << CORDIC_CSR_PRECISION_Pos);
	}

	//later an applicable scale should be checked for every function
	if (scale < 8)
	{
		CORDIC	-> CSR 		|= (scale << CORDIC_CSR_SCALE_Pos);
	}

	CORDIC		-> CSR 		&= ~CORDIC_CSR_NRES;
	CORDIC		-> CSR 		&= ~CORDIC_CSR_NARGS;
	CORDIC		-> CSR 		|= CORDIC_CSR_ARGSIZE;
	CORDIC		-> CSR 		|= CORDIC_CSR_RESSIZE;

	for (i = 0; i < size; i++)
	{
		data1 = (uint32_t)arg1[i];
		data2 = (uint32_t)arg2[i];
		data = (data2 << 16) | (data1 & 0x0000FFFF);
		WriteCORDIC(data);

		while(!(CORDIC->CSR & CORDIC_CSR_RRDY));

		result = ReadCORDIC();

		result1 = (int16_t)(((result & 0xFFFF0000) >> 16));
		res1[i] = result1;
		result2 = (int16_t)((result & 0x0000FFFF));
		res2[i] = result2;
	}
}

void QuickFunctionQ31inQ31out(	int32_t *arg1, int32_t *arg2, int32_t *res1, int32_t *res2, uint16_t size,
									uint8_t scale, func_t function, uint8_t precision)
{
	uint16_t i = 0;
	static int32_t data1, data2;
	static int32_t result1, result2;

	//is this the same?
	CORDIC		-> CSR 		&= (~CORDIC_CSR_FUNC & ~CORDIC_CSR_PRECISION & ~CORDIC_CSR_SCALE);

	CORDIC		-> CSR 		&= ~CORDIC_CSR_FUNC;
	CORDIC		-> CSR 		&= ~CORDIC_CSR_PRECISION;
	CORDIC		-> CSR 		&= ~CORDIC_CSR_SCALE;

	CORDIC		-> CSR 		|= (function << CORDIC_CSR_FUNC_Pos);
	if (precision < 16)
	{
		CORDIC	-> CSR 		|= (precision << CORDIC_CSR_PRECISION_Pos);
	}

	//later an applicable scale should be checked for every function
	if (scale < 8)
	{
		CORDIC	-> CSR 		|= (scale << CORDIC_CSR_SCALE_Pos);
	}

	CORDIC		-> CSR 		|= CORDIC_CSR_NRES;
	CORDIC		-> CSR 		|= CORDIC_CSR_NARGS;
	CORDIC		-> CSR 		&= ~CORDIC_CSR_ARGSIZE;
	CORDIC		-> CSR 		&= ~CORDIC_CSR_RESSIZE;

	for (i = 0; i < size; i++)
	{
		data1 = arg1[i];
		data2 = arg2[i];

		WriteCORDIC(data1);
		WriteCORDIC(data2);

		while(!(CORDIC->CSR & CORDIC_CSR_RRDY));

		result1 = ReadCORDIC();
		result2 = ReadCORDIC();

		res1[i] = result1;
		res2[i] = result2;
	}
}
