# P7: Brazo Robótico

Brazo articulado con 3 servos: base, codo y pinza. ¡Agarra objetos!

## Objetivo

Controlar múltiples servos coordinados. Introducir cinemática básica y secuencias de movimiento.

## Conceptos

- Control de múltiples servos
- Movimiento coordinado
- Secuencias programadas
- Potenciómetros para control manual

## Material

- Arduino UNO
- 3x Servo SG90 (o MG90S para más fuerza)
- 3x Potenciómetro 10kΩ (para control manual)
- Fuente externa 5V (recomendado para 3+ servos)
- Estructura LEGO Technic o impresa 3D
- **Imprimir:** Pinza para servo, articulaciones

## Esquema

```
Servos:
  Base (giro horizontal) → Pin 9
  Codo (arriba/abajo) → Pin 10
  Pinza (abrir/cerrar) → Pin 11

  Todos los servos:
    Rojo → 5V (fuente externa recomendada)
    Marrón → GND (común con Arduino)
    Naranja → Pin señal

Potenciómetros (modo manual):
  Pot Base → A0
  Pot Codo → A1
  Pot Pinza → A2

  Cada pot: extremos a 5V y GND, centro al pin A
```

**IMPORTANTE:** Con 3 servos, el pin 5V del Arduino puede no dar suficiente corriente. Usa fuente externa de 5V para los servos, con GND común.

## Rol del niño

- CONSTRUIR: Brazo con LEGO Technic o piezas impresas
- CONTROLAR: Mover potenciómetros como joysticks
- PROGRAMAR: Decidir qué secuencias grabar
- JUGAR: ¡Agarrar objetos pequeños!

## Modos de operación

1. **Manual:** Los potenciómetros controlan cada articulación
2. **Secuencia:** Ejecuta movimientos pregrabados
3. **Grabación:** Guarda posiciones y las reproduce

## Código

```cpp
// Ver archivo p7_brazo_robotico.ino
```

## Ideas de construcción

- **LEGO Technic:** Vigas y conectores para estructura
- **Impresión 3D:** Buscar "robot arm servo" en Thingiverse
- **Híbrido:** Base LEGO, pinza impresa

## Piezas 3D recomendadas

Buscar en Thingiverse:
- "SG90 robot arm" - brazos completos
- "SG90 gripper" - solo pinza
- "servo bracket" - soportes para montar servos

## El juego

1. Poner objetos pequeños (LEGO, canicas) en la mesa
2. Mover el brazo con potenciómetros
3. Agarrar y mover objetos de un lado a otro
4. Competición: ¿cuántos objetos en 1 minuto?

## Experimentos

- [ ] Control manual con 3 potenciómetros
- [ ] Grabar y reproducir una secuencia
- [ ] Añadir botón para "posición inicial"
- [ ] Integrar control IR (P6) para mover el brazo
- [ ] Añadir 4º servo para rotación de muñeca

## Precauciones

- Los servos consumen mucha corriente al moverse
- Si se reinicia el Arduino, usa fuente externa
- No fuerces los servos contra topes mecánicos
- Los servos SG90 son débiles, no cargar mucho peso

## Estado

- [ ] Estructura del brazo construida
- [ ] Servos montados y cableados
- [ ] Fuente externa conectada (si necesario)
- [ ] Control manual funcionando
- [ ] Secuencias programadas
- [ ] ¡Agarrando objetos!
