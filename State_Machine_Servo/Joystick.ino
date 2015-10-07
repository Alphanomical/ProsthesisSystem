//Function: controlJoyStick
//Input: Servo Object, Joystick Pin
//Output: None
//Purpose: This function reads the joystick and moves the servo proportionally
void controlJoyStick(VarSpeedServo thisServo, int Joystick)
{
  //Read the sensor, center reading about zero
  sensorRead = analogRead(Joystick)-int(512);  
  
  //Create a deadzone in the center to account for vibrational noise
  if(sensorRead<25 && sensorRead>-25){sensorRead=0;}
  
  //A positive reading, move servo in +direction 
  if(sensorRead>0)
  {
    //map speed from 1-255
    motorSpeed = map(sensorRead,0,512,1,255);
    thisServo.write(180,motorSpeed);
  }
  //A negative reading, move servo in -direction
  else if(sensorRead<0)
  {
    //map speed from 1-255
    motorSpeed = map(sensorRead,0,-512,1,255);
    thisServo.write(0,motorSpeed);
  }
  //A zero reading will stop the servo at the current position
  else
  {
    motorSpeed = 0;
    thisServo.stop();
  }
}

