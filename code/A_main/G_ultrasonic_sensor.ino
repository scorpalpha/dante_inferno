
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
  central_trig_pin=22;
 central_echo_pin=24;
}
float get_ultrasonic_value(int trigPin ,int echoPin)
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
return distance;
}
