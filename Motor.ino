void MotorStop()
{
  AO();
  delay(100);
}
  
void TuneMotor(int MotorSpeed) //ปรับจูนมอเตอร์
{
    LeftSpeed=MotorSpeed-0; //เอียงขวา
    RightSpeed=MotorSpeed+0; //เอียงซ้าย
    // LeftSpeed = MotorSpeed + 15;   // เพิ่มกำลังล้อซ้าย
    // RightSpeed = MotorSpeed - 30;  // ลดกำลังล้อขวา
}

void Forward(int MotorSpeed,int Time) //เดินหน้า
{
  TuneMotor(MotorSpeed);
  FD2(LeftSpeed+9,RightSpeed);
  delay(Time);
}

void Backward(int MotorSpeed,int Time) //ถอยหลัง
{
  TuneMotor(MotorSpeed);
  BK2(LeftSpeed,RightSpeed);
  delay(Time);
}