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



int decodeGcode(char *line);
char *getGcodeCommand(char *line,StoreCMD *cmd);



#endif // _COMMANDCODE_H
