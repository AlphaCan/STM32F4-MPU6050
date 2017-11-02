#include "Flash_To_Eeprom.h"
#include <stdint.h>

uint32_t text_buffer[] = {1234567};
#define Length sizeof(text_buffer)
#define SIZE Length/4+((Length%4)?1:0)

uint32_t temp[SIZE] = {0};

uint32_t FLASH_ReadWord(uint32_t faddr)
{
	return *(uint32_t*)faddr; 
}


void EEPROM_WRITE_DATE(uint32_t WriteAddr,uint32_t *pBuffer,uint32_t Data_Length)
{
	HAL_StatusTypeDef Flash_Status;
	FLASH_EraseInitTypeDef FLASH_EraseInit;
	
//	uint8_t Data_Length = sizeof(pBuffer);//获取数据长度
	uint32_t Start_Addr = 0;
	uint32_t End_Addr =0;
	uint32_t PageError = 0;
	
	if(WriteAddr<FLASH_BASE_ADDRESS||WriteAddr%4)return ;//非法地址时
	
	HAL_FLASH_Unlock();//FLASH 解锁
	
	Start_Addr = WriteAddr;
	End_Addr = WriteAddr + Data_Length*4;
	
	if(Start_Addr < 0x1FFFF000 )
	{
		while(Start_Addr<End_Addr)
		{
			if(FLASH_ReadWord(Start_Addr)!=0xFFFF)
			{
				FLASH_EraseInit.TypeErase = FLASH_TYPEERASE_PAGES;
				FLASH_EraseInit.PageAddress = FLASH_BASE_ADDRESS;
				FLASH_EraseInit.NbPages = 1;
				if(HAL_FLASHEx_Erase(&FLASH_EraseInit,&PageError)!=HAL_OK)
					break;
				else
					Start_Addr +=4;
			}
			FLASH_WaitForLastOperation(FLASH_WAITE_TIME);
		}
	}
	
	
	Flash_Status = FLASH_WaitForLastOperation(FLASH_WAITE_TIME);
	if(Flash_Status == HAL_OK)
	{
		while(Start_Addr<End_Addr)
		{
			if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Start_Addr,*pBuffer)!=HAL_OK)//写入数据出错
			{
				break;
			}
			Start_Addr += 4;
			pBuffer++;
		}
	}
	
	HAL_FLASH_Lock();//FLASH上锁
	
}


void EEPROM_READ_DATE(uint32_t ReadAddr,uint32_t *pBuffer,uint32_t Data_Length)
{
	for(uint32_t i=0;i<Data_Length;i++)
	{
		pBuffer[i] = FLASH_ReadWord(ReadAddr);
		ReadAddr += 4;
	}
	
	
}


void EEPROM_Init(void)
{

//	printf("STM32数据存储实验\r\n");
	
//	printf("写入的数据是：%s",text_buffer);
	
	EEPROM_WRITE_DATE(FLASH_BASE_ADDRESS,(uint32_t*)text_buffer,SIZE);
	
//	printf("\r\n正在读取数据：\r\n");
	
	EEPROM_READ_DATE(FLASH_BASE_ADDRESS,(uint32_t*)temp,SIZE);
	
	printf("读取的数据是：%d\r\n",temp);
	
}










