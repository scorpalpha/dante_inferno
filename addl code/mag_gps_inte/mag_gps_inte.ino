#include <SimpleKalmanFilter.h>

#include <TinyGPS++.h>


#include <Wire.h>
#include <HMC5883L.h>


HMC5883L compass;
TinyGPSPlus gps;
SimpleKalmanFilter kalman(1,1,0.01); 

void setup()
{
  Serial.begin(9600);

  // Initialize Initialize HMC5883L
  //Serial.println("Initialize HMC5883L");
  while (!compass.begin())
  {
    //Serial.println("Could not find a valid HMC5883L sensor, check wiring!");
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
  compass.setOffset(183, -33);
}

void loop()
{
  Vector norm = compass.readNormalize();

  // Calculate heading
  float heading = atan2(norm.YAxis, norm.XAxis);

  // Set declination angle on your location and fix heading
  // You can find your declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative
  // For Bytom / Poland declination angle is 4'26E (positive)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  float declinationAngle = (-1 + (53.0 / 60.0)) / (180 / M_PI);
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
  float headingDegrees = heading * 180/M_PI; delay(10); 

  // Output
  float gps_heading = gps.courseTo(8.918877,76.621402,8.9142304,76.6297634);
  //Serial.print(" Heading = ");
  //Serial.print(heading);
  //Serial.print("gps = ");
  //Serial.print(gps_heading);
  Serial.print(" Degress = ");
  Serial.print(headingDegrees);
  Serial.print(" ");
  Serial.println(kalman.updateEstimate(headingDegrees));
  //Serial.println();

  delay(100);
}
