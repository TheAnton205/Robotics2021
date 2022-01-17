/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\sharonovan23                                     */
/*    Created:      Thu Dec 16 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Drivetrain           drivetrain    1, 2, 9, 10     
// RightUp              motor         7               
// RightDown            motor         6               
// LeftUp               motor         3               
// LeftDown             motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool L1 = false;
bool L2 = false;

void L1Pressed() {
  RightUp.spinToPosition(450.0,deg,100,dps,false);
  LeftUp.spinToPosition(450,deg,100,dps,false);
  RightDown.spinToPosition(800.0,deg,350,dps,false);
  LeftDown.spinToPosition(800.0,deg,350,dps,true);

  }

void L2Pressed() {
  RightDown.resetPosition();
  LeftDown.resetPosition();
  RightDown.spinToPosition(-430,deg,160,dps,false);
  LeftDown.spinToPosition(-420,deg,160,dps,false);
  RightUp.spinToPosition(-200,deg,100,dps,false);
  LeftUp.spinToPosition(-200,deg,100,dps,false);


}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  //Controller1.ButtonL1.pressed(L1Pressed);
  while(true) {
    RightUp.resetPosition();
    LeftUp.resetPosition();
    Controller1.ButtonL1.pressed(L1Pressed);
    Controller1.ButtonL2.pressed(L2Pressed);
    if(Controller1.ButtonR1.pressing()){
      LeftDown.rotateFor(50,deg,false);
      RightDown.rotateFor(50,deg,false);
    }
    if(Controller1.ButtonR2.pressing()){
      LeftDown.rotateFor(-50,deg,false);
      RightDown.rotateFor(-50,deg,false);
    }
    if(Controller1.ButtonX.pressing()) {
      LeftUp.rotateFor(-100,deg,50,dps,false);
      RightUp.rotateFor(-100,deg,50,dps,false);
      LeftDown.rotateFor(-50,deg,50,dps,false);
      RightDown.rotateFor(-50,deg,50,dps,false);
    }
    if(Controller1.ButtonB.pressing()){
      LeftDown.rotateFor(50,deg,50,dps,false);
      RightDown.rotateFor(50,deg,50,dps,false);
    }
    
  }
}
