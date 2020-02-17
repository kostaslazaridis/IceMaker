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

const int led_AddWater=10;
const int led_IceFull=11;
const int led_Work=12;

const int on_off_Button=9;

//analog input
int waterSensor = A0;
int ThermistorPin = A1;
int SelectorButtons = A2;

//variables-constant



//integers
int sizeOfIceCube=3;
int i=0;


  
void setup() {
 Serial.begin(9600);
 startUpSound();

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
 digitalWrite(valve,HIGH);      //heating valve off
 delay(500);
 digitalWrite(Compressor,LOW); //Compressor On        
 toTheEndRight();
 toTheEndLeft();
 OkSound();

}



void loop() {

    readButtonSelect();

    if(debounced() == true){
      Serial.println("wait to press button");
      digitalWrite(led_Work,LOW);
      i=0;
    }

    if(debounced() == false){
      if(i==0){
        CommandSound();
        delay(1000);
      }
      i=1;
      Serial.println("Button pressed");
      digitalWrite(led_Work,HIGH);
      digitalWrite(led_IceFull,LOW);
      digitalWrite(led_AddWater,LOW);
      
      MakeIceCubes(sizeOfIceCube);
    }
  
}



  
