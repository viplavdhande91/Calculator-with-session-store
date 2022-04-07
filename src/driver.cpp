#include <iostream>
#include "MyException.h"
#include <limits>
#include <stdexcept> // To use runtime_error
#include "Calculator.h"
#include "sqlDemo.h"
#include <sqlite3.h>

/*QUERY MAKEIER HELPER FUNCTION */
void queryDoer(int choice, double number1, double number2, double result, const char *dir)
{
    std::string sql;

    if (choice == 1) // FOR +
    {

        sql = "INSERT INTO SESSION_TABLE(NUMBER1, NUMBER2, OPERATION_PERFORMED, RESULT) VALUES(" +
              std::to_string(number1) + ',' +
              std::to_string(number2) + ',' + "'ADD'" + ',' +
              std::to_string(result) + "); ";
    }
    else if (choice == 2) //-
    {
        sql = "INSERT INTO SESSION_TABLE(NUMBER1, NUMBER2, OPERATION_PERFORMED, RESULT) VALUES(" +
              std::to_string(number1) + ',' +
              std::to_string(number2) + ',' + "'SUBTR'" + ',' +
              std::to_string(result) + "); ";
    }
    else if (choice == 3) //*
    {
        sql = "INSERT INTO SESSION_TABLE(NUMBER1, NUMBER2, OPERATION_PERFORMED, RESULT) VALUES(" +
              std::to_string(number1) + ',' +
              std::to_string(number2) + ',' + "'MUL'" + ',' +
              std::to_string(result) + "); ";
    }
    else if (choice == 4) // DIV
    {
        sql = "INSERT INTO SESSION_TABLE(NUMBER1, NUMBER2, OPERATION_PERFORMED, RESULT) VALUES(" +
              std::to_string(number1) + ',' +
              std::to_string(number2) + ',' + "'DIV'" + ',' +
              std::to_string(result) + "); ";
    }

    if (choice == 5) // SELECT WHOLE DATA
    {
        sqlDemo::selectData(dir);
    }
    else
    {
        sqlDemo::insertData(dir, sql); // INSERTDATA

        std::cout << "Result is: " << result << std::endl;
    }
}

int main(void)
{
    int choice = 0;

    std::cout << "************CALCULATOR*****************" << std::endl;

    std::cout << "Addition: Enter 1" << std::endl;
    std::cout << "Subtraction: Enter 2" << std::endl;
    std::cout << "Multiplication: Enter 3" << std::endl;
    std::cout << "Division: Enter 4" << std::endl;
    std::cout << "Check Database: Enter 5" << std::endl;

    bool loopRun = true;
    double number1 = 1;
    double number2 = 1;

    while (loopRun)
    {
        std::cout << "Enter the Choice: " << std::endl;
        std::cin >> choice;

        if (choice > 0 && choice < 5)
        {
            std::cout << "Enter First Number: " << std::endl;
            std::cin >> number1;

            std::cout << "Enter Second Number: " << std::endl;
            std::cin >> number2;

            loopRun = false;
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice" << std::endl;
        }
    }
    Calculator obj{};
    auto result = 0.0;
    const char *dir = R"(calculatorSessionDb.db)";
    sqlDemo::createDB(dir);
    sqlDemo::createTable(dir);
    // deleteData(dir);
    std::string sql = "";

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