
//========================delays=======================//
const int waterPumpTime=11000;


//=====================================================================================================================//
 //                                             check if the Cartridge has Water                                        //
 //=====================================================================================================================//
  boolean checkNoWater(){ 
    
      float waterConductivity = analogRead(waterSensor);
      Serial.println(waterConductivity);
      if(waterConductivity>200){
        return true;
      }
      else
       digitalWrite(led_AddWater,HIGH);
       Serial.println("NO WATER, ADD WATER PLEASE");
       waterFullSound(); 
       return false;
  } 

 //============================================//
 //          fill the tray with water          //
 //============================================//
  void fillTheTrayWithWater(){
      unsigned long StartTime = millis();
      unsigned long CurrentTime = millis();
      unsigned long ElapsedTime;
      
      Serial.println("Fill the tray with water");
      Serial.println("Going to the correct possition");
      toTheEndLeft();
      Serial.println("Water pump ON");
      digitalWrite(waterPump,HIGH); //water pump on
      delay(2000);

      while((ElapsedTime>(waterPumpTime+100) || ElapsedTime<(waterPumpTime-100))&&checkNoWater()){
      CurrentTime = millis();
      ElapsedTime = CurrentTime - StartTime;
      Serial.print("ElapsedTime : ");
      Serial.println(ElapsedTime);
      }
     
     digitalWrite(waterPump,LOW);  //water pump off
     Serial.println("Water pump OFF");
     Serial.println("End of filling water");
 
  }
