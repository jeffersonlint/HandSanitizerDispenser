// Main.c

#include <stdint.h>
#include "tm4c123gh6pm.h"

#include "SysTickInts.h"
#include "PLL.h"
#include "LaunchPad.h"
#include "CortexM.h"
#include "I2C0.h"
#include "ST7735.h"
#include "Pump.h"
#include "Motion.h"
#include "LiquidLevel.h"



/* global variables to store and display distance in cm */
uint32_t time; /*stores pulse on time */
uint32_t distance; /* stores measured distance value */

/* main code to take distance measurement and send data to UART terminal */


int main(void){
  PLL_Init(Bus80MHz);         // bus clock at 80 MHz
  LaunchPad_Init();           // activate port F
	Timer0ACapture_init();  /*initialize Timer0A in edge edge time */
	//I2C_Init();
	LL_Init();
	EnableInterrupts();
  while(1){    
		time = Measure_distance(); /* take pulse duration measurement */ 
		distance = (time * 10625)/10000000; /* convert pulse duration into distance */
		//ST7735_SetCursor(0,3);
		//int distance = Measure_distance();
		if(checkLevel()==1){
			lowLevel();
		}
		else{
			GPIO_PORTB_DATA_R &= ~0x02;
		}
		if(distance < 30){
			Pump_Init();
			PF1 ^= 0x02;
			Delay(20000);
			Pump_Disable();
			if(checkLevel()==1){
				lowLevel();
			}
		}
	}
}







