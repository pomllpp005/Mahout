void TurnLeft()
{
  MotorStop();
  SL(60);       // SpinLeft(int)
  delay(200);
  ConvertAnalog(true);
  while(L3 == 1)
  {
    ConvertAnalog(true);
  }
  MotorStop();
}

void TurnRight()
{
  MotorStop();
  SR(60);       // SpinRight(int)
  delay(200);
  ConvertAnalog(true);
  while(R3 == 1)
  {
    ConvertAnalog(true);
  }
  MotorStop();
}

