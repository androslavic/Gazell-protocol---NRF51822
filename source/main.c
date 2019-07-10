#include "main.h"



void system_init(void){
	


	clock_init();
	uart_init();	
	RingBufInit(&ringBuf, buffer,size);
	

}





	
int main (void) {
	
	int i;
	
	terminalOut("\n\r Entering main... ");	
	
	system_init();


	terminalOut("\n\r Main program ready. \n\r ");	
	
	
	
  // set up and send i2c commands


//  uint8_t txbuf[1] = {0xE3};
//  uint8_t rxbuf[1] = {0};
//	uint8_t *data;
//	unsigned char tekst[12]="aaaa";
//	data=tekst;
//	i2c_master_send(data,7);
//	unsigned char text[100]="androslavicandroslavicandroslavicandroslavicandroslavicandroslavic";
//	unsigned char *data;
//	data=text;
	
	
	
	

		
		
  while (1) {

			++i;	

  }	
}
	
	



