int trig_pin1 = 13;
int trig_pin2 = 12;
int trig_pin3 = 11;
int trig_pin4 = 10;
int trig_pin5 = 9;
int echo_pin1 = 8;
int echo_pin2 = 7;
int echo_pin3 = 6;
int echo_pin4 = 5;
int echo_pin5 = 4;


float get_ultrasonic_value(int TRIG_PIN,int ECHO_PIN)
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);  

  const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
  float distance= duration/29/2;
  if(duration==0){
    Serial.println("Warning: no pulse from sensor");
  } else {
    Serial.print("ultrasonic_value :");
    
    Serial.println(distance);
    return distance; 
  }
  delay(100);
}
void setup()
{
  pinMode(trig_pin1,OUTPUT);
  pinMode(trig_pin2,OUTPUT);
  pinMode(trig_pin3,OUTPUT);
  pinMode(trig_pin4,OUTPUT);
  pinMode(trig_pin5,OUTPUT);
  pinMode(echo_pin1,INPUT);
  pinMode(echo_pin2,INPUT);
  pinMode(echo_pin3,INPUT);
  pinMode(echo_pin4,INPUT);
  pinMode(echo_pin5,INPUT);
}
void loop()
{
  get_ultrasonic_value(trig_pin1,echo_pin1);
  get_ultrasonic_value(trig_pin2,echo_pin2);
  get_ultrasonic_value(trig_pin3,echo_pin3);
  get_ultrasonic_value(trig_pin4,echo_pin4);
  get_ultrasonic_value(trig_pin5,echo_pin5);
  
}
