#include <MedianFilter.h>

/* Arduino example sketch to control a JSN-SR04T ultrasonic distance sensor with Arduino. No library needed. More info: https://www.makerguides.com */

// Define Trig and Echo pin:
#define trigPin 2
#define echoPin 3

// Define variables:
long duration;
int distance;
MedianFilter val(35,0);


void setup() {
  // Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT_PULLUP);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  // Begin Serial communication at a baudrate of 9600:
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin by setting it LOW:
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
  
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  //Serial.print("Distance = ");
  Serial.print(distance); Serial.print(" ");
  //Serial.println(" cm");
  val.in(distance);
  distance = val.out();
  //Serial.print(" Median value = ");
  Serial.println(distance);
  if(distance <= 20)
  
  {
    digitalWrite(13,HIGH);
  }
  else
  { digitalWrite(13,LOW);
    }
  
  delay(100);
}
