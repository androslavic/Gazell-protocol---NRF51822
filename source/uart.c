#include "uart.h"

extern 	unsigned char buffer[30];
extern	tRingBufObject ringBuf;
extern	unsigned long size;	
extern	unsigned char pucData[30];	
extern	int count;
volatile uint8_t slovo=0;
volatile uint8_t boot=0;


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
	
  NVIC_DisableIRQ(UART0_IRQn);    
	NVIC_ClearPendingIRQ(UART0_IRQn);	
	NRF_UART0->EVENTS_RXDRDY = 0;
	slovo = (NRF_UART0->RXD);
	RingBufWriteOne(&ringBuf, slovo);
	count++;
	
	if (slovo=='\n')
	{
	  RingBufRead(&ringBuf,pucData,count);
		RingBufAdvanceRead(&ringBuf,count);
		terminalIn((char *)pucData);
		count=0;

	}
	NVIC_EnableIRQ (UART0_IRQn);	
}






void uart_puts(char *word){
	
	int i=0;

	NRF_UART0->TXD = 0;
	
	while(word[i]!='\0')
	{
		if (NRF_UART0->EVENTS_TXDRDY==1)
		{
			NRF_UART0->EVENTS_TXDRDY = 0;
			NRF_UART0->TXD = word[i];
			i++;			
		}
	}

}
	


	
	
