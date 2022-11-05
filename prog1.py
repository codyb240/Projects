# --------------------------------------------------------------------------------------------------------------------------
# Programmer:Cody Bruehl
# Program: 1
# Date:7-4-20
# Description: This program provides tutoring for addition, subtraction and multiplication.
# The program generates a random arithmetic problem using numbers in the range 1-20.
# --------------------------------------------------------------------------------------------------------------------------
import random
def randIntMax20():
    num = random.randint(1, 20)
    return num

numProbs = int(input("How many problems?"))

for i in range(0, numProbs):
    num1 = randIntMax20()
    num2 = randIntMax20()

    if num1 < num2:
        num1 = 20

    r = round(random.random() * 2)

    if r == 0:
        print(num1, "+", num2, "=")

        correctAnswer = num1 + num2

    elif r == 1:
        print(num1, "-", num2, "=")

        correctAnswer = num1 - num2

    if r == 2:
        print(num1, "x", num2, "=")

        correctAnswer = num1 * num2

    studentAnswer = int(input())
    if studentAnswer == correctAnswer:
        print("Correct, well done!")
    else:
        print("Sorry, the correct answer is", correctAnswer)
