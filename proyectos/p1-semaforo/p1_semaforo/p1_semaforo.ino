/*
 * P1: Semáforo LEGO - EigenRobotics
 *
 * Semáforo con 3 LEDs: rojo, amarillo, verde.
 * Secuencia realista de semáforo de tráfico.
 *
 * Conceptos:
 * - Múltiples outputs
 * - Secuencias de estados
 * - Timing
 *
 * Circuito:
 * - LED Rojo en pin 10
 * - LED Amarillo en pin 9
 * - LED Verde en pin 8
 * - Cada LED con resistencia 220 ohm a GND
 */

const int LED_ROJO = 10;
const int LED_AMARILLO = 9;
const int LED_VERDE = 8;

// Tiempos en milisegundos
const int TIEMPO_VERDE = 3000;     // 3 segundos
const int TIEMPO_AMARILLO = 1000;  // 1 segundo
const int TIEMPO_ROJO = 3000;      // 3 segundos

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  // Apagar todos al inicio
  apagarTodos();
}

void loop() {
  // Verde
  digitalWrite(LED_VERDE, HIGH);
  delay(TIEMPO_VERDE);
  digitalWrite(LED_VERDE, LOW);

  // Amarillo
  digitalWrite(LED_AMARILLO, HIGH);
  delay(TIEMPO_AMARILLO);
  digitalWrite(LED_AMARILLO, LOW);

  // Rojo
  digitalWrite(LED_ROJO, HIGH);
  delay(TIEMPO_ROJO);
  digitalWrite(LED_ROJO, LOW);
}

void apagarTodos() {
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_VERDE, LOW);
}

/*
 * EXPERIMENTOS:
 *
 * 1. Cambia los tiempos del semáforo
 * 2. Añade modo "noche": solo amarillo parpadeando
 * 3. Añade un segundo semáforo para un cruce
 * 4. Añade semáforo peatonal (rojo/verde)
 */
