int relay_pin1 = 2;
int relay_pin2 = 3;
int relay_pin3 = 4;
int relay_pin4 = 5;
int trig_pin1 = 6;
int echo_pin1 = 7;
int trig_pin2 = 8;
int echo_pin2 = 9;
int trig_pin3 = 10;
int echo_pin3 = 11;
int trig_pin4 = 12;
int echo_pin4 = 13;
int trig_pin5 = 22;
int echo_pin5 = 24;
long duration;
int distance;
#include <MedianFilter.h>
MedianFilter val(35,0);
MedianFilter val1(35,0);
MedianFilter val2(35,0);
MedianFilter val3(35,0);
MedianFilter val4(35,0);
float wat_proof(int trigPin, int echoPin)
{ 
  digitalWrite(trigPin, LOW);
  
  delayMicroseconds(2);

 // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
  duration = pulseIn(echoPin, HIGH,26000);
  
  // Calculate the distance:
  distance = duration*0.034/2;
  
  
  Serial.print(distance); Serial.print(" ");
 switch(trigPin)
 {
  case 4:
  val.in(distance);
  distance = val.out();
  break;
  case 6:
  val1.in(distance);
  distance = val1.out();
  break;
  case 8:
  val2.in(distance);
  distance = val2.out();
  break;
  case 10:
  val3.in(distance);
  distance = val3.out();
  break;
  case 12:
  val4.in(distance);
  distance = val4.out();
  break;
 }
 Serial.println(distance);
return distance;
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
void setup() 
{ pinMode(trig_pin1,OUTPUT);
  pinMode(trig_pin2,OUTPUT);
  pinMode(trig_pin3,OUTPUT);
  pinMode(trig_pin4,OUTPUT);
  pinMode(trig_pin5,OUTPUT);
  pinMode(echo_pin1,INPUT_PULLUP);
  pinMode(echo_pin2,INPUT_PULLUP);
  pinMode(echo_pin3,INPUT_PULLUP);
  pinMode(echo_pin4,INPUT_PULLUP);
  pinMode(echo_pin5,INPUT);
  pinMode(relay_pin1,OUTPUT);
  pinMode(relay_pin2,OUTPUT);;
 pinMode(relay_pin3,OUTPUT);
 pinMode(relay_pin4,OUTPUT);
 digitalWrite(relay_pin1,HIGH);
 digitalWrite(relay_pin2,HIGH);
 digitalWrite(relay_pin3,HIGH);
 digitalWrite(relay_pin4,HIGH);
  Serial.begin(9600);
}

void checker()
{
  float one = wat_proof(trig_pin1,echo_pin1);
  //float two = wat_proof(trig_pin2,echo_pin2);
  //float three = wat_proof(trig_pin3,echo_pin3);
  //float four = wat_proof(trig_pin4,echo_pin4);
  if(one <= 50)
  {
    Stop();
  }
  else
  {
    fwd();
   
  }
 
}
void loop() 
{
 checker();
}
