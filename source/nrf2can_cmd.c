#include "nrf2can_cmd.h"


#define APP_INPUT_BUF_SIZE		256
char g_cInput[APP_INPUT_BUF_SIZE];//temp buffer for command line parser
unsigned char cBr = 0; //counter for temp. buffer for command line parser

gzllStruct gzll;
nrf_gzll_host_rx_info_t rx_info;
nrf_gzll_device_tx_info_t tx_info;

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
int CMD_gzll_default_host(int argc, char **argv);
int CMD_gzll_default_device(int argc, char **argv);
int CMD_gzll_rssi(int argc, char **argv);
int CMD_gzll_tr(int argc, char **argv);
int CMD_gzll_xx(int argc, char **argv);
int CMD_flash_save(int argc, char **argv);
int CMD_flash_read(int argc, char **argv);


 tCmdLineEntry g_sCmdTable[] =
{
    {"help",     					CMD_help,       					"" },
		{"can",								CMD_can_termination,			"" },
		{"mcp_change_mode", 	CMD_mcp_change_mode,  		"" },
		{"mcp_set_tx_filter", CMD_mcp_set_tx_filter,		"" },
		{"mcp_set_rx_filter", CMD_mcp_set_rx_filter, 		"" },
		{"mode", 						  CMD_gzll_mode,     				"" },
		{"pipe",		   				CMD_gzll_pipe,     				"" },
		{"datarate", 					CMD_gzll_datarate,    	 	"" },
		{"channel", 					CMD_gzll_channel,     		"" },
		{"power",				 			CMD_gzll_power,     			"" },
		{"start",	 						CMD_gzll_start,     			"" },
		{"stop",	 						CMD_gzll_stop,     				"" },
		{"gzll_lastdata",	 		CMD_gzll_lastdata,    		"" },
		{"send",				 			CMD_gzll_send,     				"" },
		{"save",				 			CMD_flash_save,    				"" },
		{"read",				 			CMD_flash_read,    				"" },
		{"dh",						 		CMD_gzll_default_host,		"" },
		{"dd",								CMD_gzll_default_device,	"" },
		{"rssi",							CMD_gzll_rssi,						"" },
		{"tr",								CMD_gzll_tr,							"" },
		{"xx",								CMD_gzll_xx,							"" },

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

		
		uart_puts("  Command list: \r\n");
		uart_puts("{\"mode\",               CMD_gzll_mode,            \"device / host\" }, \r\n");
		uart_puts("{\"pipe\",               CMD_gzll_pipe,            \"\" }, \r\n");
		uart_puts("{\"datarate\",           CMD_gzll_datarate,        \"\" }, \r\n");
		uart_puts("{\"channel\",            CMD_gzll_channel,         \"\" }, \r\n");
		uart_puts("{\"power\",              CMD_gzll_power,           \"\" }, \r\n");
		uart_puts("{\"start\",              CMD_gzll_start,           \"\" }, \r\n");
		uart_puts("{\"stop\",               CMD_gzll_stop,            \"\" }, \r\n");
		uart_puts("{\"gzll_lastdata\",      CMD_gzll_lastdata,        \"\" }, \r\n");
		uart_puts("{\"send\",               CMD_gzll_send,            \"\" }, \r\n");
		uart_puts("{\"dh\",                 CMD_gzll_default_host,    \"\" }, \r\n");
		uart_puts("{\"dd\",                 CMD_gzll_default_device,  \"\" }, \r\n");
		uart_puts("{\"save\",               CMD_flash_save, 					\"\" }, \r\n");
		uart_puts("{\"read\",               CMD_flash_read, 					\"\" }, \r\n");
//		uart_puts("{\"rssi\",               CMD_gzll_rssi, 					  \"\" }, \r\n");
//		uart_puts("{\"tr\",                 CMD_gzll_tr, 							\"\" } \r\n");

    return 0;
}

