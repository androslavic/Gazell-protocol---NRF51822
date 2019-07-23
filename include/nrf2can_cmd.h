#ifndef __NRF2CAN_CMD_H
#define __NRF2CAN_CMD_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "gzll.h"
#include "cmdline.h"
#include "ringbuf.h"
#include "nrf51.h"
#include "uart.h"
#include "nrf_gzll.h"
#include "cmdline.h"
#include "sendData.h"
#include "flash.h"
#include "i2c.h"


/*Defines maximal number of argument to be used in commands.***********
********Command line parser needs this. If not defined default is 8. **/

#define CMDLINE_MAXARGS 		8
#define APP_INPUT_BUF_SIZE	256

extern	char g_cInput[APP_INPUT_BUF_SIZE];//temp buffer for command line parser
extern unsigned char cBr; //counter for temp. buffer for command line parser
//extern gzllStruct gzll;
extern I2C_config_t i2c_config;


extern uint32_t JumpAddress;
typedef  void (*pFunction)(void);
extern pFunction Jump_To_Application;
#define BOOTLOADER_ADDRESS    0x00032000
extern volatile uint8_t boot;

#endif

