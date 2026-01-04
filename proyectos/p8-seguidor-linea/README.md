# P8: Seguidor de Línea

Robot que sigue una línea negra sobre fondo blanco. ¡Clásico de robótica!

## Objetivo

Usar sensores IR para detectar contraste. Implementar control proporcional básico.

## Conceptos

- Sensores IR reflectivos (TCRT5000 o similar)
- Detección de contraste blanco/negro
- Control proporcional
- Calibración de sensores

## Material

- Arduino UNO
- 2x Sensor IR reflectivo (módulo TCRT5000)
- Chasis robot P5 (motores + driver L298N)
- Cinta aislante negra (para la línea)
- Cartulina blanca (para el circuito)

## Esquema

```
Sensores IR (2 unidades):
  Sensor Izquierdo:
    VCC → 5V
    GND → GND
    OUT → Pin A0 (analógico) o Pin 2 (digital)

  Sensor Derecho:
    VCC → 5V
    GND → GND
    OUT → Pin A1 (analógico) o Pin 3 (digital)

Motores (igual que P5):
  ENA → Pin 5
  IN1, IN2 → Pins 4, 7
  IN3, IN4 → Pins 8, 12
  ENB → Pin 6
```

## Rol del niño

- DISEÑAR: Dibujar el circuito con cinta negra
- CONSTRUIR: Montar sensores en el chasis
- CALIBRAR: Ajustar altura de sensores
- CREAR: Hacer circuitos cada vez más difíciles

## Cómo funciona

```
Sensor sobre BLANCO → refleja mucho → lectura ALTA
Sensor sobre NEGRO → refleja poco → lectura BAJA

Si izquierdo ve negro → línea está a la izquierda → girar izquierda
Si derecho ve negro → línea está a la derecha → girar derecha
Si ambos ven blanco → seguir recto
Si ambos ven negro → cruce o fin de línea
```

## Código

```cpp
// Ver archivo p8_seguidor_linea.ino
```

## Construcción del circuito

1. **Base:** Cartulina blanca grande (50x70 cm mínimo)
2. **Línea:** Cinta aislante negra de 2-3 cm de ancho
3. **Diseño:** Empezar con óvalo simple, luego añadir curvas

### Diseños progresivos

```
Nivel 1: Óvalo simple
┌──────────────────┐
│  ┌────────────┐  │
│  │            │  │
│  └────────────┘  │
└──────────────────┘

Nivel 2: Ocho
    ┌───┐
   ╱     ╲
  │       │
   ╲     ╱
    └───┘
   ╱     ╲
  │       │
   ╲     ╱
    └───┘

Nivel 3: Con intersecciones
```

## Calibración

Los sensores necesitan calibración:

1. Poner sensor sobre blanco → anotar valor
2. Poner sensor sobre negro → anotar valor
3. Calcular umbral = (blanco + negro) / 2
4. Ajustar UMBRAL en el código

## Experimentos

- [ ] Calibrar sensores correctamente
- [ ] Circuito oval simple
- [ ] Curvas cerradas
- [ ] Intersecciones (recto vs girar)
- [ ] Añadir sensor central para mejor precisión
- [ ] Control PID para movimiento más suave

## Troubleshooting

| Problema | Causa | Solución |
|----------|-------|----------|
| No detecta línea | Sensores muy altos | Bajar a 5-10mm del suelo |
| Pierde la línea en curvas | Velocidad alta | Reducir velocidad |
| Oscila mucho | Umbral mal calibrado | Recalibrar |
| Solo gira a un lado | Sensor dañado/mal conectado | Verificar conexiones |

## Estado

- [ ] Sensores montados en el chasis
- [ ] Calibración realizada
- [ ] Circuito básico construido
- [ ] Robot sigue línea recta
- [ ] Robot sigue curvas
- [ ] Circuito complejo completado
