
#include <iostream>

#ifndef CALCULATOR_H
#define CALCULATOR_H
using std::cout;
using std::endl;
#include <climits>
#include "MyException.h"
using std::runtime_error;

class Calculator
{

public:
    Calculator()
    {
    }

    template <class T1 = double, class T2>
    static void numberRangeCheck(T1 x, T2 y)
    {
        if ((x < INT_MIN) || (x > INT_MAX) || (y < INT_MIN) || (y > INT_MAX))
        {
            MyException e;
            throw e;
        }
    }

public:
    // ADDITION
    template <class T1 = double, class T2>
    auto add(T1 i, T2 j) -> decltype(i + j)
    {
        auto res = 0;
        try
        {
            numberRangeCheck(i, j);
        }
        catch (exception &e)
        {
            cout << e.what();
        }

        return i + j;
    }

    // SUBTRACTION
    template <class T1 = double, class T2>
    auto subtract(T1 i, T2 j) -> decltype(i - j)

    {
        auto res = 0;
        try
        {
            numberRangeCheck(i, j);
        }
        catch (exception &e)
        {
            cout << e.what();
        }

        return i - j;
    }

    // MULTIPLICATION
    template <class T1 = double, class T2>
    auto multiply(T1 i, T2 j) -> decltype(i * j)

    {
        auto res = 0;
        try
        {
            numberRangeCheck(i, j);
        }
        catch (exception &e)
        {
            cout << e.what();
        }

        return i * j;
    }

    // DIVISION
    template <class T1 = double, class T2>
    auto divide(T1 i, T2 j) -> decltype(i / j)

    {
        try
        {
            numberRangeCheck(i, j);

            if (j == 0)
            {
                throw runtime_error("Math error: Attempted to divide by Zero\n");
            }
        }
        catch (runtime_error &e) // DIVIDE BY ZERO EXCEPTION
        {

            cout << "Exception occurred" << endl
                 << e.what();
        }
        catch (exception &e) // NUMBER IS OUT OF RANGE EXCEPTION
        {
            cout << e.what();
        }

        return i / j;
    }
};

#endif
