#include "unity.h"
#include "CommandCode.h"
#include "string.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

void test_G00_expect_G0_cmd_X_var_100_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G00 X100";

  Try{
    cmd = decodeGcode(line,GCode00);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(100,xVar.value);

  }Catch(ex){
    dumpException(ex);
  }
}

void test_space_G00_expect_G0_cmd_X_var_100_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = " G00 X100";

  Try{
    cmd = decodeGcode(line,GCode00);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(100,xVar.value);

  }Catch(ex){
    dumpException(ex);
  }
}

void test_E00_expect_throw_exception_error_command(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL},
  };
  char *line = "E00 X100";

  Try{
    cmd = decodeGcode(line,GCode00);

  }Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(ERROR_COMMAND,ex->errorCode);
  }
  freeException(ex);
}

void test_G90_expect_G90_cmd(void)
{
  CEXCEPTION_T ex;
  StoreCMD SetUpcmd = {0,0};

  GCodeMapping GCode90[] = {
    {"G",90,NULL,handleG90orG91},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G90 ";

  Try{
    SetUpcmd = decodeGcode(line,GCode90);
    TEST_ASSERT_EQUAL('G',SetUpcmd.type);
    TEST_ASSERT_EQUAL(90,SetUpcmd.code);
  }Catch(ex){
    dumpException(ex);
  }
}

void test_G_space_00_expect_G0_cmd_X_var_100_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G 00 X100";

  Try{
    cmd = decodeGcode(line,GCode00);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(100,xVar.value);
    TEST_ASSERT_EQUAL(800,xVar.steps);

  }Catch(ex){
    dumpException(ex);
  }
}

void test_GE00_expect_throw_exception_error_code(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "GE00 X100";

  Try{
    cmd = decodeGcode(line,GCode00);

  }Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(ERROR_CODE,ex->errorCode);
  }
    freeException(ex);
}

void test_G001_expect_G1_cmd_X_var_100_val(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",1,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G001 X100";

  Try{
    cmd = decodeGcode(line,GCode00);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(1,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(100,xVar.value);
    TEST_ASSERT_EQUAL(800,xVar.steps);

  }Catch(ex){
    dumpException(ex);
  }
}

void test_G00_XY100_expect_throw_exception_error_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G00 XY100";

  Try{
    cmd = decodeGcode(line,GCode00);

  }Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(ERROR_VALUE,ex->errorCode);
  }
  freeException(ex);
}

void test_G00_expect_G0_cmd_X_var_101_value_Y_var_999_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G00 X101 Y999";
  Try{
    cmd = decodeGcode(line,GCode00);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(101,xVar.value);
    TEST_ASSERT_EQUAL('Y',yVar.name);
    TEST_ASSERT_EQUAL(999,yVar.value);
    TEST_ASSERT_EQUAL(808,xVar.steps);
    TEST_ASSERT_EQUAL(7992,yVar.steps);

  }Catch(ex){
    dumpException(ex);
  }
}

void test_G00_X101_YZ999_expect_throw_exception_error_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G00 X101 YZ999";
  Try{
    cmd = decodeGcode(line,GCode00);

  }Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(ERROR_VALUE,ex->errorCode);
  }
  freeException(ex);
}

void test_G00_X101_YZ999_expect_throw_exception_error_duplicate_variable(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G00 X101 X999";
  Try{
    cmd = decodeGcode(line,GCode00);

  }Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(ERROR_DUPLICATE_VARIABLE,ex->errorCode);
  }
  freeException(ex);
}

void test_G00_expect_G0_cmd_X_var_999_value_Y_var_101_value_Z_var_20_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G00 Y101 X999 Z20";
  Try{
    cmd = decodeGcode(line,GCode00);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(999,xVar.value);
    TEST_ASSERT_EQUAL('Y',yVar.name);
    TEST_ASSERT_EQUAL(101,yVar.value);
    TEST_ASSERT_EQUAL('Z',zVar.name);
    TEST_ASSERT_EQUAL(20,zVar.value);

  }Catch(ex){
    dumpException(ex);
  }
}

void test_G00_expect_G0_cmd_Y_var_101_value_X_var_999_value_Z_var_21_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G00Y101X999Z21";
  Try{
    cmd = decodeGcode(line,GCode00);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(999,xVar.value);
    TEST_ASSERT_EQUAL('Y',yVar.name);
    TEST_ASSERT_EQUAL(101,yVar.value);
    TEST_ASSERT_EQUAL('Z',zVar.name);
    TEST_ASSERT_EQUAL(21,zVar.value);

  }Catch(ex){
    dumpException(ex);
  }
}

void test_G00_expect_Y_var_101_throw_exception_error_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G00Y101XU999Z21";
  Try{
    cmd = decodeGcode(line,GCode00);
  }Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(ERROR_VALUE,ex->errorCode);
    TEST_ASSERT_EQUAL('Y',yVar.name);
    TEST_ASSERT_EQUAL(101,yVar.value);
  }
  freeException(ex);
}

