void ultrasonic_sensor_setup()
{
  pinMode(trig_pin_fwd_centre,OUTPUT);
  pinMode(echo_pin_fwd_centre,INPUT);
}
void get_echo_wat_proof(int trigPin,int echoPin)
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
  distance_ultra = duration*0.034/2;
  
  
  Serial.print(distance_ultra); Serial.print(" ");

return distance_ultra;
}
void normal_ultra(int trigPin, int echoPin)
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
  distance_ultra = duration*0.034/2;
  
  
  Serial.print(distance_ultra); Serial.print(" ");

return distance_ultra;
}
