/************************************************ Library ************************************************/

#include "fmac.h"

/**************************************** Configuration functions ***************************************/

void InitFmac(void)
{
	RCC		-> AHB1ENR		|= RCC_AHB1ENR_FMACEN;

	FMAC	-> CR			|= FMAC_CR_RIEN;

	NVIC_EnableIRQ(FMAC_IRQn);
	NVIC_SetPriority(FMAC_IRQn, 5);
}

//threshold is free space 2^FULL_WM watermark
void ConfigFmacX1buff (uint8_t offset, uint8_t len, uint8_t threshold)
{
	FMAC	-> X1BUFCFG		&= ~FMAC_X1BUFCFG_X1_BASE;
	FMAC	-> X1BUFCFG		&= ~FMAC_X1BUFCFG_X1_BUF_SIZE;
	FMAC	-> X1BUFCFG		&= ~FMAC_X1BUFCFG_FULL_WM;

	FMAC	-> X1BUFCFG		|= (offset << FMAC_X1BUFCFG_X1_BASE_Pos);
	FMAC	-> X1BUFCFG		|= (len << FMAC_X1BUFCFG_X1_BUF_SIZE_Pos);
	FMAC	-> X1BUFCFG		|= (threshold << FMAC_X1BUFCFG_FULL_WM_Pos);
}

void ConfigFmacX2Buff (uint8_t offset, uint8_t len)
{
	FMAC	-> X2BUFCFG		&= ~FMAC_X2BUFCFG_X2_BASE;
	FMAC	-> X2BUFCFG		&= ~FMAC_X2BUFCFG_X2_BUF_SIZE;

	FMAC	-> X2BUFCFG		|= (offset << FMAC_X2BUFCFG_X2_BASE_Pos);
	FMAC	-> X2BUFCFG		|= (len << FMAC_X2BUFCFG_X2_BUF_SIZE_Pos);
}

//threshold is required data 2^FULL_WM watermark
void ConfigFmacYBuff(uint8_t offset, uint8_t len, uint8_t threshold)
{
	FMAC	-> YBUFCFG		&= ~FMAC_YBUFCFG_Y_BASE;
	FMAC	-> YBUFCFG		&= ~FMAC_YBUFCFG_Y_BUF_SIZE;
	FMAC	-> YBUFCFG		&= ~FMAC_YBUFCFG_EMPTY_WM;

	FMAC	-> YBUFCFG		|= (offset << FMAC_YBUFCFG_Y_BASE_Pos);
	FMAC	-> YBUFCFG		|= (len << FMAC_YBUFCFG_Y_BUF_SIZE_Pos);
	FMAC	-> YBUFCFG		|= (threshold << FMAC_YBUFCFG_EMPTY_WM_Pos);
}

void ConfigFmacRQP (uint8_t r_param, uint8_t q_param, uint8_t p_param)
{
	FMAC	-> PARAM		|= (r_param << FMAC_PARAM_R_Pos);
	FMAC	-> PARAM		|= (q_param << FMAC_PARAM_Q_Pos);
	FMAC	-> PARAM		|= (p_param << FMAC_PARAM_P_Pos);
}

/**************************************** Execution functions ***************************************/

void ExecuteFmacFunction(void)
{
	FMAC	-> PARAM		|= FMAC_PARAM_START;
}

void StopFmacFunction(void)
{
	FMAC	-> PARAM		&= ~FMAC_PARAM_START;
}

void ResetFmac(void)
{
	FMAC	-> CR			|= FMAC_CR_RESET;
}

void WriteFmacData(uint16_t data)
{
	FMAC	-> WDATA		|= data;
}

void WriteFmacBuffer(uint16_t *data, uint8_t length)
{
	uint8_t i;

	for (i = 0; i < length; i++)
	{
		WriteFmacData(data[i]);
	}
}

uint16_t ReadFmacDataY(void)
{
	return (FMAC -> RDATA);
}

/**************************************** Preload functions ***************************************/

