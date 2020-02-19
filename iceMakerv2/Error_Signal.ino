void ErrorServoMove(){
  trayMotor.writeMicroseconds(1500); //stop 
  digitalWrite(valve,HIGH);      //heating valve off
  digitalWrite(Compressor,LOW); //Compressor On 
  
  while(1){
    tone(buzzer,1000);
    delay(4000);
    Serial.println("ERROR WITH SERVO");
    digitalWrite(led_Work,HIGH);
    digitalWrite(led_IceFull,HIGH);
    digitalWrite(led_AddWater,HIGH);
    noTone(buzzer);
    delay(1000);
    digitalWrite(led_Work,LOW);
    digitalWrite(led_IceFull,LOW);
    digitalWrite(led_AddWater,LOW);
  }
}
