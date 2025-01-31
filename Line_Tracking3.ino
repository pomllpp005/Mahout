#include <POP32.h>
#include <POP32_Huskylens.h>
#include <QTRSensors.h>
POP32_Huskylens huskylens;
int colorID=0,colorID2=0;
int L3, L2, L1, R1, R2, R3; 
//int RefL3 = 2175, // Analog 0 
 //   RefL2 = 2230, // Analog 1 
 //   RefL1 = 2675, // Analog 2 
  //  RefR1 = 2550, // Analog 3 
  //  RefR2 = 2230, // Analog 4 
  //  RefR3 = 2465; // Analog 5 
//--------
int RefL3 = 1160, // Analog 0 
    RefL2 = 1615, // Analog 1 
    RefL1 = 1613, // Analog 2 
    RefR1 = 1470, // Analog 3 
    RefR2 = 1464, // Analog 4 
    RefR3 = 1570; // Analog 5 
//--------
QTRSensors qtr;

const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];
uint32_t LastPosition;
int LeftSpeed, RightSpeed;
int Error, Integral, Derivative, PreError;
int Kp = 9, Ki = 0, Kd = 5;
float KP=0;
float KD=0;
double KI=0;
int sp=0;
int Sensor[SensorCount];
int Rmotor , Lmotor ;
int Last_value = 0;
int error = 0;
int integral = 0;
int differencial = 0;
int Last_error = 0;
void setup() {
   qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, SensorCount);
  qtr.setEmitterPin(2);
  while (!huskylens.begin(Wire)) { 
    oled.text(1, 0, "Begin failed!");  //หากเชื่อมต่อไม่ได้
    oled.show();
    delay(100);
  }
  huskylens.writeAlgorithm(ALGORITHM_COLOR_RECOGNITION); // เลือกโหมดรู้จำสี
  SetServo();
  ao();
  oled.clear();
  oled.text(1, 0, "OK Mission  1 | Green"); 
  oled.text(2, 0, "A  Mission  2 | Blue"); 
  oled.text(3, 0, "B  Mission  3 | Red"); 
    oled.show();
    delay(10);
 
  //waitSW_OK_bmp();
  //ao();

  

}

void loop() {
  
  int OP=Read_map();
  oled.clear();
    oled.text(0,0,"%d",analogRead(0));
    oled.text(1,0,"%d",analogRead(1));
    oled.text(2,0,"%d",analogRead(2));
    oled.text(3,0,"%d",analogRead(3));
    oled.text(4,0,"%d",analogRead(4));
    oled.text(5,0,"%d",analogRead(5));
    oled.show();
    
 if(SW_OK())
  {
    Mission1();
    //DropFront();
  }
  else if(SW_A())
  {
    
    
   
    Mission2();
    //DropBack();
  }
  else if(SW_B())
  {
    Mission3();
  }
   // LightCheck(); 
  
}
