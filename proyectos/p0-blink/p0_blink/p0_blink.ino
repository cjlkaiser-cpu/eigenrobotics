/*
 * P0: Blink - EigenRobotics
 *
 * El "Hola Mundo" de Arduino.
 * Un LED que parpadea cada segundo.
 *
 * Conceptos:
 * - pinMode(): configurar pin como salida
 * - digitalWrite(): encender/apagar
 * - delay(): esperar milisegundos
 * - loop(): se repite infinitamente
 *
 * Circuito:
 * - LED conectado al pin 13 (o usar el LED integrado en la placa)
 * - Resistencia 220 ohm en serie
 */

const int LED = 13;  // Pin 13 tiene LED integrado en la placa

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);  // Encender
  delay(100);              // Esperar 1 segundo
  digitalWrite(LED, LOW);   // Apagar
  delay(900
  );              // Esperar 1 segundo
}

/*
 * EXPERIMENTOS:
 *
 * 1. Cambia delay(1000) a delay(100) - parpadeo rápido
 * 2. Cambia delay(1000) a delay(2000) - parpadeo lento
 * 3. Haz que encienda 2 segundos y apague 0.5 segundos
 * 4. Conecta un LED externo en otro pin (ej: pin 8)
 */
