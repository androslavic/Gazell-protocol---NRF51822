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

	
	////////////////////////////////
	//provjeri ima li sta u flashu//
	// flash_check();
	////////////////////////////////
	
	
	#if NRF_DEVICE

	gzll_init_device();	
	int32_t i=0;

while(1){
		
	for(i=0;i<500000;i++);

	if (i != 0)
		i=0;
	nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&i,1);
	 
	
}
#else
	gzll_init_host();
	while(1){}	 		
#endif
}
	
	



