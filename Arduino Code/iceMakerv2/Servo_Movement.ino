
 //========================servo========================//
 const int speedServoToTheRightMicrosecond=1780;
 const int speedServoToTheLeftMicrosecond=1250;
 const int stopServo=1500;

 //delays 
 const int delayTimeBetween_left_and_right=2000;
 const int maximumTimeForMoving=3000;
 //============================================//
 //   go right until it hit the limit switch   //
 //============================================//
  void toTheEndRight(){
    unsigned long StartTime = millis();
    unsigned long CurrentTime = millis();
    unsigned long ElapsedTime=0;
    
    Serial.println("Going Right");
    int rightSwitchState = digitalRead(rightSwitch);
    Serial.println(rightSwitchState);
    
    if(rightSwitchState==LOW){
    do{
      CurrentTime = millis();
      ElapsedTime = CurrentTime - StartTime;
      
      delay(100);
      rightSwitchState = digitalRead(rightSwitch);
      Serial.println("moving");
      trayMotor.writeMicroseconds(speedServoToTheRightMicrosecond);  //turn right
      
      if(ElapsedTime>maximumTimeForMoving){
        ErrorServoMove();
      }
    }while (rightSwitchState==LOW);
    trayMotor.writeMicroseconds(stopServo); //stop 
    }
  }

 //============================================//
 //    go left until it hit the limit switch   //
 //============================================//
  void toTheEndLeft(){
    unsigned long StartTime = millis();
    unsigned long CurrentTime = millis();
    unsigned long ElapsedTime=0;
    
    Serial.println("Going Left");
    int leftSwitchState = digitalRead(leftSwitch);
    Serial.println(leftSwitchState);
    
    if(leftSwitchState==LOW){
    do{
      CurrentTime = millis();
      ElapsedTime = CurrentTime - StartTime;
      delay(100);
      leftSwitchState = digitalRead(leftSwitch);
      Serial.println("moving");
      trayMotor.writeMicroseconds(speedServoToTheLeftMicrosecond);  //turn left
      if(ElapsedTime>maximumTimeForMoving){
        ErrorServoMove();
      }
    }while (leftSwitchState==LOW);
    Serial.println("stop moving");
    trayMotor.writeMicroseconds(stopServo); //stop 
    }
  }

 //=====================================================================================================================//
 //   empty ice cubes from tray, basicly it is a reciprocating motion and at the end it goes to the original position   //
 //=====================================================================================================================//
  void EmptyIceCubes(){ 
      Serial.println("emptying IceCubes");
      toTheEndLeft();
      delay(delayTimeBetween_left_and_right);
      toTheEndRight();
      delay(delayTimeBetween_left_and_right);
      toTheEndLeft();
    
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
