#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "nrf.h"                        // Device header
#include "RTE_Components.h"             // Component selection
#include "system_nrf51.h"               // NordicSemiconductor::Device:Startup
#include "startup_config.h"             // NordicSemiconductor::Device:StartupConfig
#include "uart.h"
#include "clock.h"
#include "gzll.h"
#include "cmdline.h"
#include "ringbuf.h"
#include "nrf2can_cmd.h"
#include "sendData.h"

