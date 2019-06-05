#include "nrf_gpio.h"
#include "uart.h"
#include "app_util_platform.h"
#include "nrf_gpio.h"
#include <string.h>



#define NRF_LOG_MODULE_NAME "APP"

#define SPI_INSTANCE  0 /**< SPI instance index. */
static const nrf_drv_spi_t spi = NRF_DRV_SPI_INSTANCE(SPI_INSTANCE);  /**< SPI instance. */
static volatile bool spi_xfer_done;  /**< Flag used to indicate that SPI instance completed the transfer. */

#define TEST_STRING "Nordic"
#define TEST_STRING2 "ALOALOA"
static uint8_t       m_tx_buf[] = TEST_STRING;           /**< TX buffer. */
static uint8_t       m_rx_buf[] = TEST_STRING2;    /**< RX buffer. */
static const uint8_t m_length = sizeof(m_tx_buf);        /**< Transfer length. */




void spi_init (void);
