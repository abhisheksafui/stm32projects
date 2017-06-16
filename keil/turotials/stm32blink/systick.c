#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC


volatile uint32_t tick_ms=0;
volatile uint32_t delay_count;

void sysTickInit(uint32_t freq)
{
	RCC_ClocksTypeDef rcc_clock;
	RCC_GetClocksFreq(&rcc_clock);
	SysTick_Config(rcc_clock.HCLK_Frequency /freq);
}


void SysTick_Handler(){
	tick_ms++;
	delay_count--;
}

uint32_t millis()
{
	return tick_ms;
}

void delay(uint32_t time)
{
	delay_count = time;
	while(delay_count);
}
