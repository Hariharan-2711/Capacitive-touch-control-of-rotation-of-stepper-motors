#include<LiquidCrystal.h>
int rs = 12;
int en = 11;
int d4 = 5;
int d5 = 4;
int d6 = 3;
int d7 = 2;
char array1[] = "hello world";
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int touchpin = 6;
int touchstate = 0;
int bpin = 7;
int pin0 = 13;
int pin1 = 10;
int pin2 = 9;
int pin3 = 8;
int _step;
int _speed;
int count = 0;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(bpin,OUTPUT);
  pinMode(touchpin,INPUT);
  pinMode(pin0,OUTPUT);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("STATUS: LOCKED");
  lcd.setCursor(0,1);
  lcd.print("TOUCH TO UNLOCK");
  touchstate = digitalRead(touchpin);
  if(touchstate==HIGH)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("UNLOCKING...");
    digitalWrite(bpin,HIGH);
    Speed(15);
    Step(512);
    digitalWrite(bpin,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("STATUS: UNLOCKED");
    lcd.setCursor(0,1);
    lcd.print("TOUCH TO LOCK");
    wait();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("LOCKING...");
    digitalWrite(bpin,HIGH);
    Speed(15);
    Step(-512);
    digitalWrite(bpin,LOW);
    lcd.clear();
    lcd.setCursor(0,0);
    //lcd.scrollDisplayRight();
    lcd.print("STATUS: LOCKED");
    lcd.setCursor(0,1);
    lcd.print("TOUCH TO UNLOCK");
  }

}
void Speed(int stepperspeed)
{
  _speed = 15 - stepperspeed;
  if(_speed<1)
  {
    _speed = 1;
  }  
}
void Step( int _step)
{
  if(_step>=0)
  {
    for(int i=0;i<_step;i++)
    {
      setstep(1,0,0,0);
      delay(_speed);
      setstep(1,1,0,0);
      delay(_speed);
      setstep(0,1,0,0);
      delay(_speed);
      setstep(0,1,1,0);
      delay(_speed);
      setstep(0,0,1,0);
      delay(_speed);
      setstep(0,0,1,1);
      delay(_speed);
      setstep(0,0,0,1);
      delay(_speed);
      setstep(1,0,0,1);
      delay(_speed);
    }
  }
  else
  {
    for(int i=_step;i<0;i++)
    {
      setstep(0,0,0,1);
      delay(_speed);
      setstep(0,0,1,1);
      delay(_speed);
      setstep(0,0,1,0);
      delay(_speed);
      setstep(0,1,1,0);
      delay(_speed);
      setstep(0,1,0,0);
      delay(_speed);
      setstep(1,1,0,0);
      delay(_speed);
      setstep(1,0,0,0);
      delay(_speed);
      setstep(1,0,0,1);
      delay(_speed);
    }
  }
}
void setstep(int a,int b,int c,int d)
{
  digitalWrite(pin0,a);
  digitalWrite(pin1,b);
  digitalWrite(pin2,c);
  digitalWrite(pin3,d);
}
void wait()
{
  do
  {
    Serial.println("UNLOCKED");
    touchstate = digitalRead(touchpin);
  }while(touchstate == LOW);
}
