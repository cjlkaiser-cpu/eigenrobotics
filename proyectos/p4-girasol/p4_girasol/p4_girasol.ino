/*
 * P4: Girasol Robot - EigenRobotics
 *
 * Flor que sigue la luz, como un girasol de verdad.
 * Usa dos sensores de luz para decidir hacia dónde girar.
 *
 * Conceptos:
 * - LDR (fotorresistencia): más luz = menos resistencia
 * - Comparar dos sensores
 * - Librería Servo.h
 * - Divisor de voltaje
 *
 * Circuito:
 * - LDR izquierda: 5V -> LDR -> A0 -> R10k -> GND
 * - LDR derecha:   5V -> LDR -> A1 -> R10k -> GND
 * - Servo: Naranja->9, Rojo->5V, Marrón->GND
 */

#include <Servo.h>

const int LDR_IZQ = A0;
const int LDR_DER = A1;
const int SERVO_PIN = 9;

const int UMBRAL = 50;       // Diferencia mínima para moverse
const int VELOCIDAD = 1;     // Grados por paso (1 = suave, 5 = rápido)

Servo servo;
int posicion = 90;  // Empezar en el centro

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(posicion);

  Serial.begin(9600);
  Serial.println("Girasol Robot activado!");

  delay(500);  // Esperar a que el servo se posicione
}

void loop() {
  // Leer ambos sensores
  int luzIzq = analogRead(LDR_IZQ);
  int luzDer = analogRead(LDR_DER);
  int diferencia = luzIzq - luzDer;

  // Mostrar valores
  Serial.print("Izq: ");
  Serial.print(luzIzq);
  Serial.print(" | Der: ");
  Serial.print(luzDer);
  Serial.print(" | Dif: ");
  Serial.print(diferencia);
  Serial.print(" | Pos: ");
  Serial.println(posicion);

  // Decidir movimiento
  if (diferencia > UMBRAL && posicion > 0) {
    // Más luz a la izquierda -> girar izquierda
    posicion -= VELOCIDAD;
  }
  else if (diferencia < -UMBRAL && posicion < 180) {
    // Más luz a la derecha -> girar derecha
    posicion += VELOCIDAD;
  }
  // Si la diferencia es pequeña, no moverse

  // Mover servo
  servo.write(posicion);

  delay(20);  // Pausa corta para movimiento suave
}

/*
 * EXPERIMENTOS:
 *
 * 1. Ajusta UMBRAL: más bajo = más sensible
 * 2. Ajusta VELOCIDAD: más alto = más rápido
 * 3. Añade un segundo servo para movimiento arriba/abajo
 * 4. Invierte la lógica: que EVITE la luz en lugar de seguirla
 * 5. Añade un LED que brille según la luz total recibida
 */
