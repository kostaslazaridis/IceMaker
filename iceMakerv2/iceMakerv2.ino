#include <Servo.h> 

Servo trayMotor;


//pins
//digital input
const int valve=2;
const int servoMotor=3;
const int Compressor=4;
const int buzzer=5;
const int waterPump=6;
const int leftSwitch=7;
const int rightSwitch=8;

const int led_AddWater=9;
const int led_IceFull=10;
const int led_Work=11;

const int on_off_Button=12;

//analog input
int ThermistorPin = A0;
int waterSensor = A1;


//variables-constant
//=======================boolean=======================//


//======================int/float======================//

float RT, VR, ln, TX, T0, VRT;

#define VCC 5    //Supply voltage
#define R 10000  //R=10KΩ
#define RT0 10000   // Ω
#define B 3977      // K

//========================servo========================//
const int speedServoToTheRightMicrosecond=1700;
const int speedServoToTheLeftMicrosecond=1350;
const int stopServo=1500;

//========================delays=======================//
const int waterPumpTime=3000;
const int delayForMiniCubes=10;   
const int delayForMiddleCubes=13; 
const int delayForMegaCubes=15;    
const int delayEmptingWaterMinute=2; 
const int delayTimeBetween_left_and_right=2;
//---------------------microseconds--------------------//
const int oneMinute=60000; //1minute=60000microsecond


//integers
int delayEmptingWater=delayEmptingWaterMinute*60000; 
int sizeOfIceCube=3;

//===============debounced====================
int State = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers




  
void setup() {
  Serial.begin(9600);
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
T0 = 25 + 273.15;
 digitalWrite(valve,LOW);        //begin with valve on 
 digitalWrite(Compressor,LOW);   //begin with compressor off
 toTheEndLeft();
 tone(buzzer,1000);
 delay(1000);
 noTone(buzzer);
}



