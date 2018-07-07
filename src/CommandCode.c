#include "CommandCode.h"
#include "CheckRegister.h"
#include "CException.h"
#include "Exception.h"
#include "CException.h"
#include "error.h"

int decodeGcode(char *line)
{
  StoreCMD cmd;
  char *variables;
  line = getGcodeCommand(line,&cmd);
  if(cmd.code==0 && cmd.type=='G')
  {
    fillInVarTableG91(line);
    return TRUE;
  }
  return FALSE;
}

char *getGcodeCommand(char *line,StoreCMD *cmd)
{
  int i=0;
  char storenum[20] = {0};
  while(isEmpty(*line))
  {
    line += 1;
  }
  while(isAlpha(*line))
  {
    //checkindex->index += 1;
    cmd->type = *line;
    line += 1;
  }
  while(isEmpty(*line))
  {
    line += 1;
  }
    while(isNumbers(*line))
    {
      storenum[i] = *line;
      i++;
      line += 1;
    }
    cmd->code = atoi(storenum);
    if(cmd->code >= 100)
    {
      throwException(NOCODE,"Error!,no such code\n");
    }
    return line;
}

void fillInVarTableG91(char *line)
{
  while(isEmpty(*line))
  {
    line += 1;
  }
  if(*line == varTableG00[0].name)
  {

  }
}
