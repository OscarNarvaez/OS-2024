// →↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓←
// → OSCAR JULIAN NARVAEZ GETIAL ←
// →↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑←

const int LED_REED = 13; 
const int sensorPin = A0;
const int motorPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(LED_REED, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  
  float temperatura = analogRead(sensorPin) * 0.48828125 - 50;

  if (temperatura < 5) {
    digitalWrite(LED_REED, HIGH);
    delay(500);
    digitalWrite(LED_REED, LOW);
    delay(500);
  } else if (temperatura >= 6 && temperatura <= 25) {
    digitalWrite(LED_REED, LOW);
  } else if (temperatura > 25) {
    digitalWrite(LED_REED, HIGH);
    digitalWrite(motorPin, HIGH);
  }
  // TEMPERATURA
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
}