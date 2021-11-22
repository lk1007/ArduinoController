void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int x = analogRead(A0);
int y = analogRead(A1);
int newx;
int newy;
if(x > 600)
  newx = 2;
else if (x < 400)
  newx = 0;
else
  newx = 1;
if(y > 600)
  newy = 2;
else if(y < 400)
  newy = 0;
else
  newy = 1;
Serial.print("S");
Serial.print(newx);
Serial.print(",");
Serial.print(newy);
Serial.print(",");
Serial.println(digitalRead(13));
delay(50);
}