void loop() {

 digitalWrite(valve,HIGH);      //heating valve off
            Serial.println("valve off");
            delay(1000);
            digitalWrite(Compressor,HIGH); //Compressor On
            Serial.println("compressor on");
            delay(delayForMegaCubes*oneMinute); //wait...
            Serial.println("end delay");
            digitalWrite(Compressor,LOW); //Compressor Off
            toTheEndRight(); //empty water
            delay(3000); //wait to empty water
            toTheEndRight(); //going to collect ice cubes                
            digitalWrite(valve,HIGH);      //heating valve off
            delay(2000);
//
//  if(debounced() == true){
//    Serial.println("wait to press button");
//    digitalWrite(led_Work,LOW);
//  }
//
//  if(debounced() == false){
//    Serial.println("working");
  //   MakeIceCubes(3);
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
  void MakeIceCubes(int sizeOfIceCube){
  Serial.println("check if Cartridge Is Full");
  
    //******************check cartridge if it is full******************  
    if(checkIfCartridgeIsFull==true){
      Serial.println("Cartridge Is Full");
    
      digitalWrite(led_IceFull,HIGH);    //ICE FULL light indicator on
      
      for(int i=0;i<=3;i++){         // 3 times buzzer tone 
        tone(buzzer,1000);
        delay(1000);
        noTone(buzzer);
      }
      State=HIGH;
    }

    //****************check cartridge if it is nor full****************  
    else{
      Serial.println("Making Ice cubes");
      
        if (fillTheTrayWithWater()== true){
        
        int leftSwitchState = digitalRead(leftSwitch);
        int rightSwitchState = digitalRead(rightSwitch);
        
      switch (sizeOfIceCube) {


        case 1: //mini cubes
          Serial.println("Making Ice cubes number 1");
          
          if(rightSwitchState==HIGH && leftSwitchState==LOW){ //If it is on the right position (water hold)
            digitalWrite(led_Work,HIGH);        //work light on
            digitalWrite(valve,HIGH);      //heating valve off
            delay(500);
            digitalWrite(Compressor,HIGH); //Compressor On
            delay(delayForMiniCubes*oneMinute); //wait...
            digitalWrite(Compressor,LOW); //Compressor Off
            toTheEndLeft(); //empty water
            delay(delayEmptingWater*oneMinute); //wait to empty water                 
            digitalWrite(valve,HIGH);      //heating valve off
            delay(2000);
            EmptyIceCubes();
          }
          break;
          
        case 2: //middle cubes
        Serial.println("Making Ice cubes number 2");
          if(rightSwitchState==HIGH && leftSwitchState==LOW){ //If it is on the right position (water hold)
            digitalWrite(led_Work,HIGH);        //work light on
            digitalWrite(valve,HIGH);      //heating valve off
            delay(500);
            digitalWrite(Compressor,HIGH); //Compressor On
            delay(delayForMiddleCubes*oneMinute); //wait...
            digitalWrite(Compressor,LOW); //Compressor Off
            toTheEndLeft(); //empty water
            delay(delayEmptingWater*oneMinute); //wait to empty water                 
            digitalWrite(valve,HIGH);      //heating valve off
            delay(2000);
            EmptyIceCubes();
          }
          break;
          
        case 3: //mega cubes
        Serial.println("Making Ice cubes number 3");
          if(rightSwitchState==HIGH && leftSwitchState==LOW){ //If it is on the right position (water hold)
        
            digitalWrite(valve,HIGH);      //heating valve off
            Serial.println("valve off");
            delay(1000);
            digitalWrite(Compressor,HIGH); //Compressor On
            Serial.println("compressor on");
            delay(delayForMegaCubes*oneMinute); //wait...
            Serial.println("end delay");
            digitalWrite(Compressor,LOW); //Compressor Off
            toTheEndRight(); //empty water
            delay(3000); //wait to empty water
            toTheEndRight(); //going to collect ice cubes                
            digitalWrite(valve,HIGH);      //heating valve off
            delay(2000);
            EmptyIceCubes();
          }
          break;  
          }      
        }
        else if (fillTheTrayWithWater() == false){
         Serial.println("no water, going back");
        State=HIGH;
        
        }
    }
  }

 //=====================================================================================================================//
 // check if the Cartridge is Full, videlicet the temperature is near zero                                              //
 //=====================================================================================================================//
  boolean checkIfCartridgeIsFull(){ 
      VRT = analogRead(ThermistorPin);              //Acquisition analog value of VRT
      VRT = (5.00 / 1023.00) * VRT;      //Conversion to voltage
      VR = VCC - VRT;
      RT = VRT / (VR / R);               //Resistance of RT
    
      ln = log(RT / RT0);
      TX = (1 / ((ln / B) + (1 / T0))); //Temperature from thermistor
    
      TX = TX - 273.15;                 //Conversion to Celsius
    
      Serial.print("Temperature:");
      Serial.print("\t");
      Serial.print(TX);
      Serial.print("C\t\t");
      Serial.print(TX + 273.15);        //Conversion to Kelvin
      Serial.print("K\t\t");
      Serial.print((TX * 1.8) + 32);    //Conversion to Fahrenheit
      Serial.println("F");

      if(TX<=4){
        return true;
      }
      else{
        return false;
      }
  }

 //=====================================================================================================================//
 //                                             check if the Cartridge has Water                                        //
 //=====================================================================================================================//
  boolean checkNoWater(){ 
    
      float V1 = analogRead(waterSensor);
      Serial.println(V1);
      if(V1>7){
        return true;
      }
      else
        digitalWrite(led_AddWater,HIGH);
        digitalWrite(waterPump,LOW);
        return false;
  } 

 //=====================================================================================================================//
 //   empty ice cubes from tray, basicly it is a reciprocating motion and at the end it goes to the original position   //
 //=====================================================================================================================//
  void EmptyIceCubes(){ 
    
    
      toTheEndLeft();
      delay(delayTimeBetween_left_and_right*oneMinute);
      toTheEndRight();
    
  }

 //=============================================//
 //     empty the water from tray (go left)     //
 //=============================================//
  void EmptyWaterfromWaterTray(){
    
    if(rightSwitch==LOW && leftSwitch==HIGH){ //If it is on the right position (water hold)
      toTheEndLeft();
    }

    if(rightSwitch==HIGH && leftSwitch==LOW){ //If it is on the left position (empty tray)
    }

    if(rightSwitch==HIGH && leftSwitch==HIGH){ //If it is on the middle
      toTheEndLeft();
    }
    
  }

 //============================================//
 //          fill the tray with water          //
 //============================================//
  boolean fillTheTrayWithWater(){
    
  
      toTheEndLeft();
      digitalWrite(waterPump,HIGH); //water pump on
      
      for(int i=0;i<=unsigned(waterPumpTime);i++){
        if(i>=2000){
        if(checkNoWater() == false){ 
          Serial.println("NO WATER, ADD WATER PLEASE"); 
          return false;
        }
        }
        else delay(1);
      }
      
      digitalWrite(waterPump,LOW);  //water pump off
      return true;
 
  }
  
 //============================================//
 //   go right until it hit the limit switch   //
 //============================================//
  void toTheEndRight(){
     int rightSwitchState = digitalRead(rightSwitch);
    if(rightSwitchState==HIGH){
    do{
      delay(100);
      rightSwitchState = digitalRead(rightSwitch);
      trayMotor.writeMicroseconds(speedServoToTheRightMicrosecond);  //turn right
    }while (rightSwitchState==HIGH);
    trayMotor.writeMicroseconds(stopServo); //stop 
    }
  }

 //============================================//
 //    go left until it hit the limit switch   //
 //============================================//
  void toTheEndLeft(){
     int leftSwitchState = digitalRead(leftSwitch);
    if(leftSwitchState==HIGH){
    do{
      delay(100);
      leftSwitchState = digitalRead(leftSwitch);
      Serial.println("moving");
      trayMotor.writeMicroseconds(speedServoToTheLeftMicrosecond);  //turn right
    }while (leftSwitchState==HIGH);
    Serial.println("stop moving");
    trayMotor.writeMicroseconds(stopServo); //stop 
    }
  }
  
