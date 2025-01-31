void ShowName()  //แสดงชื่อ
{
  oled.clear(); //เคลียร์หน้าจอ
  oled.textSize(2); //ขนาดตัวอักษร
  oled.mode(2);
  oled.text(0,0,"YRC001"); //ตัวอักษร
  oled.show();
}

void LightCheck() 
{
  ReadAnalog();
  oled.clear(); //เคลียร์หน้าจอ
  oled.textSize(1); //ขนาดตัวอักษร
  oled.mode(0);
  // oled.text(0,0,"FL = %d",FL);
  // oled.text(1,0,"C  = %d",C);
  // oled.text(2,0,"FR = %d",FR);
  // oled.text(3,0,"BL = %d",BL);
  // oled.text(4,0,"BR = %d",BR);

  oled.text(0,0,"L3 = %d ",  L3);
  oled.text(1,0,"L2 = %d ",  L2);
  oled.text(2,0,"L1 = %d ",  L1);
  oled.text(3,0,"R1 = %d ",  R1);
  oled.text(4,0,"R2 = %d ",  R2);
  oled.text(5,0,"R3 = %d ",  R3);
  oled.show();
}

