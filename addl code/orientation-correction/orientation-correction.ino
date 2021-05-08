int relay_pin1 = 2;
int relay_pin2 = 3;
int relay_pin3 = 4;
int relay_pin4 = 5;
float degr;
#include <Wire.h>
#include <HMC5883L.h>

HMC5883L compass;

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
 Serial.println("Initialize HMC5883L");
  while (!compass.begin())
  {
    Serial.println("Could not find a valid HMC5883L sensor, check wiring!");
    delay(500);
  }

  // Set measurement range
  compass.setRange(HMC5883L_RANGE_1_3GA);

  // Set measurement mode
  compass.setMeasurementMode(HMC5883L_CONTINOUS);

  // Set data rate
  compass.setDataRate(HMC5883L_DATARATE_30HZ);

  // Set number of samples averaged
  compass.setSamples(HMC5883L_SAMPLES_8);

  // Set calibration offset. See HMC5883L_calibration.ino
  compass.setOffset(0, 0);
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
float orien()
{Vector norm = compass.readNormalize();

  // Calculate heading
  float heading = atan2(norm.YAxis, norm.XAxis);

  // Set declination angle on your location and fix heading
  // You can find your declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative
  // For Bytom / Poland declination angle is 4'26E (positive)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / M_PI);
  heading += declinationAngle;

  // Correct for heading < 0deg and heading > 360deg
  if (heading < 0)
  {
    heading += 2 * PI;
  }

  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }

  // Convert to degrees
  float headingDegrees = heading * 180/M_PI; 
  return headingDegrees;
  }
void loop() 
{ Serial.println(orien());   
   if( 10 < orien() && orien()< 170  )
   {Serial.println(orien());
    left();
    fwd();
    delay(500);
    
   
   }
   else if ( orien() < 370 && orien() > 190 ){Serial.println(orien());right();fwd();delay(500);}    
  else 
  {
    Stop();
  }
   
}
