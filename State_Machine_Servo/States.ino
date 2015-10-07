//States
//Used to coordinate every state the system can be in
//All Utility functions and pin assignments are here

//Pins representing the lights
//Depending on the state, either 1 or 3 lights will be controlled
const int TopFront_Pin = 48;
const int BottomFront_Pin = 44;
const int Left_Pin = 50;
const int Right_Pin = 46;
const int Back_Pin = 52;

//utility functions
void allControl() {
  Serial.println("All Control");
  
  digitalWrite(TopFront_Pin, HIGH);
  digitalWrite(BottomFront_Pin, LOW);
  digitalWrite(Left_Pin, HIGH);
  digitalWrite(Right_Pin, HIGH);
  digitalWrite(Back_Pin, LOW);
}

void topFrontControl() {
  Serial.println("Top Front Control");
  
  //read the current position 
  //int currentPos = YawServo.read();
  //do something with the current position
  //doSomething();
  //detach servo
  YawServo.detach();
  //attach servo to Top Light
  YawServo.attach(servoPinYaw_TF);
  
  digitalWrite(TopFront_Pin, HIGH);
  digitalWrite(BottomFront_Pin, LOW);
  digitalWrite(Left_Pin, LOW);
  digitalWrite(Right_Pin, LOW);
  digitalWrite(Back_Pin, LOW);
  
}

void bottomFrontControl() {
  Serial.println("Bottom Front Control");
  
  //read the current position 
  //int currentPos = YawServo.read();
  //do something with the current position
  //doSomething();
  //detach servo
  YawServo.detach();
  //attach servo to Top Light
  YawServo.attach(servoPinYaw_BF);
  
  digitalWrite(TopFront_Pin, LOW);
  digitalWrite(BottomFront_Pin, HIGH);
  digitalWrite(Left_Pin, LOW);
  digitalWrite(Right_Pin, LOW);
  digitalWrite(Back_Pin, LOW);
  
}
void leftControl() {
  Serial.println("Left Control");
  
  digitalWrite(TopFront_Pin, LOW);
  digitalWrite(BottomFront_Pin, LOW);
  digitalWrite(Left_Pin, HIGH);
  digitalWrite(Right_Pin, LOW);
  digitalWrite(Back_Pin, LOW);
  
}
void rightControl() {
  Serial.println("Right Control");
  
  //read the current position 
  //int currentPos = YawServo.read();
  //do something with the current position
  //doSomething();
  //detach servo
  YawServo.detach();
  //attach servo to Top Light
  //YawServo.attach(servoPinYaw_TF);
  
  digitalWrite(TopFront_Pin, LOW);
  digitalWrite(BottomFront_Pin, LOW);
  digitalWrite(Left_Pin, LOW);
  digitalWrite(Right_Pin, HIGH);
  digitalWrite(Back_Pin, LOW);
  
}

void backControl() {
  Serial.println("Back Control");
  
  //read the current position 
  //int currentPos = YawServo.read();
  //do something with the current position
  //doSomething();
  //detach servo
  YawServo.detach();
  //attach servo to Top Light
  //YawServo.attach(servoPinYaw_TF);
  
  digitalWrite(TopFront_Pin, LOW);
  digitalWrite(BottomFront_Pin, LOW);
  digitalWrite(Left_Pin, LOW);
  digitalWrite(Right_Pin, LOW);
  digitalWrite(Back_Pin, HIGH);
  
}

