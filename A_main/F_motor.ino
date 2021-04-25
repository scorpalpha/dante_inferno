void motor_setup()
{
 pinMode(motor_drive_1,OUTPUT);
 pinMode(motor_drive_2,OUTPUT);
 pinMode(steering_motor_1,OUTPUT);
 pinMode( steering_motor_2,OUTPUT);
 digitalWrite(motor_drive_1,HIGH);
 digitalWrite(motor_drive_2,HIGH);
 digitalWrite(steering_motor_1,HIGH);
 digitalWrite(steering_motor_2,HIGH);
 
 
}
void Stop()
{
  digitalWrite(motor_drive_1,HIGH);
 digitalWrite(motor_drive_2,HIGH);
 digitalWrite(steering_motor_1,HIGH);
 digitalWrite(steering_motor_2,HIGH);
}
void forward()
{
  digitalWrite(motor_drive_1,LOW);
  digitalWrite(motor_drive_2,HIGH);
  digitalWrite(steering_motor_1,HIGH);
  digitalWrite(steering_motor_2,HIGH);
}
void reverse()
{
   digitalWrite(motor_drive_1,HIGH);
  digitalWrite(motor_drive_2,LOW);
  digitalWrite(steering_motor_1,HIGH);
  digitalWrite(steering_motor_2,HIGH);
}
void fwd_right()
{
   digitalWrite(motor_drive_1,LOW);
  digitalWrite(motor_drive_2,HIGH);
  digitalWrite(steering_motor_1,LOW);
  digitalWrite(steering_motor_2,HIGH);
}
void fwd_left()
{
   digitalWrite(motor_drive_1,LOW);
  digitalWrite(motor_drive_2,HIGH);
  digitalWrite(steering_motor_1,HIGH);
  digitalWrite(steering_motor_2,LOW);
}
void reverse_right()
{
   digitalWrite(motor_drive_1,HIGH);
  digitalWrite(motor_drive_2,LOW);
  digitalWrite(steering_motor_1,LOW);
  digitalWrite(steering_motor_2,HIGH);
}
void reverse_left()
{
  digitalWrite(motor_drive_1,HIGH);
  digitalWrite(motor_drive_2,LOW);
  digitalWrite(steering_motor_1,HIGH);
  digitalWrite(steering_motor_2,LOW);
}
void right()
{
  digitalWrite(steering_motor_1,LOW);
  digitalWrite(steering_motor_2,HIGH);
}
void left()
{
  digitalWrite(steering_motor_1,HIGH);
  digitalWrite(steering_motor_2,LOW);
}
