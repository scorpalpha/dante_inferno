void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available())
  {
    Serial.println(Serial.readString());
    
  }

}
