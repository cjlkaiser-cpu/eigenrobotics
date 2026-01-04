# P10: Comunicación Serial

Controla el Arduino desde el ordenador. Envía comandos y recibe datos.

## Objetivo

Establecer comunicación bidireccional PC ↔ Arduino. Base para proyectos más avanzados.

## Conceptos

- Comunicación Serial (UART)
- Protocolo de comandos
- Parsing de mensajes
- Buffer serial

## Material

- Arduino UNO
- Cable USB
- Ordenador con Arduino IDE (Monitor Serial)
- LEDs/servos para probar comandos

## Esquema

```
Solo necesitas el cable USB.

Opcional - LEDs para probar:
  Pin 8 ── R 220Ω ── LED Rojo ── GND
  Pin 9 ── R 220Ω ── LED Verde ── GND
  Pin 10 ── R 220Ω ── LED Azul ── GND
```

## Rol del niño

- ESCRIBIR: Comandos en el Monitor Serial
- EXPERIMENTAR: ¿Qué pasa si escribo esto?
- CREAR: Inventar nuevos comandos
- JUGAR: Control por "voz" (teclado)

## Comandos implementados

| Comando | Acción |
|---------|--------|
| `LED_ON` | Enciende LED |
| `LED_OFF` | Apaga LED |
| `LED_R` | Enciende rojo |
| `LED_G` | Enciende verde |
| `LED_B` | Enciende azul |
| `BLINK:5` | Parpadea 5 veces |
| `STATUS` | Muestra estado actual |
| `HELP` | Lista de comandos |

## Código

```cpp
// Ver archivo p10_comunicacion.ino
```

## Cómo usar

1. Subir el código al Arduino
2. Abrir Monitor Serial (Tools → Serial Monitor)
3. Configurar: 9600 baud, "Newline" al final
4. Escribir comandos y pulsar Enter
5. Ver respuestas del Arduino

## Protocolo de comunicación

```
PC → Arduino:  Comandos de texto (terminados en newline)
Arduino → PC:  Respuestas y confirmaciones

Ejemplo de sesión:
> LED_ON
< LED encendido
> STATUS
< Estado: LED=ON, Uptime=45s
> BLINK:3
< Parpadeando 3 veces...
< Parpadeo completado
```

## Extensiones avanzadas

### Python control

```python
import serial
import time

arduino = serial.Serial('/dev/cu.usbmodem*', 9600)
time.sleep(2)  # Esperar conexión

arduino.write(b'LED_ON\n')
respuesta = arduino.readline()
print(respuesta)
```

### Control desde otro programa

Cualquier programa que pueda abrir puerto serial puede controlar el Arduino:
- Python
- Processing
- Node.js
- Aplicación móvil (via Bluetooth)

## Ideas de uso

- **Centro de control:** Dashboard que muestra sensores
- **Datalogger:** Guardar datos de sensores en PC
- **Control remoto:** Mover robot desde teclado
- **Juegos:** Arduino como controlador de juego

## Integración con otros proyectos

| Proyecto | Comunicación |
|----------|--------------|
| P5 Robot | Comandos: ADELANTE, ATRAS, IZQUIERDA... |
| P7 Brazo | Comandos: BASE:90, CODO:45, PINZA:ABRIR |
| P9 LCD | Enviar texto a mostrar desde PC |

## Experimentos

- [ ] Enviar y recibir comandos básicos
- [ ] Crear comando personalizado
- [ ] Integrar con otro proyecto (robot, brazo)
- [ ] Control desde Python
- [ ] Enviar datos de sensores al PC
- [ ] Graficar datos con Processing o Python

## Estado

- [ ] Comunicación básica funcionando
- [ ] Comandos LED implementados
- [ ] Comando personalizado creado
- [ ] Integrado con otro proyecto
