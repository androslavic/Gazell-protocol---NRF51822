#include "main.h"



void system_init(void){
	
	clock_init();
	uart_init();	
	RingBufInit(&ringBuf, buffer,size);
	flash_check();

}





	
int main (void) {
	
	

	system_init();
	
	int i;
	
	terminalOut("\n\r Bootloader initialised!.");	


	NRF_UART0->ENABLE = 0; 

	JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
	Jump_To_Application = (pFunction) JumpAddress;

	__set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
		
	Jump_To_Application();
		

	
	
  while (1) {

			++i;	

  }	
}
	
	



