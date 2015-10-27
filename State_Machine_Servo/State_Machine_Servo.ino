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
VarSpeedServo YawServo_2;
VarSpeedServo YawServo_3;
VarSpeedServo YawServo_4;
const int servoPinYaw_TF = 9;
const int servoPinYaw_BF = 10;

//initialize pitch servo
VarSpeedServo PitchServo;
VarSpeedServo PitchServo_2;
VarSpeedServo PitchServo_3;
VarSpeedServo PitchServo_4;
const int servoPinPitch_TF = 3;

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

//state number
volatile byte stateNumber = 0;
volatile byte statePowerPin[] = {24,26,28,30,32};

void setup()
{
  Serial.begin(9600);
  
  //Joystick Setup
  pinMode(joyPinYaw,INPUT);
  
  //Set power pins as OUTPUTs and initialize
  for(int i = 0; i<sizeof(statePowerPin); i++)
  {
    pinMode(statePowerPin[i],OUTPUT);
    digitalWrite(statePowerPin[i],LOW);
  }
    
  //Interrupts for switching states
  attachInterrupt(0,nextStateDEBOUNCE,RISING);  //pin 2 (on the MEGA)
  attachInterrupt(1,prevStateDEBOUNCE,RISING);  //pin 3 (on the MEGA)
  
  //Interrupts for turning the light on/off
  attachInterrupt(2,off_DEBOUNCE,RISING);  //pin 18 (on the MEGA)
  attachInterrupt(3,on_DEBOUNCE,RISING);   //pin 19 (on the MEGA)
}

void loop()
{
  controlJoyStick(YawServo,joyPinYaw);
  
  delay(10);
}

