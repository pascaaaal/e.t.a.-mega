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
  r = 255;
  g = 0;
  b = 0;
}

void loop() {
  for(r && g; r < 256 && g >= 0; r-- && g++) {  //von rot zu grün
    analogWrite(rot, r);
    analogWrite(gruen, g);
    delayMicroseconds(1);
    schreiben();
  }
  for(g && b; g < 256 && b >= 0; g-- && b++) {  //von grün zu blau
    analogWrite(gruen, g);
    analogWrite(blau, b);
    delayMicroseconds(1);
    schreiben();
  }
  for(b && r; b < 256 && r >= 0; b-- && r++) {  //von blau zu rot
    analogWrite(blau, b);
    analogWrite(rot, r);
    delayMicroseconds(1);
    schreiben();
  }

}

void schreiben() {
  Serial.print("rot: ");
  Serial.println(r);
  Serial.print("grün: ");
  Serial.println(g);
  Serial.print("blau: ");
  Serial.println(b);
  Serial.println();
}
