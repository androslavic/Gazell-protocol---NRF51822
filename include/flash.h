#ifndef FLASH_H__
#define FLASH_H__

#include "nrf51.h"
#include "sendData.h"
#include "ringbuf.h"
#include "nrf_nvmc.h"




void flash_check(void);
void flash_save(void);
void flash_erase(void);
void flash_read(void);
void flash_load(void);

#define ADRESA 0x0003F600

#endif //FLASH_H__


