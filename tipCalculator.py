__Author__ = 'liam'
'''
This program calculates the tax, tip, and total cost of a meal!

input list: meal (cost of meal)
output list: tip, tax, total (total cost including tax and tip)

display "hello!"
prompt meal
input meal
tip = meal * 0.20
tax = meal * 0.06
total = meal + tip + tax

display meal, tip, tax, total
'''

print("hello!\n")

meal = float(input("please enter the price of your meal:"))
tip = meal * 0.20
tax = meal * 0.06
total = meal + tip + tax

print("\nRECIPT OF CHARGES\n")
print("meal:","-------", "$ %.2f" %(meal))
print("tip:","--------", "$  %.2f" %(tip))
print("tax","---------", "$   %.2f" %(tax))
print("TOTAL:","------", "$ %.2f" %(total))

