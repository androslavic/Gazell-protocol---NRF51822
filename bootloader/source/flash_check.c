#include "flash.h"


int firmwareUpgrade(void){






	return 0;
};




void flash_check(void){


		uint32_t *adresa=(uint32_t *)ADRESA_FLASH;
	
		uint32_t flash_data = *(adresa);


		if (flash_data == 0xFFFFFFFF)
		{			
				terminalOut("\r\n No new firmware available.\r\n ");
		} 
		else if (flash_data == 0x1)
		{
				terminalOut("\r\n New firmware available.\r\n ");			
				terminalOut("\r\n Starting the firmware upgrade...\r\n ");
			
				if (firmwareUpgrade())
					terminalOut("\r\n Firmware update succesful.\r\n ");
				else
					terminalOut("\r\n Error! Firmware upgrade failed.\r\n ");

		}
		else
				terminalOut("\r\n Error! Unexpected value at firmware upgrade flag.\r\n ");

}

void flash_save(void) {


//		nrf_nvmc_write_words(ADRESA,(const uint32_t *)&gzll,sizeof(gzll));
	
		flash_erase();
	
		nrf_nvmc_write_words(ADRESA_FLASH,&gzll.address,sizeof(gzllStruct));

		flash_read();
}


void flash_load(void){


		uint32_t *adresa=(uint32_t *) ADRESA_FLASH;

		gzllStruct *struktura;
		memcpy(struktura, adresa, sizeof(gzllStruct));
	
		gzll=*struktura;
		gzll_init(gzll);
		terminalOut(" Configuration loaded from memory.\r\n ");

}


void flash_read(void) {

		uint32_t *adresa=(uint32_t *) ADRESA_FLASH;

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
	
		nrf_nvmc_page_erase (ADRESA_FLASH);		

}




void gzll_check(void){


		uint32_t *adresa=(uint32_t *)ADRESA_GZLL;
	
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
								uart_puts("Default device mode activated.\r\n");	

		}
		
}

void gzll_save(void) {


//		nrf_nvmc_write_words(ADRESA_GZLL,(const uint32_t *)&gzll,sizeof(gzll));
	
		flash_erase();
	
		nrf_nvmc_write_words(ADRESA_GZLL,&gzll.address,sizeof(gzllStruct));

		flash_read();
}


void gzll_load(void){


		uint32_t *adresa=(uint32_t *) ADRESA_GZLL;

		gzllStruct *struktura;
		memcpy(struktura, adresa, sizeof(gzllStruct));
	
		gzll=*struktura;
		gzll_init(gzll);
		terminalOut(" Configuration loaded from memory.\r\n ");

}


void gzll_read(void) {

		uint32_t *adresa=(uint32_t *) ADRESA_GZLL;

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




void gzll_erase(void) {
	
		nrf_nvmc_page_erase (ADRESA_GZLL);		

}
