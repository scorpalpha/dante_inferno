




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
int motor_drive_1= 13;
int motor_drive_2= 12;
int steering_motor_1= 11;
int steering_motor_2= 10;
int jetson_pin_1;
bool jetson_value;
bool started;
int measurement_uncertainity = 2;
int estimation_uncertainity = 2;
float process_noise = 0.01;
double Time_one=0;
double X_Axis,Y_Axis,Z_Axis,velo_x,velo_y,velo_z,posi_x,posi_y,posi_z;
float position_0,velocity_0, P_0, Q, R,H;
int right_trig_pin = 9;
int left_trig_pin = 8;
int back_trig_pin = 7;
int forward_trig_pin= 6;
int right_echo_pin= 5;
int left_echo_pin= 4;
int back_echo_pin=3;
int forward_echo_pin=2;
int certain_threshold = 20;
//****************************************************************************************************************************************//
TinyGPSPlus gps;
HMC5883L compass;
MPU6050 mpu;
SimpleKalmanFilter simpleKalmanFilter_imu_X (measurement_uncertainity, estimation_uncertainity, process_noise);
SimpleKalmanFilter simpleKalmanFilter_imu_Y (measurement_uncertainity, estimation_uncertainity, process_noise); //kalman filter, requires calibration. 
SimpleKalmanFilter simpleKalmanFilter_imu_Z(measurement_uncertainity, estimation_uncertainity, process_noise); //kalman filter, requires calibration. 

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
  while(raw_bt_data == "##")
  {
    get_data_usr();
  }
  get_data_cleaned(raw_bt_data);
  
  while(desti_lat!=000000 && desti_lng!=000000)
  {
    while(gps.satellites.value()<4 && started==false)
    {
      Stop();
      
    }
    started = true;
    distance_to_target();
    while(distance_to!=0)
    { gps_getloc();
      gps_heading=gps_course(crnt_lat,crnt_lng,desti_lat,desti_lng);
      get_heading_mag();
      check_orientation:
      if(abs(gps_heading-mag_heading)<=15)
      {
        jetson_read();
        if(jetson_value==HIGH)
        {
          forward();
          distance_to_target();
        }
        else if (jetson_value==LOW)
        {  check_right:
          if(get_ultrasonic_value(right_trig_pin,right_echo_pin)>certain_threshold)
          {
            correction_code();
            goto check_orientation;
          }
          else
          {
           Stop();
           if (get_ultrasonic_value(back_trig_pin,back_echo_pin)>certain_threshold)
           {
             reverse();
             goto check_right;
             
           }
          }
        }
        
      }
      else 
      {
        while(abs(gps_heading - mag_heading)>15)
        {
          orientation_correction();
          delay(500);
          get_heading_mag();
        }
      }
      
    }
    Stop();
    
  }
}
  
