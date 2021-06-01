void drive_motor_setup()
{
  pinMode(relay_d_1, OUTPUT);
  pinMode(relay_d_2, OUTPUT);
  digitalWrite(relay_d_1, HIGH);
  digitalWrite(relay_d_2, HIGH);
}
void fwd()
{
  digitalWrite(relay_d_1, LOW);
  digitalWrite(relay_d_2, HIGH);
}
void back()
{
  digitalWrite(relay_d_1, HIGH);
  digitalWrite(relay_d_2, LOW);
}
