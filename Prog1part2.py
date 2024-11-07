#Jackson Hoornaert
#jackson.hoornaert@und.edu
#Part 2 - Using user input create a mailing adress using 1 print statements

first = input("First: ")
last = input("Last: ")
address = input("Address: ")
city = input("City: ")
state = input("State: ")
zip = input("Zip: ")

print(first, last, "\n", address, "\n", city + ",", state, "", zip)