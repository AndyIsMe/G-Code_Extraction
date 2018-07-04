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

// void test_CheckRegister5_(void)
// {
//     char *line = "X12345 Y3455";
//     fillsInVariableTable(line);
// }

// void test_CheckRegister6_(void)
// {
//     char *line = "X1.2345 Y3455";
//     fillsInVariableTable(line);
// }
