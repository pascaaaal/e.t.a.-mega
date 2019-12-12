int a = 0;
int b = 0;

void setup() {
  Serial.begin(9600);
  delay(1000);

}

void loop() {
  a = random(1, 21);
  b = random(1, 21);
  if(a == b) {
    b = random(1, 21);
  }
  Serial.print(a);
  Serial.print(" und ");
  Serial.print(b);
  Serial.println(" ");
  delay(1000);

}
