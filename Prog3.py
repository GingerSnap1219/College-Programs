#Jackson Hoornaert
#jackson.hoornaert@und.edu

#This function takes in an integer and squares it and then returns that value
def square(intVal):
    return intVal * intVal

#This function take in an integer and adds to squares between
#1 and the given value and returns the sum
def sumOfSquares(intVal):
    total = int(0)
    while intVal > 0:
        total += square(intVal)
        intVal -= 1
    return total

#This function takes and integer and determines if it's odd
#and returns True if it is and False if not
def isOdd(intVal):
    if intVal % 2 != 0:
        return True
    else:
        return False
    
#This function takes and integer and determines if it's even
#and returns True if it is and False if not
def isEven(intVal):
    if intVal % 2 == 0:
        return True
    else:
        return False
    
#This function takes in two integers and compares them if int1
#is greater it returns 1 if int2 is greater it returns -1 and 
#if they are even it returns 0
def compareTo(intVal1, intVal2):
    if intVal1 == intVal2:
        return 0
    if intVal1 > intVal2:
        return 1
    if intVal1 < intVal2:
        return -1
    
#This function takes in 3 integers and returns the one with the greatest absolute value
def maxMagnitude(intVal1, intVal2, intVal3):
    if abs(intVal1) >= abs(intVal2):
        if abs(intVal1) >= abs(intVal3):
            return intVal1
        else:
            return intVal3
    elif abs(intVal2) >= abs(intVal3):
        return intVal2
    else:
        return intVal3
    
#This funtion takes in an integer year and tells you how many days February has
def daysInFebruary(year):
    if year % 4 == 0:
        if year % 100 == 0:
            if year % 400 == 0:
                return 29
            else:
                return 28
        else:
            return 29
    else:
        return 28
    
#This function takes in an integer military time and returns the regular time
def militaryToRegularTime(militaryTime):
    mT = str(militaryTime)
    
    if len(mT) == 4:
        hours = str(mT[0] + mT[1])
        minutes = str(mT[2] + mT[3])
    elif len(mT) == 3:
        hours = str(mT[0])
        minutes = str(mT[1] + mT[2])
    else:
        hours = "12"
        minutes = "00"

    if int(hours) - 12 >= 0:
        if int(hours) - 12 == 0:
            hours = 12
            timeOfDay = "AM"
        else:
            hours = int(hours) - 12
            timeOfDay = str("PM")
    else:
        timeOfDay = str("AM")
    
    return str(hours) + ":" + str(minutes) + " " + timeOfDay

def main():
    print(square(5))
    print(sumOfSquares(5))
    print(isOdd(5))
    print(isEven(3))
    print(compareTo(4, 5))
    print(maxMagnitude(-100, 50, 75))
    print(daysInFebruary(2024))
    print(militaryToRegularTime(0))

main()