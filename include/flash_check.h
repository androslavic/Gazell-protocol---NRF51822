#ifndef FLASH_H__
#define FLASH_H__

#include "nrf51.h"
#include "sendData.h"
#include "ringbuf.h"
#include "nrf_nvmc.h"



void flash_check(void);
void flash_save(void);
void flash_erase(void);



#endif //FLASH_H__


