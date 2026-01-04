# P9: Display LCD

Pantalla LCD 16x2 para mostrar mensajes, datos de sensores o menús.

## Objetivo

Dar feedback visual al usuario. Introducir comunicación I2C y manejo de displays.

## Conceptos

- Display LCD 16x2 (16 columnas, 2 filas)
- Comunicación I2C (solo 2 cables de datos)
- Librería LiquidCrystal_I2C
- Caracteres personalizados

## Material

- Arduino UNO
- Display LCD 16x2 con módulo I2C (PCF8574)
- 4 cables (VCC, GND, SDA, SCL)

## Esquema

```
LCD I2C:
  VCC → 5V
  GND → GND
  SDA → Pin A4 (I2C Data)
  SCL → Pin A5 (I2C Clock)
```

¡Solo 4 cables! El módulo I2C simplifica mucho la conexión.

## Rol del niño

- ESCRIBIR: ¿Qué mensaje quieres mostrar?
- DISEÑAR: Crear caritas o iconos personalizados
- INTEGRAR: Añadir LCD a otros proyectos
- JUGAR: Hacer un marcador para juegos

## Dirección I2C

Los módulos I2C tienen una dirección. Las más comunes son:
- `0x27` (la mayoría)
- `0x3F` (algunos modelos)

Si no funciona, usa el escáner I2C incluido en el código.

## Código

```cpp
// Ver archivo p9_lcd.ino
```

## Caracteres especiales

El LCD puede mostrar 8 caracteres personalizados (5x8 píxeles cada uno).

```
Ejemplo: Carita feliz

  0 0 0 0 0
  0 1 0 1 0   → ojos
  0 0 0 0 0
  1 0 0 0 1   → boca
  0 1 1 1 0
  0 0 0 0 0
```

## Ideas de uso

- **Termómetro:** Mostrar temperatura con sensor
- **Distancia:** Mostrar lectura del HC-SR04
- **Cronómetro:** Para juegos o carreras
- **Menú:** Navegar opciones con botones
- **Mensajes secretos:** El niño escribe mensajes

## Integración con otros proyectos

| Proyecto | Uso del LCD |
|----------|-------------|
| P3 Alarma | "INTRUSO!" o distancia actual |
| P4 Girasol | Nivel de luz izq/der |
| P5 Robot | Estado: "Avanzando", "Girando" |
| P8 Seguidor | "Linea OK" o "Perdido" |

## Experimentos

- [ ] Mostrar "Hola Mundo"
- [ ] Contador que incrementa cada segundo
- [ ] Mostrar lectura de sensor (luz, distancia)
- [ ] Crear carita feliz y triste personalizadas
- [ ] Animación simple (texto que se desplaza)
- [ ] Integrar con otro proyecto

## Troubleshooting

| Problema | Causa | Solución |
|----------|-------|----------|
| No muestra nada | Contraste bajo | Girar potenciómetro del módulo I2C |
| Cuadros negros | Sin inicializar | Verificar dirección I2C |
| Caracteres raros | Dirección incorrecta | Usar escáner I2C |
| Solo muestra basura | Cables mal conectados | Verificar SDA/SCL |

## Estado

- [ ] LCD conectado (4 cables)
- [ ] Dirección I2C verificada
- [ ] Contraste ajustado
- [ ] "Hola Mundo" funcionando
- [ ] Caracteres personalizados creados
- [ ] Integrado con otro proyecto
