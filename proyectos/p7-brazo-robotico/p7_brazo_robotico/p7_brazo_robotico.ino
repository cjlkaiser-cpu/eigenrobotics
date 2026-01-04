/*
 * P7: Brazo Robótico - EigenRobotics
 *
 * Brazo con 3 servos controlado por potenciómetros.
 * Base (giro), codo (arriba/abajo), pinza (abrir/cerrar).
 *
 * Conceptos:
 * - Control de múltiples servos
 * - Mapeo de potenciómetros a ángulos
 * - Movimiento suave
 * - Secuencias programadas
 *
 * Circuito:
 * - Servo base: pin 9
 * - Servo codo: pin 10
 * - Servo pinza: pin 11
 * - Pot base: A0, Pot codo: A1, Pot pinza: A2
 */

#include <Servo.h>

// Pines de servos
const int PIN_BASE = 9;
const int PIN_CODO = 10;
const int PIN_PINZA = 11;

// Pines de potenciómetros
const int POT_BASE = A0;
const int POT_CODO = A1;
const int POT_PINZA = A2;

// Límites de movimiento (ajustar según tu brazo)
const int BASE_MIN = 0;
const int BASE_MAX = 180;
const int CODO_MIN = 30;   // Evitar que golpee la base
const int CODO_MAX = 150;
const int PINZA_ABIERTA = 90;
const int PINZA_CERRADA = 30;

// Servos
Servo servoBase;
Servo servoCodo;
Servo servoPinza;

// Posiciones actuales
int posBase = 90;
int posCodo = 90;
int posPinza = 90;

void setup() {
  Serial.begin(9600);
  Serial.println("Brazo Robotico - EigenRobotics");
  Serial.println("Mueve los potenciometros para controlar");
  Serial.println();

  // Inicializar servos
  servoBase.attach(PIN_BASE);
  servoCodo.attach(PIN_CODO);
  servoPinza.attach(PIN_PINZA);

  // Posición inicial (centro)
  posicionInicial();

  delay(1000);
}

void loop() {
  // Leer potenciómetros
  int lecturaBase = analogRead(POT_BASE);
  int lecturaCodo = analogRead(POT_CODO);
  int lecturaPinza = analogRead(POT_PINZA);

  // Mapear a ángulos
  int objetivoBase = map(lecturaBase, 0, 1023, BASE_MIN, BASE_MAX);
  int objetivoCodo = map(lecturaCodo, 0, 1023, CODO_MIN, CODO_MAX);
  int objetivoPinza = map(lecturaPinza, 0, 1023, PINZA_ABIERTA, PINZA_CERRADA);

  // Mover suavemente hacia el objetivo
  posBase = moverSuave(posBase, objetivoBase, 2);
  posCodo = moverSuave(posCodo, objetivoCodo, 2);
  posPinza = moverSuave(posPinza, objetivoPinza, 3);

  // Aplicar posiciones
  servoBase.write(posBase);
  servoCodo.write(posCodo);
  servoPinza.write(posPinza);

  // Mostrar posiciones
  Serial.print("Base: ");
  Serial.print(posBase);
  Serial.print(" | Codo: ");
  Serial.print(posCodo);
  Serial.print(" | Pinza: ");
  Serial.println(posPinza);

  delay(20);
}

// Mover gradualmente hacia el objetivo
int moverSuave(int actual, int objetivo, int paso) {
  if (actual < objetivo) {
    return min(actual + paso, objetivo);
  } else if (actual > objetivo) {
    return max(actual - paso, objetivo);
  }
  return actual;
}

// Volver a posición central
void posicionInicial() {
  servoBase.write(90);
  servoCodo.write(90);
  servoPinza.write(PINZA_ABIERTA);
  posBase = 90;
  posCodo = 90;
  posPinza = PINZA_ABIERTA;
}

// ==================== SECUENCIAS EJEMPLO ====================

// Agarrar objeto delante y dejarlo a la derecha
void secuenciaAgarrar() {
  // Posición inicial
  moverA(90, 90, PINZA_ABIERTA);
  delay(500);

  // Bajar al objeto
  moverA(90, 50, PINZA_ABIERTA);
  delay(500);

  // Cerrar pinza
  moverA(90, 50, PINZA_CERRADA);
  delay(500);

  // Subir
  moverA(90, 120, PINZA_CERRADA);
  delay(500);

  // Girar a la derecha
  moverA(30, 120, PINZA_CERRADA);
  delay(500);

  // Bajar
  moverA(30, 50, PINZA_CERRADA);
  delay(500);

  // Soltar
  moverA(30, 50, PINZA_ABIERTA);
  delay(500);

  // Volver
  posicionInicial();
}

// Mover todos los servos a posición específica
void moverA(int base, int codo, int pinza) {
  // Movimiento gradual
  while (posBase != base || posCodo != codo || posPinza != pinza) {
    posBase = moverSuave(posBase, base, 2);
    posCodo = moverSuave(posCodo, codo, 2);
    posPinza = moverSuave(posPinza, pinza, 3);

    servoBase.write(posBase);
    servoCodo.write(posCodo);
    servoPinza.write(posPinza);

    delay(20);
  }
}

/*
 * EXPERIMENTOS:
 *
 * 1. Ajusta los límites (CODO_MIN, etc.) para tu brazo
 * 2. Llama a secuenciaAgarrar() desde loop() para probar
 * 3. Crea tus propias secuencias
 * 4. Añade un botón para activar secuencias
 * 5. Guarda posiciones en array para reproducirlas
 * 6. Integra control IR del P6
 *
 * PARA EJECUTAR SECUENCIA:
 * Descomenta esta línea en loop():
 *   secuenciaAgarrar();
 *   while(true); // Ejecutar solo una vez
 */