int CMD_can_termination (int argc, char **argv)
{
	if(argc == 2)
	{
		if(strcmp(argv[1], "on") == 0)
		{
		uart_puts("CANTerminationON();\r\n");	
		}
		else if(strcmp(argv[1], "off") == 0)
		{
		uart_puts("CANTerminationOFF();\r\n");	
		}
		else {
			uart_puts("CMDLINE_INVALID_ARG\r\n");	
			return CMDLINE_INVALID_ARG;
		}
	}
	else{
		uart_puts("CMDLINE_TOO_FEW_ARGS\r\n");	
		return CMDLINE_TOO_FEW_ARGS;
	}	

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
	if(argc == 2){	
		if (strcmp(argv[1],"device") == 0){
			uart_puts("nrf_gzll_mode_t device;\r\n");		
			gzll.mode=NRF_GZLL_MODE_DEVICE;
			return 0;
		}else if (strcmp(argv[1],"host") == 0){
			uart_puts("nrf_gzll_mode_t host;\r\n");		
			gzll.mode=NRF_GZLL_MODE_HOST;
			return 0;
		}else {
			uart_puts("CMDLINE_INVALID_ARG\r\n");	
			return CMDLINE_INVALID_ARG;
		}
	}else{
		uart_puts("CMDLINE_TOO_FEW_ARGS\r\n");	
		return CMDLINE_TOO_FEW_ARGS;
		}
	}



int CMD_gzll_pipe(int argc, char **argv){
	
	// dva argumenta
	// redni broj pipe-a
	// zeljena bazna adresa ->string pretvorit u hex
	

	
if(argc == 3){	

	int  number = (int)strtol(argv[1], NULL, 16);   
	uint32_t address = (uint32_t)strtol(argv[2], NULL, 16); 
	if (number>-1 && number<8){
		terminalOut("gzll.address = 0x%x;\r\n",address);	
		gzll.address=address;
		terminalOut("gzll.pipe = %d;\r\n",number);	
		gzll.pipe = number;
		return 0;
	}else {
			uart_puts("CMDLINE_INVALID_ARG\r\n");	
			return CMDLINE_INVALID_ARG;
		}
	
	}else{
		uart_puts("CMDLINE_TOO_FEW_ARGS\r\n");	
		return CMDLINE_TOO_FEW_ARGS;
		}
}

int CMD_gzll_datarate(int argc, char **argv){
	
	if(argc == 2){	
	if (strcmp(argv[1],"250k")==0){
		gzll.data_rate=NRF_GZLL_DATARATE_250KBIT;
		uart_puts("NRF_GZLL_DATARATE_250KBIT\r\n");	
		return 0;
	}else	if (strcmp(argv[1],"1M")==0){
		gzll.data_rate=NRF_GZLL_DATARATE_1MBIT;
		uart_puts("NRF_GZLL_DATARATE_1MBIT\r\n");	
		return 0;
	}else	if (strcmp(argv[1],"2M")==0){
		gzll.data_rate=NRF_GZLL_DATARATE_2MBIT;
		uart_puts("NRF_GZLL_DATARATE_2MBIT\r\n");	
		return 0;
	}else {
		uart_puts("CMDLINE_INVALID_ARG\r\n");	
		return CMDLINE_INVALID_ARG;
		}
	}else{
		uart_puts("CMDLINE_TOO_FEW_ARGS\r\n");	
		return CMDLINE_TOO_FEW_ARGS;
		}
}


