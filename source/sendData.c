#include "sendData.h"

extern	tRingBufObject ringBuf;
extern	unsigned char pucData[30];	
extern	int count;


int sendData(const char *format, ...){
	
		char buffer[30]={0};

	  va_list arg;

	  va_start (arg, format);

	  vsprintf (buffer, format, arg);
	
			if (!(nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&buffer,count*sizeof(uint8_t)))){ 
					uart_puts(" Greska,paket nije dodan na tx fifo!\r\n");
					RingBufFlush(&ringBuf);		
					}
	  va_end (arg);

	
	return 0;
	
}
