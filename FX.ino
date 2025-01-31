void checkColor(){
  while(colorID!=1){
   if (huskylens.updateBlocks()) {
    for (int i = 0; i < huskylens.getNumBlocks(); i++) {  
      HUSKYLENSResult result = huskylens.get(i); 
      colorID=result.ID;
      MotorStop();
    }
  } 
  else { 
      colorID=0;
    }
  }
  Forward(20,10);
  colorID=0;
}

void checkTraffic(){
  while(colorID!=1)
  {
    MotorStop();
  }
  
  Forward(20,10);
  
}