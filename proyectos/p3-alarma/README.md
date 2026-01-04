# P3: Alarma de Fortaleza

Sistema de seguridad para un castillo LEGO. ¡No actives la alarma!

## Objetivo

Usar sensor de distancia para detectar intrusos. Introducir condicionales.

## Conceptos

- Sensor ultrasónico HC-SR04
- `pulseIn()` - medir tiempo de pulso
- Condicionales `if/else`
- Cálculo de distancia

## Material

- Arduino UNO
- Sensor HC-SR04
- Buzzer activo
- LED rojo
- Resistencia 220Ω
- Cables
- LEGO para el castillo/fortaleza

## Esquema

```
HC-SR04:
  VCC  → 5V
  Trig → Pin 7
  Echo → Pin 6
  GND  → GND

Buzzer:
  (+) → Pin 8
  (-) → GND

LED Rojo:
  Pin 9 ── R 220Ω ── LED ── GND
```

## Rol del niño

- CONSTRUIR: Castillo/fortaleza con entrada vigilada
- INSTALAR: Decidir dónde va el sensor (puerta, ventana)
- JUGAR: Intentar "entrar" sin activar la alarma
- PROBAR: ¿A qué distancia se activa?

## Cómo funciona el HC-SR04

1. Arduino envía pulso por Trig
2. Sensor emite ultrasonido
3. Sonido rebota en objeto
4. Sensor recibe eco por Echo
5. Tiempo de vuelta = distancia

```
Distancia (cm) = Tiempo (μs) / 58
```

## Código

```cpp
// alarma.ino
const int TRIG = 7;
const int ECHO = 6;
const int BUZZER = 8;
const int LED = 9;

const int DISTANCIA_ALARMA = 20;  // cm

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distancia = medirDistancia();

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  if (distancia < DISTANCIA_ALARMA) {
    // ¡Intruso detectado!
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  } else {
    // Todo tranquilo
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  delay(100);
}

int medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duracion = pulseIn(ECHO, HIGH);
  int distancia = duracion / 58;

  return distancia;
}
```

## Ideas de construcción

- **Castillo medieval:** Sensor en el puente levadizo
- **Base secreta:** Sensor en la entrada oculta
- **Banco:** Sensor protegiendo el "tesoro"

## El juego

1. Activar la alarma
2. Niño intenta pasar sin ser detectado
3. ¿Puede moverse muy lento? ¿Muy rápido?
4. ¿Hay ángulos muertos?

## Experimentos

- [ ] Cambiar distancia de activación
- [ ] Añadir "cuenta atrás" antes de alarma
- [ ] Diferentes sonidos (buzzer pasivo + tonos)
- [ ] LED que parpadea en modo "armado"

## Estado

- [ ] Circuito montado
- [ ] Código funcionando
- [ ] Fortaleza LEGO construida
- [ ] ¡Alarma probada jugando!
- [ ] Foto en carpeta fotos/
