#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int gamesound[] = {523,784,698,659}; // 게임 리셋 사운드
int goalsound[] = {589,523,349}; // 1점 골 사운드
int goalsound3[] = {784,880,988,880,784}; // 3점 골 사운드

const int onep1 = 3; //왼쪽1점 골대
const int opep2;//오른쪽1점 골대
const int twop1 = 9;//왼쪽2점골대
const int twop2;//오른쪽2점골대
const int thrp = 11;//3점골대a
const int booz = 5;//부저

int score = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(onep1,INPUT);
  pinMode(twop1,INPUT);
  pinMode(thrp,INPUT);
  pinMode(booz,OUTPUT);

  lcd.begin();
  lcd.clear();
}

void loop() {
  int oneg1 = digitalRead(onep1);
  //int oneg2 = digitalRead(onep2);
  int twog1 = digitalRead(twop1);
  //int twog2 = digitalRead(twop2);
  int thrg = digitalRead(thrp);

  if(oneg1!=1){
    score++;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Goal");
    lcd.setCursor(0,1);
    lcd.print("Score :");
    lcd.print(score);

    for(int i=0;  i<3; i++) {
      tone(booz,goalsound[i],200);
      delay(150);
    }
    delay(500); //중복점수 방지
  }

  if(twog1!=1) {
    score+=2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Goal");
    lcd.setCursor(0,1);
    lcd.print("Score :");
    lcd.print(score);

    for(int i=0;  i<3; i++) {
      tone(booz,goalsound[i],200);
      delay(150);
    }
    delay(500); //중복점수 방지
  }

  if(thrg!=1) {
    score+=3;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Goal");
    lcd.setCursor(0,1);
    lcd.print("Score :");
    lcd.print(score);

    for(int i=0;  i<5; i++) {
      tone(booz,goalsound3[i],200);
      delay(150);
    }
    delay(500); //중복점수 방지
  }
  delay(100); //0.1초마다 센서 확인
}
