void setup() {
  pinMode(36,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Serial.begin(9600);
}

void loop() { /*int a = analogRead(A1);
Serial.println(a);
delay(1000);*/
  
  if(digitalRead(36)== LOW)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }

}
