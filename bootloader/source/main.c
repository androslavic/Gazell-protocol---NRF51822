#include "main.h"





void system_init(void){
	
	clock_init();
	uart_init();	
	RingBufInit(&ringBuf, buffer,size);
	gzll.mode=NRF_GZLL_MODE_SUSPEND;	

	gzll_check();	
	flash_check();

		NRF_UART0->ENABLE = 0; 

}





	
int main (void) {
	
	
	system_init();

	int i=0;
	

	
	JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
	Jump_To_Application = (pFunction) JumpAddress;

	__set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
		
	Jump_To_Application();
		
	terminalOut("\n\r Error,bootloader did not enter main program.");	

	
  while (1) 
	{
			++i;	
  }	
}
	
	



