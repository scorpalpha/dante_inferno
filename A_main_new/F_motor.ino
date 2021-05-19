void motor_setup()
{
  pinMode(relay_pin1, OUTPUT);
  pinMode(relay_pin2, OUTPUT);
  pinMode(relay_pin3, OUTPUT);
  pinMode(relay_pin4, OUTPUT);
  digitalWrite(relay_pin1, HIGH);
  digitalWrite(relay_pin2, HIGH);
  digitalWrite(relay_pin3, HIGH);
  digitalWrite(relay_pin4, HIGH);
}
void back()
{

  digitalWrite(relay_pin3, HIGH);
  digitalWrite(relay_pin4, LOW);
}
void fwd()
{
  digitalWrite(relay_pin3, LOW);
  digitalWrite(relay_pin4, HIGH);
}
void Stop()
{
  digitalWrite(relay_pin1, HIGH);
  digitalWrite(relay_pin2, HIGH);
  digitalWrite(relay_pin3, HIGH);
  digitalWrite(relay_pin4, HIGH);
}
void right()
{
  digitalWrite(relay_pin1, LOW);
  digitalWrite(relay_pin2, HIGH);
}
void left()
{
  digitalWrite(relay_pin1, HIGH);
  digitalWrite(relay_pin2, LOW);
}
void left_forward_correction()
{
  digitalWrite(relay_pin1, LOW);
  digitalWrite(relay_pin2, HIGH);
  delay(25);
  digitalWrite(relay_pin1, HIGH);
  digitalWrite(relay_pin2, HIGH);
}
void right_forward_correction()
{
  digitalWrite(relay_pin1, HIGH);
  digitalWrite(relay_pin2, LOW);
  delay(25);
  digitalWrite(relay_pin2, HIGH);
  digitalWrite(relay_pin1, HIGH);
}
