#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

// CUSTOM EXCEPTION CLASS
class MyException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Exception Occurred: Number is out of range\n";
    }
};

#endif // MYEXCEPTION_H
