#ifndef _COMMANDCODE_H
#define _COMMANDCODE_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Error.h"


#define isAlpha(x)      (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z'))
#define isNumbers(x)          ((x) >= '0' && (x) <= '9')
#define isEmpty(x)          ((x) == ' ')
#define isDecimal(x)    ((x) == '.')

typedef struct StoreCMD StoreCMD;
struct StoreCMD{
  char SetUpcmd;
  char SetUpCode;
  char type;
  int code;

};

typedef struct Variable Variable;
struct Variable {
  char name;
  double integer;
  int fraction;
  int isValid;
};
typedef struct VariableMap VariableMap;
struct VariableMap{
  char name;
  Variable *var;
};

typedef struct GCodeMapping GCodeMapping;
struct GCodeMapping{
  char *name;
  VariableMap *varMap;
};

typedef struct XYZStep XYZStep;
struct XYZStep{
  int XStep;
  int YStep;
  int ZStep;
};
enum UnitType {MM_UNIT = 0,INCH_UNIT = 1}baseType;
#define MM_TO_STEPS(x) ((x)*8)
#define INCH_TO_STEPS(MM_TO_STEPS) ((MM_TO_STEPS)*8*0.0393701)

//void convertBaseUnitToSteps(VariableMap *var,int baseType);
StoreCMD decodeGcode(char *line,GCodeMapping *GCode);
char *getGcodeCommand(char *line,GCodeMapping *GCode,StoreCMD *cmd);
void getVariables(char *line,GCodeMapping *GCode);
char *getValue(char *line,GCodeMapping *GCode);
int *CheckUnitSetUpCmd(StoreCMD *SetUpCmd,VariableMap *var);
int *convertBaseUnitToSteps(VariableMap *var,int baseType);
int *CheckSetUpCmd(int *Steps,StoreCMD SetUpCmd2);
//void CheckSetUpCmd(StoreCMD SetUpCmd,VariableMap *var);



#endif // _COMMANDCODE_H
