#Jackson Hoornaert
#jackson.hoornaert@und.edu
#Part 4 - Convert given change into a dollar amount

quarters = int(input("Quarters: "))
dimes = int(input("Dimes: "))
nickels = int(input("Nickels: "))
pennies = int(input("Pennies: "))

total = int(quarters * 25 + dimes * 10 + nickels * 5 + pennies)
total /= 100

print("Amount: $", format(total, ".2f"))