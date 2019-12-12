int rot = 11;
int gruen = 10;
int blau = 9;
int r = 0;
int g = 0;
int b = 0;


void setup() {
  Serial.begin(9600);
  pinMode(rot, OUTPUT);
  pinMode(gruen, OUTPUT);
  pinMode(blau, OUTPUT);
}

void loop() {
  tuerkis();
  delay(1000);
}

void tuerkis() {
  r = 64;
  g = 224;
  b = 204;
  analogWrite(rot, r);
  analogWrite(gruen, g);
  analogWrite(blau, b);
}
