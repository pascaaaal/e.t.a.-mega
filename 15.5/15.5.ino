int i = 100;


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop() {
  for (i; i < 1000; i = i + 50) {
    tone(5, i);
    digitalWrite(13, HIGH);
    Serial.print(i);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
  }
}

//Die LED geht 19 mal an
