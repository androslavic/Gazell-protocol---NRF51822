#include "uart.h"


extern volatile uint8_t slovo=0;

void uart_init(void){

	

                                        

	//Pin select for RXD
  NRF_UART0->PSELRXD = 0xB;

	//Pin select for TXD
  NRF_UART0->PSELTXD = 0xC;	
	
	//Baud rate 9600
	NRF_UART0->BAUDRATE = 0x00275000;

	//interrupt enable on RXDRDY
	NRF_UART0->INTENSET = 4;    
	
//   uint8_t     rx_buf[RX_BUF_SIZE] = {0};                                                    
//   uint8_t     tx_buf[TX_BUF_SIZE] = {0};      

	//UART enable
	 NRF_UART0->ENABLE = 4;
	 
	NVIC_EnableIRQ (UART0_IRQn);
	 
                                                  
	//Start UART receiver
	NRF_UART0->TASKS_STARTRX = 1;
	 
	
	 
	 
	 //Start UART transmitter
	NRF_UART0->TASKS_STARTTX = 1; 

	 
	 	

}

void UART0_IRQHandler (void){


  NVIC_DisableIRQ(UART0_IRQn);    

	NVIC_ClearPendingIRQ(UART0_IRQn);	

	NRF_UART0->EVENTS_RXDRDY = 0;


	
	slovo = (NRF_UART0->RXD);


#if NRF_DEVICE 


	
if (nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&slovo,sizeof(slovo))){ 

		 	NRF_UART0->TXD = slovo;

	 }else{
	 
 	NRF_UART0->TXD = 'X';	 
	 };		
	
	 
#else


		
 if (nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&slovo,sizeof(slovo))){
	 

		 	NRF_UART0->TXD = slovo;

	 }else{
	 
 	NRF_UART0->TXD = 'X';	 

	 };		
	
	 
#endif

	
	
	




	NVIC_EnableIRQ (UART0_IRQn);	

}
