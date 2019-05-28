#include "flash.h"



void flash_check(void){


		uint32_t *adresa=(uint32_t *)ADRESA;
	
		uint32_t flash_data[sizeof(gzllStruct)];
		
					for(int i=0; i<sizeof(gzllStruct); i++)
					{
							flash_data[i] = *(adresa+i);
					}

		if (flash_data[1] != 0xFFFFFFFF && flash_data[2] != 0xFFFFFFFF && flash_data[3] != 0xFFFFFFFF){
			
					terminalOut("\r\n Reading saved configuration.\r\n ");
			
					for(int i=0; i<sizeof(gzllStruct); i++)
					{
							flash_data[i] = *(adresa+i);
							terminalOut("%X ", flash_data[i]);
					}
					terminalOut("\r\n ");
							flash_load();


		} else{
		
								terminalOut("\r\n Memory empty.\r\n ");
								gzll_init_device();
								uart_puts(" Default device mode activated.\r\n");	

		}
		
}

void flash_save(void) {


//		nrf_nvmc_write_words(ADRESA,(const uint32_t *)&gzll,sizeof(gzll));
	
		flash_erase();
	
		nrf_nvmc_write_words(ADRESA,&gzll.address,sizeof(gzllStruct));

		flash_read();
}


void flash_load(void){


		uint32_t *adresa=(uint32_t *) ADRESA;

		gzllStruct *struktura;
		memcpy(struktura, adresa, sizeof(gzllStruct));
	
		gzll=*struktura;
		gzll_init(gzll);
		terminalOut(" Configuration loaded from memory.\r\n ");

}


void flash_read(void) {

		uint32_t *adresa=(uint32_t *) ADRESA;

		int i;
		uint32_t flash_data[sizeof(gzllStruct)]={0};

	
			for(i=0; i<sizeof(gzllStruct); i++)
		{
				flash_data[i] = *(adresa+i);
				terminalOut("%X ", flash_data[i]);
		}
			terminalOut("\r\n ");

//		gzllStruct *gzll_data;
//	
//		gzll_data=(gzllStruct *) *adresa;

//		terminalOut("mode: ", gzll_data->mode);


}




void flash_erase(void) {
	
		nrf_nvmc_page_erase (ADRESA);		

}
