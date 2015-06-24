#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 13, 9, 4, 5, 6, 7);

int photogate;
int photogate2;
unsigned long time;
unsigned long time2;
unsigned long time3;
int distance;
int speed;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
    Serial.begin(9600);
//  pinMode(13, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
  distance=1;
  
  lcd.setCursor(0, 0);
  lcd.print("Photogate");
  delay(1500);
  lcd.clear();
}

void loop() {
 
  photogate=digitalRead(A1);
  photogate2 = digitalRead(A2);
  
  if((photogate==1))
  {
    
    time = micros();
    
  }
 
  
  if((photogate2==1)&&(time2 > 1))
    {
  time2 = micros();  
  time3 = time2 - time;
  Serial.println(time3);
  photogate2=0;
  lcd.setCursor(0, 0);
  lcd.print("time");
  lcd.setCursor(0, 1);
  lcd.print(time3);
    
  speed=1000.0*distance/(time3);
  
  lcd.setCursor(9, 0);
  lcd.print("m/s");
  lcd.setCursor(9, 1);
  lcd.print(speed);
  time2=0;
    }

}


