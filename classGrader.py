__author__ = 'liam'

#input list: studentCount, grade
#output list: highestGrade, lowestGrade, averageGrade


"""
function numberOfStudents(students array):
    while true
        try
            display prompt
            input integer value

            if value = 0
                display "please enter a number greater than zero"
                continue try loop
            if studentCount < 0:
                display "please enter a positive number"
                continue try loop
            break try loop
        except value error
            display "please reenter your value (no letters!)"
            continue try loop
    append value to students array
    return students array
"""

def numberOfStudents(students):
    while True:
        try:
            studentCount = int(input("please enter number of students taking the test: "))
            if studentCount == 0:
                print("please enter a number greater than zero")
                continue
            if studentCount < 0:
                print("please enter a positive number")
                continue
            break
        except ValueError:
            print("please reenter your value (no letters!)")
            continue
    students.append(studentCount)
    return students

"""
function gradeInput(grades array):
    while true
        try
            display prompt
            input  integer value
            if value = 0
                display "please enter a number greater than zero"
                continue try loop
            if grade < 0: 
                display "please enter a positive number"
                continue try loop
        except value error
            display "please reenter your value (no letters!)"
            continue try loop
        break while loop
    append value to grades array
    return grades
"""

def gradeInput(grades):
    while True:
        try:
            grade = int(input("please enter the grades for the test: "))
            if grade == 0:
                print("please enter a number greater than zero")
                continue
            if grade < 0: 
                print("please enter a positive number")
                continue
        except ValueError:
            print("please reenter your value (no letters!)")
            continue
        break
    grades.append(grade)
    return grades

"""
function averageGrade(grades array):
    declare integer summ = sum(grades array)
    declare int average = summ / len(grades array)
    return average
"""

def averageGrade(grades):
    summ = sum(grades)
    average = summ / len(grades)
    return average

"""
function lowestGrade(grades array):
    declare integer lowest = min(grades array)
    return lowest
"""

def lowestGrade(grades):
    lowest = min(grades)
    return lowest

"""
function highestGrade(grades array):
    declare integer highest = max(grades array)
    return highest
"""

def highestGrade(grades):
    highest = max(grades)
    return highest

"""
function gradeOutput(grades array):
    display newline
    display "the highest grade is" and highestGrade(grades array)
    display "the lowest grade is" and lowestGrade(grades array)
    display "the average grade is" and averageGrade(grades array)
    display newline
"""

def gradeOutput(grades):
    print()
    print("the highest grade is", highestGrade(grades))
    print("the lowest grade is", lowestGrade(grades))
    print("the average grade is", averageGrade(grades))
    print()

"""
function main():
    declare array students = []
    declare array grades = []
    declare boolean value restartProgram = true
    
    while restartProgram = true
        declare integer gradeCount = 0
        delete grades array
        delete students array
        call numberOfStudents(students array)
        endOfInput = false
    
        while endOfInput = false    
            call gradeInput(grades)
            gradeCount += 1

            if gradeCount = students[0]
                endOfInput = true
                call gradeOutput(grades)
                
                while true
                    display prompt "would you like to begin input on a new test (n) or exit the program (e)? "
                    input value
                    if value = 'e' or value = 'n'
                        break while loop
                    else
                        display "enter either n or e please"
                    
                if value = 'n'
                    display newline
                    restartProgram = true
                else if value = 'e'
                    display "~~namaste~~"
                    restartProgram = false

"""

def main():
    students = []
    grades = []
    restartProgram = True
    
    while restartProgram == True:
        gradeCount = 0
        del grades[:]
        del students[:]
        numberOfStudents(students)
        endOfInput = False
    
        while endOfInput == False:    
            gradeInput(grades)
            gradeCount += 1

            if gradeCount == students[0]:
                endOfInput = True
                gradeOutput(grades)
                
                while True:
                    programContinue = input("would you like to begin input on a new test (n) or exit the program (e)? ")
                    if programContinue.lower() == 'e' or programContinue.lower() == 'n':
                        break
                    else:
                        print("enter either n or e please\n")
                    
                if programContinue.lower() == 'n':
                    print()
                    restartProgram = True
                elif programContinue.lower() == 'e':
                    print("~~namaste~~")
                    restartProgram = False

"""
call main function
"""

main()
