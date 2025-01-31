void Mission2()
{
  oled.clear();
  oled.text(1, 0, "Mission 2"); 
    oled.show();
    delay(10);

 

TrackCrossR(20, 0.035,0.5);  
SR(50);
delay(120);
//////////////////////////////////////////////////////////////
TrackTimewhite(20, 2250,0.035,0.3);
 TrackCrosswhite(20, 0.035,0.5);  
 MotorStop(); 
 checkColor();
 TrackTimewhite(20, 4000,0.035,0.3);
 TrackCrosswhite(20, 0.035,0.5); 


}
