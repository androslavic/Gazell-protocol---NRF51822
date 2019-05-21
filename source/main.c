#include "main.h"


	unsigned char buffer[30]={0};
	tRingBufObject ringBuf;
	unsigned long size=30;	
	unsigned char pucData[30]={0};	
	int count=0;
	
	
int main (void) {
	
	clock_init();
	uart_init();	
	RingBufInit(&ringBuf, buffer,size);
	start_timer();                    
	gzll.mode=NRF_GZLL_MODE_SUSPEND;
	


	////////////////////////////////
	//provjeri ima li sta u flashu//
	// flash_check();
	////////////////////////////////
	

	while(1){}	 		
}
	
	



