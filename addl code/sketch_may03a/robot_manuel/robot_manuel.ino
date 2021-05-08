int relay_pin1 = 2;
int relay_pin2 = 3;
int relay_pin3 = 4;
int relay_pin4 = 5;

void setup() {
 Serial.begin(9600);
 Serial1.begin(9600);
 pinMode(relay_pin1,OUTPUT);
 pinMode(relay_pin2,OUTPUT);
 pinMode(relay_pin3,OUTPUT);
 pinMode(relay_pin4,OUTPUT);
 digitalWrite(relay_pin1,HIGH);
 digitalWrite(relay_pin2,HIGH);
 digitalWrite(relay_pin3,HIGH);
 digitalWrite(relay_pin4,HIGH);
 

}

void loop() {
  while(Serial1.available())
  {
    char t = Serial1.read();
    switch (t){
    case 'F':
    digitalWrite(relay_pin3,LOW);
    digitalWrite(relay_pin4,HIGH);
    break;
    case 'B':
    digitalWrite(relay_pin3,HIGH);
    digitalWrite(relay_pin4,LOW);
    Serial.print(t);
    break;
    case 'G':
     digitalWrite(relay_pin3,LOW);
    digitalWrite(relay_pin4,HIGH);
    digitalWrite(relay_pin1,HIGH);
    digitalWrite(relay_pin2,LOW);
    break;
    case 'I':
    digitalWrite(relay_pin3,LOW);
    digitalWrite(relay_pin4,HIGH);
    digitalWrite(relay_pin1,LOW);
    digitalWrite(relay_pin2,HIGH);
    break;
    
    case 'R':
    digitalWrite(relay_pin1,LOW);
    digitalWrite(relay_pin2,HIGH);
    Serial.print(t);
    break;
    case 'L':
    digitalWrite(relay_pin1,HIGH);
    digitalWrite(relay_pin2,LOW);
    Serial.print(t);
    break;
    case 'S':
    digitalWrite(relay_pin1,HIGH);
 digitalWrite(relay_pin2,HIGH);
 digitalWrite(relay_pin3,HIGH);
 digitalWrite(relay_pin4,HIGH);
   
    }
    
  }

}
