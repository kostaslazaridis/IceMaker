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
   delay(300);
   noTone(buzzer);
   delay(100);
   tone(buzzer,1000);
   delay(300);
   noTone(buzzer);
   delay(50);
   tone(buzzer,1200);
   delay(300);
   noTone(buzzer);
   delay(50);
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
