# Notas sobre el mini proyecto de blink

Empezamos con el microcontrolador ESP32 conectado a la protoboard, a modo que su entrada micro USB quede libre. Dentro de Arduino IDE seleccionamos 
> Tools > Board > esp32 > DOIT ESP32 DEVKIT V1

Esto nos permite generar el código correcto para nuestro microcontrolador particular

Es importante tener en mente que ESP32 se refiere a la unidad de procesamiento y otras especificaciones, sin embargo, la placa sobre la cual está montada puede variar de modelo a modelo. La siguiente imagen representa nuestro caso particular
![esp32-layout](./imagenes/esp32pinout.jpg)

Expliquemos parte de la terminología de la imagen:
- `EN` -> Enable, pin de habilitación de regulador 3.3V
- `GIOPx` -> General Input Output Pin, pin de uso general, numerado en la placa
- `ADCx` -> Analogic-Digital Converter, convertidor de señal
- `TOUCHx` -> Entrada touch
- `DACx` -> Digital-Analogic Converter, convertidor de señal 
- `GND` -> Ground, tierra eléctrica

C es análogo a Java; existen diversos tipos primitivos para trabajar, y una sintax para trabajar con funciones. Por ejemplo `void recursion(int x){...}` es una función que acepta un parámetro entero, realiza alguna rutina y no devuelve nada. Otro ejemplo puede ser `int fourier(float x){... return -1;}`. 

No obstante, existen diferencias significativas. Por ejemplo, se usan <b>macros</b> y se declaran las variables, normalmente, en métodos especiales. 

Por el momento usamos un ejemplo hallado en _File > Examples > 01Basics > Blink_ que nos permite controlar el parpadeo de una luz led, ya sea la integrada en la placa, o bien una led externa conectada a la protoboard

![Blink](./imagenes/blink_integrated.gif) ![Blue_blink](./imagenes/blue_blink.gif)

Para lograr el resultado de la led azul se realizó lo siguiente:
- A GIOP33 se conectó un cable dupont MM, para lograr espacio, y en conexión con el ánodo de la led
- El cátodo de la led está en conexión con una resistencia, misma que está conectada al GND del ESP32
- Se cargó el **[programa](https://github.com/CarlosDanPVST/maquinas_digitales/blob/main/Blink/Blink.ino)** (click) que hace parpadear cada 500ms la led azul, de forma iterativa.