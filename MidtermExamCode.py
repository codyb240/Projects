# ---------------------------------------------------------------------------------------------------
# Programmer name: Cody Bruehl
# Program: 2b
# Date: 7-12-20
# Description: Creating a GUI in Python using Tkinter.
# ---------------------------------------------------------------------------------------------------
#from tkinter import *


#def myClick1():
#    myLabel = Label(root)
#    for num in range(1, 11):
#        num2 = num**2
#        print(num, "\t", num2)

#    myLabel.pack()


#button1 = Button(root, text="Table", command=myClick1)
#button1.pack()

#root.mainloop()

from tkinter import *
canvas_width = 100
canvas_height = 100
root = Tk()
x = Canvas(root, width=canvas_width, height=canvas_height, bg="green")
x.pack()
x.create_oval(10, 10, 90, 90, fill="red", width=2)
line = x.create_line(10, 10, 90, 90, fill='white', width=2)

root.mainloop()
