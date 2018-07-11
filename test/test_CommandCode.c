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

// void test_G00_expect_G0_cmd_X_var_100_value(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = "G00 X100";
//
//   Try{
//     cmd = decodeGcode(line,GCode00);
//     TEST_ASSERT_EQUAL('G',cmd.type);
//     TEST_ASSERT_EQUAL(0,cmd.code);
//     TEST_ASSERT_EQUAL('X',xVar.name);
//     TEST_ASSERT_EQUAL(100,xVar.integer);
//
//   }Catch(ex){
//     dumpException(ex);
//   }
// }
//
// void test_space_G00_expect_G0_cmd_X_var_100_value(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = " G00 X100";
//
//   Try{
//     cmd = decodeGcode(line,GCode00);
//     TEST_ASSERT_EQUAL('G',cmd.type);
//     TEST_ASSERT_EQUAL(0,cmd.code);
//     TEST_ASSERT_EQUAL('X',xVar.name);
//     TEST_ASSERT_EQUAL(100,xVar.integer);
//
//   }Catch(ex){
//     dumpException(ex);
//   }
// }
//
// void test_E00_expect_throw_exception_error_command(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = "E00 X100";
//
//   Try{
//     cmd = decodeGcode(line,GCode00);
//
//   }Catch(ex){
//     dumpException(ex);
//     TEST_ASSERT_EQUAL(ERROR_COMMAND,ex->errorCode);
//   }
//   freeException(ex);
// }
//
// void test_G_space_00_expect_G0_cmd_X_var_100_value(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = "G 00 X100";
//
//   Try{
//     cmd = decodeGcode(line,GCode00);
//     TEST_ASSERT_EQUAL('G',cmd.type);
//     TEST_ASSERT_EQUAL(0,cmd.code);
//     TEST_ASSERT_EQUAL('X',xVar.name);
//     TEST_ASSERT_EQUAL(100,xVar.integer);
//
//   }Catch(ex){
//     dumpException(ex);
//   }
// }
//
// void test_GE00_expect_throw_exception_error_code(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = "GE00 X100";
//
//   Try{
//     cmd = decodeGcode(line,GCode00);
//
//   }Catch(ex){
//     dumpException(ex);
//     TEST_ASSERT_EQUAL(ERROR_CODE,ex->errorCode);
//   }
//     freeException(ex);
// }
//
// void test_G001_expect_throw_exception_error_variable(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = "G001 X100";
//
//   Try{
//     cmd = decodeGcode(line,GCode00);
//
//   }Catch(ex){
//     dumpException(ex);
//     TEST_ASSERT_EQUAL(ERROR_VARIABLE,ex->errorCode);
//   }
//   freeException(ex);
// }
//
// void test_G00_XY100_expect_throw_exception_error_value(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = "G00 XY100";
//
//   Try{
//     cmd = decodeGcode(line,GCode00);
//
//   }Catch(ex){
//     dumpException(ex);
//     TEST_ASSERT_EQUAL(ERROR_VALUE,ex->errorCode);
//   }
//   freeException(ex);
// }
//
// void test_G00_expect_G0_cmd_X_var_101_value_Y_var_999_value(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = "G00 X101 Y999";
//   Try{
//     cmd = decodeGcode(line,GCode00);
//     TEST_ASSERT_EQUAL('G',cmd.type);
//     TEST_ASSERT_EQUAL(0,cmd.code);
//     TEST_ASSERT_EQUAL('X',xVar.name);
//     TEST_ASSERT_EQUAL(101,xVar.integer);
//     TEST_ASSERT_EQUAL('Y',yVar.name);
//     TEST_ASSERT_EQUAL(999,yVar.integer);
//
//   }Catch(ex){
//     dumpException(ex);
//   }
// }
//
// void test_G00_X101_YZ999_expect_throw_exception_error_value(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = "G00 X101 YZ999";
//   Try{
//     cmd = decodeGcode(line,GCode00);
//
//   }Catch(ex){
//     dumpException(ex);
//     TEST_ASSERT_EQUAL(ERROR_VALUE,ex->errorCode);
//   }
//   freeException(ex);
// }
//
// void test_G00_X101_YZ999_expect_throw_exception_error_duplicate_variable(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = "G00 X101 X999";
//   Try{
//     cmd = decodeGcode(line,GCode00);
//
//   }Catch(ex){
//     dumpException(ex);
//     TEST_ASSERT_EQUAL(ERROR_DUPLICATE_VARIABLE,ex->errorCode);
//   }
//   freeException(ex);
// }
//
// void test_G00_expect_G0_cmd_X_var_999_value_Y_var_101_value_Z_var_20_value(void)
// {
//   CEXCEPTION_T ex;
//   StoreCMD cmd = {0,0};
//   char *remaining;
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode00[] = {
//     {"G00",g00VarTableMapping},
//     {NULL,NULL},
//   };
//   char *line = "G00 Y101 X999 Z20";
//   Try{
//     cmd = decodeGcode(line,GCode00);
//     TEST_ASSERT_EQUAL('G',cmd.type);
//     TEST_ASSERT_EQUAL(0,cmd.code);
//     TEST_ASSERT_EQUAL('X',xVar.name);
//     TEST_ASSERT_EQUAL(999,xVar.integer);
//     TEST_ASSERT_EQUAL('Y',yVar.name);
//     TEST_ASSERT_EQUAL(101,yVar.integer);
//     TEST_ASSERT_EQUAL('Z',zVar.name);
//     TEST_ASSERT_EQUAL(20,zVar.integer);
//
//   }Catch(ex){
//     dumpException(ex);
//   }
// }

void test_G00_expect_G0_cmd_X_var_99_point_99_value_Y_var_101_value_Z_var_20_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
  char *line = "G00 Y101 X99.99 Z20";
  Try{
    cmd = decodeGcode(line,GCode00);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(99.99,xVar.integer);
    TEST_ASSERT_EQUAL('Y',yVar.name);
    TEST_ASSERT_EQUAL(101,yVar.integer);
    TEST_ASSERT_EQUAL('Z',zVar.name);
    TEST_ASSERT_EQUAL(20,zVar.integer);

  }Catch(ex){
    dumpException(ex);
  }
}

void test_G00_Y101_X99_point_99_point_5_expect_throw_exception_error_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
  char *line = "G00 Y101 X99.99.5 Z20";
  Try{
    cmd = decodeGcode(line,GCode00);

  }Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(ERROR_VALUE,ex->errorCode);
  }
  freeException(ex);
}
