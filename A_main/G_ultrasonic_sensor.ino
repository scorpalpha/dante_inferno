
void ultrasonic_setup()
{
  pinMode(right_trig_pin, OUTPUT);
  pinMode(right_echo_pin, INPUT);
   pinMode(back_trig_pin, OUTPUT);
  pinMode(back_echo_pin, INPUT);
   pinMode(forward_trig_pin, OUTPUT);
  pinMode(forward_echo_pin, INPUT);
   pinMode(left_trig_pin, OUTPUT);
  pinMode(left_echo_pin, INPUT);
}
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
