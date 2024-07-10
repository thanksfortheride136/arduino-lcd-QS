#include <LiquidCrystal.h> 
#include <Arduino.h>
int button_pin = 13;
int button_state;
int count = 0;
int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //list all pins connected to LCD except for v0 on LCD

 void setup()
 {
  Serial.begin(9600);
    pinMode(button_pin, INPUT_PULLUP);
    analogWrite(6,Contrast); //V0 pin goes here.
    lcd.begin(16, 2);
  } 
     void loop()
 { 
    //count_up();
    //scroll_left();
    //blinking_cursor();
    //Serial.println(digitalRead(button_pin));
    //delay(100);
    //button();
    select_char();

 }

void count_up(){        //Counts up every second
    lcd.setCursor(0, 0);
    lcd.print("Count: ");
    lcd.setCursor(0,1);
    lcd.print(count); 
    count++;
    delay(1000);
}

void scroll_left(){
  lcd.setCursor(15, 0);
  lcd.print("Im Scrolling");
  lcd.scrollDisplayLeft();    //built in method in liquid Crystal 
  delay(550);
}

void blinking_cursor(){
  lcd.setCursor(0, 0);
  lcd.blink();
  delay(5000);
}

/* NOT FINISHED -- NEED TO GET 
void select_char() {
    String results[3] = { "uno", "duo", "tri" };
    button_state = digitalRead(button_pin);
    Serial.print("BUTTON STATE IS: ");
    Serial.println(button_state);

    if (button_state == LOW) {  // Use comparison operator and LOW constant
        for (int i = 0; i < 3; i++) {
            Serial.println(results[i]);
        }
    }
}*/

///////////Just testing the button, not used for anything else//////////
void button(){
  button_state = digitalRead(button_pin);
  if(button_state == HIGH){              //IF BUTTON NOT WORKING TEST DIFFERENT PINS, HARD TO SEE WHICH PIN IS WITCH
    Serial.println("Not Pressed");
  }else{
    Serial.println("Pressed");
  }
}