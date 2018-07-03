#ifndef _CHECKREGISTER_H
#define _CHECKREGISTER_H
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "Token.h"
#include "Error.h"
#include "Exception.h"
#include "CExceptionConfig.h"

#define isCharacter(x)      (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z'))
#define isNumbers(x)          ((x) >= '0' && (x) <= '9')
#define isNULL(x)          ((x) == ' ')

typedef struct Variable Variable;
struct Variable {
  char name;
  int integer;
  int fraction;
  int isValid;
};
//char **fillsInVariableTable(char **linePtrPtr);
void fillsInVariableTable(char *linePtrPtr);
// void getChar(char **line);
//char getChar(char **line);
int getChar(char **linePtrPtr);
int getValue(char **linePtrPtr,int index);
#endif // _CHECKREGISTER_H
