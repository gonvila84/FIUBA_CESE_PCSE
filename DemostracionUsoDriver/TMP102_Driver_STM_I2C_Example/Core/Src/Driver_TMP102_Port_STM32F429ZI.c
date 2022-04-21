/*
//#include "main.h"

enum i2cDeviceNumber { I2CDEV1, I2CDEV2};
enum tmp102TransmissionError { TMP102_OK, TMP102_ERROR, TMP102_BUSY, TMP102_TIMEOUT}; //Subir a capa superior

typedef enum i2cDeviceNumber i2cDeviceNumber_t;
typedef enum tmp102TransmissionError tmp102TransmissionError_t;
I2C_HandleTypeDef i2cHandler;

tmp102TransmissionError_t STM32F429ZI_I2C_Convert_Error_To_Upper_Layer (HAL_StatusTypeDef stmHalErrorType);
bool_t STM32F429ZI_I2C_Init (i2cDeviceNumber_t i2cDeviceNumber, uint8_t clockSpeedInkHz);
tmp102TransmissionError_t STM32F429ZI_I2C_Send (uint16_t i2cDeviceAddress, uint8_t * messageBuffer, uint32_t transmissionTimeout);
tmp102TransmissionError_t STM32F429ZI_I2C_Receive (uint16_t i2cDeviceAddress, uint8_t * messageBuffer, uint32_t transmissionTimeout);
tmp102TransmissionError_t STM32F429ZI_I2C_Convert_Error_To_Upper_Layer (HAL_StatusTypeDef stmHalErrorType);

bool_t STM32F429ZI_I2C_Init (i2cDeviceNumber_t i2cDeviceNumber, uint8_t clockSpeedInkHz){
	if (i2cDeviceNumber == I2CDEV1)
	{
		i2cHandler.Instance = I2C1;
	}
	if (i2cDeviceNumber == I2CDEV2)
	{
		i2cHandler.Instance = I2C2;
	}
	i2cHandler.Init.ClockSpeed = clockSpeedInkHz*1000;
	i2cHandler.Init.DutyCycle = I2C_DUTYCYCLE_2;
	i2cHandler.Init.OwnAddress1 = 0;
	i2cHandler.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	i2cHandler.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	i2cHandler.Init.OwnAddress2 = 0;
	i2cHandler.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	i2cHandler.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

	if (HAL_I2C_Init(&i2cHandler) != HAL_OK)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Definir Address y Message en la capa superior
tmp102TransmissionError_t STM32F429ZI_I2C_Send (uint16_t i2cDeviceAddress, uint8_t * messageBuffer, uint32_t transmissionTimeout){
	uint16_t bytesToTransmit = 1; //Definirlo en capa superior
	HAL_StatusTypeDef transmissionStatus = 	HAL_I2C_Master_Transmit(&i2cHandler, i2cDeviceAddress, messageBuffer , bytesToTransmit, transmissionTimeout);
	return STM32F429ZI_I2C_Convert_Error_To_Upper_Layer (transmissionStatus);
}

tmp102TransmissionError_t STM32F429ZI_I2C_Receive (uint16_t i2cDeviceAddress, uint8_t * messageBuffer, uint32_t transmissionTimeout){
	uint16_t bytesToReceive = 2; //Definirlo en capa superior
	HAL_StatusTypeDef transmissionStatus = HAL_I2C_Master_Receive(&i2cHandler, i2cDeviceAddress, messageBuffer, bytesToReceive, transmissionTimeout);
	return STM32F429ZI_I2C_Convert_Error_To_Upper_Layer (transmissionStatus);
}

tmp102TransmissionError_t STM32F429ZI_I2C_Convert_Error_To_Upper_Layer (HAL_StatusTypeDef stmHalErrorType){
	return stmHalErrorType;
}

bool_t validate_clock_speed (uint8_t clockSpeedInkHz){
	if (clockSpeedInkHz > 400 || clockSpeedInkHz < 1)
	{
		return false;
	}
	return true;
}
*/

