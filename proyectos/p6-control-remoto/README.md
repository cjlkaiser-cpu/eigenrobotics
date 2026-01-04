# P6: Control Remoto IR

Controla LEDs, servos o el robot con un mando a distancia infrarrojo.

## Objetivo

Introducir comunicación inalámbrica. Decodificar señales IR y mapear botones a acciones.

## Conceptos

- Receptor IR VS1838B
- Librería IRremote
- Decodificación de protocolos (NEC, Sony, etc.)
- Mapeo de códigos a acciones

## Material

- Arduino UNO
- Receptor IR VS1838B (incluido en kit ELEGOO)
- Mando IR (incluido en kit ELEGOO)
- LEDs para probar
- Resistencias 220Ω

## Esquema

```
Receptor IR VS1838B (mirando la parte abombada):
  - Pata izquierda (OUT) → Pin 11
  - Pata central (GND) → GND
  - Pata derecha (VCC) → 5V

LEDs de prueba:
  Pin 8 ── R 220Ω ── LED Rojo ── GND
  Pin 9 ── R 220Ω ── LED Verde ── GND
  Pin 10 ── R 220Ω ── LED Azul ── GND
```

## Rol del niño

- APUNTAR: Usar el mando como "varita mágica"
- DESCUBRIR: ¿Qué hace cada botón?
- DECIDIR: Asignar funciones a los botones favoritos
- JUGAR: Controlar luces o robot a distancia

## Cómo funciona

1. El mando emite pulsos de luz infrarroja
2. El receptor detecta los pulsos
3. Arduino decodifica el patrón
4. Cada botón tiene un código único
5. Mapeamos códigos a acciones

## Código

```cpp
// Ver archivo p6_control_remoto.ino
```

## Primeros pasos

1. Subir el código
2. Abrir Monitor Serial (9600 baud)
3. Pulsar botones del mando
4. Anotar los códigos que aparecen
5. Modificar el código con tus códigos

## Códigos típicos (mando ELEGOO)

| Botón | Código (hex) |
|-------|--------------|
| CH- | 0xBA45FF00 |
| CH | 0xB946FF00 |
| CH+ | 0xB847FF00 |
| 0 | 0xE916FF00 |
| 1 | 0xF30CFF00 |
| 2 | 0xE718FF00 |

*Nota: Los códigos pueden variar. Usa el Monitor Serial para ver los tuyos.*

## Ideas de uso

- **Control de luces:** Cada número enciende un LED diferente
- **Atenuador:** VOL+ y VOL- cambian brillo
- **Control del robot P5:** Flechas para mover, PLAY para parar
- **Secuencias:** Botón 1 = efecto arcoíris, botón 2 = parpadeo

## Experimentos

- [ ] Descubrir todos los códigos de tu mando
- [ ] Controlar brillo de LED con VOL+/VOL-
- [ ] Añadir control IR al robot P5
- [ ] Usar otro mando (TV, aire acondicionado) y ver sus códigos

## Estado

- [ ] Receptor IR conectado
- [ ] Códigos descubiertos y anotados
- [ ] LEDs respondiendo a botones
- [ ] Integrado con otro proyecto (robot, luces)
