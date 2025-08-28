/*
 * RandomNumberGenerator.h
 *
 *  Created on: Aug 13, 2025
 *      Author: MohsenCha
 */

#ifndef RANDOM_NUMBER_GENERATOR_H_
#define RANDOM_NUMBER_GENERATOR_H_

#include <stdint.h>

// *** RNG Configuration Parameters ***
#define RNG_INTERRUPT	(0)		//keep it zero for now

enum{
	RNG_OK = 1,
	RNG_CLOCK_ERROR,
	RNG_SEED_ERROR,
};

void RNG_init(void);
void RNG_Low_Power_Enable(void);
void RNG_Low_Power_Disable(void);
void RNG_Disable(void);
uint8_t RNG_Data_Read(uint32_t* random_value);

#endif /* RANDOM_NUMBER_GENERATOR_H_ */
