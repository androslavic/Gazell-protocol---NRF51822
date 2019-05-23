#include "main.h"


void system_init(void){
	
	clock_init();
	uart_init();	
	RingBufInit(&ringBuf, buffer,size);
	start_timer();                    
	gzll.mode=NRF_GZLL_MODE_SUSPEND;	
	flash_check();

}
	
int main (void) {
	
	system_init();

	int i;
	while(1){
	i++;
	}	 		
}
	
	



