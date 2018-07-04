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
    printf("Name : %c\n",v.name);
    printf("Integer : %d\n",v.integer);
}

void test_X_12345_expect_char_X_int_12345_in_v(void)
{
    Variable v;
    char *line = "X 12345";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL('X',v.name);
    TEST_ASSERT_EQUAL(12345,v.integer);
    printf("Name : %c\n",v.name);
    printf("Integer : %d\n",v.integer);
}


void test_X12345Y3455_expect_char_Y_int_3455(void)
{
    Variable v;
    char *line = "X12345Y3455";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL('Y',v.name);
    TEST_ASSERT_EQUAL(3455,v.integer);
    printf("Name : %c\n",v.name);
    printf("Integer : %d\n",v.integer);
}

void test_X12345_Y3455_expect_char_Y_int_3455(void)
{
    Variable v;
    char *line = "X12345 Y3455";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL('Y',v.name);
    TEST_ASSERT_EQUAL(3455,v.integer);
    printf("Name : %c\n",v.name);
    printf("Integer : %d\n",v.integer);
}

void test_X_12345_Y_3455_expect_char_Y_int_3455(void)
{
    Variable v;
    char *line = "X 12345 Y 3455";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL('Y',v.name);
    TEST_ASSERT_EQUAL(3455,v.integer);
    printf("Name : %c\n",v.name);
    printf("Integer : %d\n",v.integer);
}

// void test_X12345_Y3455_Z4455_expect_char_Z_int_4455(void)
// {
//     Variable v;
//     char *line = "X12345 Y3455 Z4455";
//     v = fillsInVariableTable(line);
//     TEST_ASSERT_EQUAL('Z',v.name);
//     TEST_ASSERT_EQUAL(4455,v.integer);
//     printf("Name : %c\n",v.name);
//     printf("Integer : %d\n",v.integer);
// }

void test_X_12345_Y_3455_Z_4455_expect_char_Z_int_4455(void)
{
    Variable v;
    char *line = "X 12345 Y 3455 Z 4455";
    v = fillsInVariableTable(line);
    TEST_ASSERT_EQUAL('Z',v.name);
    TEST_ASSERT_EQUAL(4455,v.integer);
    printf("Name : %c\n",v.name);
    printf("Integer : %d\n",v.integer);
}

// void test_X_12345_Y_3_point_455_expect_fraction_455(void)
// {
//     Variable v;
//     char *line = "X12345 Y3.455";
//     v = fillsInVariableTable(line);
//     TEST_ASSERT_EQUAL('Y',v.name);
//     TEST_ASSERT_EQUAL(3,v.integer);
//     TEST_ASSERT_EQUAL(455,v.fraction);
//     printf("Name : %c\n",v.name);
//     printf("Integer : %d\n",v.integer);
//     printf("Fraction : %d\n",v.fraction);
// }
//
// void test_X_1_point_2345_Y_3455_expect_fraction_0(void)
// {
//     Variable v;
//     char *line = "X1.2345 Y3455";
//     v = fillsInVariableTable(line);
//     TEST_ASSERT_EQUAL('Y',v.name);
//     TEST_ASSERT_EQUAL(3455,v.integer);
//     TEST_ASSERT_EQUAL(0,v.fraction);
//     printf("Name : %c\n",v.name);
//     printf("Integer : %d\n",v.integer);
//     printf("Fraction : %d\n",v.fraction);
// }
//
// void test_X_1_Y_3455_Z_9_point_999999999_expect_fraction_999999999(void)
// {
//     Variable v;
//     char *line = "X12345 Y3455 Z9.999999999";
//     v = fillsInVariableTable(line);
//     TEST_ASSERT_EQUAL('Z',v.name);
//     TEST_ASSERT_EQUAL(9,v.integer);
//     TEST_ASSERT_EQUAL(999999999,v.fraction);
//     printf("Name : %c\n",v.name);
//     printf("Integer : %d\n",v.integer);
//     printf("Fraction : %d\n",v.fraction);
// }
