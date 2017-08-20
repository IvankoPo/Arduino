#include <Servo.h>
Servo s;
int v = 0;
unsigned int L = 0;
unsigned int R = 0;
unsigned int t = 0;
unsigned int H = 0;
int in1 = 5;
int in2 = 6;
int in3 = 7;
int in4 = 8;
const int trig = 3; 
const int echo = 2; 
void STOP()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);
}
void  drive_forvard()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
}
void turn_right(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in4, LOW);
  digitalWrite(in3, HIGH);
  delay(375);
}
void turn_left(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in4, HIGH);
  digitalWrite(in3, LOW);
  delay(375);
}
void check()
{
  s.write(180);
  delay(100);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  t = pulseIn(echo,HIGH);
  L = t/58;
  s.write(0);
  delay(100);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  t = pulseIn(echo,HIGH);
  R = t/58;
  s.write(90);
  delay(600);
}
void setup() {
  // put your setup code here, to run once:

pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(trig, OUTPUT); 
pinMode(echo, INPUT); 
s.attach(9);
s.write(90);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  drive_forvard();
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  t = pulseIn(echo,HIGH);
  H = t/58;
  if ( H <= 30 ){
    STOP();
  check();
  if (L > R)
  turn_left();
  else turn_right();
  }
  
}
