#ifndef INC_DRIVER_TMP102_PORT_H_
#define	INC_DRIVER_TMP102_PORT_H_

#include "Driver_TMP102.h"

/**
 * @brief Función de envio I2C.
 *
 * Esta función es utilizada para realizar la solicitud correspondiente al Slave desde el Master.
 *
 * @param tmp102address_t (Dirección del dispositivo Slave).
 * @param tmp102transmissionPayload_t *
 * @param tmp102transmissionTimeout_t
 * @return tmp102commResult_t (enum)
 */
tmp102commResult_t 	TMP102_Port_I2C_Send	(tmp102address_t tmp102Address,tmp102transmissionPayload_t * payload,const tmp102transmissionTimeout_t timeout);

/**
 * @brief Función de recepción I2C.
 *
 * Esta función es utilizada para realizar la recepción de respuestas del Slave desde el Master.
 *
 * @param tmp102address_t (Dirección del dispositivo Slave).
 * @param tmp102transmissionPayload_t *
 * @param tmp102transmissionTimeout_t
 * @return tmp102commResult_t (enum)
 */
tmp102commResult_t	TMP102_Port_I2C_Receive (tmp102address_t tmp102Address,tmp102transmissionPayload_t * payload,const tmp102transmissionTimeout_t timeout);

/**
* @brief Función de inicialización del handler I2C.
*
* Esta función es utilizada para inicializar el handler I2C.
*
* @return tmp102commResult_t (enum)
 */
tmp102configResult_t TMP102_Port_I2C_Init_Handler (void);


#endif
