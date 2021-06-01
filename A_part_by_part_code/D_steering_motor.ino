
void steering_setup()
{
  pinMode(relay_s_1, OUTPUT);
  pinMode(relay_s_2, OUTPUT);
  digitalWrite(relay_s_1, HIGH);
  digitalWrite(relay_s_2, HIGH);
}
void right()
{
  digitalWrite(relay_s_1, LOW);
  digitalWrite(relay_s_2, HIGH);
}
void left()
{
  digitalWrite(relay_s_1, HIGH);
  digitalWrite(relay_s_2, LOW);
}

void Stop()
{
  digitalWrite(relay_s_1, HIGH);
  digitalWrite(relay_s_2, HIGH);
  digitalWrite(relay_d_1, HIGH);
  digitalWrite(relay_d_2, HIGH);
}
