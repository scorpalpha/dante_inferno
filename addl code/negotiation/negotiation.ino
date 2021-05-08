int relay_pin1 = 2;
int relay_pin2 = 3;
int relay_pin3 = 4;
int relay_pin4 = 5;
void setup()
{Serial.begin(9600);
  pinMode(relay_pin1,OUTPUT);
  pinMode(relay_pin2,OUTPUT);
  pinMode(relay_pin3,OUTPUT);
  pinMode(relay_pin4,OUTPUT);
 digitalWrite(relay_pin1,HIGH);
 digitalWrite(relay_pin2,HIGH);
 digitalWrite(relay_pin3,HIGH);
 digitalWrite(relay_pin4,HIGH);
}
void back()
{
  
  digitalWrite(relay_pin3,HIGH);
  digitalWrite(relay_pin4,LOW);
}
void fwd()
{
  digitalWrite(relay_pin3,LOW);
  digitalWrite(relay_pin4,HIGH);
}
void Stop()
{
  digitalWrite(relay_pin1,HIGH);
 digitalWrite(relay_pin2,HIGH);
 digitalWrite(relay_pin3,HIGH);
 digitalWrite(relay_pin4,HIGH);
}
void right()
{
   digitalWrite(relay_pin1,LOW);
    digitalWrite(relay_pin2,HIGH);
}
void left()
{
   digitalWrite(relay_pin1,HIGH);
    digitalWrite(relay_pin2,LOW);
}
void left_forward_correction()
{
   digitalWrite(relay_pin1,LOW);
    digitalWrite(relay_pin2,HIGH);
    delay(25);
    digitalWrite(relay_pin1,HIGH);
    digitalWrite(relay_pin2,HIGH);
}
void right_forward_correction()
{
   digitalWrite(relay_pin1,HIGH);
    digitalWrite(relay_pin2,LOW);
    delay(25);
    digitalWrite(relay_pin2,HIGH);
    digitalWrite(relay_pin1,HIGH);
}
void loop()
{
 
  int a= analogRead(A0);
  Serial.println(a);
  if (a>500 && a<524)
  {
   fwd();
   delay(200);
   Stop();
   delay(500);
   back();
   delay(200);
  }
  else if (a < 500){right_forward_correction();}
  else if (a > 500){left_forward_correction();}
 }
