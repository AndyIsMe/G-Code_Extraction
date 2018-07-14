#include "User.h"


int convertBaseUnitToSteps(float unit,int baseType)
{
  int steps;
  if(baseType == MM_UNIT)
  {
   steps = MM_TO_STEPS(unit);
  }
  if(baseType == INCH_UNIT)
  {
    steps == INCH_TO_STEPS(unit);
  }
  return steps;
}

//User only input value in mm
//Either to convert it to inch then only to steps
//or mm to steps is
//depending on the GCommand 
