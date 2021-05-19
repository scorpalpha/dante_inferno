void plot()
{
  distance_to_target();
  gps_course();

}
void plot_start()
{
  gps_start_course();
  distance_to_target_start();

}

void check_orientation()
{ get_heading_mag();
  Serial.print(gps_heading); Serial.print(" ");
  Serial.println(mag_heading);

  if (abs(gps_heading - mag_heading) <= orientation_tolerence)
  {
    orientation_check = true;
  }
  else
  {
    orientation_check = false;
  }
}
void correct_orientation()
{
  int x = (gps_heading - 360);
  int y = (mag_heading - x);
  int z = (y - 360);
  if ((z <= 180) && (z >= 0))
  {
    left();
    fwd();
  }
  else
  {
    right();
    fwd();
  }
  check_orientation();
  Serial.print(gps_heading); Serial.print(" "); Serial.println(mag_heading);
}
