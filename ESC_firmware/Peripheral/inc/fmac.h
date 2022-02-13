/************************************************ Library ************************************************/

#include "stm32g4xx.h"

/********************************************* Used functions ********************************************/

#define FMAC_PARAM_FUNC_LOAD_X1_BUFFER             (0x1UL << FMAC_PARAM_FUNC_Pos)
#define FMAC_PARAM_FUNC_LOAD_X2_BUFFER             (0x2UL << FMAC_PARAM_FUNC_Pos)
#define FMAC_PARAM_FUNC_LOAD_Y_BUFFER          	   (0x3UL << FMAC_PARAM_FUNC_Pos)
#define FMAC_PARAM_FUNC_CONV_IIR		           (0x8UL << FMAC_PARAM_FUNC_Pos) //FIR is convolution
#define FMAC_PARAM_FUNC_IIR_FILTER		           (0x9UL << FMAC_PARAM_FUNC_Pos)

void InitFmac(void);
void ConfigFmacX1buff (uint8_t offset, uint8_t len, uint8_t threshold);
void ConfigFmacX2Buff (uint8_t offset, uint8_t len);
void ConfigFmacYBuff(uint8_t offset, uint8_t len, uint8_t threshold);
void ConfigFmacRQP (uint8_t r_param, uint8_t q_param, uint8_t p_param);
void ExecuteFmacFunction(void);
void StopFmacFunction(void);
void ResetFmac(void);
void WriteFmacData(uint16_t data);
uint16_t ReadFmacDataY(void);
void SelectFmacPreloadFmacX1(uint8_t offset, uint8_t len, uint8_t threshold);
void SelectFmacPreloadFmacX2(uint8_t offset, uint8_t n_param, uint8_t m_param);
void SelectFmacPreloadFmacY(uint8_t offset, uint8_t len, uint8_t threshold);
void SelectFmacConvFir(	uint8_t in_offset, uint8_t in_len, uint8_t in_threshold,
						uint8_t coeff_offset, uint8_t b_coeff_num,
						uint8_t out_offset, uint8_t out_len, uint8_t out_threshold,
						uint8_t gain);
void SelectFmacIir(	uint8_t in_offset, uint8_t in_len, uint8_t in_threshold,
					uint8_t coeff_offset, uint8_t a_coeff_num, uint8_t b_coeff_num,
					uint8_t out_offset, uint8_t out_len, uint8_t out_threshold,
					uint8_t gain);
void WriteFmacIirCoefficients(uint16_t *data, uint8_t offset, uint8_t length_a, uint8_t length_b);
