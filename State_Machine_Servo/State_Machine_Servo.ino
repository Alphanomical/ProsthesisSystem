/* 
Creator: Amit Anand
Contact: amit.anand@alumni.ubc.ca

State Machine for Prothesis Anti-Robot's Spotlights
*/

//Include statements
#include <FiniteStateMachine.h>
#include <VarSpeedServo.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//initialize the PWM Driver Board (using default 0x40 addy)
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN 110
#define SERVOMAX 595

//initalize yaw servo
VarSpeedServo YawServo;
VarSpeedServo YawServo_2;
VarSpeedServo YawServo_3;
VarSpeedServo YawServo_4;
const int servoPinYaw_TF = 9;
const int servoPinYaw_BF = 10;
const int servoPinYaw_R = 11;
const int servoPinYaw_L = 12;
const int servoPinYaw_B = 13;

volatile int currentPos[] = {90,90,90,90,90};

//initialize pitch servo
VarSpeedServo PitchServo;
VarSpeedServo PitchServo_2;
VarSpeedServo PitchServo_3;
VarSpeedServo PitchServo_4;
const int servoPinPitch_TF = 13;

volatile int currentPosPITCH[] = {90,90,90,90,90};

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
long debounce_time = 25; //milliseconds
volatile unsigned long last_time;

//Input for Joystick
const int joyPinYaw = A0;
const int joyPinPitch = A1;

//Joystick readings
int sensorRead = 0;
int motorSpeed = 0;

//state number
volatile boolean updateFlag = false;
volatile byte stateNumber = 0;
volatile byte statePowerPin[] = {24,26,28,30,32};

//function prototype
void printStatements(boolean cs_tf = false,boolean pos_tf = false);

void setup()
{
  Serial.begin(9600);
  
  //pwm board setup
  pwm.begin();
  pwm.setPWMFreq(60); //run at ~60Hz
  
  //Joystick Setup
  pinMode(joyPinYaw,INPUT);
  pinMode(joyPinPitch,INPUT);
  
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
  
  if(updateFlag==true){
  for(int i = 0; i<sizeof(currentPos); i++){pwm.setPWM(i,0,map(currentPos[i],0,180,SERVOMIN,SERVOMAX));}
  updateFlag=false;
  }
 
  printStatements(true);
  
  delay(100);
}


void printStatements(boolean cs_tf, boolean pos_tf){
  
  if(cs_tf){Serial.print("Current State: " );Serial.println(stateNumber);}
  
  if(pos_tf){
  Serial.print("  Positions: ");
  Serial.print(currentPos[0]);
  Serial.print(" ");
  Serial.print(currentPos[1]);
  Serial.print(" ");
  Serial.print(currentPos[2]);
  Serial.print(" ");
  Serial.print(currentPos[3]);
  Serial.print(" ");
  Serial.println(currentPos[4]);
  }
  
}
