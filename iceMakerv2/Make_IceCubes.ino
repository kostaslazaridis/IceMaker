//========================delays=======================//
const int delayForMiniCubes=7;   
const int delayForMiddleCubes=9; 
const int delayForMegaCubes=11; 

const int EmptyingWaterDelay=2000;   
const float ValveDealayToHeat=0.4; 
 
 
 
 
 //=====================================================//
 //     make ice cubes 1(mini),2(middle) or 3(mega)     //
 //=====================================================//
 
  void MakeIceCubes(int sizeOfIceCube){
     Serial.println("check if Cartridge Is Full");
     if(checkIfCartridgeIsFull()==false){ //If Cartridge is not full proceed
         Serial.println("Making IceCubes");
         fillTheTrayWithWater();          //full the tray with water
         int leftSwitchState = digitalRead(leftSwitch);
         int rightSwitchState = digitalRead(rightSwitch);

         switch (sizeOfIceCube) {

           case 1: //mini cubes
            Serial.println("Making Ice cubes number 1");
            algorithIcecubes(delayForMiniCubes);
            break;

            case 2: //middle cubes
            Serial.println("Making Ice cubes number 2");
            algorithIcecubes(delayForMiddleCubes);
            break;

            case 3: //mega cubes
            Serial.println("Making Ice cubes number 3");
            algorithIcecubes(delayForMegaCubes);
            break;
         }
     }
     else return; //Cartridge is full do not proceed
     }


   void algorithIcecubes(float minutesForCubeSize){
     digitalWrite(valve,LOW);      //heating valve off
     delay(500);
     
     digitalWrite(Compressor,HIGH); //Compressor On
     Serial.println("Compressor ON");
     
     delayForMinutes(minutesForCubeSize); //Waiting to Froze the Ice Cubes
     
     digitalWrite(Compressor,LOW); //Compressor Off
     Serial.println("Compressor OFF");
     
     toTheEndRight(); //empty water
     delay(EmptyingWaterDelay); //wait to empty water   
     digitalWrite(valve,HIGH);      //heating valve off
     delayForMinutes(ValveDealayToHeat); //wait to heat the cubes to fall
     EmptyIceCubes();      
 
   }
