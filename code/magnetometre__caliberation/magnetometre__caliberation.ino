#include <Wire.h>
#include <HMC5883L.h>

HMC5883L compass;

int minX = 0;
int maxX = 0;
int minY = 0;
int maxY = 0;
int offX = 0;
int offY = 0;

void setup() {
Serial.begin(9600);

  // Initialize Initialize HMC5883L
  while (!compass.begin())
  {
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

}

void loop() {
   Vector mag = compass.readRaw();
  if (mag.XAxis < minX) minX = mag.XAxis;
  if (mag.XAxis > maxX) maxX = mag.XAxis;
  if (mag.YAxis < minY) minY = mag.YAxis;
  if (mag.YAxis > maxY) maxY = mag.YAxis;
  offX = (maxX + minX)/2;
  offY = (maxY + minY)/2;
  avg_delta=(offX+offY)/2;
  scaleX = avg_delta/offX;
  scaleY = avg_delta/offY;
  corrected_X = (mag.XAxis - offX)*scaleX;
  corrected_Y = (mag.YAxis - offY)*scaleY;
  Serial.print("Offset_X :");
  Serial.print(offX);
  Serial.print("Offset_Y :");
  Serial.print(offY);
  Serial.print("corrected_X :");
  Serial.print(corrected_X);
  Serial.print("corrected_Y :");
  Serial.print(corrected_Y);
  delay(1000);





  

}
