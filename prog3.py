# ---------------------------------------------------------------------------------------------------
# Programmer name: Cody Bruehl
# Program: 3
# Date: 7-16-20
# Description: Creating a Metric Conversion GUI in Python using Tkinter.
# ---------------------------------------------------------------------------------------------------
from tkinter import *
root = Tk()

Frame1 = Frame(root)
Frame1.pack()
outputLabel = Label(Frame1, text="Cody Bruehl's Metric Conversion App", height=2, fg="blue")
outputLabel.pack()

Frame2 = Frame(root)
Frame2.pack()
inputLabel = Label(Frame2, text="Miles")
inputLabel.pack(side=LEFT)
userEntry1 = Entry(Frame2, bd=4)
userEntry1.pack(side=RIGHT)

Frame3 = Frame(root)
Frame3.pack()
outputLabel = Label(Frame3, text="Kilometers:")
outputLabel.pack(side=LEFT)
resultString1 = StringVar()
resultLabel = Label(Frame3, textvariable=resultString1, height=2, fg="red")
resultLabel.pack(side=RIGHT)

Frame4 = Frame(root)
Frame4.pack()
inputLabel = Label(Frame4, text="Pounds")
inputLabel.pack(side=LEFT)
userEntry2 = Entry(Frame4, bd=4)
userEntry2.pack(side=RIGHT)

Frame5 = Frame(root)
Frame5.pack()
outputLabel = Label(Frame5, text="Kilograms:")
outputLabel.pack(side=LEFT)
resultString2 = StringVar()
resultLabel = Label(Frame5, textvariable=resultString2, height=2, fg="red")
resultLabel.pack(side=RIGHT)


def calculateLength():
    userInput = userEntry1.get()
try:
    num = float(userInput)
except ValueError:
    print("No input detected!")
return
# conversion_factor = 0.62137119
x = num / 0.62137119
resultString1.set(str(round(x,2)))


def calculateMass():
    userInput = userEntry2.get()
try:
    num = float(userInput)
except ValueError:
    print("No input detected!")
return
x = num * 0.453592
resultString2.set(str(round(x, 2)))


def Quit():
    root.destroy()


CLButton = Button(root, text="Convert Length", command=calculateLength, height=2)
CLButton.pack(side=LEFT, ipadx=0)
CMButton = Button(root, text="Convert Mass", command=calculateMass, height=2)
CMButton.pack(side=LEFT, ipadx=0)
quitButton = Button(root, text="Quit", command=Quit, height=2)
quitButton.pack(side=RIGHT, ipadx=15)
root.mainloop()
