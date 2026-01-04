/*
 * P5: Robot Explorador - EigenRobotics
 *
 * Robot móvil autónomo que evita obstáculos.
 * El proyecto final que integra todo.
 *
 * Conceptos:
 * - Control de motores DC con driver L298N
 * - PWM para velocidad
 * - Algoritmo de navegación básico
 * - Integración de subsistemas
 *
 * Circuito:
 * - Motor izquierdo: ENA->5, IN1->4, IN2->3
 * - Motor derecho: ENB->6, IN3->8, IN4->7
 * - HC-SR04: Trig->10, Echo->9
 * - L298N: +12V->Pilas, GND->Pilas y Arduino
 */

// --- Pines Motor Izquierdo ---
const int ENA = 5;   // PWM velocidad
const int IN1 = 4;   // Dirección
const int IN2 = 3;   // Dirección

// --- Pines Motor Derecho ---
const int ENB = 6;   // PWM velocidad
const int IN3 = 8;   // Dirección
const int IN4 = 7;   // Dirección

// --- Pines Sensor ---
const int TRIG = 10;
const int ECHO = 9;

// --- Configuración ---
const int VELOCIDAD = 150;      // 0-255 (empieza bajo, sube si necesitas)
const int DISTANCIA_MIN = 20;   // cm - distancia para detectar obstáculo
const int TIEMPO_GIRO = 400;    // ms - duración del giro

void setup() {
  // Configurar pines de motores
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Configurar pines de sensor
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
  Serial.println("Robot Explorador listo!");
  Serial.println("Distancia minima: " + String(DISTANCIA_MIN) + " cm");

  delay(2000);  // Esperar 2 segundos antes de empezar
  Serial.println("Arrancando...");
}

void loop() {
  int distancia = medirDistancia();

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia > DISTANCIA_MIN || distancia == 0) {
    // Camino libre -> avanzar
    avanzar();
  } else {
    // Obstáculo detectado -> parar y girar
    parar();
    delay(200);

    // Girar a la derecha (podrías hacerlo aleatorio)
    girarDerecha();
    delay(TIEMPO_GIRO);

    parar();
    delay(100);
  }

  delay(50);
}

// ==================== FUNCIONES DE MOVIMIENTO ====================

void avanzar() {
  // Motor izquierdo adelante
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, VELOCIDAD);

  // Motor derecho adelante
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, VELOCIDAD);
}

void retroceder() {
  // Motor izquierdo atrás
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, VELOCIDAD);

  // Motor derecho atrás
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, VELOCIDAD);
}

void girarDerecha() {
  // Izquierdo adelante, derecho atrás
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, VELOCIDAD);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, VELOCIDAD);
}

void girarIzquierda() {
  // Izquierdo atrás, derecho adelante
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, VELOCIDAD);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, VELOCIDAD);
}

void parar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// ==================== FUNCIÓN DE SENSOR ====================

int medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duracion = pulseIn(ECHO, HIGH, 30000);

  if (duracion == 0) {
    return 0;  // Sin eco (objeto muy lejos o error)
  }

  return duracion / 58;
}

/*
 * EXPERIMENTOS:
 *
 * 1. Ajusta VELOCIDAD - empieza bajo y sube
 * 2. Ajusta DISTANCIA_MIN - más alto = reacciona antes
 * 3. Ajusta TIEMPO_GIRO - más alto = gira más
 * 4. Añade segundo sensor (izquierda o derecha)
 * 5. Modo "seguir pared": mantén distancia constante de la pared
 * 6. Añade LEDs que indiquen: verde=avanzando, rojo=obstáculo
 * 7. Añade buzzer que suene al detectar obstáculo
 *
 * TROUBLESHOOTING:
 *
 * - Robot no se mueve: verifica pilas, conexiones GND
 * - Gira en círculos: un motor está invertido, cambia cables
 * - No detecta obstáculos: revisa TRIG/ECHO, prueba serial monitor
 * - Velocidades diferentes: ajusta VELOCIDAD para cada motor
 */
