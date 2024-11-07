#Jackson Hoornaert
#jackson.hoornaert@und.edu
#Part 2
#Make a program that makes a box out of a given character

width = int(input("Enter width: "))
height = int(input("Enter height: "))
char = str(input("Enter a character: "))

i = 0
while i < height:
    j = 0
    while j < width:
        print(char, end="")
        j += 1
    print()
    i += 1
    