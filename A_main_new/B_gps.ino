void gps_setup()
{
  Serial2.begin(9600);
}

void gps_getloc()
{
  crnt_lat = (gps.location.lat(), 6);
  crnt_lng = (gps.location.lng(), 6);

}

void gps_course()
{
  gps_heading = TinyGPSPlus::courseTo(gps.location.lat(), gps.location.lng(), desti_lat, desti_lng);

}
void gps_start_course()
{
  gps_heading = TinyGPSPlus::courseTo(start_lat, start_lng, desti_lat, desti_lng);
}
void distance_to_target_start()
{
  distance_to =  TinyGPSPlus::distanceBetween(start_lat, start_lng, desti_lat, desti_lng);
}
void distance_to_target()
{

  distance_to =  TinyGPSPlus::distanceBetween(gps.location.lat(), gps.location.lng(), desti_lat, desti_lng);
}
void distance_to_target_crnt()
{

  distance_to =  TinyGPSPlus::distanceBetween(crnt_lat, crnt_lng, desti_lat, desti_lng);
}
int check_gps_count()
{
  int count = gps.satellites.value();
  return count;
}
void dead_reckon(float time_val)
{ imu_values();
  int starting_value = 0;
  float delta_time = time_val - initial_time;
  float velocity = X_Axis* delta_time;
  
  positions = positions + (velocity*delta_time) + (0.5*X_Axis*(sq(delta_time)));
  distance_to = distance_to - positions;
  initial_time = time_val;
  
  
}
