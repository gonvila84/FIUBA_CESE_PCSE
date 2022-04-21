# Repositorio para el trabajo final de la materia Protocolos de comunicación en sistemas embebidos (CESE-FIUBA)

Alumno y cohorte:
=================
- Alumno: Gonzalo Vila
- Cohorte: 16/2021

Objetivo:
=========
En el presente repositorio se registra la implementación de un driver para el sensor TMP102 de *Texas Instruments* y su *port* a la plataforma STM32F429ZI. La implementación posee fines puramente académicos.

El sensor TMP102 es un sensor de temperatura ambiental ampliamente utilizado en ámbitos industriales y dispositivos médicos. Posee un rango de operación de -40 C a +125 C.

Alcance:
========
El driver para la plataforma STM32F429ZI se encarga de:

1. Inicializar el *hardware* y los *handlers* I2C.
2. Proveer las funciones necesarias para obtener la temperatura del sensor y expresarla en grados Celsius o Fahrenheit.
3. Unifica la gestión de errores de manera de mejorar su capacidad de ser portado a otras plataformas.
4. Divide la implementación en capas para favorecer la portabilidad a otras plataformas.

Funciones expuestas al usuario:
===============================

1. TMP102_InitDriver: Invoca la inicialización del hardware específico sobre el cual funciona el driver. Le permite al usuario determinar cuando iniciar el driver. Todos los detalles específicos de la inicialización del hardware se realizan en capas inferiores a efectos de asegurar la portabilidad.
2. TMP102_GetTemperatureMeasureUnit: Verifica la unidad de medida utilizada por el driver (Celsius o Fahrenheit).
3. TMP102_SetTemperatureMeasureUnit: Permite establecer, tras la inicialización del driver, la unidad de medida a ser utilizada por el mismo (Celsius | Fahrenheit).
4. TMP102_GetTemperature: Permite obtener la unidad actual de medición de temperatura (Celsius | Fahrenheit).
5. TMP102_TestMeasurement: Realiza una medición de temperatura a modo de test sobre el sensor.

Las funciones internas al driver y específicas de la plataforma se describen con mayor detalle en la documentación Doxygen.

Documentación:
==============
Se incluye como documentación la presentación realizada como parte de la cátedra de Protocolos de Comunicación En Sistemas Embebidos (CESE-FIUBA).
Adicionalmente, se puede obtener mayor detalle de las funciones del driver en la carpeta /Docs/html (ver index.html).

📖 La documentacion del proyecto fue generada automaticamente utilizando Doxygen.

Ejemplo:
========
En la carpeta raíz del repositorio se incluye un ejemplo que demuestra el uso de las funciones del driver.
