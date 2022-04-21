#include "Driver_TMP102_Port.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_i2c.h"
#include "stm32f4xx_hal_i2c_ex.h"

I2C_HandleTypeDef i2cHandler;

enum commDirection {SEND, RECEIVE};

typedef enum commDirection commDirection_t;

tmp102commResult_t TMP102_Port_Convert_Error_To_Upper_Layer (HAL_StatusTypeDef stmHalErrorType, commDirection_t commDirection);

/**
 *@brief Función "específica" de inicialización del driver para la plataforma STM32-F429ZI
 *Realiza las operaciones específicas para la librería STM
 *@return tmp102configResult_t
 */
tmp102configResult_t TMP102_Port_I2C_Init_Handler (void)
{
	tmp102configResult_t handlerReturnCode;

	i2cHandler.Instance = I2C1;
	i2cHandler.Init.ClockSpeed = 100000;
	i2cHandler.Init.DutyCycle = I2C_DUTYCYCLE_2;
	i2cHandler.Init.OwnAddress1 = 0;
	i2cHandler.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	i2cHandler.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	i2cHandler.Init.OwnAddress2 = 0;
	i2cHandler.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	i2cHandler.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;


	HAL_I2C_Init(&i2cHandler);

	if (HAL_I2C_Init(&i2cHandler) != HAL_OK)
	{
		handlerReturnCode = TMP102_CONFIG_SUCCESS;
	}
	else
	{
		handlerReturnCode = TMP102_CONFIG_FAIL;
	}
	return handlerReturnCode;
}

/**
 *@brief Función "específica" para la transmisión I2C en STM32-F429ZI
 *Realiza las operaciones de transmisión I2C específicas para la librería STM
 *@param tmp102address_t (Direccion I2C del sensor)
 *@param tmp102transmissionPayload_t * (Payload a enviar)
 *@param const tmp102transmissionTimeout_t (Timeout para la transacción)
 *@return tmp102commResult_t
 */
tmp102commResult_t TMP102_Port_I2C_Send (tmp102address_t tmp102Address,tmp102transmissionPayload_t * payload,const tmp102transmissionTimeout_t timeout)
{
	const uint16_t bytesToTransmit = 1; //Definirlo en capa superior
	HAL_StatusTypeDef transmissionStatus = 	HAL_I2C_Master_Transmit(&i2cHandler, tmp102Address, payload , bytesToTransmit, timeout);
	return TMP102_Port_Convert_Error_To_Upper_Layer (transmissionStatus, SEND);
}

/**
 *@brief Función "específica" para la recepción I2C en STM32-F429ZI
 *Realiza las operaciones de recepción I2C específicas para la librería STM
 *@param tmp102address_t (Direccion I2C del sensor)
 *@param tmp102transmissionPayload_t * (Payload a enviar)
 *@param const tmp102transmissionTimeout_t (Timeout para la transacción)
 *@return tmp102commResult_t
 */
tmp102commResult_t TMP102_Port_I2C_Receive (tmp102address_t tmp102Address,tmp102transmissionPayload_t * payload,const tmp102transmissionTimeout_t timeout)
{
	const uint16_t bytesToReceive = 2; //Definirlo en capa superior
	HAL_StatusTypeDef transmissionStatus = HAL_I2C_Master_Receive(&i2cHandler, tmp102Address, payload, bytesToReceive, timeout);
	return TMP102_Port_Convert_Error_To_Upper_Layer (transmissionStatus, RECEIVE);
}

/**
 *@brief Función de compatibilidad entre los errores de STM y otros fabricantes
 *@param HAL_StatusTypeDef (Errores STM)
 *@param commDirection_t (Dirección de la transmisión Transmisión/Recepción)
 *@return tmp102commResult_t
 */
tmp102commResult_t TMP102_Port_Convert_Error_To_Upper_Layer (HAL_StatusTypeDef stmHalErrorType, commDirection_t commDirection){
	tmp102commResult_t returnValue;
	switch( stmHalErrorType )
	{
	    case HAL_OK:
	        if (SEND == commDirection)
	        {
	        	returnValue = TMP102_SEND_SUCCESS;
	        }
	        else
	        {
	        	returnValue = TMP102_RECEIVE_SUCCESS;
	        }
	        break;
	    case HAL_ERROR:
	        if (SEND == commDirection)
	        {
	        	returnValue = TMP102_SEND_FAILURE;
	        }
	        else
	        {
	        	returnValue = TMP102_RECEIVE_FAILURE;
	        }
	        break;
	    case HAL_BUSY :
	        if (SEND == commDirection)
	        {
	        	returnValue = TMP102_SEND_BUSY;
	        }
	        else
	        {
	        	returnValue = TMP102_RECEIVE_BUSY;
	        }
	        break;
	    case HAL_TIMEOUT:
	        if (SEND == commDirection)
	        {
	        	returnValue = TMP102_SEND_TIMEOUT;
	        }
	        else
	        {
	        	returnValue = TMP102_RECEIVE_TIMEOUT;
	        }
	    	break;
	}


	return returnValue;
}

