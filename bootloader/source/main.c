#include "main.h"



void system_init(void)
{
	clock_init();
	uart_init();	
	RingBufInit(&ringBuf, buffer,size);
	
	//upogonit spi
	
	//flash_check() je za gzll parametre,nebitan u bootloaderu 
	//flash_check();
	
	//bootloader preko spi prima .bin file - FW i upisuje ga direktno
	//od adrese 0x0 na gore koristeci ymodem protokol

}





	
int main(void)
{
	int i,j;
  uint8_t c;

	system_init();	
	terminalOut("\n\r Bootloader initialised!.\n\r");	

	__disable_irq();

	for (i=0;i<4;i++)
	{
		if(Receive_Byte(&c,NAK_TIMEOUT)!=0)
		{
			Send_Byte('C');
		}

//		for(j=0;j<5000000;j++);
	}
	for (i=0;i<16;i++)
	{
		if(Receive_Byte(&c,NAK_TIMEOUT)!=0)
		{
			Send_Byte(ACK);
		}

//for(j=0;j<5000000;j++);
	}
//	while(NRF_UART0->EVENTS_TXDRDY==0)
//	{
//		//do nothing
//	} 
//				
//	NRF_UART0->TXD = c;		
//	
////Receive_Packet
//	
//	
//		while(1)
//	{		
//			Send_Byte(ACK);
//	}
//	
 

	JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
	Jump_To_Application = (pFunction) JumpAddress;

	__set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
		
	Jump_To_Application();
		
		
	
	
  while (1) 
	{
			++i;	
  }	
	
}
	
	



