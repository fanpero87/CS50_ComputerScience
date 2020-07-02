def main():
    CreditNumber = positiveNumber()
    if (check_isvalid(CreditNumber) == True):#Check if the number is valid
        cardBrand(CreditNumber) #Print the brand of the card
    else:
        print("INVALID\n")

#Function that ask the user for a positive number
def positiveNumber():
    while True:
        CreditNumber = input("Number: \n")
        n = int(CreditNumber)
        if n > 0:
            break
    return CreditNumber

#Function to check if the # of digits is correct to be a credit card
def check_isvalid(CreditNumber):
    validNumber = checksum(CreditNumber)
    lenght = len(CreditNumber)
    if ((lenght == 13 or lenght == 15 or lenght == 16) and (validNumber % 10 == 0)):
        return True
    else:
        return False

#Funtion to check Luhn’s Algorithm to determine if a creditcard number is valid
def checksum(CreditNumber):
    lenght = len(CreditNumber)
    ccn = int(CreditNumber)
    sum1 = 0
    sum2 = 0
    if lenght % 2 == 0:
        for i in range (lenght): #If the CreditCard is an even Number
            if lenght % 2 == 0:
                a = ccn % 10
                sum1 = sum1 + a
                ccn = int(ccn / 10)
                lenght -= 1
            else:
                b = 2 * (ccn % 10)
                bb = b // 10 + b % 10
                sum2 = sum2 + bb
                ccn = int(ccn /10)
                lenght -= 1
        return sum1 + sum2
    else:
        for i in range (lenght): #If the CreditCard is an odd Number
            if lenght % 2 == 0:
                a = 2 * (ccn % 10)
                aa = a //10 + a % 10
                sum1 = sum1 + aa
                ccn = int(ccn / 10)
                lenght -= 1
            else:
                b = ccn % 10
                sum2 = sum2 + b
                ccn = int(ccn / 10)
                lenght -= 1
        return sum1 + sum2

#Function to know what is the company's card
def cardBrand(ccn):
    if (len(ccn) == 15) and (ccn[:2] == '34') or (ccn[:2] == '37'):
        print("AMEX\n")
    elif (len(ccn) == 16) and (ccn[:2] == '51') or (ccn[:2] == '52') or (ccn[:2] == '53') or (ccn[:2] == '54') or (ccn[:2] == '55'):
        print("MASTERCARD\n")
    elif ((len(ccn) == 13 or len(ccn) == 16) and ccn[:1] == '4'):
        print("VISA\n")
    else:
        print("INVALID\n")


main()