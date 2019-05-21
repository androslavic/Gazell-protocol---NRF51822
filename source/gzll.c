#include "gzll.h"


	void gzll_init( gzllStruct gzll){
	
			nrf_gzll_disable();
			nrf_gzll_init	(gzll.mode)	;

			if (gzll.pipe==1)
					nrf_gzll_set_base_address_0 (gzll.address);
			else
					nrf_gzll_set_base_address_1 (gzll.address);
		
			if (gzll.mode==NRF_GZLL_MODE_HOST)
				nrf_gzll_set_rx_pipes_enabled (1);

	    nrf_gzll_set_timeslot_period	(gzll.period);
			nrf_gzll_set_timeslots_per_channel (gzll.timeslots);
		  nrf_gzll_set_address_prefix_byte	(	gzll.pipe, gzll.address_prefix);
			nrf_gzll_set_datarate	(gzll.data_rate);
			nrf_gzll_set_tx_power(gzll.power);
			nrf_gzll_set_channel_table	(	gzll.poljeKanala,gzll.brojKanala);
		  nrf_gzll_set_device_channel_selection_policy	(NRF_GZLL_DEVICE_CHANNEL_SELECTION_POLICY_USE_SUCCESSFUL);
	  	nrf_gzll_set_xosc_ctl (NRF_GZLL_XOSC_CTL_AUTO );		
			nrf_gzll_enable();

	} 

	void gzll_init_host (void){
	
			nrf_gzll_disable();
		
			uint8_t poljeKanala[3]={10,20,30,40};
		
			nrf_gzll_init	(	NRF_GZLL_MODE_HOST)	;

			nrf_gzll_set_base_address_0 (0x00ABCDEF);
		
			// pipe 0 shall listen for packets in Host mode
			nrf_gzll_set_rx_pipes_enabled (1);
		
	    nrf_gzll_set_timeslot_period	(2700);
		
  		nrf_gzll_set_device_channel_selection_policy	(NRF_GZLL_DEVICE_CHANNEL_SELECTION_POLICY_USE_SUCCESSFUL);
	
			nrf_gzll_set_timeslots_per_channel (3);
		
			nrf_gzll_set_channel_table	(	poljeKanala,sizeof(poljeKanala));
		
			nrf_gzll_set_datarate	(NRF_GZLL_DATARATE_250KBIT);
		
		  nrf_gzll_set_address_prefix_byte	(	0, 0xAA);
		
	  	nrf_gzll_set_xosc_ctl (NRF_GZLL_XOSC_CTL_AUTO );

			gzll.mode=NRF_GZLL_MODE_HOST;

			nrf_gzll_enable();
	}
	
	
	
	
	void gzll_init_device (void){
		
			nrf_gzll_disable();

			uint8_t poljeKanala[3]={10,20,30,40};

			nrf_gzll_init	(	NRF_GZLL_MODE_DEVICE)	;

			nrf_gzll_set_base_address_0 (0x00ABCDEF);

			nrf_gzll_set_timeslot_period	(2700);

		  nrf_gzll_set_device_channel_selection_policy	(NRF_GZLL_DEVICE_CHANNEL_SELECTION_POLICY_USE_SUCCESSFUL);

		  nrf_gzll_set_timeslots_per_channel (3);

			nrf_gzll_set_channel_table	(	poljeKanala,sizeof(poljeKanala));

		  nrf_gzll_set_tx_power(NRF_GZLL_TX_POWER_N8_DBM );

			nrf_gzll_set_datarate	(NRF_GZLL_DATARATE_250KBIT);

   		nrf_gzll_set_address_prefix_byte	(	0, 0xAA);
		
  		nrf_gzll_set_xosc_ctl (NRF_GZLL_XOSC_CTL_AUTO );

			gzll.mode=NRF_GZLL_MODE_DEVICE;
			
			nrf_gzll_enable();



	}
	
	void nrf_gzll_host_rx_data_ready(uint32_t pipe, nrf_gzll_host_rx_info_t rx_info){
		

	uint8_t data[NRF_GZLL_CONST_MAX_PAYLOAD_LENGTH]={'0'};	
	uint32_t sizeofdata;


		
	if (nrf_gzll_fetch_packet_from_rx_fifo	(pipe,data,&sizeofdata)){
	

					char formatData[30]={0};

					if (isalnum(data[0])){
					strncpy(formatData, (char*)data, sizeofdata-2);
					formatData[sizeofdata-1]='\0';
					uart_puts("Device:");
					uart_puts((char*)data);
					CmdLineProcess(formatData);
					
					}


		
	}
};
	
	void nrf_gzll_device_tx_failed	(	uint32_t 	pipe,nrf_gzll_device_tx_info_t 	tx_info ){
		uart_puts("Error: TX Device failed");
	
};
	
	void nrf_gzll_device_tx_success	(	uint32_t 	pipe,nrf_gzll_device_tx_info_t 	tx_info ){


	uint8_t data[NRF_GZLL_CONST_MAX_PAYLOAD_LENGTH];	
	uint32_t sizeofdata;

		
	if (nrf_gzll_fetch_packet_from_rx_fifo	(pipe,data,&sizeofdata)){
		
		
					char formatData[30]={0};

					if (isalnum(data[0])){
					strncpy(formatData, (char*)data, sizeofdata-2);
					formatData[sizeofdata-1]='\0';
					uart_puts("Host:");
					uart_puts((char*)data);
					CmdLineProcess(formatData);
					


					}


	};
	
};

	void nrf_gzll_disabled	(	void ){

};		





 
