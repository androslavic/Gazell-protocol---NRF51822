#include <stdbool.h>
#include "nrf.h"
#include "gzll.h"


void start_timer(void);
void TIMER2_IRQHandler(void);

extern volatile uint8_t boot;
