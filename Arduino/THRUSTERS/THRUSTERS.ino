#include <SoftwareSerial.h>
SoftwareSerial mySerial (7, 8); //to connect with sensors arduino

int SpeedV; //vertical thruster speed
int SpeedH; //horizontal thruster speed
String movement = ""; //(R)ight, (L)eft, (F)orward, (B)ackward, (U)p, (D)own, X:rotate right, Y:rotate left
String HorV = ""; //horizontal or vertical

#define M1 A1
#define M2 A2
#define M3 A3
#define M4 A4
#define M5 A5
#define M6 A6

#define PWM1 3
#define PWM2 5
#define PWM3 6
#define PWM4 9
#define PWM5 1
#define PWM6 1


void setup() {

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(M5, OUTPUT);
  pinMode(M6, OUTPUT);

  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(PWM3,OUTPUT);
  pinMode(PWM4,OUTPUT);
  pinMode(PWM5,OUTPUT);
  pinMode(PWM6,OUTPUT);
  
  Serial.begin(9600);
  mySerial.begin(38400); //with Sensors arduino
}

void loop() {

  if (Serial.available()) {
    movement = Serial.read(); //first byte is the letter of movement
    
    HorV = Serial.read(); //second byte is H or V thruster
    if (HorV == "V") {
      SpeedV = Serial.parseInt();
      SpeedH = Serial.parseInt();
    } else if (HorV == "H") {
      SpeedH = Serial.parseInt();
      SpeedV = Serial.parseInt();
    } else {
      Serial.println("neither Horizontal nor Vertical!"); //print an error message if wrong thruster was entered
    }
  }
  if(movement=="F"){ Forward(); }
  else if(movement=="B"){ Backward(); }
  else if(movement=="R"){ Right(); }
  else if(movement=="L"){ Left(); }
  else if(movement=="U"){ Up(); }
  else if(movement=="D"){ Down(); }
  else if(movement=="X"){ RotateRight(); }
  else if(movement=="S"){ RotateLeft(); }
  else if(movement=="Y"){ STOP(); }
  else{ Serial.println("Invalid movement!"); }
  
}


void Right() {
  digitalWrite(M1,0);
  digitalWrite(M2,1);
  digitalWrite(M3,0);
  digitalWrite(M4,1);
  digitalWrite(M5,0);
  digitalWrite(M6,0);

  digitalWrite(PWM1,SpeedH);
  digitalWrite(PWM2,SpeedH);
  digitalWrite(PWM3,SpeedH);
  digitalWrite(PWM4,SpeedH);
  digitalWrite(PWM5,1);
  digitalWrite(PWM6,0);
  //STOP();
  }
  
void Left() {
  digitalWrite(M1,1);
  digitalWrite(M2,0);
  digitalWrite(M3,1);
  digitalWrite(M4,0);
  digitalWrite(M5,1);
  digitalWrite(M6,0);

  digitalWrite(PWM1,SpeedH);
  digitalWrite(PWM2,SpeedH);
  digitalWrite(PWM3,SpeedH);
  digitalWrite(PWM4,SpeedH);
  digitalWrite(PWM5,1);
  digitalWrite(PWM6,0);
  //STOP();
  }
  
void Forward() {
  digitalWrite(M1,1);
  digitalWrite(M2,1);
  digitalWrite(M3,1);
  digitalWrite(M4,1);
  digitalWrite(M5,1);
  digitalWrite(M6,0);

  digitalWrite(PWM1,SpeedH);
  digitalWrite(PWM2,SpeedH);
  digitalWrite(PWM3,SpeedH);
  digitalWrite(PWM4,SpeedH);
  digitalWrite(PWM5,1);
  digitalWrite(PWM6,0);
  //STOP();
  }
  
  void Backward() {
  
  digitalWrite(M1,0);
  digitalWrite(M2,0);
  digitalWrite(M3,0);
  digitalWrite(M4,0);
  digitalWrite(M5,1);
  digitalWrite(M6,0);

  digitalWrite(PWM1,SpeedH);
  digitalWrite(PWM2,SpeedH);
  digitalWrite(PWM3,SpeedH);
  digitalWrite(PWM4,SpeedH);
  digitalWrite(PWM5,1);
  digitalWrite(PWM6,0);
  //STOP();
  }
  
void RotateRight() {
  
  digitalWrite(M1,1);
  digitalWrite(M2,0);
  digitalWrite(M3,0);
  digitalWrite(M4,1);
  digitalWrite(M5,1);
  digitalWrite(M6,0);

  digitalWrite(PWM1,SpeedH);
  digitalWrite(PWM2,SpeedH);
  digitalWrite(PWM3,SpeedH);
  digitalWrite(PWM4,SpeedH);
  digitalWrite(PWM5,0);
  digitalWrite(PWM6,0);
  //STOP();
  }
  
void RotateLeft() {
  
  digitalWrite(M1,0);
  digitalWrite(M2,1);
  digitalWrite(M3,1);
  digitalWrite(M4,0);
  digitalWrite(M5,1);
  digitalWrite(M6,0);

  digitalWrite(PWM1,SpeedH);
  digitalWrite(PWM2,SpeedH);
  digitalWrite(PWM3,SpeedH);
  digitalWrite(PWM4,SpeedH);
  digitalWrite(PWM5,0);
  digitalWrite(PWM6,0);
  //STOP();
  }
  
void Up() {
  
  digitalWrite(M1,0);
  digitalWrite(M2,0);
  digitalWrite(M3,0);
  digitalWrite(M4,0);
  digitalWrite(M5,1);
  digitalWrite(M6,1);

  digitalWrite(PWM1,0);
  digitalWrite(PWM2,0);
  digitalWrite(PWM3,0);
  digitalWrite(PWM4,0);
  digitalWrite(PWM5,SpeedV);
  digitalWrite(PWM6,SpeedV);
  //STOP();
  }
  
void Down() {
  
  digitalWrite(M1,0);
  digitalWrite(M2,0);
  digitalWrite(M3,0);
  digitalWrite(M4,0);
  digitalWrite(M5,0);
  digitalWrite(M6,0);

  digitalWrite(PWM1,0);
  digitalWrite(PWM2,0);
  digitalWrite(PWM3,0);
  digitalWrite(PWM4,0);
  digitalWrite(PWM5,SpeedV);
  digitalWrite(PWM6,SpeedV);
  //STOP();
  }

 void STOP(){
  
  digitalWrite(M1,1);
  digitalWrite(M2,1);
  digitalWrite(M3,0);
  digitalWrite(M4,0);
  digitalWrite(M5,1);
  digitalWrite(M6,0);

  digitalWrite(PWM1,0);
  digitalWrite(PWM2,0);
  digitalWrite(PWM3,0);
  digitalWrite(PWM4,0);
  digitalWrite(PWM5,0);
  digitalWrite(PWM6,0);
  }
