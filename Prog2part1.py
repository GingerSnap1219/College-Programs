#Jackson Hoornaert
#jackson.hoornaert@und.edu
#Part 1
#Make a program that tracks the score and possible score of a set of students

score = 0
posScore = 0
numScores = 0
totalPoints = 0
totalPossible = 0
perfScores = 0
grade = "G"
avg = 0.00

while score >= 0:
    score = int(input("Enter a score: "))
    if score >= 0:
        numScores += 1
        totalPoints += score
    else:
        break
    posScore = int(input("Enter the possible score: "))
    totalPossible += posScore
    if score == posScore:
            perfScores += 1
 
if totalPoints != 0:
    avg = float((totalPoints / totalPossible) * 100)

if avg >= 90:
     grade = "A"
elif avg >= 80:
    grade = "B"
elif avg >= 70:
    grade = "C"
elif avg >= 60:
    grade = "D"
else:
     grade = "F"

print()
print("Number of scores:", numScores)
print("Total points:", totalPoints)
print("Total possible:", totalPossible)
print("Average:", format(avg, ".3f"))
print("Grade: " + grade)
print("Perfect scores:", perfScores)