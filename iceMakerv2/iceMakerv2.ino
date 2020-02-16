#include <Servo.h> 

Servo trayMotor;


//pins
//digital input
const int valve=2;
const int servoMotor=3;
const int Compressor=4;
const int buzzer=5;
const int waterPump=6;
const int rightSwitch=7;
const int leftSwitch=8;

const int led_AddWater=11;
const int led_IceFull=10;
const int led_Work=12;

const int on_off_Button=9;

//analog input
int waterSensor = A0;
int ThermistorPin = A1;
int SelectorButtons = A2;

//variables-constant



//integers
int sizeOfIceCube=3;

//===============debounced====================
int State = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

//temp
const int tempValueforFull=4; //degrees to stop the machine because it's full


  
void setup() {
 Serial.begin(9600);
 //-----------------
 // start up beep
 //-----------------
 tone(buzzer,1000);
 delay(300);
 noTone(buzzer);
 delay(100);
 tone(buzzer,1000);
 delay(300);
 noTone(buzzer);
 delay(1000);
 //-----------------
 // stop beep
 //-----------------


 //---------------------------
 //connecting the components
 //---------------------------
 
 trayMotor.attach(servoMotor);
 
 pinMode(valve,OUTPUT);
 pinMode(Compressor,OUTPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(waterPump,OUTPUT);
 pinMode(leftSwitch,INPUT);
 pinMode(rightSwitch,INPUT);
 pinMode(led_Work,OUTPUT);
 pinMode(led_IceFull,OUTPUT);
 pinMode(led_AddWater,OUTPUT);
 pinMode(on_off_Button,INPUT);



//----------INITIALIZE----------------//
         

 toTheEndRight();
 toTheEndLeft();
 tone(buzzer,1000);
 delay(1000);
 noTone(buzzer);

 
}



void loop() {




          
//
// digitalWrite(valve,HIGH);      //heating valve off
//            Serial.println("valve off");
//            delay(1000);
//            digitalWrite(Compressor,HIGH); //Compressor On
//            Serial.println("compressor on");
//            delay(delayForMegaCubes*oneMinute); //wait...
//            Serial.println("end delay");
//            digitalWrite(Compressor,LOW); //Compressor Off
//            toTheEndRight(); //empty water
//            delay(3000); //wait to empty water
//            toTheEndRight(); //going to collect ice cubes                
//            digitalWrite(valve,HIGH);      //heating valve off
//            delay(2000);
//
//  if(debounced() == true){
//    Serial.println("wait to press button");
//    digitalWrite(led_Work,LOW);
//  }
//
//  if(debounced() == false){
//    Serial.println("working");

     //MakeIceCubes(3);

//    digitalWrite(led_Work,HIGH);
//  }
  
}




//-------------------------------------------------------------------------//
//--------------------------------FUNCTIONS--------------------------------//
//-------------------------------------------------------------------------//

 //=====================================================//
 //                    debounced button                 //
 //=====================================================//
  boolean debounced(){
      // read the state of the switch into a local variable:
  int reading = digitalRead(on_off_Button);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        State = !State;
      }
    }
  }



  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

    if(State==HIGH){
      return true;
    }
    else{
      return false;
    }

  }
  
 //=====================================================//
 //     make ice cubes 1(mini),2(middle) or 3(mega)     //
 //=====================================================//
//  void MakeIceCubes(int sizeOfIceCube){
//  Serial.println("check if Cartridge Is Full");
//  
//    //******************check cartridge if it is full******************  
//    if(checkIfCartridgeIsFull==true){
//      Serial.println("Cartridge Is Full");
//    
//      digitalWrite(led_IceFull,HIGH);    //ICE FULL light indicator on
//      
//      for(int i=0;i<=3;i++){         // 3 times buzzer tone 
//        tone(buzzer,1000);
//        delay(1000);
//        noTone(buzzer);
//      }
//      State=HIGH;
//    }
//
//    //****************check cartridge if it is nor full****************  
//    else{
//      Serial.println("Making Ice cubes");
//      
//        fillTheTrayWithWater();
//        
//        int leftSwitchState = digitalRead(leftSwitch);
//        int rightSwitchState = digitalRead(rightSwitch);
//        
//      switch (sizeOfIceCube) {
//
//
//        case 1: //mini cubes
//          Serial.println("Making Ice cubes number 1");
//          
//          if(rightSwitchState==HIGH && leftSwitchState==LOW){ //If it is on the right position (water hold)
//            digitalWrite(led_Work,HIGH);        //work light on
//            digitalWrite(valve,HIGH);      //heating valve off
//            delay(500);
//            digitalWrite(Compressor,HIGH); //Compressor On
//            delay(delayForMiniCubes*oneMinute); //wait...
//            digitalWrite(Compressor,LOW); //Compressor Off
//            toTheEndLeft(); //empty water
//            delay(delayEmptingWater*oneMinute); //wait to empty water                 
//            digitalWrite(valve,HIGH);      //heating valve off
//            delay(2000);
//            EmptyIceCubes();
//          }
//          break;
//          
//        case 2: //middle cubes
//        Serial.println("Making Ice cubes number 2");
//          if(rightSwitchState==HIGH && leftSwitchState==LOW){ //If it is on the right position (water hold)
//            digitalWrite(led_Work,HIGH);        //work light on
//            digitalWrite(valve,HIGH);      //heating valve off
//            delay(500);
//            digitalWrite(Compressor,HIGH); //Compressor On
//            delay(delayForMiddleCubes*oneMinute); //wait...
//            digitalWrite(Compressor,LOW); //Compressor Off
//            toTheEndLeft(); //empty water
//            delay(delayEmptingWater*oneMinute); //wait to empty water                 
//            digitalWrite(valve,HIGH);      //heating valve off
//            delay(2000);
//            EmptyIceCubes();
//          }
//          break;
//          
//        case 3: //mega cubes
//        Serial.println("Making Ice cubes number 3");
//          if(rightSwitchState==HIGH && leftSwitchState==LOW){ //If it is on the right position (water hold)
//        
//            digitalWrite(valve,HIGH);      //heating valve off
//            Serial.println("valve off");
//            delay(1000);
//            digitalWrite(Compressor,HIGH); //Compressor On
//            Serial.println("compressor on");
//            delay(delayForMegaCubes*oneMinute); //wait...
//            Serial.println("end delay");
//            digitalWrite(Compressor,LOW); //Compressor Off
//            toTheEndRight(); //empty water
//            delay(3000); //wait to empty water
//            toTheEndRight(); //going to collect ice cubes                
//            digitalWrite(valve,HIGH);      //heating valve off
//            delay(2000);
//            EmptyIceCubes();
//          }
//          break;  
//          }      
//        
//
//    }
//  }








  
