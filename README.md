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
```

---

## Estructura del proyecto

```
eigenrobotics/
├── hardware/          # Lista de componentes
├── proyectos/
│   ├── p0-blink/
│   ├── p1-semaforo/
│   ├── p2-nave-luces/
│   ├── p3-alarma/
│   ├── p4-girasol/
│   └── p5-robot/
└── 3d-prints/         # STLs y adaptadores
```

---

## Equipo

- **Constructor jefe:** Hugo (7 años) - LEGO, pruebas, ideas
- **Programador:** Papá + Claude Code - Arduino, electrónica

---

## Estado actual

| Proyecto | Estado |
|----------|--------|
| P0 Blink | Pendiente |
| P1 Semáforo | Pendiente |
| P2 Nave | Pendiente |
| P3 Alarma | Pendiente |
| P4 Girasol | Pendiente |
| P5 Robot | Pendiente |
