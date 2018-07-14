#include "unity.h"
#include "User.h"

void setUp(void){}
void tearDown(void){}

void test_Convert_MM_To_Steps(void)
{
  float mm = 200;
  int value = convertBaseUnitToSteps(mm,0);
  TEST_ASSERT_EQUAL(1600,value);
}
