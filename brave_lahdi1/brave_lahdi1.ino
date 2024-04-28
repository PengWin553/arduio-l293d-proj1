int btn1 = 8;
int btn2 = 9;
int btn3 = 10;

int nMotor1 = 11;
int pMotor1 = 12;


int btn1State;
int btn2State;
int btn3State;

int crct1State;
int crct2State;
int crct3State;


void setup(){
  pinMode(btn1,INPUT); //turns the car on / off
  pinMode(btn2,INPUT); //left
  pinMode(btn3,INPUT); //right
  
  Serial.begin(9600);

}

void loop(){
  btn1State = digitalRead(btn1);
  btn2State = digitalRead(btn2);
  btn3State = digitalRead(btn3);
 
  //Tells if the car is on or off
  if(btn1State == LOW){
    if(crct1State == LOW){
      crct1State = HIGH;
      Serial.println("The car is on.");
    }else{
      crct1State = LOW;
      Serial.println("The car is off.");
      digitalWrite(nMotor1,LOW);
      digitalWrite(pMotor1,LOW);
    }
  }
  
  //If the car is on, you may perform the following:
  
      if(crct1State == HIGH){
          
        //left
        if(btn2State == LOW){
          if(crct2State == LOW){
            crct2State = HIGH;
            
            digitalWrite(nMotor1,HIGH);
            digitalWrite(pMotor1,LOW);
          }else{
            crct2State = LOW;
          }
        }
          
        //right
        if(btn3State == LOW){
          if(crct3State == LOW){
            crct3State = HIGH;
            Serial.println("The car turns right.");
            
            digitalWrite(nMotor1,LOW);
            digitalWrite(pMotor1,HIGH);
            
            
          }else{
            crct3State = LOW;
          }
        }
        
      }
  
    delay(100);

}