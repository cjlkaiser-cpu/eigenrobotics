/*
 * P3: Alarma de Fortaleza - EigenRobotics
 *
 * Sistema de seguridad con sensor ultrasónico.
 * ¡No actives la alarma!
 *
 * Conceptos:
 * - Sensor HC-SR04 (ultrasonido)
 * - pulseIn(): medir tiempo de pulso
 * - Condicionales if/else
 * - Cálculo de distancia
 *
 * Circuito:
 * - HC-SR04: VCC->5V, Trig->7, Echo->6, GND->GND
 * - Buzzer: (+)->8, (-)>GND
 * - LED Rojo: pin 9 con resistencia 220 ohm
 */

const int TRIG = 7;
const int ECHO = 6;
const int BUZZER = 8;
const int LED = 9;

const int DISTANCIA_ALARMA = 20;  // cm - ajusta según tu fortaleza

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
  Serial.println("Alarma de Fortaleza activada!");
  Serial.println("Distancia de deteccion: " + String(DISTANCIA_ALARMA) + " cm");
}

void loop() {
  int distancia = medirDistancia();

  // Mostrar en monitor serial
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia > 0 && distancia < DISTANCIA_ALARMA) {
    // ¡INTRUSO DETECTADO!
    activarAlarma();
  } else {
    // Todo tranquilo
    desactivarAlarma();
  }

  delay(100);
}

int medirDistancia() {
  // Enviar pulso de 10 microsegundos
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Medir tiempo del eco
  long duracion = pulseIn(ECHO, HIGH, 30000);  // Timeout 30ms

  // Calcular distancia (velocidad del sonido = 343 m/s)
  // Distancia = (tiempo * velocidad) / 2
  // En cm: duracion(us) / 58
  int distancia = duracion / 58;

  return distancia;
}

void activarAlarma() {
  digitalWrite(LED, HIGH);
  digitalWrite(BUZZER, HIGH);
}

void desactivarAlarma() {
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);
}

/*
 * EXPERIMENTOS:
 *
 * 1. Cambia DISTANCIA_ALARMA para más/menos sensibilidad
 * 2. Añade cuenta atrás de 3 segundos antes de activar alarma
 * 3. Haz que el LED parpadee cuando está en modo "armado"
 * 4. Usa buzzer pasivo y tone() para diferentes sonidos
 */
