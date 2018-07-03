#include "unity.h"
#include "CheckRegister.h"
#include "Exception.h"
#include "CExceptionConfig.h"

void setUp(void){}

void tearDown(void){}

void test_CheckRegister_(void)
{
    char *line = "X12345";
    fillsInVariableTable(line);
}
