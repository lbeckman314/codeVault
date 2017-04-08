"""
LAB 4
#Purpose: To output the money due for returning a certain number of refundable bottles (10 cents per bottle).
#Input list: number of bottles returned (bottles)
#Output list: number of bottles returned (bottles), total paid out in cents(numberOfCents), total paid out in dollars (numberOfDollars)
__Author__ = "liam"

Pseudocode:

while true
    display "How many bottles returned today?"
    input number_of_bottles
    if input is a number
        convert number_of_bottles from string to integers
        bottles = number_of_bottles
        break
    else
        ouput  "Please enter again."

define module totalBottlesReturned(bottles)
    totalBottles = 0
    totalBottles = totalBottles + bottles    
    return totalBottles

define module totalPaidOut(totalBottles)
    numberOfCents = 10 * totalBottles
    return numberOfCents

def centsToDollars(numberOfCents):
    numberOfDollars = numberOfCents / 100
    return numberOfDollars

define module outputResults(totalBottles, numberOfCents)
    numberOfDollars = centsToDollars(numberOfCents)
    output "Total bottles returned:", totalBottles, "bottles"
    output "Total paid out:", numberOfCents, "cents"
    output "---------------", numberOfDollars, "dollars"

call outputResults(totalBottlesReturned(bottles), totalPaidOut(totalBottlesReturned(bottles)))

#totalBottles = totalBottlesReturned(bottles)
#numberOfCents = totalPaidOut(totalBottles)
#outputResults(totalBottles, numberOfCents)

"""

while(True):
    bottles = input("How many bottles returned today? ")
    if bottles.isdigit() == True:
        bottles = int(bottles)
        break
    else:
        print("Please enter again.")


def totalBottlesReturned(bottles):
    totalBottles = 0
    totalBottles += bottles    
    return totalBottles

def totalPaidOut(totalBottles):
    numberOfCents = 10 * totalBottles
    return numberOfCents

def centsToDollars(numberOfCents):
    numberOfDollars = numberOfCents / 100
    return numberOfDollars
    

def outputResults(totalBottles, numberOfCents):
    numberOfDollars = centsToDollars(numberOfCents)
    print("Total bottles returned:", totalBottles, "bottles")
    print ("Total paid out:", "%.2f" %numberOfCents, "cents")
    print ("---------------", "%.2f" %numberOfDollars, "dollars")
 

outputResults(totalBottlesReturned(bottles), totalPaidOut(totalBottlesReturned(bottles)))


