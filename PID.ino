void CalError()
{
  ConvertAnalog(true);
  if      (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 0) Error = 5;  //  1  1  1  1  1  0 
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 0 && R3 == 0) Error = 4;  //  1  1  1  1  0  0 
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 0 && R3 == 1) Error = 3;  //  1  1  1  1  0  1 
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 0 && R2 == 0 && R3 == 1) Error = 2;  //  1  1  1  0  0  1
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 0 && R2 == 1 && R3 == 1) Error = 1;  //  1  1  1  0  1  1 
  else if (L3 == 1 && L2 == 1 && L1 == 0  && R1 == 0 && R2 == 1 && R3 == 1) Error = 0;  //  1  1  0  0  1  1  mid
  else if (L3 == 1 && L2 == 1 && L1 == 0  && R1 == 1 && R2 == 1 && R3 == 1) Error = -1; //  1  1  0  1  1  1
  else if (L3 == 1 && L2 == 0 && L1 == 0  && R1 == 1 && R2 == 1 && R3 == 1) Error = -2; //  1  0  0  1  1  1
  else if (L3 == 1 && L2 == 0 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 1) Error = -3; //  1  0  1  1  1  1 
  else if (L3 == 0 && L2 == 0 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 1) Error = -4; //  0  0  1  1  1  1
  else if (L3 == 0 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 1) Error = -5; //  0  1  1  1  1  1 

  else if (L3 == 0 && L2 == 0 && L1 == 0 && R1 == 0 && R2 == 0 && R3 == 0) Error = 1000; //  0  0  0  0  0  0  0 
  else if (L3 == 0 && L2 == 0 && L1 == 0) Error = 101;     // 0 0 0 ? ? ? ?
  else if (R1 == 0 && R2 == 0 && R3 == 0) Error = 102;     // ? ? ? ? 0 0 0
  else if (L3 == 0 && L2 == 1 && R2 == 1 && R3 == 0) Error = 1002;     // ? ? ? ? 0 0 0
}

void TrackPID(int MotorSpeed)
{
  int Output,LeftOutput, RightOutput, MaxSpeed = MotorSpeed;

  TuneMotor(MotorSpeed); 
  Integral += Error;    // Integral = Integral + Error; 
  Derivative = Error - PreError;
  Output = (Kp * Error) + (Ki * Integral) + (Kd * Derivative);
  LeftOutput  = (LeftSpeed  + Output);
  RightOutput = (RightSpeed - Output);

  constrain(LeftOutput,-MaxSpeed,MaxSpeed);
  constrain(RightOutput,-MaxSpeed,MaxSpeed);
      
  motor(4,RightOutput);
  motor(3,RightOutput);
  motor(2,LeftOutput+9);
  motor(1,LeftOutput+9);
  // motor(2,-LeftOutput);
  // motor(4,-LeftOutput);
  
  PreError = Error;
}

void TrackJC(int MotorSpeed, int Time) // เดินเช็คแยก
{
  Error = 0;
  PreError = 0; 
  while(Error < 1000)
  {
    TrackPID(MotorSpeed);
    CalError();
  }
  Forward(MotorSpeed,Time);
}

