# This file is a script for Psychoanalysis
# Contains conditions for each response written in Python 2 or 3
# Just run this by `py script.py`

ans = input("How are you feeling? ")

if ans == "I'm feeling down":
    ans2 = input("Are you feeling down because of your job? ")
    if ans2 == "yes":
        ans3 = input("Why are you down? ")
        if ans3 == "I'm stressed":
           print("You need to rest a little bit, don't overstress yourself") 
    elif ans2 != "yes":
        ans3 = input("Please state your reason: ")
        if ans3:
            print("Seems you need a professional psychiatrist.")
    else:
        print("This is not good at all")
elif ans == "I'm feeling happy":
    ans2 = input("Are you happy because of your job? ")
    if ans2:
        ans3 = input("Why are you happy? ")
        if ans3 == "I got promoted":
            print("Oh, very nice, keep up the good work")
        elif ans3 == "I got a raise":
            print("That's good my man, salary increased")
        else:
            print("That's good to hear, just keep up the good work") 
    else:
        print("Quiet or no answer, you are really happy")
else:
    ans2 = input("Why are you feeling like that? ")
    if ans2:
        ans3 = input("Why you do that anyway? ")
        if ans3:
            print("Probably you just need some rest. Take your time, don't rush")
    else:
        print("I have nothing to say.")
