# P2: Nave con Luces

Una construcción LEGO con LEDs que el niño controla con una perilla.

## Objetivo

Introducir señales analógicas: leer potenciómetro, controlar brillo con PWM.

## Conceptos

- `analogRead()` - leer valor 0-1023
- `analogWrite()` - PWM, valor 0-255
- `map()` - convertir rangos
- Pines PWM (~)

## Material

- Arduino UNO
- 2-4 LEDs (colores a elegir)
- Resistencias 220Ω
- Potenciómetro 10kΩ
- Cables
- LEGO para la nave/casa

## Esquema

```
Potenciómetro:
  - Pata izquierda → 5V
  - Pata central → Pin A0
  - Pata derecha → GND

LEDs (usar pines PWM: 3, 5, 6, 9, 10, 11):
  Pin 9  ──── R 220Ω ──── LED ──── GND
  Pin 10 ──── R 220Ω ──── LED ──── GND
```

## Rol del niño

- CONSTRUIR: Nave espacial / casa / vehículo LEGO
- DECIDIR: Dónde van los LEDs ("motores", "ventanas", "faros")
- CONTROLAR: Girar la perilla para cambiar brillo
- JUGAR: Historias con la nave iluminada

## Código

```cpp
// nave_luces.ino
const int POT = A0;
const int LED1 = 9;
const int LED2 = 10;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  int lectura = analogRead(POT);        // 0-1023
  int brillo = map(lectura, 0, 1023, 0, 255);

  analogWrite(LED1, brillo);
  analogWrite(LED2, brillo);

  delay(10);
}
```

## Ideas de construcción

- **Nave espacial:** LEDs como motores traseros
- **Casa:** LEDs en ventanas, se "encienden las luces"
- **Coche:** LEDs como faros delanteros
- **Robot:** LEDs como ojos

## Experimentos

- [ ] LEDs con brillos diferentes (uno más tenue)
- [ ] Efecto "respirar" automático (sin potenciómetro)
- [ ] Añadir más LEDs de colores
- [ ] Dos potenciómetros para controlar grupos separados

## Estado

- [ ] Circuito montado
- [ ] Código funcionando
- [ ] Construcción LEGO terminada
- [ ] Foto en carpeta fotos/
