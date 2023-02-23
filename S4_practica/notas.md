# Notas de los temas vistos en clase 

**Serial Peripheral Interface (SPI)**. Provee una comunicación bilateral rápida (Full Duplex @ 15MHz). Es 
recomendable si la cantidad de conexiones no es un problema. SPI permite la comunicación 
entre elementos como *el CPU y el DSP* y *la RAM y el Banco de Tonos*. SPI tiene una biblioteca
que podemos usar

Nosotros usaremos esto para comunicarnos con una tarjeta **Secure Digital [card] (SD)**. 
La biblioteca que la representa extiende de **Stream**. 

**Inter Integrated Circuit (I2C)** representada por la librería *Wire Library*. Provee una
comunicación moderada, por turnos (Half Duplex @ 400kHz) y permite ahorrar espacio 
en conexiones. *Este protocolo lo usaremos para comunicarnos con el BMP 180*. Como dato,
este protocolo se usa en muchos oxímetros

Algunas definiciones encontradas en Internet

<details>
    <summary>SPI</summary>
    <p>Interfaz de especificación de <em>comunicación serial síncrona</em> usada 
    para comunicaciones a corta distancia. El SPI bus específica cuatro señales lógicas
    <ul>
        <li><b>SCLK.</b> Serial Clock</li>
        <li><b>MOSI.</b> Master Out Slave In</li>
        <li><b>MISO.</b> Master In Slave Out</li>
        <li><b>CS/SS</b> Chip Slave Select</li>
    </ul>
    Especificamos estos nombres *son los que hayamos impresos en los sensores y en 
    los pinouts </p>
</details>

<details>
    <summary>SD</summary>
    <p>Formato de tarjeta de memoria flash no volátil patentado desarrollado por SD
    Association (SDA) para su uso en dispositivos portátiles.</p>
</details>

<details>
    <summary>I2C</summary>
    <p>Interfaz de especificación de <em>comunicación serial asíncrona</em>. 
    Esta comunicación solo usa dos cables para transmitir datos entre dispositivos
    <ul>
        <li><b>SDA (Serial Data).</b> Bilateral, envío y recibo entre Master y Slave</li>
        <li><b>SCL (Serial Clock)</b> Línea que carrea la señal del reloj</li>
    </ul></p>
</details>

Instalamos las librerías correspondientes a nuestro sensor atmosférico. En nuestro caso,
 mediante <code>Tools > Manage Libraries </code>, la librería <code>BMP280</code> de 
*Adafruit*. Se presentó el error de una búsqueda de dirección en memoria por default 
que no coincidía con nuestro caso específico; para encontrar nuestra dirección usamos
el siguiente [código](https://playground.arduino.cc/Main/sourceblock_1/index.txt?action=sourceblock&num=1)

Para probar nuestro sensor hicimos uso de <code> File > Examples > Adafruit BMP280 Library > 
bmp280test.ino </code> con la sustitución, en la línea 39, fue <code>  status = bmp.begin(0x76);</code>
con "0x76" igual a nuestra dirección particular

Recordemos que los carácteres tienen una correspondencia con algún código, como ASCII.
Entonces, para trasmitir un mensaje podemos enviar el número que representa dicho carácter
, ¿pero cómo, físicamente, transmitimos dicho número?

En comunicación paralela, cada bit se transmite por su propia vía física, digamos un cable.
Esto hace la comunicación paralela muy rápida, pero al costo de la necesidad de una infraestructura
muy costosa. 

La contraparte de este tipo de comunicación es la *serial*, donde los datos se emiten
uno tras de otro. 

Las comunicaciones también se clasifican por *la dirección de trasmisión*
- **Simplex**, solo un dispositivo envía, y el otro solo puede recibir
- **Half duplex**, ambos dispositivos pueden enviar y recibir, pero en un momento dado solo pueden tener uno
de estos comportamientos
- **Full duplex**, dos canales físicos, por lo qué ambos dispositivos pueden enviar y recibir
simultáneamente

Otra clasificación es *por señal de reloj*
- **Asíncrona**, no hay *señal de reloj* que indique el periodo con el cual se enviarán/recibirán los bits
- **Síncrona**, comparten una línea de *señal de reloj* que indica el periodo 

La especificación de qué combinación de clasificaciones se está usando se conoce como 
*protocolo*. Para nuestro caso, todas las siguientes las usamos y *corresponden a 
trasmisión en serie*

- **UART**. Asíncrono, Full Duplex. Consta de 1 bit de inicio, 8 bits de datos, y 
1 bit de parada. **TX, RX** indican los canales de transmisión y recepción en los 
dispositivos. *La suma de los bits señalizadores y de datos se denomina **BAUD**, 
y con UART ponemos transmitir hasta 115200 BAUDS*
- **I2C**. Síncrono, Half Duplex. Dos líneas, **SDA** para Data, y **SCL** para Clock.
Nos permite comunicarnos en paralelo con varios *slave*. Para lograr esto, a cada slave se le asigna
una dirección en memoria, seguida del mensaje. A través del canal compartido todos los 
slave reciben la información, *pero solo aquel que tiene la dirección adecuada hace caso*
- **SPI**. Síncrono, Full Duplex. 