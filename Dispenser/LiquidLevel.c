//LiquidLevel.c

#include <stdint.h>
#include "tm4c123gh6pm.h"

#include "SysTickInts.h"
#include "PLL.h"
#include "LaunchPad.h"
#include "CortexM.h"

// LL_Init
// initialize LiquidLevelSensor
// also initialize LEDs
void LL_Init(void){
			SYSCTL_RCGCGPIO_R |= 0x0000000A;            //Initialize clock for port D
			while((SYSCTL_RCGCGPIO_R&0x0A)==0){
			}
			GPIO_PORTD_DEN_R |=  0x01;
			GPIO_PORTD_DIR_R &=  ~0x01;
			
			//initialize the LED
			GPIO_PORTB_DEN_R |= 0x02;
			GPIO_PORTB_DIR_R |= 0x02;
			GPIO_PORTB_PUR_R |= 0x02;
			GPIO_PORTB_DATA_R &= ~0x02;
}

// checkLevel
// return the level of liquid in the dispenser
// returned as a positive double
// called every time sanitizer is dispensed
int checkLevel(void){
	return GPIO_PORTD_DATA_R&0x01;
}

// lowLevel
// code to be executed in the event of a low level of sanitizer
void lowLevel(void){
	GPIO_PORTB_DATA_R |= 0x02;
}
