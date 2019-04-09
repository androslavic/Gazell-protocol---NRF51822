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

 tCmdLineEntry g_sCmdTable[] =
{
    {"help",     					CMD_help,       				"" },
		{"can_termination", 	CMD_can_termination,		"" },
		{"mcp_change_mode", 	CMD_mcp_change_mode,  	"" },
		{"mcp_set_tx_filter", CMD_mcp_set_tx_filter,	"" },
		{"mcp_set_rx_filter", CMD_mcp_set_rx_filter, 	"" },
		{"mcp_verfy_spi", 		CMD_mcp_verfy_spi,     	"" },
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
//	return 0;
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

//	return 0;
}

