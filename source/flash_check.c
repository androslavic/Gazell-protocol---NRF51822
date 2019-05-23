#include "flash.h"



void flash_check(void){



		uint32_t *adresa=(uint32_t *)0x39600;
	
		uint32_t flash_data[4]={1,2,3,4};
	
//		nrf_nvmc_page_erase (*adresa);
//			terminalOut("\r\nradim ");
		
		
		

		//	nrf_nvmc_write_words(*adresa,(uint32_t *)&gzll,sizeof(gzll));
//		nrf_nvmc_write_words(*adresa,flash_data,4);
//	
//		terminalOut("\r\nData after writing on 0x%X: ", adresa);
		for(int i=0; i<4; i++)
		{
				flash_data[i] = *(adresa+i);
				terminalOut("%X ", flash_data[i]);
		}

		if (flash_data[1] != 0xFF && flash_data[2] != 0xFF && flash_data[3] != 0xFF){
			
					terminalOut("\r\n Reading saved configuration.");
			
		} else{
		
								terminalOut("\r\n Memory empty.");
								gzll_init_device();
								uart_puts("Default device mode activated.\r\n");	

		}
		
}

void flash_save(void) {

		uint32_t *adresa=(uint32_t *)0x39600;

		nrf_nvmc_write_words(*adresa,(uint32_t *)&gzll,sizeof(gzll));


}
