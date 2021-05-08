void jetson_setup()
{
  pinMode(jetson_pin_1,INPUT_PULLUP);
}
void jetson_read()
{
  jetson_value = digitalRead(jetson_pin_1);
}
