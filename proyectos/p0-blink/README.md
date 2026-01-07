# P0: Blink

El "Hola Mundo" de Arduino. Un LED que parpadea.

## Objetivo

Verificar que todo funciona: IDE instalado, placa detectada, código subido.

## Conceptos

- `pinMode()` - configurar pin como salida
- `digitalWrite()` - encender/apagar
- `delay()` - esperar milisegundos
- `loop()` - se repite infinitamente

## Material

- Arduino UNO
- LED (cualquier color)
- Resistencia 220Ω
- Cables

## Esquema

```
Arduino Pin 13 ──── Resistencia 220Ω ──── LED (+) ──── LED (-) ──── GND
```

Nota: El pin 13 tiene LED integrado en la placa. Puedes probar sin conectar nada externo.

## Rol del niño

- Elegir color del LED
- Observar el parpadeo
- Contar: "uno, dos, uno, dos..."

## Pasos

1. Instalar Arduino IDE
2. Conectar Arduino por USB
3. Seleccionar placa y puerto
4. Abrir ejemplo: File → Examples → 01.Basics → Blink
5. Subir (botón flecha)
6. Ver LED parpadear

## Código

```cpp
// blink.ino
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
```

## Experimentos

- [ ] Cambiar delay a 100ms (parpadeo rápido)
- [ ] Cambiar delay a 2000ms (parpadeo lento)
- [ ] Conectar LED externo en pin 13
- [ ] Usar otro pin (ej: pin 8)

## Estado

- [x] IDE instalado
- [x] Placa detectada
- [x] Blink funcionando
- [x] Experimentos completados (2 LEDs en paralelo)

## Sesiones

- [SESION_2026-01-07.md](SESION_2026-01-07.md) - Primera sesion con kit Elegoo