void test_G00_expect_throw_exception_variable_does_not_exist(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G00C101X999Z21";
  Try{
    cmd = decodeGcode(line,GCode00);
  }Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(VARIABLE_DOES_NOT_EXIST,ex->errorCode);
  }
  freeException(ex);
}

void test_G00_expect_G0_cmd_X_var_99_point_99_value_Y_var_101_value_Z_var_20_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *line = "G00 Y101 X99.99 Z20";
  Try{
    cmd = decodeGcode(line,GCode00);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(99.99,xVar.value);
    TEST_ASSERT_EQUAL('Y',yVar.name);
    TEST_ASSERT_EQUAL(101,yVar.value);
    TEST_ASSERT_EQUAL('Z',zVar.name);
    TEST_ASSERT_EQUAL(20,zVar.value);
    TEST_ASSERT_EQUAL(799,xVar.steps);
    TEST_ASSERT_EQUAL(808,yVar.steps);
    TEST_ASSERT_EQUAL(160,zVar.steps);
  }Catch(ex){
    dumpException(ex);
  }
}

void test_G00_Y101_X99_point_99_point_5_expect_throw_exception_error_value(void)
{
  CEXCEPTION_T ex;
  StoreCMD cmd = {0,0};
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
    {"G",0,g00VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
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

void test_G20_G00_Y101_X99_point_99_point_5_expect_value_from_MM_to_Steps(void)
{
  CEXCEPTION_T ex;
  int *Steps;
  StoreCMD cmd = {0,0};
  Variable xVar = {0,0,0,0};
  Variable yVar = {0,0,0,0};
  Variable zVar = {0,0,0,0};
  VariableMap g00VarTableMapping[] = {
    {'X',&xVar},
    {'Y',&yVar},
    {'Z',&zVar},
    {NULL,NULL},
  };
  GCodeMapping GCode[] = {
    {"G",0,g00VarTableMapping,handleG00},
    {"G",20,NULL,handleG20or21},
    {NULL,NULL,NULL,NULL},
  };
  char *SetUp = "G20";
  char *line = "G00 Y101 X99.99 Z20";
  Try{
    cmd = decodeGcode(SetUp,GCode);
    cmd = decodeGcode(line,GCode);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(99.99,xVar.value);
    TEST_ASSERT_EQUAL('Y',yVar.name);
    TEST_ASSERT_EQUAL(101,yVar.value);
    TEST_ASSERT_EQUAL('Z',zVar.name);
    TEST_ASSERT_EQUAL(20,zVar.value);
    TEST_ASSERT_EQUAL(799,xVar.steps);
    TEST_ASSERT_EQUAL(808,yVar.steps);
    TEST_ASSERT_EQUAL(160,zVar.steps);
  }Catch(ex){
    dumpException(ex);
  }
}

void test_G21_G00_Y101_X99_point_99_point_5_expect_value_from_INCH_to_Steps(void)
{
  CEXCEPTION_T ex;
  int *Steps;
  StoreCMD cmd = {0,0};
  Variable xVar = {0,0,0,0};
  Variable yVar = {0,0,0,0};
  Variable zVar = {0,0,0,0};
  VariableMap g00VarTableMapping[] = {
    {'X',&xVar},
    {'Y',&yVar},
    {'Z',&zVar},
    {NULL,NULL},
  };
  GCodeMapping GCode[] = {
    {"G",0,g00VarTableMapping,handleG00},
    {"G",21,NULL,handleG20or21},
    {NULL,NULL,NULL,NULL},
  };
  char *SetUp = "G21";
  char *line = "G00 Y101 X99.99 Z20";
  Try{
    cmd = decodeGcode(SetUp,GCode);
    cmd = decodeGcode(line,GCode);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(99.99,xVar.value);
    TEST_ASSERT_EQUAL('Y',yVar.name);
    TEST_ASSERT_EQUAL(101,yVar.value);
    TEST_ASSERT_EQUAL('Z',zVar.name);
    TEST_ASSERT_EQUAL(20,zVar.value);
    TEST_ASSERT_EQUAL(31,xVar.steps);
    TEST_ASSERT_EQUAL(31,yVar.steps);
    TEST_ASSERT_EQUAL(6,zVar.steps);
  }Catch(ex){
    dumpException(ex);
  }
}

void test_G21_G00_G91_G01_cmd_expect_absolute_steps(void)
{
  CEXCEPTION_T ex;
  int *Steps;
  StoreCMD cmd = {0,0};
  StoreCMD cmd1 = {0,0};
  Variable xVar = {0,0,0,0};
  Variable yVar = {0,0,0,0};
  Variable zVar = {0,0,0,0};
  Variable x1Var = {0,0,0,0};
  Variable y1Var = {0,0,0,0};
  Variable z1Var = {0,0,0,0};
  VariableMap g00VarTableMapping[] = {
    {'X',&xVar},
    {'Y',&yVar},
    {'Z',&zVar},
    {NULL,NULL},
  };
  VariableMap g01VarTableMapping[] = {
    {'X',&x1Var},
    {'Y',&y1Var},
    {'Z',&z1Var},
    {NULL,NULL},
  };
  GCodeMapping GCode[] = {
    {"G",0,g00VarTableMapping,handleG00},
    {"G",21,NULL,handleG20or21},
    {"G",91,NULL,handleG90orG91},
    {"G",1,g01VarTableMapping,handleG00},
    {NULL,NULL,NULL,NULL},
  };
  char *SetUp = "G21";
  char *line = "G00 Y101 X99.99 Z20";
  char *SetUp2 = "G91";
  char *line2 = "G01 Z10 Y20 X15";
  Try{
    cmd = decodeGcode(SetUp,GCode);
    cmd = decodeGcode(line,GCode);
    TEST_ASSERT_EQUAL('G',cmd.type);
    TEST_ASSERT_EQUAL(0,cmd.code);
    TEST_ASSERT_EQUAL('X',xVar.name);
    TEST_ASSERT_EQUAL(99.99,xVar.value);
    TEST_ASSERT_EQUAL('Y',yVar.name);
    TEST_ASSERT_EQUAL(101,yVar.value);
    TEST_ASSERT_EQUAL('Z',zVar.name);
    TEST_ASSERT_EQUAL(20,zVar.value);
    TEST_ASSERT_EQUAL(31,xVar.steps);
    TEST_ASSERT_EQUAL(31,yVar.steps);
    TEST_ASSERT_EQUAL(6,zVar.steps);
    cmd1 = decodeGcode(SetUp2,GCode);
    cmd1 = decodeGcode(line2,GCode);
    TEST_ASSERT_EQUAL('G',cmd1.type);
    TEST_ASSERT_EQUAL(1,cmd1.code);
    TEST_ASSERT_EQUAL('X',x1Var.name);
    TEST_ASSERT_EQUAL(15,x1Var.value);
    TEST_ASSERT_EQUAL('Y',y1Var.name);
    TEST_ASSERT_EQUAL(20,y1Var.value);
    TEST_ASSERT_EQUAL('Z',z1Var.name);
    TEST_ASSERT_EQUAL(10,z1Var.value);
    TEST_ASSERT_EQUAL(120,x1Var.steps);
    TEST_ASSERT_EQUAL(160,y1Var.steps);
    TEST_ASSERT_EQUAL(80,z1Var.steps);
  }Catch(ex){
    dumpException(ex);
  }
}

// void test_G21_G00_Y101_X99_point_99_point_5_expect_value_from_INCH_to_Steps(void)
// {
//   CEXCEPTION_T ex;
//   int *Steps;
//   StoreCMD cmd = {0,0};
//   StoreCMD SetUpCmd = {0,0};
//   Variable xVar = {0,0,0,0};
//   Variable yVar = {0,0,0,0};
//   Variable zVar = {0,0,0,0};
//   VariableMap g00VarTableMapping[] = {
//     {'X',&xVar},
//     {'Y',&yVar},
//     {'Z',&zVar},
//     {NULL,NULL},
//   };
//   GCodeMapping GCode[] = {
//     {"G",0,g00VarTableMapping},
//     //{.type "G",.code 21,.varMap NULL},
//     {NULL,NULL,NULL},
//   };
//   //char *SetUp = "G21";
//   char *line = "G00 Y101 X99.99 Z20";
//   Try{
//     //SetUpCmd = decodeGcode(SetUp,GCode);
//     cmd = decodeGcode(line,GCode);
//     // TEST_ASSERT_EQUAL('G',SetUpCmd.type);
//     // TEST_ASSERT_EQUAL(21,SetUpCmd.code);
//     TEST_ASSERT_EQUAL('G',cmd.type);
//     TEST_ASSERT_EQUAL(0,cmd.code);
//     TEST_ASSERT_EQUAL('X',xVar.name);
//     TEST_ASSERT_EQUAL(99.99,xVar.value);
//     TEST_ASSERT_EQUAL('Y',yVar.name);
//     TEST_ASSERT_EQUAL(101,yVar.value);
//     TEST_ASSERT_EQUAL('Z',zVar.name);
//     TEST_ASSERT_EQUAL(20,zVar.value);
//     // Steps = CheckUnitSetUpCmd(&SetUpCmd,g00VarTableMapping);
//     // TEST_ASSERT_EQUAL(31,*(Steps));
//     // TEST_ASSERT_EQUAL(31,*(Steps+1));
//     // TEST_ASSERT_EQUAL(6,*(Steps+2));
//   }Catch(ex){
//     dumpException(ex);
//   }
// }
