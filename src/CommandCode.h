#ifndef _COMMANDCODE_H
#define _COMMANDCODE_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Error.h"

typedef struct StoreCMD StoreCMD;
struct StoreCMD{
  char type;
  int code;
};

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
// Variable xVar = {0,0,0,0};
// Variable yVar = {0,0,0,0};
// Variable zVar = {0,0,0,0};

typedef struct GCodeMapping GCodeMapping;
struct GCodeMapping{
  char *name;
  VariableMap *varMap;
};
StoreCMD decodeGcode(char *line,GCodeMapping *GCode/*,StoreCMD *cmd*/);
// char *decodeGcode(char *line,GCodeMapping *GCode,StoreCMD *cmd);
char *getGcodeCommand(char *line,GCodeMapping *GCode,StoreCMD *cmd);
// int getVariables(char *line,GCodeMapping *GCode);
void getVariables(char *line,GCodeMapping *GCode);
char *getValue(char *line,GCodeMapping *GCode);
//int decodeGcode(char *line);
//char *getGcodeCommand(char *line,StoreCMD *cmd);



#endif // _COMMANDCODE_H
