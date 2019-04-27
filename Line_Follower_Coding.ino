int M1F = 8;
int M1B = 9;
int M1E = 10;  
int M2F = 2;
int M2B = 4;
int M2E = 3;
int IR1 = 12;
int IR2 = 13;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(M2F  ,OUTPUT);
  pinMode(M2B ,OUTPUT);
  pinMode(M2E ,OUTPUT);

  pinMode(M1F  ,OUTPUT);
  pinMode(M1B ,OUTPUT);
  pinMode(M1E ,OUTPUT);

  pinMode(IR1 , INPUT);
  pinMode(IR2 , INPUT);

  digitalWrite(M1F, LOW);
  digitalWrite(M1B, LOW);
  
  digitalWrite(M2F, LOW);
  digitalWrite(M2B, LOW);
  
  
  analogWrite(M2E, 50);
  analogWrite(M1E, 50);
}


void forward()
{
    
  digitalWrite(M1B,LOW);
  digitalWrite(M2B,LOW);  
  
  digitalWrite(M1F,HIGH);
  digitalWrite(M2F,HIGH);

}


void backward()
{
    
  digitalWrite(M1F,LOW);
  digitalWrite(M2F,LOW);
    
  digitalWrite(M1B,HIGH);
  digitalWrite(M2B,HIGH);  
}

void left()
{
  digitalWrite(M1F,LOW);  
  digitalWrite(M1B,LOW);
  digitalWrite(M2B,LOW);


  digitalWrite(M2F,HIGH);  
}


void right()
{
  digitalWrite(M2F,LOW);  
  digitalWrite(M1B,LOW);
  digitalWrite(M2B,LOW);


    
  digitalWrite(M1F,HIGH);
}


void rotRight()
{
  
  digitalWrite(M2F,LOW);  
  digitalWrite(M1B,LOW);
  
  digitalWrite(M2B,HIGH);
  digitalWrite(M1F,HIGH);
  
}

void rotLeft()
{
  digitalWrite(M2B,LOW);
  digitalWrite(M1F,LOW);
  
  digitalWrite(M2F,HIGH);  
  digitalWrite(M1B,HIGH); 
}
void loop() 
{
  // put your main code here, to run repeatedly:
  //This code is to move forward
  if(digitalRead(IR1)==HIGH && digitalRead(IR2)==HIGH)
  forward();
  else if (digitalRead(IR1)==LOW && digitalRead(IR2)==LOW)
  forward();
  else if(digitalRead(IR1)==HIGH)
  rotLeft();
  else
  rotRight();
  
  /*digitalWrite(9,HIGH);
  delay(1000);
  digitalWrite(9,LOW);
  delay(1000);
  if(digitalRead(IR1)==HIGH)
  Serial.println("Swnsor 1 is High");
  else if(digitalRead(IR2)==HIGH)
  Serial.println("IR2 is HIGH");
  delay(200);*/
 
}
