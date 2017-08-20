#include <VirtualWire.h>




const char *per1 = "w";
const char *per2 = "a";
const char *per3 = "d";
const char *per4 = "s";
int val = 0;
int d = 13;
const int per = 4;
void setup() {
  // put your setup code here, to run once:
  vw_set_tx_pin(per);
  vw_setup(2000);
  Serial.begin(9600);
  pinMode(d, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    val = Serial.read();
    if (val == 'w')
    {
      digitalWrite(d, HIGH);
      delay(100);
      digitalWrite(d,LOW);
      vw_send((uint8_t*)per1,strlen(per1));
      vw_wait_tx();
    }
    else if (val == 'a')
    {
      digitalWrite(d, HIGH);
      delay(100);
      digitalWrite(d,LOW);
      vw_send((uint8_t*)per2,strlen(per2));
      vw_wait_tx();
    }
    else if (val == 'd')
    {
      digitalWrite(d, HIGH);
      delay(100);
      digitalWrite(d,LOW);
      vw_send((uint8_t*)per3,strlen(per3));
      vw_wait_tx();
    }
    else if (val == 's')
    {
      digitalWrite(d, HIGH);
      delay(100);
      digitalWrite(d,LOW);
      vw_send((uint8_t*)per4,strlen(per4));
      vw_wait_tx();
    }
  }
  

}
