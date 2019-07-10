#include "uart.h"


extern 	unsigned char buffer[30];
extern	tRingBufObject ringBuf;
extern	unsigned long size;	
extern	unsigned char pucData[30];	
extern	int count;
volatile uint8_t slovo=0;


#define APPLICATION_ADDRESS    0x00010000

	void uart_init(void){                             

  NRF_UART0->PSELRXD = 0xB;
  NRF_UART0->PSELTXD = 0xC;	
	NRF_UART0->BAUDRATE = 0x00275000;
	NRF_UART0->INTENSET = 4;    
	NRF_UART0->ENABLE = 4; 
	NVIC_EnableIRQ (UART0_IRQn);	                                                 
	NRF_UART0->TASKS_STARTRX = 1;
	NRF_UART0->TASKS_STARTTX = 1;   	

}

void UART0_IRQHandler (void){
	

	uint32_t JumpAddress;
	
	JumpAddress = *(__IO uint32_t*) (0x48 + APPLICATION_ADDRESS);	

	Jump_To_Application = (pFunction) JumpAddress;
	
	Jump_To_Application();



}




void uart_puts(char *word){
	
	
	NRF_UART0->TXD = 0;

	int i=0;
	
	while(word[i]!='\0'){
		
		if (NRF_UART0->EVENTS_TXDRDY==1){
			
			    NRF_UART0->EVENTS_TXDRDY = 0;
					NRF_UART0->TXD = word[i];
					i++;			
		}
	}

}
	


	
	
