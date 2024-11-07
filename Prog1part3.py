#Jackson Hoornaert
#jackson.hoornaert@und.edu
#Part 3 - Convert a number of milliseconds given by user input into minues, seconds, and leftover milliseconds

print("Part 3:\n")

ms = int(input("Milliseconds: "))

seconds = int(5)
minutes = int(5)

seconds = ms // 1000
minutes = seconds // 60
seconds %= 60
ms %= 1000

print(minutes)
print(seconds)
print(ms)