#include <LiquidCrystal.h>

const int rs=12, en =11, d4=5,d5=1,d6=3,d7=2;

LiquidCrystal lcd (rs, en, d4, d5, d6, d7) ;

float temp = 0;

int green = 13;

int red = 10;

void setup () {

//I put your setup code here, to run once:

lcd. begin (16, 2) ;

temp = analogRead (A0) ;

Serial. begin (9600);
 pinMode (green , OUTPUT); 
 pinMode (red, OUTPUT);

}

void loop( ){

//I put your main code here, to run repeatedly:

lcd. setCursor (0, 0) ;

int data = analogRead (A0);

float voltage = data *0.48828125;

//Eloat temperature =voltage /10 ;

Serial. print ("temp =");

Serial. println (voltage) ;

lcd. setCursor (0, 0) ;

 delay (2000) ;

if (voltage >43){

lcd. setCursor (0, 1) ;

lcd.print ("warm");

digitalWrite (red , HIGH);

digitalWrite (green,LOW) ;

}else{

lcd. setCursor (0, 1) ;

lcd. print ("Cold");

digitalWrite (red , LOW); 
digitalWrite (green , HIGH);

}
}
