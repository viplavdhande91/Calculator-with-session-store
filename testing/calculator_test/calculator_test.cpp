#include <gtest/gtest.h>
#include "../../Calculator.cpp"
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

// TEST(test_calculations, with_zeros)
// {
//     int arr[] = {-1, -5, -4, 0, 7, 9, 0, -10, -2, -3};
//     size_t n = sizeof(arr) / sizeof(arr[0]);
//     float mean = calculate_mean(arr, n);
//     EXPECT_FLOAT_EQ(mean, -0.89999998);
// }