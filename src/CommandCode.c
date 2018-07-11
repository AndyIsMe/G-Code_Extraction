#include "CommandCode.h"
#include "CheckRegister.h"
#include "CException.h"
#include "Exception.h"
#include "CException.h"
#include "error.h"

StoreCMD decodeGcode(char *line,GCodeMapping *GCode/*,StoreCMD *cmd*/)
{
  StoreCMD cmd;
  char *line2;
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
      printf("check : %c\n",*line );
      throwException(ERROR_COMMAND,"Error!,no such command exist\n \
      Expect to be 'G' but was %c\n",*line);
    }
    GCode->name += 1;
    //line2 = line;
    // variables = line;
    // return variables;
    line = getGcodeCommand(line,GCode,&cmd);
    getVariables(line,GCode);
    return cmd;
    // valid = getVariables(line,GCode);
    //return variables;
    //getVariables()
  // line = getGcodeCommand(line,&cmd);
  // if(cmd.code==0 && cmd.type=='G')
  // {
  //   fillInVarTableG91(line);
  //   return TRUE;
  // }
  // return FALSE;
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
    Expect to be an integer but was %c\n",*line);
    //checkindex->index += 1;
    //cmd->type = *line;
    //line += 1;
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
    // while(isNumbers(*line))
    // {
    //   storenum[i] = *line;
    //   i++;
    //   line += 1;
    // }
    // cmd->code = atoi(storenum);
    // if(cmd->code >= 100)
    // {
    //   throwException(NOCODE,"Error!,no such code\n");
    // }
    // return line;
}
void getVariables(char *line,GCodeMapping *GCode)
{

  int j,i=0;
  if(isNumbers(*line))
  {
    throwException(ERROR_VARIABLE,"Invalid variable,expect variable to be \n\
    a character but was %c",*line);
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
          throwException(ERROR_DUPLICATE_VARIABLE,"Error,variable of %c has been declared once\n",*line);
        }
      }
      else{
      *(GCode)->varMap++;
      i++;
      // GCode->varMap->var++;
      }
    }
  }
  else{
    throwException(NOT_ALPHA,"Error!,expect it to be a character but was %c\n",*line);
  }
  while(i!=0)
  {
    *(GCode)->varMap--;
    i--;
  }
    //&(*(GCode)->varMap) = &(*(GCode)->varMap) - i;
  // *GCode->varMap =  GCode->varMap[0];
  // GCode->varMap->name = 0;
  // GCode->varMap->var = 0;
}
}

char *getValue(char *line,GCodeMapping *GCode)
{
  int i=0;
  char storenum[20] = {0};
  int value;
  if(isAlpha(*line))
  {
    throwException(ERROR_VALUE,"Error!,expect integer since variable has been declared \
     but was %c\n",*line);
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
  value = atoi(storenum);
  (GCode)->varMap->var->integer = value;
  return line;

}
// int getVariables(char *line,GCodeMapping *GCode)
// {
//   char storenum[20] = {0};
//   int i=0,value;
//   while(isEmpty(*line))
//   {
//     line += 1;
//   }
//   if(isAlpha(*line))
//   {
//     while(isAlpha((GCode)->varMap->name))
//     {
//       if(isEmpty(*line))
//       {
//         line += 1;
//       }
//       if(*line == (GCode)->varMap->name)
//       {
//         (GCode)->varMap->var->name = *line;
//         line += 1;
//         while(isEmpty(*line))
//         {
//           line += 1;
//         }
//         while(isNumbers(*line))
//         {
//           storenum[i] = *line;
//           i++;
//           line += 1;
//         }
//         value = atoi(storenum);
//         (GCode)->varMap->var->integer = value;
//         i=0;
//       }
//       GCode->varMap->name += 1;
//       GCode->varMap->var += 1;
//
//     }
//     return 1;
//   }
//   else{
//     throwException(NOT_ALPHA,"Error!,expect it to be an alphabet but was %c\n",*line);
//   }
// }

// char *getGcodeCommand(char *line,StoreCMD *cmd)
// {
//   int i=0;
//   char storenum[20] = {0};
//   while(isEmpty(*line))
//   {
//     line += 1;
//   }
//   while(isAlpha(*line))
//   {
//     //checkindex->index += 1;
//     cmd->type = *line;
//     line += 1;
//   }
//   while(isEmpty(*line))
//   {
//     line += 1;
//   }
//     while(isNumbers(*line))
//     {
//       storenum[i] = *line;
//       i++;
//       line += 1;
//     }
//     cmd->code = atoi(storenum);
//     if(cmd->code >= 100)
//     {
//       throwException(NOCODE,"Error!,no such code\n");
//     }
//     return line;
// }

// void fillInVarTableG91(char *line)
// {
//   while(isEmpty(*line))
//   {
//     line += 1;
//   }
//   if(*line == varTableG00[0].name)
//   {
//
//   }
// }
