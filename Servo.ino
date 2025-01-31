void SetServo() 
{   
    AO();  
    servo(1,0);
    servo(2,90);
    delay(100);
}

void DropLeft() 
{   
    AO();  
    servo(1,90);
    delay(500);
    servo(1,0);
    delay(500);
    
}

void DropRight() 
{   
    AO();  
    servo(2,0);
    delay(500);
    servo(2,90);
    delay(500);
    
}
