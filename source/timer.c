#include "timer.h"

void start_timer(void)
{		
  NRF_TIMER2->MODE = TIMER_MODE_MODE_Timer;  // Set the timer in Counter Mode
  NRF_TIMER2->TASKS_CLEAR = 1;               // clear the task first to be usable for later
	NRF_TIMER2->PRESCALER = 6;                             //Set prescaler. Higher number gives slower timer. Prescaler = 0 gives 16MHz timer
	NRF_TIMER2->BITMODE = TIMER_BITMODE_BITMODE_16Bit;		 //Set counter to 16 bit resolution
	NRF_TIMER2->CC[0] = 25000;                             //Set value for TIMER2 compare register 0
	NRF_TIMER2->CC[1] = 5;                                 //Set value for TIMER2 compare register 1
		
  // Enable interrupt on Timer 2, both for CC[0] and CC[1] compare match events
	NRF_TIMER2->INTENSET = (TIMER_INTENSET_COMPARE0_Enabled << TIMER_INTENSET_COMPARE0_Pos) | (TIMER_INTENSET_COMPARE1_Enabled << TIMER_INTENSET_COMPARE1_Pos);
  NVIC_EnableIRQ(TIMER2_IRQn);
		
  NRF_TIMER2->TASKS_START = 1;               // Start TIMER2
}
		
/** TIMTER2 peripheral interrupt handler. This interrupt handler is called whenever there it a TIMER2 interrupt
 */
void TIMER2_IRQHandler(void)
{
	uint8_t i;
	if ((NRF_TIMER2->EVENTS_COMPARE[0] != 0) && ((NRF_TIMER2->INTENSET & TIMER_INTENSET_COMPARE0_Msk) != 0))
  {
		
		NRF_TIMER2->EVENTS_COMPARE[0] = 0;           //Clear compare register 0 event	
  		i=0;
			nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&i,1);
	
	}
	
	if ((NRF_TIMER2->EVENTS_COMPARE[1] != 0) && ((NRF_TIMER2->INTENSET & TIMER_INTENSET_COMPARE1_Msk) != 0))
  {
		NRF_TIMER2->EVENTS_COMPARE[1] = 0;           //Clear compare register 1 event
  		i=0;
			nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&i,1); 
	}
}