void magnetometre_setup()
{

  // Initialize Initialize HMC5883L
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
  calibrateCompass();
  start_time = millis();
  end_time = start_time;
  for(int i =0; i<1000;i++)
  {
    get_heading_mag();
  }
  
}
double get_heading_mag()
{ Vector norm = compass.readNormalize();

  // Calculate heading
  double heading = atan2(norm.YAxis, norm.XAxis);

  // Set declination angle on your location and fix heading
  // You can find your declination on: http://magnetic-declination.com/
  // (+) Positive or (-) for negative
  // For Bytom / Poland declination angle is 4'26E (positive)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  double declinationAngle = (1 - (53.0 / 60.0)) / (180 / M_PI);
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
  double headingDegrees = heading * 180 / M_PI;
  return headingDegrees;
}
void calibrateCompass()                                           // Experimental Use Only to Calibrate Magnetometer/ Compass
{
  int minX = 0;
  int maxX = 0;
  int minY = 0;
  int maxY = 0;
  int offX = 0;
  int offY = 0;

  for (int i = 1000; i >= 1; i--)
  {
    Vector mag = compass.readRaw();                                 // Read compass data

    // Determine Min / Max values
    if (mag.XAxis < minX) minX = mag.XAxis;
    if (mag.XAxis > maxX) maxX = mag.XAxis;
    if (mag.YAxis < minY) minY = mag.YAxis;
    if (mag.YAxis > maxY) maxY = mag.YAxis;

    offX = (maxX + minX) / 2;                                       // Calculate offsets
    offY = (maxY + minY) / 2;

    delay(10);
    //Serial.print("Compass X & Y offset: ");
    //Serial.print(offX);
    //Serial.print(" ");
    //Serial.print(offY);
    //Serial.print("\n");

  }                                                               // end of for loop



  Serial.print("Compass X & Y offset: ");
    Serial.print(offX);
    Serial.print(" ");
    Serial.print(offY);
    Serial.print("\n");
  compass.setOffset(offX, offY);                                 // Set calibration offset
}
