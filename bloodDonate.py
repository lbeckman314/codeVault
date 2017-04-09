__author__ = 'liam'

#-------------------------------------------------------------------------------------------------------------
# PURPOSE --------- This program calculates the tax, tip, and total cost of a meal!
# AUTHOR ---------- liam beckman
# DATE ------------ 26 october 2016 wednesday
# SOURCES --------- none
# ASSIGNMENT ------ cis122 lab 3 tip tax total 2.0 (due october 31st 2016)
# COMPILED WITH --- Python 3.5.2 [GCC 5.4.0 20160609] in Sublime Text 3 Build 3126
#--------------------------------------------------------------------------------------------------------------

#input list: numberOfPints
#output list: lowestPint, highestPint, averagePint  

"""
function pintCollection(blood array):
    while true
        try   
            display prompt
            input integer value
            if value < 0
                display "please enter a positive number"
                continue
            else if value = 0
                display "please enter a number greater than zero"
                continue
            break try loop
        except value error
            display "please enter a number"
    append value to blood array
"""

def pintCollection(blood):          
    while True:
        try:    
            numberOfPints = int(input("Please enter number of pints: "))
            if numberOfPints < 0:
                print("please enter a positive number")
                continue
            elif numberOfPints == 0:
                print("please enter a number greater than zero")
                continue
            break
        except ValueError:
            print("please enter a number")
    blood.append(numberOfPints)

"""
function lowest(blood array):
    declare array lowestPint
    lowestPint.append(min(blood array)
    return lowestPint
"""

def lowest(blood):
    lowestPint = []
    lowestPint.append(min(blood)) 
    return lowestPint[0]

"""
function highest(blood array):
    declare array highestPint
    highestPint.append(max(blood array))
    return highestPint
"""

def highest(blood):
    highestPint = []
    highestPint.append(max(blood))
    return highestPint[0]

"""
function average(blood array):
    declare integer summ = 0
    summ = sum(blood)
    declare integer average = summ / len(blood array)
    return average
"""

def average(blood):
    summ = 0
    summ = sum(blood)
    averagePint = summ / len(blood)
    return averagePint


"""
function outputPints(blood array)
    display "\n"
    display "the average number of donates pints: ", average(blood array)
    display "the lowest number of donated pints:  ", lowest(blood array)
    display "the highest number of donated pints: ", highest(blood array)

"""

def outputPints(blood):
    print("\n")
    print("the average number of donates pints: ", average(blood))
    print("the lowest number of donated pints:  ", lowest(blood))
    print("the highest number of donated pints: ", highest(blood))
            


"""
def main():
    display "Welcome to Dr. Acula's Blood Collector 3000!"
    display "Press Ctrl+C to pause collection and output results"
    display newline
    declare array blood = []
    declare boolean value endOfWork = False
    
    while endOfWork = false
        try
            call pintCollection(blood)
        except KeyboardInterrupt
            call outputPints(blood array)
            
            display prompt
            input character value
            display newline
            if character value = 'n'
                endOfWork = true
"""

def main():
    print("Welcome to Dr. Acula's Blood Collector 3000!")
    print("Press Ctrl+C to pause collection and output results")
    print()
    blood = []
    endOfWork = False
    
    while endOfWork == False:
        try:
            pintCollection(blood)
        except KeyboardInterrupt:
            outputPints(blood)
            programContinue = input("would you like to continue the program (y/n): ")
            print()
            if programContinue.lower() == 'n':
                endOfWork = True

"""
call main function
"""
            
main()
