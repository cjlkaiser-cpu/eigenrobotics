# P4: Girasol Robot

Una flor LEGO que sigue la luz, como un girasol de verdad.

## Objetivo

Comparar dos sensores para tomar decisiones. Controlar servo con precisión.

## Conceptos

- LDR (fotorresistencia): más luz = menos resistencia
- Comparar dos sensores
- Control de servo con `Servo.h`
- Divisor de voltaje

## Material

- Arduino UNO
- 2x LDR (fotorresistencias)
- 2x Resistencia 10kΩ
- Servo SG90
- Cables
- LEGO para la flor
- **Imprimir:** Adaptador servo-LEGO

## Esquema

```
LDR Izquierda:
  5V ── LDR ──┬── A0
              └── R 10kΩ ── GND

LDR Derecha:
  5V ── LDR ──┬── A1
              └── R 10kΩ ── GND

Servo SG90:
  Naranja (señal) → Pin 9
  Rojo (5V) → 5V
  Marrón (GND) → GND
```

## Rol del niño

- CONSTRUIR: Flor LEGO con "pétalos" y tallo
- MONTAR: Servo como articulación del tallo
- JUGAR: Mover linterna y ver la flor seguirla
- EXPERIMENTAR: ¿Qué pasa con dos linternas?

## Cómo funciona

1. Dos LDRs miran en direcciones ligeramente diferentes
2. Si LDR izquierda recibe más luz → girar izquierda
3. Si LDR derecha recibe más luz → girar derecha
4. Si reciben igual → quedarse quieto

## Código

```cpp
// girasol.ino
#include <Servo.h>

const int LDR_IZQ = A0;
const int LDR_DER = A1;
const int SERVO_PIN = 9;

const int UMBRAL = 50;  // Diferencia mínima para moverse

Servo servo;
int posicion = 90;  // Centro

void setup() {
  servo.attach(SERVO_PIN);
  servo.write(posicion);
  Serial.begin(9600);
}

void loop() {
  int luzIzq = analogRead(LDR_IZQ);
  int luzDer = analogRead(LDR_DER);
  int diferencia = luzIzq - luzDer;

  Serial.print("Izq: "); Serial.print(luzIzq);
  Serial.print(" Der: "); Serial.print(luzDer);
  Serial.print(" Dif: "); Serial.println(diferencia);

  if (diferencia > UMBRAL && posicion > 0) {
    posicion--;  // Girar hacia izquierda
  } else if (diferencia < -UMBRAL && posicion < 180) {
    posicion++;  // Girar hacia derecha
  }

  servo.write(posicion);
  delay(20);
}
```

## Ideas de construcción

- **Flor simple:** Pétalos y centro con LDRs visibles
- **Girasol realista:** Pétalos amarillos, centro marrón
- **Robot mirón:** Cabeza que sigue la luz

## Impresión 3D

Necesitas adaptador servo SG90 → LEGO.

Buscar en Thingiverse: "SG90 servo LEGO mount"

Ver `3d-prints/README.md` para detalles.

## Experimentos

- [ ] Ajustar UMBRAL para más/menos sensibilidad
- [ ] Añadir segundo servo (arriba/abajo)
- [ ] Modo "evitar luz" (invertir lógica)
- [ ] LED que brilla según luz recibida

## Estado

- [ ] Circuito montado
- [ ] Adaptador 3D impreso
- [ ] Código funcionando
- [ ] Flor LEGO construida
- [ ] ¡Sigue la linterna!
- [ ] Foto en carpeta fotos/
