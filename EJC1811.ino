/*
Code for Project EJC1811 for B.R.A.D. Engineering at Abilene Christian University
Created by Jared Barker
*/

const int button1 = 2;
const int button2 = 3;
const int resetButton = 4;
const int pauseButton = 5;
const int LED1 = 6;
const int LED2 = 7;

unsigned long baseTime = 0;
unsigned long elapsedTime = 0;

void setup() 
{
    pinMode(button1,INPUT_PULLUP);
    pinMode(button2,INPUT_PULLUP);
    pinMode(resetButton,INPUT_PULLUP);
    pinMode(pauseButton,INPUT_PULLUP);
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);

    //Serial.begin(9600);
    
}

void loop() 
{
    //Serial.println(elapsedTime + millis() - baseTime);
    
    if(digitalRead(resetButton) == LOW)
    {
      delay(20);
      if(digitalRead(resetButton) == LOW)
      {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);

        delay(1000);
        
        while(digitalRead(resetButton) == HIGH)
        {
          delay(20);
        }
        
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        
        baseTime = millis();
        elapsedTime = 0;
        //Serial.println("Reset");

        delay(1000);
      }
    }
    
    if(digitalRead(button1) == LOW)
    {
      delay(20);
      if(digitalRead(button1) == LOW)
      {
        elapsedTime = elapsedTime + millis() - baseTime;
        digitalWrite(LED1,HIGH);
        
        int exit = 0;
        
        while(!exit)
        {
          if(digitalRead(resetButton) == LOW)
          {
            exit = 1;
          }
          
          if(digitalRead(pauseButton) == LOW)
          {
            baseTime = millis();
            digitalWrite(LED1,LOW);
            exit = 1;
          }
        }
      }
    }
    
    if(digitalRead(button2) == LOW)
    {
      delay(20);
      if(digitalRead(button2) == LOW)
      {
        elapsedTime = elapsedTime + millis() - baseTime;
        digitalWrite(LED2,HIGH);
        
        int exit = 0;
        
        while(!exit)
        {
          if(digitalRead(resetButton) == LOW)
          {
            exit = 1;
          }
          
          if(digitalRead(pauseButton) == LOW)
          {
            baseTime = millis();
            digitalWrite(LED2,LOW);
            exit = 1;
          }
        }
      }
    }

    if((elapsedTime + millis() - baseTime) >= 45000)
    {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);

        delay(1000);
        
        while(digitalRead(resetButton) == HIGH)
        {
          delay(20);
        }
        
        digitalWrite(LED1,LOW);
        digitalWrite(LED2,LOW);
        
        baseTime = millis();
        elapsedTime = 0;
       // Serial.println("Reset by time");

        delay(1000);
    }
}














