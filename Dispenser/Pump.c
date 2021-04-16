// Pump.c

#include <stdint.h>
#include "tm4c123gh6pm.h"

#include "SysTickInts.h"
#include "PLL.h"
#include "LaunchPad.h"
#include "CortexM.h"

// Pump_Init
// initialize the pump
// pump uses port D pin 1 as an output driving pin
void Pump_Init(void){
	//SYSCTL_RCGCGPIO_R |= 0x00000008;
	//while((SYSCTL_RCGCGPIO_R&0x10)==0){
	//		}
	GPIO_PORTD_DEN_R |=  0x02;
	GPIO_PORTD_DIR_R |=  0x02;
	GPIO_PORTD_DATA_R |=  0x02;
}

// pump_disable
// turn off the fucking pump
void Pump_Disable(void){
	GPIO_PORTD_DATA_R &=  ~0x02;
	
}
