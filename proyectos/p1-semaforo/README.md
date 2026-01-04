# P1: Semáforo LEGO

Un semáforo real con LEDs montado en una torre LEGO.

## Objetivo

Controlar múltiples outputs en secuencia. Introducir timing y estados.

## Conceptos

- Múltiples `pinMode()`
- Secuencias de estados
- Timing realista de semáforo

## Material

- Arduino UNO
- LED rojo
- LED amarillo
- LED verde
- 3x Resistencia 220Ω
- Cables
- LEGO para la torre

## Esquema

```
Pin 10 ──── R 220Ω ──── LED Rojo ──── GND
Pin 9  ──── R 220Ω ──── LED Amarillo ──── GND
Pin 8  ──── R 220Ω ──── LED Verde ──── GND
```

## Rol del niño

- CONSTRUIR: Torre/poste LEGO para el semáforo
- DECIDIR: Dónde colocar cada LED en la estructura
- JUGAR: Coches de juguete que respetan el semáforo

## Secuencia del semáforo

```
1. Verde    (3 segundos)
2. Amarillo (1 segundo)
3. Rojo     (3 segundos)
4. Repetir
```

## Código

```cpp
// semaforo.ino
const int LED_ROJO = 10;
const int LED_AMARILLO = 9;
const int LED_VERDE = 8;

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
}

void loop() {
  // Verde
  digitalWrite(LED_VERDE, HIGH);
  delay(3000);
  digitalWrite(LED_VERDE, LOW);

  // Amarillo
  digitalWrite(LED_AMARILLO, HIGH);
  delay(1000);
  digitalWrite(LED_AMARILLO, LOW);

  // Rojo
  digitalWrite(LED_ROJO, HIGH);
  delay(3000);
  digitalWrite(LED_ROJO, LOW);
}
```

## Ideas de construcción LEGO

- Poste alto con los 3 LEDs verticales
- Esquina de "ciudad" con acera
- Semáforo peatonal adicional (más LEDs)

## Experimentos

- [ ] Cambiar tiempos del semáforo
- [ ] Añadir segundo semáforo (para cruce)
- [ ] Modo "noche" (amarillo parpadeante)
- [ ] Añadir semáforo peatonal

## Estado

- [ ] Circuito montado
- [ ] Código funcionando
- [ ] Torre LEGO construida
- [ ] Foto en carpeta fotos/
