#include "CommandCode.h"
#include "CException.h"
#include "Exception.h"
#include "CException.h"
#include "error.h"

int isInMM = 1;
int isAbsolute = 1;

StoreCMD decodeGcode(char *line,GCodeMapping *GCode)
{
  StoreCMD cmd;

    line = getGcodeCommand(line,GCode,&cmd);
    while(cmd.code != (GCode)->code)
    {
    *GCode++;
    }
    getVariables(line,GCode);
    while(cmd.code != (GCode)->code)
    {
    *GCode++;
    }
    (GCode)->doOperation(GCode->code,GCode->varMap);
    return cmd;
}

char *getGcodeCommand(char *line,GCodeMapping *GCode,StoreCMD *cmd)
{
  int i=0;
  char storecode[20] = {0};
  //Check name of the command
  //Whether 'G' or 'M'
  while(isEmpty(*line))
  {
    line  += 1;
  }
  while(*(GCode)->name == NULL)
  {
    *GCode++;
  }
    if(*line == *(GCode)->name)
    {
      cmd->type = *line;
      line += 1;
    }
    else
    {
      throwException(ERROR_COMMAND,"Error! No such command exist\n \
      Expect to be 'G' but was ",*line);
    }
    //Check code
  while(isEmpty(*line))
  {
    line += 1;
  }
  if(isAlpha(*line))
  {
    throwException(ERROR_CODE,"Error! Spotted more than 1 alphabet in a command\n \
    Expect to be an integer but was ",*line);
  }
  while(isNumbers(*line))
  {
      storecode[i] = *line;
      line += 1;
      i++;
  }
  // while(j !=0)
  // {
  //   *GCode--;
  //   GCode->name--;
  //   j--;
  // }
  cmd->code = atoi(storecode);
  while(GCode->name != NULL)
  {
    if(cmd->code == GCode->code)
    {
      return line;
    }
    else
    {
      *GCode++;
    }
  }
  Throw(createException("Error! Code either is not in the same group sharing the \
  same variable or code does not exist\n",ERROR_CODE));
}


void getVariables(char *line,GCodeMapping *GCode)
{

  int j,i=0;
  const int len = strlen(line);
  if(isNumbers(*line))
  {
    throwException(ERROR_VARIABLE,"Error! Invalid variable,expect variable to be \n\
    a character but was ",*line);
  }
  while(isEmpty(*line))
  {
    if(len > 0  && line[len-1] == '/')
    {
      return 0;
    }
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
          throwException(ERROR_DUPLICATE_VARIABLE,"Error! Variable has been declared once",*line);
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
    throwException(NOT_ALPHA,"Error! Expect it to be a character but was ",*line);
  }
  while(i!=0)
  {
    *(GCode)->varMap--;
    i--;
  }
}
  if(*line != NULL)
  {
    throwException(VARIABLE_DOES_NOT_EXIST,"Error! Variable does not exist in this command",*line);
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
    throwException(ERROR_VALUE,"Error! Expect integer since variable has been declared but was ",*line);
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
          throwException(ERROR_VALUE,"Error! Value contains more than 1 ",*line);
        }
      }
    storenum[i] = *line;
    i++;
    line += 1;
  }

  value = atof(storenum);
  (GCode)->varMap->var->value = value;
  return line;

}
void handleG20or21(int code,VariableMap *table)
{
  if(code == 20)
  {
    isInMM = TRUE;
  }
  else
  {
    isInMM = FALSE;
  }
}

void handleG90orG91(int code,Variable *table)
{
  if(code == 90)
  {
    isAbsolute = TRUE;
  }
  else
  {
    isAbsolute = TRUE;
  }
}
void handleG00(int code,VariableMap *g00VarTableMapping)
{
  if(isInMM == TRUE)
  {
        while(g00VarTableMapping->var!=NULL)
        {
          if(g00VarTableMapping->var->name == 'F')
          {
            *(g00VarTableMapping)++;
          }
          else
          {
            g00VarTableMapping->var->steps = MM_TO_STEPS(g00VarTableMapping->var->value);
            *(g00VarTableMapping)++;
          }
        }
  }
  else
  {
    while(g00VarTableMapping->var!=NULL)
    {
      if(g00VarTableMapping->var->name == 'F')
      {
        *(g00VarTableMapping)++;
      }
      else
      {
        g00VarTableMapping->var->steps = INCH_TO_STEPS(g00VarTableMapping->var->value);
        *(g00VarTableMapping)++;
      }
    }
  }

}
