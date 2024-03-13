// →↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓←
// → OSCAR JULIAN NARVAEZ GETIAL ←
// →↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑←

#define LED_GREEN	11
#define LED_RED		12
#define LED_YELLOW	13

bool intermittent = false;

void setup()
{                                                                   
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  while (Serial.available()== 0) {
    if (intermittent) {
      delay(1000);
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      delay(1000);
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
    }
  };
  
  int input = Serial.read() - 48;
  
  if (1 == input) {
    intermittent = false;
    digitalWrite(LED_GREEN, HIGH);
  } else if (2 == input) {
    intermittent = false;
    digitalWrite(LED_GREEN, LOW);
  } else if (3 == input) {
    intermittent = false;
    digitalWrite(LED_RED, HIGH);
  } else if (4 == input) {
    intermittent = false;
    digitalWrite(LED_RED, LOW);
  } else if (5 == input) {
    intermittent = false;
    digitalWrite(LED_YELLOW, HIGH);
  } else if (6 == input) {
    intermittent = false;
    digitalWrite(LED_YELLOW, LOW);
  } else if (7 == input) {
    intermittent = false;
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, HIGH);
  } else if (8 == input) {
    intermittent = false;
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, LOW);
  } else if (9 == input) {
    intermittent = !intermittent;
  }
}