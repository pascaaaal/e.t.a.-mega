int a = 0;
int b = 0;
int i = 1;


void setup() {
  Serial.begin(9600);
  delay(1000);
  randomSeed(analogRead(A0));

}

void loop() {
  for(i; i < 101; i++) { 
    a = random(1, 1001);
    Serial.println(a);
    if(a > b) {
      b = a;
      delay(5);
    }
    delay(5);
  }
  Serial.println(" ");
  Serial.println("Größte Zahl: ");
  Serial.print(b);
  Serial.println(" ");
  delay(1000);
  while(true) {}
}
