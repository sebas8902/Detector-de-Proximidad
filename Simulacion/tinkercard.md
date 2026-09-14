# Simulación Interactiva en Tinkercad

Este directorio contiene la simulación virtual del **Detector de Proximidad con Sensor Ultrasónico HC-SR04** desarrollada en la plataforma Tinkercad.



## Enlace al Proyecto Interactivo

Puedes probar la simulación en tiempo real, modificar el código y manipular la distancia del objeto directamente desde tu navegador:

**[Abrir Simulación en Tinkercad](https://www.tinkercad.com/things/bSI2QZ8odVo-sensordistancia?sharecode=udNH8Iiuvep2GFb4RK_zpIXeuZUfk0gqZzSzQUWD7KU)**


## Desarrollo de la Simulación

Para validar el funcionamiento del circuito antes del montaje en físico, se recreó el entorno virtual siguiendo estos pasos:

1. **Montaje de Componentes:**
   * Se insertó una placa **Arduino UNO R3** y una protoboard estándar.
   * Se colocó el sensor **HC-SR04** y un **LED rojo** con su respectiva resistencia limitadora de $220\ \Omega$.

2. **Cableado Digital y Alimentación:**
   * Se conectaron los pines `VCC` y `GND` del sensor a las líneas de alimentación de $5\text{V}$ y tierra de la protoboard.
   * Se asignaron los pines digitales: **Pin 10** para `Trig`, **Pin 9** para `Echo` y **Pin 8** para el control del LED.

3. **Carga y Verificación del Código:**
   * Se implementó el script en C++ dentro del editor de código de Tinkercad.
   * Se abrió el **Monitor Serial** integrado para observar la salida de datos en centímetros y comprobar que el mensaje de alerta `"OBJETO DETECTADO"` solo se enviara una vez al cruzar el umbral de los $10\text{ cm}$.


## Esquema del Circuito

![Simulación Tinkercad](./conexion_tinkercad.png)
