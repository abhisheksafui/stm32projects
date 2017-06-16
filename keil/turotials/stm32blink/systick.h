#ifndef ASD
#define ASD

void sysTickInit(uint32_t freq);
void sysTickHandler(void);
uint32_t millis(void);
void delay(uint32_t time);

#endif
