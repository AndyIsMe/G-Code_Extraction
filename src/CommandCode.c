#include "CommandCode.h"
#include "CException.h"
#include "Exception.h"
#include "CException.h"
#include "error.h"

StoreCMD decodeGcode(char *line,GCodeMapping *GCode)
{
  StoreCMD cmd;
  while(isEmpty(*line))
  {
    line  += 1;
  }
    if(*line == *(GCode)->name)
    {
      cmd.type = *line;
      line += 1;
    }
    else
    {
      throwException(ERROR_COMMAND,"Error!,no such command exist\n \
      Expect to be 'G' but was ",*line);
    }
    GCode->name += 1;
    line = getGcodeCommand(line,GCode,&cmd);
    getVariables(line,GCode);
    return cmd;
}

char *getGcodeCommand(char *line,GCodeMapping *GCode,StoreCMD *cmd)
{
  int i=0,j;
  char storecode[20] = {0};
  while(isEmpty(*line))
  {
    line += 1;
  }
  if(isAlpha(*line))
  {
    throwException(ERROR_CODE,"Error!,spotted more than 1 alphabet in a command\n \
    Expect to be an integer but was ",*line);
  }
  for(i=0 ; i<2 ; i++)
  {
    if(*line == *(GCode)->name)
    {
      storecode[i] = *line;
      line += 1;
      GCode->name += 1;
    }
    else
    {
      Throw(createException("Error!,code either is not in the same group sharing the \
      same variable or code does not exist\n",ERROR_CODE));
    }
  }
  cmd->code = atoi(storecode);
  // if(cmd->code >= 100)
  // {
  //   throwException(NOCODE,"Error!,no such code\n");
  // }
  return line;
}
void getVariables(char *line,GCodeMapping *GCode)
{

  int j,i=0;
  if(isNumbers(*line))
  {
    throwException(ERROR_VARIABLE,"Invalid variable,expect variable to be \n\
    a character but was ",*line);
  }
  while(isEmpty(*line))
  {
    line += 1;
  }
  for(j=0;j<strlen(line);j++)
  {
  if(isAlpha(*line))
  {
    while(((GCode)->varMap->name)!=NULL)
    {
      if(isEmpty(*line))
      {
        line += 1;
      }
      if(*line == (GCode)->varMap->name)
      {
        if((GCode)->varMap->var->isValid == 0)
        {
          (GCode)->varMap->var->name = *line;
          line += 1;
          line = getValue(line,GCode);
          (GCode)->varMap->var->isValid = 1;
        }
        else
        {
          throwException(ERROR_DUPLICATE_VARIABLE,"Error,variable has been declared once",*line);
        }
      }
      else{
      *(GCode)->varMap++;
      i++;
      // if(*line != (GCode)->varMap->name && ((GCode)->varMap->name)==NULL)
      // {
      //   throwException(VARIABLE_DOES_NOT_EXIST,"Error,variable does not exist in this command",*line);
      // }
      }
    }
  }
  else{
    throwException(NOT_ALPHA,"Error!,expect it to be a character but was ",*line);
  }
  while(i!=0)
  {
    *(GCode)->varMap--;
    i--;
  }
}
  if(*line != NULL)
  {
    throwException(VARIABLE_DOES_NOT_EXIST,"Error,variable does not exist in this command",*line);
  }
}

char *getValue(char *line,GCodeMapping *GCode)
{
  int i=0;
  int validate_decimal = 0;
  char storenum[20] = {0};
  double value;
  if(isAlpha(*line))
  {
    throwException(ERROR_VALUE,"Error!,expect integer since variable has been declared but was ",*line);
  }
  while(isEmpty(*line))
  {
    line += 1;
  }
  while(isNumbers(*line)||isDecimal(*line))
  {
      if(isDecimal(*line))
      {
        if(validate_decimal == FALSE)
        {
          storenum[i] = *line;
          line += 1;
          i++;
          validate_decimal = TRUE;
        }
        else{
          throwException(ERROR_VALUE,"Value contains more than 1 ",*line);
        }
      }
    storenum[i] = *line;
    i++;
    line += 1;
  }

  value = atof(storenum);
  (GCode)->varMap->var->integer = value;
  return line;

}
