String get_usr_data()
{ String raw_data;
  if (Serial.available())
  {
    raw_data = Serial.readString();
  }
  else
  {
    raw_data = "##";
  }
  return raw_data;
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
