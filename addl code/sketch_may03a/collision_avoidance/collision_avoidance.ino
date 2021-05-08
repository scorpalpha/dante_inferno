int trig_left_fwd = 13;
int trig_centr_fwd = 12;
int trig_right_fwd = 11;
int trig_back_left = 10;
int trig_back_right = 9;
int echo_left_fwd = 8;
int echo_centre_fwd =7;
int echo_right_fwd = 6; 
int relay_pin1 = 2;
int relay_pin2 = 3;
int relay_pin3 = 4;
int relay_pin4 = 5;
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

float get_ultrasonic_value(int TRIG_PIN,int ECHO_PIN)
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);  

  const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
  float distance= (duration*0.0344)/2;
  if(duration==0){
    Serial.println("Warning: no pulse from sensor");
  } else {
    Serial.print("ultrasonic_value :");
    
    Serial.println(distance);
    return distance; 
  }
  delay(1000);
}
void fwd()
{
  digitalWrite(relay_pin3,LOW);
    digitalWrite(relay_pin4,HIGH);
}
void setup() 
{
 Serial.begin(9600);
 pinMode(relay_pin1,OUTPUT);
 pinMode(relay_pin2,OUTPUT);
 pinMode(relay_pin3,OUTPUT);
 pinMode(relay_pin4,OUTPUT);
 digitalWrite(relay_pin1,HIGH);
 digitalWrite(relay_pin2,HIGH);
 digitalWrite(relay_pin3,HIGH);
 digitalWrite(relay_pin4,HIGH);
 pinMode(trig_left_fwd,OUTPUT);pinMode(trig_centr_fwd,OUTPUT);pinMode(trig_right_fwd,OUTPUT);
 pinMode(echo_left_fwd,INPUT);pinMode(echo_centre_fwd,INPUT);pinMode(echo_right_fwd,INPUT);
  

}

void loop() 
{ int a = get_ultrasonic_value(trig_left_fwd,echo_left_fwd);
  
}
