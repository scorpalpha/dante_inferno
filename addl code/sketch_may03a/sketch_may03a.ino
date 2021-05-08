float ultrasonic (int TRIG_PIN, int ECHO_PIN )
{
digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);  

  const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
  float distance= (duration*0.0344)/2;
  if(duration==0){
    Serial.println("Warning: no pulse from sensor");
  } else {
    Serial.print("ultrasonic_value :");
    
    Serial.println(distance);
    return distance; 
  }
  delay(1000);
}  

void setup() {
  Serial.begin(9600);// put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
 pinMode(13,OUTPUT);
 pinMode(12,INPUT); 
}
void right_fwd()
{
   digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
}
void left_fwd()
{
   digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
void fwd()
{
   digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
}
void Stop(){ 
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);}
void back()
{
   digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
}
void right()
{
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
}
void left()
{
 digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}

void loop()  
{
float a = ultrasonic(13,12);
Serial.println(a);
if (a > 30)
{
  fwd();
}
else if (a <=30 )
{
  Stop();
  delay(1000);
  back();
  delay(2000);
  right_fwd();
  delay(2500);
  left_fwd();
  delay(2500);
 
  
}  
  
}