void CalError2()
{
  ConvertAnalog(true);
  if      (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 0) Error = 5;  //  1  1  1  1  1  0 
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 0 && R3 == 0) Error = 4;  //  1  1  1  1  0  0 
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 0 && R3 == 1) Error = 3;  //  1  1  1  1  0  1 
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 0 && R2 == 0 && R3 == 1) Error = 2;  //  1  1  1  0  0  1
  else if (L3 == 1 && L2 == 1 && L1 == 1  && R1 == 0 && R2 == 1 && R3 == 1) Error = 1;  //  1  1  1  0  1  1 
  else if (L3 == 1 && L2 == 1 && L1 == 0  && R1 == 0 && R2 == 1 && R3 == 1) Error = 0;  //  1  1  0  0  1  1  mid
  else if (L3 == 1 && L2 == 1 && L1 == 0  && R1 == 1 && R2 == 1 && R3 == 1) Error = -1; //  1  1  0  1  1  1
  else if (L3 == 1 && L2 == 0 && L1 == 0  && R1 == 1 && R2 == 1 && R3 == 1) Error = -2; //  1  0  0  1  1  1
  else if (L3 == 1 && L2 == 0 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 1) Error = -3; //  1  0  1  1  1  1 
  else if (L3 == 0 && L2 == 0 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 1) Error = -4; //  0  0  1  1  1  1
  else if (L3 == 0 && L2 == 1 && L1 == 1  && R1 == 1 && R2 == 1 && R3 == 1) Error = -5; //  0  1  1  1  1  1 

  else if (L3 == 0 && L2 == 0 && L1 == 0 && R1 == 0 && R2 == 0 && R3 == 0) Error = 100; //  0  0  0  0  0  0  0 
  else if (L3 == 0 && L2 == 0 && L1 == 0) Error = 50;     // 0 0 0 ? ? ? ?
  else if (R1 == 0 && R2 == 0 && R3 == 0) Error = 60;     // ? ? ? ? 0 0 0
  else if (L3 == 0 && L2 == 1 && R2 == 1 && R3 == 0) Error = 70;     // ? ? ? ? 0 0 0
}


void TrackJC2(int MotorSpeed, int Time) // เดินเช็คแยก
{

  Error = 0;
  PreError = 0; 
  while(Error < 100)
  {
    TrackPID(MotorSpeed);
    CalError2();
  }
  Forward(MotorSpeed,Time);
 
  
}
void TrackTime(int MotorSpeed, int Time,float KPl,float KDl) // เดินเช็คแยก
{
  sp=MotorSpeed;
  
  KP = KPl, KI = 0, KD = KDl;
  Error = 0;
  PreError = 0; 
  unsigned long startTime = millis(); 
  unsigned long duration = Time; 

while (millis() - startTime < duration){
  
    Pid2();
}
}
  
  void TrackTimewhite(int MotorSpeed, int Time,float KPl,float KDl) //เส้นสีขาว
{
  sp=MotorSpeed;
  
  KP = KPl, KI = 0, KD = KDl;
  Error = 0;
  PreError = 0; 
  unsigned long startTime = millis(); 
  unsigned long duration = Time; 

while (millis() - startTime < duration){
  
   PidWhite();
}
  
 
  
}
void TrackCross(int MotorSpeed,float KPl,float KDl)  //เส้นตัดสีขาว
{
  sp=MotorSpeed;
  
  KP = KPl, KI = 0, KD = KDl;
  Error = 0;
  PreError = 0; 

Read_map();
while (analogRead(0)<2000&&analogRead(5)<2000){
    Pid2();
}
 unsigned long startTime = millis(); 
  unsigned long duration = 100; 
while (millis() - startTime < duration){
  
    Pid2();
}
AO();
  
 
  
}
void TrackCrossR(int MotorSpeed,float KPl,float KDl)  //เส้นตัดสีขาว
{
  sp=MotorSpeed;
  
  KP = KPl, KI = 0, KD = KDl;
  Error = 0;
  PreError = 0; 

Read_map();
while (analogRead(5)<2000){
    Pid2();
}
 unsigned long startTime = millis(); 
  unsigned long duration = 100; 
while (millis() - startTime < duration){
  
    Pid2();
}
AO();
  
 
  
}


void TrackCrosswhite(int MotorSpeed,float KPl,float KDl) //เส้นตัดสีขาว
{
  sp=MotorSpeed;
  
  KP = KPl, KI = 0, KD = KDl;
 


Read_map2();
while (Sensor[0]<950&&Sensor[5]<950){
  Read_map2();
    PidWhite();
}
 unsigned long startTime = millis(); 
  unsigned long duration = 100; 
while (millis() - startTime < duration){
  
    PidWhite();
}
AO();
  
 
  
}
void TrackCrosswhiteR(int MotorSpeed,float KPl,float KDl) //เส้นตัดสีขาว
{
  sp=MotorSpeed;
  
  KP = KPl, KI = 0, KD = KDl;
  Error = 0;
  PreError = 0; 


Read_map2();
while (analogRead(5)>500){
    PidWhite();
}
 unsigned long startTime = millis(); 
  unsigned long duration = 100; 
while (millis() - startTime < duration){
  
    PidWhite();
}
AO();
  
 
  
}
