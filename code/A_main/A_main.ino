#include <MedianFilter.h>






#include <SimpleKalmanFilter.h>
#include <TinyGPS++.h>
#include <Wire.h>
#include <HMC5883L.h>
#include <MPU6050.h>



//****************************************************************************************************************************************//
double crnt_lat,corr_crnt_lat;
double crnt_lng,corr_crnt_lng;
String raw_bt_data ="##";
float   start_lat;
float start_lng;
float desti_lat;
float desti_lng;
int slot=0;
float mag_heading;
float gps_heading;
float distance_to;
int relay_pin1 = 2;
int relay_pin2 = 3;
int relay_pin3 = 4;
int relay_pin4 = 5;
int jetson_pin_1;
bool jetson_value;
bool started;
bool orientation_check;
int measurement_uncertainity = 2;
int estimation_uncertainity = 2;
float process_noise = 0.01;
double Time_one=0;
double X_Axis,Y_Axis,Z_Axis,velo_x,velo_y,velo_z,posi_x,posi_y,posi_z;
float position_0,velocity_0, P_0, Q, R,H;
int right_trig_pin = 6;
int left_trig_pin = 7;
int back_trig_pin = 8;
int forward_trig_pin= 9;
int right_echo_pin= 10;
int left_echo_pin= 11 ;
int back_echo_pin=12 ;
int forward_echo_pin=13;
int central_trig_pin=22;
int central_echo_pin=24;
int certain_threshold = 20;
int orientation_tolerence = 15;long duration;
int distance;

//****************************************************************************************************************************************//
TinyGPSPlus gps;
HMC5883L compass;
MPU6050 mpu;
SimpleKalmanFilter simpleKalmanFilter_imu_X (measurement_uncertainity, estimation_uncertainity, process_noise);
SimpleKalmanFilter simpleKalmanFilter_imu_Y (measurement_uncertainity, estimation_uncertainity, process_noise); //kalman filter, requires calibration. 
SimpleKalmanFilter simpleKalmanFilter_imu_Z(measurement_uncertainity, estimation_uncertainity, process_noise); //kalman filter, requires calibration. 
MedianFilter val(35,0);
MedianFilter val1(35,0);
MedianFilter val2(35,0);
MedianFilter val3(35,0);
MedianFilter val4(35,0);
//***************************************************************************************************************************************//
void setup() {
  gps_setup();
  bluetooth_setup();
  magnetometre_setup();
  imu_setup();
  motor_setup();
  jetson_setup();
  ultrasonic_setup();
}

void loop()
{
  
}
  
