__author__ = "Liam Beckman"

#-------------------------------------------------------------------------------------------------------------
# PURPOSE --------- This program calculates the tax, tip, and total cost of a meal!
# AUTHOR ---------- liam beckman
# DATE ------------ 26 october 2016 wednesday
# SOURCES --------- none
# ASSIGNMENT ------ cis122 lab 3 tip tax total 2.0 (due october 31st 2016)
# COMPILED WITH --- Python 3.5.2 [GCC 5.4.0 20160609] in Sublime Text 3 Build 3126
#--------------------------------------------------------------------------------------------------------------

"""
This program functions as a rudimentary calculator, with the ability to add, subtract, multiply, and divide user-inputted numbers.

INPUT LIST: firstNumber (first number in input_numbers[]), number (subsequent numbers in input_numbers[]), calculation_mode (input_operators[]) 
OUTPUT LIST: input_numbers[], input_operatiors[], calculated_result
"""


"""
Global Array input_numbers = []
Global Array input_operators = []
"""

input_numbers = []
input_operators = []


"""
Class Calculator
    Private Real _calculated_result
    Private Int _number_of_operands
    
    Public module __init__(self, Real number_of_operands):
        self._number_of_operands = number_of_operands
"""

class Calculator:
    _calculated_result = 0.0
    _number_of_operands = 0
    
    def __init__(self, number_of_operands):
        self._number_of_operands = number_of_operands


    """
    Public Function get_first_number(self):
        Boolean input_done = False
        While not input_done:
            try:
                Real number = float(input("***Please enter your first number: "))
                self._calculated_result = number
                input_done = True
            except ValueError:
                Display "Please enter a number (no letters allowed)")
        input_numbers.append(number)
        Return input_numbers
    End Function
    """

    def get_first_number(self):
        input_done = False
        while not input_done:
            try:
                firstNumber = float(input("***Please enter your first number: "))
                self._calculated_result = firstNumber
                input_done = True
            except ValueError:
                print("Please enter a number (no letters allowed)")
        input_numbers.append(firstNumber)
        return input_numbers
    

    """
    Public Function get_numbers(self):
        input_done = False
        while not input_done:
            try:
                number = float(input("***Please enter another number: "))
                input_done = True
            except ValueError:
                Display "Please enter a number (no letters allowed)"
        input_numbers.append(number)
        Return input_numbers[len(input_operators)]
    End Function   
    """

    def get_numbers(self):
        input_done = False
        while not input_done:
            try:
                number = float(input("***Please enter another number: "))
                input_done = True
            except ValueError:
                print("Please enter a number (no letters allowed)")
        input_numbers.append(number)
        return input_numbers[len(input_operators)]


    """
    Public Function get_mode(self):
        input_done = False
        while not input_done:
            try:
                calculation_mode = input("Would you like to add (+), subtract (-), multiply (*), or divide (/)? ")
                input_done = True
            except ValueError:
                Display "please reenter your desired mode"
        input_operators.append(calculation_mode)
        Return input_operators[len(input_operators)-1]
    End Function   
    """

    def get_mode(self):
        input_done = False
        while not input_done:
            try:
                calculation_mode = input("Would you like to add (+), subtract (-), multiply (*), or divide (/)? ")
                input_done = True
            except ValueError:
                print("please reenter your desired mode")
        input_operators.append(calculation_mode)
        return input_operators[len(input_operators)-1]
    

    """
    Public Function calculate_numbers(self):
        while True:
            try:    
                mode = Calculator.get_mode(self)
                number = Calculator.get_numbers(self)
                If mode == '+' or mode.lower() == 'a':
                    self._calculated_result += number 
                    Display "Added"
                    break
                Else If mode == '-' or mode.lower() == 's':
                    self._calculated_result -= number
                    Display "Subtracted"
                    break
                Else If mode == '*' or mode.lower() == 'm':
                    self._calculated_result *= number
                    Display "Multiplied"
                    break
                Else If mode == '/' or mode.lower() == 'd':
                    self._calculated_result /= number
                    Display "Divided"
                    break
                Else:
                    Display "please reenter your desired mode")
            except ZeroDivisionError:
                Display "float division by zero -- please reenter number"
        Return self._calculated_result
    End Function   
    """

    def calculate_numbers(self):
        while True:    
            try:
                mode = Calculator.get_mode(self)
                number = Calculator.get_numbers(self)
                if mode == '+' or mode.lower() == 'a':
                    self._calculated_result += number 
                    print("Added")
                    break
                elif mode == '-' or mode.lower() == 's':
                    self._calculated_result -= number
                    print("Subtracted") 
                    break
                elif mode == '*' or mode.lower() == 'm':
                    self._calculated_result *= number
                    print("Multiplied") 
                    break
                elif mode == '/' or mode.lower() == 'd':
                    self._calculated_result /= number
                    print("Divided") 
                    break
                else:
                    print("please reenter your desired mode")
            except ZeroDivisionError:
                print("float division by zero -- please reenter number")
        return self._calculated_result


    """
    Public Function display_results(self):
        Display newline
        for i in range(len(input_operators)):
            Display input_numbers[i]
            Display input_operators[i]
        Display input_numbers[len(input_numbers)-1]
        Display "----------equals-----------"
        Display "{0:.5f}".format(self._calculated_result)
    End Function
    """

    def display_results(self):
        print()
        for i in range(len(input_operators)):
            print(input_numbers[i], end=" ")
            print(input_operators[i], end=" ")
        print(input_numbers[len(input_numbers)-1])
        print("----------equals-----------")
        print("{0:.5f}".format(self._calculated_result))


"""
Module main():
    input_done = False
    user_number_of_operands = int(input("How many numbers would you like to work with? "))
    userCal = Calculator(user_number_of_operands)
    userCal.get_first_number()
    while not input_done:
        Display )
        userCal.calculate_numbers()
        userCal.display_results()
        
        if len(input_numbers) == user_number_of_operands:
            input_done = True
            continue
"""

def main():
    input_done = False
    while True:
        try:
            user_number_of_operands = int(input("How many numbers would you like to work with? "))
            if user_number_of_operands >= 2:
                break
            else:
                print("please enter a value of 2 or greater")
        except ValueError:
            print("please reenter your value (integers only)")
    userCal = Calculator(user_number_of_operands)
    userCal.get_first_number()
    while not input_done:
        print()
        userCal.calculate_numbers()
        userCal.display_results()
        
        if len(input_numbers) == user_number_of_operands:
            input_done = True
            continue


"""
Call main() module
"""

main()