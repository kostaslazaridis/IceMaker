 
 
  //temp
  const int tempValueforFull=-0.5; //degrees to stop the machine because it's full
  
  //======================int/float======================//
  
  float RT, VR, ln,  T0, VRT;
  double TX;
  #define VCC 5    //Supply voltage
  #define R 10000  //R=10KΩ
   
   
 //============================================//
 //               read temperature             //
 //============================================//
    double readTemp(){ 
      VRT = analogRead(ThermistorPin);   //Acquisition analog value of VRT
      VRT = (5.00 / 1023.00) * VRT;      //Conversion to voltage
      RT = (R*(VCC/VRT - 1.0))/1000;            //finding the uknown resistor

      double rPowerFive=pow(RT, 5);   // r^5
      double rPowerFour=pow(RT, 4);   // r^4
      double rPowerThree=pow(RT, 3);  // r^3
      double rPowerTwo=pow(RT, 2);    // r^2  
    
      TX =-0.00000398985138208*rPowerFive+0.00059799669742102*rPowerFour-0.03516510255701613*rPowerThree+1.02628245620174429*rPowerTwo-15.7405852126064704*double(RT)+106.032203606033576; //Temperature from thermistor
    
      Serial.print("| Temperature");
      Serial.print("\t| ");
      Serial.print(TX);
      Serial.print("C |\t ");
      Serial.print(RT);
      Serial.println(" kΩ|\t\t ");
      return TX;
  }

 //=====================================================================================================================//
 // check if the Cartridge is Full, videlicet the temperature is near zero                                              //
 //=====================================================================================================================//
  boolean checkIfCartridgeIsFull(){ 
    
      if(readTemp()<=tempValueforFull){
        Serial.println("Cartridge Is Full");
        digitalWrite(led_IceFull,HIGH);    //ICE FULL light indicator on
        fullCartiegeSound();
        return true;
      }
      else{
        return false;
      }
  }
