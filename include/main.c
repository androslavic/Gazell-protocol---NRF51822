#include "main.h"

int main (void) {
	
	clock_init();
	uart_init();	

#if NRF_DEVICE

	gzll_init_device();	
	int32_t i=0;

while(1){
		
	for(i=0;i<100000;i++);

	if (slovo != 0)
		slovo=0;
	nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&slovo,1);
	 
	

	

}
#else
	gzll_init_host();

while(1){


		
		}

	 		
#endif




}
	
	



