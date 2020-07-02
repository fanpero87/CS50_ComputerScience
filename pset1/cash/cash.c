#include <stdio.h>
#include <cs50.h>

float get_positive_int(void);
int calculate_coin(int);

int main(void)
{
    int count = 0, count1 = 0, count2 = 0, whole_number_part, decimal_number_part;

    float change = get_positive_int();
   
    if (change >= 1)
    {
        whole_number_part = change;
        count1 = whole_number_part * 4;
        decimal_number_part = (change - whole_number_part + 0.00001) * 100;
        count2 = calculate_coin(decimal_number_part);
        count = count1 + count2;
    }
    else
    {
        decimal_number_part = change * 100;
        count = calculate_coin(decimal_number_part);
    } 
    printf("%i\n", count);
}

//Function asking for a positive number
float get_positive_int(void)
{
    float n;
    do
    {
        n = get_float("Change owed: "); 
    }
    while (n < 0);
    return n;
}

//Function calculating the minimum # of coins for the change
int calculate_coin(int coin)
{
    int quarters = 25, dimes = 10, nickels = 5, pennies = 1, count = 0, y;

    while (coin >= quarters)
    {
        y = coin / quarters;
        coin = coin % quarters;
        count = count + y;
    }
    while (coin >= dimes)
    {
        y = coin / dimes;
        coin = coin % dimes;
        count = count + y;
    }
    while (coin >= nickels)
    {
        y = coin / nickels;
        coin = coin % nickels;
        count = count + y;
    }
    while (coin >= pennies)
    {
        y = coin / pennies;
        coin = coin % pennies;
        count = count + y;
    }
    return count;
}