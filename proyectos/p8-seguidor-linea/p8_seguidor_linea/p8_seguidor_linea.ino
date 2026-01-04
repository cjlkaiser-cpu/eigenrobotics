/*
 * P8: Seguidor de Línea - EigenRobotics
 *
 * Robot que sigue una línea negra sobre fondo blanco.
 * Usa 2 sensores IR reflectivos para detectar la línea.
 *
 * Conceptos:
 * - Sensores IR reflectivos
 * - Detección de contraste
 * - Control diferencial
 * - Calibración
 *
 * Circuito:
 * - Sensor IR izq: A0
 * - Sensor IR der: A1
 * - Motores: misma config que P5
 */

// --- Pines Sensores ---
const int SENSOR_IZQ = A0;
const int SENSOR_DER = A1;

// --- Pines Motores (igual que P5) ---
const int ENA = 5;
const int IN1 = 4;
const int IN2 = 7;
const int ENB = 6;
const int IN3 = 8;
const int IN4 = 12;

// --- Configuración ---
const int UMBRAL = 500;      // Ajustar según calibración
const int VEL_BASE = 120;    // Velocidad base (0-255)
const int VEL_GIRO = 80;     // Velocidad en giros

// --- Calibración (rellenar con tus valores) ---
// Pon el sensor sobre blanco, anota el valor
// Pon el sensor sobre negro, anota el valor
// UMBRAL = (blanco + negro) / 2
int valorBlancoIzq = 800;  // Ejemplo, mide el tuyo
int valorNegroIzq = 200;   // Ejemplo
int valorBlancoDer = 800;  // Ejemplo
int valorNegroDer = 200;   // Ejemplo

void setup() {
  Serial.begin(9600);
  Serial.println("Seguidor de Linea - EigenRobotics");
  Serial.println("Calibrando... pon sensores sobre BLANCO");

  // Configurar motores
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  parar();

  delay(2000);
  Serial.println("Arrancando en 3 segundos...");
  delay(3000);
}

void loop() {
  // Leer sensores
  int lecturaIzq = analogRead(SENSOR_IZQ);
  int lecturaDer = analogRead(SENSOR_DER);

  // Detectar línea (negro = lectura baja)
  bool lineaIzq = lecturaIzq < UMBRAL;
  bool lineaDer = lecturaDer < UMBRAL;

  // Mostrar en serial
  Serial.print("Izq: ");
  Serial.print(lecturaIzq);
  Serial.print(lineaIzq ? " [NEGRO]" : " [blanco]");
  Serial.print(" | Der: ");
  Serial.print(lecturaDer);
  Serial.println(lineaDer ? " [NEGRO]" : " [blanco]");

  // Decidir movimiento
  if (!lineaIzq && !lineaDer) {
    // Ambos ven blanco: línea en el centro, avanzar
    avanzar(VEL_BASE);
  }
  else if (lineaIzq && !lineaDer) {
    // Izquierdo ve negro: línea a la izquierda, girar izquierda
    girarIzquierda();
  }
  else if (!lineaIzq && lineaDer) {
    // Derecho ve negro: línea a la derecha, girar derecha
    girarDerecha();
  }
  else {
    // Ambos ven negro: cruce o línea gruesa, avanzar lento
    avanzar(VEL_GIRO);
  }

  delay(10);
}

// ==================== FUNCIONES DE MOVIMIENTO ====================

void avanzar(int velocidad) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidad);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidad);
}

void girarIzquierda() {
  // Motor izquierdo lento/parado, derecho normal
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);  // Parar izquierdo

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, VEL_GIRO);
}

void girarDerecha() {
  // Motor derecho lento/parado, izquierdo normal
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, VEL_GIRO);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);  // Parar derecho
}

void parar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// ==================== CALIBRACIÓN ====================

void calibrar() {
  Serial.println("=== MODO CALIBRACION ===");
  Serial.println("Mueve el robot sobre blanco y negro");
  Serial.println("Anota los valores min y max de cada sensor");
  Serial.println();

  while (true) {
    int izq = analogRead(SENSOR_IZQ);
    int der = analogRead(SENSOR_DER);

    Serial.print("Izq: ");
    Serial.print(izq);
    Serial.print("\t Der: ");
    Serial.println(der);

    delay(200);
  }
}

/*
 * CÓMO CALIBRAR:
 *
 * 1. Descomenta calibrar() en loop() (comenta el resto)
 * 2. Sube el código
 * 3. Abre Monitor Serial
 * 4. Pon sensores sobre BLANCO, anota valores
 * 5. Pon sensores sobre NEGRO, anota valores
 * 6. Calcula UMBRAL = (blanco + negro) / 2
 * 7. Actualiza UMBRAL en el código
 * 8. Vuelve a comentar calibrar() y descomenta loop normal
 *
 * EXPERIMENTOS:
 *
 * 1. Ajusta VEL_BASE para encontrar velocidad óptima
 * 2. Prueba diferentes estrategias de giro
 * 3. Añade 3er sensor central para mejor precisión
 * 4. Implementa control proporcional (más suave)
 * 5. Detecta intersecciones y toma decisiones
 */
