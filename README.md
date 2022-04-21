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

Documentación:
==============
Se incluye como documentación la presentación realizada como parte de la cátedra de Protocolos de Comunicación En Sistemas Embebidos (CESE-FIUBA).
Adicionalmente, se puede obtener mayor detalle de las funciones del driver en la carpeta /Docs/html (ver index.html).

📖 La documentacion del proyecto fue generada automaticamente utilizando Doxygen.
