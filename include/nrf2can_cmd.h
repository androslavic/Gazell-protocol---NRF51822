#ifndef __NRF2CAN_CMD_H
#define __NRF2CAN_CMD_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "cmdline.h"
#include "ringbuf.h"
#include "nrf51.h"
#include "uart.h"




/*Defines maximal number of argument to be used in commands.***********
********Command line parser needs this. If not defined default is 8. **/

#define CMDLINE_MAXARGS 		8
#define APP_INPUT_BUF_SIZE	256

extern	char g_cInput[APP_INPUT_BUF_SIZE];//temp buffer for command line parser
extern unsigned char cBr; //counter for temp. buffer for command line parser


#endif

