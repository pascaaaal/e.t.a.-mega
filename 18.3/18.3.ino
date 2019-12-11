//Config vars definieren
int grun = 13;
int blau = 12;
int rot = 11;
int input = A0;

int stufe1 = 100;
int stufe2 = 250;

void setup() {
  //Alle Ports definieren
  pinMode(A0, INPUT);

  pinMode(grun, OUTPUT);
  pinMode(blau, OUTPUT);
  pinMode(rot, OUTPUT);
}

void loop() {
  int a = analogRead(input); //Sensor lesen

  clear(); //alte Anzeige löschen
  
  if(a > stufe1 && a < stufe2) { //Stufe1
    digitalWrite(grun, HIGH); //Grün an
  } else if(a >= stufe2) { //Stufe2
    digitalWrite(blau, HIGH); //Blau an
  } else { //Alles andere also kleiner als Stufe 1
    blink(rot, 100); //Rot blink
  }
}
//Einfache clear funktion, yk
void clear() {
  digitalWrite(blau, LOW);
  digitalWrite(rot, LOW);
  digitalWrite(grun, LOW);
}

//Einfach blink funktion, yk
void blink(int port, long d) {
  digitalWrite(port, HIGH);
  delay(d);
  digitalWrite(port, LOW);
  delay(d);
}
