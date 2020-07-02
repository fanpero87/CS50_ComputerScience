from sys import argv, exit
import csv

def main():
#Check that the arguments are correct
    if len(argv) != 3:
        print("missing command-line argument")
        exit(1)

#Open the Database file
    database = argv[1]
    db_file = open (database, "r")
    db_data = csv.reader(db_file)
    STR_sequence = next(db_data)[1:]#To capture only the STR names of the file

#Open the Sequence file
    sequence = argv[2]
    seq_file = open(sequence, "r")
    seq_data = seq_file.read()

    STR_result = [0] * len(STR_sequence)
    index = 0
    for STR_names in STR_sequence:
        STR_count = consecutive_STR(seq_data, STR_names)
        STR_result[index] = STR_count
        index += 1

    print_name(db_data, STR_result)

#Close both Files
    db_file.close()
    seq_file.close()

#Function to compute the longest run of consecutive repeats of the STR in the DNA sequence
def consecutive_STR(seq_data, STR_names):
    lenght_data = len(seq_data)
    lenght_STR = len(STR_names)
    STR_count = [0] * lenght_data

    for i in range (lenght_data - lenght_STR, -1, -1):
        if seq_data[i: i + lenght_STR] == STR_names:
            if i + lenght_STR > lenght_data - 1:
                STR_count[i] = 1
            else:
                STR_count[i] = 1 + STR_count[i + lenght_STR]
    return max(STR_count)

#Function that print out the name of the matching individual
def print_name(db_data, STR_result):

    for row in db_data:
        name = row[0]
        values = [int(val) for val in row[1:]]
        if values == STR_result:
            print(name)
            return

    print("No match")

main()