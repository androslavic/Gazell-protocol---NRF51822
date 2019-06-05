#include "spi.h"


void spi_event_handler(nrf_drv_spi_evt_t const * p_event)
{
	
	
    if (m_rx_buf[0] != 0)
    {
							terminalOut(" SPI : %s!\r\n",m_rx_buf);	
    }else{
							terminalOut(" SPI : prazan!\r\n");	
		}
		
			    spi_xfer_done = true;	

}


void spi_init (void){


//    nrf_drv_spi_config_t spi_config = NRF_DRV_SPI_DEFAULT_CONFIG;
//    spi_config.ss_pin   = SPI_SS_PIN;
//    spi_config.miso_pin = SPI_MISO_PIN;
//    spi_config.mosi_pin = SPI_MOSI_PIN;
//    spi_config.sck_pin  = SPI_SCK_PIN;
//		nrf_drv_spi_init(&spi, &spi_config, spi_event_handler);
//								terminalOut("  tup !\r\n");	

}


