#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC


volatile uint32_t tick=0;

void sysTickInit(uint32_t freq)
{
	RCC_ClocksTypeDef rcc_clock;
	RCC_GetClocksFreq(&rcc_clock);
	SysTick_Config(rcc_clock.HCLK_Frequency /freq);
}


void SysTick_Handler(){
	tick++;
}

uint32_t millis()
{
	return tick;
}

void delay(uint32_t time)
{
	uint32_t start_time = millis();
	while(millis() - start_time < time);
}
