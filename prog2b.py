# ---------------------------------------------------------------------------------------------------
# Programmer name: Cody Bruehl
# Program: 2b
# Date: 7-12-20
# Description: Creating a GUI in Python using Tkinter.
# ---------------------------------------------------------------------------------------------------
from tkinter import *

canvas_width = 150
canvas_height = 50
root = Tk()
x = Canvas(root, width=canvas_width, height=canvas_height, bg="skyblue")
x.pack()
x.create_oval(50, 5, 100, 50, fill="orange")


def myClick1():
    myLabel = Label(root)
    print("\tTemperature\n" "\tConversion\n" "F" "\t\t\t\t " "C\n" "---------------------")
    for currentFahrenheitTemperature in range(80, 100, 2):
        celsiusTemperatureEquivalent = round(5 / 9 * (currentFahrenheitTemperature - 32))
        print(currentFahrenheitTemperature, "\t\t\t\t", celsiusTemperatureEquivalent)
        myLabel.pack()
    print("---------------------")


def myClick2():
    myLabel = Label(root, command=root.destroy())
    myLabel.pack()


button1Object = Button(root, text="Temperature", command=myClick1)
button1Object.pack()
button2Object = Button(root, text="Quit", command=myClick2, padx=23)
button2Object.pack()

root.mainloop()
