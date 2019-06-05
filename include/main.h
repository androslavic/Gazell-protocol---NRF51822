#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "nrf.h"                        // Device header
#include "RTE_Components.h"             // Component selection
#include "system_nrf51.h"               // NordicSemiconductor::Device:Startup
#include "startup_config.h"             // NordicSemiconductor::Device:StartupConfig
#include "gzll.h"
#include "uart.h"
#include "clock.h"
#include "cmdline.h"
#include "ringbuf.h"
#include "nrf2can_cmd.h"
#include "sendData.h"
#include "timer.h"
#include "flash.h"
#include "i2c.h"


unsigned char buffer[30]={0};
tRingBufObject ringBuf;
unsigned long size=30;	
unsigned char pucData[30]={0};	
int count=0;
	
