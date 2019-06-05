#include "main.h"



void system_init(void){
	
	clock_init();
	uart_init();	
	RingBufInit(&ringBuf, buffer,size);
	gzll.mode=NRF_GZLL_MODE_SUSPEND;	
	flash_check();
	start_timer();
  i2c_init_config(17, 19, 0x40);
  i2c_enable();	
}







	
int main (void) {
	
	system_init();

	int i=0;

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

        //i2c_config.I2C_bus->EVENTS_TXDSENT = 0;
  }	
}
	
	



