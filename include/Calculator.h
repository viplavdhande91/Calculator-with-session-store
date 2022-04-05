
#include <iostream>

#ifndef CALCULATOR_H
#define CALCULATOR_H
using std::cout;
using std::endl;
#include <climits> // TODO: replace C lang limits with C++'s <limits>
#include "MyException.h"
using std::runtime_error;

// TODO: Stop using "using"
// TODO: Header guard needs to be the first thing a header file

class Calculator
{

public:
    Calculator() // TODO: use compiler generated default constructor
    {
    }

    // TODO: there is no reason for this to be a static class method. Make it a free function
    // TODO: we use 'typename' instead of 'class' in templates. Class is the legacy way.
    // Q: why "T1 = double"
    // Q: shouldn't T1 and T2 be the same type?
    template <class T1 = double, class T2>
    static void numberRangeCheck(T1 x, T2 y)
    {
        if ((x < INT_MIN) || (x > INT_MAX) || (y < INT_MIN) || (y > INT_MAX))
        {
            MyException e;
            throw e;
        }
    }

public: // TODO: redundant public label
    // ADDITION
    template <class T1 = double, class T2>
    auto add(T1 i, T2 j) -> decltype(i + j)  // TODO: no need for decltype we can use auto. Also as mentioned above maybe T1 == T2.
    {
        auto res = 0;
        try
        {
            numberRangeCheck(i, j);
        }
        catch (exception &e)
        {
            cout << e.what();  // TODO: logic error i + j return still happens even if they are out of range. Ditto for others.
        }

        return i + j; // TODO: logic error sum of i+j can be out of range of your range check. Ditto for others too.
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
        } // TODO: throwing and catching here serves no purpose
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
