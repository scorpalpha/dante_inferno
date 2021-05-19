void bluetooth_setup()
{
  Serial.begin(9600);

}
void get_data_usr()
{ String data;
  if (Serial.available() > 0)
  {
    data = Serial.readString();
    Serial.print(data);
    raw_bt_data = data;
  }
  else {
    raw_bt_data = "##";
  }

}
void get_data_cleaned(String raw_data)
{ int k = slot;
  int ind =  raw_data.indexOf(",", k);
  start_lat = (raw_data.substring(k, ind)).toFloat();
  k = ind + 1;
  ind = raw_data.indexOf(",", k);
  start_lng = (raw_data.substring(k, ind)).toFloat();

  k = ind + 1;
  slot = k;
  ind = raw_data.indexOf(",", k);
  desti_lat = (raw_data.substring(k, ind)).toFloat();
  k = ind + 1;
  ind = raw_data.indexOf(",", k);
  desti_lng = (raw_data.substring(k, ind)).toFloat();

}
