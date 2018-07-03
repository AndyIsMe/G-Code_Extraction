#include "CheckRegister.h"
#include "CException.h"


void fillsInVariableTable(char *line)
{
  int i,value;
  int type;
  char word;
  Variable v;

    type = getChar(&line);
    word = *line+type;
    value = getValue(&line,type+1);
    printf("%c\n",word);
    printf("%d\n",value);
    //printf("%s\n",*line);
    // type = getChar(&line,v);
    // word = *line+type;
    // printf("%c\n",*line+0);
    //value = getValue(&line);
    // word =
    // if(isDigit(linePtrPtr+i))
    // {
    //   getValue = linePtrPtr+i;
    // }
  //printf("%c\n",linePtrPtr+1);
  //return linePtrPtr;
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
int getChar(char **linePtrPtr)
{
  int i=0;
  char word;
  word = *linePtrPtr;
    while(isNULL(*linePtrPtr))
    {
      i++;
      linePtrPtr += i;
    }
    if(isCharacter(word=*linePtrPtr))
    {
      //word = **linePtrPtr+i;
      return i;
    }
  Throw(createException("No identifier found ",NO_IDENTIFIER));

}

int getValue(char **linePtrPtr,int index)
{
  int i=0,j=0;
  int value;
  char word;
  char storenum[20];
  while(!isNULL(*linePtrPtr+index)&&!isCharacter(word=*linePtrPtr+index))
  {
    if(isNumbers(word=*linePtrPtr+index+i))
    {
      storenum[j] = *linePtrPtr+i+index;
      printf("number %d\n",storenum[j]);
      j++;
      i++;
      linePtrPtr+=i;
    }
    else
    {
      Throw(createException("No integer ",NO_INTEGER));
    }

  }
        value = atoi(storenum);
        printf("store num :%d\n",value );
        return value;
//   int i,value;
//   for()
}
