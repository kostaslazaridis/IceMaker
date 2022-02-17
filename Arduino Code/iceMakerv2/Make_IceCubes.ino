//========================delays=======================//
const int delayForMiniCubes=8;   
const int delayForMiddleCubes=10; 
const int delayForMegaCubes=13; 

const int EmptyingWaterDelay=2000;   
const float ValveDealayToHeat=0.4; 
 
 
 
 
 //=====================================================//
 //     make ice cubes 1(mini),2(middle) or 3(mega)     //
 //=====================================================//
 
  void MakeIceCubes(int sizeOfIceCube){
    
   int CartrigeFull = checkIfCartridgeIsFull(); //If Cartridge is not full proceed
   if (CartrigeFull){
    State=HIGH ;
    return; 
   }

   int TrayFilled = fillTheTrayWithWater(); //If there is water proceed
   if (!TrayFilled){
    State=HIGH ;
    return; 
   }
       
   Serial.println("Making IceCubes");   
    switch (sizeOfIceCube) {
    
     case 1: //mini cubes
        Serial.println("Making Ice cubes number 1");
        algorithmOfIcecubes(delayForMiniCubes);
        break;
      
      case 2: //middle cubes
        Serial.println("Making Ice cubes number 2");
        algorithmOfIcecubes(delayForMiddleCubes);
        break;
    
      case 3: //mega cubes
        Serial.println("Making Ice cubes number 3");
        algorithmOfIcecubes(delayForMegaCubes);
        break;
   }
        
  }


   void algorithmOfIcecubes(float minutesForCubeSize){
     
     digitalWrite(valve,LOW);      //heating valve off
     Serial.println("Vlave OFF");
     delay(500);
     
     digitalWrite(Compressor,HIGH); //Compressor On
     Serial.println("Compressor ON");
     
     delayForMinutesCompressor(minutesForCubeSize); //Waiting to Froze the Ice Cubes
     
     digitalWrite(Compressor,LOW); //Compressor Off
     Serial.println("Compressor OFF");

     Serial.println("Emptying water");
     toTheEndRight(); //empty water
     
     delay(EmptyingWaterDelay); //wait to empty water  
     Serial.println("Droping IceCubes");
     digitalWrite(valve,HIGH);      //heating valve off
     delayForMinutes(ValveDealayToHeat); //wait to heat the cubes to fall
     Serial.println("empty Icecubes from Cartrige");
     EmptyIceCubes();      
 
   }
