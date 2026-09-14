# Detector de Proximidad con Sensor Ultrasónico HC-SR04 y Arduino UNO

Este proyecto implementa un sistema de medición de distancia en tiempo real utilizando el sensor ultrasónico HC-SR04. El programa detecta la presencia de un objeto cuando este se encuentra a menos de **10 cm** y activa un LED de advertencia por 500 ms sin repetir mensajes continuos mientras el objeto permanezca en la zona de detección.



## 📂 Estructura del Repositorio

Para revisar el código fuente, el circuito interactivo y las evidencias del montaje físico, selecciona las siguientes carpetas:

* **[Código Fuente (.ino)](/Codigo/detector_distancia.ino)**  
Script en C++ cargado en la placa Arduino (`distancia.ino`) con comentarios explicativos de la lógica de control.
* **[Simulación en Tinkercad](/Simulacion/readme.md)**  
Esquema del circuito en entorno simulado y enlace interactivo al proyecto de Tinkercad.
* **[Evidencias Físicas y Video](/Fotos/)**  
Capturas del montaje en laboratorio sobre protoboard y video de verificación del funcionamiento en tiempo real.


##  Materiales Utilizados

* 1x Placa Arduino UNO R3
* 1x Sensor Ultrasónico HC-SR04
* 1x LED (Indicador de presencia)
* 1x Resistencia de 220 Ω
* 1x Protoboard
* Cables Jumper



##  Conexión del Circuito

| Componente | Pin del Componente | Pin en Arduino UNO | Descripción |
| :--- | :--- | :--- | :--- |
| HC-SR04 | VCC | 5V | Alimentación de 5V |
| HC-SR04 | Trig | Pin 10 | Disparo del pulso ultrasónico (`OUTPUT`) |
| HC-SR04 | Echo | Pin 9 | Recepción del eco (`INPUT`) |
| HC-SR04 | GND | GND | Tierra común |
| LED | Ánodo (+) | Pin 8 | Salida digital vía resistencia 220 Ω (`OUTPUT`) |
| LED | Cátodo (-) | GND | Tierra común |




##  Explicación Técnica de la Lógica

1. **Cálculo de Distancia:**


El sensor HC-SR04 genera un pulso ultrasónico de $40\text{ kHz}$ cuando el pin `Trig` recibe un pulso en alto de $10\ \mu\text{s}$. El pulso viaja por el aire, rebota en un objeto y regresa al sensor, activando el pin `Echo`.

Sabiendo que la velocidad del sonido a nivel del mar es aproximadamente $343\text{ m/s}$ ($0.0343\text{ cm/}\mu\text{s}$), y que el pulso recorre una trayectoria de ida y vuelta, la distancia se calcula según la fórmula:

$$\text{Distancia} = \frac{\text{Duración} \times 0.0343}{2}$$


2. **Mecanismo Anti-Repetición:**  
      
Para evitar que el LED parpadee constantemente mientras el objeto está estático frente al sensor, se usa la variable booleana `objetoDetectado`:


* Al entrar al rango ($<10\text{ cm}$), se enciende el LED por 500 ms, se envía la alerta serial y se cambia `objetoDetectado = true`.


* En las lecturas siguientes, la condición `!objetoDetectado` se vuelve falsa, omitiendo la activación repetida.


* Solo al salir de la zona ($\ge 10\text{ cm}$), se reestablece `objetoDetectado = false`, habilitando la detección para un nuevo evento.



## Autores:  

**Estudiantes:**

* Alberto Fandino
* Camilo Martinez
* Martin Castro
* Sebastian De Luque
* Sebastian Martinez
* Steven Santamaria


**Asignatura:**
* Fundamentos de Mecatrónica


**Institución:**    
* Corporación Universitaria Americana
