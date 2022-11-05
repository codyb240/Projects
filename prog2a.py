# --------------------------------------------------------------------------------------------------------------------------
# Programmer:Cody Bruehl
# Program: 2a
# Date:7-9-20
# Description: This program utilizes Classes, Dictionaries, Lists, and Sets.
# --------------------------------------------------------------------------------------------------------------------------
import math
# for math.sqrt()


class Point:
    x = 0  # a new point object starts at the origin (0, 0)
    y = 0

    def goto(self, newx, newy):  # changes the coordinates self.x and self.y to new values
        self.x = newx
        self.y = newy

    def position(self):  # prints the coordinates of the point object as (x, y); for example, (-2, 3)
        print(self.x, self.y)

    def fromOrigin(self):  # returns the distance of the point object from the origin; √𝑥2 + 𝑦2
        return print(math.sqrt(self.x**2 + self.y**2))

    def quadrant(self):  # returns a string that specifies the quadrant of the point object
        quad = {1: "Quad I", 2: "Quad II", 3: "Quad III", 4: "Quad IV"}  # build a small dictionary
        # check self.x and self.y; based on their values return quad[1], quad[2], quad[3], or quad[4]
        if self.x > 0 and self.y > 0:
            return print(quad[1])
        elif self.x < 0 and self.y > 0:
            return print(quad[2])
        elif self.x < 0 and self.y < 0:
            return print(quad[3])
        elif self.x > 0 and self.y < 0:
            return print(quad[4])
        # if the point object is not in any of the four quadrants, return the string “On axis”
        else:
            return print("On axis")

    def move(self, direction):
        # This function assumes that the point object can move one unit in one of four directions: up, down,
        # left, or right; the direction parameter will be “u”, “d”, “l”, or “r”. Based on direction, the x or y
        # coordinate of the point object will be updated.
        # If direction is not a valid direction abbreviation, the function prints “**Invalid direction”.

        if direction == 'u':
            self.y = self.y + 1
        elif direction == 'd':
            self.y = self.y - 1
        elif direction == 'l':
            self.x = self.x - 1
        elif direction == 'r':
            self.x = self.x + 1
        else:
            print("**Invalid direction")
# ----------------------------------------------------------------------------------------------------------------
# main: add sufficient amount of code here to test each of the functions
# The output generated by main must be descriptive and readable.


if __name__ == '__main__':
    x = Point()
    x.goto(2, -3)
    x.position()
    x.fromOrigin()
    x.quadrant()
    x.move('l')
    x.position()
    x.quadrant()

    x.goto(0, -5)
    x.position()
    x.fromOrigin()
    x.quadrant()
    x.move('u')
    x.position()
    x.quadrant()

    x.goto(0, 0)
    x.position()
    x.fromOrigin()
    x.quadrant()
    x.move('r')
    x.position()
    x.quadrant()

    x.goto(4, 1)
    x.position()
    x.fromOrigin()
    x.quadrant()
    x.move('d')
    x.position()
    x.quadrant()

    x.goto(-2, 3)
    x.position()
    x.fromOrigin()
    x.quadrant()
    x.move('u')
    x.position()
    x.quadrant()

    x.goto(-1, -1)
    x.position()
    x.fromOrigin()
    x.quadrant()
    x.move('d')
    x.position()
    x.quadrant()

    x.goto(1, 1)
    x.position()
    x.fromOrigin()
    x.quadrant()
    x.move('t')
    x.position()
    x.quadrant()