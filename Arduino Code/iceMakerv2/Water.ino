
//========================delays=======================//
const int waterPumpTime=11000;


//=====================================================================================================================//
 //                                             check if the Cartridge has Water                                        //
 //=====================================================================================================================//
  boolean checkNoWater(){ 
    
      float waterConductivity = analogRead(waterSensor);
      Serial.println(waterConductivity);
      if(waterConductivity<990){
        return true;
      }
      else{
       digitalWrite(led_AddWater,HIGH);
       Serial.println("NO WATER, ADD WATER PLEASE");
       return false;
      }
  } 

 //============================================//
 //          fill the tray with water          //
 //============================================//
  boolean fillTheTrayWithWater(){
      unsigned long StartTime = millis();
      unsigned long CurrentTime = millis();
      unsigned long ElapsedTime=0;
      
      Serial.println("Fill the tray with water");
      Serial.println("Going to the correct possition");
      toTheEndLeft();
      Serial.println("Water pump ON");
      digitalWrite(waterPump,HIGH); //water pump on
      delay(700);
      Serial.println("check conductivity after the delay");
      
      while((ElapsedTime>(waterPumpTime+100) || ElapsedTime<(waterPumpTime-100))){
        
       if(checkNoWater()==false){
         digitalWrite(waterPump,LOW);  //water pump off
         Serial.println("Water pump OFF");
         Serial.println("No Water BREAK");
         waterFullSound(); 
         return false;
       }
     
      CurrentTime = millis();
      ElapsedTime = CurrentTime - StartTime;
      Serial.print("ElapsedTime : ");
      Serial.println(ElapsedTime);
      }
     
     digitalWrite(waterPump,LOW);  //water pump off
     Serial.println("Water pump OFF");
     Serial.println("End of filling water");
     return true;
 
  }
