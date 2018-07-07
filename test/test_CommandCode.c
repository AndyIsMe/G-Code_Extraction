#include "unity.h"
#include "CommandCode.h"
#include "string.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

void test_CommandCode(void)
{
  int val;
    char cmd[] = "G 00 X123 ";
    val = decodeGcode(cmd);
    TEST_ASSERT_EQUAL(1,val);
    printf("%s\n",cmd);
}

void test_CommandCode_expect_exception(void)
{
    CEXCEPTION_T ex;
    int val;
    char cmd[] = "G 100 X123 ";
  Try{
    val = decodeGcode(cmd);
  }Catch(ex){
    dumpException(ex);
  }
  freeException(ex);
}

void test_Gcode00(void)
{
  StoreCMD cmd;
  VariableMap g00VarTableMapping[] = {
    {'X',&xVar},
    {'Y',&xVar},
    {'Z',&xVar}
  };
  GCodeMapping GCode00[] = {
    {"G00",g00VarTableMapping}
  };
  char line[] = "G00 X100";
  line = decodeGcode(line,GCode00,&cmd);


}
