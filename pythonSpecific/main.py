from dataclasses import dataclass
import database


class Calculator:
    def add(self, a, b):
        return a+b

    def subtract(self, a, b):
        return a-b

    def multiply(self, a, b):
        return a*b

    def divide(self, a, b):
        return a/b


# create a calculator object
calc = Calculator()

while True:

    print("1: Add")
    print("2: Subtract")
    print("3: Multiply")
    print("4: Divide")
    print("5: Exit")

    ch = int(input("Select operation: "))

    # Make sure the user have entered the valid choice
    if (ch > 0 and ch < 6):

        # first check whether user want to exit
        if(ch == 5):
            break

        # If not then ask fo the input and call appropiate methods

        loopvar = True

        while(loopvar):
            try:
                a = float(input("Enter first number: "))
                b = float(input("Enter second number: "))
                loopvar = False

            except ValueError:
                print("Specify Correct Operands")

        if(ch == 1):
            print(a, "+", b, "=", calc.add(a, b))
            task = (a, b, "ADD", calc.add(a, b))

        elif(ch == 2):
            print(a, "-", b, "=", calc.subtract(a, b))
            task = (a, b, "SUBTRACT", calc.subtract(a, b))

        elif(ch == 3):
            print(a, "*", b, "=", calc.multiply(a, b))
            task = (a, b, "MULTIPLY", calc.multiply(a, b))

        elif(ch == 4):
            print(a, "/", b, "=", calc.divide(a, b))
            task = (a, b, "DIVISION", calc.divide(a, b))

        database.store(task)
