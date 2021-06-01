void imu_setup()
{
  Serial.println("Initialize MPU6050");

  while (!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }

  // If you want, you can set accelerometer offsets
  // mpu.setAccelOffsetX();
  // mpu.setAccelOffsetY();
  // mpu.setAccelOffsetZ();

  checkSettings();
  caliberateIMU();
   for(int i =0; i<1000;i++)
  {
    imu_values();
  }
}


void checkSettings()
{
  Serial.println();

  Serial.print(" * Sleep Mode:            ");
  Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");

  Serial.print(" * Clock Source:          ");
  switch (mpu.getClockSource())
  {
    case MPU6050_CLOCK_KEEP_RESET:     Serial.println("Stops the clock and keeps the timing generator in reset"); break;
    case MPU6050_CLOCK_EXTERNAL_19MHZ: Serial.println("PLL with external 19.2MHz reference"); break;
    case MPU6050_CLOCK_EXTERNAL_32KHZ: Serial.println("PLL with external 32.768kHz reference"); break;
    case MPU6050_CLOCK_PLL_ZGYRO:      Serial.println("PLL with Z axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_YGYRO:      Serial.println("PLL with Y axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_XGYRO:      Serial.println("PLL with X axis gyroscope reference"); break;
    case MPU6050_CLOCK_INTERNAL_8MHZ:  Serial.println("Internal 8MHz oscillator"); break;
  }

  Serial.print(" * Accelerometer:         ");
  switch (mpu.getRange())
  {
    case MPU6050_RANGE_16G:            Serial.println("+/- 16 g"); break;
    case MPU6050_RANGE_8G:             Serial.println("+/- 8 g"); break;
    case MPU6050_RANGE_4G:             Serial.println("+/- 4 g"); break;
    case MPU6050_RANGE_2G:             Serial.println("+/- 2 g"); break;
  }

}
void imu_values()
{
  Vector rawAccel = mpu.readRawAccel();
  Vector normAccel = mpu.readNormalizeAccel();
  X_Axis = normAccel.XAxis;
  Y_Axis = normAccel.YAxis;
  Z_Axis = normAccel.ZAxis;
  X_Axis = simpleKalmanFilter_imu_X.updateEstimate(X_Axis);
  Y_Axis = simpleKalmanFilter_imu_Y.updateEstimate(Y_Axis);
  Z_Axis = simpleKalmanFilter_imu_Z.updateEstimate(Z_Axis);

}
void caliberateIMU()
{
  int minX = 0;
  int maxX = 0;
  int minY = 0;
  int maxY = 0;
  int offX = 0;
  int offY = 0;

  for (int i = 1000; i >= 1; i--)
  {
    Vector imu = mpu.readNormalizeAccel();                                 // Read compass data

    // Determine Min / Max values
    if (imu.XAxis < minX) minX = imu.XAxis;
    if (imu.XAxis > maxX) maxX = imu.XAxis;
    if (imu.YAxis < minY) minY = imu.YAxis;
    if (imu.YAxis > maxY) maxY = imu.YAxis;

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
  mpu.setAccelOffsetX(offX);
  mpu.setAccelOffsetY(offY);                              // Set calibration offset
}
