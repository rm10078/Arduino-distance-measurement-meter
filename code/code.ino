
#include<LiquidCrystal.h>  //This is a library for lcd
const int echo=3;   //ultrasonic sensor pins echo and trigger
const int trigger=4;
const int rs=13,en=12,d4=11,d5=10,d6=9,d7=8;//lcd pins
float t=0;
float dis=0;
float pri=0,curr=0;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);  
void setup(){
  pinMode(echo,INPUT);  //echo is input and trigger is a output
  pinMode(trigger,OUTPUT);
  lcd.begin(16,2);
  lcd.print("Wellcome");    //print wellcome in the lcd 
  delay(1000);     //just for 1s
  lcd.clear();    //clear the lcd
  }
void printlcd(float result){
  lcd.clear();
  lcd.print("Distance      cm");
  lcd.setCursor(0,1);
  lcd.print(result);
  }
void loop(){
 
  //measur the sensor valu
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  t=pulseIn(echo,HIGH);
  dis=t*340/20000;
   curr=dis;  
   if(pri != curr){
    printlcd(dis);
    pri=curr;
    }
  }
