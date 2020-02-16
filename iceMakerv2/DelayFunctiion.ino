 //============================================//
 //             delay for minutes             //
 //============================================//

 void delayForMinutes(float minutes){
      unsigned long StartTime = millis();
      unsigned long CurrentTime = millis();
      unsigned long ElapsedTime=0;
      
      while(ElapsedTime<(minutes*60000)){
      CurrentTime = millis();
      ElapsedTime = CurrentTime - StartTime;
      Serial.print("ElapsedTime : ");
      Serial.println(ElapsedTime);
      }
      
      Serial.println("end of delay");
 }
