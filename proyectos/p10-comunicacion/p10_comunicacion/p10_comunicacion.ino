/*
 * P10: Comunicación Serial - EigenRobotics
 *
 * Recibe comandos desde el ordenador y responde.
 * Base para control remoto, datalogging, interfaces.
 *
 * Conceptos:
 * - Comunicación Serial (UART)
 * - Parsing de comandos
 * - Protocolo simple
 * - Buffer de entrada
 *
 * Circuito:
 * - Solo cable USB
 * - Opcional: LEDs en pins 8, 9, 10
 */

// Pines de LEDs
const int LED_ROJO = 8;
const int LED_VERDE = 9;
const int LED_AZUL = 10;
const int LED_INTEGRADO = 13;

// Estado
bool ledEncendido = false;
unsigned long tiempoInicio;

// Buffer para comandos
String comandoBuffer = "";

void setup() {
  Serial.begin(9600);

  // Esperar conexión serial
  while (!Serial) {
    ; // Esperar en placas con USB nativo
  }

  // Configurar LEDs
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_INTEGRADO, OUTPUT);

  apagarTodo();

  tiempoInicio = millis();

  // Mensaje de bienvenida
  Serial.println("=================================");
  Serial.println("EigenRobotics - Control Serial");
  Serial.println("=================================");
  Serial.println("Escribe HELP para ver comandos");
  Serial.println();
}

void loop() {
  // Leer datos del serial
  while (Serial.available() > 0) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {
      // Fin de comando
      if (comandoBuffer.length() > 0) {
        procesarComando(comandoBuffer);
        comandoBuffer = "";
      }
    } else {
      comandoBuffer += c;
    }
  }
}

void procesarComando(String cmd) {
  cmd.trim();
  cmd.toUpperCase();

  Serial.print("> ");
  Serial.println(cmd);

  // Comandos simples
  if (cmd == "HELP") {
    mostrarAyuda();
  }
  else if (cmd == "LED_ON") {
    digitalWrite(LED_INTEGRADO, HIGH);
    ledEncendido = true;
    Serial.println("LED encendido");
  }
  else if (cmd == "LED_OFF") {
    digitalWrite(LED_INTEGRADO, LOW);
    ledEncendido = false;
    Serial.println("LED apagado");
  }
  else if (cmd == "LED_R") {
    apagarTodo();
    digitalWrite(LED_ROJO, HIGH);
    Serial.println("LED Rojo encendido");
  }
  else if (cmd == "LED_G") {
    apagarTodo();
    digitalWrite(LED_VERDE, HIGH);
    Serial.println("LED Verde encendido");
  }
  else if (cmd == "LED_B") {
    apagarTodo();
    digitalWrite(LED_AZUL, HIGH);
    Serial.println("LED Azul encendido");
  }
  else if (cmd == "OFF") {
    apagarTodo();
    ledEncendido = false;
    Serial.println("Todo apagado");
  }
  else if (cmd == "STATUS") {
    mostrarStatus();
  }
  else if (cmd.startsWith("BLINK:")) {
    int veces = cmd.substring(6).toInt();
    if (veces > 0 && veces <= 20) {
      parpadear(veces);
    } else {
      Serial.println("Error: usa BLINK:1 a BLINK:20");
    }
  }
  else if (cmd.startsWith("SAY:")) {
    String mensaje = cmd.substring(4);
    Serial.print("Arduino dice: ");
    Serial.println(mensaje);
  }
  else {
    Serial.println("Comando no reconocido. Escribe HELP");
  }

  Serial.println();
}

void mostrarAyuda() {
  Serial.println("--- COMANDOS DISPONIBLES ---");
  Serial.println("LED_ON    - Enciende LED integrado");
  Serial.println("LED_OFF   - Apaga LED integrado");
  Serial.println("LED_R     - LED Rojo");
  Serial.println("LED_G     - LED Verde");
  Serial.println("LED_B     - LED Azul");
  Serial.println("OFF       - Apaga todo");
  Serial.println("BLINK:N   - Parpadea N veces (1-20)");
  Serial.println("SAY:texto - Arduino repite el texto");
  Serial.println("STATUS    - Muestra estado actual");
  Serial.println("HELP      - Esta ayuda");
  Serial.println("----------------------------");
}

void mostrarStatus() {
  unsigned long uptime = (millis() - tiempoInicio) / 1000;

  Serial.println("--- STATUS ---");
  Serial.print("LED integrado: ");
  Serial.println(ledEncendido ? "ON" : "OFF");
  Serial.print("Uptime: ");
  Serial.print(uptime);
  Serial.println(" segundos");
  Serial.print("Memoria libre: ");
  Serial.print(freeMemory());
  Serial.println(" bytes");
  Serial.println("--------------");
}

void parpadear(int veces) {
  Serial.print("Parpadeando ");
  Serial.print(veces);
  Serial.println(" veces...");

  for (int i = 0; i < veces; i++) {
    digitalWrite(LED_INTEGRADO, HIGH);
    delay(200);
    digitalWrite(LED_INTEGRADO, LOW);
    delay(200);
  }

  Serial.println("Parpadeo completado");
}

void apagarTodo() {
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_INTEGRADO, LOW);
}

// Función para medir memoria libre
int freeMemory() {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

/*
 * CÓMO USAR:
 *
 * 1. Sube el código
 * 2. Abre Monitor Serial (9600 baud)
 * 3. Selecciona "Newline" en el desplegable
 * 4. Escribe comandos y pulsa Enter
 *
 * EXPERIMENTOS:
 *
 * 1. Añade nuevo comando (ej: RAINBOW para secuencia de colores)
 * 2. Añade comando para leer sensor (ej: TEMP, DIST)
 * 3. Crea comandos para controlar el robot P5
 * 4. Haz un programa en Python que envíe comandos
 * 5. Guarda datos de sensores en un archivo
 *
 * EJEMPLO PYTHON:
 *
 * import serial
 * import time
 *
 * arduino = serial.Serial('/dev/cu.usbmodem14201', 9600)
 * time.sleep(2)
 *
 * arduino.write(b'LED_ON\n')
 * print(arduino.readline().decode())
 *
 * arduino.write(b'BLINK:5\n')
 * while True:
 *     if arduino.in_waiting:
 *         print(arduino.readline().decode(), end='')
 *     else:
 *         break
 */