//X1 preload is not required for filter functions with continuous data stream, but is useful with vector operations
void SelectFmacPreloadFmacX1(uint8_t offset, uint8_t len, uint8_t threshold)
{
	ConfigFmacX1buff(offset, len, threshold);
	ConfigFmacRQP (0, 0, len);

	FMAC	-> PARAM		|= FMAC_PARAM_FUNC_LOAD_X1_BUFFER;
	ExecuteFmacFunction();
}

//X2 preload is obligatory for filter coefficients
void SelectFmacPreloadFmacX2(uint8_t offset, uint8_t n_param, uint8_t m_param)
{
	ConfigFmacX2Buff(offset, (n_param + m_param));
	ConfigFmacRQP (0, m_param, n_param);

	FMAC	-> PARAM		|= FMAC_PARAM_FUNC_LOAD_X2_BUFFER;
	ExecuteFmacFunction();
}

//Y Preload is used mostly with output feedback functions
void SelectFmacPreloadFmacY(uint8_t offset, uint8_t len, uint8_t threshold)
{
	ConfigFmacYBuff(offset, len, threshold);
	ConfigFmacRQP (0, 0, len);

	FMAC	-> PARAM		|= FMAC_PARAM_FUNC_LOAD_Y_BUFFER;
	ExecuteFmacFunction();
}

//Gain is multiplier of normalized coefficients
void SelectFmacConvFir(	uint8_t in_offset, uint8_t in_len, uint8_t in_threshold,
		uint8_t coeff_offset, uint8_t b_coeff_num,
		uint8_t out_offset, uint8_t out_len, uint8_t out_threshold,
		uint8_t gain)
{
	ConfigFmacX1buff(in_offset, in_len, in_threshold);
	ConfigFmacX2Buff(coeff_offset, b_coeff_num);
	ConfigFmacYBuff(out_offset, out_len, out_threshold);
	ConfigFmacRQP (gain, 0, b_coeff_num);

	FMAC	-> PARAM		|= FMAC_PARAM_FUNC_CONV_IIR;
	ExecuteFmacFunction();
}

//Gain is multiplier of normalized coefficients
void SelectFmacIir(	uint8_t in_offset, uint8_t in_len, uint8_t in_threshold,
					uint8_t coeff_offset, uint8_t a_coeff_num, uint8_t b_coeff_num,
					uint8_t out_offset, uint8_t out_len, uint8_t out_threshold,
					uint8_t gain)
{
	ConfigFmacX1buff(in_offset, in_len, in_threshold);
	ConfigFmacX2Buff(coeff_offset, (a_coeff_num + b_coeff_num));
	ConfigFmacYBuff(out_offset, out_len, out_threshold);
	ConfigFmacRQP (gain, a_coeff_num, b_coeff_num);

	FMAC	-> PARAM		|= FMAC_PARAM_FUNC_IIR_FILTER;
	ExecuteFmacFunction();
}

/**************************************** Filter functions ***************************************/

void WriteFmacIirCoefficients(uint16_t *iir_coeff_a, uint16_t *iir_coeff_b, uint8_t offset, uint8_t length_a, uint8_t length_b)
{
	uint8_t i;

	SelectFmacPreloadFmacX2(offset, length_a, length_b);

	for (i = 0; i < length_b; i++)
	{
		WriteFmacData(iir_coeff_b[i]);
	}

	for (i = 0; i < length_a; i++)
	{
		WriteFmacData(iir_coeff_a[i]);
	}

	while (FMAC	-> PARAM & FMAC_PARAM_START);
}

/***************************************** DMA functions ****************************************/

/*
void DMAwriteFMAC(uint8_t *data, uint16_t len)
{
	//study about possible conflict to implement while delay

	DMA1_Channel6		-> CCR		&= ~DMA_CCR_EN;

	DMA1_Channel6		-> CMAR		= (uint32_t)data;
	DMA1_Channel6		-> CNDTR	= len;

	DMA1_Channel6		-> CCR		|= DMA_CCR_EN;

	//flag clear should be set?
}

uint16_t DMAreadFMAC (void)
{

}

*/
