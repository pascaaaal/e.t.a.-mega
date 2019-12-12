int i = 1;
int a = 0;
int b = 0;
boolean x = true;

void setup() {
  Serial.begin(9600);
  delay(1000);
  randomSeed(analogRead(A0));

}

void loop() {
  for(i; i < 601; i++) {
    a = random(1, 7);
    if(a == 6) { 
      b++;
    }
    Serial.println(a);
    delayMicroseconds(1);
  }
  delay(1000);
  if(x == true) {
  Serial.println(" ");
  Serial.print("Anzahl der Treffer: ");
  Serial.print(b);
  x = false;
  delay(1000);
  }
}
