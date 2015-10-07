/* 
Creator: Amit Anand
Contact: amit.anand@alumni.ubc.ca

State Machine for Prothesis Anti-Robot's Spotlights
*/

//Include statements
#include <FiniteStateMachine.h>
#include <VarSpeedServo.h>

//initalize yaw servo
VarSpeedServo YawServo;
const int servoPinYaw_TF = 9;
const int servoPinYaw_BF = 10;

//initialize pitch servo
VarSpeedServo PitchServo;
const int servoPinPitch_TF = 14;

//Initialize States
State All = State(allControl);
State TopFront = State(topFrontControl);
State BottomFront = State(bottomFrontControl);
State Left = State(leftControl);
State Right = State(rightControl);
State Back = State(backControl);

//initialize the state machine
//it will start in the Front state
FSM SpotlightStateMachine = FSM(TopFront);

//debouncing timing
long debounce_time = 50; //milliseconds
volatile unsigned long last_time;

//Input for Joystick
const int joyPinYaw = A0;
const int joyPinPitch = A1;

//Joystick readings
int sensorRead = 0;
int motorSpeed = 0;

//

void setup()
{
  Serial.begin(9600);
  
  //Joystick Setup
  pinMode(joyPinYaw,INPUT);
  
  Serial.println(YawServo.attach(servoPinYaw_TF));
  Serial.println(PitchServo.attach(servoPinPitch_TF));
  YawServo.write(90,255,true);
  
  //Interrupts for switching states
  attachInterrupt(0,nextStateDEBOUNCE,RISING);  //pin 2 (on the MEGA)
  attachInterrupt(1,prevStateDEBOUNCE,RISING);  //pin 3 (on the MEGA)
}

void loop()
{
  controlJoyStick(YawServo,joyPinYaw);
  
  delay(10);
}

