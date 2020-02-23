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

const int led_Small = A3;
const int led_Medium = A4;
const int led_Big = A5;

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
 pinMode(led_Small,OUTPUT);
 pinMode(led_Medium,OUTPUT);
 pinMode(led_Big,OUTPUT);
 pinMode(on_off_Button,INPUT);

 

//----------INITIALIZE----------------//
 digitalWrite(led_Work,LOW);         //LED WORK off
 digitalWrite(led_IceFull,LOW);      //LED IceFull off
 digitalWrite(led_AddWater,LOW);     //LED AddWater off
 digitalWrite(led_Small,LOW);        //LED Small off
 digitalWrite(led_Medium,LOW);       //LED Medium off
 digitalWrite(led_Big,LOW);          //LED Big off
  
 startUpSound();

 digitalWrite(valve,HIGH);      //heating valve off
 delay(500);
 digitalWrite(Compressor,LOW); //Compressor On
 digitalWrite(led_Big,HIGH);      //heating valve off        
 toTheEndRight();
 toTheEndLeft();
 OkSound();
 LedIceCube();
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
        delay(500);
      }
      i=1;
      Serial.println("Button pressed");
      digitalWrite(led_Work,HIGH);
      digitalWrite(led_IceFull,LOW);
      digitalWrite(led_AddWater,LOW);
      
      MakeIceCubes(sizeOfIceCube);
    }
  
}


void LedIceCube(){
  if(sizeOfIceCube==1){
     digitalWrite(led_Small,HIGH);        //LED Small on
     digitalWrite(led_Medium,LOW);       //LED Medium off
     digitalWrite(led_Big,LOW);          //LED Big off
  }
  else if(sizeOfIceCube==2){
     digitalWrite(led_Small,LOW);        //LED Small off
     digitalWrite(led_Medium,HIGH);      //LED Medium on
     digitalWrite(led_Big,LOW);          //LED Big off
  }
  else if(sizeOfIceCube==3){
     digitalWrite(led_Small,LOW);        //LED Small off
     digitalWrite(led_Medium,LOW);       //LED Medium off
     digitalWrite(led_Big,HIGH);         //LED Big on
  }
}
  
