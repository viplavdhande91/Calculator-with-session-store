#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include <limits>
#include "MyException.h"

class Calculator
{

public:
    //HELPER FUNCTION TO CHECK NUMBER RANGES
    template <typename T1 = double, typename T2 = double>
    void numberRangeCheck(T1 x, T2 y)
    {
        if ((x > std::numeric_limits<double>::max()) || (x < std::numeric_limits<double>::lowest()) || (y > std::numeric_limits<double>::max()) || (y < std::numeric_limits<double>::lowest()))
        {
            MyException e;
            throw e;
        }
    }

    //HELPER FUNCTION TO CHECK OVERFLOW OF ARIHMETIC OPERATION
    template <typename T1 = double, typename T2 = double>
    int overflowcheck(T1 x, T2 y)
    {
        
        if (x+y > std::numeric_limits<double>::max() || x*y > std::numeric_limits<double>::max() )
        {
            /* handle overflow */
            MyException e;
            throw e;
        }
        else if ( x+y < std::numeric_limits<double>::lowest() || x*y < std::numeric_limits<double>::lowest())
        {
            /* handle underflow */
            MyException e;
            throw e;
        }

        return 0;
    }

    // ADDITION
    template <typename T1 = double, typename T2 = double>
    auto add(T1 i, T2 j)
    {
        auto res = 0;
        try
        {
            numberRangeCheck(i, j);
            overflowcheck(i, j);
        }
        catch (exception &e)
        {
            std::cout << e.what();
        }

        return i + j;
    }

    // SUBTRACTION
    template <typename T1 = double, typename T2 = double>
    auto subtract(T1 i, T2 j)
    {
        auto res = 0;
        try
        {
            numberRangeCheck(i, j);
            overflowcheck(i, j);
        }
        catch (exception &e)
        {
            std::cout << e.what();
        }

        return i - j;
    }

    // MULTIPLICATION
    template <typename T1 = double, typename T2 = double>
    auto multiply(T1 i, T2 j)

    {
        auto res = 0;
        try
        {
            numberRangeCheck(i, j);
            overflowcheck(i, j);
        }
        catch (exception &e)
        {
            std::cout << e.what();
        }

        return i * j;
    }

    // DIVISION
    template <typename T1 = double, typename T2 = double>
    auto divide(T1 i, T2 j)
    {
        try
        {
            numberRangeCheck(i, j);

            if (j == 0)
            {
                throw std::runtime_error("Math error: Attempted to divide by Zero\n");
            }
        }
        catch (std::runtime_error &e) // DIVIDE BY ZERO EXCEPTION
        {

            std::cout << "Exception occurred" << std::endl
                      << e.what();
        }
        catch (exception &e) // NUMBER IS OUT OF RANGE EXCEPTION
        {
            std::cout << e.what();
        }

        return i / j;
    }
};

#endif
