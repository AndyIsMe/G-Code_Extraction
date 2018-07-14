#ifndef _USER_H
#define _USER_H
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
// #define MM_UNIT 0
// #define INCH_UNIT 1
/*
  *Correct SPU value = ( Current SPU value * Entered distance value ) / Measured distance value
  Current SPU = 200
  Entered Distance = 10mm
  Measured distance = 2.5mm
  Correct SPU value= (200*10)/2.5 = 800 SPU
  *
  *
  *
  */
enum UnitType {MM_UNIT = 0,INCH_UNIT = 1}baseType;
#define MM_TO_STEPS(x) ((x)*8)
#define INCH_TO_STEPS(MM_TO_STEPS) (MM_TO_STEPS*0.0393701)

// enum UnitType baseType

int convertBaseUnitToSteps(float unit,int baseType);


#endif // _USER_H
