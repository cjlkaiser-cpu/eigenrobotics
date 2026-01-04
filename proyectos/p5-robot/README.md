# P5: Robot Explorador

Robot móvil autónomo que evita obstáculos. El proyecto final.

## Objetivo

Integrar todo: sensores, actuadores, lógica de control. Robot que "piensa".

## Conceptos

- Control de motores DC con driver
- PWM para velocidad
- Algoritmo de navegación básico
- Integración de subsistemas

## Material

- Arduino UNO
- 2x Motor DC con reductora (TT motor)
- Driver L298N
- Sensor HC-SR04
- Portapilas 4xAA + pilas
- Cables
- LEGO Technic para chasis
- **Imprimir:** Ruedas + soportes motor

## Esquema

```
Driver L298N:
  ENA → Pin 5 (PWM velocidad motor A)
  IN1 → Pin 4
  IN2 → Pin 3
  IN3 → Pin 8
  IN4 → Pin 7
  ENB → Pin 6 (PWM velocidad motor B)

  Motor izquierdo → OUT1, OUT2
  Motor derecho → OUT3, OUT4

  +12V → Portapilas (+)
  GND  → Portapilas (-) y Arduino GND
  +5V  → Arduino 5V (si jumper 5V está puesto)

HC-SR04:
  VCC  → 5V
  Trig → Pin 10
  Echo → Pin 9
  GND  → GND
```

**IMPORTANTE:** GND del Arduino y del portapilas deben estar conectados.

## Rol del niño

- CONSTRUIR: Chasis LEGO Technic completo
- DISEÑAR: Forma del robot (¿coche? ¿tanque? ¿bicho?)
- CREAR: Laberinto de obstáculos LEGO
- JUGAR: Ver el robot navegar solo
- MODIFICAR: Cambiar el laberinto, ver cómo reacciona

## Algoritmo básico

```
REPETIR:
  1. Medir distancia al frente
  2. Si distancia > 20cm:
       Avanzar
  3. Si distancia < 20cm:
       Parar
       Girar derecha (o izquierda)
       Esperar un poco
```

## Código

```cpp
// robot.ino

// Pines motor izquierdo
const int ENA = 5;
const int IN1 = 4;
const int IN2 = 3;

// Pines motor derecho
const int ENB = 6;
const int IN3 = 8;
const int IN4 = 7;

// Pines sensor
const int TRIG = 10;
const int ECHO = 9;

// Configuración
const int VELOCIDAD = 150;       // 0-255
const int DISTANCIA_MIN = 20;    // cm

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {
  int distancia = medirDistancia();

  Serial.print("Distancia: ");
  Serial.println(distancia);

  if (distancia > DISTANCIA_MIN) {
    avanzar();
  } else {
    parar();
    delay(200);
    girarDerecha();
    delay(400);
  }

  delay(50);
}

// --- Funciones de movimiento ---

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

void parar() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
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

// --- Función de sensor ---

int medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duracion = pulseIn(ECHO, HIGH);
  return duracion / 58;
}
```

## Ideas de construcción

- **Coche explorador:** Chasis bajo, ruedas grandes
- **Tanque:** Orugas LEGO (si tienes piezas)
- **Bicho:** Patas decorativas (no funcionales)

## Impresión 3D

Necesitas:
- Ruedas para motor TT
- Soportes motor TT → LEGO Technic

Ver `3d-prints/README.md` para detalles.

## El juego del laberinto

1. Niño construye laberinto con LEGO/cajas
2. Poner robot en la entrada
3. ¿Puede salir solo?
4. Modificar laberinto, repetir

## Experimentos

- [ ] Ajustar VELOCIDAD y DISTANCIA_MIN
- [ ] Añadir segundo sensor (izquierda o derecha)
- [ ] Modo "seguir pared"
- [ ] Añadir LEDs que indican estado
- [ ] Buzzer que suena al detectar obstáculo

## Troubleshooting

| Problema | Causa probable | Solución |
|----------|----------------|----------|
| No se mueve | Pilas bajas | Cambiar pilas |
| Gira en círculos | Motor invertido | Cambiar cables del motor |
| No detecta obstáculos | Sensor mal conectado | Revisar TRIG/ECHO |
| Velocidades diferentes | Motores distintos | Ajustar velocidad individual |

## Estado

- [ ] Chasis LEGO construido
- [ ] Motores montados
- [ ] Electrónica conectada
- [ ] Código básico funcionando
- [ ] Ruedas impresas/montadas
- [ ] ¡Robot navega solo!
- [ ] Laberinto creado
- [ ] Foto/video en carpeta fotos/
