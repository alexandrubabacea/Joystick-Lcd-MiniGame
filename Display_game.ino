#include <LiquidCrystal.h>
enum lcd_const {
  Rs = 7, E, D4, D5, D6, D7
};
const int Xpin = A4, Ypin = A5;
int Xval, Yval, ok = 1;
const int CrtMin = 350, CrtMax = 650;

int Xobj, Yobj;

LiquidCrystal lcd(Rs, E, D4, D5, D6, D7);

void setup() {
  lcd.begin(16, 2);
  
  lcd.setCursor(Yobj, Xobj);
  lcd.print("o");
  
  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
}

void move_left() {
  lcd.clear();
  if(Yobj > 0)
    Yobj--;
  lcd.setCursor(Yobj, Xobj);
  lcd.print("o");
  ok = 0;
}

void move_right() {
  lcd.clear();
  if(Yobj < 15)
    Yobj++;
  lcd.setCursor(Yobj, Xobj);
  lcd.print("o");
  ok = 0;
}

void move_up() {
  lcd.clear();
  if(Xobj == 1)
    Xobj = 0;
  lcd.setCursor(Yobj, Xobj);
  lcd.print("o");
  ok = 0;
}

void move_down() {
  lcd.clear();
  if(Xobj == 0)
    Xobj = 1;
  lcd.setCursor(Yobj, Xobj);
  lcd.print("o");
  ok = 0;
}

void loop() {
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  if((Xval > CrtMin && Xval < CrtMax) && (Yval > CrtMin && Yval < CrtMax))
    ok = 1;
  if(ok) {
    switch(Xval)
    {
      case 0 ... CrtMin:
        move_left();
        break;
      case CrtMax ... 1024:
        move_right();
        break;
      default:
        break;
    }
    switch(Yval)
    {
      case 0 ... CrtMin:
        move_up();
        break;
      case CrtMax ... 1024:
        move_down();
        break;
      default:
        break;
    }
  }
}
