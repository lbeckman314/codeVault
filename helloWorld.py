#-------------------------------------------------------------------------------------------------------------
# PURPOSE --------- This program calculates the tax, tip, and total cost of a meal!
# AUTHOR ---------- liam beckman
# DATE ------------ 26 october 2016 wednesday
# SOURCES --------- none
# ASSIGNMENT ------ cis122 lab 3 tip tax total 2.0 (due october 31st 2016)
# COMPILED WITH --- Python 3.5.2 [GCC 5.4.0 20160609] in Sublime Text 3 Build 3126
#--------------------------------------------------------------------------------------------------------------

iceCream = """
     oQo
   (     )
   {,~.~,}
    \.MM/
     \W/
      V
"""

print ("Hello World!")
print ("How are you feeling today?")
response = input()
if response.lower() == "good":
    print("Sweet! Have an ice cream!")
    print(iceCream)
elif response.lower() == "bad":
    print("I am sorry to hear that. Have an ice cream")
    print(iceCream)
else:
    print("Ah yes. Such is the way of all things")
    print(iceCream)
