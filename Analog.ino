void ReadAnalog(){ //อ่านค่าเซนเซอร์ข้างหน้า
   L3 = analog(0);  
   L2 = analog(1);
   L1 = analog(2);
   R1 = analog(3);
   R2 = analog(4);
   R3 = analog(5);
}

void ConvertAnalog(bool switchval) 
{     
  // Black = 0, White = 1
  ReadAnalog();
  // ถ้า analog(int) > ค่าเฉลี่ยของ analog(int) --> ananlog(int) = 0 (สีดำ) | ไม่ใช่ --> analog(int) = 1 (สีขาว1)
  if(switchval){    // White
    // Left 
    if(L3 < RefL3) L3 = 1;  else L3 = 0;
    if(L2 < RefL2) L2 = 1;  else L2 = 0;
    if(L1 < RefL1) L1 = 1;  else L1 = 0;

    // Right
    if(R1 < RefR1) R1 = 1;  else R1 = 0;
    if(R2 < RefR2) R2 = 1;  else R2 = 0;
    if(R3 < RefR3) R3 = 1;  else R3 = 0;
  }
  else {  // Black
    // Left 
    if(L3 < RefL3) L3 = 0;  else L3 = 1;
    if(L2 < RefL2) L2 = 0;  else L2 = 1;
    if(L1 < RefL1) L1 = 0;  else L1 = 1;

    // Right
    if(R1 < RefR1) R1 = 0;  else R1 = 1;
    if(R2 < RefR2) R2 = 0;  else R2 = 1;
    if(R3 < RefR3) R3 = 0;  else R3 = 1;
  }
}