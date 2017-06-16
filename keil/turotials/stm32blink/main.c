
#include "GPIO_STM32F10x.h"
#include "systick.h"

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	sysTickInit(1000);
	GPIO_PortClock(GPIOC,true);
	GPIO_PinConfigure(GPIOC,13,GPIO_OUT_OPENDRAIN,GPIO_MODE_OUT50MHZ);
	
	
	while(1){
		//for(int i=0;i<500000UL;i++);
		delay(500);
		GPIO_PinWrite(GPIOC,13,1);
		//for(int i=0;i<500000UL;i++);
		delay(500);
		GPIO_PinWrite(GPIOC,13,0);
	}
}
