#include <Servo.h>

#define FINGER 6
#define FINGERIND 11
#define GPSIND 12
#define GPS 7
#define REDLED 8
#define GREENLED 9
#define BUZZER 3
#define SERVO 5


int runOnce = 0;

int locked = 0;
int unlocked = 90;

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(SERVO);
  myservo.write(locked);//lock position
  pinMode(FINGER, INPUT);
  pinMode(GPS, INPUT);
  pinMode(FINGERIND, OUTPUT);
  pinMode(GPSIND, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(GREENLED, LOW);
  digitalWrite(BUZZER, LOW);
  digitalWrite(REDLED, HIGH);
  digitalWrite(FINGERIND, HIGH);
  digitalWrite(GPSIND, HIGH);
}

void loop() {
  if((digitalRead(FINGER)== HIGH) && (digitalRead(GPS) == HIGH)){//unlock
    digitalWrite(GREENLED, HIGH);
    digitalWrite(REDLED, LOW);
    
    if(runOnce == 0){
      tone(BUZZER, 1000, 500);
      runOnce = 1;
    }
    myservo.write(unlocked);
    delay(100);
    digitalWrite(FINGERIND, LOW);
    digitalWrite(GPSIND, LOW);
  }
  else{//locked
    digitalWrite(GREENLED, LOW);
    digitalWrite(REDLED, HIGH);
    
    if(digitalRead(FINGER)== HIGH){
      digitalWrite(FINGERIND, HIGH);
    }
    else{
      digitalWrite(FINGERIND, LOW);
    }
    
    if(digitalRead(GPS)== HIGH){
      digitalWrite(GPSIND, HIGH);
    }
    else{
      digitalWrite(GPSIND, LOW);
    }
    
    runOnce = 0;
    myservo.write(locked);
    delay(100);
  }
}
