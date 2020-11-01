#include <SoftwareSerial.h>
SoftwareSerial mySerial (7, 8); //to connect with Thrusters Arduino
SoftwareSerial mySerial2 (7, 8); //to connect with Pressure Sensor

//--------------------------------------------------Pressure Sensor------------------------------------------------
int fsrPin = 0;     // the FSR and 10K pulldown are connected to A0
int fsrReading;     // the analog reading from the FSR resistor divider
int fsrMin = 1023;        // minimum sensor value
int fsrMax = 0;           // maximum sensor value

//----------------------------------------------------IMU sensor--------------------------------------------------
#include <Wire.h>

const int MPU = 0x68;                             //MPU6050 I2C address

float GyroZ;                                      //raw gyroscope reading in degree/sec
float GyroErrorZ;                                 //error in gyroscope reading
int count = 0;                                    //variable to be used in looping 200 times to estimate this error
float elapsedTime, currentTime, previousTime;     //to be used in converting raw gyroscope data into useful angles, deg/s * s = deg

float yaw;                                        //yaw angle with reference to north direction
//----------------------------------------------------------------------------------------------------------------

void setup() {
  mySerial.begin(38400);      //with thrusters arduino
  mySerial2.begin(38400);     //with Pressure sensor
  Serial.begin(9600);         //with Qt

  //----------------------------------------------------IMU sensor--------------------------------------------------
  Wire.begin();                   //initialize comunication
  Wire.beginTransmission(MPU);    //start communication with MPU6050 // MPU=0x68
  Wire.write(0x6B);               //talk to the register 6B
  Wire.write(0x00);               //make reset - place a 0 into the 6B register to wake it up
  Wire.endTransmission(true);     //end the transmission


  //Configure Gyro Sensitivity - Full Scale Range (default +/- 250deg/s)
  Wire.beginTransmission(MPU);
  Wire.write(0x1B); // Talk to the GYRO_CONFIG register (1B hex)
  Wire.write(0x10); // Set the register bits as 00010000 (1000deg/s full scale)
  Wire.endTransmission(true);
  delay(20);


  //Call this function if you need to get the IMU error values for your module
  calculate_IMU_error();
  delay(20);

  //--------------------------------------------------Pressure Sensor------------------------------------------------

  // calibrate during the first five seconds DON'T FORGET TO PUSH THE FSR HARD!!!
  while (millis() < 5000) {
    fsrReading = analogRead(fsrPin);

    // record the maximum sensor value
    if (fsrReading > fsrMax) {
      fsrMax = fsrReading;
    }

    // record the minimum sensor value
    if (fsrReading < fsrMin) {
      fsrMin = fsrReading;
    }
  }

}

void loop() {
  //recieving Command from Qt and saving it to a variable named Command
  String Command;
  if (mySerial.available()) {
    Command = mySerial.readString();
    delay(1000);
  }

  //sending Command recieved to Thrusters Arduino
  mySerial.print(Command);
  delay(1000);



  //---------------------------------------------------IMU Sensor------------------------------------------------------

  previousTime = currentTime; //Previous time is stored before the actual time read
  currentTime = millis(); //Current time actual time read
  elapsedTime = (currentTime - previousTime) / 1000; //Divide by 1000 to get seconds

  Wire.beginTransmission(MPU);
  Wire.write(0x47); //Gyro data first register address 0x47
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 2, true); //Read 2 registers total, z-axis value is stored in 2 registers
  GyroZ = (Wire.read() << 8 | Wire.read()) / 131.0; //For a 250deg/s range we have to divide first the raw value by 131.0, according to the datasheet

  //Correct the outputs with the calculated error values
  GyroZ = GyroZ - GyroErrorZ; //subtracting error value from reading

  //Currently the raw values are in degrees per seconds(deg/s), so we need to multiply by seconds(s) to get the angle in degrees
  yaw = yaw + GyroZ * elapsedTime; // (deg/s) * s = deg

  //--------------------------------------------------Pressure Sensor------------------------------------------------
  fsrReading = analogRead(fsrPin);
  fsrReading = map(fsrReading, fsrMin, fsrMax, 0.0, 10.0);   //FSR pressure mapped on a scale of 1-10.
  // Scale could be adjusted for more accurate force output when calibration is more controlled.
  fsrReading = constrain(fsrReading, 0.0, 10.0);   // no readings above or below the 0-10 scale

  //--------------------------------------------Sending Sensors' readings to Qt---------------------------------------
  Serial.print("Dir: ");
  Serial.println(yaw);
  Serial.print("Pressure: ");
  Serial.println(fsrReading);
  delay(1000);

}


//-----------------------------------------------------Calculate Error Function--------------------------------------------------------------

void calculate_IMU_error() {
  //We can call this funtion in the setup section to calculate the gyro data error. From here we will get the error values used in the above equations.
  //Note that we should place the IMU flat in order to get the proper values, so that we then can the correct values

  //Read gyro values 200 times
  while (count < 200) {
    Wire.beginTransmission(MPU);
    Wire.write(0x47);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 2, true);
    GyroZ = Wire.read() << 8 | Wire.read();

    //Sum all readings
    GyroErrorZ = GyroErrorZ + (GyroZ / 131.0);
    count++;
  }

  //Divide the sum by 200 to get the error value
  GyroErrorZ = GyroErrorZ / 200;
}
