#include "main.h"



void system_init(void){
		
	clock_init();
	uart_init();	
	RingBufInit(&ringBuf, buffer,size);
	gzll.mode=NRF_GZLL_MODE_SUSPEND;	
	flash_check();
	start_timer();
	__enable_irq();
}





	
int main (void) {
	
	system_init();
	terminalOut("System initialised!\r\n");	
	
	
  while (1) 
	{

	
	// firmware update flag check
	if (boot == 1)
		{
	
			boot = 0;
			__disable_irq();
		
			JumpAddress = *(__IO uint32_t*) (BOOTLOADER_ADDRESS + 4);
			Jump_To_Application = (pFunction) JumpAddress;

			__set_MSP(*(__IO uint32_t*) BOOTLOADER_ADDRESS);
		
			Jump_To_Application();
	
		}

  }	
}
	
	



