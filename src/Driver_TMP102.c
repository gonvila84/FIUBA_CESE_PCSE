#include "Driver_TMP102.h"
#include "Driver_TMP102_Port.h"

const uint8_t TMP102_TEMP_REGISTER = 0;

const float LSB_MULTIPLIER_TO_CELSIUS = 0.0625;

struct driverControl
{
	tmp102measureUnit_t tempMeasureUnit;
};

typedef struct driverControl driverControl_t;

driverControl_t tmp102DriverControl;

tmp102temperature_t	TMP102_ConvertTemperatureToMeasureUnit(tmp102transmissionPayload_t * payload);
tmp102measureUnit_t	TMP102_GetTemperatureMeasureUnit ();

/**
 * @brief Función "genérica" de inicialización del driver
 *Realiza las llamadas correspondientes al port para iniciar el driver I2C
 *@param tmp102measureUnit_t
 *@return tmp102configResult_t
 */
tmp102configResult_t TMP102_InitDriver(tmp102measureUnit_t measureUnit)
{
	tmp102configResult_t initReturnCode;
	TMP102_SetTemperatureMeasureUnit(measureUnit);
	if (TMP102_CONFIG_SUCCESS == TMP102_Port_I2C_Init_Handler())
	{
		initReturnCode = TMP102_CONFIG_SUCCESS;
	}
	else
	{
		initReturnCode = TMP102_CONFIG_FAIL;
	}
	return initReturnCode;
}

/**
 * @brief Permite obtener la unidad de medición de la temperatura en uso
 * @return tmp102measureUnit_t
 */
tmp102measureUnit_t	TMP102_GetTemperatureMeasureUnit ()
{
	return tmp102DriverControl.tempMeasureUnit;
}

/**
 * @brief Permite modificar la unidad de medición de la temperatura en forma dinámica tras el inicio del driver
 * @param tmp102measureUnit_t
 */
void TMP102_SetTemperatureMeasureUnit(tmp102measureUnit_t resultMeasureUnit)
{
	tmp102DriverControl.tempMeasureUnit = resultMeasureUnit;
}


/**
 * @brief Invoca las transacciones necesarias con el port especifico para obtener la temperatura
 * @param tmp102temperature_t  *
 * @return tmp102opsResult_t
 */
tmp102opsResult_t	TMP102_GetTemperature(tmp102temperature_t * temperature)
{
	tmp102opsResult_t opsResult;
	tmp102transmissionPayload_t payload [2] = {TMP102_TEMP_REGISTER};
	if (TMP102_SEND_SUCCESS == TMP102_Port_I2C_Send	(TMP102_ADDRESS,payload,TMP102_TRANSMISSION_TIMEOUT))
	{
		if (TMP102_RECEIVE_SUCCESS == TMP102_Port_I2C_Receive (TMP102_ADDRESS,payload,TMP102_TRANSMISSION_TIMEOUT))
		{
			*temperature = TMP102_ConvertTemperatureToMeasureUnit(payload);
		}
		else
		{
			opsResult = TMP102_OPS_FAILED;
		}
		opsResult = TMP102_OPS_OK;
	}
	else
	{
		opsResult = TMP102_OPS_FAILED;
	}

	return opsResult;
}


/**
 * @brief Función que interpreta los datos provistos por el sensor y los expresa en la unidad de medida adecuada.
 *
 * @return tmp102temperature_t
 */
tmp102temperature_t	TMP102_ConvertTemperatureToMeasureUnit(tmp102transmissionPayload_t * payload)
{
	tmp102temperature_t temperature = 0.0;
	int16_t rawData = 0;
	rawData = ((int16_t)payload[0] << 4) | (payload[1] >> 4);

	if (rawData > 0x7FF)
	{
		rawData |= 0xF000;
	}
	temperature = rawData * LSB_MULTIPLIER_TO_CELSIUS;
	if (tmp102DriverControl.tempMeasureUnit == FAHRENHEIT)
	{
		temperature = (temperature * 1.8) + 32;
	}
	return temperature;
}

/**
 * @brief Función de verificación del sensor.
 *
 * Esta función es utilizada para verificar que el sensor reporta datos.
 *
 * @return tmp102commResult_t (enum)
 */
tmp102opsResult_t TMP102_TestMeasurement (void)
{
	tmp102temperature_t temperature;
	if (TMP102_OPS_FAILED == TMP102_GetTemperature(&temperature))
	{
		return TMP102_OPS_FAILED;
	}
	else
	{
		return TMP102_OPS_OK;
	}
}


