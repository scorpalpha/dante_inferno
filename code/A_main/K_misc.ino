void check_orientation()
{
  gps_course();
  get_heading_mag();
  if (gps_heading - mag_heading <= orientation_tolerence)
  {
    orientation_check = true;
  }
  else 
  {
    orientation_check = false;
  }
}

void forward_fire()
{
  
}
