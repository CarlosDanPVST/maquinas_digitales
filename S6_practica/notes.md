Una parte importante de los microcontroladores es su capacidad de manejar **interrupciones**
, mediante las cuales cambiamos, temporalmente, el flujo de ejecución de nuestros programas.
Es clave decir que _las interrupciones deben ser tan cortas, en términos de running time,
como sea_posible, pues podrían tener efectos colaterales en nuestro código.

Las interrupciones pueden implementarse de dos formas, por **hardware** y por **software.**
Dentro del marco del ESP32 tenemos los siguientes métodos para generar interrupciones:
- **attachInterrupt(GPIOPIN, ISR, Mode);** _GPIOPin_ hace referencia al pin que recibirá
la señal interruptora. _ISR_ a la rutina, usualmente una función, específica que se ejecutará.
 Y _Mode_ a qué se considerará como interrupción:
    - **LOW**. Detecta un estado bajo, 0
    - **HIGH**. Detecta un estado alto, 1
    - **CHANGE**. Detecta una cambio de estado, de 0 a 1, o de 1 a 0
    - **FALLING**. Detecta un flanco de bajada, de 1 a 0
    - **RISING**. Detecta un flanco de subida, de 0 1 

