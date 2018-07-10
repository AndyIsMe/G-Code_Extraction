#include "CommandCode.h"
#include "CheckRegister.h"
#include "CException.h"
#include "Exception.h"
#include "CException.h"
#include "error.h"

void decodeGcode(char *line,GCodeMapping *GCode,StoreCMD *cmd)
{
  char *line2;
  while(isEmpty(*line))
  {
    line  += 1;
  }
    if(*line == *(GCode)->name)
    {
      cmd->type = *line;
      line += 1;
    }
    GCode->name += 1;
    line2 = line;
    // variables = line;
    // return variables;
    line2 = getGcodeCommand(line,GCode,cmd);
    getVariables(line2,GCode);
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
    throwException(ERROR_CODE,"Error!,spotted more than 1 alphabet in a command\n");
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
  }
  cmd->code = atoi(storecode);
  if(cmd->code >= 100)
  {
    throwException(NOCODE,"Error!,no such code\n");
  }
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
  //int i;
  //char *initial = *line;
  //char storenum[20] = {0};
  int j;
  while(isEmpty(*line))
  {
    line += 1;
  }
  for(j=0;j<strlen(line);j++)
  {
  if(isAlpha(*line))
  {
    while(isAlpha((GCode)->varMap->name))
    {
      if(isEmpty(*line))
      {
        line += 1;
      }
      if(*line == (GCode)->varMap->name)
      {
        (GCode)->varMap->var->name = *line;
        line += 1;
        line = getValue(line,GCode);
        (GCode)->varMap->var->isValid = 1;
        // while(isNumbers(*line))
        // {
        //   storenum[i] = *line;
        //   i++;
        //   line += 1;
        // }
        // value = atoi(storenum);
        // (GCode)->varMap->var->integer = value;
        // i=0;
      }
      else{
      GCode->varMap->name += 1;
      GCode->varMap->var += 1;
      }
    }
  }
  else{
    throwException(NOT_ALPHA,"Error!,expect it to be an alphabet but was %c\n",*line);
  }
  // GCode->varMap->name = 0;
  // GCode->varMap->var = 0;
}
}

char *getValue(char *line,GCodeMapping *GCode)
{
  int i=0;
  char storenum[20] = {0};
  int value;
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