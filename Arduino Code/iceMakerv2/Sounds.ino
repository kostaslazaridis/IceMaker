  void fullCartiegeSound(){
   tone(buzzer,2000);
   delay(1700);
   noTone(buzzer);
   delay(1000);
  }
  
  void waterFullSound(){
   tone(buzzer,1000);
   delay(300);
   noTone(buzzer);
   delay(100);
   tone(buzzer,1500);
   delay(1500);
   noTone(buzzer);
   delay(500);
  }

 //-----------------
 // start up beep
 //-----------------
 void startUpSound(){
   tone(buzzer,800);
   digitalWrite(led_IceFull,HIGH);
   delay(300);
   noTone(buzzer);
   delay(100);
   tone(buzzer,1000);
   digitalWrite(led_AddWater,HIGH);
   delay(300);
   noTone(buzzer);
   delay(50);
   tone(buzzer,1200);
   digitalWrite(led_Work,HIGH);
   delay(300);
   noTone(buzzer);
   delay(50);
   digitalWrite(led_Work,LOW);
   digitalWrite(led_AddWater,LOW);
   digitalWrite(led_IceFull,LOW);
 }

 //Good
 void OkSound(){
   tone(buzzer,1000);
   delay(1000);
   noTone(buzzer);
 }


 
 //Command OK
 void CommandSound(){
   tone(buzzer,1100);
   delay(200);
   noTone(buzzer);
   delay(50);
   tone(buzzer,1100);
   delay(200);
   noTone(buzzer);
 }

  //Command OK
 void selectSound(){
   tone(buzzer,1000);
   delay(200);
   noTone(buzzer);
   delay(100);

 }
