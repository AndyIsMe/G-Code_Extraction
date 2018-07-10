#include "unity.h"
#include "CommandCode.h"
#include "string.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

// void test_CommandCode(void)
// {
//   int val;
//     char cmd[] = "G 00 X123 ";
//     val = decodeGcode(cmd);
//     TEST_ASSERT_EQUAL(1,val);
//     printf("%s\n",cmd);
// }
//
// void test_CommandCode_expect_exception(void)
// {
//     CEXCEPTION_T ex;
//     int val;
//     char cmd[] = "G 100 X123 ";
//   Try{
//     val = decodeGcode(cmd);
//   }Catch(ex){
//     dumpException(ex);
//   }
//   freeException(ex);
// }

void test_Gcode00(void)
{
  StoreCMD cmd;
  char *remaining;
  Variable xVar = {0,0,0,0};
  Variable yVar = {0,0,0,0};
  Variable zVar = {0,0,0,0};

  VariableMap g00VarTableMapping[] = {
    {'X',&xVar},
    {'Y',&yVar},
    {'Z',&zVar},
    {NULL,NULL},
  };
  GCodeMapping GCode00[] = {
    {"G00",g00VarTableMapping},
    {NULL,NULL},
  };
  char *line = "G00 X100";
  decodeGcode(line,GCode00,&cmd);
  //printf("Remaining string : %s\n",line);
  TEST_ASSERT_EQUAL('G',cmd.type);
  TEST_ASSERT_EQUAL(0,cmd.code);
  TEST_ASSERT_EQUAL('X',xVar.name);
  TEST_ASSERT_EQUAL(100,xVar.integer);


}

void test_Gcode01(void)
{
  StoreCMD cmd;
  char *remaining;
  Variable xVar = {0,0,0,0};
  Variable yVar = {0,0,0,0};
  Variable zVar = {0,0,0,0};

  VariableMap g00VarTableMapping[] = {
    {'X',&xVar},
    {'Y',&yVar},
    {'Z',&zVar},
    {NULL,NULL},
  };
  GCodeMapping GCode01[] = {
    {"G01",g00VarTableMapping},
    {NULL,NULL},
  };
  char *line = "G01 X101 Y999";
  decodeGcode(line,GCode01,&cmd);
  TEST_ASSERT_EQUAL('G',cmd.type);
  TEST_ASSERT_EQUAL(1,cmd.code);
  TEST_ASSERT_EQUAL('Y',yVar.name);
  TEST_ASSERT_EQUAL(999,yVar.integer);



}
