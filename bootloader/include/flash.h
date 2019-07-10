#ifndef FLASH_H__
#define FLASH_H__

#include "nrf51.h"
#include "gzll.h"
#include "sendData.h"
#include "ringbuf.h"
#include "nrf_nvmc.h"




void flash_check(void);
void flash_save(void);
void flash_erase(void);
void flash_read(void);
void flash_load(void);

void gzll_check(void);
void gzll_save(void);
void gzll_erase(void);
void gzll_read(void);
void gzll_load(void);

int firmwareUpgrade(void);


#define ADRESA_GZLL 0x0003F600
#define ADRESA_FLASH 0x0003F5FC

#endif //FLASH_H__


