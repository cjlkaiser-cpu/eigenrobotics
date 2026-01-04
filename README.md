# EigenRobotics

Proyectos de robótica Arduino + LEGO para aprender haciendo.

## Filosofía

**Piano piano.** Cada proyecto construye sobre el anterior. Sin prisas, sin saltar pasos.

**LEGO como estructura.** El niño construye, el padre programa. Cada uno aporta su dominio.

**Hardware desde el día 1.** Nada de simuladores. Un LED parpadeando en la mesa vale más que mil en pantalla.

**Código mínimo, resultado máximo.** Cada sketch hace una cosa bien. Si no cabe en una pantalla, es demasiado complejo.

---

## Roadmap

```
NIVEL 0 - Setup
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
[P0] Blink                              ← EMPEZAR AQUÍ
     LED parpadeante
     Conceptos: digitalWrite, delay, loop
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

NIVEL 1 - Outputs
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
[P1] Semáforo LEGO
     3 LEDs en secuencia
     Conceptos: múltiples outputs, timing
     Construcción: torre/poste LEGO

[P2] Nave con Luces
     LEDs controlados con potenciómetro
     Conceptos: analogWrite (PWM), analogRead
     Construcción: nave/casa/vehículo LEGO
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

NIVEL 2 - Inputs + Outputs
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
[P3] Alarma de Fortaleza
     Sensor ultrasonido + buzzer
     Conceptos: HC-SR04, condicionales
     Construcción: castillo/fortaleza LEGO
     Juego: ¡no actives la alarma!

[P4] Girasol Robot
     2 LDRs + servo que sigue la luz
     Conceptos: comparar sensores, servos
     Construcción: flor LEGO articulada
     Imprimir: adaptador servo-LEGO
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

NIVEL 3 - Movimiento
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
[P5] Robot Explorador
     2 motores DC + sensor obstáculos
     Conceptos: driver L298N, PWM motores
     Construcción: chasis LEGO Technic
     Juego: construye laberintos
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

NIVEL 4 - Control Inalámbrico
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
[P6] Control Remoto IR
     Mando infrarrojo + receptor
     Conceptos: IRremote, decodificación
     Juego: controla LEDs o robot a distancia

[P7] Brazo Robótico
     3 servos + pinza articulada
     Conceptos: múltiples servos, secuencias
     Construcción: brazo LEGO Technic
     Juego: agarrar objetos
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

NIVEL 5 - Proyectos Avanzados
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
[P8] Seguidor de Línea
     2 sensores IR + robot móvil
     Conceptos: calibración, control
     Construcción: circuito con cinta negra

[P9] Display LCD
     Pantalla 16x2 con I2C
     Conceptos: I2C, caracteres personalizados
     Juego: mensajes y datos en pantalla

[P10] Comunicación Serial
      Control desde ordenador
      Conceptos: protocolo, comandos
      Extensión: Python, interfaces gráficas
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
```

---

## Estructura del proyecto

```
eigenrobotics/
├── hardware/            # Lista de componentes
├── proyectos/
│   ├── p0-blink/
│   ├── p1-semaforo/
│   ├── p2-nave-luces/
│   ├── p3-alarma/
│   ├── p4-girasol/
│   ├── p5-robot/
│   ├── p6-control-remoto/
│   ├── p7-brazo-robotico/
│   ├── p8-seguidor-linea/
│   ├── p9-lcd/
│   └── p10-comunicacion/
└── 3d-prints/           # STLs y adaptadores
```

---

## Equipo

- **Constructor jefe:** El niño - LEGO, pruebas, ideas
- **Programador:** Papá/Mamá + Claude Code - Arduino, electrónica

---

## Estado actual

| Proyecto | Nivel | Estado |
|----------|-------|--------|
| P0 Blink | 0 | Pendiente |
| P1 Semáforo | 1 | Pendiente |
| P2 Nave | 1 | Pendiente |
| P3 Alarma | 2 | Pendiente |
| P4 Girasol | 2 | Pendiente |
| P5 Robot | 3 | Pendiente |
| P6 Control IR | 4 | Pendiente |
| P7 Brazo | 4 | Pendiente |
| P8 Seguidor | 5 | Pendiente |
| P9 LCD | 5 | Pendiente |
| P10 Serial | 5 | Pendiente |

---

## Material recomendado

Ver [hardware/lista-compras.md](hardware/lista-compras.md) para lista completa.

**Kit básico:** ELEGOO Super Starter Kit (~35€) - cubre P0-P6

**Adicional para P5-P8:** Motores DC, driver L298N, sensores IR línea

**Adicional para P7:** Servos extra SG90/MG90S

**Adicional para P9:** Display LCD 16x2 I2C

---

## Contribuir

¿Tienes ideas para nuevos proyectos? ¡Abre un issue o PR!
