from sys import argv, exit
from cs50 import SQL

if len(argv) != 2:
    print("missing command-line argument")
    exit(1)

# Open and make a Query to the .db file
db = SQL("sqlite:///students.db")
rows = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last", argv[1])

# Go through each row and print the information
for line in rows:
    if line["middle"] == "NULL":
        print(line["first"], line["last"] + ', born', line["birth"])
    else:
        print(line["first"], line["middle"], line["last"] + ', born', line["birth"])