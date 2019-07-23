#ifndef UART_H__
#define UART_H__

#include "nrf51.h"
#include "nrf_gzll.h"
#include "nrf_gzll_constants.h"
#include "gzll.h"
#include "sendData.h"
#include "ringbuf.h"

#define     RX_BUF_SIZE     32   /**< Size of desired RX buffer, must be a power of 2 or ZERO (No FIFO). */
#define     TX_BUF_SIZE     32   /**< Size of desired TX buffer, must be a power of 2 or ZERO (No FIFO) */



void uart_puts(char *word);
void uart_init(void);
void UART0_IRQHandler(void);
extern volatile uint8_t slovo;

extern uint32_t JumpAddress;
typedef  void (*pFunction)(void);
extern pFunction Jump_To_Application;
#define APPLICATION_ADDRESS    0x0000000

#endif //UART_H__

#define NRF_DEVICE  1

