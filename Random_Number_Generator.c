/*
 * RandomNumberGenerator.c
 *
 *  Created on: Aug 13, 2025
 *      Author: MohsenCha
 *      Version: 1.0
 *      Limitation:
 *      	Interrupt and Low-power modes are not yet supported
 *      Target Hardware Families:
 *      	STM32F4xx family
 *      Description:
 *      	The RNG processor is a random number generator, based on a continuous analog noise, that provides a random 32-bit value to the host when read.
 * 			The RNG passed the FIPS PUB 140-2 (2001 October 10) tests with a success ratio of 99%
 */

#include "Random_Number_Generator.h"
#include "bit_operation.h"
#include "main.h"

//__HAL_RCC_RNG_FORCE_RESET();
//__HAL_RCC_RNG_RELEASE_RESET()

void RNG_init(void)
{
	// Enabling RNG Clock
	__HAL_RCC_RNG_CLK_ENABLE();
	// Enabling RNG Interrupt
#if RNG_INTERRUPT == 1
	BIT_SET(RNG->CR,RNG_CR_IE);
#endif
	//Enable Random Number Generation
	BIT_SET(RNG->CR,RNG_CR_RNGEN);
}

void RNG_Disable(void)
{
#if RNG_INTERRUPT == 1
	BIT_CLR(RNG->CR,RNG_CR_IE);
#endif
	BIT_CLR(RNG->CR,RNG_CR_RNGEN);
	__HAL_RCC_RNG_CLK_DISABLE();
}
void RNG_Low_Power_Enable(void)
{
	//_HAL_RCC_RNG_CLK_SLEEP_ENABLE();
}
void RNG_Low_Power_Disable(void)
{
	__HAL_RCC_RNG_CLK_SLEEP_DISABLE();
}
uint8_t RNG_Data_Read(uint32_t* random_value)
{
	while(BIT_CHK(RNG->SR,RNG_SR_DRDY) != 1);
	*random_value = (RNG->DR);
	return RNG_OK;
}

