const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(4,OUTPUT);
   pinMode(5,OUTPUT);
   pinMode(3,OUTPUT);
   pinMode(2,OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   if (Serial.available())
   {
    Serial.print(Serial.read());
    if ( Serial.read()=="F" && cm > 20)
    {
      fwd();
    } 
    else if (Serial.read()=="R")
    {
      right();
    }
    else if (Serial.read()=="L")
    {
      left();
    }
    else 
    {
      Stop();
    }
   }
   
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
void fwd()
{ 
  pinMode(4,HIGH);
  pinMode(5,LOW);
  
}
void right()
{
  fwd();
  pinMode(3,LOW);
  pinMode(2,HIGH);
}
void left()
{
  fwd();
  pinMode(3,HIGH);
  pinMode(2,LOW);
}
void Stop()
{
  pinMode(3,HIGH);
  pinMode(2,HIGH);pinMode(4,HIGH);
  pinMode(5,HIGH);
}
