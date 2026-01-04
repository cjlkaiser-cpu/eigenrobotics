/*
 * P9: Display LCD - EigenRobotics
 *
 * Pantalla LCD 16x2 con comunicación I2C.
 * Muestra mensajes, datos de sensores, animaciones.
 *
 * Conceptos:
 * - Display LCD 16x2
 * - Comunicación I2C
 * - Librería LiquidCrystal_I2C
 * - Caracteres personalizados
 *
 * Circuito:
 * - LCD I2C: VCC->5V, GND->GND, SDA->A4, SCL->A5
 *
 * Instalación librería:
 * - Arduino IDE: Tools > Manage Libraries
 * - Buscar "LiquidCrystal I2C" por Frank de Brabander
 * - Instalar
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección I2C del LCD (prueba 0x27 o 0x3F)
const int LCD_ADDR = 0x27;

// Inicializar LCD: dirección, columnas, filas
LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

// Caracteres personalizados (5x8 píxeles)
byte caritaFeliz[] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B01110,
  B00000,
  B00000
};

byte caritaTriste[] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B01110,
  B10001,
  B00000,
  B00000
};

byte corazon[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

void setup() {
  Serial.begin(9600);
  Serial.println("LCD I2C - EigenRobotics");

  // Iniciar LCD
  lcd.init();
  lcd.backlight();  // Encender luz de fondo

  // Crear caracteres personalizados
  lcd.createChar(0, caritaFeliz);
  lcd.createChar(1, caritaTriste);
  lcd.createChar(2, corazon);

  // Mensaje inicial
  lcd.setCursor(0, 0);  // Columna 0, Fila 0
  lcd.print("EigenRobotics");

  lcd.setCursor(0, 1);  // Columna 0, Fila 1
  lcd.print("Hola Mundo! ");
  lcd.write(0);  // Carita feliz

  Serial.println("LCD inicializado correctamente");

  delay(3000);
}

void loop() {
  // Demo 1: Contador
  demoContador();

  // Demo 2: Caracteres personalizados
  demoCaracteres();

  // Demo 3: Texto desplazándose
  demoScrolling();
}

void demoContador() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Contador:");

  for (int i = 0; i <= 10; i++) {
    lcd.setCursor(0, 1);
    lcd.print(i);
    lcd.print("   ");  // Limpiar dígitos anteriores
    delay(500);
  }
}

void demoCaracteres() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Caracteres:");

  lcd.setCursor(0, 1);
  lcd.write(0);  // Feliz
  lcd.print(" ");
  lcd.write(1);  // Triste
  lcd.print(" ");
  lcd.write(2);  // Corazón
  lcd.print(" ");
  lcd.write(0);
  lcd.write(2);
  lcd.write(0);

  delay(3000);
}

void demoScrolling() {
  lcd.clear();
  String mensaje = "Proyecto EigenRobotics - Arduino + LEGO ";

  lcd.setCursor(0, 0);
  lcd.print("Scrolling:");

  // Mostrar mensaje desplazándose
  for (int i = 0; i < mensaje.length() - 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print(mensaje.substring(i, i + 16));
    delay(200);
  }
}

// ==================== FUNCIONES ÚTILES ====================

void mostrarEnLCD(String linea1, String linea2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(linea1);
  lcd.setCursor(0, 1);
  lcd.print(linea2);
}

// ==================== ESCÁNER I2C ====================

void escanerI2C() {
  Serial.println("Escaneando dispositivos I2C...");

  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Dispositivo encontrado en 0x");
      Serial.println(addr, HEX);
    }
  }

  Serial.println("Escaneo completado");
}

/*
 * SI EL LCD NO FUNCIONA:
 *
 * 1. Descomenta la línea en setup():
 *      escanerI2C();
 *    Abre Monitor Serial y mira la dirección
 *
 * 2. Cambia LCD_ADDR al valor encontrado
 *
 * 3. Si solo ves cuadros negros, gira el potenciómetro
 *    pequeño en la parte trasera del módulo I2C
 *
 * EXPERIMENTOS:
 *
 * 1. Diseña tus propios caracteres (robot, nave, etc.)
 * 2. Muestra temperatura de un sensor
 * 3. Crea un cronómetro con botón start/stop
 * 4. Haz un menú navegable con botones
 * 5. Integra con P3 para mostrar distancia
 */
