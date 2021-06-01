void get_req_head_distance()
{
  int sat_count = gps.satellites.value();
  if (sat_count >= 4)
  {
    gps_heading = TinyGPSPlus::courseTo(gps.location.lat(), gps.location.lng(), desti_lat, desti_lng);
    Serial.print("gps heading");Serial.print(/t);Serial.println(gps_heading);
    if (desti_lat == 00.00)
    {
      distance = 0;
    }
    else
    {
      distance = TinyGPSPlus::distanceBetween(gps.location.lat(), gps.location.lng(), desti_lat, desti_lng);
      Serial.print("distance");Serial.print(/t);Serial.println(distance);
    }
  }
  else
  {
    dead_reckon_flag = 1;
    gps_heading = TinyGPSPlus::courseTo(start_lat, start_lng, desti_lat, desti_lng);
    Serial.print("gps heading");Serial.print(/t);Serial.println(gps_heading);
    if (desti_lat == 00.00)
    {
      distance = 0;
    }
    else
    {
      distance = TinyGPSPlus::distanceBetween(start_lat, start_lng, desti_lat, desti_lng);
      Serial.print("distance");Serial.print(/t);Serial.println(distance);
    }
  }
}
void set_orientation()
{
  mag_heading = get_heading_mag();
  Serial.print("mag heading");Serial.print(/t);Serial.println(mag_heading);
  double delta_head = abs(gps_heading-mag_heading);
  if(delta_head<=10)
  {
    if (digitalRead(18)== HIGH)
    {
      fwd();
      calculate_velo_dist(initial_time);
      
    }
    else
    {
      Stop();
    }
  }
  else
  {
    while(delta_head > 10)
    {
      Stop();
      mag_heading = get_heading_mag();
      int x,y,z;
      x = gps_heading - 360;
      y = mag_heading - x;
      z= y - 360;
      if ((z<=180)&&(z>=0))
      {
        left();
        fwd();
        delay(50);
        Stop();
        mag_heading = get_heading_mag();
        Serial.print("mag heading");Serial.print(/t);Serial.println(mag_heading);
      }
      else
      {
        right();
        fwd();
        delay(50);
        Stop();
        mag_heading = get_heading_mag();
        Serial.print("mag heading");Serial.print(/t);Serial.println(mag_heading);
      }
      
    }
  }
}
void calculate_velo_dist(unsigned long initial_time)
{
  if(dead_reckon_flag ==1)
  {
    unsigned long time_now = millis();
    unsigned long time_delta = (time_now - initial_time);
    imu_values();
    accel = sqrt(sq(X_Axis)+sq(Y_Axis));
    velo  = velo + accel*(time_delta);
    posi =  posi + (velo*time_delta)+(0.5 * accel * sq(time_delta)); 
    distance = distance - posi;
    initial_time = time_now;
    Serial.print("speed");Serial.print(/t);Serial.println(velo);
    Serial.print("posi");Serial.print(/t);Serial.println(posi);
     
  }
  else
  {
    velo = gps.speed.mps();
    distance = TinyGPSPlus::distanceBetween(gps.location.lat(),gps.location.lng(),desti_lat,desti_lng);
  }
  
}
