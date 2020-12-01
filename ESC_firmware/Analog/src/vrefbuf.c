/************************************************ Library ************************************************/

#include "vrefbuf.h"

/********************************************* Used functions ********************************************/

void InitVrefbuf (void)
{
	RCC				-> APB2ENR	|= RCC_APB2ENR_SYSCFGEN;

	VREFBUF			-> CSR		|= VREFBUF_CSR_VRS_0;					//VREFBUF = 2.5V
	while (VREFBUF->CSR & VREFBUF_CSR_VRR);
	VREFBUF			-> CSR		|= VREFBUF_CSR_ENVR;
	VREFBUF			-> CSR		&= ~VREFBUF_CSR_HIZ;
}
