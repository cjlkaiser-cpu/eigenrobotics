/*
 * P2: Nave con Luces - EigenRobotics
 *
 * LEDs controlados con potenciómetro.
 * El niño gira la perilla y cambia el brillo.
 *
 * Conceptos:
 * - analogRead(): leer valor 0-1023
 * - analogWrite(): PWM, valor 0-255
 * - map(): convertir rangos
 * - Pines PWM (marcados con ~)
 *
 * Circuito:
 * - Potenciómetro: patas externas a 5V y GND, central a A0
 * - LED 1 en pin 9 (PWM)
 * - LED 2 en pin 10 (PWM)
 * - Cada LED con resistencia 220 ohm
 */

const int POT = A0;     // Potenciómetro en pin analógico A0
const int LED1 = 9;     // Primer LED (motor izquierdo de la nave)
const int LED2 = 10;    // Segundo LED (motor derecho de la nave)

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);  // Para ver valores en monitor serial
}

void loop() {
  // Leer potenciómetro (0-1023)
  int lectura = analogRead(POT);

  // Convertir a rango de brillo (0-255)
  int brillo = map(lectura, 0, 1023, 0, 255);

  // Aplicar brillo a los LEDs
  analogWrite(LED1, brillo);
  analogWrite(LED2, brillo);

  // Mostrar en monitor serial
  Serial.print("Pot: ");
  Serial.print(lectura);
  Serial.print(" -> Brillo: ");
  Serial.println(brillo);

  delay(50);  // Pequeña pausa para estabilidad
}

/*
 * EXPERIMENTOS:
 *
 * 1. Haz que LED2 tenga la mitad de brillo que LED1
 * 2. Añade más LEDs de diferentes colores
 * 3. Haz un efecto "respirar" automático (sin potenciómetro)
 * 4. Usa dos potenciómetros para controlar grupos de LEDs separados
 */
