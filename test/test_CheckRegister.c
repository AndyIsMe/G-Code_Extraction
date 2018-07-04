#include "unity.h"
#include "CheckRegister.h"
#include "Exception.h"
#include "CException.h"
#include "Error.h"

void setUp(void){}

void tearDown(void){}

void test_X12345_expect_char_X_int_12345_in_v(void)
{
    Variable v;
    char *line = "X12345";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL('X',v.name);
    TEST_ASSERT_EQUAL(12345,v.integer);
}

void test_X_12345_expect_char_X_int_12345_in_v(void)
{
    Variable v;
    char *line = "X 12345";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL('X',v.name);
    TEST_ASSERT_EQUAL(12345,v.integer);
}

// void test_XY12345_expect_INVALID_INTEGER(void)
// {
//     CEXCEPTION_T ex;
//     Variable v;
//     char *line = "XY12345";
//     Try {
//     v = fillsInVariableTable(line);
//   }Catch(ex){
//     dumpErrorMessage(ex,1);
//     TEST_ASSERT_EQUAL(INVALID_INTEGER,ex->errorCode);
//   }
//   freeException(ex);
// }

void test_X12345Y3455_expect_char_Y_int_3455(void)
{
    Variable v;
    char *line = "X12345Y3455";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL('Y',v.name);
    TEST_ASSERT_EQUAL(3455,v.integer);
}

void test_X12345_Y3455_expect_char_Y_int_3455(void)
{
    Variable v;
    char *line = "X12345 Y3455";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL('Y',v.name);
    TEST_ASSERT_EQUAL(3455,v.integer);
}

void test_X12345_Y3455_Z4455_expect_char_Z_int_4455(void)
{
    Variable v;
    char *line = "X12345 Y3455 Z4455";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL('Z',v.name);
    TEST_ASSERT_EQUAL(4455,v.integer);
}

void test_X_12345_Y_3_point_455_expect_fraction_455(void)
{
    Variable v;
    char *line = "X12345 Y3.455";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL(455,v.fraction);
}

void test_X_1_point_2345_Y_3455_expect_fraction_0(void)
{
    Variable v;
    char *line = "X1.2345 Y3455";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL(0,v.fraction);
}
