#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

using std::exception;

// CUSTOM EXCEPTION CLASS
class MyException : public exception
{
public:
    const char *what() const throw()
    {
        return "Exception Occured\n";
    }
};

#endif
