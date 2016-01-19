//States
//Used to coordinate every state the system can be in
//All Utility functions and pin assignments are here

//Pins representing the lights
const int TopFront_Pin = 48;
const int BottomFront_Pin = 44;
const int Left_Pin = 50;
const int Right_Pin = 46;
const int Back_Pin = 52;

const int Multi_TF_A = 23;
const int Multi_TF_B = 25;

//utility functions
void allControl() {
  Serial.println("All Control");
  stateNumber = 5;
  digitalWrite(TopFront_Pin, HIGH);
  digitalWrite(BottomFront_Pin, LOW);
  digitalWrite(Left_Pin, HIGH);
  digitalWrite(Right_Pin, HIGH);
  digitalWrite(Back_Pin, LOW); 
}

void topFrontControl() {
  Serial.println("Top Front Control");
  stateNumber = 0;
  
  //detach servo
  YawServo.detach();
  PitchServo.detach();
  //attach servo to Top Light
  YawServo.attach(servoPinYaw_TF);
  YawServo.write(currentPos[stateNumber]);
  PitchServo.attach(servoPinPitch_TF);
  PitchServo.write(currentPosPITCH[stateNumber]);
  
  digitalWrite(Multi_TF_A, LOW);
  digitalWrite(Multi_TF_B, LOW);
  
  digitalWrite(TopFront_Pin, HIGH);
  digitalWrite(BottomFront_Pin, LOW);
  digitalWrite(Left_Pin, LOW);
  digitalWrite(Right_Pin, LOW);
  digitalWrite(Back_Pin, LOW);
}

void bottomFrontControl() {
  Serial.println("Bottom Front Control");
  stateNumber = 1;
  //detach servo
  YawServo.detach();
  PitchServo.detach();
  //attach servo to Top Light
  YawServo.attach(servoPinYaw_BF);
  YawServo.write(currentPos[stateNumber]);
  
  digitalWrite(Multi_TF_A, HIGH);
  digitalWrite(Multi_TF_B, LOW);
  
  digitalWrite(TopFront_Pin, LOW);
  digitalWrite(BottomFront_Pin, HIGH);
  digitalWrite(Left_Pin, LOW);
  digitalWrite(Right_Pin, LOW);
  digitalWrite(Back_Pin, LOW);
}

void leftControl() {
  Serial.println("Left Control");
  stateNumber = 2;
  //detach servo
  YawServo.detach();
  PitchServo.detach();
  //attach servo to Top Light
  YawServo.attach(servoPinYaw_L);
  YawServo.write(currentPos[stateNumber]);
  
  digitalWrite(Multi_TF_A, HIGH);
  digitalWrite(Multi_TF_B, LOW);
  
  digitalWrite(TopFront_Pin, LOW);
  digitalWrite(BottomFront_Pin, LOW);
  digitalWrite(Left_Pin, HIGH);
  digitalWrite(Right_Pin, LOW);
  digitalWrite(Back_Pin, LOW);
}

void rightControl() {
  Serial.println("Right Control");
  stateNumber = 3;
  //detach servo
  YawServo.detach();
  PitchServo.detach();
  //attach servo to Top Light
  YawServo.attach(servoPinYaw_R);
  YawServo.write(currentPos[stateNumber]);
  
  digitalWrite(Multi_TF_A, HIGH);
  digitalWrite(Multi_TF_B, LOW);
  
  digitalWrite(TopFront_Pin, LOW);
  digitalWrite(BottomFront_Pin, LOW);
  digitalWrite(Left_Pin, LOW);
  digitalWrite(Right_Pin, HIGH);
  digitalWrite(Back_Pin, LOW);
}

void backControl() {
  Serial.println("Back Control");
  stateNumber = 4;
  
  //detach servo
  YawServo.detach();
  PitchServo.detach();
  //attach servo to Top Light
  YawServo.attach(servoPinYaw_B );
  YawServo.write(currentPos[stateNumber]);
  
  digitalWrite(Multi_TF_A, HIGH);
  digitalWrite(Multi_TF_B, LOW);
  
  digitalWrite(TopFront_Pin, LOW);
  digitalWrite(BottomFront_Pin, LOW);
  digitalWrite(Left_Pin, LOW);
  digitalWrite(Right_Pin, LOW);
  digitalWrite(Back_Pin, HIGH);
  
  
}

