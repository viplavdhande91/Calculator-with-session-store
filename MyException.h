#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
using namespace std;

// CUSTOM EXCEPTION CLASS
class MyException : public exception
{
public:
    const char* what() const throw()
    {
        return "Exception Occured: Number is out of range\n";
    }
};

#endif // MYEXCEPTION_H
