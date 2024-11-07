#Jackson Hoornaert
#jackson.hoornaert@und.edu
#Part 3
#Make a program that counts from a given starting number to end number

start = int(input("Enter starting value: "))
end = int(input("Enter ending value: "))

if start <= end:
    for x in range(start, end + 1):
        print(x)
if end < start:
    for x in range(start, end - 1, -1):
        print(x)