
 
  
  //======================int/float======================//
  
  float Rs,VRs;
  #define R1 10000  //R=10KΩ
  #define Vsupply 5    //Supply voltage
  #define R2 1
  #define R3 10
  #define R4 100
   
 //============================================//
 //               read selector             //
 //============================================//
    void readButtonSelect(){ 
      VRs = analogRead(SelectorButtons);     //Acquisition analog value of VRs
      VRs = (5.00 / 1023.00) * VRs;          //Conversion to voltage
      Rs = (R1*(Vsupply/VRs - 1.0))/1000;    //finding the uknown resistor

      if(Rs>R4-20 && Rs<R4+20){
        sizeOfIceCube=1;
        digitalWrite(led_Small,HIGH);      //heating valve off
        digitalWrite(led_Medium,LOW);      //heating valve off
        digitalWrite(led_Big,LOW);      //heating valve off
        selectSound();
      }
      if(Rs>R3-2 && Rs<R3+2){
        sizeOfIceCube=2;
        digitalWrite(led_Small,LOW);      //heating valve off
        digitalWrite(led_Medium,HIGH);      //heating valve off
        digitalWrite(led_Big,LOW);      //heating valve off
        for(int i=0; i<=1; i++){
          selectSound();
        }
      }
      if(Rs>R2-0.5 && Rs<R2+0.5){
        sizeOfIceCube=3;
        digitalWrite(led_Small,LOW);      //heating valve off
        digitalWrite(led_Medium,LOW);      //heating valve off
        digitalWrite(led_Big,HIGH);      //heating valve off
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
