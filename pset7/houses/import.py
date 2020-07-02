from sys import argv, exit
from cs50 import SQL
import csv

if len(argv) != 2:
    print("missing command-line argument")
    exit(1)

# Create a .db file a stablish a connection
open("students.db", "w").close()
db = SQL("sqlite:///students.db")

# Create a Table on the .db file
db.execute("""CREATE TABLE students (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            first VARCHAR(255),
            middle VARCHAR(255),
            last VARCHAR(255),
            house VARCHAR(10),
            birth INTEGER
            )""")

#Open the .csv file
database = open(argv[1], "r")
reader = csv.DictReader(database)

# Copy the information of the .csv file into the .db file
for row in reader:
    FullName = row["name"].split()
    if len(FullName) == 2:
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
               (FullName[0], "NULL", FullName[1], row["house"], row["birth"]))
    else:
        db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
               (FullName[0], FullName[1], FullName[1], row["house"], row["birth"]))

# Close the .csv file
database.close()