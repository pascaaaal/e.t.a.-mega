int led = 9;
int i = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);
}


void loop() {
  for(i; i < 256; i++) {
    analogWrite(led, i);
    Serial.println(i);
    delay(5);
    
  }
for(i; i > 1; i--) {
      analogWrite(led, i);
      Serial.println(i);
      delay(5);
    }
}
