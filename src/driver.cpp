#include <iostream>
using namespace std;  // TODO: using namespace std;
// TODO: These relative include paths are a codesmell. We typically have the headers alongside the CPPs 
#include "../include/MyException.h" 
#include <climits>
#include <stdexcept> 
#include "../include/Calculator.h"
#include "../include/sqlDemo.h"
#include "../sqlite3.h"  // TODO: this should be <sqlite3.h> right? as in a system header.


/*QUERY MAKEIER HELPER FUNCTION */
// TODO: replace 'const char *' with std::stringview or std::string
void queryDoer(int choice, double number1, double number2, double result, const char *dir)
{
    string sql;

    if (choice == 1) //FOR +
    {
        // TODO: use String stream or FMT lib for these String constructions
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
    Calculator obj; // TODO: no need to create an object to call static functions
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