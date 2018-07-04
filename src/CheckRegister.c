#include "CheckRegister.h"
#include "CException.h"
#include "Exception.h"


Variable fillsInVariableTable(char *line)
{
  int i;
  int value,decimal;
  int index;
  char word;
  Variable v;
  CheckIndex CheckIndex;

  for(i=0;i<strlen(line);i++)
  {
    word = getChar(&line,&CheckIndex);
    line += CheckIndex.index;
    value = getValue(&line,&CheckIndex);
    // line += CheckIndex.index;
    if(*line == '.')
    {
    decimal = getDeci(&line,&CheckIndex);
    v.fraction = decimal;
    }
    else{
      v.fraction = 0;
    }
    v.name = word;
    v.integer = value;
    printf("word : %c\n",v.name);
    printf("integer : %d\n",v.integer);
    // printf("%c\n",word);
    // printf("%d\n",value);
  }
  return v;

}
// int inc(int *i){
//   (*i)++;
// }
//
// void int main(int argc, char const *argv[]) {
//   x = 1;
//   inc(&x)
//   return 0;
// }
char getChar(char **linePtrPtr,CheckIndex *checkindex)
{
  int i=0;
  //word = *linePtrPtr;
  char word;
  if(isEmpty(**linePtrPtr))
  {
    *linePtrPtr += 1;
  }
  while(isAlpha(**linePtrPtr))
  {
        checkindex->index = 1;
        word = **linePtrPtr;
        return word;
  }
  Throw(createException("No identifier found ",INVALID_IDENTIFIER));
  //   while(!isEmpty(**linePtrPtr))
  //   {
  //   if(isAlpha(**linePtrPtr))
  //   {
  //     checkindex->index = i+1;
  //     word = **linePtrPtr;
  //     return word;
  //   }
  //   else{
  //     Throw(createException("No identifier found ",NO_IDENTIFIER));
  //   }
  //   *linePtrPtr += 1;
  // }

}

int getValue(char **linePtrPtr,CheckIndex *checkindex)
{
  Variable v;
  checkindex->index =0;
  int i=0,j=0;
  int value,decimal;
  char storenum[20]={0};
  float check;
  if(isAlpha(**linePtrPtr))
  {
     Throw(createException("INVALID_INTEGER ",INVALID_INTEGER));
  }
  if(isEmpty(**linePtrPtr))
  {
    *linePtrPtr += 1;
    checkindex->index += 1;
  }
  while(isNumbers(**linePtrPtr))
  {
    storenum[j] = **linePtrPtr;
    j++;
    *linePtrPtr += 1;
    checkindex->index +=1;
  }
  value = atoi(storenum);
  return value;

  // while(!isEmpty(**linePtrPtr)&&!isAlpha(**linePtrPtr))
  // {
  //   if(isNumbers(**linePtrPtr))
  //   {
  //     storenum[j] = **linePtrPtr;
  //     // printf("number %d\n",storenum[j]);
  //     j++;
  //     // i++;
  //     // *linePtrPtr+=i;
  //     // check = strtof(*linePtrPtr,&storenum);
  //   }
  //   else
  //   {
  //     Throw(createException("No integer ",NO_INTEGER));
  //   }
  //   *linePtrPtr += 1;
  // }

}

int getDeci(char **linePtrPtr,CheckIndex *checkindex)
{
  int j=0;
  int decimal;
  char storedeci[20]={0};
  if(isDecimal(**linePtrPtr))
  {
    *linePtrPtr += 1;
    checkindex->index +=1;
    while(isNumbers(**linePtrPtr))
    {
      storedeci[j] = **linePtrPtr;
      j++;
      *linePtrPtr += 1;
      checkindex->index +=1;
    }
    decimal = atoi(storedeci);
    return decimal;
  }
}
