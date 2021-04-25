void gps_setup()
{
  Serial1.begin(9600);



}

void gps_getloc()
{
  crnt_lat = (gps.location.lat(),6);
  crnt_lng = (gps.location.lng(),6);

}

int gps_course(float S_latitude,float S_longitude, float D_latitude,float D_longitude )
{
  float course_setting = TinyGPSPlus::courseTo(S_latitude,S_longitude,D_latitude,D_longitude);
  return course_setting;
}
void distance_to_target()
{
 distance_to =  TinyGPSPlus::distanceBetween(gps.location.lat(),gps.location.lng(),desti_lat,desti_lng);
}
