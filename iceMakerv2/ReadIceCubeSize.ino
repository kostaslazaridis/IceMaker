
 
  
  //======================int/float======================//
  
  float Rs,VRs;
  #define R1 10000  //R=10KΩ
   #define Vsupply 5    //Supply voltage
   
 //============================================//
 //               read selector             //
 //============================================//
    void readButtonSelect(){ 
      VRs = analogRead(SelectorButtons);   //Acquisition analog value of VRT
      VRs = (5.00 / 1023.00) * VRs;      //Conversion to voltage
      Rs = (R1*(Vsupply/VRs - 1.0))/1000;            //finding the uknown resistor

      if(Rs>0.5 && Rs<1.5){
        sizeOfIceCube=1;
        selectSound();
      }
      if(Rs>8 && Rs<12){
        sizeOfIceCube=2;
        for(int i=0; i<=1; i++){
          selectSound();
        }
      }
      if(Rs>60 && Rs<130){
        sizeOfIceCube=3;
        for(int i=0; i<=2; i++){
          selectSound();
        }
      }
      Serial.print("sizeOfIceCube| ");
      Serial.print("\t| ");
      Serial.print(sizeOfIceCube);
      Serial.print("\t| ");
      Serial.print("| Resistance");
      Serial.print("\t| ");
      Serial.print(Rs);
      Serial.println("kΩ |\t ");

  }
