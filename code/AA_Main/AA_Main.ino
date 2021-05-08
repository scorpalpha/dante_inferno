//**************************************************************************************************************************************//
#include <TinyGPS++.h> // Tiny gps++ library for gps 
//**************************************************************************************************************************************//
TinyGPSPlus gps; // creating gps instance
//**************************************************************************************************************************************//
String directions;
int slot;
//**************************************************************************************************************************************//
void setup() 
{
  gps_setup(); // Serial1 is used for gps 
  bt_setup();  // Serial0 is used for bluetooth
  

}

void loop() 
{
  directions= get_usr_data(); //getting user data
  

}