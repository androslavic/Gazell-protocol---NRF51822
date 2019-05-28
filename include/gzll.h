#ifndef GZLL_H__
#define GZLL_H__

#include "nrf51.h"
#include "nrf_gzll.h"
#include "nrf_gzll_constants.h"
#include "uart.h"
#include "ctype.h"
#include "cmdline.h"
#include "string.h"


typedef struct
{
//  base_address	The 4 byte base address. All bytes are used.	
		uint32_t address;
	
//  Enumerator used for selecting Gazell mode.
//  NRF_GZLL_MODE_DEVICE 	Device mode.
//  NRF_GZLL_MODE_HOST 		Host mode.
//  NRF_GZLL_MODE_SUSPEND  Suspend mode ("disabled with timer running")
		nrf_gzll_mode_t mode;
	

//	This value is a bitmap, and each bit corresponds to a given pipe number.
//	Bit 0 set to "1" enables pipes 0, bit 1 set to "1" enables pipe 1 and so forth.
//	The maximum number of pipes is defined by NRF_GZLL_CONST_PIPE_COUNT.
	  uint8_t pipe;		
	
//  The length in microseconds of a Gazell link layer timeslot.
		uint32_t period;		

//  Set the number of timeslots that Gazell shall reside on a single channel
//	before switching to another channel.	
		uint32_t 	timeslots;	
		
//  The address prefix byte.		
		uint8_t address_prefix;
		
//  Set the table of Radio Frequency (RF) channels.
//  The valid channels are in the range 0 <= channel <= 125,
//	where the actual centre frequency is (2400 + channel) MHz.
//  The maximum channel table size is defined by NRF_GZLL_CONST_MAX_CHANNEL_TABLE_SIZE.
		uint8_t poljeKanala[8];		
		
//	The size of the channel table.
		uint8_t brojKanala;		

//  Set the radio datarate.
		nrf_gzll_datarate_t data_rate;

//Enumerator used for selecting the transmit (TX) power.
		nrf_gzll_tx_power_t power;	
		
}
gzllStruct;

	extern gzllStruct gzll;
	void gzll_init( gzllStruct gzll);


	void gzll_init_host (void); 
	void gzll_init_device (void); 

#endif 
