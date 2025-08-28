# STM32RandomNumberGenerator
The RNG is a co-processor on STM32 MCUs for generating true random numbers.

This libray is based on HAL/LL drivers for initialization and working with RNG feature in stm32 MCUs.

# Limitation:
- Interrupt and Low-power modes are not yet supported. do not try to uncomment related parts.
# Target Hardware Families:
- STM32F4xx family
# Description:
- The RNG processor is a random number generator, based on a continuous analog noise, that provides a random 32-bit value to the host when read.
- The RNG passed the FIPS PUB 140-2 (2001 October 10) tests with a success ratio of 99%
