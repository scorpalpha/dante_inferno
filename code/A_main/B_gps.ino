void gps_setup()
{
  Serial1.begin(9600);



}

void gps_getloc()
{
  crnt_lat = (gps.location.lat(),6);
  crnt_lng = (gps.location.lng(),6);

}

void gps_course()
{
  gps_heading = TinyGPSPlus::courseTo(gps.location.lat(),gps.location.lng(),desti_lat,desti_lng);
  
}
void distance_to_target()
{
 distance_to =  TinyGPSPlus::distanceBetween(gps.location.lat(),gps.location.lng(),desti_lat,desti_lng);
}
