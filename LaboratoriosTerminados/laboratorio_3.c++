// →↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓←
// → OSCAR JULIAN NARVAEZ GETIAL ←
// →↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑←

#include <LiquidCrystal.h>
#define TMP A0
#define LED_REED 13
#define motor 10
int segundos = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup(){
lcd_1.begin(16, 2);
  Serial.begin(9600);
  pinMode(LED_REED, OUTPUT);
  pinMode(motor, OUTPUT);
  lcd_1.print("........");
}

void loop(){
  float temperatura = analogRead(TMP) * 0.48828125 - 50;
  
lcd_1.setCursor(0, 1);
  lcd_1.print(segundos);
  delay(1100);
  segundos += 1;
  lcd_1.print("   ");
  lcd_1.print(temperatura);
  lcd_1.print(" ");
  
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");
  
  if (isnan(temperatura)) {
    Serial.println("Error al leer el sensor de temperatura.");
    return;
  }

  if (temperatura < 10.0){
    digitalWrite(LED_REED, HIGH);
    delay(500);
    digitalWrite(LED_REED, LOW);
    delay(500);
    digitalWrite(motor, LOW);
    
  } else if (temperatura >= 11.0 && temperatura <= 24.0) {
    digitalWrite(LED_REED, LOW);
    digitalWrite(motor, LOW);
    
  } else if (temperatura > 26.0) {
    digitalWrite(LED_REED, HIGH);
    delay(200);
    digitalWrite(motor, HIGH);
    delay(500);
  }
}