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
