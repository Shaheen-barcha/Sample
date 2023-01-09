 int trig = A2; 
 int echo = A1;
 int out = 11;

 

  void setup() 
  {
  
  Serial.begin(9600); 
  pinMode(trig, OUTPUT); 
  pinMode(echo, INPUT); 
  pinMode(out,OUTPUT);

  }

  void loop()
 
  {
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delay(15);
  digitalWrite(trig,LOW);

  int dist = pulseIn(echo,HIGH);
  int distanceInch = 0.0134*(dist/2);

 Serial.println(distanceInch);
  delay(50);



  
  float value = map(distanceInch,2,56,0,255);

  if(distanceInch > 8 && distanceInch < 56)

  {

  float outPut = 255-value;

  Serial.println(distanceInch);
  delay(500);


  analogWrite(out,outPut);

  
  }

  else

  {
  analogWrite(out,255);
  }

  }
