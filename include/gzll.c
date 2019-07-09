#include "gzll.h"


	void gzll_init_host (void){
		
			uint8_t poljeKanala[3]={10,20,30};
		
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
			
			nrf_gzll_enable();
	}
	
	
	
	
	void gzll_init_device (void){
		
			uint8_t poljeKanala[3]={10,20,30};

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

			nrf_gzll_enable();



	}
	
	void nrf_gzll_host_rx_data_ready(uint32_t pipe, nrf_gzll_host_rx_info_t rx_info){
		

	uint8_t data[NRF_GZLL_CONST_MAX_PAYLOAD_LENGTH]={'0'};	
	uint32_t sizeofdata;
	int16_t i=0;


		
	if (nrf_gzll_fetch_packet_from_rx_fifo	(pipe,data,&sizeofdata)){
	
		

		for (i=0;i<sizeofdata;i++){
		
				NRF_UART0->TXD = data[i];

		}
		
	}
};
	
	void nrf_gzll_device_tx_failed	(	uint32_t 	pipe,nrf_gzll_device_tx_info_t 	tx_info ){
				NRF_UART0->TXD = 'F';


	
};
	
	void nrf_gzll_device_tx_success	(	uint32_t 	pipe,nrf_gzll_device_tx_info_t 	tx_info ){


	uint8_t data[NRF_GZLL_CONST_MAX_PAYLOAD_LENGTH];	
	uint32_t sizeofdata;
	int16_t i=0;





		
	if (nrf_gzll_fetch_packet_from_rx_fifo	(pipe,data,&sizeofdata)){

		for (i=0;i<sizeofdata;i++){
		
				NRF_UART0->TXD = data[i];
		
		}

	};
	
};

	void nrf_gzll_disabled	(	void ){

};		





 
