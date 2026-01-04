/*
 * P6: Control Remoto IR - EigenRobotics
 *
 * Controla LEDs con un mando a distancia infrarrojo.
 * Primero descubre los códigos, luego asigna acciones.
 *
 * Conceptos:
 * - Receptor IR VS1838B
 * - Librería IRremote
 * - Decodificación de señales
 * - Mapeo de botones a acciones
 *
 * Circuito:
 * - Receptor IR: OUT->11, GND->GND, VCC->5V
 * - LED Rojo: pin 8
 * - LED Verde: pin 9
 * - LED Azul: pin 10
 *
 * Instalación librería:
 * - Arduino IDE: Sketch > Include Library > Manage Libraries
 * - Buscar "IRremote" por shirriff
 * - Instalar
 */

#include <IRremote.hpp>

const int IR_PIN = 11;
const int LED_ROJO = 8;
const int LED_VERDE = 9;
const int LED_AZUL = 10;

// Códigos del mando ELEGOO (ajusta con los tuyos)
// Usa el Monitor Serial para descubrir tus códigos
const uint32_t BOTON_1 = 0xF30CFF00;
const uint32_t BOTON_2 = 0xE718FF00;
const uint32_t BOTON_3 = 0xA15EFF00;
const uint32_t BOTON_0 = 0xE916FF00;  // Apagar todo

void setup() {
  Serial.begin(9600);
  Serial.println("Control Remoto IR - EigenRobotics");
  Serial.println("Pulsa botones del mando para ver sus codigos");
  Serial.println();

  // Iniciar receptor IR
  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

  // Configurar LEDs
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);

  apagarTodo();
}

void loop() {
  if (IrReceiver.decode()) {
    // Mostrar código recibido
    Serial.print("Codigo recibido: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    // Obtener el código
    uint32_t codigo = IrReceiver.decodedIRData.decodedRawData;

    // Ejecutar acción según el botón
    switch (codigo) {
      case BOTON_1:
        Serial.println("-> LED Rojo");
        apagarTodo();
        digitalWrite(LED_ROJO, HIGH);
        break;

      case BOTON_2:
        Serial.println("-> LED Verde");
        apagarTodo();
        digitalWrite(LED_VERDE, HIGH);
        break;

      case BOTON_3:
        Serial.println("-> LED Azul");
        apagarTodo();
        digitalWrite(LED_AZUL, HIGH);
        break;

      case BOTON_0:
        Serial.println("-> Apagar todo");
        apagarTodo();
        break;

      default:
        Serial.println("-> Boton no asignado");
        break;
    }

    Serial.println();

    // Preparar para siguiente señal
    IrReceiver.resume();
  }
}

void apagarTodo() {
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);
}

/*
 * CÓMO DESCUBRIR TUS CÓDIGOS:
 *
 * 1. Sube este sketch
 * 2. Abre Monitor Serial (9600 baud)
 * 3. Pulsa cada botón del mando
 * 4. Anota el código hexadecimal que aparece
 * 5. Reemplaza los valores BOTON_1, BOTON_2, etc.
 *
 * EXPERIMENTOS:
 *
 * 1. Añade más botones y LEDs
 * 2. Usa VOL+/VOL- para cambiar brillo (PWM)
 * 3. Crea un efecto "discoteca" con un botón
 * 4. Integra este código con el robot P5
 * 5. Prueba con el mando de tu TV
 */
