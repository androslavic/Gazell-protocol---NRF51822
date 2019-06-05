#include "timer.h"

void start_timer(void)
{		
  NRF_TIMER1->MODE = TIMER_MODE_MODE_Timer;  // Set the timer in Counter Mode
  NRF_TIMER2->MODE = TIMER_MODE_MODE_Timer;  // Set the timer in Counter Mode
  NRF_TIMER1->TASKS_CLEAR = 1;               // clear the task first to be usable for later
  NRF_TIMER2->TASKS_CLEAR = 1;               // clear the task first to be usable for later
	NRF_TIMER1->PRESCALER = 9;                             //Set prescaler. Higher number gives slower timer. Prescaler = 0 gives 16MHz timer
	NRF_TIMER2->PRESCALER = 9;                             //Set prescaler. Higher number gives slower timer. Prescaler = 0 gives 16MHz timer
																						// Prescaler 9 produces 31250 Hz timer frequency => 1 tick = 32 us
	NRF_TIMER1->BITMODE = TIMER_BITMODE_BITMODE_24Bit;		 //Set counter to 16 bit resolution
	NRF_TIMER2->BITMODE = TIMER_BITMODE_BITMODE_24Bit;		 //Set counter to 16 bit resolution
	NRF_TIMER1->CC[0] = 0;                             //Set value for TIMER2 compare register 0
	NRF_TIMER2->CC[0] = 31250;                             //Set value for TIMER2 compare register 0
		
  // Enable interrupt on Timer, both for CC[0] and CC[1] compare match events
	NRF_TIMER1->INTENSET = (TIMER_INTENSET_COMPARE0_Enabled << TIMER_INTENSET_COMPARE0_Pos);
	NRF_TIMER2->INTENSET = (TIMER_INTENSET_COMPARE0_Enabled << TIMER_INTENSET_COMPARE0_Pos) | (TIMER_INTENSET_COMPARE1_Enabled << TIMER_INTENSET_COMPARE1_Pos);
  NVIC_EnableIRQ(TIMER1_IRQn);
  NVIC_EnableIRQ(TIMER2_IRQn);
		
  //NRF_TIMER1->TASKS_START = 1;               // Start TIMER1
  NRF_TIMER2->TASKS_START = 1;               // Start TIMER2
}




/** TIMTER1 peripheral interrupt handler. This interrupt handler is called whenever there it a TIMER1 interrupt
 */
void TIMER1_IRQHandler(void)
{
	
	NRF_TIMER1->EVENTS_COMPARE[0] = 0;           //Clear compare register 0 event	

	
	static int i=0;
//	int y= 10;
	
	++i;
	
	//if (i%y==0)
		
				terminalOut(" Timer1 i: %d!\r\n",i);	

}

/** TIMTER2 peripheral interrupt handler. This interrupt handler is called whenever there it a TIMER2 interrupt
 */
void TIMER2_IRQHandler(void)
{
	char i;
	uint8_t data[NRF_GZLL_CONST_MAX_PAYLOAD_LENGTH]={'0'};	
	uint32_t sizeofdata;
	
	

	
	if ((NRF_TIMER2->EVENTS_COMPARE[0] != 0) && ((NRF_TIMER2->INTENSET & TIMER_INTENSET_COMPARE0_Msk) != 0))
  {
		NRF_TIMER2->EVENTS_COMPARE[0] = 0;           //Clear compare register 0 event	
  		i='\0';
		if(gzll.mode==NRF_GZLL_MODE_DEVICE && NRF_UART0->EVENTS_TXDRDY==1 && nrf_gzll_get_rx_fifo_packet_count(0)<2 && nrf_gzll_get_tx_fifo_packet_count(0)<2){
		

			if (nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&i,1)){ 
			i=0;
			//uart_puts(" device (timer) salje na tx fifo!\r\n");
				
		}else{
			terminalOut(" TX: %d RX: %d\r\n",nrf_gzll_get_tx_fifo_packet_count(0),nrf_gzll_get_rx_fifo_packet_count(0));
			uart_puts(" Greska1,paket nije dodan na tx fifo!\r\n");
			i=nrf_gzll_get_error_code();
			terminalOut("Error code: %d!\r\n",i);	


		};
	}else if(gzll.mode==NRF_GZLL_MODE_HOST && NRF_UART0->EVENTS_TXDRDY==1 && nrf_gzll_get_tx_fifo_packet_count(0)<2 && nrf_gzll_get_rx_fifo_packet_count(0)<2 ){

	
			if (nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&i,1)){
			i=0;
			//uart_puts(" host (timer) salje na tx fifo!\r\n");			
			}else{			
			terminalOut(" TX: %d RX: %d\r\n",nrf_gzll_get_tx_fifo_packet_count(0),nrf_gzll_get_rx_fifo_packet_count(0));
			uart_puts(" Greska2,paket nije dodan na tx fifo!\r\n");
				i=nrf_gzll_get_error_code();
			terminalOut("Error code: %d!\r\n",i);	

		};
	}else if (nrf_gzll_get_tx_fifo_packet_count(0)==3 || nrf_gzll_get_rx_fifo_packet_count(0)==3){
	
			nrf_gzll_fetch_packet_from_rx_fifo	(0,data,&sizeofdata);
			nrf_gzll_fetch_packet_from_rx_fifo	(0,data,&sizeofdata);
			nrf_gzll_fetch_packet_from_rx_fifo	(0,data,&sizeofdata);
//			terminalOut("else  TX: %d RX: %d\r\n",nrf_gzll_get_tx_fifo_packet_count(0),nrf_gzll_get_rx_fifo_packet_count(0));

	}
}
	
	if ((NRF_TIMER2->EVENTS_COMPARE[1] != 0) && ((NRF_TIMER2->INTENSET & TIMER_INTENSET_COMPARE1_Msk) != 0))
  {

		NRF_TIMER2->EVENTS_COMPARE[1] = 0;           //Clear compare register 1 event
  		i='\0';
			//nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&i,1); 
	}
}
