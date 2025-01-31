int Read_map(){
  bool OnLine = false;
 
  uint32_t Avg = 0; 
  uint16_t Sum = 0;
 qtr.read(sensorValues);
  for (uint8_t i=0;i<SensorCount;i++){
    Sensor[i]=map(analog(i),350,1000,0,1000);
    if (Sensor[i]<300)Sensor[i]=0;
    if (Sensor[i]>900)Sensor[i]=1000;
    Serial.print(Sensor[i]);
  Serial.print('\t');
  }

  for (uint8_t i = 0; i <SensorCount; i++)
  {
    int Value = Sensor[i];
    if (Value > 890  ) { OnLine = true; }
    if (Value > 10)
    {
      Avg += (uint32_t)Value * (i * 1000);
      Sum += Value;
    }
  }
  if (!OnLine)
  {

    if (LastPosition < (SensorCount - 1) * 1000 / 2)
    {
     return 0;
      
    }
    else
    { 
       return (SensorCount - 1) * 1000;
      
      
    }
    
  }

  LastPosition = Avg / Sum;
  return LastPosition;
  
 
}

int Read_map2(){
  bool OnLine = false;
 
  uint32_t Avg = 0; 
  uint16_t Sum = 0;
 qtr.read(sensorValues);
  for (uint8_t i=0;i<SensorCount;i++){
    Sensor[i]=1000-map(analogRead(i),300,900,0,1000);
    if (Sensor[i]<400)Sensor[i]=0;
    if (Sensor[i]>900)Sensor[i]=1000;
   
  }

  for (uint8_t i = 0; i <SensorCount; i++)
  {
    int Value = Sensor[i];
    if (Value > 500  ) { OnLine = true; }
    if (Value > 10)
    {
      Avg += (uint32_t)Value * (i * 1000);
      Sum += Value;
    }
  }
  if (!OnLine)
  {

    if (LastPosition < (SensorCount - 1) * 1000 / 2)
    {
     return 0;
      
    }
    else
    { 
       return (SensorCount - 1) * 1000;
      
      
    }
    
  }

  LastPosition = Avg / Sum;
  return LastPosition;
  
 
}
 void   Pid2()
  {
    int Max=60;
    int Vlue=Read_map();
    error =Vlue-2500;
    integral += error;
    differencial = (error * KP) + ((error - Last_error) *KD )+ (0 * KI);
    Last_error = error;
    Lmotor= sp+9 + differencial;
    Rmotor = sp - differencial;   

    if(Lmotor > Max) Lmotor = Max ;
    else if(Lmotor < -40 ) Lmotor = -40;

    if(Rmotor > Max) Rmotor = Max ;
    else if(Rmotor < -40 ) Rmotor = -40;
    
  motor(4,Rmotor);
  motor(3,Rmotor);
  motor(2,Lmotor);
  motor(1,Lmotor);
  }

  void   PidWhite()
  {
    int Max=60;
    int Vlue=Read_map2();
    error =Vlue-2500;
    integral += error;
    differencial = (error * KP) + ((error - Last_error) *KD )+ (0 * KI);
    Last_error = error;
    Lmotor= sp+9 + differencial;
    Rmotor = sp - differencial;   

    if(Lmotor > Max) Lmotor = Max ;
    else if(Lmotor < -40 ) Lmotor = -40;

    if(Rmotor > Max) Rmotor = Max ;
    else if(Rmotor < -40 ) Rmotor = -40;
    
  motor(4,Rmotor);
  motor(3,Rmotor);
  motor(2,Lmotor);
  motor(1,Lmotor);
  }