/************************************************ Library ************************************************/

#include "vrefbuf.h"

/********************************************* Used functions ********************************************/

void InitVrefbuf (void)
{
	RCC				-> APB2ENR	|= RCC_APB2ENR_SYSCFGEN;

	VREFBUF			-> CSR		|= (0x3UL << VREFBUF_CSR_VRS_Pos);			//VREFBUF = 2.90V
	while (VREFBUF->CSR & VREFBUF_CSR_VRR);
	VREFBUF			-> CSR		|= VREFBUF_CSR_ENVR;
	VREFBUF			-> CSR		&= ~VREFBUF_CSR_HIZ;
}
