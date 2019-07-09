#include "clock.h"
	
	void clock_init(void){
		
		//16 MHz crystal is used
		NRF_CLOCK->XTALFREQ = 0xFF;
		
		//Start clock
		NRF_CLOCK->TASKS_HFCLKSTART=1;
		
		
		NRF_CLOCK->LFCLKSRC = CLOCK_LFCLKSRC_SRC_Xtal;
		
		NRF_CLOCK->TASKS_LFCLKSTART=1;
		
	};
	
	
