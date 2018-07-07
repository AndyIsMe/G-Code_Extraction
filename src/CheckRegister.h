#ifndef _CHECKREGISTER_H
#define _CHECKREGISTER_H
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "Token.h"
#include "Error.h"



#define isAlpha(x)      (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z'))
#define isNumbers(x)          ((x) >= '0' && (x) <= '9')
#define isEmpty(x)          ((x) == ' ')
#define isDecimal(x)    ((x) == '.')

typedef struct Variable Variable;
struct Variable {
  char name;
  int integer;
  int fraction;
  int isValid;
};
typedef struct VariableMap VariableMap;
struct VariableMap{
  char name;
  Variable *var;
};
Variable xVar = {0,0,0,0};
Variable yVar = {0,0,0,0};
Variable zVar = {0,0,0,0};

typedef struct GCodeMapping GCodeMapping;
struct GCodeMapping{
  char name;
  VariableMap *varMap;
};


typedef struct CheckIndex CheckIndex;
struct CheckIndex{
  int index;
};
//char **fillsInVariableTable(char **linePtrPtr);
Variable fillsInVariableTable(char *linePtrPtr);
// void getChar(char **line);
//char getChar(char **line);
char getChar(char **linePtrPtr,CheckIndex *checkindex);
int getValue(char **linePtrPtr,CheckIndex *checkindex);
int getDeci(char **linePtrPtr,CheckIndex *checkindex);
//char getChar(char **linePtrPtr);
//int getValue(char **linePtrPtr,int index);
#endif // _CHECKREGISTER_H
