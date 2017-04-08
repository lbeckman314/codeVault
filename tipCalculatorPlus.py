#-------------------------------------------------------------------------------------------------------------
# PURPOSE --------- This program calculates the tax, tip, and total cost of a meal!
# AUTHOR ---------- liam beckman
# DATE ------------ 26 october 2016 wednesday
# SOURCES --------- none
# ASSIGNMENT ------ cis122 lab 3 tip tax total 2.0 (due october 31st 2016)
# COMPILED WITH --- Python 3.5.2 [GCC 5.4.0 20160609] in Sublime Text 3 Build 3126
#--------------------------------------------------------------------------------------------------------------

__Author__ = 'liam'

'''
This program calculates the tax, tip, and total cost of a meal!

input list: meal (cost of meal)
output list: tip, tax, total (total cost including tax and tip)

display "hello!"
prompt meal
input meal
if(0.1<=meal<=5.99)
	tip = meal * 0.20
else if(6<=meal<=12.00)
	tip = meal * 0.20
else if(12.01<=meal<=17.00)
	tip = meal * 0.20
else if(17.01<=meal<=25.00)
	tip = meal * 0.20
else if(25.01<=meal)
	tip = meal * 0.20
tax = meal * 0.06
total = meal + tip + tax

display meal, tip, tax, total
'''

print("hello!\n")

meal = float(input("please enter the price of your meal:"))
if (0.1<=meal<=5.99):
	tip = meal * 0.10
elif (6<=meal<=12.00):
	tip = meal * 0.13
elif (12.01<=meal<=17.00):
	tip = meal * 0.16
elif (17.01<=meal<=25.00):
	tip = meal * 0.19
elif (25.01<=meal):
	tip = meal * 0.22
tax = meal * 0.06
total = meal + tip + tax

print("\nRECIPT OF CHARGES\n")
print("meal:","-------", "$ %.2f" %(meal))
print("tip:","--------", "$ %.2f" %(tip))
print("tax","---------", "$ %.2f" %(tax))
print("TOTAL:","------", "$ %.2f" %(total))

