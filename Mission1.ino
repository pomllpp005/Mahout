void Mission1(){    // Green  
  oled.clear();
  oled.text(1, 0, "Mission 1"); 
  oled.show();
  delay(10);
  
  TrackCross(25, 0.035,0.5); 
  MotorStop();
  checkColor();   // 1st Traffic Check
 TrackTime(25, 5500,0.035,0.3); 



  TrackCross(20, 0.035,0.5); 
  MotorStop();    // 1st Data Matrix Check 
  delay(1000);
  DropLeft();   
  
  TrackTime(20, 1000,0.035,0.3); 
  TrackTime(30, 900,0.006,0.001);//เส้นประ
  TrackTime(20, 900,0.035,0.3); 
  TrackCross(20, 0.035,0.5); 
  MotorStop();
  checkColor();   // 1st Traffic Check
  TrackTime(20, 1100,0.035,0.3); 




TrackCross(20, 0.035,0.5); 
 MotorStop();    // 1st Data Matrix Check 
  delay(1000);
  DropLeft();  

 TrackTime(20, 1180,0.035,0.3); 




TrackCross(20, 0.035,0.5); 
 MotorStop();    // 1st Data Matrix Check 
  delay(1000);
  DropLeft();  

 TrackTime(30, 9200,0.035,0.3);
 TrackCross(20, 0.035,0.5);  
MotorStop();  
delay(1000);
DropLeft();  

 
  

}