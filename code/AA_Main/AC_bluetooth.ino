void bt_setup()
{
  Serial.begin(9600);
}
String get_usr_data()
{
  String data;
  if (Serial.available())
  {
    data= Serial.readStringUntil("**");
    
  }
  return data;
}
void cleaned_usr_data(){
int k= slot;
  int ind =  raw_data.indexOf(",",k);
  start_lat = (raw_data.substring(k,ind)).toFloat();
  k = ind+1;
  ind = raw_data.indexOf(",",k);
  start_lng = (raw_data.substring(k,ind)).toFloat();
  
  k = ind+1;
  slot = k;
  ind = raw_data.indexOf(",",k);
  desti_lat = (raw_data.substring(k,ind)).toFloat();
   k = ind+1;
  ind = raw_data.indexOf(",",k);
  desti_lng = (raw_data.substring(k,ind)).toFloat();
}
