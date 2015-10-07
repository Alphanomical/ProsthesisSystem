//Interupt Service Routines

//ISR for int.0
void nextStateDEBOUNCE()
{
  if((long)(micros()-last_time)>=debounce_time*1000)
  {
    nextState();
    last_time=micros();
  }
}

//top -> bottom -> left -> right -> back -> top
void nextState()
{   
  if(SpotlightStateMachine.isInState(TopFront)) {SpotlightStateMachine.transitionTo(BottomFront);}
  else if(SpotlightStateMachine.isInState(BottomFront)) {SpotlightStateMachine.transitionTo(Left);}
  else if(SpotlightStateMachine.isInState(Left)) {SpotlightStateMachine.transitionTo(Right);}
  else if(SpotlightStateMachine.isInState(Right)) {SpotlightStateMachine.transitionTo(Back);}
  else if(SpotlightStateMachine.isInState(Back)) {SpotlightStateMachine.transitionTo(TopFront);}
  SpotlightStateMachine.update();
}

//ISR for int.1
void prevStateDEBOUNCE()
{
  if((long)(micros()-last_time)>=debounce_time*1000)
  {
    last_time=micros();
    prevState();
  }
}

//back -> right -> left -> bottom -> top -> back
void prevState()
{
  if(SpotlightStateMachine.isInState(Back)) {SpotlightStateMachine.transitionTo(Right);}
  else if(SpotlightStateMachine.isInState(Right)) {SpotlightStateMachine.transitionTo(Left);}
  else if(SpotlightStateMachine.isInState(Left)) {SpotlightStateMachine.transitionTo(BottomFront);}
  else if(SpotlightStateMachine.isInState(BottomFront)) {SpotlightStateMachine.transitionTo(TopFront);}
  else if(SpotlightStateMachine.isInState(TopFront)) {SpotlightStateMachine.transitionTo(Back);}
  SpotlightStateMachine.update();
}


