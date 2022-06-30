#include "sht3x.h"

static int16_t Sht3xAddr = 0x44 << 1 ; //0x88
SHT3XDATATYPE Sht3x_Data;

int8_t Sensor_I2C1_Read(uint16_t DevAddr, uint8_t *oData, uint16_t DataLen)
{
	return HAL_I2C_Master_Receive(&hi2c1,DevAddr,oData,DataLen,1000);
}

int8_t Sensor_I2C1_Write(uint16_t DevAddr, uint8_t *iData, uint16_t DataLen)
{
	return HAL_I2C_Master_Transmit(&hi2c1,DevAddr,iData,DataLen,1000);
}

void Sht3x_Read_Data(void)
{
	uint8_t Read_Buf[6];

	Read_Buf[0] = 0x24;
	Read_Buf[1] = 0x0b;
	Sensor_I2C1_Write(Sht3xAddr, Read_Buf, 2);
	Sensor_I2C1_Read(Sht3xAddr,Read_Buf, 6);

	Sht3x_Data.Temperature = (uint16_t)((Read_Buf[0]<<8) | Read_Buf[1]);
	Sht3x_Data.Humidity = (uint16_t)((Read_Buf[3]<<8) | Read_Buf[4]);

	Sht3x_Data.Temperature = (175.0f * (Sht3x_Data.Temperature / 65535.0f) - 45.0f);    // T = -45 + 175 * tem / (2^16-1)
	Sht3x_Data.Humidity = (100.0f * Sht3x_Data.Humidity / 65535.0f);           		    // RH = hum*100 / (2^16-1)
}


