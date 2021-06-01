#include <MPU6050.h>

#include <TinyGPS++.h>

#include <HMC5883L.h>

#include <SimpleKalmanFilter.h>
//home : 8.918877,76.621402 tkm: 8.9142304,76.6297634
//####################################################################################################################
int relay_s_1 = 23;
int relay_s_2 = 22;
int relay_d_1 = 24;
int relay_d_2 = 25;
int trig_pin_fwd_centre=26;
int echo_pin_fwd_centre=27;
float distance_ultra,duration;
int nxt = 0;
String raw_data_process = "##";
int slot = 0;
int dead_reckon_flag = 0;
unsigned long start_time, initial_time = 0;
unsigned long end_time;
float start_lat, start_lng, desti_lat, desti_lng, gps_heading, distance;
double delta_head, mag_heading, X_Axis, Y_Axis, Z_Axis,accel,velo,posi;
//#####################################################################################################################
SimpleKalmanFilter magneto(1, 1, 0.01);
SimpleKalmanFilter simpleKalmanFilter_imu_X(1, 1, 0.01);
SimpleKalmanFilter simpleKalmanFilter_imu_Y(1, 1, 0.01);
SimpleKalmanFilter simpleKalmanFilter_imu_Z(1, 1, 0.01);
HMC5883L compass;
MPU6050 mpu;
TinyGPSPlus gps;
//#####################################################################################################################
void setup() {
  Serial.begin(9600);
  magnetometre_setup();
  ultrasonic_sensor_setup();
  imu_setup();
  steering_setup();
  drive_motor_setup();
  
  pinMode(18, INPUT_PULLUP);
  while (raw_data_process == "##")
  {
    raw_data_process = get_usr_data();
  }
}

void loop() {

  for (nxt; nxt < 1; nxt++)
  {
    get_data_cleaned(raw_data_process);
     Serial.print(start_lat); Serial.print(","); Serial.print(start_lng); Serial.print("/"); Serial.print(desti_lat); Serial.print(","); Serial.println(desti_lng);
  }
  
  while (desti_lat != 00.00)
  {
    get_req_head_distance();
    while(distance != 0)
    { 
      set_orientation();
    }
    nxt = 0;
  }
}
