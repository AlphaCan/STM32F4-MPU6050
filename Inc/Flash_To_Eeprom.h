#ifndef __FLASH_TO_EEPROM_H
#define __FLASH_TO_EEPROM_H
#include "stm32f1xx_hal.h"
#include "usart.h"


#define FLASH_BASE_ADDRESS 0x08020800    //共512K的FLASH容量，将前10K的容量作为程序存储，后面的作为数据存储
#define FLASH_WAITE_TIME  50000



void EEPROM_WRITE_DATE(uint32_t WriteAddr,uint32_t *pBuffer,uint32_t Data_Length);
void EEPROM_READ_DATE(uint32_t ReadAddr,uint32_t *pBuffer,uint32_t Data_Length);
void EEPROM_Init(void);
uint32_t FLASH_ReadWord(uint32_t faddr);













#endif













