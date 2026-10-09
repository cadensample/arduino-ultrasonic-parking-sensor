#include"SR04.h"
#include "pitches.h"
#include <LiquidCrystal.h>

//Creates LiquidCrystal object with specified pins (RS, Enable, D4, D5, D6, D7)
LiquidCrystal lcd(7,6,5,4,3,2);

#define TRIG_PIN 11
#define ECHO_PIN 12

SR04 my_SR04(ECHO_PIN,TRIG_PIN); //initalize the SR04 Object
long distance;
long last_shown = -2;

int frequencies[] =  {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6}; //Create array of frequencies
long beep_frequency;


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Getting Data");
  delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  distance = my_SR04.Distance(); //gets distance in cm
  
  if ((distance > 56 or distance == 0) and (last_shown >! 56 or last_shown != 0)){
    distance = 56;
    lcd.clear();
    lcd.print("TOO FAR!");
  }

  //Serial.println(distance);

  beep_frequency = exp(0.12 * distance); 
  if (beep_frequency > 1000){
    beep_frequency = 1000;
  }


   if (distance > 48){
    tone(8, frequencies[1]);
    delay(40);
    noTone(8);
    delay(beep_frequency);
    if (last_shown != distance){
      lcd.clear();
      lcd.print(distance);
      lcd.print(" cm");
      last_shown = distance;
    }
  }
  else if (distance > 40){
    tone(8, frequencies[2]);
    delay(40);
    noTone(8);
    delay(beep_frequency);
    if (last_shown != distance){
      lcd.clear();
      lcd.print(distance);
      lcd.print(" cm");
      last_shown = distance;
    }
  }
  else if (distance > 32){
    tone(8, frequencies[3]);
    delay(40);
    noTone(8);
    delay(beep_frequency);
    if (last_shown != distance){
      lcd.clear();
      lcd.print(distance);
      lcd.print(" cm");
      last_shown = distance;
    }
  }
  else if (distance > 24){
    tone(8, frequencies[4]);
    delay(40);
    noTone(8);
    delay(beep_frequency);
    if (last_shown != distance){
      lcd.clear();
      lcd.print(distance);
      lcd.print(" cm");
      last_shown = distance;
    }
  }
  else if (distance > 16){
    tone(8, frequencies[5]);
    delay(40);
    noTone(8);
    delay(beep_frequency);
    if (last_shown != distance){
      lcd.clear();
      lcd.print(distance);
      lcd.print(" cm");
      last_shown = distance;
    }
  }
  else if (distance > 8){
    tone(8, frequencies[6]);
    delay(40);
    noTone(8);
    delay(beep_frequency);
    if (last_shown != distance){
      lcd.clear();
      lcd.print(distance);
      lcd.print(" cm");
      last_shown = distance;
    }
  }
  else{
    tone(8, frequencies[7]);
    if (last_shown > 8){
      lcd.clear();
      lcd.print("STOP!!!");
      last_shown = distance;
    }
  }


}
