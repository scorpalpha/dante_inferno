int steering_feedback()
{
 int feedback = analogRead(A0);
 return feedback;
 
}
void correction_code()
{ double times=millis();
  while(millis()-times<=1500)
  {
   fwd_right();
  }
  int n = 500; 
  while(steering_feedback()!= 512 )
  {
    if (steering_feedback > 512)
    {
      right();
      delay(n);
      Stop();
      if (n<=100){n = n-25;}
      else{
      n = n -100;}
    }
    else if (steering_feedback()< 512)
    {
      left();
      delay(n);
      Stop();
       if (n<=100){n = n-25;}
      else{
      n = n -100;}
    }
    else 
    {
      break;
    }
    
  }
}

void orientation_correction()
{
  int x = (gps_heading - 360);
  int y = (mag_heading - x);
  int z = (y - 360);
  if (z <=180 && z>=0)
  {
    fwd_left();
    
  }
  else 
  {
    fwd_right();
  }
}
