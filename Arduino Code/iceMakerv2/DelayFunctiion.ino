
 
 //============================================//
 //             delay for minutes             //
 //============================================//

 void delayForMinutesCompressor(float minutes){
      Serial.print("minutes of delay = ");
      Serial.println(minutes);
      unsigned long StartTime = millis();
      unsigned long CurrentTime = millis();
      unsigned long ElapsedTime=0;
      int LastStateDe=State;
      //Serial.println("LastStateDe");
      //Serial.println(LastStateDe);
      
      while(ElapsedTime<(minutes*60000)){

      CurrentTime = millis();
      ElapsedTime = CurrentTime - StartTime;
      Serial.print("ElapsedTime : ");
      Serial.println(ElapsedTime);

        if(debounced()!=LastStateDe){
          Serial.println("Button pressed I am out");
          break;
        }
      }
      
      Serial.println("end of delay");
 }


 //============================================//
 //             delay for minutes             //
 //============================================//

 void delayForMinutes(float minutes){
      Serial.print("minutes of delay = ");
      Serial.println(minutes);
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
