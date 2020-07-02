#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);

//Creating a full pyramid with two spaces in the middle
int main(void)
{
    int number = get_positive_int();
    for (int i = 1; i <= number; i++)
    {
        for (int j = i; j < number; j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}

//Function asking for a positive number between 1 and 8
int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Height: "); 
    }
    while (n < 1 || n > 8);
    return n;
}
