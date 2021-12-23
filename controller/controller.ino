void setup() {
  // put your setup code here, to run once:
  pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(11,INPUT);
  pinMode(10,INPUT);
  pinMode(5,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int a = digitalRead(10);
int b = digitalRead(11);
int c = digitalRead(12);
int d = digitalRead(13);
int left = digitalRead(3);
int right = digitalRead(2);
int up = digitalRead(5);
int down = digitalRead(4);
int dx;
int dy;
if(left == 1) dx = 2;
else if (right == 1) dx = 0;
else dx = 1;
if(up == 1) dy = 2;
else if (down == 1) dy = 0;
else dy = 1;
/* Analog stick statements
int x = analogRead(A0);
int y = analogRead(A1);
if(x > 600)
  dx = 2;
else if (x < 400)
  dx = 0;
else
  dx = 1;
if(y > 600)
  dy = 2;
else if(y < 400)
  dy = 0;
else
  dy = 1;
  */
Serial.print("S");
Serial.print(dx);
Serial.print(",");
Serial.print(dy);
Serial.print(",");
Serial.print(a); 
Serial.print(",");
Serial.print(b); 
Serial.print(",");
Serial.print(c); 
Serial.print(",");
Serial.println(d); 
delay(100);
}
