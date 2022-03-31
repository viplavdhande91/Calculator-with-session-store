#include <gtest/gtest.h>
#include "../../../include/Calculator.h"
using std::cout;
using std::endl;
TEST(CalculatorTests, adddition)
{
     Calculator obj;
     EXPECT_EQ(3, obj.add(2, 1));
     EXPECT_EQ(2, obj.add(true, true));

     EXPECT_NE(3, obj.add(0, 1));

     cout << "TEST CASE FINISHED" << endl<< endl<< endl;
}

TEST(CalculatorTests, multiply)
{
     Calculator obj;
     EXPECT_EQ(200, obj.multiply(20, 10));
     EXPECT_NE(3, obj.multiply(0, 13333));
     cout << "TEST CASE FINISHED" << endl
          << endl<< endl;
}

TEST(test_calculations, division)
{
     Calculator obj;
     EXPECT_EQ(10, obj.divide(20, 10));
     EXPECT_NE(3, obj.divide(0, 13333));
     cout << "TEST CASE FINISHED" << endl
          << endl<< endl;
}
TEST(test_calculations, substraction)
{
     Calculator obj;
     EXPECT_EQ(10, obj.subtract(20, 10));
     EXPECT_NE(3, obj.subtract(0, 13333));
     cout << "TEST CASE FINISHED" << endl
          << endl<< endl;
}
