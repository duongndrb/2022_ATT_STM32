/*
 * sht3x.h
 *
 *  Created on: Jun 30, 2022
 *      Author: inhuo
 */

#ifndef SHT3X_H_
#define SHT3X_H_

#include "main.h"

typedef struct{
	float Temperature;
	float Humidity;
}SHT3XDATATYPE;

extern SHT3XDATATYPE Sht3x_Data;
extern I2C_HandleTypeDef hi2c1;

int8_t Sensor_I2C1_Read(uint16_t DevAddr, uint8_t *oData, uint16_t DataLen);
int8_t Sensor_I2C1_Write(uint16_t DevAddr, uint8_t *iData, uint16_t DataLen);

void Sht3x_Read_Data(void);

#endif






