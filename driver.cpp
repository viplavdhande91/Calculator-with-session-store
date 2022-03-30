#include <iostream>
using namespace std;
#include "MyException.h"
#include <climits>
#include <stdexcept> // To use runtime_error
#include "Calculator.cpp"
#include "sqlDemo.h"


#include "sqlite3.h"


/*QUERY MAKEIER HELPER FUNCTION */
void queryDoer(int choice, double number1, double number2, double result, const char *dir)
{
    string sql;

    if (choice == 1) //FOR +
    {

        sql = "INSERT INTO SESSION_TABLE(NUMBER1, NUMBER2, OPERATION_PERFORMED, RESULT) VALUES(" +
              to_string(number1) + ',' +
              to_string(number2) + ',' + "'ADD'" + ',' +
              to_string(result) + "); ";
    }
    else if (choice == 2) //-
    {
        sql = "INSERT INTO SESSION_TABLE(NUMBER1, NUMBER2, OPERATION_PERFORMED, RESULT) VALUES(" +
              to_string(number1) + ',' +
              to_string(number2) + ',' + "'SUBTR'" + ',' +
              to_string(result) + "); ";
    }
    else if (choice == 3)//*
    {
        sql = "INSERT INTO SESSION_TABLE(NUMBER1, NUMBER2, OPERATION_PERFORMED, RESULT) VALUES(" +
              to_string(number1) + ',' +
              to_string(number2) + ',' + "'MUL'" + ',' +
              to_string(result) + "); ";
    }
    else if (choice == 4) //DIV
    {
        sql = "INSERT INTO SESSION_TABLE(NUMBER1, NUMBER2, OPERATION_PERFORMED, RESULT) VALUES(" +
              to_string(number1) + ',' +
              to_string(number2) + ',' + "'DIV'" + ',' +
              to_string(result) + "); ";
    }

    if (choice == 5) //SELECT WHOLE DATA
    {
        selectData(dir);
    }
    else
    {
        insertData(dir, sql); //INSERTDATA

        cout << "Result is: " << result << endl;
    }
}

int main(void)
{
    int choice = 0;

    cout << "************CALCULATOR*****************" << endl;

    cout << "Addition: Enter 1" << endl;
    cout << "Subtraction: Enter 2" << endl;
    cout << "Multiplication: Enter 3" << endl;
    cout << "Division: Enter 4" << endl;
    cout << "Check Database: Enter 5" << endl;

    bool loopRun = true;
    double number1 = 1;
    double number2 = 1;

    while (loopRun)
    {
        cout << "Enter the Choice: " << endl;
        cin >> choice;

        if (choice > 0 && choice < 5)
        {
            cout << "Enter First Number: " << endl;
            cin >> number1;

            cout << "Enter Second Number: " << endl;
            cin >> number2;

            loopRun = false;
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
    Calculator obj;
    auto result = 0.0;
    const char *dir = R"(calculatorSessionDb.db)";
     createDB(dir);
     createTable(dir);
    // deleteData(dir);
    string sql = "";

    switch (choice)
    {
    case 1:
        result = obj.add(number1, number2);
        queryDoer(choice, number1, number2, result, dir);

        break;
    case 2:
        result = obj.subtract(number1, number2);
        queryDoer(choice, number1, number2, result, dir);
        break;

    case 3:
        result = obj.multiply(number1, number2);
        queryDoer(choice, number1, number2, result, dir);
        break;
    case 4:
        result = obj.divide(number1, number2);
        queryDoer(choice, number1, number2, result, dir);
        break;

    case 5:
        queryDoer(choice, number1, number2, result, dir);
        break;

    default:
        break;
    }

    return 0;
}

//