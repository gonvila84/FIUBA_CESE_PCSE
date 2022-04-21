#ifndef INC_DRIVER_TMP102_H_
#define INC_DRIVER_TMP102_H_

#include <stdint.h>
#include <stdbool.h>

typedef bool bool_t;

/**
 * @brief Enumeración utilizada para reflejar el resultado de una operación de configuración del driver. 
 */
enum configResult 					{
										TMP102_CONFIG_SUCCESS,
										TMP102_CONFIG_FAIL
									};

/**
 * @brief Enumeración utilizada para reflejar el resultado de una operación de configuración del driver. 
 */
enum communicationResult			{
										 TMP102_SEND_SUCCESS,
									 	 TMP102_SEND_FAILURE,
									 	 TMP102_RECEIVE_SUCCESS,
									 	 TMP102_RECEIVE_FAILURE,
									 	 TMP102_SEND_BUSY,
									 	 TMP102_RECEIVE_BUSY,
									 	 TMP102_SEND_TIMEOUT,
										 TMP102_RECEIVE_TIMEOUT,
									};

/**
 * @brief Enumeración utilizada para reflejar el resultado de una transacción con el driver (ej: solicitar la temperatura). 
 */
enum operationsResult				{
										 TMP102_OPS_OK,
										 TMP102_OPS_FAILED
									};

/**
 * @brief Enumeración utilizada distinguir las unidades de medición de temperatura con las que opera el driver. 
 */
enum measureUnit 					{CELSIUS, FAHRENHEIT};

/**
 * @brief Typedef para la enumeración configResult. 
 */
typedef enum configResult			tmp102configResult_t;

/**
 * @brief Typedef para la enumeración communicationResult. 
 */
typedef enum communicationResult	tmp102commResult_t;

/**
 * @brief Typedef para la enumeración operationsResult. 
 */
typedef enum operationsResult		tmp102opsResult_t;

/**
 * @brief Typedef para la enumeración measureUnit. 
 */
typedef enum measureUnit			tmp102measureUnit_t;

/**
 * @brief Tipo de datos utilizado para almacenar un registro de temperatura. 
 */
typedef float						tmp102temperature_t;

/**
 * @brief Tipo de datos utilizado para almacenar la dirección del I2C slave.
 */
typedef uint16_t					tmp102address_t;

/**
 * @brief Tipo de datos utilizado para definir timeouts en las transacciones I2C.
 */
typedef uint32_t					tmp102transmissionTimeout_t;

/**
 * @brief Tipo de datos utilizado para enviar/recibir el payload de una transacción I2C.
 */
typedef uint8_t						tmp102transmissionPayload_t;

/**
 * @brief Constante que contiene la dirección (7 bits) del dispositivo I2C.
 */
static const tmp102address_t				TMP102_ADDRESS = (0X48 << 1);

/**
 * @brief Constante que contiene el timeout por defecto de una transacción I2C.
 */
static const tmp102transmissionTimeout_t 	TMP102_TRANSMISSION_TIMEOUT = 0xFFFFFFFFU;

/**
 * @brief Función de inicialización del driver
 *
 * Esta función debe ser invocada antes que cualquier otra. Realiza la configuración de la unidad de medición que utilizara el driver (FAHRENHEIT | CELSIUS). Inicializa el hardware y los handlers correspondientes a la plataforma en uso. 
 *
 * @param tmp102measureUnit_t (enum)
 * @return tmp102configResult_t (enum)
 */
tmp102configResult_t 	TMP102_InitDriver					(tmp102measureUnit_t measureUnit);


/**
 * @brief Función de configuración de la unidad de medición de temperatura (FAHRENHEIT | CELSIUS) 
 * Modifica la unidad en la que se expresa la temperatura.
 *
 * @param tmp102measureUnit_t (enum)
 * @return void
 */
void				 	TMP102_SetTemperatureMeasureUnit	(tmp102measureUnit_t resultMeasureUnit);

/**
 * @brief Devuelve la unidad de medición utilizada para expresar la temperatura
 *
 * @return tmp102measureUnit_t (enum)
 */
tmp102measureUnit_t		TMP102_GetTemperatureMeasureUnit	();

/**
 * @brief Solicita al sensor el registro de la temperatura
 * Esta función obtiene el valor actual de la temperatura registrada por el sensor TMP102.
 *
 * @param tmp102measureUnit_t (enum)
 * @return tmp102opsResult_t (enum)
 */
tmp102opsResult_t		TMP102_GetTemperature (tmp102temperature_t * temperature);

/**
 * @brief Realiza una prueba de medición para verificar el estado del sensor.
 * Intenta obtener un registro de temperatura para verificar la salud del sensor.
 *
 * @param void
 * @return tmp102opsResult_t
 */
tmp102opsResult_t		TMP102_TestMeasurement	(void);


#endif /* INC_DRIVER_TMP102_H_ */