int CMD_gzll_channel(int argc, char **argv){

	return 0;
}
int CMD_gzll_power(int argc, char **argv){
	
	nrf_gzll_set_tx_power(NRF_GZLL_TX_POWER_4_DBM );
	
	if(argc == 2){	
	if (strcmp(argv[1],"4")==0){
		gzll.power=NRF_GZLL_TX_POWER_4_DBM;
		uart_puts("NRF_GZLL_TX_POWER_4_DBM\r\n");	
		return 0;
	}else	if (strcmp(argv[1],"0")==0){
		gzll.power=NRF_GZLL_TX_POWER_0_DBM;
		uart_puts("NRF_GZLL_TX_POWER_0_DBM\r\n");
		return 0;
	}else	if (strcmp(argv[1],"-4")==0){
		gzll.power=NRF_GZLL_TX_POWER_N4_DBM;
		uart_puts("NRF_GZLL_TX_POWER_N4_DBM\r\n");
		return 0;
	}else	if (strcmp(argv[1],"-8")==0){
		gzll.power=NRF_GZLL_TX_POWER_N8_DBM;
		uart_puts("NRF_GZLL_TX_POWER_N8_DBM\r\n");
		return 0;
	}else	if (strcmp(argv[1],"-12")==0){
		gzll.power=NRF_GZLL_TX_POWER_N12_DBM;
		uart_puts("NRF_GZLL_TX_POWER_N12_DBM\r\n");
		return 0;
	}else	if (strcmp(argv[1],"-16")==0){
		gzll.power=NRF_GZLL_TX_POWER_N16_DBM;
		uart_puts("NRF_GZLL_TX_POWER_N16_DBM\r\n");
		return 0;
	}else	if (strcmp(argv[1],"-20")==0){
		gzll.power=NRF_GZLL_TX_POWER_N20_DBM;
		uart_puts("NRF_GZLL_TX_POWER_N20_DBM\r\n");
		return 0;
	}else {
		uart_puts("CMDLINE_INVALID_ARG\r\n");	
		return CMDLINE_INVALID_ARG;
		}
	}else{
		uart_puts("CMDLINE_TOO_FEW_ARGS\r\n");	
		return CMDLINE_TOO_FEW_ARGS;
		}
}
int CMD_gzll_start(int argc, char **argv){
	
	gzll_init(gzll);
	uart_puts("Gazell initialised.\r\n");	

	return 0;
}
int CMD_gzll_stop(int argc, char **argv){

	nrf_gzll_disable();
	uart_puts("Gazell disabled.\r\n");	
	return 0;
}
int CMD_gzll_lastdata(int argc, char **argv){

	return 0;
}
int CMD_gzll_send(int argc, char **argv){
	
		int i=0,count=0; 
		char Data[50]={0};
		
		for (i=0;i<argc-1;i++){
			strcat(Data, argv[i+1]);
			if (i<argc-2)
			strcat(Data, " ");
			else
			strcat(Data, "\r\n");

		}

		
		i=0;
		while (Data[i]!='\0'){
			count++;
				i++;}
		
				//terminalOut(" TX: %d RX: %d\r\n",nrf_gzll_get_tx_fifo_packet_count(0),nrf_gzll_get_rx_fifo_packet_count(0));		

		if (nrf_gzll_add_packet_to_tx_fifo	(	0,(uint8_t *)&Data,count*sizeof(uint8_t))){ 
			
		}else{
			uart_puts(" Greska3,paket nije dodan na tx fifo!\r\n");
				i=nrf_gzll_get_error_code();
			terminalOut("Error code: %d!\r\n",i);	

		};
		
	return 0;
}


int CMD_gzll_default_host(int argc, char **argv){

		gzll_init_host();
		uart_puts("Default host mode activated.\r\n");	
		return 0;
		}

int CMD_gzll_default_device(int argc, char **argv){
	
		gzll_init_device();
		uart_puts("Default device mode activated.\r\n");	
		return 0;
		}

		
int CMD_gzll_rssi(int argc, char **argv){

	if(gzll.mode==NRF_GZLL_MODE_HOST)
		terminalOut("Host RSSI: %d!\r\n",rx_info.rssi);	
	if(gzll.mode==NRF_GZLL_MODE_DEVICE)
		terminalOut("Device RSSI: %d!\r\n",tx_info.rssi);	

	return 0;


}


 int CMD_gzll_tr(int argc, char **argv){
terminalOut(" TX: %d RX: %d\r\n",nrf_gzll_get_tx_fifo_packet_count(0),nrf_gzll_get_rx_fifo_packet_count(0));

	return 0;

}
 
 int CMD_gzll_xx(int argc, char **argv){


	uint8_t data[NRF_GZLL_CONST_MAX_PAYLOAD_LENGTH]={'0'};	
	uint32_t sizeofdata;


		
	if (nrf_gzll_fetch_packet_from_rx_fifo	(0,data,&sizeofdata)){
	

					char formatData[30]={0};

					if (isalnum(data[0])){
					strncpy(formatData, (char*)data, sizeofdata-2);
					formatData[sizeofdata-1]='\0';
					uart_puts("Device:");
					uart_puts((char*)data);
					CmdLineProcess(formatData);
					
					}


		
	}
		return 0;

}

