from tkinter import *
root = Tk()


Frame1 = Frame(root)
Frame1.pack()
inputLabel = Label(Frame1)
inputLabel.pack()
userEntry1 = Entry(Frame1)
userEntry1.pack()
resultString1 = StringVar()
resultLabel = Label(Frame1, textvariable=resultString1)
resultLabel.pack(side=RIGHT)


def CalculateAge():
    userInput = userEntry1.get()
    x = int(userInput)
    age = 2020 - x
    resultString1.set(str(age))


def Quit():
    root.destroy()


AgeButton = Button(root, text="Calculate", command=CalculateAge)
AgeButton.pack()

quitButton = Button(root, text="Quit", command=quit)
quitButton.pack()

root.mainloop()


