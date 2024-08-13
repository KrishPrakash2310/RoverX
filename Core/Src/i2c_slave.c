/*
 * i2c_slave.c
 *
 *  Created on: Aug 12, 2024
 *      Author: krish
 */

#include "main.h"
#include <string.h>
#include"i2c_slave.h"
extern I2C_HandleTypeDef hi2c1;
#define size 30
uint8_t RxData[size];

uint8_t rxcount =0;
uint8_t First_Data=0;


void process_data(void)
{


}

void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode)
{
	if(TransferDirection == I2C_DIRECTION_TRANSMIT)  // if the master wants to transmit the data
	{
		if(First_Data==0)
		{
			rxcount =0;
			HAL_I2C_Slave_Sequential_Receive_IT(&hi2c, RxData+rxcount, 1, I2C_FIRST_FRAME);
		}

	}
	else  // master requesting the data is not supported yet
	{
		Error_Handler();
	}
}
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c)
{
	if(First_Data ==0)
	{
		First_Data = 1;
		rxcount++;
		HAL_I2C_Slave_Sequential_Receive_IT(&hi2c, RxData+rxcount, RxData[0], I2C_LAST_FRAME);
	}
	else
	{
		First_Data=0;
		rxcount=RxData[0];
	}

}
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
	HAL_I2C_EnableListen_IT(&hi2c1);
}

