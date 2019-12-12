int a = 1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  if(a == 1) {
  Serial.println(" ~~~ ");
  Serial.println("-   -");
  Serial.println("X   X");
  Serial.println(" O   ");
  Serial.println("1___1");
  a = a + 1;
  }
  else {
    delay(100);
  }
}
