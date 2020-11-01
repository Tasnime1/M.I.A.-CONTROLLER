#include <Servo.h>

#include <SoftwareSerial.h>
SoftwareSerial mySerial (7, 8); //to connect with sensors arduino

int SpeedV; //vertical thruster speed
int SpeedH; //horizontal thruster speed
String movement = ""; //(R)ight, (L)eft, (F)orward, (B)ackward, (U)p, (D)own, X:rotate right, Y:rotate left
String HorV = ""; //horizontal or vertical

void setup() {
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
  else if(movement=="Y"){ RotateLeft(); }
  else{ Serial.println("Invalid movement!"); }
  
}


void Right() {
  
  }
  
void Left() {
  
  }
  
void Forward() {
  
  }
  
void Backward() {
  
  }
  
void RotateRight() {
  
  }
  
void RotateLeft() {
  
  }
  
void Up() {
  
  }
  
void Down() {
  
  }
  
