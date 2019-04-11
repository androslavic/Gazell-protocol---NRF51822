#include "nrf2can_cmd.h"


#define APP_INPUT_BUF_SIZE		256
char g_cInput[APP_INPUT_BUF_SIZE];//temp buffer for command line parser
unsigned char cBr = 0; //counter for temp. buffer for command line parser


/*Declaration of functions needed for implementing command line interpreter*/

int CMD_help (int argc, char **argv);
int CMD_can_termination (int argc, char **argv);
int CMD_mcp_change_mode (int argc, char **argv);
int CMD_mcp_set_tx_filter (int argc, char **argv);
int CMD_mcp_set_rx_filter (int argc, char **argv);
int CMD_mcp_verfy_spi (int argc, char **argv);

int CMD_gzll_mode(int argc, char **argv);
int CMD_gzll_pipe(int argc, char **argv);
int CMD_gzll_datarate(int argc, char **argv);
int CMD_gzll_channel(int argc, char **argv);
int CMD_gzll_power(int argc, char **argv);
int CMD_gzll_start(int argc, char **argv);
int CMD_gzll_stop(int argc, char **argv);
int CMD_gzll_lastdata(int argc, char **argv);
int CMD_gzll_send(int argc, char **argv);



 tCmdLineEntry g_sCmdTable[] =
{
    {"help",     					CMD_help,       				"" },
		{"can_termination", 	CMD_can_termination,		"" },
		{"mcp_change_mode", 	CMD_mcp_change_mode,  	"" },
		{"mcp_set_tx_filter", CMD_mcp_set_tx_filter,	"" },
		{"mcp_set_rx_filter", CMD_mcp_set_rx_filter, 	"" },
		{"gzll_mode", 				CMD_gzll_mode,     			"" },
		{"gzll_pipe", 				CMD_gzll_pipe,     			"" },
		{"gzll_datarate", 		CMD_gzll_datarate,     	"" },
		{"gzll_channel", 			CMD_gzll_channel,     	"" },
		{"gzll_power",	 			CMD_gzll_power,     		"" },
		{"gzll_start",	 			CMD_gzll_start,     		"" },
		{"gzll_stop",	 				CMD_gzll_stop,     			"" },
		{"gzll_lastdata",	 		CMD_gzll_lastdata,    	"" },
		{"gzll_send",		 			CMD_gzll_send,     		"" },


		{ 0, 0, 0 }
};

const int NUM_CMD = (sizeof(g_sCmdTable)/sizeof(tCmdLineEntry))-1;



//*****************************************************************************
//
// Command: help
//
// Print the help strings for all commands.
//
//*****************************************************************************
int CMD_help (int argc, char **argv){
    int index;
    
    (void)argc;
    (void)argv;
    
    for (index = 0; index < NUM_CMD; index++)
    {

		}   
		
							uart_puts("  help is on the way \r\n");

    return (0);
}

int CMD_can_termination (int argc, char **argv)
{
//	if(argc == 2)
//	{
//		if(strcmp(argv[1], "on") == 0)
//		{
//			CANTerminationON();
//		}
//		else if(strcmp(argv[1], "off") == 0)
//		{
//			CANTerminationOFF();
//		}
//		else return CMDLINE_INVALID_ARG;
//	}
//	else return CMDLINE_TOO_FEW_ARGS;
//	

return 0;
}

int CMD_mcp_change_mode (int argc, char **argv)
{

	return 0;
}

int CMD_mcp_set_tx_filter (int argc, char **argv)
{

	return 0;
}

int CMD_mcp_set_rx_filter (int argc, char **argv)
{

	return 0;
}
#define CAN_BUFF_SIZE		MAX_DATA_BYTES
//uint8_t can_rx[CAN_BUFF_SIZE], can_tx[CAN_BUFF_SIZE];

int CMD_mcp_verfy_spi (int argc, char **argv)
{
//	int i;
//	int seed; 
//	
//	sscanf(argv[1], "%d", &seed);
//	srand(seed);
//	for(i = 0; i < CAN_BUFF_SIZE; i++)
//	{
//		can_tx[i] = rand() & 0xFF;
//		can_rx[i] = 0xFF;
//	}
	
	//Write to MCP RAM
	//DRV_CANFDSPI_WriteByteArray(DRV_CANFDSPI_INDEX_0, cRAMADDR_START, can_tx, CAN_BUFF_SIZE);
	
	//Read from MCP RAM
	//DRV_CANFDSPI_WriteByteArray(DRV_CANFDSPI_INDEX_0, cRAMADDR_START, can_rx, CAN_BUFF_SIZE);

//	for(i = 0; i < CAN_BUFF_SIZE; i++)
//	{
//		if(can_tx[i] != can_rx[i]) 
//		{
//			uart_printf("RAM check error on index %d, TX: %c, RX: %c\r\n", i, can_tx[i], can_rx[i]);
//		}
//	}

	return 0;
}

int CMD_gzll_mode(int argc, char **argv){
	
	// jedan argument
	// string "device" ili "host"
	
	
	if (strcmp(argv[1],"device")){
		gzll_init_device();	
		return 0;
	}
	
	if (strcmp(argv[1],"host")){
		gzll_init_host();	
		return 0;
	}
	
	//Wrong input
	return 1;
}
int CMD_gzll_pipe(int argc, char **argv){
	
	// dva argumenta
	// redni broj pipe-a
	// zeljena bazna adresa ->string pretvorit u hex
	
	int  number = (int)strtol(argv[1], NULL, 16);   
	int address = (int)strtol(argv[2], NULL, 16); 
	if (number==0){
		nrf_gzll_set_base_address_0 (address);
		return 0;
	}

	if (number>1 && number<8){
		nrf_gzll_set_base_address_1 (address);
		return 0;
	}
	
	//Wrong input
	return 1;
}

int CMD_gzll_datarate(int argc, char **argv){
	
	
	if (strcmp(argv[1],"250k")){
		nrf_gzll_set_datarate	(NRF_GZLL_DATARATE_250KBIT);
		return 0;
	}
	if (strcmp(argv[1],"1M")){
		nrf_gzll_set_datarate	(NRF_GZLL_DATARATE_1MBIT);
		return 0;
	}
	if (strcmp(argv[1],"2M")){
		nrf_gzll_set_datarate	(NRF_GZLL_DATARATE_2MBIT);
		return 0;
	}
	


	return 0;
}
int CMD_gzll_channel(int argc, char **argv){

	return 0;
}
int CMD_gzll_power(int argc, char **argv){

	return 0;
}
int CMD_gzll_start(int argc, char **argv){

	return 0;
}
int CMD_gzll_stop(int argc, char **argv){

	return 0;
}
int CMD_gzll_lastdata(int argc, char **argv){

	return 0;
}
int CMD_gzll_send(int argc, char **argv){

	return 0;
}
