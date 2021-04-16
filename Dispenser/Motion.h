// Motion.h

#include <stdint.h>

void Motion_Init(void);

void Motion_Handler(void);

uint32_t Measure_distance(void);
void Timer0ACapture_init(void);
void Delay_MicroSecond(int time);
void Delay(unsigned long counter);

