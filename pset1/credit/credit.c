#include <stdio.h>
#include <cs50.h>

void print_creditcard_brand(long);
bool checksum(long);
bool check_validity(long);
long get_positive_int(void);
int find_lenght(long);

int main(void)
{
    long creditcard_number = get_positive_int();
    if (check_validity(creditcard_number) == true)
    {
        print_creditcard_brand(creditcard_number);
    }
    else
    {
        printf("INVALID\n");
    }
}
//........................................
//Function that ask the user for a positive number
//........................................
long get_positive_int(void)
{
    long n;
    do
    {
        n = get_long("Credit Card Number: ");
    }
    while (n < 0);
    return n;
}
//........................................
//Function to check if the # of digits is correct to be a credit card
//........................................
bool check_validity(long creditcard_number)
{
    int len = find_lenght(creditcard_number);
    if ((len == 13 || len == 15 || len == 16) && checksum(creditcard_number))
    {
        return true;
    }
    else
    {
        return false;
    }
}
//........................................
//Function to know the lenght of a number
//........................................
int find_lenght(long n)
{
    int len;
    for (len = 0; n != 0; n /= 10)
    {
        len++;
    }
    return len;
}
//........................................
//Funtion to check Luhn’s Algorithm to determine if a creditcard number is valid
//........................................
bool checksum(long ccn)
{
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
    {
        if (i % 2 == 0)
        {
            sum += ccn % 10;
        }
        else
        {
            int digit = 2 * (ccn % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 0;
}
//........................................
// Function to know what is the company's card
//........................................
void print_creditcard_brand(long ccn)
{
    if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))
    {
        printf("AMEX\n");
    }
    else if (ccn >= 51e14 && ccn < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}