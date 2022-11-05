# ---------------------------------------------------------------------------------------------------
# Programmer name: Cody Bruehl
# Program: 4
# Date: 7-24-20
# Description: Creating a Math Problem Solver GUI in Python using Tkinter.
# ---------------------------------------------------------------------------------------------------
from tkinter import *
root = Tk()
root.geometry("250x250")
root.title("Math Problem Solver")

Frame1 = Frame(root)
Frame1.pack()
outputLabel = Label(Frame1, text="Enter your math problem", height=2, fg="black")
outputLabel.pack()

Frame2 = Frame(root)
Frame2.pack()
inputLabel = Label(Frame2, text="First number      ")
inputLabel.pack(side=LEFT)
userEntry1 = Entry(Frame2, bd=4)
userEntry1.pack(side=RIGHT)

Frame3 = Frame(root)
Frame3.pack()
inputLabel = Label(Frame3, text="Operation Sign  ")
inputLabel.pack(side=LEFT)
userEntry2 = Entry(Frame3, bd=4)
userEntry2.pack(side=RIGHT)

Frame4 = Frame(root)
Frame4.pack()
inputLabel = Label(Frame4, text="Second number")
inputLabel.pack(side=LEFT)
userEntry3 = Entry(Frame4, bd=4)
userEntry3.pack(side=RIGHT)

Frame5 = Frame(root)
Frame5.pack()
outputLabel = Label(Frame5, text="Answer: ")
outputLabel.pack(side=LEFT)
resultString = StringVar()
resultLabel = Label(Frame5, textvariable=resultString, height=2, fg="red")
resultLabel.pack(side=RIGHT)


def Submit():
    num1 = int(userEntry1.get())
    oSign = userEntry2.get()
    num2 = int(userEntry3.get())
    if oSign == '+':
        resultString.set(num1+num2)
    elif oSign == '-':
        resultString.set(num1-num2)
    elif oSign == '*':
        resultString.set(num1*num2)
    elif oSign == '/':
        resultString.set(num1/num2)


def Quit():
    root.destroy()


SubmitButton = Button(root, text="Submit", command=Submit, height=2)
SubmitButton.pack(side=LEFT, ipadx=23)
quitButton = Button(root, text="Quit", command=Quit, height=2)
quitButton.pack(side=RIGHT, ipadx=30)
root.mainloop()
